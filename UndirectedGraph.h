//
// Created by Ben Napier on 08/03/2019.
//

#ifndef CGRAPH_UNDIRECTEDGRAPH_H
#define CGRAPH_UNDIRECTEDGRAPH_H


#include <tuple>
#include <vector>
#include "Node.h"


class UndirectedGraph {
private:
    std::vector<int> node_vector;
    std::vector<std::tuple<int, int>> adjancency_vector;
public:
    void AddNode(int index);
    void AddEdge(int from_index, int to_index);
    std::vector<int> GetNeighbors(int index);
    std::vector<int> GetEdges();
    std::vector<int> GetNodes();
    int GetNodeCount();
    int GetEdgeCount();
};


#endif //CGRAPH_UNDIRECTEDGRAPH_H
