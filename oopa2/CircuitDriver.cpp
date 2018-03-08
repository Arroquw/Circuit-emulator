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
        } else if (i->second.find("PROBE") != std::string::npos) {
        } else {
            i->second.pop_back();
            nodes_.insert(make_pair(i->first, NodeFactory::create(i->second.c_str())));
            nodes_[i->first]->SetName(i->first);
        }
    }
}

void CircuitDriver::CreateEdges() {
    auto links = reader_.GetLinks();
    for (auto c : nodes_) {
        std::string placeholder;
        if ((placeholder = links[c.second->GetName()]) != "") {
            placeholder.pop_back();
            const auto delimiter = ',';
            size_t pos;
            while ((pos = placeholder.find(delimiter)) != std::string::npos) {
                const auto token = placeholder.substr(0, pos);
                c.second->Attach(new Edge(token, 0));
                placeholder.erase(0, pos + 1);
            }
            c.second->Attach(new Edge(placeholder, 0));
            c.second->action();
        } else {
            throw std::invalid_argument("Unconnected Node(s) found! Please make sure every node is connected to at least one other Node.");
        }
    }
}

void CircuitDriver::DriveValues() {
    for (auto c : nodes_) {
        auto edges = c.second->GetEdges();
        std::for_each(edges.begin(), edges.end(),
            [this](Edge* x) {
            x->SetValue(nodes_[x->GetName()]->GetValue());
        });
        c.second->accept(visitor_);
    }
}
