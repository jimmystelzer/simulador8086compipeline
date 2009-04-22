#include "Control.h"

Control::Control(){
    // std::string *rD, *rS, *Mneumonic;
    this->rD = new std::string(3,'0');
    this->rS = new std::string(3,'0');
    this->Mneumonic = new std::string;
    this->hp = new Helpers();
    this->param = new std::string(3,'0');
    this->mod = new std::string(2,'0');
    this->w = new std::string(1,'0');

}
void Control::setOpcode(std::string opcode){
    opcode = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(opcode,16)),2); // hex to bin
    if((opcode.substr(0,8)).compare("01100110")==0){
        //mov reg, label
        //01100110 10111001 00000000 00000000    mov cx, iteracoes
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("movreglabel"));
        this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(13,3));
        this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(10,3));
        this->mod->replace(this->mod->begin(),this->mod->end(),opcode.substr(8,2));
        this->param->replace(this->param->begin(),this->param->end(),(opcode.substr(24,8)).append(opcode.substr(16,8)));
        this->w->replace(this->w->begin(),this->w->end(),std::string("1")); //deveria ser 1?
    }else if((opcode.substr(0,3)).compare("1011")==0){
        //mov reg, immed
        //10110100 00000001 mov ah, 1
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("movregimmed"));
        this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(5,3));
        this->rS->replace(this->rS->begin(),this->rS->end(),std::string(""));
        this->mod->replace(this->mod->begin(),this->mod->end(),std::string(""));
        this->w->replace(this->w->begin(),this->w->end(),opcode.substr(4,1));
        if (this->w->compare("0")){
            this->param->replace(this->param->begin(),this->param->end(),opcode.substr(8,8));
        }else{
            this->param->replace(this->param->begin(),this->param->end(),(opcode.substr(16,8)).append(opcode.substr(8,8)));
        }
    }else if((opcode.substr(0,5)).compare("100010")==0){
        //mov reg, reg
        //10001000 11011000 mov al, bl
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("movregereg"));
        this->mod->replace(this->mod->begin(),this->mod->end(),opcode.substr(8,2));
        if ((opcode.substr(6,1)).compare("0")){
            // from reg
            this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(10,3));
            this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(13,3));
        }else{
            // to reg
            this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(13,3));
            this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(10,3));
        }
        this->w->replace(this->w->begin(),this->w->end(),opcode.substr(7,1));
        if (this->w->compare("0")){
            this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        }else{
            this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        }
    }else if((opcode.substr(0,5)).compare("000000")==0){
        //add reg, reg
        //00000000 11000011 add bl, al
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("addregereg"));
        this->mod->replace(this->mod->begin(),this->mod->end(),opcode.substr(8,2));
        if ((opcode.substr(6,1)).compare("0")){
            // from reg
            this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(10,3));
            this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(13,3));
        }else{
            // to reg
            this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(13,3));
            this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(10,3));
        }
        this->w->replace(this->w->begin(),this->w->end(),opcode.substr(7,1));
        if (this->w->compare("0")){
            this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        }else{
            this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        }
    }else if((opcode.substr(0,7)).compare("11110100")==0){
        //hlt
        //11110100  hlt
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("hlt"));
        this->rD->replace(this->rD->begin(),this->rD->end(),std::string(""));
        this->rS->replace(this->rS->begin(),this->rS->end(),std::string(""));
        this->mod->replace(this->mod->begin(),this->mod->end(),std::string(""));
        this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        this->w->replace(this->w->begin(),this->w->end(),std::string("")); //deveria ser 1?
    }else if((opcode.substr(0,7)).compare("11100000")==0){
        //loopnz
        //11100000 11110110 loopnz retorno
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("loopnz"));

    }else if((opcode.substr(0,7)).compare("01110100")==0){
        //jz label (short)
        //01110100 00001011 jz primeiro
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("jzlabel"));

    }else if((opcode.substr(0,7)).compare("10000000")==0){
        //cmp reg, immed
        //10000000 11111011 00000000    cmp bl, 0
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("cmpregimmed"));

    }else if((opcode.substr(0,7)).compare("11101001")==0){
        //jmp label (complemento de 2)
        //11101001 11101100 11111111 11111111 11111111  jmp retorno
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("jmplabel"));


    }
}
std::string Control::getMneumonic(){
    return *(this->Mneumonic);
}
std::string Control::getRD(){
    return *(this->rD);
}
std::string Control::getRS(){
    return *(this->rS);
}
std::string Control::getParam(){
    return *(this->param);
}
