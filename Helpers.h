#ifndef TOOL_H
#define TOOL_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

class Helpers{
    private:

    public:
        Helpers();
        std::string intToBase(unsigned int num, unsigned int b);

        std::string readFile(std::string filename);
};

#endif  //MEMORIA_H
