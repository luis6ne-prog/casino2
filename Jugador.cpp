#include"Jugador.h"

Jugador::Jugador(int Din){
    dinero = Din;
    Carta carta1;
    Carta carta2;
    ManoJug[0] = carta1;
    ManoJug[1] = carta2;
    usado = 2;
}

void Jugador::CambiarDin(int cambio){
    dinero += cambio;
}

void Jugador::setCarta(Carta car){
    if(usado<5){
        ManoJug[usado] = car;
    }
    usado++;
}

Mano Jugador::generarmano(){
    Mano mano(ManoJug[0], ManoJug[1], ManoJug[2], ManoJug[3], ManoJug[4]);

    return mano;
}

void Jugador::Printcartas(){
    for(int i=0; i<usado; i++){
        ManoJug[i].printCarta();
    }

    std::cout << "Pulsa Enter para esconder";
    std::cin.ignore();
    std::cin.get();

  
    int lineas = usado * 10 + usado;
    
    // Borrar desde "Pulsa Enter..." hacia arriba
    for (int i = 0; i < lineas; i++) {
        std::cout << "\033[2K";
        if (i < lineas - 1)
            std::cout << "\033[1A";
    }

    std::cout << "\033[2K";
}

int Jugador::Getdin(){
    return dinero;
}

void Jugador::Resetear(){
    Carta carta1;
    Carta carta2;
    ManoJug[0] = carta1;
    ManoJug[1] = carta2;
    usado = 2;

    return;
}