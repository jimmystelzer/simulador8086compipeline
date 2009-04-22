#ifndef CONTROL_H
#define CONTROL_H
#include <string>
#include "Helpers.h"

class Control{
    private:
        std::string *rD, *rS, *Mneumonic, *param, *mod, *w;
        Helpers *hp;
    public:
        Control();
        void setOpcode(std::string opcode);
        std::string getMneumonic();
        std::string getRD();
        std::string getRS();
        std::string getParam();
};

#endif  //CONTROL_H
