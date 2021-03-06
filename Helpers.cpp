#include "Helpers.h"


Helpers::Helpers(){
}
std::string Helpers::intToBase(unsigned long long int num, unsigned int b){
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
    std::stringstream tmpstr;
    std::string nbc = std::string("0123456789ABCDEF");
    unsigned long long int fnum = 0;
    unsigned int tmp;
    if (!num.empty()) {
        for (unsigned int i=0;i<num.length();i++){
            tmp = nbc.find((num.substr(i,1)).c_str(), 0);
            fnum = (unsigned long long int)(fnum + (tmp)*pow(b,(num.length()-i-1)));
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
            lineTmpStr = cleanFile(lineTmpStr);
            if(lineTmpStr.compare("")!=0){
                tmpStr << lineTmpStr << std::endl;
            }
        }
        return tmpStr.str();
    }
}

unsigned long long int Helpers::stringToInt(const std::string& s){
    std::istringstream i(s);
    unsigned long long int x;
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

std::string Helpers::cleanFile(std::string s){
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
std::string Helpers::binNegToPos(std::string s){
    //inverte
    for(unsigned int it = 0; it < s.length() ; it++){
        if((s.substr(it,1)).compare("1")==0){
            s.replace(it,1,std::string("0"));
        }else{
            s.replace(it,1,std::string("1"));
        }
    }
    //soma 1
    for(int it = s.length()-1; it > 0 ; it--){
        if((s.substr(it,1)).compare("1")==0){
            s.replace(it,1,std::string("0"));
        }else{
            s.replace(it,1,std::string("1"));
            it=0;
        }
    }
    return s;
}
std::string Helpers::binPosToNeg(std::string s){
    //subritair
    for(int it = s.length()-1; it > 0 ; it--){
        if((s.substr(it,1)).compare("0")==0){
            s.replace(it,1,std::string("1"));
        }else{
            s.replace(it,1,std::string("0"));
            it=0;
        }
    }
    //inverte
    for(unsigned int it = 0; it < s.length() ; it++){
        if((s.substr(it,1)).compare("1")==0){
            s.replace(it,1,std::string("0"));
        }else{
            s.replace(it,1,std::string("1"));
        }
    }
    return s;
}


void Helpers::cleanLog(){
    this->logString.str("");
}

std::string Helpers::leadingZeroBin(std::string s){
    if(s.length()<16){
        s.insert(0,std::string(16 - s.length(),'0'));
    }
    return s;
}
std::string Helpers::leadingZero(std::string s, int b){
    s.insert(0,std::string(b - s.length(),'0'));
    return s;
}
std::string Helpers::leadingZeroHex(std::string s){
    if(s.length()<4){
        s.insert(0,std::string(4 - s.length(),'0'));
    }
    return s;
}
