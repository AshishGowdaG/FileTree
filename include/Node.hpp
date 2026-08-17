#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Directory;

class Node {
protected:
    std::string name;
    Directory* parent;

public:
    Node(const std::string& name, Directory* parent);
    virtual ~Node() = default;

    std::string getName() const;
    Directory* getParent() const;

    virtual bool isDirectory() const = 0;
};

#endif