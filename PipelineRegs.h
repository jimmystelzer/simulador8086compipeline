#ifndef PIPELINE_REGS_H
#define PIPELINE_REGS_H
#define REG32BITS 0x8
#include <string>

class RegistradorPipeline{
    private:
        std::string *regP;

    public:
        RegistradorPipeline();
        void reset();
};
#endif  //PIPELINE_REGS_H
