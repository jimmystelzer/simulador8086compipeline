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
        std::string exec(std::string mnem, std::string dest, std::string src, std::string w, std::string param, std::string mod);
        std::string getCF();
        std::string getPF();
        std::string getAF();
        std::string getZF();
        std::string getSF();
        std::string getTF();
        std::string getIF();
        std::string getDF();
        std::string getOF();
};

#endif  //ALU_H
