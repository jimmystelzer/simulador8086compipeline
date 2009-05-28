#include "ALU.h"

ALU::ALU(){
    this->hp = new Helpers();
    reset();
}
std::string ALU::exec(std::string mnem, std::string dest, std::string src, std::string w, std::string param){

    if(mnem.compare("addregreg")==0){
        int tmpi = hp->stringToInt(hp->baseToInt(dest,16)) + hp->stringToInt(hp->baseToInt(src,16));

        dest = hp->leadingZeroHex(hp->intToBase(tmpi, 16));

        if(w.compare("0")==0){
            dest = dest.substr(dest.size()-2);
        }else{
            dest = dest.substr(dest.size()-4);
        }

        //.OF, .SF, .ZF, .AF, .PF, .CF
            if (tmpi < 0){
                this->SF = true;
            }else{
                this->SF = false;
            }
            if (tmpi == 0){
                this->ZF = true;
            }else{
                this->ZF = false;
            }
            if (tmpi > 255 && w.compare("0")==0){
                this->CF = true;
            }else{
                this->CF = false;
            }
            if ((tmpi < -128 || tmpi > 127) && w.compare("0")==0){
                this->OF = true;
            }else{
                this->OF = false;
            }

            if (tmpi > 65535 && w.compare("1")==0){
                this->AF = true;
            }else{
                this->AF = false;
            }
            if (w.compare("0")==0){
                if(tmpi%2 == 0){
                    this->PF = true; //par
                }else{
                    this->PF = false; //nãp par -> impar
                }
            }else{
                this->PF = false; //não par -> não avaliado
            }


    }else if(mnem.compare("cmpregimmed")==0){
        if(hp->stringToInt(hp->baseToInt(src,16)) == hp->stringToInt(hp->baseToInt(param,16))){
            this->ZF = true;
        }else{
            this->ZF = false;
        }
    }else if(mnem.compare("jzlabel")==0){
        if(this->ZF == true){
            dest = std::string("true");
        }else{
            dest = std::string("false");
        }
    }else if(mnem.compare("loopnz")==0){
        unsigned int tmpi = hp->stringToInt(hp->baseToInt(dest,16));
        if(tmpi>0){
            tmpi--;
            dest = hp->leadingZeroHex(hp->intToBase(tmpi, 16));
            if(w.compare("0")==0){
                dest = dest.substr(dest.size()-2);
            }else{
                dest = dest.substr(dest.size()-4);
            }
        }else{
            dest = std::string("false");
        }
    }else if(mnem.compare("hlt")==0){
        dest = std::string("off");

    }else if(mnem.compare("movregreg")==0){
        if(w.compare("0")==0){
            dest = src.substr(src.size()-2);
        }else{
            dest = src.substr(src.size()-4);
        }
    }else if(mnem.compare("movregimmed")==0){
        param = hp->leadingZeroHex(hp->intToBase(hp->stringToInt(hp->baseToInt(param,2)),16));
        if(w.compare("0")==0){
            dest = param.substr(param.size()-2);
        }else{
            dest = param.substr(param.size()-4);
        }
    }

    return dest;
}

std::string ALU::getCF(){
    if (this->CF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getPF(){
    if (this->PF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getAF(){
    if (this->AF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getZF(){
    if (this->ZF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getSF(){
    if (this->SF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getTF(){
    if (this->TF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getIF(){
    if (this->IF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getDF(){
    if (this->DF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
std::string ALU::getOF(){
    if (this->OF){
        return std::string("1");
    }else{
        return std::string("0");
    }
}
void ALU::reset(){
    CF = false;
    PF = false;
    AF = false;
    ZF = false;
    SF = false;
    TF = false;
    IF = false;
    DF = false;
    OF = false;
}
