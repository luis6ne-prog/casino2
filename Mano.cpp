#include"Mano.h"

Mano::Mano(Carta car1, Carta car2, Carta car3, Carta car4, Carta car5){
    cartas[0] = car1;
    cartas[1] = car2;
    cartas[2] = car3;
    cartas[3] = car4;
    cartas[4] = car5;
     
    for(int i=0; i<4; i++){
        for(int j=0; j<4-i; j++){
            if(cartas[j].getNum() > cartas[j+1].getNum()){
                Carta aux = cartas[j];
                cartas[j] = cartas[j+1];
                cartas[j+1] = aux;
            }
        }
    }
}

void Mano::printMano(){
    cartas[0].printCarta();
    std::cout << std::endl;
    cartas[1].printCarta();
    std::cout << std::endl;
    cartas[2].printCarta();
    std::cout << std::endl;
    cartas[3].printCarta();
    std::cout << std::endl;
    cartas[4].printCarta();

    return;
}

bool Mano::Color(){
    if(cartas[0].getPalo() == cartas[1].getPalo() && cartas[1].getPalo() == cartas[2].getPalo() && cartas[2].getPalo() == cartas[3].getPalo() && cartas[3].getPalo() == cartas[4].getPalo())
        return true;
    else
        return false;
}

bool Mano::Escalera(){
    if(cartas[0].getNum()+1 == cartas[1].getNum() && cartas[1].getNum()+1 == cartas[2].getNum() && cartas[2].getNum()+1 == cartas[3].getNum() && cartas[3].getNum()+1 == cartas[4].getNum())
        return true;
    else 
        return false;
}

bool Mano::Full(){
    if((cartas[0].getNum() == cartas[1].getNum() && cartas[1].getNum() == cartas[2].getNum() && cartas[3].getNum() == cartas[4].getNum()) || (cartas[2].getNum() == cartas[3].getNum() && cartas[3].getNum() == cartas[4].getNum() && cartas[0].getNum() == cartas[1].getNum()))
        return true;
    else    
        return false;
}

bool Mano::DoblePar(){
    if((cartas[0].getNum() == cartas[1].getNum() && cartas[2].getNum() == cartas[3].getNum()) || (cartas[0].getNum() == cartas[1].getNum() && cartas[3].getNum() == cartas[4].getNum()) || (cartas[1].getNum() == cartas[2].getNum() && cartas[3].getNum() == cartas[4].getNum()))
        return true;
    else 
        return false;
}

int Mano::Iguales(){
    if(cartas[0].getNum() == cartas[1].getNum() && cartas[1].getNum() == cartas[2].getNum() && cartas[2].getNum() == cartas[3].getNum() && cartas[3].getNum() == cartas[4].getNum())
        return 5;
    else if((cartas[1].getNum() == cartas[2].getNum() && cartas[2].getNum() == cartas[3].getNum() && cartas[3].getNum() == cartas[4].getNum()) || (cartas[0].getNum() == cartas[1].getNum() && cartas[1].getNum() == cartas[2].getNum() && cartas[2].getNum() == cartas[3].getNum()))
        return 4;
    else if((cartas[0].getNum() == cartas[1].getNum() && cartas[1].getNum() == cartas[2].getNum()) || (cartas[1].getNum() == cartas[2].getNum() && cartas[2].getNum() == cartas[3].getNum()) || (cartas[2].getNum() == cartas[3].getNum() && cartas[3].getNum() == cartas[4].getNum()))
        return 3;
    else if(cartas[0].getNum() == cartas[1].getNum() || cartas[1].getNum() == cartas[2].getNum() || cartas[2].getNum() == cartas[3].getNum() || cartas[3].getNum() == cartas[4].getNum())
        return 2;
    else 
        return 1;
}

int Mano::CartaIgual(){
    int cantidad = this->Iguales();

    if(cantidad == 1){
        return cartas[4].getNum();
    }
    else if(cantidad == 2){
        if(cartas[0].getNum() == cartas[1].getNum()){
            return cartas[1].getNum();
        }
        else if(cartas[1].getNum() == cartas[2].getNum()){
            return cartas[2].getNum();
        }
        else if(cartas[2].getNum() == cartas[3].getNum()){
            return cartas[3].getNum();
        }
        else{
            return cartas[4].getNum();
        }
    }
    else if(cantidad == 3){
        if(cartas[0].getNum() == cartas[1].getNum() && cartas[1].getNum() == cartas[2].getNum()){
            return cartas[2].getNum();
        }
        else if(cartas[1].getNum() == cartas[2].getNum() && cartas[2].getNum() == cartas[3].getNum()){
            return cartas[3].getNum();
        }
        else{
            return cartas[4].getNum();
        }
    }
    else if(cantidad == 4){
        return cartas[3].getNum();
    }
    else
        return cartas[4].getNum();
}

int Mano::Puntos(){
    int puntos;
    int cantidad = this->Iguales();
    if(this->Color()){
        if(cantidad == 5){
            puntos = 10*15+cartas[4].getNum();
        }
        else if(this->Escalera()){
            puntos = 9*15+cartas[4].getNum();
        }
        else{
            puntos = 5*15+cartas[4].getNum();
        }
    }
    else if(this->Escalera()){
        puntos = 4*15+cartas[4].getNum();
    }
    else if(this->Full()){
        puntos = 6*15+cartas[4].getNum();
    }
    else if(this->DoblePar()){
        puntos = 2*15+cartas[3].getNum();
    }
    else if(cantidad == 5){
        puntos = 8*15+cartas[4].getNum();
    }
    else if(cantidad == 4){
        puntos = 7*15+cartas[3].getNum();
    }
    else if(cantidad == 3){
        puntos = 3*15+cartas[3].getNum();
    }
    else if(cantidad == 2){
        puntos = 1*15+this->CartaIgual();
    }
    else if(cantidad == 1){
        puntos = cartas[4].getNum();
    }

    return puntos;
}

int Mano::Car1(){
    return cartas[0].getNum();
}

int Mano::Car2(){
    return cartas[1].getNum();
}

int Mano::Car3(){
    return cartas[2].getNum();
}

int Mano::Car4(){
    return cartas[3].getNum();
}

int Mano::Car5(){
    return cartas[4].getNum();
}

bool Mano::ManoAlta(Mano mano2){
    if(this->Puntos() > mano2.Puntos()){
        return true;
    }
    else if(this->Puntos() < mano2.Puntos()){
        return false;
    }
    else{
        if(this->Car5() > mano2.Car5()){
            return true;
        }
        else if(this->Car5() < mano2.Car5()){
            return false;
        }
        else{
            if(this->Car4() > mano2.Car4()){
                return true;
            }
            else if(this->Car4() < mano2.Car4()){
                return false;
            }
            else{
                if(this->Car3() > mano2.Car3()){
                    return true;
                }
                else if(this->Car3() < mano2.Car3()){
                    return false;
                }
                else{
                    if(this->Car2() > mano2.Car2()){
                        return true;
                    }
                    else if(this->Car2() < mano2.Car2()){
                        return false;
                    }
                    else{
                        if(this->Car1() > mano2.Car1()){
                            return true;
                        }
                        else{
                            return true;
                        }
                    }
                }
            }
        }
    }
}