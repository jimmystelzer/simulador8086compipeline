#include "PipelineCPU.h"

PipelineCPU::PipelineCPU(){
        this->ip = new Register();
        this->oip = new Register();
        this->ooip = new Register();
        this->cs = new Register();
        this->ds = new Register();
        this->ss = new Register();
        this->es = new Register();

        this->rb = new RegisterBank();

        this->hp = new Helpers();

        this->alu = new ALU();

        this->dataMem = new Mem();
        this->instMem = new Mem();

        this->c = new Control();

        this->ifIdI = new RegistradorPipeline();
        this->idExI = new RegistradorPipeline();
        this->exMemI = new RegistradorPipeline();
        this->memWbI = new RegistradorPipeline();

        this->ifIdO = new RegistradorPipeline();
        this->idExO = new RegistradorPipeline();
        this->exMemO = new RegistradorPipeline();
        this->memWbO = new RegistradorPipeline();

        this->IF = new std::string("");
        this->ID = new std::string("");
        this->EX = new std::string("");
        this->MEM = new std::string("");
        this->WB = new std::string("");

        this->on = true;
        this->nop = false;
}

void PipelineCPU::execIF(int s=0){
            /** LOG **/
                this->hp->setLog(std::string("====+====+====+====+== IF ==+====+====+====+===="));
            /** LOG_end **/

    int tmpIP, ntmpIP;
    if(s==0){
        this->ooip->setX(this->oip->getX());
        this->oip->setX(this->ip->getX());
    }
    //le IP
    tmpIP = this->hp->stringToInt(this->hp->baseToInt(this->ip->getX(),16));
            /** LOG **/
                tmpAllToStr.str("");
                tmpAllToStr << tmpIP;
                this->hp->setLog( std::string("tmpIP = ").append(tmpAllToStr.str()) );
            /** LOG_end **/
    //carrega instMem(IP)
    this->IF->replace(this->IF->begin(),this->IF->end(),this->instMem->getByte(tmpIP));

    //calcula novo IP
    ntmpIP = PIP();
            /** LOG **/
                tmpAllToStr.str("");
                tmpAllToStr << ntmpIP;
                this->hp->setLog( std::string("ntmpIP = ").append(tmpAllToStr.str()) );
            /** LOG_end **/
    //descarta bytes relevantes
    this->IF->replace(this->IF->begin(),this->IF->end(),IF->substr(0,ntmpIP));

    this->ifIdI->setInst(IF->substr());


    //incrementa IP
    tmpIP = tmpIP + ntmpIP;
            /** LOG **/
                tmpAllToStr.str("");
                tmpAllToStr << tmpIP;
                this->hp->setLog( std::string("tmpIP + ntmpIP = ").append(tmpAllToStr.str()) );
            /** LOG_end **/
    this->ip->setX(this->hp->leadingZeroHex(this->hp->intToBase(tmpIP,16)));
    this->ifIdI->setPC(this->ip->getX());
}

