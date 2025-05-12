#include "Server.h"
#include <sstream>
#include <iomanip>
#include "CloudExceptions.hpp"
Server::Server(string id, double cpu, double memory): Resource(id,cpu,memory), available_cpu(cpu), available_memory(memory) {}

bool Server::allocate(double cpu, double memory) {
    if(!active){
        throw AllocationException("Allocation Error: Serveur " + id + " n'est pas actif");
    }
    if (cpu <= available_cpu && memory <= available_memory) {
        available_cpu -= cpu;
        available_memory -= memory;
        return true; 
    }
    else{
        throw AllocationException("Les ressources demandées dépassent ce qui est disponible");
    }
    return false;
}

void Server::start() {
    active = true;
}
void Server::stop(){
    active = false;
}

string Server::getMetrics() const {
    ostringstream oss;
    oss << fixed << setprecision(1);
    oss << "[Server: " << std::setw(10) << std::left << id << "| Total : " << std::setw(6) << std::left<< cpu <<
     " CPU, " << std::setw(6) << std::left << memory << " MB  | Free : " << std::setw(6) << std::left << available_cpu 
     << " CPU, " << std::setw(6) << std::left << available_memory << " MB]";
    return oss.str();
}

ostream& operator<<(ostream& os, const Server& s) {
    os << s.getMetrics();
    return os;
}

bool Server::isActive() const {
    return active;
} 
