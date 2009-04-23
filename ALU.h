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
        std::string exec(std::string m, std::string d, std::string s, std::string w, std::string p, std::string mod);
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