void PipelineCPU::execID(){
    int tmpIP, ntmpIP;
            /** LOG **/
                this->hp->setLog(std::string("====+====+====+====+== ID ==+====+====+====+===="));
            /** LOG_end **/
    // decodifica
    this->c->setOpcode(this->ifIdO->getInst());
            /** LOG **/
                tmpAllToStr.str("");
                tmpAllToStr << this->ifIdO->getInst();
                this->hp->setLog( std::string("opCode = ").append(tmpAllToStr.str()) );
            /** LOG_end **/
    // mostra Mneumonic
    this->ID->replace(this->ID->begin(),this->ID->end(),this->c->getMneumonic());
            /** LOG **/
                tmpAllToStr.str("");
                tmpAllToStr << this->c->getMneumonic();
                this->hp->setLog( std::string("Internal Mneumonic = ").append(tmpAllToStr.str()) );
            /** LOG_end **/
    if(this->c->getMneumonic().compare("jmplabel")==0){
        tmpIP = this->hp->stringToInt(this->hp->baseToInt(this->oip->getX(),16));
                /** LOG **/
                    tmpAllToStr.str("");
                    tmpAllToStr << tmpIP;
                    this->hp->setLog( std::string("jmp tmpIP = ").append(tmpAllToStr.str()) );
                /** LOG_end **/
        if(this->c->getParam().substr(0,1).compare("1")==0){
            ntmpIP = hp->stringToInt(hp->baseToInt(hp->binNegToPos(this->c->getParam()),2));
            tmpIP = tmpIP - (ntmpIP * 2);
                    /** LOG **/
                        tmpAllToStr.str("");
                        tmpAllToStr << ntmpIP;
                        this->hp->setLog( std::string("jmp ntmpIP = ").append(tmpAllToStr.str()) );
                    /** LOG_end **/
                    /** LOG **/
                        tmpAllToStr.str("");
                        tmpAllToStr << tmpIP;
                        this->hp->setLog( std::string("jmp tmpIP - (ntmpIP * 2) - 4 = ").append(tmpAllToStr.str()) );
                    /** LOG_end **/
        }else{
            ntmpIP = hp->stringToInt(hp->baseToInt(this->c->getParam(),2));
            tmpIP = tmpIP + ntmpIP;
                    /** LOG **/
                        tmpAllToStr.str("");
                        tmpAllToStr << ntmpIP;
                        this->hp->setLog( std::string("jmp ntmpIP = ").append(tmpAllToStr.str()) );
                    /** LOG_end **/
                    /** LOG **/
                        tmpAllToStr.str("");
                        tmpAllToStr << tmpIP;
                        this->hp->setLog( std::string("jmp tmpIP + ntmpIP = ").append(tmpAllToStr.str()) );
                    /** LOG_end **/
        }
        this->ip->setX(this->hp->leadingZeroHex(this->hp->intToBase(tmpIP,16)));
        this->execIF(1);
    }

    //this->idExI->setExec()
    this->idExI->setInst(this->c->getMneumonic());
    this->idExI->setExec(this->c->getEX());
    this->idExI->setMem(this->c->getMEM());
    this->idExI->setMod(this->c->getMod());
    this->idExI->setParam(this->c->getParam());
    //this->idExI->setPC()
    this->idExI->setRegD(this->c->getRD());
    this->idExI->setRegDr(this->rb->getRD(this->c->getRD(),this->c->getW()));
    this->idExI->setRegS(this->c->getRS());
    this->idExI->setRegSr(this->rb->getRS(this->c->getRS(),this->c->getW()));
    this->idExI->setW(this->c->getW());
    this->idExI->setWB(this->c->getWB());

    /** LOG **/
        tmpAllToStr.str("");
        tmpAllToStr << std::endl << "getW = " << c->getW() << std::endl << "getRD= " << c->getRD()<< std::endl << "getRS = " << c->getRS();
        tmpAllToStr << std::endl << "getMneumonic = " << c->getMneumonic() << std::endl << "getParam= " << c->getParam()<< std::endl << "getWB = " << c->getWB();
        tmpAllToStr << std::endl << "getEX = " << c->getEX() << std::endl << "getMem= " << c->getMEM()<< std::endl << "getMod = " << c->getMod();
        this->hp->setLog( std::string("Control: ").append(tmpAllToStr.str()) );
    /** LOG_end **/
    /** LOG **/
        tmpAllToStr.str("");
        tmpAllToStr << std::endl << "getW = " << this->idExI->getW() << std::endl << "getRD= " << this->idExI->getRegD() << std::endl << "getRS = " << this->idExI->getRegS();
        tmpAllToStr << std::endl << "getMneumonic = " << this->idExI->getInst() << std::endl << "getParam= " << this->idExI->getParam() << std::endl << "getWB = " << this->idExI->getWB();
        tmpAllToStr << std::endl << "getEX = " << this->idExI->getExec() << std::endl << "getMem= " << this->idExI->getMem() << std::endl << "getMod = " << this->idExI->getMod();
        tmpAllToStr << std::endl << "regD = " << this->rb->getRD(this->c->getRD(),this->c->getW())<< std::endl << "regS = " << this->rb->getRS(this->c->getRS(),this->c->getW()) ;
        this->hp->setLog( std::string("idExI: ").append(tmpAllToStr.str()) );
    /** LOG_end **/
    this->ifIdO->setExec(this->ifIdI->getExec());
    this->ifIdO->setInst(this->ifIdI->getInst());
    this->ifIdO->setMem(this->ifIdI->getMem());
    this->ifIdO->setMod(this->ifIdI->getMod());
    this->ifIdO->setParam(this->ifIdI->getParam());
    this->ifIdO->setPC(this->ifIdI->getPC());
    this->ifIdO->setRegD(this->ifIdI->getRegD());
    this->ifIdO->setRegDr(this->ifIdI->getRegDr());
    this->ifIdO->setRegS(this->ifIdI->getRegS());
    this->ifIdO->setRegSr(this->ifIdI->getRegSr());
    this->ifIdO->setW(this->ifIdI->getW());
    this->ifIdO->setWB(this->ifIdI->getWB());
}

