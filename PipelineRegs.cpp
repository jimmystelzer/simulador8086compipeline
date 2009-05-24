#include "PipelineRegs.h"

RegistradorPipeline::RegistradorPipeline(){
    reset();
}
std::string RegistradorPipeline::getInst(){
    return this->inst.substr(0,this->inst.length());
}
std::string RegistradorPipeline::getExec(){
    return this->exec.substr(0,this->exec.length());
}
std::string RegistradorPipeline::getMem(){
    return this->mem.substr(0,this->mem.length());
}
std::string RegistradorPipeline::getWB(){
    return this->wb.substr(0,this->wb.length());
}
std::string RegistradorPipeline::getPC(){
    return this->pc.substr(0,this->pc.length());
}
std::string RegistradorPipeline::getRegD(){
    return this->regd.substr(0,this->regd.length());
}
std::string RegistradorPipeline::getW(){
    return this->w.substr(0,this->w.length());
}
std::string RegistradorPipeline::getRegDr(){
    return this->regdr.substr(0,this->regdr.length());
}
std::string RegistradorPipeline::getRegSr(){
    return this->regsr.substr(0,this->regsr.length());
}
std::string RegistradorPipeline::getRegS(){
    return this->regs.substr(0,this->regs.length());
}
std::string RegistradorPipeline::getParam(){
    return this->param.substr(0,this->param.length());
}
std::string RegistradorPipeline::getMod(){
    return this->mod.substr(0,this->mod.length());
}
void RegistradorPipeline::setInst(std::string s){
    this->inst.replace(this->inst.begin(),this->inst.end(),s);
}
void RegistradorPipeline::setExec(std::string s){
    this->exec.replace(this->exec.begin(),this->exec.end(),s);
}
void RegistradorPipeline::setMem(std::string s){
    this->mem.replace(this->mem.begin(),this->mem.end(),s);
}
void RegistradorPipeline::setWB(std::string s){
    this->wb.replace(this->wb.begin(),this->wb.end(),s);
}
void RegistradorPipeline::setPC(std::string s){
    this->pc.replace(this->pc.begin(),this->pc.end(),s);
}
void RegistradorPipeline::setRegS(std::string s){
    this->regs.replace(this->regs.begin(),this->regs.end(),s);
}
void RegistradorPipeline::setRegD(std::string s){
    this->regd.replace(this->regd.begin(),this->regd.end(),s);
}
void RegistradorPipeline::setRegDr(std::string s){
    this->regdr.replace(this->regdr.begin(),this->regdr.end(),s);
}
void RegistradorPipeline::setRegSr(std::string s){
    this->regsr.replace(this->regsr.begin(),this->regsr.end(),s);
}
void RegistradorPipeline::setParam(std::string s){
    this->param.replace(this->param.begin(),this->param.end(),s);
}
void RegistradorPipeline::setW(std::string s){
    this->w.replace(this->w.begin(),this->w.end(),s);
}
void RegistradorPipeline::setMod(std::string s){
    this->mod.replace(this->mod.begin(),this->mod.end(),s);
}
void RegistradorPipeline::reset(){
    this->inst.replace(this->inst.begin(),this->inst.end(),std::string(""));
    this->exec.replace(this->exec.begin(),this->exec.end(),std::string(""));
    this->mem.replace(this->mem.begin(),this->mem.end(),std::string(""));
    this->wb.replace(this->wb .begin(),this->wb.end(),std::string(""));
    this->pc.replace(this->pc.begin(),this->pc.end(),std::string(""));
    this->regs.replace(this->regs.begin(),this->regs.end(),std::string(""));
    this->regd.replace(this->regd.begin(),this->regd.end(),std::string(""));
    this->param.replace(this->param.begin(),this->param.end(),std::string(""));
    this->w.replace(this->w.begin(),this->w.end(),std::string(""));
    this->regdr.replace(this->regdr.begin(),this->regdr.end(),std::string(""));
    this->regsr.replace(this->regsr.begin(),this->regsr.end(),std::string(""));
    this->mod.replace(this->mod.begin(),this->mod.end(),std::string(""));
}
