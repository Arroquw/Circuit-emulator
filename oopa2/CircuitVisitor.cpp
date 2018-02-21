#include "CircuitVisitor.h"
#include "AndNode.h"
#include "OrNode.h"
#include "NotNode.h"
#include "XorNode.h"

void CircuitVisitor::visit(AndNode* pNode) {
    // output = input1 & input2;
}

void CircuitVisitor::visit(OrNode* pNode) {
    // output = input1 | input2;
}

void CircuitVisitor::visit(NotNode* pNode) {
    // output = !input;
}

void CircuitVisitor::visit(XorNode* pNode) {
    // output = input1 ^ input2;
}
