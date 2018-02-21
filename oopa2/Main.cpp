#include "Fileread.h"
#include "Node.h"
#include "NodeFactory.h"
#include "CircuitVisitor.h"
#include <iostream>

void checkForLeaks() {
#ifdef _DEBUG
    int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    flag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(flag);
#endif
}

int main(int argc, char *argv[]) {
    checkForLeaks();
    filereader a(argv[1]);
    a.ReadFile();
    CircuitVisitor visitor;
    auto types = a.getTypes();
    std::vector<Node*> nodes;
    IOclass * value = nullptr;
    NodeFactory * factory = nullptr;
    for (auto i = types.begin(); i != types.end(); ++i) {
        if (i->second.find("INPUT") != std::string::npos) {
            if (i->first.find("HIGH") != std::string::npos) {
               value = new IOclass(input, 1, i->first); //leaks
            } else {
               value = new IOclass(input, 0, i->first); //leaks
            }
        } else if (i->second.find("PROBE") != std::string::npos) {
            value = new IOclass(output, 0, i->first); //leaks
        } else {
            auto tmp = i->second;
            tmp.pop_back();
            nodes.push_back(factory->create(tmp.c_str()));
            static auto n = 0;
            nodes[n]->accept(visitor);
            n++;
        }
    }
    delete value;
    delete factory;
    for(auto i = 0u; i < nodes.size(); ++i) {
        delete nodes[i];
    }
    std::cin.get();
    return 0;
}
