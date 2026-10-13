#ifndef CARTA_H
#define CARTA_H

#include<iostream>
#include<ctime>
#include<cstdlib>

class Carta{
    private:
        int num;
        int palo;
    public:
        Carta();
        int getNum();
        int getPalo();
        void printCarta();
        int getNumBl();
};

#endif
