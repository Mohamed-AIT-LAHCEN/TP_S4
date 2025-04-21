#include "Pod.h"
#include <sstream>
#include <algorithm>

Pod::Pod(std::string name, std::unordered_map<std::string, std::string> labels)
    : name_(std::move(name)), labels_(std::move(labels)) {}

void Pod::addContainer(std::unique_ptr<Container> container) {
    containers_.push_back(std::move(container));
}

bool Pod::removeContainer(const std::string& id) {
    auto it = std::find_if(containers_.begin(), containers_.end(),
        [&id](const auto& container) { return container->getMetrics().find(id) != std::string::npos; });
    
    if (it != containers_.end()) {
        containers_.erase(it);
        return true;
    }
    return false;
}

void Pod::deploy() {
    for (auto& container : containers_) {
        container->start();
    }
}

std::string Pod::getMetrics() const {
    std::stringstream ss;
    ss << "[Pod: " << name_ << "]\n";
    for (const auto& container : containers_) {
        ss << container->getMetrics() << "\n";
    }
    return ss.str();
}

const std::vector<std::unique_ptr<Container>>& Pod::getContainers() const {
    return containers_;
}

std::ostream& operator<<(std::ostream& os, const Pod& p) {
    os << "[Pod: " << p.name_ << "]\n";
    for (const auto& container : p.containers_) {
        os << *container << "\n";
    }
    return os;
} 