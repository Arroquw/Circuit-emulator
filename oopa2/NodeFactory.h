#pragma once
#include <map>
#include <string>

class Node;

class NodeFactory {
public:
    NodeFactory();
    ~NodeFactory();
    static Node *create(const char*);
private:
    static void assign(const char*, Node*);
    typedef std::map<std::string, Node*> node_map;
    static node_map &GetMap();
    friend class Node;
};

