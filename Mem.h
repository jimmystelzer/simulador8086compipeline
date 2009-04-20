#ifndef MEMORIA_H
#define MEMORIA_H
#define MEMSIZE64k 0x10000
#include <iostream>
// [00500 - A0000]

class Mem{
    private:
        unsigned char mem[MEMSIZE64k]; //64k
        unsigned short pos;

    public:
        Mem();
        void setByte(unsigned short IP, char byte);
        void setByte(char byte);
        char getByte(unsigned short IP);
        void reset();
};

#endif  //MEMORIA_H
