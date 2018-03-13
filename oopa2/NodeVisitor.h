#pragma once

class InputNode;
class Probe;
class XorNode;
class NotNode;
class OrNode;
class AndNode;
class NandNode;
class NorNode;

class NodeVisitor {
public:
    virtual ~NodeVisitor() = default;
    virtual void visit(AndNode*) = 0;
	virtual void visit(NandNode*) = 0;
    virtual void visit(OrNode*) = 0;
    virtual void visit(NotNode*) = 0;
    virtual void visit(XorNode*) = 0;
	virtual void visit(NorNode*) = 0;
    virtual void visit(Probe*) = 0;
    virtual void visit(InputNode*) = 0;
};

