#ifndef FILE_HPP
#define FILE_HPP

#include "Node.hpp"

class File : public Node {
public:
    File(const std::string& name, Directory* parent);

    bool isDirectory() const override;
};

#endif