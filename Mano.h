#ifndef MANO_H
#define MANO_H

#include"Carta.h"

class Mano{
    private:
        Carta cartas[5];
    public:
        Mano(Carta car1, Carta car2, Carta car3, Carta car4, Carta car5);
        int Car1();
        int Car2();
        int Car3();
        int Car4();
        int Car5();
        void printMano();
        bool Color();
        bool Escalera();
        bool Full();
        bool DoblePar();
        int Iguales();
        bool ManoAlta(Mano mano2);
        int Puntos();
        int CartaIgual();
};


#endif
