#include "XorNode.h"
#include <iostream>
#include <algorithm>

XorNode XorNode::m_cStaticMember_("XOR");

XorNode::XorNode() {
}

XorNode::XorNode(const char* szID) : Node(szID) {
}


Node* XorNode::clone() const {
    return new XorNode;
}

void XorNode::action() {
    std::cout << GetName() << ", XOR:\n";
    std::for_each(GetEdges().begin(), GetEdges().end(), [](Edge* x) {std::cout << x->GetName() << std::endl;});
}


void XorNode::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

XorNode::~XorNode() {
}
