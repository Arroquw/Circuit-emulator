#pragma once
#include "NodeVisitor.h"

class NorNode;

class CircuitVisitor :
    public NodeVisitor {
public:
    void visit(AndNode*) override;
	void visit(NandNode*) override;
    void visit(OrNode*) override;
    void visit(NotNode*) override;
    void visit(XorNode*) override;
	void visit(NorNode*) override;
    void visit(Probe*) override;
    void visit(InputNode*) override;
};

