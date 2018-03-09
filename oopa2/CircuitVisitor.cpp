#include "CircuitVisitor.h"
#include "AndNode.h"
#include "OrNode.h"
#include "NotNode.h"
#include "XorNode.h"
#include "Probe.h"

void CircuitVisitor::visit(AndNode* pNode) {
    auto tmp = 1;
    for (auto i = 0u; i < pNode->GetNodes().size(); ++i)
        tmp &= pNode->GetNodes()[i]->GetValue();
    pNode->SetValue(tmp);
}

void CircuitVisitor::visit(OrNode* pNode) {
    auto tmp = 0;
    for (auto i = 0u; i < pNode->GetNodes().size(); ++i)
        tmp |= pNode->GetNodes()[i]->GetValue();
    pNode->SetValue(tmp);
}

void CircuitVisitor::visit(NotNode* pNode) {
    pNode->SetValue(!pNode->GetNodes()[0]->GetValue());
}

void CircuitVisitor::visit(XorNode* pNode) {
    auto tmp = 0;
    for (auto i = 0u; i < pNode->GetNodes().size(); ++i)
        tmp ^= pNode->GetNodes()[i]->GetValue();
    pNode->SetValue(tmp);
}

void CircuitVisitor::visit(Probe* pNode) {
    pNode->SetValue(pNode->GetNodes()[0]->GetValue());
}

void CircuitVisitor::visit(InputNode*) {
}
