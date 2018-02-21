#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <iterator>

class filereader;

class filereader {
 public:
    explicit filereader(std::string path);
    virtual ~filereader();
    virtual void ReadFile();
    virtual void DisplayList();
 private:
    std::ifstream my_file_;
    std::list<std::string> types_;
    std::list<std::string> links_;
    int amount_links_;
    int amount_types_;
};