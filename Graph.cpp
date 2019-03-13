//
// Created by Ben Napier on 13/03/2019.
//

#include "Graph.h"

void Graph::AddDirectedEdge(int from, int to, int weight) {
    if (from == to) return;
    bool exists = false;
    for (auto &node : node_vector) {
        if (node.get_data() == from || node.get_data() == to) {
            if (exists) {
                for (auto &edge_vector : edge_vector_vector) {
                    if (std::get<0>(edge_vector) == from) {
                        for (auto &edge : std::get<1>(edge_vector)) {
                            if (edge.to == to) {
                                edge.weight = weight;
                                return;
                            }
                        }
                        std::get<1>(edge_vector).push_back(Edge(to, weight));
                        return;
                    }
                }
            } else {
                exists = true;
            }
        }
    }
    std::cerr << "cgraph: One of the nodes entered does not exist.";
}

void Graph::AddEdge(int from, int to, int weight, bool directed) {
    AddDirectedEdge(from, to, weight);
    if (directed) return;
    AddDirectedEdge(to, from, weight);
}

void Graph::AddEdge(int from, int to, int weight) {
    AddEdge(from, to, weight, true);
}

void Graph::AddNode(int data) {
    if (data < 0) return;
    for (auto &node : node_vector) {
        if (node.get_data() == data) {
            node = Node(data);
            return;
        }
    }
    node_vector.emplace_back(Node(data));
    edge_vector_vector.emplace_back();
    std::get<0>(edge_vector_vector[edge_vector_vector.size() - 1]) = data;
}

std::vector<Edge> Graph::Neighbours(int data) {
    for (auto edge_vector : edge_vector_vector) {
        if (std::get<0>(edge_vector) == data && !std::get<1>(edge_vector).empty()) {
            return std::get<1>(edge_vector);
        }
    }
    return std::vector<Edge>();
}