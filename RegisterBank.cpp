#include "RegisterBank.h"

RegisterBank::RegisterBank(){
    this->AX = new Register();
    this->BX = new Register();
    this->CX = new Register();
    this->DX = new Register();
    this->SP = new Register();
    this->BP = new Register();
    this->SI = new Register();
    this->DI = new Register();

    this->rD = new Register();
    this->rS = new Register();
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

Register RegisterBank::getRD(std::string c,std::string w){
    if(c.compare("000")==0){
        this->rD = this->AX;
    }else if(c.compare("001")==0){
        this->rD = this->CX;
    }else if(c.compare("010")==0){
        this->rD = this->DX;
    }else if(c.compare("011")==0){
        this->rD = this->BX;
    }else if(c.compare("100")==0){
        if(w.compare("0")==0){
            this->rD = this->AX;
        }else{
            this->rD = this->SP;
        }
    }else if(c.compare("101")==0){
        if(w.compare("0")==0){
            this->rD = this->CX;
        }else{
            this->rD = this->BP;
        }
    }else if(c.compare("110")==0){
        if(w.compare("0")==0){
            this->rD = this->DX;
        }else{
            this->rD = this->SI;
        }
    }else if(c.compare("111")==0){
        if(w.compare("0")==0){
            this->rD = this->BX;
        }else{
            this->rD = this->DI;
        }
    }

    return *(this->rD);
}
Register RegisterBank::getRS(std::string c,std::string w){
    if(c.compare("000")==0){
        this->rS = this->AX;
    }else if(c.compare("001")==0){
        this->rS = this->CX;
    }else if(c.compare("010")==0){
        this->rS = this->DX;
    }else if(c.compare("011")==0){
        this->rS = this->BX;
    }else if(c.compare("100")==0){
        if(w.compare("0")==0){
            this->rS = this->AX;
        }else{
            this->rS = this->SP;
        }
    }else if(c.compare("101")==0){
        if(w.compare("0")==0){
            this->rS = this->CX;
        }else{
            this->rS = this->BP;
        }
    }else if(c.compare("110")==0){
        if(w.compare("0")==0){
            this->rS = this->DX;
        }else{
            this->rS = this->SI;
        }
    }else if(c.compare("111")==0){
        if(w.compare("0")==0){
            this->rS = this->BX;
        }else{
            this->rS = this->DI;
        }
    }

    return *(this->rS);
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
