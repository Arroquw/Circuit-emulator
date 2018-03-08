#pragma once
#include "Node.h"
#include "CircuitVisitor.h"

class Probe :
    public Node {
public:
    Node* clone() const override;
    void action() override;
    void accept(CircuitVisitor& visitor) override;
    virtual ~Probe();
private:
    Probe();
    explicit Probe(const char*);
    static Probe m_cStaticMember_;
};

