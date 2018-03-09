#include "NandNode.h"
#include <iostream>
#include <algorithm>

NandNode NandNode::m_cStaticMember_("NAND");

NandNode::NandNode() {
}

NandNode::NandNode(const char* szID) : Node(szID) {
}

Node* NandNode::clone() const {
	return new NandNode;
}

void NandNode::action() {
	std::cout << GetName() << ", NAND " << ":\n";
	std::for_each(GetNodes().begin(), GetNodes().end(), [](Node* x) {std::cout << x->GetName() << std::endl; });
}

void NandNode::accept(CircuitVisitor& visitor) {
	visitor.visit(this);
}

NandNode::~NandNode() {
}
