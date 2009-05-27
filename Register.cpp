#include "Register.h"

Register::Register(){
    this->reset();
}

void Register::setX(std::string data){
    this->reg->replace(this->reg->begin(),this->reg->end(),data.substr(0,data.size()));
}
void Register::setH(std::string data){
    this->reg->replace(this->reg->begin(),this->reg->end()-2,data.substr(0,data.size()));
}
void Register::setL(std::string data){
    this->reg->replace(this->reg->begin()+2,this->reg->end(),data.substr(0,data.size()));
}
std::string Register::getX(){
    return this->reg->substr(0,this->reg->size());
}
std::string Register::getH(){
    return this->reg->substr(0,this->reg->size()-2);
}
std::string Register::getL(){
    return this->reg->substr(2,this->reg->size());
}
void Register::reset(){
    this->reg = new std::string(REG16BITS, '0');
}
