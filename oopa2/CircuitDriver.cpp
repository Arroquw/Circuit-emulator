#include "CircuitDriver.h"
#include "Node.h"
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#include <iostream>

CircuitDriver::CircuitDriver() : reader_("") {
}

CircuitDriver::CircuitDriver(const std::string path) : reader_(path) {
    reader_.ReadFile();
}

CircuitDriver::~CircuitDriver() {
    for (auto eleme_node : nodes_) {
        delete eleme_node;
    }
}

void CircuitDriver::CreateNodes() {
    auto types = reader_.GetTypes();
    for (auto i = types.begin(); i != types.end(); ++i) {
        if (i->second.find("INPUT") != std::string::npos) {
            
        } else if (i->second.find("PROBE") != std::string::npos) {
            
        } else {
            static auto n = 0;
            i->second.pop_back();
            nodes_.push_back(NodeFactory::create(i->second.c_str()));
            nodes_[n]->SetName(i->first);
            n++;
        }
    }
}

void CircuitDriver::CreateEdges() {
    auto links = reader_.GetLinks();
    for (auto c : nodes_) {
        auto placeholder = links[c->GetName()];
        placeholder.pop_back();
        const auto delimiter = ',';
        size_t pos;
        while ((pos = placeholder.find(delimiter)) != std::string::npos) {
            const auto token = placeholder.substr(0, pos);
            c->Attach(new Edge(token, 0));
            placeholder.erase(0, pos + 1);
        }
        c->Attach(new Edge(placeholder, 0));
        c->action();
    }
}
