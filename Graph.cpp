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

void Graph::AddEdgeFrom(std::vector<std::tuple<int, int, int>> edge_vector, bool directed) {
    for (auto edge : edge_vector) {
        AddEdge(std::get<0>(edge), std::get<1>(edge), std::get<2>(edge), directed);
    }
}

void Graph::AddEdgeFrom(std::vector<std::tuple<int, int, int>> edge_vector) {
    for (auto edge : edge_vector) {
        AddEdge(std::get<0>(edge), std::get<1>(edge), std::get<2>(edge));
    }
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

void Graph::AddNodesFrom(std::vector<int> data_vector) {
    for (auto data : data_vector) {
        AddNode(data);
    }
}

std::vector<Edge> Graph::Neighbours(int data) {
    for (auto edge_vector : edge_vector_vector) {
        if (std::get<0>(edge_vector) == data && !std::get<1>(edge_vector).empty()) {
            return std::get<1>(edge_vector);
        }
    }
    return std::vector<Edge>();
}

std::vector<std::tuple<int, int, int>> Graph::GetEdges() {
    std::vector<std::tuple<int, int, int>> return_vector;
    for (auto edge_vector : edge_vector_vector) {
        for (auto edge : std::get<1>(edge_vector)) {
            return_vector.emplace_back();
            std::get<0>(return_vector[return_vector.size() - 1]) = std::get<0>(edge_vector);
            std::get<1>(return_vector[return_vector.size() - 1]) = edge.to;
            std::get<2>(return_vector[return_vector.size() - 1]) = edge.weight;
        }
    }
    return return_vector;
}

std::vector<int> Graph::GetNodesData() {
    std::vector<int> return_vector;
    for (auto node : node_vector) {
        return_vector.push_back(node.get_data());
    }
    return return_vector;
}


