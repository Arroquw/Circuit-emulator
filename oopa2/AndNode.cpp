#include "AndNode.h"
#include <iostream>
#include <algorithm>

AndNode AndNode::m_cStaticMember_("AND");

AndNode::AndNode() {
}

AndNode::AndNode(const char* szID) : Node(szID) {
}

Node* AndNode::clone() const {
    return new AndNode;
}

void AndNode::action() {
    std::cout << GetName() << ", AND " << ":\n";
    std::for_each(GetEdges().begin(), GetEdges().end(), [](Edge* x) {std::cout << x->GetName() << std::endl;});
}

void AndNode::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

AndNode::~AndNode() {
}
