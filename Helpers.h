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
        std::ostringstream logString;
    public:
        Helpers();
        std::string intToBase(unsigned long long int num, unsigned int b);
        std::string baseToInt(unsigned int num, unsigned int b);
        std::string baseToInt(std::string num, unsigned int b);
        unsigned long long int stringToInt(const std::string& s);

        std::string binNegToPos(std::string s);
        std::string binPosToNeg(std::string s);

        std::string leadingZeroBin(std::string s);
        std::string leadingZero(std::string s, int b);
        std::string leadingZeroHex(std::string s);

        std::string readFile(std::string filename);
        std::string cleanFile(std::string s);

        void setLog(std::string s);
        std::string getLog();
        void cleanLog();
        void saveLog(std::string fileName);


};
#endif  //MEMORIA_H
