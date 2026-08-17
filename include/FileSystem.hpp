#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include "Directory.hpp"

#include <memory>
#include <string>

class FileSystem {
private:
    std::unique_ptr<Directory> root;
    Directory* current;

public:
    FileSystem();

    void mkdir(const std::string& name);
    void touch(const std::string& name);
    void rm(const std::string& name);

    void cd(const std::string& name);
    void ls() const;
    void pwd() const;
};

#endif