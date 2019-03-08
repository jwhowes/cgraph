//
// Created by Ben Napier on 08/03/2019.
//

#ifndef CGRAPH_NODE_H
#define CGRAPH_NODE_H

#include <string>
#include <vector>

class Node {
private:
    std::vector<int> label_vector;
    std::vector<std::string> label_name_vector;
    int data;
public:
    explicit Node(int p_data) {
        data = p_data;
    }

    void SetLabel(const std::string &label, int data) {
        for (int i = 0; i < label_name_vector.size(); ++i) {
            if (label_name_vector[i] == label) {
                label_vector[i] = data;
                break;
            }
        }
    }

    void AddLabel(const std::string &label) {
        label_name_vector.push_back(label);
        label_vector.emplace_back();
    }


    int get_data() {
        return data;
    }

    void set_data(int p_data) {
        data = p_data;
    }
};

#endif //CGRAPH_NODE_H
