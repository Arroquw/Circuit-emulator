#pragma once
#include "NodeVisitor.h"
class CircuitVisitor :
    public NodeVisitor {
public:
    void visit(AndNode*) override;
    void visit(OrNode*) override;
    void visit(NotNode*) override;
    void visit(XorNode*) override;
};

