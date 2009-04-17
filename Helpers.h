#ifndef TOOL_H
#define TOOL_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cmath>


class Helpers{
    private:

    public:
        Helpers();
        std::string intToBase(unsigned int num, unsigned int b);
        std::string baseToInt(unsigned int num, unsigned int b);
        std::string baseToInt(std::string num, unsigned int b);
        std::string readFile(std::string filename);
        inline int stringToInt(const std::string& s);

};
#endif  //MEMORIA_H
