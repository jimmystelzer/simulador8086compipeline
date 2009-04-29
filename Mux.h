#ifndef MUX_H
#define MUX_H
#include <string>

class Mux2{
    private:
        std::string *i0, *i1;
        std::string *out;
        std::string *sel1;
    public:
        Mux2();
        void setInput(std::string i0, std::string i1);
        void setSelect(std::string sel1);
        std::string getOut();
        std::string getOut(std::string i0, std::string i1,std::string sel1);

};

class Mux4{
    private:
        std::string *i0, *i1, *i2, *i3;
        std::string *out;
        std::string *sel1, *sel2;
    public:
        Mux4();
        void setInput(std::string i0, std::string i1, std::string i2, std::string i3);
        void setSelect(std::string sel1, std::string sel2);
        std::string getOut();
        std::string getOut(std::string i0, std::string i1, std::string i2, std::string i3, std::string sel1, std::string sel2);

};
#endif  //MUX_H
