#ifndef POD_H
#define POD_H

#include "Container.h"
#include <unordered_map>
#include <memory>
#include <vector>

class Pod {
    private:
        string name;
        vector<unique_ptr<Container>> containers;
        unordered_map<string,string> labels;
    public:
        Pod(string name, unordered_map<string, string> labels = {});
        void addContainer(unique_ptr<Container> container);
        bool removeContainer(const string& id);
        void deploy();
        string getMetrics() const;
        friend ostream& operator<<(ostream& os, const Pod& p);
        const vector<unique_ptr<Container>>& getContainers() const;
        string getName() const;

};

#endif