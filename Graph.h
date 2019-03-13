//
// Created by Ben Napier on 13/03/2019.
//

#ifndef CGRAPH_GRAPH_H
#define CGRAPH_GRAPH_H
#include <vector>
#include <tuple>
#include <iostream>
#include "Node.h"

struct Edge {
    int to; // Node to
    int weight;

    Edge(int p_to, int p_weight) {
        to = p_to;
        weight = p_weight;
    }
};

class Graph {
private:
    std::vector<Node> node_vector;
    std::vector<std::tuple<int, std::vector<Edge>>> edge_vector_vector;

    void AddDirectedEdge(int from, int to, int weight);
public:
    /**
     * Adds an edge (directed or not) between two nodes.
     * @param from the starting node
     * @param to the ending node
     * @param weight the weight of the edge
     * @param directed whether or not the edge is directed
     */
    void AddEdge(int from, int to, int weight, bool directed);

    /**
     * Adds a directed edge between two nodes.
     * Will overwrite existing edges.
     * @param from the starting node
     * @param to the ending node
     * @param weight the weight of the edge
     */
    void AddEdge(int from, int to, int weight);

    /**
     * Adds an edge (directed or not) from a vector of tuples, parameters ordered the same as above.
     */
    void AddEdgesFrom(std::vector<std::tuple<int, int, int>> edge_vector, bool directed);

    /**
     * Adds a directed edge from a vector of tuples, parameters ordered the same as above.
     * @param vector of edges
     */
    void AddEdgesFrom(std::vector<std::tuple<int, int, int>> edge_vector);

    /**
     * Adds a node.
     * Will overwrite a nodes labels (not edges) if a node with the same data already exists.
     * @param data the data of the node (>= 0)
     */
    void AddNode(int data);

    /**
     * Adds a list of nodes.
     * @param data_vector list of data of the nodes
     */
    void AddNodesFrom(std::vector<int> data_vector);

    /**
     * Returns all nodes with a direct edge from the node.
     * @param data the node index
     * @return a vector of nodes adjacent
     */
    std::vector<Edge> Neighbours(int data);

    /**
     * Returns a vector of all the edges.
     * @return a vector of all edges, an edge is of the form (from, to, weight)
     */
    std::vector<std::tuple<int, int, int>> GetEdges();

    /**
     * Returns a vector of all the nodes.
     * @return a vector of all the nodes
     */
    std::vector<Node> get_node_vector() {
        return node_vector;
    }

    /**
     * Returns a vector of the data of all the nodes.
     * @return a vector of all the nodes' data
     */
     std::vector<int> GetNodesData();


    void Debug() {
        for (auto i : edge_vector_vector) {
            std::cout << std::get<0>(i) << ": ";
            for (auto j : std::get<1>(i)) {
                std::cout << j.to << " (" << j.weight << ")" << ",";
            }
            std::cout << std::endl;
        }
    }
};

#endif //CGRAPH_GRAPH_H
