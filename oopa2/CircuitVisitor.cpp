#include "CircuitVisitor.h"
#include "AndNode.h"
#include "OrNode.h"
#include "NotNode.h"
#include "XorNode.h"
#include "Probe.h"
#include "NorNode.h"
#include "NandNode.h"
#include "InputNode.h"

void CircuitVisitor::visit(AndNode* pNode) {
    auto tmp = 1;
    if (pNode->GetNodes().size() > 1) {
        for (auto i = 0u; i < pNode->GetNodes().size(); ++i)
            tmp &= pNode->GetNodes()[i]->GetValue();
    } else {
        tmp = 100;
    }
    pNode->SetValue(tmp);
}

void CircuitVisitor::visit(NandNode* pNode) {
	auto tmp = 0;
    if (pNode->GetNodes().size() > 1) {
        for (auto i = 0u; i < pNode->GetNodes().size(); ++i) {
            tmp &= pNode->GetNodes()[i]->GetValue();
            tmp = ~tmp;
        }
    } else {
        tmp = 100;
    }
    pNode->SetValue(tmp);
}

void CircuitVisitor::visit(OrNode* pNode) {
    auto tmp = 0;
    if (pNode->GetNodes().size() > 1) {
        for (auto i = 0u; i < pNode->GetNodes().size(); ++i)
            tmp |= pNode->GetNodes()[i]->GetValue();
    } else {
        tmp = 100;
    }
    pNode->SetValue(tmp);
}

void CircuitVisitor::visit(NotNode* pNode) {
    if (pNode->GetNodes().size() > 0 && pNode->GetNodes().size() < 2)
        pNode->SetValue(!pNode->GetNodes()[0]->GetValue());
}

void CircuitVisitor::visit(XorNode* pNode) {
    auto tmp = 0;
    if (pNode->GetNodes().size() > 1) {
        for (auto i = 0u; i < pNode->GetNodes().size(); ++i)
            tmp ^= pNode->GetNodes()[i]->GetValue();
    } else {
        tmp = 100;
    }
    pNode->SetValue(tmp);
}

void CircuitVisitor::visit(NorNode* pNode) {
	auto tmp = 0;
    if (pNode->GetNodes().size() > 1) {
        for (auto i = 0u; i < pNode->GetNodes().size(); ++i) {
            tmp |= pNode->GetNodes()[i]->GetValue();
            tmp = ~tmp;
        }
    } else {
        tmp = 100;
    }
	pNode->SetValue(tmp);
}

void CircuitVisitor::visit(Probe* pNode) {
    if (pNode->GetNodes().size() > 0 && pNode->GetNodes().size() < 2)
        pNode->SetValue(pNode->GetNodes()[0]->GetValue());
    else
        pNode->SetValue(100);
}

void CircuitVisitor::visit(InputNode* pNode) {
    if(pNode->GetNodes().size() > 0) {
        pNode->SetValue(100);
    }
}
