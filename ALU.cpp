#include "ALU.h"

ALU::ALU(){
    this->hp = new Helpers();
}
std::string ALU::doOp(std::string m, std::string d, std::string s){
    int a, b, c;
    std::string tmp;

    if(m.compare("ADD")==0){
        a = this->hp->stringToInt(this->hp->baseToInt(d,16)); //converte pra dec
        b = this->hp->stringToInt(this->hp->baseToInt(s,16)); //converte pra dec
        c = a + b; // opera
        if (c < 0){
            this->SF = true;
        }
        if (c == 0){
            this->ZF = true;
        }
        if (c > 65535){
            this->CF = true;
        }
        tmp = this->hp->intToBase(c,16); //converte pra hexa

    }else if(m.compare("JZ")==0){

    }

    return tmp;
}

bool ALU::getCF(){
    return this->CF;
}
bool ALU::getPF(){
    return this->PF;
}
bool ALU::getAF(){
    return this->AF;
}
bool ALU::getZF(){
    return this->ZF;
}
bool ALU::getSF(){
    return this->SF;
}
bool ALU::getTF(){
    return this->TF;
}
bool ALU::getIF(){
    return this->IF;
}
bool ALU::getDF(){
    return this->DF;
}
bool ALU::getOF(){
    return this->OF;
}
