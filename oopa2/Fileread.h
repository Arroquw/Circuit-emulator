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
private:
    std::ifstream my_file_;
    std::vector<std::string> types_;
    std::vector<std::string> links_;
};
