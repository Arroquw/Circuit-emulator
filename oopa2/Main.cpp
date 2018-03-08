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
    try {
        a.CreateEdges();
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl << " Press enter to continue" << std::endl;
        std::cin.get();
        return -1;
    }
    a.DriveValues();
    std::cin.get();
    return 0;
}
