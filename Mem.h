#ifndef MEMORIA_H
#define MEMORIA_H
#define MEMSIZE64k 0x10000
#include <iostream>
// [00500 - A0000]

class Mem{
    private:
        std::string *mem; //64k
        unsigned short pos;

    public:
        Mem();
        void setByte(unsigned short IP, std::string byte);
        std::string getByte(unsigned short IP);
        std::string getMem();
        void reset();
};

#endif  //MEMORIA_H
