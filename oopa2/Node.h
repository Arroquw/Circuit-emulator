#pragma once
#include "CircuitVisitor.h"
#include <string>
#include <vector>
#include "Edge.h"

class Node {
public:
    Node();
    explicit Node(const char*);
    virtual ~Node();
    virtual Node* clone() const = 0;
    virtual void action() = 0;
    virtual void accept(CircuitVisitor& visitor) = 0;
    virtual void SetName(const std::string& name);
    virtual void SetValue(const uint8_t value);
    virtual std::string& GetName();
    virtual uint8_t GetValue();
    virtual std::vector<Edge*>& GetEdges();
    virtual void SetEdges(const std::vector<Edge*>&);
    virtual void Attach(Edge* edge);
private:
    std::vector<Edge*> edges_;
    std::string name_;
    uint8_t value_;
};