void PipelineCPU::execEX(){
    /** LOG **/
        this->hp->setLog(std::string("====+====+====+====+== EX ==+====+====+====+===="));
    /** LOG_end **/
    int tmpIP, ntmpIP;
    if((this->idExO->getExec()).compare("0")==0){
        this->EX->replace(this->EX->begin(),this->EX->end(),std::string("~").append(this->idExO->getInst()));
                /** LOG **/
                    this->hp->setLog(std::string("ALU -> ~").append(this->idExO->getInst()));
                /** LOG_end **/
    }else{
        this->EX->replace(this->EX->begin(),this->EX->end(),this->idExO->getInst());
                /** LOG **/
                    tmpAllToStr.str("");
                    tmpAllToStr << "ALU ( " << this->idExO->getInst() << ", " << this->idExO->getRegDr() << ", " << this->idExO->getRegSr() << ", " << this->idExO->getW() << ", " << this->idExO->getParam() << " )";
                    this->hp->setLog(tmpAllToStr.str());
                /** LOG_end **/
        this->idExO->setRegDr(this->alu->exec(this->idExO->getInst(),this->idExO->getRegDr(),this->idExO->getRegSr(),this->idExO->getW(),this->idExO->getParam()));
        tmpIP = this->hp->stringToInt(this->hp->baseToInt(this->ooip->getX(),16));
        if((this->idExO->getInst()).compare("jzlabel")==0){
            if(this->idExO->getRegDr().compare("true")==0){
                if(this->idExO->getParam().substr(0,1).compare("1")==0){
                    ntmpIP = this->hp->stringToInt(this->hp->baseToInt(this->hp->binNegToPos(this->idExO->getParam()),2));
                    tmpIP = tmpIP - (ntmpIP * 2);
                }else{
                    ntmpIP = this->hp->stringToInt(this->hp->baseToInt(this->idExO->getParam(),2));
                    tmpIP = tmpIP + (ntmpIP * 2);
                }
                this->ip->setX(this->hp->leadingZeroHex(this->hp->intToBase(tmpIP,16)));
                this->execIF(1);
                this->ifIdO->setInst("");
                this->execID();
            }
        }else if((this->idExO->getInst()).compare("loopnz")==0){
            if(this->idExO->getRegDr().compare("false")!=0){
                if(this->idExO->getParam().substr(0,1).compare("1")==0){
                    ntmpIP = this->hp->stringToInt(this->hp->baseToInt(this->hp->binNegToPos(this->idExO->getParam()),2));
                    tmpIP = tmpIP - (ntmpIP * 2);
                }else{
                    ntmpIP = this->hp->stringToInt(this->hp->baseToInt(this->idExO->getParam(),2));
                    tmpIP = tmpIP + (ntmpIP * 2);
                }
                this->ip->setX(this->hp->leadingZeroHex(this->hp->intToBase(tmpIP,16)));
                this->execIF(1);
                this->ifIdO->setInst("");
                this->execID();
            }
        }else if((this->idExO->getInst()).compare("hlt")==0){
                this->nop = true;
        }

        if(this->nop == true){
                this->ip->setX(this->hp->leadingZeroHex(this->hp->intToBase(tmpIP,16)));
                this->execIF(1);
                this->ifIdO->setInst("");
                this->execID();
        }
                /** LOG **/
                    tmpAllToStr.str("");
                    tmpAllToStr << this->idExO->getRegDr();
                    this->hp->setLog( std::string("ALU result = ").append(tmpAllToStr.str()));
                /** LOG_end **/
    }
    //this->exMemI->setExec()
    this->exMemI->setInst(this->idExO->getInst());
    this->exMemI->setMem(this->idExO->getMem());
    this->exMemI->setMod(this->idExO->getMod());
    this->exMemI->setParam(this->idExO->getParam());
    //this->exMemI->setPC()
    this->exMemI->setRegD(this->idExO->getRegD());
    this->exMemI->setRegDr(this->idExO->getRegDr());
    this->exMemI->setRegS(this->idExO->getRegS());
    this->exMemI->setRegSr(this->idExO->getRegSr());
    this->exMemI->setW(this->idExO->getW());
    this->exMemI->setWB(this->idExO->getWB());

    this->idExO->setExec(this->idExI->getExec());
    this->idExO->setInst(this->idExI->getInst());
    this->idExO->setMem(this->idExI->getMem());
    this->idExO->setMod(this->idExI->getMod());
    this->idExO->setParam(this->idExI->getParam());
    this->idExO->setPC(this->idExI->getPC());
    this->idExO->setRegD(this->idExI->getRegD());
    this->idExO->setRegDr(this->idExI->getRegDr());
    this->idExO->setRegS(this->idExI->getRegS());
    this->idExO->setRegSr(this->idExI->getRegSr());
    this->idExO->setW(this->idExI->getW());
    this->idExO->setWB(this->idExI->getWB());
}

