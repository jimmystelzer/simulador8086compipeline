#ifndef CONTROL_H
#define CONTROL_H
#include <string>
#include "Helpers.h"

class Control{
    private:
        std::string *rD, *rS, *Mneumonic, *param, *mod, *w, *ex, *mem, *wb;
        Helpers *hp;
    public:
        Control();
        void setOpcode(std::string opcode);
        std::string getMneumonic();
        std::string getRD();
        std::string getRS();
        std::string getParam();
        std::string getMod();
        std::string getW();
        std::string getEX();
        std::string getMEM();
        std::string getWB();
};

#endif  //CONTROL_H
