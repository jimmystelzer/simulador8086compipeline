#include "Adder.h"

Adder::Adder(){
    this->hp = new Helpers();
    this->result = new std::string(2,'0');
    this->param1 = new std::string(2,'0');
    this->param2 = new std::string(2,'0');
}

std::string Adder::doAdd(){
    std::string tmp;
    int a = this->hp->stringToInt(this->hp->baseToInt(std::string("0x").append(this->param1->c_str()),16));
    int b = this->hp->stringToInt(this->hp->baseToInt(std::string("0x").append(this->param2->c_str()),16));
    int r = a +b;
    tmp = this->hp->intToBase(r, 16);
    if(tmp.length() > REG16BITS){
        this->result->replace(0,REG16BITS,tmp.substr(tmp.length() - REG16BITS,REG16BITS));
    }else{
        this->result->replace(REG16BITS - tmp.length(),tmp.length(),tmp.substr(0,tmp.length()));
    }
    return *this->result;
}

std::string Adder::doAdd(std::string param1,std::string param2){
    std::string tmp;
    this->param1 = &param1;
    this->param2 = &param2;
    int a = this->hp->stringToInt(this->hp->baseToInt(std::string("0x").append(this->param1->c_str()),16));
    int b = this->hp->stringToInt(this->hp->baseToInt(std::string("0x").append(this->param2->c_str()),16));
    int r = a +b;
    tmp = this->hp->intToBase(r, 16);
    this->result = new std::string(REG16BITS,'0');
    if(tmp.length() > REG16BITS){
        this->result->replace(0,REG16BITS,tmp.substr(tmp.length() - REG16BITS,REG16BITS));
    }else{
        this->result->replace(REG16BITS - tmp.length(),tmp.length(),tmp.substr(0,tmp.length()));
    }
    return *this->result;
}

void Adder::setParametros(std::string param1, std::string param2){
    this->param1 = &param1;
    this->param2 = &param2;
}
