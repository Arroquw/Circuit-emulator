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
    virtual void DriveValues();
private:
    filereader reader_;
    CircuitVisitor visitor_;
    std::map<std::string, Node*> nodes_;
};

