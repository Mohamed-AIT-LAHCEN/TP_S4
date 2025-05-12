#ifndef CONTAINER_H
#define CONTAINER_H

#include "Resource.h"

class Container : public Resource {
    private:
        string image;
    public:
        Container(string id, string image, double cpu, double memory);
        void start() override;
        void stop() override;
        string getMetrics() const override;
        friend ostream& operator<<(ostream& os, const Container& c);
        double getCPU() const;
        double getMemory() const;
};

#endif