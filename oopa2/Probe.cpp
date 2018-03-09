#include "Probe.h"
#include <iostream>
#include <algorithm>

Probe Probe::m_cStaticMember_("PROBE");

Probe::Probe() {
}

Probe::Probe(const char* szID) : Node(szID) {
}

Node* Probe::clone() const {
    return new Probe;
}

void Probe::action() {
    std::cout << GetName() << ", Probe " << ":\n";
    std::for_each(GetNodes().begin(), GetNodes().end(), [](Node* x) {std::cout << x->GetName() << std::endl; });
}

void Probe::accept(CircuitVisitor& visitor) {
    visitor.visit(this);
}

Probe::~Probe() {
}
