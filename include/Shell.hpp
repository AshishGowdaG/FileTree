#ifndef SHELL_HPP
#define SHELL_HPP

#include "FileSystem.hpp"

class Shell {
private:
    FileSystem fs;

public:
    void run();
};

#endif