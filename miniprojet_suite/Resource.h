#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <string>
using namespace std;

class Resource {
    protected:
        string id;
        double cpu;
        double memory;
        bool active;
    public:
        Resource(string id, double cpu, double memory);
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual string getMetrics() const = 0;
        virtual ~Resource() = default;
        string getId() const;
};

#endif