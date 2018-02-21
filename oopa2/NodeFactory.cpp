#include "NodeFactory.h"
#include <cassert>


NodeFactory::NodeFactory() {
}


NodeFactory::~NodeFactory() {
}

void NodeFactory::assign(const char* szID, Node *base) {
    NodeMap cmap = getMap();
    assert(szID != nullptr);
    assert(*szID != '\0');
    assert(cmap.find(szID) == cmap.end());
    cmap[szID] = base;
}

Node* NodeFactory::create(const char* szID) {
    NodeMap& cmap = getMap();
    NodeMap::const_iterator iFind = cmap.find(szID);

    if (iFind == cmap.end()) {
        return nullptr;
    } 
    return iFind->second->clone();
}

