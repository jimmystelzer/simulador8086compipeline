#ifndef PIPELINE_REGS_H
#define PIPELINE_REGS_H
#define REG80BITS 0x10
#define REG40BITS 0x5
#define REG32BITS 0x4
#define REG4BITS 0x1

#include <string>
#include "Helpers.h"
class RegistradorPipeline{
    private:
        std::string inst, exec, mem, wb, pc, regs, regd, param;
    public:
        RegistradorPipeline();
        std::string getInst();
        std::string getExec();
        std::string getMem();
        std::string getWB();
        std::string getPC();
        std::string getRegS();
        std::string getRegD();
        std::string getParam();
        void setInst(std::string s);
        void setExec(std::string s);
        void setMem(std::string s);
        void setWB(std::string s);
        void setPC(std::string s);
        void setRegS(std::string s);
        void setRegD(std::string s);
        void setParam(std::string s);
        void reset();
};
#endif  //PIPELINE_REGS_H
