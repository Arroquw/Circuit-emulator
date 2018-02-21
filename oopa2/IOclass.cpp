#include "IOclass.h"


IOclass::IOclass(): value(0), type() {
}

IOclass::IOclass(IO pType, int pValue, std::string name) {
    type = pType;
    value = pValue;
    handle = name;
}


IOclass::~IOclass() {
}