void PipelineCPU::execMEM(){
    /** LOG **/
        this->hp->setLog(std::string("====+====+====+====+== MEM ==+====+====+====+===="));
    /** LOG_end **/

    if((this->exMemO->getMem()).compare("0")==0){
        this->MEM->replace(this->MEM->begin(),this->MEM->end(),std::string("~").append(this->exMemO->getInst()));
    }else{
        this->MEM->replace(this->MEM->begin(),this->MEM->end(),this->exMemO->getInst());
        if((this->exMemO->getInst()).compare("movregmem")==0){
            this->exMemO->setRegDr(this->dataMem->getByte(this->hp->stringToInt(this->hp->baseToInt(this->exMemO->getParam(),2))));
        }
    }
    //this->memWbI->setExec()
    this->memWbI->setInst(this->exMemO->getInst());
    //this->memWbI->setMem()
    this->memWbI->setMod(this->exMemO->getMod());
    this->memWbI->setParam(this->exMemO->getParam());
    //this->memWbI->setPC()
    this->memWbI->setRegD(this->exMemO->getRegD());
    this->memWbI->setRegDr(this->exMemO->getRegDr());
    this->memWbI->setRegS(this->exMemO->getRegS());
    this->memWbI->setRegSr(this->exMemO->getRegSr());
    this->memWbI->setW(this->exMemO->getW());
    this->memWbI->setWB(this->exMemO->getWB());

    this->exMemO->setExec(this->exMemI->getExec());
    this->exMemO->setInst(this->exMemI->getInst());
    this->exMemO->setMem(this->exMemI->getMem());
    this->exMemO->setMod(this->exMemI->getMod());
    this->exMemO->setParam(this->exMemI->getParam());
    this->exMemO->setPC(this->exMemI->getPC());
    this->exMemO->setRegD(this->exMemI->getRegD());
    this->exMemO->setRegDr(this->exMemI->getRegDr());
    this->exMemO->setRegS(this->exMemI->getRegS());
    this->exMemO->setRegSr(this->exMemI->getRegSr());
    this->exMemO->setW(this->exMemI->getW());
    this->exMemO->setWB(this->exMemI->getWB());
}

