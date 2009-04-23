#include "PipelineRegs.h"

RegistradorPipeline::RegistradorPipeline(){
    reset();
}
std::string RegistradorPipeline::getInst(){
    return this->inst;
}
std::string RegistradorPipeline::getExec(){
    return this->exec;
}
std::string RegistradorPipeline::getMem(){
    return this->mem;
}
std::string RegistradorPipeline::getWB(){
    return this->wb;
}
std::string RegistradorPipeline::getPC(){
    return this->pc;
}
std::string RegistradorPipeline::getRegD(){
    return this->regd;
}
std::string RegistradorPipeline::getRegS(){
    return this->regs;
}
std::string RegistradorPipeline::getParam(){
    return this->param;
}
void RegistradorPipeline::setInst(std::string s){
    this->inst = s;
}
void RegistradorPipeline::setExec(std::string s){
    this->exec = s;
}
void RegistradorPipeline::setMem(std::string s){
    this->mem = s;
}
void RegistradorPipeline::setWB(std::string s){
    this->wb = s;
}
void RegistradorPipeline::setPC(std::string s){
    this->pc = s;
}
void RegistradorPipeline::setRegS(std::string s){
    this->regs = s;
}
void RegistradorPipeline::setRegD(std::string s){
    this->regd = s;
}
void RegistradorPipeline::setParam(std::string s){
    this->param = s;
}
void RegistradorPipeline::reset(){
    this->inst = std::string("");
    this->exec = std::string("");
    this->mem = std::string("");
    this->wb = std::string("");
    this->pc = std::string("");
    this->regs = std::string("");
    this->regd = std::string("");
    this->param = std::string("");
}
