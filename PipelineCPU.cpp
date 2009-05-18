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

        this->IF = new std::string();
        this->ID = new std::string();
        this->EX = new std::string();
        this->MEM = new std::string();
        this->WB = new std::string();
}
void PipelineCPU::exec(){

    /** **IF** **/
    int tmpIP, ntmpIP;
    //le IP
    tmpIP = this->hp->stringToInt(this->hp->baseToInt(this->ip->getX(),16));

    //carrega instMem(IP)
    this->IF->replace(this->IF->begin(),this->IF->end(),this->instMem->getByte(tmpIP));

    //calcula novo IP
    ntmpIP = PIP();

    //descarta bytes relevantes
    this->IF->replace(this->IF->begin(),this->IF->end(),IF->substr(0,ntmpIP));

    this->nifId->setInst(IF->substr());


    //incrementa IP
    tmpIP = tmpIP + ntmpIP;
    this->ip->setX(this->hp->leadingZeroHex(this->hp->intToBase(tmpIP,16)));
    this->nifId->setPC(this->ip->getX());

    /** **ID** **/
    // decodifica
    this->c->setOpcode(this->oifId->getInst());

    // mostra Mneumonic
    this->ID->replace(this->ID->begin(),this->ID->end(),this->c->getMneumonic());

    if(this->c->getMneumonic().compare("jmplabel")==0){
        tmpIP = this->hp->stringToInt(this->hp->baseToInt(this->ip->getX(),16));
        if(this->c->getParam().substr(0,1).compare("1")==0){
            ntmpIP = hp->stringToInt(hp->baseToInt(hp->binNegToPos(this->c->getParam()),2));
            tmpIP = tmpIP - ntmpIP;
        }else{
            ntmpIP = hp->stringToInt(hp->baseToInt(this->c->getParam(),2));
            tmpIP = tmpIP + ntmpIP;
        }
        this->ip->setX(this->hp->leadingZeroHex(this->hp->intToBase(tmpIP,16)));
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

    *this->oifId = *this->nifId;

    /** **EX** **/

    if((this->oidEx->getExec()).compare("0")==0){
        this->EX->replace(this->EX->begin(),this->EX->end(),std::string("~").append(this->oidEx->getInst()));

    }else{
        this->EX->replace(this->EX->begin(),this->EX->end(),this->oidEx->getInst());
//        this->oidEx->setRegDr(this->alu->exec(this->oidEx->getInst(),this->oidEx->getRegDr(),this->oidEx->getRegSr(),this->oidEx->getW(),this->oidEx->getParam()));
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

    *this->oidEx = *this->nidEx;
    /** **MEM** **/

    if((this->oexMem->getMem()).compare("0")==0){
        this->MEM->replace(this->MEM->begin(),this->MEM->end(),std::string("~").append(this->oexMem->getInst()));
    }else{
        this->MEM->replace(this->MEM->begin(),this->MEM->end(),this->oexMem->getInst());
//        if(this->oexMem->getInst().compare("movregrm")){
//            this->oexMem->setRegDr(this->dataMem->getByte(this->hp->stringToInt( this->hp->baseToInt(this->oexMem->getParam(),2))).substr(0,4));
//        }
    }
    this->nmemWb->setRegSr(this->oexMem->getRegSr());
    this->nmemWb->setRegDr(this->oexMem->getRegDr());
    this->nmemWb->setInst(this->oexMem->getInst());
    this->nmemWb->setRegS(this->oexMem->getRegS());
    this->nmemWb->setRegD(this->oexMem->getRegD());
    this->nmemWb->setParam(this->oexMem->getParam());
    this->nmemWb->setWB(this->oexMem->getWB());
    this->nmemWb->setW(this->oexMem->getW());
    *this->oexMem = *this->nexMem;

    /** **WB** **/

    if((this->omemWb->getWB()).compare("0")==0){
        this->WB->replace(this->WB->begin(),this->WB->end(),std::string("~").append(this->omemWb->getInst()));
    }else{
        this->WB->replace(this->WB->begin(),this->WB->end(),this->omemWb->getInst());
//        /**  <-<---->->   **/
//        this->rb->setRD(this->omemWb->getRegDr(),this->omemWb->getRegD(),this->omemWb->getW());
//        /**  <-<---->->   **/
    }
    hp->setLog("--");
    hp->saveLog("log.txt");
    *this->omemWb = *this->nmemWb;
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
    this->hp->cleanLog();
    this->hp->setLog(tmpStr.str());
    this->hp->saveLog(std::string("DataMem.txt"));

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
    this->hp->cleanLog();
    this->hp->setLog(tmpStr.str());
    this->hp->saveLog(std::string("CodeMem.txt"));

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
