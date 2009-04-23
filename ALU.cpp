#include "ALU.h"

ALU::ALU(){
    this->hp = new Helpers();
    CF = false;
    PF = false;
    AF = false;
    ZF = false;
    SF = false;
    TF = false;
    IF = false;
    DF = false;
    OF = false;
}
std::string ALU::exec(std::string mnem, std::string dest, std::string src, std::string w, std::string param, std::string mod){

    if(mnem.compare("movregimmed")==0){
        dest = src;

    }
    return dest;
//    bool bits8;
//    int a, b;
//    std::string tmp;
//
//    if(m.compare("ADD")==0){
//        if(d.length() == 4){
//            bits8 = false;
//        }else{
//            bits8 = true;
//        }
//        a = this->hp->stringToInt(this->hp->baseToInt(d,16)); //converte pra dec
//        b = this->hp->stringToInt(this->hp->baseToInt(s,16)); //converte pra dec
//        a = a + b; // opera
//        // .OF, .SF, .ZF, .AF, .PF, .CF
//        if (a < 0){
//            this->SF = true;
//        }else{
//            this->SF = false;
//        }
//        if (a == 0){
//            this->ZF = true;
//        }else{
//            this->ZF = false;
//        }
//        if (a > 255 && bits8){
//            this->CF = true;
//        }else{
//            this->CF = false;
//        }
//        if ((a < 128 || a > 127) && bits8){
//            this->OF = true;
//        }else{
//            this->OF = false;
//        }
//
//        if (a > 65535 && !bits8){
//            this->AF = true;
//        }else{
//            this->AF = false;
//        }
//        if (bits8){
//            if(a%2 == 0){
//                this->PF = true; //par
//            }else{
//                this->PF = false; //nãp par -> impar
//            }
//        }else{
//            this->PF = false; //não par -> não avaliado
//        }
//        tmp = this->hp->intToBase(a,16); //converte pra hexa
//
//    }else if(m.compare("JZ")==0){
//
//    }
//
//    return tmp;
}

std::string ALU::getCF(){
    if (this->CF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getPF(){
    if (this->PF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getAF(){
    if (this->AF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getZF(){
    if (this->ZF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getSF(){
    if (this->SF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getTF(){
    if (this->TF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getIF(){
    if (this->IF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getDF(){
    if (this->DF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getOF(){
    if (this->OF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
