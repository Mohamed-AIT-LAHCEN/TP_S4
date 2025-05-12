#include "Container.h"
#include <sstream>
#include <iomanip>

Container::Container(string id, string image, double cpu, double memory):
Resource(id,cpu,memory) , image(image) {}

void Container::start() {
    active = true;
}
void Container::stop(){
    active = false;
}

string Container::getMetrics() const{
    ostringstream oss;
   oss << fixed << setprecision(1);
   oss << "[Container: " << std::setw(10) << std::left << id << ": " << std::setw(5) << std::left << cpu <<
    " CPU, " << std::setw(5) << std::left << memory << " Memory, " << std::setw(10) << std::left << image << "]";
    return oss.str();
}

ostream& operator<<(ostream& os, const Container& c) {
    os << c.getMetrics();
    return os;
}

double Container::getMemory() const {
    return memory;
}

double Container::getCPU() const {
    return cpu;
}