#include "Registrador.h"

Registrador::Registrador(){
}

void Registrador::setX(unsigned char data[REG16BITS]){
    for(unsigned int i=0;i<REG16BITS;i++){
        this->reg[i] = data[i];
    }
}
void Registrador::setH(unsigned char data[REG8BITS]){
    for(unsigned int i=0;i<REG8BITS;i++){
        this->reg[i] = data[i];
    }
}
void Registrador::setL(unsigned char data[REG8BITS]){
    for(unsigned int i=REG8BITS;i<REG16BITS;i++){
        this->reg[i] = data[i];
    }
}
unsigned char Registrador::getX(){
    return *(this->reg);
}
unsigned char Registrador::getH(){
    unsigned char tmpchars[REG8BITS];
    for(unsigned int i=0;i<REG8BITS;i++){
        tmpchars[i] = this->reg[i];
    }
    return *tmpchars;
}
unsigned char Registrador::getL(){
    unsigned char tmpchars[REG8BITS];
    for(unsigned int i=REG8BITS;i<REG16BITS;i++){
        tmpchars[i] = this->reg[i];
    }
    return *tmpchars;
}
void Registrador::reset(){
    unsigned char *begin = &this->reg[0];
    unsigned char *end = begin + sizeof(this->reg);
    std::fill(begin, end, 0);
}
