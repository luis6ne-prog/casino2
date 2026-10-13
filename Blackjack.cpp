#include "Blackjack.h"

void jugarBlackjack(int& balance){
    srand(time(NULL));
            int numJug = 0;
            int jug_prin = 1;
            while (numJug < 1 || numJug > 4) {
                std::cout << "Introduce numero jugadores(max 4): ";
                std::cin >> numJug;
            }
            
            if (numJug > 1){
                do {
                    std::cout << "Quién es el jugador principal y usará el balance principal?";
                    std::cin >> jug_prin;
                } while (jug_prin < 1 || jug_prin > numJug);
            }

            bool uno = true;
            int suma1 = 0;
            int apuesta1;

            bool dos = false;
            int suma2 = 0;
            int apuesta2;

            int dinero1 = 1000;
            int dinero2 = 1000;
            bool tres = false;
            bool cuatro = false;

            int dinero3 = 1000;
            int suma3 = 0;
            int apuesta3;

            int dinero4 = 1000;
            int suma4 = 0;
            int apuesta4;

            switch (jug_prin) {
            case 1: balance -= dinero1; break;
            case 2: balance -= dinero2; break;
            case 3: balance -= dinero3; break;
            case 4: balance -= dinero4; break;
            }

            int sumaMesa = 0;
            if (numJug >= 2) {
                dos = true;
            }
            if (numJug >= 3) {
                tres = true;
            }
            if (numJug == 4) {
                cuatro = true;
            }

            bool terminado = false;
            while (!terminado) {
                Carta *Mesa = new Carta[21];
                if (uno && dinero1 > 0) {
                    suma1 = 0;
                    Carta *jug1 = new Carta[21];
                    int cartas = 2;
                    int decision = 0;
                    std::cout << "Turno jugador 1." << std::endl;
                    std::cout << "Dinero jugador 1: " << dinero1 << std::endl;
                    std::cout << "Carta en la mesa: " << std::endl;
                    Mesa[0].printCarta();
                    std::cout << "Cartas jugador 1: " << std::endl;
                    jug1[0].printCarta();
                    jug1[1].printCarta();
                    suma1 += jug1[0].getNumBl() + jug1[1].getNumBl();
                    std::cout << "Apuesta: ";
                    std::cin >> apuesta1;
                    dinero1 += -1 * apuesta1;
                    while (suma1 < 21 && decision != 2) {
                        std::cout << "¿Quiere una carta? 1 para pedir carta, 2 para plantarse";
                        std::cin >> decision;
                        if (decision == 1) {
                            jug1[cartas].printCarta();
                            suma1 += jug1[cartas].getNumBl();
                            cartas++;
                        }
                    }
                    delete[] jug1;
                }
                if (dos && dinero2 > 0) {
                    suma2 = 0;
                    Carta *jug2 = new Carta[21];
                    int cartas = 2;
                    int decision = 0;
                    std::cout << "Turno jugador 2." << std::endl;
                    std::cout << "Dinero jugador 2: " << dinero2 << std::endl;
                    std::cout << "Carta en la mesa: " << std::endl;
                    Mesa[0].printCarta();
                    std::cout << "Cartas jugador 2: " << std::endl;
                    jug2[0].printCarta();
                    jug2[1].printCarta();
                    suma2 += jug2[0].getNumBl() + jug2[1].getNumBl();
                    std::cout << "Apuesta: ";
                    std::cin >> apuesta2;
                    dinero2 += -1 * apuesta2;
                    while (suma2 < 21 && decision != 2) {
                        std::cout << "¿Quiere una carta? 1 para pedir carta, 2 para plantarse";
                        std::cin >> decision;
                        if (decision == 1) {
                            jug2[cartas].printCarta();
                            suma2 += jug2[cartas].getNumBl();
                            cartas++;
                        }
                    }
                    delete[] jug2;
                }
                if (tres && dinero3 > 0) {
                    suma3 = 0;
                    Carta *jug3 = new Carta[21];
                    int cartas = 2;
                    int decision = 0;
                    std::cout << "Turno jugador 3." << std::endl;
                    std::cout << "Dinero jugador 3: " << dinero3 << std::endl;
                    std::cout << "Carta en la mesa: " << std::endl;
                    Mesa[0].printCarta();
                    std::cout << "Cartas jugador 3: " << std::endl;
                    jug3[0].printCarta();
                    jug3[1].printCarta();
                    suma3 += jug3[0].getNumBl() + jug3[1].getNumBl();
                    std::cout << "Apuesta: ";
                    std::cin >> apuesta3;
                    dinero3 += -1 * apuesta3;
                    while (suma3 < 21 && decision != 2) {
                        std::cout << "¿Quiere una carta? 1 para pedir carta, 2 para plantarse";
                        std::cin >> decision;
                        if (decision == 1) {
                            jug3[cartas].printCarta();
                            suma3 += jug3[cartas].getNumBl();
                            cartas++;
                        }
                    }
                    delete[] jug3;
                }
                if (cuatro && dinero4 > 0) {
                    suma4 = 0;
                    Carta *jug4 = new Carta[21];
                    int cartas = 2;
                    int decision = 0;
                    std::cout << "Turno jugador 4." << std::endl;
                    std::cout << "Dinero jugador 4: " << dinero4 << std::endl;
                    std::cout << "Carta en la mesa: " << std::endl;
                    Mesa[0].printCarta();
                    std::cout << "Cartas jugador 4: " << std::endl;
                    jug4[0].printCarta();
                    jug4[1].printCarta();
                    suma4 += jug4[0].getNumBl() + jug4[1].getNumBl();
                    std::cout << "Apuesta: ";
                    std::cin >> apuesta4;
                    dinero4 += -1 * apuesta4;
                    while (suma4 < 21 && decision != 2) {
                        std::cout << "¿Quiere una carta? 1 para pedir carta, 2 para plantarse";
                        std::cin >> decision;
                        if (decision == 1) {
                            jug4[cartas].printCarta();
                            suma4 += jug4[cartas].getNumBl();
                            cartas++;
                        }
                    }
                    delete[] jug4;
                }

                std::cout << "Cartas Mesa: " << std::endl;

                int i = 0;
                sumaMesa = 0;
                while (sumaMesa < 17) {
                    sumaMesa += Mesa[i].getNumBl();
                    Mesa[i].printCarta();
                    i++;
                }

                if ((suma1 <= 21 && sumaMesa > 21) || (suma1 <= 21 && sumaMesa <= 21 && suma1 > sumaMesa)) {
                    std::cout << "Jugador 1 gana." << std::endl;
                    dinero1 += apuesta1 * 2;
                }
                else if (suma1 <= 21 && sumaMesa <= 21 && suma1 == sumaMesa) {
                    std::cout << "Jugador 1 empata." << std::endl;
                    dinero1 += apuesta1;
                }
                else {
                    std::cout << "Jugador 1 pierde." << std::endl;
                }
                if (dos) {
                    if ((suma2 <= 21 && sumaMesa > 21) || (suma2 <= 21 && sumaMesa <= 21 && suma2 > sumaMesa)) {
                        std::cout << "Jugador 2 gana." << std::endl;
                        dinero2 += apuesta2 * 2;
                    }
                    else if (suma2 <= 21 && sumaMesa <= 21 && suma2 == sumaMesa) {
                        std::cout << "Jugador 2 empata." << std::endl;
                        dinero2 += apuesta2;
                    }
                    else {
                        std::cout << "Jugador 2 pierde." << std::endl;
                    }
                }
                if (tres) {
                    if ((suma3 <= 21 && sumaMesa > 21) || (suma3 <= 21 && sumaMesa <= 21 && suma3 > sumaMesa)) {
                        std::cout << "Jugador 3 gana." << std::endl;
                        dinero3 += apuesta3 * 2;
                    }
                    else if (suma3 <= 21 && sumaMesa <= 21 && suma3 == sumaMesa) {
                        std::cout << "Jugador 3 empata." << std::endl;
                        dinero3 += apuesta3;
                    }
                    else {
                        std::cout << "Jugador 3 pierde." << std::endl;
                    }
                }

                if (cuatro) {
                    if ((suma4 <= 21 && sumaMesa > 21) || (suma4 <= 21 && sumaMesa <= 21 && suma4 > sumaMesa)) {
                        std::cout << "Jugador 4 gana." << std::endl;
                        dinero4 += apuesta4 * 2;
                    }
                    else if (suma4 <= 21 && sumaMesa <= 21 && suma4 == sumaMesa) {
                        std::cout << "Jugador 4 empata." << std::endl;
                        dinero4 += apuesta4;
                    }
                    else {
                        std::cout << "Jugador 4 pierde." << std::endl;
                    }
                }
                int resultado = 0;
                while (resultado != 1 && resultado != 2) {
                    std::cout << "1 para acabar, 2 para seguir" << std::endl;
                    std::cin >> resultado;
                }

                if (resultado == 1) {
                    terminado = true;
                    delete[] Mesa;
                }
                
            }

            // El jugador principal devuelve su dinero al balance compartido
            switch (jug_prin) {
                case 1: balance += dinero1; break;
                case 2: balance += dinero2; break;
                case 3: balance += dinero3; break;
                case 4: balance += dinero4; break;
            }
    
}
