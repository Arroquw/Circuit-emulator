#include "CircuitDriver.h"
#include "Node.h"
#include <vld.h>
#include <iostream>
#include <algorithm>

CircuitDriver::CircuitDriver() : reader_("") {
}

CircuitDriver::CircuitDriver(const std::string path) : reader_(path) {
    reader_.ReadFile();
}

CircuitDriver::~CircuitDriver() {
    for (auto eleme_node : nodes_) {
        delete eleme_node.second;
    }
}

void CircuitDriver::CreateNodes() {
    auto f = [](auto i) -> int {
        if (i.find("HIGH") != std::string::npos)
            return 1;
        else
            return 0;
    };
    auto types = reader_.GetTypes();
    for (auto i = types.begin(); i != types.end(); ++i) {
        if (i->second.find("INPUT") != std::string::npos) {
        } else {
            i->second.pop_back();
            nodes_.insert(make_pair(i->first, NodeFactory::create(i->second.c_str())));
            nodes_[i->first]->SetName(i->first);
        }
    }
}

void CircuitDriver::CreateEdges() {
    auto f = [](auto i) { if (i.find("HIGH") != std::string::npos) {
        return 1;
    } else
        return 0;
    };
    auto links = reader_.GetLinks();
    auto types = reader_.GetTypes();
    for (auto l : links) {
        if (l.first.find("NODE") == std::string::npos) {
            std::string placeholder;
            if ((placeholder = l.second) != "") {
                placeholder.pop_back();
                const auto delimiter = ',';
                size_t pos;
                while ((pos = placeholder.find(delimiter)) != std::string::npos) {
                    const auto token = placeholder.substr(0, pos);
                    nodes_[token]->Attach(new Edge(l.first, f(types[l.first])));
                    placeholder.erase(0, pos + 1);
                }
                nodes_[placeholder]->Attach(new Edge(l.first, f(types[l.first])));
            }
        } else {
            std::string placeholder;
            if ((placeholder = l.second) != "") {
                placeholder.pop_back();
                const auto delimiter = ',';
                size_t pos;
                while ((pos = placeholder.find(delimiter)) != std::string::npos) {
                    const auto token = placeholder.substr(0, pos);
                    nodes_[token]->Attach(new Edge(l.first, f(types[l.first])));
                    placeholder.erase(0, pos + 1);
                }
                nodes_[placeholder]->Attach(new Edge(l.first, f(types[l.first])));
            }
        }
    }
}

void CircuitDriver::DriveValues() {
    for (auto c : nodes_) {
        if (c.second->GetName().find("NODE") != std::string::npos) {
            auto edges = c.second->GetEdges();
            std::for_each(edges.begin(), edges.end(),
                [this](Edge* x) {
                auto z = x->GetName();
                if (nodes_[z] != nullptr) {
                    x->SetValue(nodes_[z]->GetValue());
                }
            });

            c.second->accept(visitor_);
        }
        std::cout << c.second->GetName() << ": " << static_cast<int>(c.second->GetValue()) << std::endl;
    }
}
