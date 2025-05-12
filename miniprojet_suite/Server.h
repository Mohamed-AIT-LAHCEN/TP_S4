#ifndef SERVER_H
#define SERVER_H

#include "Resource.h"

class Server : public Resource{
    private:
        double available_cpu;
        double available_memory;
    public:
        Server(string id, double cpu, double memory);
        bool allocate(double cpu, double memory);
        void start() override;
        void stop() override;
        string getMetrics() const override;
        friend ostream& operator<<(ostream& os, const Server& s);
        bool isActive() const;
};

#endif