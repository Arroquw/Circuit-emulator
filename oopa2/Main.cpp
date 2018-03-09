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
    auto a = new CircuitDriver(argv[1]);
    a->CreateNodes();
    a->CreateEdges();
    try {
        a->DriveValues();
    }catch(const std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        std::cout << "Press enter to exit" << std::endl;
        std::cin.get();
        delete a;
        return -1;
    }
    std::cin.get();
    delete a;
    return 0;
}
