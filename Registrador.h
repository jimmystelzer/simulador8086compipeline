#ifndef REGISTRADOR_H
#define REGISTRADOR_H
#define REG16BITS 0x4
#define REG8BITS 0x2
#include <iostream>
#include <cstring>



class Registrador{
    private:
        unsigned char reg[REG16BITS]; //16bit

    public:
        Registrador();
        void setX(unsigned char data[REG16BITS]);
        void setH(unsigned char data[REG8BITS]);
        void setL(unsigned char data[REG8BITS]);
        unsigned char getX();
        unsigned char getH();
        unsigned char getL();
        void reset();
};

#endif  //REGISTRADOR_H
