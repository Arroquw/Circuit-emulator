#include "OrNode.h"
#include <iostream>

OrNode OrNode::m_cStaticMember_("OR");

OrNode::OrNode() {
}

OrNode::OrNode(const char* szID) : Node(szID) {
}


Node* OrNode::clone() const {
    return new OrNode;
}

void OrNode::action() const {
    std::cout << "OR" << std::endl;
}

void OrNode::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

OrNode::~OrNode() {
}
