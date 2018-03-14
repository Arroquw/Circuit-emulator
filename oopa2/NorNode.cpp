#include "NorNode.h"
#include <iostream>
#include <algorithm>

NorNode NorNode::m_c_static_member_("NOR");

NorNode::NorNode() {
}

NorNode::NorNode(const char* szID) : Node(szID) {
}


Node* NorNode::clone() const {
	return new NorNode;
}

void NorNode::action() {
	std::cout << GetName() << ", NOR:\n";
	std::for_each(GetNodes().begin(), GetNodes().end(), [](Node* x) {std::cout << x->GetName() << std::endl; });
}


void NorNode::accept(CircuitVisitor& visitor) {
	visitor.visit(this);
}

NorNode::~NorNode() {
}
