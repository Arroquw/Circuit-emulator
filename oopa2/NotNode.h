#pragma once
#include "Node.h"
#include "CircuitVisitor.h"

class NotNode :
    public Node {
public:
    Node * clone() const override;
    void action() override;
    void accept(CircuitVisitor& visitor) override;
    virtual ~NotNode();
private:
    NotNode();
    explicit NotNode(const char*);
    static NotNode m_cStaticMember_;
};

