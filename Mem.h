#ifndef MEMORIA_H
#define MEMORIA_H

#include <iostream>
using namespace std;

class Mem{
    private:
        unsigned char mem[0x10000]; //64k
        unsigned short pos; // [00500 - A0000]

    public:
        Mem();
        void setData(unsigned short IP, char byte);
        void setData(char byte);
        char getData(unsigned short IP);
};

#endif  //MEMORIA_H