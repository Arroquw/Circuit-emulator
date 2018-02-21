#pragma once
#include <string>

enum IO {
    input,
    output
};

class IOclass {
public:
    IOclass();
    IOclass(IO pType, int pValue, std::string name);
    ~IOclass();
private:
    int value;
    std::string handle;
    IO type;
};

