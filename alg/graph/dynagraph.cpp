#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Node;

class Connection {
public:
    Node* node;
    int weight;
};

class Node {
public:
    std::string name;
    std::vector<Connection> connections;

    Node(const std::string& name) : name(name) {}

    void add_connection(Node* other, int weight) {
        connections.push_back({other, weight});
    }
};

class Graph {
public:
    std::vector<Node*> nodes;

    ~Graph() {
        for (Node* node : nodes) {
            delete node;
        }
    }

    void add_node(Node* node) {
        nodes.push_back(node);
    }

    void link_nodes(Node* a, Node* b, int weight) {
        a->add_connection(b, weight);
        b->add_connection(a, weight);
    }

    void remove_connection(Node* from, Node* to) {
        auto& conns = from->connections;
        conns.erase(std::remove_if(conns.begin(), conns.end(),
                                   [to](const Connection& conn) {
                                       return conn.node == to;
                                   }),
                    conns.end());
    }

    void delete_node(Node* node) {
        for (auto& conn : node->connections) {
            remove_connection(conn.node, node);
        }
        node->connections.clear();
    }

    int connected_component_recursive(Node* r, int max_conexao, std::vector<Node*>& component_nodes, int& n_nos) {
        int peso_total = 0;
        if (n_nos > 1000) {
            fprintf(stderr, "ERRO");
            return -1;
        }
        component_nodes[n_nos++] = r;
        for (auto& v : r->connections) {
            if (v.weight >= max_conexao)
                continue;
            bool visited = false;
            for (int i = 0; i < n_nos; ++i) {
                if (component_nodes[i] == v.node) {
                    visited = true;
                    break;
                }
            }
            if (!visited) {
                peso_total += v.weight + connected_component_recursive(v.node, max_conexao, component_nodes, n_nos);
            }
        }
        return peso_total;
    }

    int connected_component(Node* start_node, int max_weight, std::vector<Node*>& component_nodes) {
        int n_nos = 0;
        return connected_component_recursive(start_node, max_weight, component_nodes, n_nos);
    }

    int connected_component_no_max_recursive(Node* r, std::vector<Node*>& component_nodes, int& n_nos) {
        int peso_total = 0;
        if (n_nos > 1000) {
            fprintf(stderr, "ERRO");
            return -1;
        }
        component_nodes[n_nos++] = r;
        for (auto& v : r->connections) {
            bool visited = false;
            for (int i = 0; i < n_nos; ++i) {
                if (component_nodes[i] == v.node) {
                    visited = true;
                    break;
                }
            }
            if (!visited) {
                peso_total += v.weight + connected_component_no_max_recursive(v.node, component_nodes, n_nos);
            }
        }
        return peso_total;
    }

    int connected_component_no_max(Node* start_node, std::vector<Node*>& component_nodes) {
        int n_nos = 0;
        return connected_component_no_max_recursive(start_node, component_nodes, n_nos);
    }

    void rename_friburgo(const Node* p_petro) {
        p_petro->connections[0].node->connections[1].node->name = "Nova Friburgo";
    }
};

int main() {
    Graph g;
    std::vector<std::string> names = {"Petropolis", "Teresopolis", "Niteroi", "Rio", "Friburgo"};
    for (const auto& name : names) {
        g.add_node(new Node(name));
    }

    g.link_nodes(g.nodes[0], g.nodes[1], 50);
    g.link_nodes(g.nodes[0], g.nodes[3], 65);
    g.link_nodes(g.nodes[1], g.nodes[3], 100);
    g.link_nodes(g.nodes[1], g.nodes[4], 75);
    g.link_nodes(g.nodes[2], g.nodes[3], 15);
    g.link_nodes(g.nodes[2], g.nodes[4], 120);
    g.link_nodes(g.nodes[3], g.nodes[4], 140);

    g.rename_friburgo(g.nodes[0]);

    std::vector<Node*> component_nodes(1000);
    int peso_total = g.connected_component(g.nodes[4], 100, component_nodes);

    if (peso_total != -1) {
        printf("Componente de %s tem %ld nos e peso total %d\n", g.nodes[4]->name.c_str(),
               std::count_if(component_nodes.begin(), component_nodes.end(), [](Node* n){ return n != nullptr; }),
               peso_total);
        for (Node* node : component_nodes) {
            if (node) {
                printf("%s\n", node->name.c_str());
            }
        }
    }

    return 0;
}
