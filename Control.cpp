#include "Control.h"

Control::Control(){
    // std::string *rD, *rS, *Meneumonic;
    this->rD = new std::string(3,'0');
    this->rS = new std::string(3,'0');
    this->Meneumonic = new std::string;
    this->hp = new Helpers();
}
void Control::setOpcode(std::string opcode){
    opcode = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(opcode,16)),2); // hex to bin
    if((opcode.substr(0,8)).compare("1100110")==0){
        //mov reg, label
    }else if((opcode.substr(0,4)).compare("1011")==0){
        //mov reg, imed
    }
}
std::string Control::getMeneumonic(){
    return *(this->Meneumonic);
}
std::string Control::getRD(){
    return *(this->rD);
}
std::string Control::getRS(){
    return *(this->rS);
}
