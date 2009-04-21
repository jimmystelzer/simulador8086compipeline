#include "PipelineRegs.h"

RegistradorPipeline::RegistradorPipeline(){
    this->regP = new std::string(REG80BITS,'0');
    this->hp = new Helpers();
}
std::string RegistradorPipeline::getInst(){
    return this->regP->substr(REG40BITS,REG40BITS);
}
std::string RegistradorPipeline::getExec(){
    std::string tmp = std::string(1,'0');
    tmp.replace(0,1,this->regP->substr(0,REG8BITS)); // tmp recebe flags
    tmp = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(tmp,16)),2); // converte tmp de hexa para um string binario
    return tmp.substr(0,1);
}
std::string RegistradorPipeline::getMem(){
    std::string tmp = std::string(1,'0');
    tmp.replace(0,1,this->regP->substr(0,REG8BITS)); // tmp recebe flags
    tmp = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(tmp,16)),2); // converte tmp de hexa para um string binario
    return tmp.substr(1,1);
}
std::string RegistradorPipeline::getWB(){
    std::string tmp = std::string(1,'0');
    tmp.replace(0,1,this->regP->substr(0,REG8BITS)); // tmp recebe flags
    tmp = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(tmp,16)),2); // converte tmp de hexa para um string binario
    return tmp.substr(2,1);
}
std::string RegistradorPipeline::getPC(){
    return this->regP->substr(REG8BITS,REG32BITS);
}
std::string RegistradorPipeline::getReg(){
    return *(this->regP);
}
void RegistradorPipeline::setInst(std::string s){
    if(s.length()>=REG40BITS){
        this->regP->replace(REG40BITS,REG40BITS,s.substr(0,REG40BITS));
    }else{
        this->regP->replace(REG40BITS,REG40BITS,s);
    }
}
void RegistradorPipeline::setExec(std::string s){
    std::string tmp = std::string(1,'0');
    tmp.replace(0,1,this->regP->substr(0,REG8BITS)); // tmp recebe flags
    tmp = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(tmp,16)),2); // converte tmp de hexa para um string binario
    tmp = tmp.replace(0,1,s.substr(0,1));
    tmp = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(tmp,2)),16); // converte tmp de binario para um string hexa
    this->regP->replace(0,REG8BITS,tmp);
}
void RegistradorPipeline::setMem(std::string s){
    std::string tmp = std::string(1,'0');
    tmp.replace(0,1,this->regP->substr(0,REG8BITS)); // tmp recebe flags
    tmp = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(tmp,16)),2); // converte tmp de hexa para um string binario
    tmp = tmp.replace(1,1,s.substr(0,1));
    tmp = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(tmp,2)),16); // converte tmp de binario para um string hexa
    this->regP->replace(0,REG8BITS,tmp);
}
void RegistradorPipeline::setWB(std::string s){
    std::string tmp = std::string(1,'0');
    tmp.replace(0,1,this->regP->substr(0,REG8BITS)); // tmp recebe flags
    tmp = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(tmp,16)),2); // converte tmp de hexa para um string binario
    tmp = tmp.replace(2,1,s.substr(0,1));
    tmp = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(tmp,2)),16); // converte tmp de binario para um string hexa
    this->regP->replace(0,REG8BITS,tmp);
}
void RegistradorPipeline::setPC(std::string s){
    if(s.length()>=REG32BITS){
        this->regP->replace(REG8BITS,REG32BITS,s.substr(0,REG32BITS));
    }else{
        this->regP->replace(REG8BITS,REG32BITS,s);
    }
}
void RegistradorPipeline::setReg(std::string s){
    if(s.length()>=REG80BITS){
        this->regP->replace(0,REG80BITS,s.substr(0,REG80BITS));
    }else{
        this->regP->replace(0,s.length(),s);
    }
}
void RegistradorPipeline::reset(){
    this->regP = new std::string(REG80BITS,'0');
}
