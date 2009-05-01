#include "Mux.h"

// Mux 2X1

Mux2::Mux2(){
    this->i0 = new std::string();
    this->i1 = new std::string();
    this->out = new std::string();
    this->sel1 = new std::string();
}
void Mux2::setInput(std::string i0, std::string i1){
    *this->i0 = i0;
    *this->i1 = i1;
}
void Mux2::setSelect(std::string sel1){
    *this->sel1 = sel1;
}
std::string Mux2::getOut(){
    if (this->sel1->compare("0")==0){
        this->out = this->i0;
    }else if (this->sel1->compare("1")==0){
        this->out = this->i1;
    }else{
        *this->out = std::string();
    }
    return *this->out;
}
std::string Mux2::getOut(std::string i0, std::string i1,std::string sel1){
    this->setInput(i0,i1);
    this->setSelect(sel1);
    return this->getOut();
}

// MUX 4x1

Mux4::Mux4(){
    this->i0 = new std::string();
    this->i1 = new std::string();
    this->i2 = new std::string();
    this->i3 = new std::string();

    this->out = new std::string();

    this->sel1 = new std::string();
    this->sel2 = new std::string();
}

void Mux4::setInput(std::string i0, std::string i1, std::string i2, std::string i3){
    *this->i0 = i0;
    *this->i1 = i1;
    *this->i2 = i2;
    *this->i3 = i3;

}

void Mux4::setSelect(std::string sel1, std::string sel2){
    *this->sel1 = sel1;
    *this->sel2 = sel2;
}

std::string Mux4::getOut(){
    if (this->sel1->compare("0")==0){
        if (this->sel2->compare("0")==0){
            this->out = this->i0;
        }else if (this->sel2->compare("1")==0){
            this->out = this->i1;
        }else{
            *this->out = std::string();
        }
    }else if (this->sel1->compare("1")==0){
        if (this->sel2->compare("0")==0){
            this->out = this->i2;
        }else if (this->sel2->compare("1")==0){
            this->out = this->i3;
        }else{
            *this->out = std::string();
        }
    }else{
        *this->out = std::string();
    }
    return *this->out;
}

std::string Mux4::getOut(std::string i0, std::string i1, std::string i2, std::string i3, std::string sel1, std::string sel2){
    this->setInput(i0,i1,i2,i3);
    this->setSelect(sel1,sel2);
    return this->getOut();
}
