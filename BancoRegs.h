#ifndef BANCO_REGS_H
#define BANCO_REGS_H
#include "Registrador.h"
/**
reg     w=0 w=1
000     al  ax
001     cl  cx
010     dl  dx
011     bl  bx
100     ah  sp
101     ch  bp
110     dh  si
111     bh  di
**/

class BancoReg{
    private:
        // o IP vai ficar fora
        Registrador *AX, *BX, *CX, *DX, *SP, *BP, *SI, *DI, *CS, *DS, *SS, *ES;
        Registrador *rD, *rS;

    public:

        BancoReg();
        std::string getAX();
        std::string getBX();
        std::string getCX();
        std::string getDX();
        std::string getSP();
        std::string getBP();
        std::string getSI();
        std::string getDI();
        std::string getCS();
        std::string getDS();
        std::string getSS();
        std::string getES();

        std::string getRD();
        std::string getRS();
        void setRDcode();
        void setRScode();

};

#endif  //BANCO_REGS_H
