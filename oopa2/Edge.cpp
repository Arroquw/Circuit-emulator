#include "Edge.h"

Edge::Edge() : input_value_(0) {
}

Edge::Edge(const std::string& name, const uint8_t value) {
    input_name_ = name;
    input_value_ = value;
}


Edge::~Edge() {
}

uint8_t Edge::GetInputValue() {
    return input_value_;
}

void Edge::SetValue(const uint8_t value) {
    input_value_ = value;
}

std::string& Edge::GetName() {
    return input_name_;
}

