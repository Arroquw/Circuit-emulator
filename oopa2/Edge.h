#pragma once

#include "Fileread.h"

class Edge {
public:
    Edge();
    Edge(const std::string&, const uint8_t);
    virtual ~Edge();
    virtual uint8_t GetInputValue();
    virtual void SetValue(uint8_t value);
    virtual std::string& GetName();
private:
    std::string input_name_;
    uint8_t input_value_;
};

