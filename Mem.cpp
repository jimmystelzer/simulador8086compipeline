#include "Mem.h"

Mem::Mem(){
	this->pos = 0;
}

void Mem::setData(char byte){
	this->mem[this->pos++] = byte;
}

void Mem::setData(unsigned short IP, char byte){
	this->mem[IP] = byte;
}

char Mem::getData(unsigned short IP){
	return this->mem[IP];
}
