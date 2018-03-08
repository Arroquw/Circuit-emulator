#pragma once

class Probe;
class XorNode;
class NotNode;
class OrNode;
class AndNode;

class NodeVisitor {
public:
    virtual ~NodeVisitor() = default;
    virtual void visit(AndNode*) = 0;
    virtual void visit(OrNode*) = 0;
    virtual void visit(NotNode*) = 0;
    virtual void visit(XorNode*) = 0;
    virtual void visit(Probe*) = 0;
};

