#include "Mem.h"

Mem::Mem(){
	this->pos = 0;
}

void Mem::setByte(char byte){
	this->mem[this->pos++] = byte;  // define byte e incrementa pos para preencher a memoria inicialmente da possicao zero em diante
}

void Mem::setByte(unsigned short IP, char byte){
	this->mem[IP] = byte;  // define byte na possicao IP
}

char Mem::getByte(unsigned short IP){
	return this->mem[IP];   // pegar byte do endereço IP
}

void Mem::reset(){
    this->pos = 0;  // reseta posicao inicial
    unsigned char *begin = &this->mem[0];
    unsigned char *end = begin + sizeof(this->mem);
    std::fill(begin, end, 0);

    //std::fill(&this->mem, &this->mem+ sizeof(this->mem), 0); // esvazia a memoria
}
