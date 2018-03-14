#include "CircuitVisitor.h"
#include "AndNode.h"
#include "OrNode.h"
#include "NotNode.h"
#include "XorNode.h"
#include "Probe.h"
#include "NorNode.h"
#include "NandNode.h"
#include "InputNode.h"

void CircuitVisitor::visit(AndNode* p_node) {
    auto tmp = 1;
    if (p_node->GetNodes().size() > 1) {
        for (auto i = 0u; i < p_node->GetNodes().size(); ++i)
            tmp &= p_node->GetNodes()[i]->GetValue();
    } else {
        tmp = 100;
    }
    p_node->SetValue(tmp);
}

void CircuitVisitor::visit(NandNode* p_node) {
	auto tmp = 0;
    if (p_node->GetNodes().size() > 1) {
        for (auto i = 0u; i < p_node->GetNodes().size(); ++i) {
            tmp &= p_node->GetNodes()[i]->GetValue();
            tmp = ~tmp;
        }
    } else {
        tmp = 100;
    }
    p_node->SetValue(tmp);
}

void CircuitVisitor::visit(OrNode* p_node) {
    auto tmp = 0;
    if (p_node->GetNodes().size() > 1) {
        for (auto i = 0u; i < p_node->GetNodes().size(); ++i)
            tmp |= p_node->GetNodes()[i]->GetValue();
    } else {
        tmp = 100;
    }
    p_node->SetValue(tmp);
}

void CircuitVisitor::visit(NotNode* p_node) {
    if (p_node->GetNodes().size() > 0 && p_node->GetNodes().size() < 2)
        p_node->SetValue(!p_node->GetNodes()[0]->GetValue());
}

void CircuitVisitor::visit(XorNode* p_node) {
    auto tmp = 0;
    if (p_node->GetNodes().size() > 1) {
        for (auto i = 0u; i < p_node->GetNodes().size(); ++i)
            tmp ^= p_node->GetNodes()[i]->GetValue();
    } else {
        tmp = 100;
    }
    p_node->SetValue(tmp);
}

void CircuitVisitor::visit(NorNode* p_node) {
	auto tmp = 0;
    if (p_node->GetNodes().size() > 1) {
        for (auto i = 0u; i < p_node->GetNodes().size(); ++i) {
            tmp |= p_node->GetNodes()[i]->GetValue();
            tmp = ~tmp;
        }
    } else {
        tmp = 100;
    }
	p_node->SetValue(tmp);
}

void CircuitVisitor::visit(Probe* p_node) {
    if (p_node->GetNodes().size() > 0 && p_node->GetNodes().size() < 2)
        p_node->SetValue(p_node->GetNodes()[0]->GetValue());
    else
        p_node->SetValue(100);
}

void CircuitVisitor::visit(InputNode* p_node) {
    if(p_node->GetNodes().size() > 0) {
        p_node->SetValue(100);
    }
}
