#include "InputNode.h"
#include <iostream>
#include <algorithm>

InputNode InputNode::m_cStaticMember_("INPUT");

InputNode::InputNode() {
}

InputNode::InputNode(const char* szID) : Node(szID) {
}

Node* InputNode::clone() const {
    return new InputNode;
}

void InputNode::action() {
    if (!GetNodes().empty()) {
        std::cout << GetName() << ", Input " << ":\n";
        std::for_each(GetNodes().begin(), GetNodes().end(), [](Node* x) {std::cout << x->GetName() << std::endl; });
    }
}

void InputNode::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

InputNode::~InputNode() {
}