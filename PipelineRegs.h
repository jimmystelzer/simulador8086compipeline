#ifndef PIPELINE_REGS_H
#define PIPELINE_REGS_H
#define REG80BITS 0x10
#define REG40BITS 0x5
#define REG32BITS 0x4
#define REG8BITS 0x1

#include <string>
#include "Helpers.h"
class RegistradorPipeline{
    private:
        std::string *regP;
        Helpers *hp;
    public:
        RegistradorPipeline();
        std::string getInst();
        std::string getExec();
        std::string getMem();
        std::string getWB();
        std::string getPC();
        std::string getReg();
        void setInst(std::string s);
        void setExec(std::string s);
        void setMem(std::string s);
        void setWB(std::string s);
        void setPC(std::string s);
        void setReg(std::string s);
        void reset();
        /**
        0x0000000000
        0x[0][0000][00000]
        [00000000]b     0x[0000]        0x[00000]
        [[Exec][Mem][WB]00000]b 0x[[PC]] 0x[[opcode][parametros]]

        **/
};
#endif  //PIPELINE_REGS_H
