#include "Pod.h"
#include <sstream>
#include <iomanip>

Pod::Pod(string name, unordered_map<string, string> labels)
: name(name) , labels(labels){}

void Pod::addContainer(unique_ptr<Container> container){
    for(auto &c : containers){
        if(c->getId() == container->getId()){
            cout << "Container déjà existant." << endl;
            return;
        }
    }
    containers.push_back(move(container));
}

bool Pod::removeContainer(const string& id) {
    for (auto it = containers.begin(); it != containers.end(); ++it) {
        if ((*it)->getId() == id) {
            containers.erase(it);  
            return true;          
        }
    }
    return false;
}

void Pod::deploy(){
    for (const auto& container : containers) {
        container->start();
    }
}

string Pod::getMetrics() const{
    ostringstream oss;
    oss << fixed << setprecision(1);
    oss << "[Pod: " << name << "]\n";
    for(const auto& c : containers){
        oss << c->getMetrics() << "\n";
    }
    return oss.str();
}

const vector<unique_ptr<Container>>& Pod::getContainers() const {
    return containers;
}

string Pod::getName() const {
    return name;
}

ostream& operator<<(ostream& os, const Pod& p) {
    os << "[Pod: " << p.name << "]\n";
    for(const auto& c : p.containers){
        os << c->getMetrics() << "\n";
    }
    return os;
}

