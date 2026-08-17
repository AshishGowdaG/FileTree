#include "Shell.hpp"

#include <iostream>
#include <sstream>

void Shell::run() {

    std::string input;

    while (true) {

        std::cout << "$ ";
        std::getline(std::cin, input);

        std::stringstream ss(input);

        std::string command;
        std::string argument;

        ss >> command;
        ss >> argument;

        if (command == "mkdir") {
            fs.mkdir(argument);
        }
        else if (command == "touch") {
            fs.touch(argument);
        }
        else if (command == "rm") {
            fs.rm(argument);
        }
        else if (command == "cd") {
            fs.cd(argument);
        }
        else if (command == "ls") {
            fs.ls();
        }
        else if (command == "pwd") {
            fs.pwd();
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Unknown command\n";
        }
    }
}
