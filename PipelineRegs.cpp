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
std::string RegistradorPipeline::getW(){
    return this->w;
}
std::string RegistradorPipeline::getRegDr(){
    return this->regdr;
}
std::string RegistradorPipeline::getRegSr(){
    return this->regsr;
}
std::string RegistradorPipeline::getRegS(){
    return this->regs;
}
std::string RegistradorPipeline::getParam(){
    return this->param;
}
std::string RegistradorPipeline::getMod(){
    return this->mod;
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
void RegistradorPipeline::setRegDr(std::string s){
    this->regdr = s;
}
void RegistradorPipeline::setRegSr(std::string s){
    this->regsr = s;
}
void RegistradorPipeline::setParam(std::string s){
    this->param = s;
}
void RegistradorPipeline::setW(std::string s){
    this->w = s;
}
void RegistradorPipeline::setMod(std::string s){
    this->mod = s;
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
    this->w = std::string("");
    this->regdr = std::string("");
    this->regsr = std::string("");
    this->mod = std::string("");
}
