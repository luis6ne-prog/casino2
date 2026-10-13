#include "Ruleta.h"

using namespace std;

void jugarRuleta(int& balance){
    srand(time(NULL));

    bool final = false;

    int resultado;
    int dinero;

    while(!final){
        int decision = -1;
        do{
            cout << "Dinero: " << dinero << endl << "1. Apostar a numeros." << endl << "2. Apostar a colores." << endl;
            cin >> decision;
        }while(decision < 1 || decision > 2);

        if(decision == 1){
            resultado = rand()%37;
            int apuesta = -1;
            int apuestaN = -1;
            do{
                cout << "Cuanto apuestas: ";
                cin >> apuesta;
            }while(apuesta < 0 || apuesta > dinero);
            dinero += -apuesta;
            do{
                cout << "Que numero eliges(0 a 36): ";
                cin >> apuestaN;
            }while(apuestaN < 0 || apuestaN > 36);

            for(int i=0; i<=37+resultado; i++){
                cout << ((i-2)%37 +37)%37 << " " << ((i-1)%37+37)%37 << " [" << i%37 << "] " << (i+1)%37 << " " << (i+2)%37;
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(100));
                if(i != 37+resultado){
                cout << "\033[2K\r";
                }
            }

            cout << endl << "El número es: " << resultado << endl;

            if(apuestaN == resultado){
                balance += apuesta*3;
                cout << "Ganador" << endl;
            }
            else{
                cout << "Perdedor" << endl;

            }
            int continua = -1;
            do{
                cout << "Continuar? 1 para si, 2 para no";
                cin >> continua;
            }while(continua < 1 || continua > 2);

            if(continua == 2){
                final = true;
            }
        }
        else{
            resultado = rand()%37;
            int apuesta = -1;
            int apuestaC = -1;
            do{
                cout << "Cuanto apuestas: ";
                cin >> apuesta;
            }while(apuesta < 0 || apuesta > dinero);
            
            dinero += -apuesta;
            
            do{
                cout << "Que color eliges(0 verde, 1 negro, 2 rojo): ";
                cin >> apuestaC;
            }while(apuestaC < 0 || apuestaC > 36);
            string colores[3];
            colores[0] = "Verde";
            colores[2] = "Negro";
            colores[1] = "Rojo";

            if(resultado == 0){
                resultado = 0;
            }
            else if(resultado%2 == 0){
                resultado = 1;
            }
            else{
                resultado = 2;
            }

            for(int i=0; i<=12+resultado; i++){
                cout << " " << colores[((i-1)%3+3)%3] << " [" << colores[i%3] << "] " << colores[(i+1)%3];
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(100));
                if(i != 12+resultado){
                cout << "\033[2K\r";
                }
            }
            cout << endl;
            if(resultado == 0){
                resultado = 0;
                cout << "El color es verde" << endl;
            }
            else if(resultado%2 == 0){
                resultado = 1;
                cout << "El color es negro" << endl;
            }
            else{
                resultado = 2;
                cout << "El color es rojo" << endl;
            }

            if(apuestaC == resultado && resultado == 1){
                balance += apuesta*2;
                cout << "Ganador" << endl;
            }
            else if(apuestaC == resultado && resultado == 2){
                balance += apuesta*2;
                cout << "Ganador" << endl;
            }
            else if(apuestaC == resultado && resultado == 0){
                balance += apuesta*4;
                cout << "Ganador" << endl;
            }
            else{
                cout << "Perdedor" << endl;
            }
            int continua = -1;
            do{
                cout << "Continuar? 1 para si, 2 para no";
                cin >> continua;
            }while(continua < 1 || continua > 2);

            if(continua == 2){
                final = true;
            }
        }

    }
}
