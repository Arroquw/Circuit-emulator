#include "CircuitVisitor.h"
#include "AndNode.h"
#include "OrNode.h"
#include "NotNode.h"
#include "XorNode.h"

void CircuitVisitor::visit(AndNode* pNode) {
    auto tmp = pNode->GetValue();
    for (auto i = 0u; i < pNode->GetEdges().size(); ++i)
        tmp &= pNode->GetEdges()[i]->GetInputValue();
    pNode->SetValue(tmp);
}

void CircuitVisitor::visit(OrNode* pNode) {
    auto tmp = pNode->GetValue();
    for (auto i = 0u; i < pNode->GetEdges().size(); ++i)
        tmp |= pNode->GetEdges()[i]->GetInputValue();
    pNode->SetValue(tmp);
}

void CircuitVisitor::visit(NotNode* pNode) {
    pNode->SetValue(!pNode->GetEdges()[0]->GetInputValue());
}

void CircuitVisitor::visit(XorNode* pNode) {
    auto tmp = pNode->GetValue();
    for (auto i = 0u; i < pNode->GetEdges().size(); ++i)
        tmp ^= pNode->GetEdges()[i]->GetInputValue();
    pNode->SetValue(tmp);
}
