#include "ALU.h"

ALU::ALU(){
    this->hp = new Helpers();
}
std::string ALU::doOp(std::string m, std::string d, std::string s){
    bool bits8;
    int a, b;
    std::string tmp;
    if(m.compare("ADD")==0){
        if(d.length() == 4){
            bits8 = false;
        }else{
            bits8 = true;
        }
        a = this->hp->stringToInt(this->hp->baseToInt(d,16)); //converte pra dec
        b = this->hp->stringToInt(this->hp->baseToInt(s,16)); //converte pra dec
        a = a + b; // opera
        // .OF, .SF, .ZF, .AF, .PF, .CF
        if (a < 0){
            this->SF = true;
        }else{
            this->SF = false;
        }
        if (a == 0){
            this->ZF = true;
        }else{
            this->ZF = false;
        }
        if (a > 255 && bits8){
            this->CF = true;
        }else{
            this->CF = false;
        }
        if ((a < 128 || a > 127) && bits8){
            this->OF = true;
        }else{
            this->OF = false;
        }

        if (a > 65535 && !bits8){
            this->AF = true;
        }else{
            this->AF = false;
        }
        if (bits8){
            if(a%2 == 0){
                this->PF = true; //par
            }else{
                this->PF = false; //nãp par -> impar
            }
        }else{
            this->PF = false; //não par -> não avaliado
        }
        tmp = this->hp->intToBase(a,16); //converte pra hexa

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
