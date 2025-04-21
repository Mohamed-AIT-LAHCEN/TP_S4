#pragma once

#include "Resource.h"
#include <string>
#include <ostream>

class Container : public Resource {
private:
    std::string image_;

public:
    Container(std::string id, std::string image, double cpu, double memory);
    
    void start() override;
    void stop() override;
    std::string getMetrics() const override;
    
    friend std::ostream& operator<<(std::ostream& os, const Container& c);
}; 