#include "Tragaperras.h"

using namespace std;

void Tragaperras::roll(){
    const int limite = getNumFiguras();
    for (int i = 0; i < max; i++)
        results[i] = rand() % limite;
}

void Tragaperras::roll_animation(int vueltas) const {
    const int figuras = getNumFiguras();

    // pasos totales de cada rodillo: vueltas completas + desfase + su resultado
    int totales[100];
    for (int k = 0; k < max; k++)
        totales[k] = vueltas * figuras + figuras * k + results[k];

    for (int i = 0; i <= totales[max - 1]; i++) {
        for (int fila = 0; fila < 3; fila++) {
            cout << "\033[2K";                  // borra la línea antes de escribirla
            cout << (fila == 1 ? ">" : " ");    // marca la fila válida (la de en medio)

            for (int k = 0; k < max; k++) {
                int paso = (i < totales[k]) ? i : totales[k];

                // fila 0 = arriba (siguiente), fila 1 = medio (actual), fila 2 = abajo (anterior)
                int desfase = 1 - fila;
                int fig = ((paso + desfase) % figuras + figuras) % figuras;

                cout << toString(fig);
                if (k < max - 1) cout << "|";
            }

            cout << (fila == 1 ? "<" : " ") << "\n";
        }
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(50));
        if (i != totales[max - 1])
            cout << "\033[3A";                  // sube 3 líneas para el siguiente fotograma
    }
}

bool Tragaperras::win(int& winfigure){
    bool won = true;

    for (int i = 0; i < max - 1; i++){
        if (results[i] != results[i+1])
            won = false;
    }
    
    if (won){
        winfigure = results[0];
        return true;
    }    
    else{
        winfigure = -1;
        return false;
    }   
}

long long Tragaperras::reward(int figure){
    int reward_icono = 0;

    switch (figure){
        case CEREZA:  reward_icono = PUNT_CEREZA;  break;
        case LIMON:   reward_icono = PUNT_LIMON;   break;
        case UVA:     reward_icono = PUNT_UVA;     break;
        case SANDIA:  reward_icono = PUNT_SANDIA;  break;
        case CAMPANA: reward_icono = PUNT_CAMPANA; break;
        case SIETE:   reward_icono = PUNT_SIETE;   break;
    }

    return dinero * reward_icono * max * (max - 1) / 90;
}

string Tragaperras::toString(int figure) const {
    switch (figure) {
        case CEREZA:  return " 🍒 ";
        case LIMON:   return " 🍋 ";
        case UVA:     return " 🍇 ";
        case SANDIA:  return " 🍉 ";
        case CAMPANA: return " 🔔 ";
        case SIETE:   return " 7️⃣  ";
        default:      return " ?  ";
    }
}

void Tragaperras::jugar(int& balance){

    srand(time(nullptr));

    int money, figura_ganadora, maximo, tiradas;
    char respuesta = 'y';

    cout << "Introduce el número de rodillos. Cuantos más rodillos mejor recompensa" << endl;
    do {
        cin >> maximo;
    } while (maximo <= 1 || maximo > 100);

    do {

        cout << "Tienes " << balance << " monedas" << endl;

        //deposita cierto dinero
        do {
            cout << "Introduce el número de monedas deseado" << endl;
            cin >> money;
        } while (money < 1);
        Tragaperras t(money, maximo);

        do {
            cout << "Cuántas tiradas quieres hacer? ";
            cin >> tiradas;
        } while (tiradas < 1);

        for (int i = 0; i < tiradas && balance >= money; i++) {
            balance -= money;

            // rollea los tres rodillos
            t.roll();
            t.roll_animation(5);

            // mira a ver si ha ganado y si es así da la recompensa
            if (t.win(figura_ganadora)) {
                int premio = t.reward(figura_ganadora);
                cout << endl << "Has ganado " << premio << " monedas" << endl;
                balance += premio;
            } else {
                cout << endl << "Has perdido" << endl;
            }
        }

        if (balance < 1) {
            cout << "No puedes apostar más, no te quedan monedas." << endl;
            respuesta = 'n';
        } else {
            cout << "Quieres jugar otra partida? (y/n)" << endl;
            do {
                cin >> respuesta;
            } while (respuesta != 'y' && respuesta != 'n');
        }

    } while (respuesta == 'y');

    cout << "Has salido con " << balance << " monedas" << endl;

}

int Tragaperras::getMax() {return max;}
int Tragaperras::getDinero() {return dinero;}
int Tragaperras::getResults(int index) {return results[index];}
int Tragaperras::getNumFiguras() const {return sizeof(rodillo) / sizeof(rodillo[0]);}

void Tragaperras::setDinero(const int money) {dinero = money;}

