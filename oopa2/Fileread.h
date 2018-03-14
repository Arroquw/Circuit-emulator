#pragma once
#include <fstream>
#include <list>
#include <string>
#include <iterator>
#include <vector>

class Filereader {
public:
    explicit Filereader(std::string path);
    virtual ~Filereader();
    virtual void ReadFile();
    virtual void DisplayList();
    virtual const std::vector<std::string>& GetTypes();
    virtual const std::vector<std::string>& GetLinks();
    virtual int GetAi();
    virtual int GetAo();
private:
    std::ifstream my_file_;
    std::vector<std::string> types_;
    std::vector<std::string> links_;
    int amount_inputs_;
    int amount_outputs_;
};