void PipelineCPU::execWB(){
    /** LOG **/
        this->hp->setLog(std::string("====+====+====+====+== WB ==+====+====+====+===="));
    /** LOG_end **/

    if((this->memWbO->getWB()).compare("0")==0){
        this->WB->replace(this->WB->begin(),this->WB->end(),std::string("~").append(this->memWbO->getInst()));
    }else{
        this->WB->replace(this->WB->begin(),this->WB->end(),this->memWbO->getInst());
        if((this->memWbO->getInst()).compare("loopnz")==0){
            if(this->memWbO->getRegDr().compare("false")==0){
                this->memWbO->setRegDr(std::string("0000"));
            }
        }
        this->rb->setRD(this->memWbO->getRegDr(),this->memWbO->getRegD(),this->memWbO->getW());
    }
    if(this->memWbO->getInst().compare("hlt")==0){
        this->on = false;
        this->hp->setLog("off");
    }
    this->memWbO->setExec(this->memWbI->getExec());
    this->memWbO->setInst(this->memWbI->getInst());
    this->memWbO->setMem(this->memWbI->getMem());
    this->memWbO->setMod(this->memWbI->getMod());
    this->memWbO->setParam(this->memWbI->getParam());
    this->memWbO->setPC(this->memWbI->getPC());
    this->memWbO->setRegD(this->memWbI->getRegD());
    this->memWbO->setRegDr(this->memWbI->getRegDr());
    this->memWbO->setRegS(this->memWbI->getRegS());
    this->memWbO->setRegSr(this->memWbI->getRegSr());
    this->memWbO->setW(this->memWbI->getW());
    this->memWbO->setWB(this->memWbI->getWB());
}

void PipelineCPU::exec(){
    if(this->on){
        /** ********************************IF******************************** **/
        this->execIF();

        /** ********************************ID******************************** **/
        this->execID();

        /** ********************************EX******************************** **/
        this->execEX();

        /** ********************************MEM******************************* **/
        this->execMEM();

        /** ********************************WB******************************** **/
        this->execWB();

        /** end **/
    }else{
            /** LOG **/
                this->hp->setLog(std::string("====+====+====+====+====+==CPU off==+====+====+====+====\n\n"));
            /** LOG_end **/
    }
            /** LOG **/
                this->hp->setLog(std::string("====+====+====+====+====+====+====+====+====+====\n\n"));
                this->hp->saveLog(std::string("log/pipeline.txt"));
            /** LOG_end **/
}

void PipelineCPU::reset(){
    this->dataMem->reset();
    this->instMem->reset();

    this->ip->reset();
    this->oip->reset();
    this->ooip->reset();
    this->cs->reset();
    this->ds->reset();
    this->ss->reset();
    this->es->reset();
    this->rb->reset();

    this->ifIdO->reset();
    this->idExO->reset();
    this->exMemO->reset();
    this->memWbO->reset();
    this->ifIdI->reset();
    this->idExI->reset();
    this->exMemI->reset();
    this->memWbI->reset();

    this->IF = new std::string();
    this->ID = new std::string();
    this->EX = new std::string();
    this->MEM = new std::string();
    this->WB = new std::string();

    this->alu->reset();

    this->hp->cleanLog();

    this->on = true;
    this->nop = false;
}
/**
 *
 * Registradores
 *
 **/
std::string PipelineCPU::getAX(){
    return this->rb->getAX();
}

std::string PipelineCPU::getBX(){
    return this->rb->getBX();
}

std::string PipelineCPU::getCX(){
    return this->rb->getCX();
}

std::string PipelineCPU::getDX(){
    return this->rb->getDX();
}

