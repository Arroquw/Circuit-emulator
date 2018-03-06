#pragma once
#include "Node.h"
#include "CircuitVisitor.h"

class OrNode :
    public Node {
public:
    Node * clone() const override;
    void action() override;
    void accept(CircuitVisitor& visitor) override;
    virtual ~OrNode();
private:
    OrNode();
    explicit OrNode(const char*);
    static OrNode m_cStaticMember_;
};

