#include "RegisterBank.h"

RegisterBank::RegisterBank(){
    this->reset();
}

std::string RegisterBank::getAX(){
    return this->AX->getX();
}
std::string RegisterBank::getBX(){
    return this->BX->getX();
}
std::string RegisterBank::getCX(){
    return this->CX->getX();
}
std::string RegisterBank::getDX(){
    return this->DX->getX();
}
std::string RegisterBank::getSP(){
    return this->SP->getX();
}
std::string RegisterBank::getBP(){
    return this->BP->getX();
}
std::string RegisterBank::getSI(){
    return this->SI->getX();
}
std::string RegisterBank::getDI(){
    return this->DI->getX();
}

std::string RegisterBank::getRD(std::string c,std::string w){
    return getRS(c,w);
}
std::string RegisterBank::getRS(std::string c,std::string w){
    if(c.compare("000")==0){
        if(w.compare("0")==0){
            return this->AX->getX().substr();
        }else{
            return this->AX->getL().substr();
        }
    }else if(c.compare("001")==0){
        if(w.compare("0")==0){
            return this->CX->getX().substr();
        }else{
            return this->CX->getL().substr();
        }
    }else if(c.compare("010")==0){
        if(w.compare("0")==0){
            return this->DX->getX().substr();
        }else{
            return this->DX->getL().substr();
        }
    }else if(c.compare("011")==0){
        if(w.compare("0")==0){
            return this->BX->getX().substr();
        }else{
            return this->BX->getL().substr();
        }
    }else if(c.compare("100")==0){
        if(w.compare("0")==0){
            return this->AX->getH().substr();
        }else{
            return this->SP->getX().substr();
        }
    }else if(c.compare("101")==0){
        if(w.compare("0")==0){
            return this->CX->getH().substr();
        }else{
            return this->BP->getX().substr();
        }
    }else if(c.compare("110")==0){
        if(w.compare("0")==0){
            return this->DX->getH().substr();
        }else{
            return this->SI->getX().substr();
        }
    }else if(c.compare("111")==0){
        if(w.compare("0")==0){
            return this->BX->getH().substr();
        }else{
            return this->DI->getX().substr();
        }
    }
    return std::string();
}
void RegisterBank::setRD(std::string s,std::string c,std::string w){
    if(c.compare("000")==0){
        if(w.compare("0")==0){
            this->AX->setX(s);
        }else{
            this->AX->setL(s);
        }
    }else if(c.compare("001")==0){
        if(w.compare("0")==0){
            this->CX->setX(s);
        }else{
            this->CX->setL(s);
        }
    }else if(c.compare("010")==0){
        if(w.compare("0")==0){
            this->DX->setX(s);
        }else{
            this->DX->setL(s);
        }
    }else if(c.compare("011")==0){
        if(w.compare("0")==0){
            this->BX->setX(s);
        }else{
            this->BX->setL(s);
        }
    }else if(c.compare("100")==0){
        if(w.compare("0")==0){
            this->AX->setH(s);
        }else{
            this->SP->setX(s);
        }
    }else if(c.compare("101")==0){
        if(w.compare("0")==0){
            this->CX->setH(s);
        }else{
            this->BP->setX(s);
        }
    }else if(c.compare("110")==0){
        if(w.compare("0")==0){
            this->DX->setH(s);
        }else{
            this->SI->setX(s);
        }
    }else if(c.compare("111")==0){
        if(w.compare("0")==0){
            this->BX->setH(s);
        }else{
            this->DI->setX(s);
        }
    }
}
void RegisterBank::setRS(std::string s,std::string c,std::string w){
    this->setRD(s,c,w);
}
void RegisterBank::reset(){
    this->AX = new Register();
    this->BX = new Register();
    this->CX = new Register();
    this->DX = new Register();
    this->SP = new Register();
    this->BP = new Register();
    this->SI = new Register();
    this->DI = new Register();
}
