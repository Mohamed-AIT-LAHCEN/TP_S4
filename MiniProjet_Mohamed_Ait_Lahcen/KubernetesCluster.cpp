#include "KubernetesCluster.h"
#include <sstream>
#include <algorithm>
#include <regex>

void KubernetesCluster::addNode(std::shared_ptr<Server> node) {
    nodes_.push_back(std::move(node));
}

bool KubernetesCluster::removePod(const std::string& name) {
    auto it = std::find_if(pods_.begin(), pods_.end(),
        [&name](const auto& pod) { return pod->getMetrics().find(name) != std::string::npos; });
    
    if (it != pods_.end()) {
        pods_.erase(it);
        return true;
    }
    return false;
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod) {
    if (schedulePod(*pod)) {
        pods_.push_back(std::move(pod));
    }
}

bool KubernetesCluster::schedulePod(Pod& pod) {
    double total_cpu = 0;
    double total_memory = 0;
    
    // Calculate total resources needed
    for (const auto& container : pod.getContainers()) {
        // Extract CPU and memory values using regex
        std::string metrics = container->getMetrics();
        std::regex cpu_regex("CPU, ([0-9.]+) Memory");
        std::regex memory_regex("Memory, ([0-9.]+)");
        
        std::smatch cpu_match, memory_match;
        if (std::regex_search(metrics, cpu_match, cpu_regex) && cpu_match.size() > 1) {
            total_cpu += std::stod(cpu_match[1].str());
        }
        
        if (std::regex_search(metrics, memory_match, memory_regex) && memory_match.size() > 1) {
            total_memory += std::stod(memory_match[1].str());
        }
    }
    
    // Try to find a node with sufficient resources
    for (auto& node : nodes_) {
        if (node->allocate(total_cpu, total_memory)) {
            pod.deploy();
            return true;
        }
    }
    return false;
}

Pod* KubernetesCluster::getPod(const std::string& name) {
    auto it = std::find_if(pods_.begin(), pods_.end(),
        [&name](const auto& pod) { return pod->getMetrics().find(name) != std::string::npos; });
    
    return it != pods_.end() ? it->get() : nullptr;
}

std::string KubernetesCluster::getMetrics() const {
    std::stringstream ss;
    ss << "=== Cluster Metrics ===\n";
    
    for (const auto& node : nodes_) {
        ss << *node << "\n";
    }
    
    for (const auto& pod : pods_) {
        ss << *pod;
    }
    
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c) {
    os << c.getMetrics();
    return os;
} 