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

class PipelineCPU{
    private:
        Register *ip, *cs, *ds, *ss, *es, *rd, *rs;
        RegisterBank *rb;
        Helpers *hp;
        ALU *alu;
        Mem *dataMem, *instMem;
        RegistradorPipeline *oifId, *oidEx, *oexMem, *omemWb;
        RegistradorPipeline *nifId, *nidEx, *nexMem, *nmemWb;
        std::string *IF, *ID, *EX, *MEM, *WB;
        Control *c;
    public:
        PipelineCPU();
        void exec();
        void reset();
        void setData(std::string s);
        void setCode(std::string s);

        std::string getDataMem();
        std::string getCodeMem();

        std::string readFile(std::string filename);

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

        std::string getCF();
        std::string getZF();
        std::string getSF();
        std::string getOF();

        std::string getPF();
        std::string getAF();
        std::string getIF();
        std::string getDF();

        std::string getPIF();
        std::string getPID();
        std::string getPEX();
        std::string getPMEM();
        std::string getPWB();

        int PIP();
};


#endif  //PIPELINE_CPU_H
