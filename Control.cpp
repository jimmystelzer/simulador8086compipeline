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
    
    }else if((opcode.substr(0,3)).compare("1011")==0){
        //mov reg, immed
    }else if((opcode.substr(0,7)).compare("10001000")==0){
	//mov reg, reg
    }else if((opcode.substr(0,7)).compare("00000000")==0){
	//add reg, reg
    }else if((opcode.substr(0,7)).compare("11110100")==0){
	//hlt
    }else if((opcode.substr(0,7)).compare("11100000")==0){
	//loopnz
    }else if((opcode.substr(0,7)).compare("01110100")==0){
	//jz label (short)
    }else if((opcode.substr(0,7)).compare("10000000")==0){
	//cmp reg, immed
    }else if((opcode.substr(0,7)).compare("11101001")==0){
	//jmp label (complemento de 2)
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
