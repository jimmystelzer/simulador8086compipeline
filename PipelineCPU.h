#ifndef PIPELINE_CPU_H
#define PIPELINE_CPU_H
#include <string>

#include "PipelineRegs.h"
#include "RegisterBank.h"
#include "ShiftLeft.h"
#include "Mem.h"
#include "Helpers.h"
#include "Hazards.h"
#include "Forwarding.h"
#include "Control.h"
#include "ALU.h"
#include "Register.h"
#include "Mux.h"

class PipelineCPU{
    private:
        Register *ip, *oip, *ooip, *cs, *ds, *ss, *es;
        RegisterBank *rb;
        Helpers *hp;
        ALU *alu;
        Mem *dataMem, *instMem;
        RegistradorPipeline *ifIdI, *idExI, *exMemI, *memWbI;
        RegistradorPipeline *ifIdO, *idExO, *exMemO, *memWbO;
        std::string *IF, *ID, *EX, *MEM, *WB;
        Control *c;
        //Estágios Pipeline
        void execIF(int s);
        void execID();
        void execEX();
        void execMEM();
        void execWB();
        bool on;
        bool nop;
        /** LOG **/
            std::stringstream tmpAllToStr;
        /** LOG_end **/
    public:
        PipelineCPU();
        //Controles CPU
        void exec();
        void reset();
        std::string getOn();
        //Registradores
        std::string getAX();
        std::string getBX();
        std::string getCX();
        std::string getDX();
        std::string getIP();
        std::string getSP();
        std::string getBP();
        std::string getSI();
        std::string getDI();
        std::string getCS();
        std::string getDS();
        std::string getSS();
        std::string getES();
        //Flags
        std::string getCF();
        std::string getZF();
        std::string getSF();
        std::string getOF();
        std::string getPF();
        std::string getAF();
        std::string getIF();
        std::string getDF();
        //Pipeline
        std::string getPIF();
        std::string getPID();
        std::string getPEX();
        std::string getPMEM();
        std::string getPWB();
        //Memoria
        void setData(std::string s);
        void setCode(std::string s);
        std::string getDataMem();
        std::string getCodeMem();
        std::string readFile(std::string filename);
        //IP
        int PIP();
};


#endif  //PIPELINE_CPU_H
