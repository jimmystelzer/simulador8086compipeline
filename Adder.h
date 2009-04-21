#ifndef ADDER_H
#define ADDER_H
#define REG16BITS 0x4
#include <string>
#include "Helpers.h"

class Adder{
    private:
        std::string *result, *param1, *param2;
        Helpers *hp;
    public:
        Adder();
        std::string doAdd();
        std::string doAdd(std::string param1,std::string param2);
        void setParametros(std::string param1, std::string param2);
};

#endif  //ADDER_H
