#include "Helpers.h"


Helpers::Helpers(){
}

std::string Helpers::intToBase(unsigned int num, unsigned int b){
    if (num > 0){
        std::string nbc = std::string("0123456789ABCDEF");
        std::ostringstream tmpstr;
        tmpstr << intToBase(num/b,b) << nbc.at(num % b);
        return tmpstr.str();
    }else{
        return std::string("");
    }
}

std::string Helpers::readFile(std::string filename){
    std::string lineTmpStr;
    std::ostringstream tmpStr;
    std::ifstream inFile;

    inFile.open(filename.c_str());

    if (!inFile) {
        // erro ao abrir
        return std::string();
    }else{
        while (std::getline(inFile,lineTmpStr)) {
            tmpStr << lineTmpStr;
        }
        return tmpStr.str();
    }
}
