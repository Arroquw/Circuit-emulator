#include "NotNode.h"
#include <iostream>

NotNode NotNode::m_cStaticMember_("NOT");

NotNode::NotNode() {
}

NotNode::NotNode(const char* szID) : Node(szID) {
}


Node* NotNode::clone() const {
    return new NotNode;
}

void NotNode::action() const {
    std::cout << "NOT" << std::endl;
}

void NotNode::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

NotNode::~NotNode() {
}
