#ifndef ALU_H
#define ALU_H
#include <string>
#include "Helpers.h"

class ALU{
    private:
        Helpers *hp;
        bool CF,PF,AF,ZF,SF,TF,IF,DF,OF;
    public:
        ALU();
        std::string doOp(std::string m, std::string d, std::string s);
        bool getCF();
        bool getPF();
        bool getAF();
        bool getZF();
        bool getSF();
        bool getTF();
        bool getIF();
        bool getDF();
        bool getOF();
};

#endif  //ALU_H
