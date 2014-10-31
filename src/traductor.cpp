#include <vector>
#include "traductor.h"
#include "palabra.h"
#include <string>
#include <fstream>
#include <stdexcept>

Traductor::Traductor(){}

void Traductor::insertarPalabra(Palabra nueva){
    conjunto_palabras.push_back(nueva);
}

Palabra Traductor::construirPalabra(string linea){
    const char limitador = ';';
    bool palabra_ya_introducida = false;
    string acumulador, palabra_base;
    vector <string> traducciones;
    int size = linea.size();
    for (int i = 0; i < size; i++){
        if (linea[i] != limitador){
            acumulador.push_back(linea[i]);
        }else if(palabra_ya_introducida){
            traducciones.push_back(acumulador);
            acumulador.clear();
        }else{
            palabra_base = acumulador;
            palabra_ya_introducida = true;
            acumulador.clear();
        }
    }
    Palabra nueva(palabra_base, traducciones);
    return nueva;
}

int Traductor::posicion(string palabra){
    int inicio = 0;
    int final = conjunto_palabras.size();
    int indice = -1;
    int media;
    while (inicio < final && indice == -1){
        media = (inicio + final)/2;
        if (palabra == conjunto_palabras[media].getPalabra()){
            indice = media;
        }else if (palabra < conjunto_palabras[media].getPalabra()){
            final = media;
        }else{
            inicio = media + 1;
        }
    }
    return indice;
}

istream & operator>>(istream &conjunto_palabras, Traductor &traductor){
    string linea;
    while(getline(conjunto_palabras, linea)){
        Palabra nueva = traductor.construirPalabra(linea);
        traductor.insertarPalabra(nueva);
    }

    traductor.ordenar();

    return conjunto_palabras;
}

vector <string> Traductor::getTraducciones(string palabra){
    
    int indice = this->posicion(palabra);
    if (indice != -1){
        return conjunto_palabras[indice].getTraducciones(); 
    }
    else{
        throw invalid_argument("No existe dicha palabra");    
    }
}

void Traductor::ordenar(){

    this->ordenar(0, this->conjunto_palabras.size());
}

void Traductor::ordenar(int inicio, int final){

    Palabra actual;
    int j;

    for(int i = inicio; i < final; i++){

        actual = this->conjunto_palabras[i];

        j = i;

        while(j > inicio && this->conjunto_palabras[j - 1] >= actual){

            this->conjunto_palabras[j] = this->conjunto_palabras[j - 1];
            j--;

        }

        this->conjunto_palabras[j] = actual;

    }
}


bool Traductor::isSorted(){
    int i = 0, tope = conjunto_palabras.size() - 2;
    while (this->conjunto_palabras[i] <= this->conjunto_palabras[i + 1] && i < tope)
        i++;
    return i == tope;
}