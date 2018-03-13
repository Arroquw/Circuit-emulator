#pragma once
#include "Node.h"
#include "CircuitVisitor.h"

class NandNode :
	public Node {
public:
	Node* clone() const override;
	void action() override;
	void accept(CircuitVisitor& visitor) override;
	virtual ~NandNode();
private:
	NandNode();
	explicit NandNode(const char*);
	static NandNode m_cStaticMember_;
};

