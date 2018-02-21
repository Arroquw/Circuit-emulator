#pragma once
#include <fstream>
#include <list>
#include <string>
#include <iterator>
#include "NodeFactory.h"
#include "IOclass.h"
#include <vector>

class filereader {
public:
    explicit filereader(std::string path);
    virtual ~filereader();
    virtual void ReadFile();
    virtual void DisplayList();
    virtual std::map<std::string, std::string> getTypes();
private:
    std::ifstream my_file_;
    std::map<std::string, std::string> types_;
    std::map<std::string, std::string> links_;
    int amount_links_;
    int amount_types_;
};
