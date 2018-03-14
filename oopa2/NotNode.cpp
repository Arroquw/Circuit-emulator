#include "NotNode.h"
#include <iostream>
#include <algorithm>

NotNode NotNode::m_c_static_member_("NOT");

NotNode::NotNode() {
}

NotNode::NotNode(const char* szID) : Node(szID) {
}


Node* NotNode::clone() const {
    return new NotNode;
}

void NotNode::action() {
    std::cout << GetName() << ", NOT:\n";
    std::for_each(GetNodes().begin(), GetNodes().end(), [](Node* x) {std::cout << x->GetName() << std::endl;});
}

void NotNode::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

NotNode::~NotNode() {
}
