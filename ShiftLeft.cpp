#include "ShiftLeft.h"

namespace Pipeline{
}

ShiftLeft::ShiftLeft(){
    this->tmpStr = new std::string(REG16BITS,'0');
    this->hp = new Helpers();
}

std::string ShiftLeft::doShiftLeft(std::string data){
    int i=0;
    std::string tmp;
    tmp = this->hp->baseToInt(std::string("0x").append(data),16); //converto pra decimal
    i = this->hp->stringToInt(tmp); //obtenho o valo decimal
    i = i*4; //efetuo o shift
    tmp = this->hp->intToBase(i,16); //converto pra hexadecimal

    if(tmp.length() > REG16BITS){
        this->tmpStr->replace(0,REG16BITS,tmp.substr(tmp.length() - REG16BITS,REG16BITS)); //pegar os ultimos 16 bits
    }else{
        this->tmpStr->replace(REG16BITS - tmp.length(),tmp.length(),tmp.substr(0,tmp.length())); //pegar os ultimos 16 bits
    }
    return *(this->tmpStr); //retorna
}
