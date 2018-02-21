#include "XorNode.h"

XorNode XorNode::m_cStaticMember_("XOR");

XorNode::XorNode() {
}

XorNode::XorNode(const char* szID) : Node(szID) {
}


Node* XorNode::clone() const {
    return new XorNode;
}

void XorNode::action() const
{
}

void XorNode::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

XorNode::~XorNode() {
}
