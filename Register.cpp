#include "Register.h"

Register::Register(){
    this->reg = new std::string(REG16BITS, '0');
}

void Register::setX(std::string data){
    this->reg->replace(0, REG16BITS, data.substr(0,REG16BITS));
}
void Register::setH(std::string data){
    this->reg->replace(0, REG8BITS, data.substr(0,REG8BITS));
}
void Register::setL(std::string data){
    this->reg->replace(REG8BITS, REG8BITS, data.substr(0,REG8BITS));
}
std::string Register::getX(){
    return this->reg->substr(0,REG16BITS);
}
std::string Register::getH(){
    return this->reg->substr(0,REG8BITS);
}
std::string Register::getL(){
    return this->reg->substr(REG8BITS,REG8BITS);
}
void Register::reset(){
    this->reg = new std::string(REG16BITS, '0');
}
