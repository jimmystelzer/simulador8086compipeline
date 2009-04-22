#ifndef CONTROL_H
#define CONTROL_H
#include <string>
#include "Helpers.h"

class Control{
    private:
        std::string *rD, *rS, *Meneumonic;
        Helpers *hp;
    public:
        Control();
        void setOpcode(std::string opcode);
        std::string getMeneumonic();
        std::string getRD();
        std::string getRS();
};

#endif  //CONTROL_H
