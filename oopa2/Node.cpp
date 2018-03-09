#include "Node.h"
#include "NodeFactory.h"

void Node::SetName(const std::string& name) {
    name_ = name;
}

void Node::SetValue(const uint8_t value) {
    value_ = value;
}

std::string& Node::GetName() {
    return name_;
}

uint8_t Node::GetValue() {
    return value_;
}

std::vector<Node*>& Node::GetNodes() {
    return nodes_;
}

void Node::SetNodes(const std::vector<Node*>& edges) {
    nodes_ = edges;
}

void Node::Attach(Node* edge) {
    nodes_.push_back(edge);
}

Node::Node(const char * szID) {
    NodeFactory::assign(szID, this);
}

Node::Node() {
}

Node::~Node() {
}
