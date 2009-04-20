#include "Registrador.h"

Registrador::Registrador(){
    this->reg = new std::string(REG16BITS, '0');
}

void Registrador::setX(std::string data){
//    for(unsigned int i=0;i<REG16BITS;i++){
//        this->reg[i] = data[i];
//    }
    this->reg->replace(0, REG16BITS, data.substr(0,REG16BITS));
}
void Registrador::setH(std::string data){
//    for(unsigned int i=0;i<REG8BITS;i++){
//        this->reg[i] = data[i];
//    }
    this->reg->replace(0, REG8BITS, data.substr(0,REG8BITS));
}
void Registrador::setL(std::string data){
//    for(unsigned int i=REG8BITS;i<REG16BITS;i++){
//        this->reg[i] = data[i];
//    }
    this->reg->replace(REG8BITS, REG8BITS, data.substr(0,REG8BITS));
}
std::string Registrador::getX(){
//    return *(this->reg);
    return this->reg->substr(0,REG16BITS);
}
std::string Registrador::getH(){
//    unsigned char tmpchars[REG8BITS];
//    for(unsigned int i=0;i<REG8BITS;i++){
//        tmpchars[i] = this->reg[i];
//    }
//    return *tmpchars;
    return this->reg->substr(0,REG8BITS);
}
std::string Registrador::getL(){
//    unsigned char tmpchars[REG8BITS];
//    for(unsigned int i=REG8BITS;i<REG16BITS;i++){
//        tmpchars[i] = this->reg[i];
//    }
//    return *tmpchars;
    return this->reg->substr(REG8BITS,REG16BITS);
}
void Registrador::reset(){
    this->reg = new std::string(REG16BITS, '0');
}
