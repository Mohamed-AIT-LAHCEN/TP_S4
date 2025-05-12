#include "Cloud_Util.h"
#include <iostream>
#include <fstream>
#include "CloudExceptions.hpp"

void display(const KubernetesCluster& cluster) {
    cout << cluster.getMetrics() << endl;
}

void deployPods(KubernetesCluster& cluster, vector<unique_ptr<Pod>>& pods) {
    for (auto& pod : pods) {
        try {
            cout << "-> Déploiement du Pod " << *pod << endl;
            auto pod_ptr = move(pod);
            cluster.deployPod(move(pod_ptr));
        } catch (const AllocationException& e) {
            cout << e.what() << endl;
        }
    }

    // Vider le vecteur de pods pour libérer les pointeurs
    pods.clear();
} 

void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename){
    std::ofstream out_file {filename, std::ios::app};
    if (!out_file) {
        throw FileException("Erreur lors de l'ouverture du fichier");
    }
    else{
        out_file << cluster.getMetrics() << endl;
        cout << "Métriques sauvegardées avec succès" << endl;
    }
}

void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func) {
    for (const auto& pod : cluster.getPods()) {
        for (const auto& container : pod->getContainers()) {
            func(*container);
        }
    }
}