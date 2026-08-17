#include "File.hpp"

File::File(const std::string& name, Directory* parent)
    : Node(name, parent) {}

bool File::isDirectory() const {
    return false;
}