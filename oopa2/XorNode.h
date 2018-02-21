#pragma once
#include "Node.h"
#include "CircuitVisitor.h"

class XorNode :
    public Node {
public:
    Node * clone() const override;
    void action() const override;
    void accept(CircuitVisitor& visitor) override;
    virtual ~XorNode();
private:
    XorNode();
    explicit XorNode(const char*);
    static XorNode m_cStaticMember_;
};

