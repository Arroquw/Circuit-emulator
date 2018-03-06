#include "Fileread.h"
#include "Node.h"
#include "NodeFactory.h"
#include "CircuitVisitor.h"
#include <iostream>
#include "CircuitDriver.h"

void checkForLeaks() {
#ifdef _DEBUG
    int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    flag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(flag);
#endif
}

int main(int argc, char *argv[]) {
    checkForLeaks();
    CircuitDriver a(argv[1]);
    a.CreateNodes();
    a.CreateEdges();
    std::cin.get();
    return 0;
}
