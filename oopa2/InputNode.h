#pragma once
#include "Node.h"
#include "CircuitVisitor.h"

class InputNode :
    public Node {
public:
    Node* clone() const override;
    void action() override;
    void accept(CircuitVisitor& visitor) override;
    virtual ~InputNode();
private:
    InputNode();
    explicit InputNode(const char*);
    static InputNode m_c_static_member_;
};