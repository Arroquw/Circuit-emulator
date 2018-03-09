#include "OrNode.h"
#include <iostream>
#include <algorithm>

OrNode OrNode::m_cStaticMember_("OR");

OrNode::OrNode() {
}

OrNode::OrNode(const char* szID) : Node(szID) {
}


Node* OrNode::clone() const {
    return new OrNode;
}

void OrNode::action() {
    std::cout << GetName() << ", OR:\n";
    std::for_each(GetNodes().begin(), GetNodes().end(), [](Node* x) {std::cout << x->GetName() << std::endl;});
}

void OrNode::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

OrNode::~OrNode() {
}
