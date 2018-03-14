#pragma once
#include "Node.h"
#include  "CircuitVisitor.h"

class NorNode :
	public Node {
public:
	Node * clone() const override;
	void action() override;
	void accept(CircuitVisitor& visitor) override;
	virtual ~NorNode();
private:
	NorNode();
	explicit NorNode(const char*);
	static NorNode m_c_static_member_;
};
