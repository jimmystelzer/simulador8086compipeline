#include "Control.h"

Control::Control() {
    this->rD = new std::string();
    this->rS = new std::string();
    this->Mneumonic = new std::string();
    this->hp = new Helpers();
    this->param = new std::string();
    this->mod = new std::string();
    this->w = new std::string();
    this->ex = new std::string();
    this->mem = new std::string();
    this->wb = new std::string();
}
void Control::setOpcode(std::string opcode) {
    int ol= opcode.length();

    if(ol>=10){
        opcode = opcode.substr(0,4);
        ol = opcode.length();
    }

    opcode = this->hp->intToBase(this->hp->stringToInt(this->hp->baseToInt(opcode,16)),2); // hex to bin
    hp->setLog(opcode);
    ol = ol * 4;
    opcode = this->hp->leadingZero(opcode,ol);
    hp->setLog(opcode);
    hp->saveLog("log.txt");
    if ((opcode.substr(0,8)).compare("01100110")==0) {
        //mov reg, label
        //01100110 10111001 00000000 00000000    mov cx, iteracoes
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("movregrm"));
        this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(13,3));
        this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(10,3));
        this->mod->replace(this->mod->begin(),this->mod->end(),opcode.substr(8,2));
        this->param->replace(this->param->begin(),this->param->end(),(opcode.substr(24,8)).append(opcode.substr(16,8)));
        this->w->replace(this->w->begin(),this->w->end(),std::string("1")); //deveria ser 1?

        this->mem->replace(this->mem->begin(),this->mem->end(),std::string("1"));
        this->ex->replace(this->ex->begin(),this->ex->end(),std::string("0"));
        this->wb->replace(this->wb->begin(),this->wb->end(),std::string("1"));
    } else if ((opcode.substr(0,4)).compare("1011")==0) {
        //mov reg, immed
        //10110100 00000001 mov ah, 1
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("movregimmed"));
        this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(5,3));
        this->rS->replace(this->rS->begin(),this->rS->end(),std::string(""));
        this->mod->replace(this->mod->begin(),this->mod->end(),std::string(""));
        this->w->replace(this->w->begin(),this->w->end(),opcode.substr(4,1));
        if (this->w->compare("0")) {
            this->param->replace(this->param->begin(),this->param->end(),opcode.substr(8,8));
        } else {
            this->param->replace(this->param->begin(),this->param->end(),(opcode.substr(16,8)).append(opcode.substr(8,8)));
        }
        this->mem->replace(this->mem->begin(),this->mem->end(),std::string("0"));
        this->ex->replace(this->ex->begin(),this->ex->end(),std::string("1"));
        this->wb->replace(this->wb->begin(),this->wb->end(),std::string("1"));
    } else if ((opcode.substr(0,6)).compare("100010")==0) {
        //mov reg, reg
        //10001000 11011000 mov al, bl
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("movregereg"));
        this->mod->replace(this->mod->begin(),this->mod->end(),opcode.substr(8,2));
        if ((opcode.substr(6,1)).compare("0")) {
            // from reg
            this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(10,3));
            this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(13,3));
        } else {
            // to reg
            this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(13,3));
            this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(10,3));
        }
        this->w->replace(this->w->begin(),this->w->end(),opcode.substr(7,1));
        if (this->w->compare("0")) {
            this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        } else {
            this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        }
        this->mem->replace(this->mem->begin(),this->mem->end(),std::string("0"));
        this->ex->replace(this->ex->begin(),this->ex->end(),std::string("1"));
        this->wb->replace(this->wb->begin(),this->wb->end(),std::string("1"));
    } else if ((opcode.substr(0,6)).compare("000000")==0) {
        //add reg, reg
        //00000000 11000011 add bl, al
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("addregereg"));
        this->mod->replace(this->mod->begin(),this->mod->end(),opcode.substr(8,2));
        if ((opcode.substr(6,1)).compare("0")) {
            // from reg
            this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(10,3));
            this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(13,3));
        } else {
            // to reg
            this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(13,3));
            this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(10,3));
        }
        this->w->replace(this->w->begin(),this->w->end(),opcode.substr(7,1));
        if (this->w->compare("0")) {
            this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        } else {
            this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        }
        this->mem->replace(this->mem->begin(),this->mem->end(),std::string("0"));
        this->ex->replace(this->ex->begin(),this->ex->end(),std::string("1"));
        this->wb->replace(this->wb->begin(),this->wb->end(),std::string("1"));
    } else if ((opcode.substr(0,8)).compare("11110100")==0) {
        //hlt
        //11110100  hlt
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("hlt"));
        this->rD->replace(this->rD->begin(),this->rD->end(),std::string(""));
        this->rS->replace(this->rS->begin(),this->rS->end(),std::string(""));
        this->mod->replace(this->mod->begin(),this->mod->end(),std::string(""));
        this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        this->w->replace(this->w->begin(),this->w->end(),std::string(""));
        this->mem->replace(this->mem->begin(),this->mem->end(),std::string("0"));
        this->ex->replace(this->ex->begin(),this->ex->end(),std::string("1"));
        this->wb->replace(this->wb->begin(),this->wb->end(),std::string("0"));
    } else if ((opcode.substr(0,8)).compare("11100000")==0) {
        //loopnz
        //11100000 11110110 loopnz retorno
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("loopnz"));
        this->rD->replace(this->rD->begin(),this->rD->end(),std::string("001"));
        this->rS->replace(this->rS->begin(),this->rS->end(),std::string(""));
        this->mod->replace(this->mod->begin(),this->mod->end(),std::string(""));
        this->param->replace(this->param->begin(),this->param->end(),opcode.substr(8,8));
        this->w->replace(this->w->begin(),this->w->end(),std::string("1")); //deveria ser 1?
        this->mem->replace(this->mem->begin(),this->mem->end(),std::string("0"));
        this->ex->replace(this->ex->begin(),this->ex->end(),std::string("1"));
        this->wb->replace(this->wb->begin(),this->wb->end(),std::string("0"));
    } else if ((opcode.substr(0,8)).compare("01110100")==0) {
        //jz label (short)
        //01110100 00001011 jz primeiro
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("jzlabel"));
        this->rD->replace(this->rD->begin(),this->rD->end(),std::string("001"));
        this->rS->replace(this->rS->begin(),this->rS->end(),std::string(""));
        this->mod->replace(this->mod->begin(),this->mod->end(),std::string(""));
        this->param->replace(this->param->begin(),this->param->end(),opcode.substr(8,8)); // IP + param
        this->w->replace(this->w->begin(),this->w->end(),std::string("0"));
        this->mem->replace(this->mem->begin(),this->mem->end(),std::string("0"));
        this->ex->replace(this->ex->begin(),this->ex->end(),std::string("1"));
        this->wb->replace(this->wb->begin(),this->wb->end(),std::string("1"));
    } else if ((opcode.substr(0,6)).compare("100000")==0) {
        //cmp reg, immed
        //10000000 11111011 00000000    cmp bl, 0
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("cmpregimmed"));
        this->mod->replace(this->mod->begin(),this->mod->end(),opcode.substr(8,2));
        if ((opcode.substr(6,1)).compare("0")) {
            // from reg
            this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(10,3));
            this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(13,3));
        } else {
            // to reg
            this->rD->replace(this->rD->begin(),this->rD->end(),opcode.substr(13,3));
            this->rS->replace(this->rS->begin(),this->rS->end(),opcode.substr(10,3));
        }
        this->w->replace(this->w->begin(),this->w->end(),opcode.substr(7,1));
        this->param->replace(this->param->begin(),this->param->end(),opcode.substr(16,8));
        this->mem->replace(this->mem->begin(),this->mem->end(),std::string("0"));
        this->ex->replace(this->ex->begin(),this->ex->end(),std::string("1"));
        this->wb->replace(this->wb->begin(),this->wb->end(),std::string("0"));
    } else if ((opcode.substr(0,8)).compare("11101001")==0) {
        //jmp label (complemento de 2)
        //11101001 11101100  jmp retorno
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),std::string("jmplabel"));
        this->rD->replace(this->rD->begin(),this->rD->end(),std::string(""));
        this->rS->replace(this->rS->begin(),this->rS->end(),std::string(""));
        this->mod->replace(this->mod->begin(),this->mod->end(),std::string(""));
        this->param->replace(this->param->begin(),this->param->end(),opcode.substr(16,8).append(opcode.substr(8,8)));
        this->w->replace(this->w->begin(),this->w->end(),std::string(""));
        this->mem->replace(this->mem->begin(),this->mem->end(),std::string("0"));
        this->ex->replace(this->ex->begin(),this->ex->end(),std::string("0"));
        this->wb->replace(this->wb->begin(),this->wb->end(),std::string("0"));
    } else {
        this->Mneumonic->replace(this->Mneumonic->begin(),this->Mneumonic->end(),opcode.substr(0,opcode.length()));//std::string("nop")
        this->rD->replace(this->rD->begin(),this->rD->end(),std::string(""));
        this->rS->replace(this->rS->begin(),this->rS->end(),std::string(""));
        this->mod->replace(this->mod->begin(),this->mod->end(),std::string(""));
        this->param->replace(this->param->begin(),this->param->end(),std::string(""));
        this->w->replace(this->w->begin(),this->w->end(),std::string(""));
        this->mem->replace(this->mem->begin(),this->mem->end(),std::string("0"));
        this->ex->replace(this->ex->begin(),this->ex->end(),std::string("0"));
        this->wb->replace(this->wb->begin(),this->wb->end(),std::string("0"));
    }
}
std::string Control::getMneumonic() {
    return this->Mneumonic->substr(0,this->Mneumonic->length());
}
std::string Control::getRD() {
    return this->rD->substr(0,this->rD->length());
}
std::string Control::getRS() {
    return this->rS->substr(0,this->rS->length());
}
std::string Control::getParam() {
    return this->param->substr(0,this->param->length());
}
std::string Control::getMod() {
    return this->mod->substr(0,this->mod->length());
}
std::string Control::getW() {
    return this->w->substr(0,this->w->length());
}
std::string Control::getEX() {
    return this->ex->substr(0,this->w->length());
}
std::string Control::getMEM() {
    return this->mem->substr(0,this->w->length());
}
std::string Control::getWB() {
    return this->wb->substr(0,this->w->length());
}
