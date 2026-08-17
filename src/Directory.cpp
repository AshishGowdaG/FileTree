#include "Directory.hpp"

#include <iostream>

Directory::Directory(const std::string& name, Directory* parent)
    : Node(name, parent) {}

bool Directory::isDirectory() const {
    return true;
}

bool Directory::add(std::unique_ptr<Node> node) {
    if (find(node->getName()) != nullptr) {
        return false;
    }

    children.push_back(std::move(node));
    return true;
}

bool Directory::remove(const std::string& name) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if ((*it)->getName() == name) {
            children.erase(it);
            return true;
        }
    }

    return false;
}

Node* Directory::find(const std::string& name) const {
    for (const auto& child : children) {
        if (child->getName() == name) {
            return child.get();
        }
    }

    return nullptr;
}

void Directory::ls() const {
    for (const auto& child : children) {
        if (child->isDirectory())
            std::cout << child->getName() << "/\n";
        else
            std::cout << child->getName() << "\n";
    }
}