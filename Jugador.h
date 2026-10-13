#ifndef JUGADOR_H
#define JUGADOR_H

#include"Mano.h"

class Jugador{
    private:
        Carta ManoJug[5];
        int dinero;
        int usado;
    public:
        void CambiarDin(int cambio);
        Jugador(int Din = 1000);
        void setCarta(Carta car);
        Mano generarmano();
        void Printcartas();
        int Getdin();
        void Resetear();
};

#endif
