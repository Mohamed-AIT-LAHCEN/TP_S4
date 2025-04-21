#pragma once

#include <string>

class Resource {
protected:
    std::string id_;
    double cpu_;
    double memory_;
    bool active_;

public:
    Resource(std::string id, double cpu, double memory);
    virtual ~Resource() = default;

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual std::string getMetrics() const = 0;
}; 