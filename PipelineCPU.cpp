#include "PipelineCPU.h"

PipelineCPU::PipelineCPU(){
        this->ip = new Register();
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
        this->oifId = new RegistradorPipeline();
        this->oidEx = new RegistradorPipeline();
        this->oexMem = new RegistradorPipeline();
        this->omemWb = new RegistradorPipeline();
        this->nifId = new RegistradorPipeline();
        this->nidEx = new RegistradorPipeline();
        this->nexMem = new RegistradorPipeline();
        this->nmemWb = new RegistradorPipeline();

        this->IF = new std::string("");
        this->ID = new std::string("");
        this->EX = new std::string("");
        this->MEM = new std::string("");
        this->WB = new std::string("");
}
void PipelineCPU::exec(){
    /** LOG **/
        std::stringstream tmpAllToStr;
    /** LOG_end **/

    /** ********************************IF******************************** **/
            /** LOG **/
                this->hp->setLog(std::string("====+====+====+====+== IF ==+====+====+====+===="));
            /** LOG_end **/
    int tmpIP, ntmpIP;
    //le IP
    tmpIP = this->hp->stringToInt(this->hp->baseToInt(this->ip->getX(),16));
            /** LOG_end **/
                tmpAllToStr.str("");
                tmpAllToStr << tmpIP;
                this->hp->setLog( std::string("tmpIP = ").append(tmpAllToStr.str()) );
            /** LOG_end **/
    //carrega instMem(IP)
    this->IF->replace(this->IF->begin(),this->IF->end(),this->instMem->getByte(tmpIP));

    //calcula novo IP
    ntmpIP = PIP();
            /** LOG_end **/
                tmpAllToStr.str("");
                tmpAllToStr << ntmpIP;
                this->hp->setLog( std::string("ntmpIP = ").append(tmpAllToStr.str()) );
            /** LOG_end **/
    //descarta bytes relevantes
    this->IF->replace(this->IF->begin(),this->IF->end(),IF->substr(0,ntmpIP));

    this->nifId->setInst(IF->substr());


    //incrementa IP
    tmpIP = tmpIP + ntmpIP;
            /** LOG_end **/
                tmpAllToStr.str("");
                tmpAllToStr << tmpIP;
                this->hp->setLog( std::string("tmpIP + ntmpIP = ").append(tmpAllToStr.str()) );
            /** LOG_end **/
    this->ip->setX(this->hp->leadingZeroHex(this->hp->intToBase(tmpIP,16)));
    this->nifId->setPC(this->ip->getX());

    /** ********************************ID******************************** **/
            /** LOG **/
                this->hp->setLog(std::string("====+====+====+====+== ID ==+====+====+====+===="));
            /** LOG_end **/
    // decodifica
    this->c->setOpcode(this->oifId->getInst());
            /** LOG **/
                tmpAllToStr.str("");
                tmpAllToStr << this->oifId->getInst();
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
        tmpIP = this->hp->stringToInt(this->hp->baseToInt(this->ip->getX(),16));
                /** LOG **/
                    tmpAllToStr.str("");
                    tmpAllToStr << tmpIP;
                    this->hp->setLog( std::string("jmp tmpIP = ").append(tmpAllToStr.str()) );
                /** LOG_end **/
        if(this->c->getParam().substr(0,1).compare("1")==0){
            ntmpIP = hp->stringToInt(hp->baseToInt(hp->binNegToPos(this->c->getParam()),2));
            tmpIP = tmpIP - (ntmpIP * 2) -4;
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

        /**
         *
         * JMP Forwarding
         *
         **/
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

            this->nifId->setInst(IF->substr());


            //incrementa IP
            tmpIP = tmpIP + ntmpIP;
                    /** LOG **/
                        tmpAllToStr.str("");
                        tmpAllToStr << tmpIP;
                        this->hp->setLog( std::string("tmpIP + ntmpIP = ").append(tmpAllToStr.str()) );
                    /** LOG_end **/
            this->ip->setX(this->hp->leadingZeroHex(this->hp->intToBase(tmpIP,16)));
            this->nifId->setPC(this->ip->getX());
    }
    // registers do regbank
    this->nidEx->setRegDr(this->rb->getRD(this->c->getRD(),this->c->getW()));
    this->nidEx->setRegSr(this->rb->getRS(this->c->getRS(),this->c->getW()));
    this->nidEx->setInst(this->c->getMneumonic());
    this->nidEx->setRegS(this->c->getRS());
    this->nidEx->setRegD(this->c->getRD());
    this->nidEx->setParam(this->c->getParam());
    this->nidEx->setWB(this->c->getWB());
    this->nidEx->setExec(this->c->getEX());
    this->nidEx->setMem(this->c->getMEM());
    this->nidEx->setW(this->c->getW());

    /** LOG **/
        tmpAllToStr.str("");
        tmpAllToStr << std::endl << "getW = " << c->getW() << std::endl << "getRD= " << c->getRD()<< std::endl << "getRS = " << c->getRS();
        tmpAllToStr << std::endl << "getMneumonic = " << c->getMneumonic() << std::endl << "getParam= " << c->getParam()<< std::endl << "getWB = " << c->getWB();
        tmpAllToStr << std::endl << "getEX = " << c->getEX() << std::endl << "getMem= " << c->getMEM()<< std::endl << "getMod = " << c->getMod();
        this->hp->setLog( std::string("Control: ").append(tmpAllToStr.str()) );
    /** LOG_end **/

    //*this->oifId = *this->nifId;
    this->oifId->setExec(this->nifId->getExec());
    this->oifId->setInst(this->nifId->getInst());
    this->oifId->setMem(this->nifId->getMem());
    this->oifId->setMod(this->nifId->getMod());
    this->oifId->setParam(this->nifId->getParam());
    this->oifId->setPC(this->nifId->getPC());
    this->oifId->setRegD(this->nifId->getRegD());
    this->oifId->setRegDr(this->nifId->getRegDr());
    this->oifId->setRegS(this->nifId->getRegS());
    this->oifId->setRegSr(this->nifId->getRegSr());
    this->oifId->setW(this->nifId->getW());
    this->oifId->setWB(this->nifId->getWB());

    /** ********************************EX******************************** **/
    /** LOG **/
        this->hp->setLog(std::string("====+====+====+====+== EX ==+====+====+====+===="));
    /** LOG_end **/

    if((this->oidEx->getExec()).compare("0")==0){
        this->EX->replace(this->EX->begin(),this->EX->end(),std::string("~").append(this->oidEx->getInst()));
                /** LOG **/
                    this->hp->setLog(std::string("ALU -> ~").append(this->oidEx->getInst()));
                /** LOG_end **/
    }else{
        this->EX->replace(this->EX->begin(),this->EX->end(),this->oidEx->getInst());
                /** LOG **/
                    tmpAllToStr.str("");
                    tmpAllToStr << "ALU ( " << this->oidEx->getInst() << ", " << this->oidEx->getRegDr() << ", " << this->oidEx->getRegSr() << ", " << this->oidEx->getW() << ", " << this->oidEx->getParam() << " )";
                    this->hp->setLog(tmpAllToStr.str());
                /** LOG_end **/
        this->oidEx->setRegDr(this->alu->exec(this->oidEx->getInst(),this->oidEx->getRegDr(),this->oidEx->getRegSr(),this->oidEx->getW(),this->oidEx->getParam()));
                /** LOG **/
                    tmpAllToStr.str("");
                    tmpAllToStr << this->oidEx->getRegDr();
                    this->hp->setLog( std::string("ALU result = ").append(tmpAllToStr.str()) );
                /** LOG_end **/
    }
    this->nexMem->setRegSr(this->oidEx->getRegSr());
    this->nexMem->setRegDr(this->oidEx->getRegDr());
    this->nexMem->setInst(this->oidEx->getInst());
    this->nexMem->setRegS(this->oidEx->getRegS());
    this->nexMem->setRegD(this->oidEx->getRegD());
    this->nexMem->setParam(this->oidEx->getParam());
    this->nexMem->setWB(this->oidEx->getWB());
    this->nexMem->setMem(this->oidEx->getMem());
    this->nexMem->setW(this->oidEx->getW());

    //*this->oidEx = *this->nidEx;
    this->oidEx->setExec(this->nidEx->getExec());
    this->oidEx->setInst(this->nidEx->getInst());
    this->oidEx->setMem(this->nidEx->getMem());
    this->oidEx->setMod(this->nidEx->getMod());
    this->oidEx->setParam(this->nidEx->getParam());
    this->oidEx->setPC(this->nidEx->getPC());
    this->oidEx->setRegD(this->nidEx->getRegD());
    this->oidEx->setRegDr(this->nidEx->getRegDr());
    this->oidEx->setRegS(this->nidEx->getRegS());
    this->oidEx->setRegSr(this->nidEx->getRegSr());
    this->oidEx->setW(this->nidEx->getW());
    this->oidEx->setWB(this->nidEx->getWB());
    /** ********************************MEM******************************** **/
            /** LOG **/
                this->hp->setLog(std::string("====+====+====+====+== MEM ==+====+====+====+===="));
            /** LOG_end **/

    if((this->oexMem->getMem()).compare("0")==0){
        this->MEM->replace(this->MEM->begin(),this->MEM->end(),std::string("~").append(this->oexMem->getInst()));
    }else{
        this->MEM->replace(this->MEM->begin(),this->MEM->end(),this->oexMem->getInst());
    }
    this->nmemWb->setRegSr(this->oexMem->getRegSr());
    this->nmemWb->setRegDr(this->oexMem->getRegDr());
    this->nmemWb->setInst(this->oexMem->getInst());
    this->nmemWb->setRegS(this->oexMem->getRegS());
    this->nmemWb->setRegD(this->oexMem->getRegD());
    this->nmemWb->setParam(this->oexMem->getParam());
    this->nmemWb->setWB(this->oexMem->getWB());
    this->nmemWb->setW(this->oexMem->getW());
    //*this->oexMem = *this->nexMem;
    this->oexMem->setExec(this->nexMem->getExec());
    this->oexMem->setInst(this->nexMem->getInst());
    this->oexMem->setMem(this->nexMem->getMem());
    this->oexMem->setMod(this->nexMem->getMod());
    this->oexMem->setParam(this->nexMem->getParam());
    this->oexMem->setPC(this->nexMem->getPC());
    this->oexMem->setRegD(this->nexMem->getRegD());
    this->oexMem->setRegDr(this->nexMem->getRegDr());
    this->oexMem->setRegS(this->nexMem->getRegS());
    this->oexMem->setRegSr(this->nexMem->getRegSr());
    this->oexMem->setW(this->nexMem->getW());
    this->oexMem->setWB(this->nexMem->getWB());

    /** ********************************WB******************************** **/
            /** LOG **/
                this->hp->setLog(std::string("====+====+====+====+== WB ==+====+====+====+===="));
            /** LOG_end **/

    if((this->omemWb->getWB()).compare("0")==0){
        this->WB->replace(this->WB->begin(),this->WB->end(),std::string("~").append(this->omemWb->getInst()));
    }else{
        this->WB->replace(this->WB->begin(),this->WB->end(),this->omemWb->getInst());
    }
    //*this->omemWb = *this->nmemWb;
    this->omemWb->setExec(this->nmemWb->getExec());
    this->omemWb->setInst(this->nmemWb->getInst());
    this->omemWb->setMem(this->nmemWb->getMem());
    this->omemWb->setMod(this->nmemWb->getMod());
    this->omemWb->setParam(this->nmemWb->getParam());
    this->omemWb->setPC(this->nmemWb->getPC());
    this->omemWb->setRegD(this->nmemWb->getRegD());
    this->omemWb->setRegDr(this->nmemWb->getRegDr());
    this->omemWb->setRegS(this->nmemWb->getRegS());
    this->omemWb->setRegSr(this->nmemWb->getRegSr());
    this->omemWb->setW(this->nmemWb->getW());
    this->omemWb->setWB(this->nmemWb->getWB());
    /** end **/
            /** LOG **/
                this->hp->setLog(std::string("====+====+====+====+====+====+====+====+====+====\n\n"));
                this->hp->saveLog(std::string("log/pipeline.txt"));
            /** LOG_end **/
}

void PipelineCPU::reset(){
    this->dataMem->reset();
    this->instMem->reset();

    this->ip->reset();
    this->cs->reset();
    this->ds->reset();
    this->ss->reset();
    this->es->reset();
    this->rb->reset();

    this->oifId->reset();
    this->oidEx->reset();
    this->oexMem->reset();
    this->omemWb->reset();
    this->nifId->reset();
    this->nidEx->reset();
    this->nexMem->reset();
    this->nmemWb->reset();

    this->IF = new std::string();
    this->ID = new std::string();
    this->EX = new std::string();
    this->MEM = new std::string();
    this->WB = new std::string();
    this->hp->cleanLog();
}

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

std::string PipelineCPU::readFile(std::string filename){
    std::string tmpStr;
    tmpStr = this->hp->readFile(filename);
    setData(tmpStr);
    setCode(tmpStr);
    return tmpStr;
}

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

std::string PipelineCPU::getDataMem(){
    return this->dataMem->getMem();
}
std::string PipelineCPU::getCodeMem(){
    return this->instMem->getMem();
}
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
