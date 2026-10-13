#ifndef TRAGAPERRAS_H
#define TRAGAPERRAS_H

#include <string>
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

class Tragaperras{
    private:
        static const int CEREZA = 0, LIMON = 1, UVA = 2, SANDIA = 3, CAMPANA = 4, SIETE = 5;
        const int PUNT_CEREZA = 15, PUNT_LIMON = 25, PUNT_UVA = 50, PUNT_SANDIA = 100, PUNT_CAMPANA = 250, PUNT_SIETE = 1000;
        const int rodillo[6] = {CEREZA, LIMON, UVA, SANDIA, CAMPANA, SIETE};
        int dinero, max;
        int results[100];

        Tragaperras(int dinero, int max = 3){
            this->dinero = dinero;
            this->max = max;
        }

        void roll();
        void roll_animation(int vueltas) const;
        bool win(int& winfigure);
        long long reward(int figure);
        
        int getMax();
        int getDinero();
        int getResults(const int indice);
        int getNumFiguras() const;

        void setDinero(const int money);

        std::string toString(int figure) const;

    public:
        static void jugar(int& balance);

};

#endif
