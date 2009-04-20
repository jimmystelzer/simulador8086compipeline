#ifndef REGISTRADOR_H
#define REGISTRADOR_H
#define REG16BITS 0x4
#define REG8BITS 0x2
#include <string>



class Registrador{
    private:
        std::string *reg;

    public:
        Registrador();
        void setX(std::string data);
        void setH(std::string data);
        void setL(std::string data);
        std::string getX();
        std::string getH();
        std::string getL();
        void reset();
};

#endif  //REGISTRADOR_H
