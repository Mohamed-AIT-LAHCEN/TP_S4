#include "Resource.h"

Resource::Resource(string id, double cpu, double memory)
: id(id) , cpu(cpu) , memory(memory) {}

string Resource::getId() const {
    return id;
}