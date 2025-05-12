#include "KubernetesCluster.h"
#include <sstream>
#include <iomanip>
#include "CloudExceptions.hpp"

void KubernetesCluster::addNode(shared_ptr<Server> node){
    for(auto n : nodes){
        if(node->getId() == n->getId()){
            cout << "Node déjà existant." << endl;
            return;
        }
    }
    nodes.push_back(node);
}

bool KubernetesCluster::removePod(const string& name){
    for (auto it = pods.begin(); it != pods.end(); ++it) {
        if ((*it)->getName() == name) {
            pods.erase(it);  
            return true;          
        }
    }
    return false;
}

void KubernetesCluster::deployPod(unique_ptr<Pod> pod){
    try {
        if(schedulePod(*pod)){
            pod->deploy();
            cout << "Pod " << *pod << " déployé avec succès." << endl;
            pods.push_back(move(pod));
        }
    } catch (const AllocationException& e) {
        cout << e.what() << endl;
    }
}

bool KubernetesCluster::schedulePod(Pod& pod) {
    double req_cpu = 0;
    double req_mem = 0;

    for (auto& container : pod.getContainers()) {
        req_cpu += container->getCPU();
        req_mem += container->getMemory();
    }
    
    for (auto& node : nodes) {
        if (node->allocate(req_cpu, req_mem)) {
            cout << "sur le noeud " << *node << endl;
            return true; 
        }
    }
    
    return false; 
}

Pod* KubernetesCluster::getPod(const string& name) {
    for (auto& pod : pods) {
        if (pod->getName() == name) {
            return pod.get();
        }
    }
    return nullptr;
}

string KubernetesCluster::getMetrics() const {
    stringstream ss;
    ss << fixed << setprecision(1);
    ss << "=== Cluster Metrics ===\n";
    for (const auto& node : nodes) {
        ss << node->getMetrics() << "\n";
    }
    for (const auto& pod : pods) {
        ss << pod->getMetrics();
    }
    return ss.str();
}

ostream& operator<<(ostream& os, const KubernetesCluster& c) {
    os << c.getMetrics();
    return os;
}

vector<shared_ptr<Server>> KubernetesCluster::getFilteredServers(const std::function<bool(const Server&)>& predicate){
    vector<shared_ptr<Server>> inactifs;
    for(auto s : nodes){
        if(predicate(*s)){
            string metrics = (*s).getMetrics();
            inactifs.push_back(s);
            cout << metrics << endl;
        }
    }
    return inactifs;
}