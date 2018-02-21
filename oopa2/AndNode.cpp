#include "AndNode.h"
#include <iostream>

AndNode AndNode::m_cStaticMember_("AND");

AndNode::AndNode() {
}

AndNode::AndNode(const char* szID) : Node(szID) {
}


Node* AndNode::clone() const {
    return new AndNode;
}

void AndNode::action() const {
    std::cout << "AND" << std::endl;
}

void AndNode::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

AndNode::~AndNode() {
}
