#include "XorNode.h"
#include <iostream>
#include <algorithm>

XorNode XorNode::m_c_static_member_("XOR");

XorNode::XorNode() {
}

XorNode::XorNode(const char* szID) : Node(szID) {
}


Node* XorNode::clone() const {
    return new XorNode;
}

void XorNode::action() {
    std::cout << GetName() << ", XOR:\n";
    std::for_each(GetNodes().begin(), GetNodes().end(), [](Node* x) {std::cout << x->GetName() << std::endl;});
}


void XorNode::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

XorNode::~XorNode() {
}
