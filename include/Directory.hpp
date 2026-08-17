#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include "Node.hpp"

#include <memory>
#include <vector>

class Directory : public Node {
private:
    std::vector<std::unique_ptr<Node>> children;

public:
    Directory(const std::string& name, Directory* parent);

    bool isDirectory() const override;

    bool add(std::unique_ptr<Node> node);
    bool remove(const std::string& name);

    Node* find(const std::string& name) const;

    void ls() const;
};

#endif