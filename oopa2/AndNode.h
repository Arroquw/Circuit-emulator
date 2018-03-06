#pragma once
#include "Node.h"
#include "CircuitVisitor.h"

class AndNode :
    public Node {
public:
    Node* clone() const override;
    void action() override;
    void accept(CircuitVisitor& visitor) override;
    virtual ~AndNode();
private:
    AndNode();
    explicit AndNode(const char*);
    static AndNode m_cStaticMember_;
};

