#include "Node.h"
#include "NodeFactory.h"


Node::Node(const char * szID) {
    NodeFactory::assign(szID, this);
}

Node::Node() {
}


Node::~Node() {
}
