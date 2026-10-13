#include <iostream>
#include "Tragaperras.h"
#include "Ruleta.h"
#include "Poker.h"
#include "Blackjack.h"
#include "Carta.h"
#include "Mano.h"
#include "Jugador.h"

using namespace std;

int main() {
    int balance = 10000;
    char game;

    do {
        cout << "Balance: " << balance << endl;
        cout << "Selecciona el juego (b: blackjack, t: tragaperras, r: ruleta, p: póker s: salir): ";

        do {
            cin >> game;
        } while (game != 'b' && game != 't' && game != 'r' && game != 'p' && game != 's');

        switch (game) {
        case 'b': {
            
            jugarBlackjack(balance);

            break;
        }

        case 't': {
            
            Tragaperras::jugar(balance);

            break;
        }

        case 'r': {
            
            jugarRuleta(balance);
            
            break;
        }

        case 'p': {
            
            jugarPoker(balance);

            break;
        }

        case 's':
            cout << "Has salido con " << balance << " monedas\n";
            break;
        }

    } while (game != 's');

    return 0;

}
