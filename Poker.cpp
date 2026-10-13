#include "Poker.h"

using namespace std;

void jugarPoker(int& balance){
    srand(time(NULL));
            int numJug = 0, jug_prin;
            while(numJug < 2 || numJug > 4){
                std::cout << "Introduce numero jugadores(max 4): ";
                std::cin >> numJug;
            }
            Jugador jugador1;
            Jugador jugador2;
            Jugador jugador3;
            Jugador jugador4;
 
            bool jug1 = true;
            bool jug2 = true;
            bool jug3 = true;
            bool jug4 = true;

            do {
                std::cout << "Quién es el jugador principal y usará el balance principal? ";
                std::cin >> jug_prin;
            } while (jug_prin < 1 || jug_prin > numJug);

            switch (jug_prin) {
            case 1: balance -= jugador1.Getdin(); break;
            case 2: balance -= jugador2.Getdin(); break;
            case 3: balance -= jugador3.Getdin(); break;
            case 4: balance -= jugador4.Getdin(); break;
            }

            if(numJug == 2){
                jug3 = false;
                jug4 = false;
            }
            if(numJug == 3){
                jug4 = false;
            }
 
            bool terminado = false;
            while(!terminado){
                int bote = 0;
                int minimo = 10;
                for(int i=1; i<=3; i++){
                    for(int j=1; j<=numJug; j++){
                        int decision = 0;
                        int apostar = 0;
                        if(j==1 && jug1 && jugador1.Getdin()>0 && (jug2 || jug3 ||jug4)){
                            std::cout << "Dinero jugador 1: " << jugador1.Getdin() << std::endl;
                            std::cout << "Dinero bote: " << bote << std::endl;
                            Carta generar;
                            int apuesta = -1;
                            jugador1.setCarta(generar);
                            while(decision<1 || decision>2){
                                std::cout << "Jugador 1, quieres ver tu mano? 1 para ver cartas, 2 para no verlas. ";
                                std::cin >> decision;
                            }
                            if(decision == 1){
                                jugador1.Printcartas();
                            }
                            while(apostar < 1 || apostar > 2){
                                std::cout << "Vas a apostar? 1 para apostar, 2 para planatarse. ";
                                std::cin >> apostar;
                            }
                            if(apostar == 1){
                                while(apuesta > jugador1.Getdin() || apuesta < minimo){
                                    std::cout << "Cuanto apuestas? Minimo: " << minimo << " ";
                                    std::cin >> apuesta;
                                }
                                minimo = apuesta;
                                jugador1.CambiarDin(apuesta*-1);
                                bote+=apuesta;
                            }
                            else{
                                jug1 = false;
                            }
                        }
                        if(j==2 && jug2 && jugador2.Getdin()>0 && (jug1 || jug3 ||jug4)){
                            std::cout << "Dinero jugador 2: " << jugador2.Getdin() << std::endl;
                            std::cout << "Dinero bote: " << bote << std::endl;
                            Carta generar;
                            int apuesta = -1;
                            jugador2.setCarta(generar);
                            while(decision<1 || decision>2){
                                std::cout << "Jugador 2, quieres ver tu mano? 1 para ver cartas, 2 para no verlas. ";
                                std::cin >> decision;
                            }
                            if(decision == 1){
                                jugador2.Printcartas();
                            }
                            while(apostar < 1 || apostar > 2){
                                std::cout << "Vas a apostar? 1 para apostar, 2 para planatarse. ";
                                std::cin >> apostar;
                            }
                            if(apostar == 1){
                                while(apuesta > jugador2.Getdin() || apuesta < minimo){
                                    std::cout << "Cuanto apuestas? Minimo: " << minimo << " ";
                                    std::cin >> apuesta;
                                }
                                minimo = apuesta;
                                jugador2.CambiarDin(apuesta*-1);
                                bote+=apuesta;
                            }
                            else{
                                jug2 = false;
                            }
                        }
                        if(j==3 && jug3 && jugador3.Getdin()>0 && (jug2 || jug1 ||jug4)){
                            std::cout << "Dinero jugador 3: " << jugador3.Getdin() << std::endl;
                            std::cout << "Dinero bote: " << bote << std::endl;
                            Carta generar;
                            int apuesta = -1;
                            jugador3.setCarta(generar);
                            while(decision<1 || decision>2){
                                std::cout << "Jugador 3, quieres ver tu mano? 1 para ver cartas, 2 para no verlas. ";
                                std::cin >> decision;
                            }
                            if(decision == 1){
                                jugador3.Printcartas();
                            }
                            while(apostar < 1 || apostar > 2){
                                std::cout << "Vas a apostar? 1 para apostar, 2 para planatarse. ";
                                std::cin >> apostar;
                            }
                            if(apostar == 1){
                                while(apuesta > jugador3.Getdin() || apuesta < minimo){
                                    std::cout << "Cuanto apuestas? Minimo: " << minimo << " ";
                                    std::cin >> apuesta;
                                }
                                minimo = apuesta;
                                jugador3.CambiarDin(apuesta*-1);
                                bote+=apuesta;
                            }
                            else{
                                jug3 = false;
                            }
                        }
                        if(j==4 && jug4 && jugador4.Getdin()>0 && (jug2 || jug3 ||jug1)){
                            std::cout << "Dinero jugador 4: " << jugador4.Getdin() << std::endl;
                            std::cout << "Dinero bote: " << bote << std::endl;
                            Carta generar;
                            int apuesta = -1;
                            jugador4.setCarta(generar);
                            while(decision<1 || decision>2){
                                std::cout << "Jugador 4, quieres ver tu mano? 1 para ver cartas, 2 para no verlas. ";
                                std::cin >> decision;
                            }
                            if(decision == 1){
                                jugador4.Printcartas();
                            }
                            while(apostar < 1 || apostar > 2){
                                std::cout << "Vas a apostar? 1 para apostar, 2 para planatarse. ";
                                std::cin >> apostar;
                            }
                            if(apostar == 1){
                                while(apuesta > jugador4.Getdin() || apuesta < minimo){
                                    std::cout << "Cuanto apuestas? Minimo: " << minimo << " ";
                                    std::cin >> apuesta;
                                }
                                minimo = apuesta;
                                jugador4.CambiarDin(apuesta*-1);
                                bote+=apuesta;
                            }
                            else{
                                jug4 = false;
                            }
                        }
                    }
                }
 
                Mano mano1 = jugador1.generarmano();
                Mano mano2 = jugador2.generarmano();
                Mano mano3 = jugador3.generarmano();
                Mano mano4 = jugador4.generarmano();
                int ganador1 = 0;
                int ganador2 = 0;
                if(jug1){
                    std::cout << "Mano jugador 1" << std::endl;
                    mano1.printMano();
                }
                if(jug2){
                    std::cout << "Mano jugador 2" << std::endl;
                    mano2.printMano();
                }
                if(jug3){
                    std::cout << "Mano jugador 3" << std::endl;
                    mano3.printMano();
                }
                if(jug4){
                    std::cout << "Mano jugador 4" << std::endl;
                    mano4.printMano();
                }
                if(jug1 && jug2){
                    if(mano1.ManoAlta(mano2)){
                        ganador1 = 1;
                    }
                    else{
                        ganador1 = 2;
                    }
                }
                else if(jug1 && !jug2){
                    ganador1 = 1;
                }
                else if(!jug1 && jug2){
                    ganador1 = 2;
                }
                else if(!jug1 && !jug2){
                    ganador1 = 0;
                }
 
                if(jug3 && jug4){
                    if(mano3.ManoAlta(mano4)){
                        ganador2 = 1;
                    }
                    else{
                        ganador2 = 2;
                    }
                }
                else if(jug3 && !jug4){
                    ganador2 = 1;
                }
                else if(!jug3 && jug4){
                    ganador2 = 2;
                }
                else if(!jug3 && !jug4){
                    ganador2 = 0;
                }
 
                if(ganador1 == 1 && ganador2 == 1){
                    if(mano1.ManoAlta(mano3)){
                        std::cout << "Gana jugador 1.";
                        jugador1.CambiarDin(bote);
                    }
                    else{
                        std::cout << "Gana jugador 3.";
                        jugador3.CambiarDin(bote);
                    }
                }
                else if(ganador1 == 1 && ganador2 == 2){
                    if(mano1.ManoAlta(mano4)){
                        std::cout << "Gana jugador 1.";
                        jugador1.CambiarDin(bote);
                    }
                    else{
                        std::cout << "Gana jugador 4.";
                        jugador4.CambiarDin(bote);
                    }
                }
                else if(ganador1 == 1 && ganador2 == 0){
                    std::cout << "Gana jugador 1.";
                    jugador1.CambiarDin(bote);
                }
                else if(ganador1 == 2 && ganador2 == 1){
                    if(mano2.ManoAlta(mano3)){
                        std::cout << "Gana jugador 2.";
                        jugador2.CambiarDin(bote);
                    }
                    else{
                        std::cout << "Gana jugador 3.";
                        jugador3.CambiarDin(bote);
                    }
                }
                else if(ganador1 == 2 && ganador2 == 2){
                    if(mano2.ManoAlta(mano4)){
                        std::cout << "Gana jugador 2.";
                        jugador2.CambiarDin(bote);
                    }
                    else{
                        std::cout << "Gana jugador 4.";
                        jugador4.CambiarDin(bote);
                    }
                }
                else if(ganador1 == 2 && ganador2 == 0){
                    std::cout << "Gana jugador 2.";
                    jugador2.CambiarDin(bote);
                }
                else if(ganador1 == 0 && ganador2 == 1){
                    std::cout << "Gana jugador 3.";
                    jugador3.CambiarDin(bote);
                }
                else if(ganador1 == 0 && ganador2 == 2){
                    std::cout << "Gana jugador 4.";
                    jugador4.CambiarDin(bote);
                }
                else if(ganador1 == 0 && ganador2 == 0){
                    std::cout << "No hay ganador";
                }
                
                switch (jug_prin) {
                    case 1: balance += jugador1.Getdin(); break;
                    case 2: balance += jugador2.Getdin(); break;
                    case 3: balance += jugador3.Getdin(); break;
                    case 4: balance += jugador4.Getdin(); break;
                }
                std::cout << std::endl;
                int acabar;
                std::cout << "Continuar? 1 para continuar, 2 para acabar. ";
                std::cin >> acabar;
 
                jug1 = true;
                jug2 = true;
                jug3 = true;
                jug4 = true;
                jugador1.Resetear();
                jugador2.Resetear();
                jugador3.Resetear();
                jugador4.Resetear();
 
                if(acabar == 2){
                    terminado = true;
                }
                if(!terminado && numJug == 2){
                    jug3 = false;
                    jug4 = false;
                }
                if(!terminado && numJug == 3){
                    jug4 = false;
                }
            }
}