std::string PipelineCPU::getIP(){
    return this->ip->getX();
}

std::string PipelineCPU::getSP(){
    return this->rb->getSP();
}

std::string PipelineCPU::getBP(){
    return this->rb->getBP();
}

std::string PipelineCPU::getSI(){
    return this->rb->getSI();
}

std::string PipelineCPU::getDI(){
    return this->rb->getDI();
}

std::string PipelineCPU::getCS(){
    return this->cs->getX();
}

std::string PipelineCPU::getDS(){
    return this->ds->getX();
}

std::string PipelineCPU::getSS(){
    return this->ss->getX();
}

std::string PipelineCPU::getES(){
    return this->es->getX();
}
/**
 *
 * Flags
 *
 **/
std::string PipelineCPU::getCF(){
    return this->alu->getCF();
}

std::string PipelineCPU::getZF(){
    return this->alu->getZF();
}

std::string PipelineCPU::getSF(){
    return this->alu->getSF();
}

std::string PipelineCPU::getOF(){
    return this->alu->getOF();
}

std::string PipelineCPU::getPF(){
    return this->alu->getPF();
}

std::string PipelineCPU::getAF(){
    return this->alu->getAF();
}

std::string PipelineCPU::getIF(){
    return this->alu->getIF();
}

std::string PipelineCPU::getDF(){
    return this->alu->getDF();
}
/**
 *
 * Pipeline
 *
 **/
std::string PipelineCPU::getPIF(){
    return this->IF->substr();
}

std::string PipelineCPU::getPID(){
    return this->ID->substr();
}

std::string PipelineCPU::getPEX(){
    return this->EX->substr();
}

std::string PipelineCPU::getPMEM(){
    return this->MEM->substr();
}

std::string PipelineCPU::getPWB(){
    return this->WB->substr();
}
/**
 *
 * Memoria
 *
 **/
void PipelineCPU::setData(std::string s){
    bool dat;
    std::stringstream ts,tmpStr;
    std::string lineTmpStr;
    ts << s;
    dat = false;
    while (std::getline(ts,lineTmpStr)) {
        if(lineTmpStr.compare(".data")==0){
            dat = true;
        }else if(lineTmpStr.compare(".text")==0){
            dat = false;
        }
        if (dat && lineTmpStr.compare(".data")!=0){
            tmpStr << lineTmpStr.substr(9);
        }
    }
    this->dataMem->setByte(0,tmpStr.str());
}

void PipelineCPU::setCode(std::string s){
    bool tex;
    std::stringstream ts,tmpStr;
    std::string lineTmpStr;
    ts << s;
    tex = false;
    while (std::getline(ts,lineTmpStr)) {
        if(lineTmpStr.compare(".text")==0){
            tex = true;
        }else if(lineTmpStr.compare(".data")==0){
            tex = false;
        }
        if (tex && lineTmpStr.compare(".text")!=0){
            tmpStr << lineTmpStr.substr(9);
        }
    }
    this->instMem->setByte(0,tmpStr.str());
}

std::string PipelineCPU::getDataMem(){
    return this->dataMem->getMem();
}

std::string PipelineCPU::getCodeMem(){
    return this->instMem->getMem();
}

std::string PipelineCPU::readFile(std::string filename){
    std::string tmpStr;
    tmpStr = this->hp->readFile(filename);
    setData(tmpStr);
    setCode(tmpStr);
    return tmpStr;
}
/**
 *
 * IP
 *
 **/
int PipelineCPU::PIP(){
    std::string s = this->IF->substr(0,2);
    if(s.compare("F4")==0){
        return 2;
    }
    if(s.compare("80")==0){
        return 6;
    }
    if(s.compare("66")==0){
        return 8;
    }
    if(s.compare("E9")==0){
        return 10;
    }
    return 4;
}

std::string PipelineCPU::getOn(){
    if(this->on==true){
        return std::string("On");
    }else{
        return std::string("Off");
    }
}
