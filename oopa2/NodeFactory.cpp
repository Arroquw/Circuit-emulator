#include "NodeFactory.h"
#include <cassert>
#include "Node.h"


NodeFactory::NodeFactory() {
}


NodeFactory::~NodeFactory() {
}

void NodeFactory::assign(const char* szID, Node *base) {
    auto& cmap = getMap();
    assert(szID != nullptr);
    assert(*szID != '\0');
    assert(cmap.find(szID) == cmap.end());
    cmap[szID] = base;
}

NodeFactory::NodeMap& NodeFactory::getMap() {
    static NodeMap cMap;
    return cMap;
}

Node* NodeFactory::create(const char* szID) {
    auto& cmap = getMap();
    const NodeMap::const_iterator iFind = cmap.find(szID);
    if (iFind == cmap.end()) {
        return nullptr;
    }
    return iFind->second->clone();
}
