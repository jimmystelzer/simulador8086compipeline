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
std::string Helpers::baseToInt(unsigned int num, unsigned int b){
    std::ostringstream tmpstr;
    tmpstr << num;
    return baseToInt(tmpstr.str(),b);
}
std::string Helpers::baseToInt(std::string num, unsigned int b){
    std::ostringstream tmpstr;
    int fnum = 0;
    if (!num.empty()) {
        for (unsigned int i=0;i<num.length();i++){
            fnum =  fnum + ((stringToInt((num.substr(i,1)).c_str()))*pow(b,(num.length()-i-1)));
        }
        tmpstr << fnum;
        return tmpstr.str();
    }else{
        return std::string("0");
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

int Helpers::stringToInt(const std::string& s){
    std::istringstream i(s);
    int x;
    i >> x;
    return x;
}

void Helpers::setLog(std::string s){
    this->logString << s << std::endl;
}
std::string Helpers::getLog(){
    return this->logString.str();
}

void Helpers::saveLog(std::string fileName){
    std::ofstream saveFile(fileName.c_str(), std::ios::out);
    if (saveFile.is_open()){
        saveFile << this->logString.str();
        saveFile.close();
    }
}
