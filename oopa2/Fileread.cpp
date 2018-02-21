
#include "Fileread.h"
#include <algorithm>

filereader::filereader(const std::string path) {
    my_file_.open(path);
    amount_links_ = 0;
    amount_types_ = 0;
}

filereader::~filereader() {

}

void filereader::ReadFile() {
    std::string tmp;
    auto cnt = 0;
    if (my_file_.is_open()) {
        while (getline(my_file_, tmp)) {
            if (tmp.find("edges") != std::string::npos) {
                cnt = 1;
            } else if (tmp.find("nodes") != std::string::npos) {
                cnt = 0;
            }
            if (tmp != "") {
                if (tmp.find('#') == std::string::npos) {
                    if (cnt) {
                        if (tmp.find(',')) {
                            for (auto i = tmp.begin(); i != tmp.end(); ++i) {
                                if (*i == ',') {
                                    amount_links_++;
                                }
                            }
                        }
                        amount_links_++;
                        tmp.erase(std::remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());
                        tmp.erase(remove(tmp.begin(), tmp.end(), '\t'));
                        links_.push_back(tmp + "\n");
                    } else {
                        tmp.erase(std::remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());
                        tmp.erase(remove(tmp.begin(), tmp.end(), '\t'));
                        amount_types_++;
                        types_.push_back(tmp + "\n");
                    }
                }
            }
        }
        my_file_.close();
        std::cout << amount_types_ << std::endl;
        std::cout << amount_links_ << std::endl;
        DisplayList();
    } else {
        std::cout << "failed to open file";
    }
}

void filereader::DisplayList() {
    std::cout << "types: \n";
    for (auto i = types_.begin(); i != types_.end(); ++i) {
        std::cout << *i;
    }
    std::cout << "\n" << "links: \n";
    for (auto j = links_.begin(); j != links_.end(); ++j) {
        std::cout << *j;
    }
}
