#include "Node.hpp"

Node::Node(const std::string& name, Directory* parent)
    : name(name), parent(parent) {}

std::string Node::getName() const {
    return name;
}

Directory* Node::getParent() const {
    return parent;
}