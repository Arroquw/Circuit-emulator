#pragma once
#include "Fileread.h"
#include "CircuitVisitor.h"

class CircuitDriver {
public:
    CircuitDriver();
    explicit CircuitDriver(const std::string path);
    virtual ~CircuitDriver();
    virtual void CreateNodes();
    virtual void CreateEdges();
private:
    filereader reader_;
    CircuitVisitor visitor_;
    std::vector<Node*> nodes_;
};

