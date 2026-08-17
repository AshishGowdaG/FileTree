#include "FileSystem.hpp"
#include "File.hpp"

#include <iostream>

FileSystem::FileSystem()
    : root(std::make_unique<Directory>("/", nullptr)),
      current(root.get()) {}

void FileSystem::mkdir(const std::string& name) {
    if (current->find(name) != nullptr) {
        std::cout << "Already exists\n";
        return;
    }

    auto dir = std::make_unique<Directory>(name, current);

    current->add(std::move(dir));
}

void FileSystem::touch(const std::string& name) {
    if (current->find(name) != nullptr) {
        std::cout << "Already exists\n";
        return;
    }

    auto file = std::make_unique<File>(name, current);

    current->add(std::move(file));
}

void FileSystem::rm(const std::string& name) {
    if (!current->remove(name)) {
        std::cout << "Not found\n";
    }
}

void FileSystem::cd(const std::string& name) {

    if (name == "..") {
        if (current->getParent() != nullptr)
            current = current->getParent();

        return;
    }

    Node* node = current->find(name);

    if (node == nullptr || !node->isDirectory()) {
        std::cout << "Directory not found\n";
        return;
    }

    current = static_cast<Directory*>(node);
}

void FileSystem::ls() const {
    current->ls();
}

void FileSystem::pwd() const {
    std::string path;
    Directory* temp = current;

    while (temp != root.get()) {
        path = "/" + temp->getName() + path;
        temp = temp->getParent();
    }

    if (path.empty())
        path = "/";

    std::cout << path << "\n";
}