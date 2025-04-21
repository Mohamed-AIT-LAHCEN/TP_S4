#include "Cloud_Util.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;
    std::cout << "\n=== Cluster 1 ===\n";
    
    // Create a vector of clusters
    std::vector<KubernetesCluster> clusters(2); // Two clusters
    
    // === Configure the first cluster ===
    KubernetesCluster& cluster1 = clusters[0];
    cluster1.addNode(std::make_shared<Server>("node1-1", 4.0, 8192.0));
    cluster1.addNode(std::make_shared<Server>("node1-2", 8.0, 14096.0));
    
    // Create containers for the first cluster
    auto c1_1 = std::make_unique<Container>("c1-1", "nginx:latest", 2, 5120.0);
    auto c1_2 = std::make_unique<Container>("c1-2", "redis:latest", 6, 2560.0);
    
    // Create a pod for the first cluster
    auto pod1_1 = std::make_unique<Pod>("web-pod", std::unordered_map<std::string, std::string>{{"app", "nginx"}});
    pod1_1->addContainer(std::move(c1_1));
    pod1_1->addContainer(std::move(c1_2));
    
    // Create another pod for the first cluster
    auto c1_3 = std::make_unique<Container>("c1-3", "mysql:latest", 0.7, 1024.0);
    auto pod1_2 = std::make_unique<Pod>("db-pod", std::unordered_map<std::string, std::string>{{"app", "mysql"}});
    pod1_2->addContainer(std::move(c1_3));
    
    // Deploy pods in the first cluster
    std::vector<std::unique_ptr<Pod>> pods1;
    pods1.push_back(std::move(pod1_1));
    pods1.push_back(std::move(pod1_2));
    deployPods(cluster1, pods1);
    
    // === Test 0: Deploy a pod with insufficient resources ===
    std::cout << "\n=== Test 0: Deploy a pod with insufficient resources ===\n";
    auto large_container = std::make_unique<Container>("large-c1", "large-app:latest", 5.0, 10000.0);
    auto large_pod = std::make_unique<Pod>("large-pod", std::unordered_map<std::string, std::string>{{"app", "large"}});
    large_pod->addContainer(std::move(large_container));
    cluster1.deployPod(std::move(large_pod));
    
    std::cout << "\n=== Cluster 2 ===\n";
    
    // === Configure the second cluster ===
    KubernetesCluster& cluster2 = clusters[1];
    cluster2.addNode(std::make_shared<Server>("node2-1", 3.0, 6144.0));
    cluster2.addNode(std::make_shared<Server>("node2-2", 1.5, 2048.0));
    
    // Create containers for the second cluster
    auto c2_1 = std::make_unique<Container>("c2-1", "node:latest", 0.6, 768.0);
    auto c2_2 = std::make_unique<Container>("c2-2", "memcached:latest", 0.4, 384.0);
    
    // Create a pod for the second cluster
    auto pod2_1 = std::make_unique<Pod>("api-pod", std::unordered_map<std::string, std::string>{{"app", "node"}});
    pod2_1->addContainer(std::move(c2_1));
    
    // Create another pod for the second cluster
    auto c2_2_2 = std::make_unique<Container>("c2-2-2", "memcached:latest", 0.4, 384.0);
    auto pod2_2 = std::make_unique<Pod>("cache-pod", std::unordered_map<std::string, std::string>{{"app", "memcached"}});
    pod2_2->addContainer(std::move(c2_2_2));
    
    // Deploy pods in the second cluster
    std::vector<std::unique_ptr<Pod>> pods2;
    pods2.push_back(std::move(pod2_1));
    pods2.push_back(std::move(pod2_2));
    deployPods(cluster2, pods2);
    
    // Display initial state
    std::cout << "\n=== Initial state ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }
    
    // Test 1: Remove a container (c1-2 from web-pod in cluster1)
    std::cout << "\n=== Test 1: Remove container c1-2 (redis) ===\n";
    Pod* web_pod = clusters[0].getPod("web-pod");
    if (web_pod && web_pod->removeContainer("c1-2")) {
        std::cout << "Container c1-2 removed from web-pod\n";
    } else {
        std::cout << "Container c1-2 or web-pod not found\n";
    }
    
    // Display state after container removal
    std::cout << "\n=== State after container removal ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }
    
    // Test 2: Remove a pod (db-pod from cluster1)
    std::cout << "\n=== Test 2: Remove pod db-pod ===\n";
    if (clusters[0].removePod("db-pod")) {
        std::cout << "Pod db-pod removed from cluster 1\n";
    } else {
        std::cout << "Pod db-pod not found\n";
    }
    
    // Display state after pod removal
    std::cout << "\n=== State after pod removal ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }
    
    // Test 3: Remove a cluster (cluster2)
    std::cout << "\n=== Test 3: Remove cluster 2 ===\n";
    clusters.erase(clusters.begin() + 1);
    
    // Display final state
    std::cout << "\n=== State after cluster removal ===\n";
    for (size_t i = 0; i < clusters.size(); ++i) {
        std::cout << "\n=== Metrics for Cluster " << (i + 1) << " ===\n";
        display(clusters[i]);
    }
    
    return 0;
} 