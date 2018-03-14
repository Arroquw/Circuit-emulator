#include "Fileread.h"
#include "Node.h"
#include <iostream>
#include "CircuitDriver.h"

int main(int argc, char *argv[]) {
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
