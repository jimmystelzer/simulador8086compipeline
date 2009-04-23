#include "Mem.h"

Mem::Mem(){
    this->mem = new std::string();
	this->pos = 0;
}

void Mem::setByte(unsigned short IP, std::string byte){
	this->mem->replace(IP,byte.length(),byte);  // define byte na possicao IP
}

std::string Mem::getByte(unsigned short IP){
    if(IP > this->mem->length()){
        return std::string("");
    }
	return this->mem->substr(IP,10);   // pegar byte do endereço IP e os cinco proximos
}

void Mem::reset(){
    this->pos = 0;  // reseta posicao inicial
    this->mem = new std::string();
}
std::string Mem::getMem(){
    return this->mem->substr(0,this->mem->length());
}
