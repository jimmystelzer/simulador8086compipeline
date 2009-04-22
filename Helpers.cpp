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
            lineTmpStr = removeComments(lineTmpStr);
            if(lineTmpStr.compare("")!=0){
                tmpStr << lineTmpStr << std::endl;
            }
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

std::string Helpers::removeComments(std::string s){
    std::ostringstream tmpStr;

    //remove os numeros
    s = s.substr(7);

    //preserva os tipo de SECTION
    std::string::size_type loc = s.find("SECTION",0);
    if(loc != std::string::npos){
        s = s.substr(loc);
        loc = s.find(".",0);
        if(loc != std::string::npos){
            s = s.substr(loc);
        }
    }

    // tira os comentarios do arquivo
    loc = s.find(";",0);
    if(loc != std::string::npos){
        s = s.substr(0,loc);
    }
    //remove [ e ]
    loc = s.find("[",0);
    if(loc != std::string::npos){
        s = s.erase(loc,1);
    }
    loc = s.find("]",0);
    if(loc != std::string::npos){
        s = s.erase(loc,1);
    }
    //ignora linha iniciadas por espaço
    if((std::string(" ")).compare(s.substr(0,1))!=0){
        // remove multiplos espaços e texto desnecessario
        loc = s.find("  ",0);
        if(loc != std::string::npos){
            s = s.substr(0,loc);
        }


        tmpStr << s;
    }

    return tmpStr.str();
}
