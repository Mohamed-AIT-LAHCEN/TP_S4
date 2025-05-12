#ifndef KUBERNETESCLUSTER_H
#define KUBERNETESCLUSTER_H

#include "Pod.h"
#include "Server.h"
#include <functional>

class KubernetesCluster {
    private:
        vector<shared_ptr<Server>> nodes;
        vector<unique_ptr<Pod>> pods;
    public:
        void addNode(shared_ptr<Server> node);
        bool removePod(const string& name);
        void deployPod(unique_ptr<Pod> pod);
        bool schedulePod(Pod& pod);
        Pod* getPod(const string& name);
        string getMetrics() const;
        friend ostream& operator<<(ostream& os, const KubernetesCluster& c);
        vector<shared_ptr<Server>> getFilteredServers(const std::function<bool(const Server&)>& predicate);
        const vector<unique_ptr<Pod>>& getPods() const { return pods; }
};

#endif