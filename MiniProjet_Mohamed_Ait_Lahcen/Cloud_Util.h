#pragma once

#include "KubernetesCluster.h"
#include <vector>
#include <memory>

void display(const KubernetesCluster& cluster);
void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods); 