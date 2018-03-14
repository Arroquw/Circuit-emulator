#pragma once
#include "Fileread.h"
#include "CircuitVisitor.h"
#include "Node.h"

class CircuitDriver {
public:
    CircuitDriver();
    explicit CircuitDriver(const std::string path);
    virtual ~CircuitDriver();
    virtual void CreateNodes();
    virtual void CreateEdges();
    virtual void DriveValues();
    virtual Node* FindValue(std::vector<Node*> vec, std::string);
private:
    Filereader reader_;
    CircuitVisitor visitor_;
    std::vector<Node*> nodes_;
};

