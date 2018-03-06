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

std::vector<Edge*>& Node::GetEdges() {
    return edges_;
}

void Node::SetEdges(const std::vector<Edge*>& edges) {
    edges_ = edges;
}

void Node::Attach(Edge* edge) {
    edges_.push_back(edge);
}

Node::Node(const char * szID) {
    NodeFactory::assign(szID, this);
}

Node::Node() : value_(0) {
}

Node::~Node() {
    for (auto i = 0u; i < edges_.size(); ++i) {
        delete edges_[i];
    }
}
