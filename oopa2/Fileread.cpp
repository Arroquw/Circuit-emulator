#include "Fileread.h"
#include <algorithm>
#include <iostream>

Filereader::Filereader(const std::string path) {
    my_file_.open(path);
    amount_inputs_ = 0;
    amount_outputs_ = 0;
}

Filereader::~Filereader() {
}

void Filereader::ReadFile() {
    std::string tmp;
    auto cnt = 0;
    if (my_file_.is_open()) {
        while (getline(my_file_, tmp)) {
            if (tmp.find("edges") != std::string::npos) {
                cnt = 1;
            } else if (tmp.find("nodes") != std::string::npos) {
                cnt = 0;
            }
            tmp.erase(remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());
            tmp.erase(remove(tmp.begin(), tmp.end(), '\t'));
            if (tmp != "") {
                if (tmp.find('#') == std::string::npos) {
                    if (cnt) {
                        links_.push_back(tmp);
                    } else {
                        if(tmp.find("INPUT") != std::string::npos) {
                            amount_inputs_++;
                        } else if (tmp.find("PROBE") != std::string::npos) {
                            amount_outputs_++;
                        }
                        types_.push_back(tmp);
                    }
                }
            }
        }
        my_file_.close();
    } else {
        std::cout << "failed to open file";
    }
}

void Filereader::DisplayList() {
    std::cout << "types: \n";
    for (auto i = types_.begin(); i != types_.end(); ++i) {
        std::cout << *i << std::endl;
    }
    std::cout << "\n" << "links: \n";
    for (auto j = links_.begin(); j != links_.end(); ++j) {
        std::cout << *j << std::endl;
    }
    std::cout << std::endl;
}

const std::vector<std::string>& Filereader::GetTypes() {
    return types_;
}

const std::vector<std::string>& Filereader::GetLinks() {
    return links_;
}

int Filereader::GetAi() {
    return amount_inputs_;
}

int Filereader::GetAo() {
    return amount_outputs_;
}
