#ifndef SHIFT_LEFT_H
#define SHIFT_LEFT_H
#define REG16BITS 0x4
#include <string>
#include "Helpers.h"

class ShiftLeft{
    private:
        std::string *tmpStr;
        Helpers *hp;
    public:
        ShiftLeft();
        std::string doShiftLeft(std::string data);
};
#endif  //SHIFT_LEFT_H
