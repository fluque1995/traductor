#include "palabra.h"
#include <string>
#include <vector>

Palabra::Palabra(string palabra_base, vector <string> traducciones){
	this->palabra_base = palabra_base;
	int size = traducciones.size();
	for(int i = 0; i < size; i++){
		this->traducciones.push_back(traducciones[i]);
	}
}

Palabra::Palabra(){
	this->palabra_base = " ";
}

Palabra & Palabra::operator= (const Palabra &otra){
	this->palabra_base = otra.palabra_base;
	this->traducciones = otra.traducciones;
	return *this;
}

string &Palabra::getPalabra(){
	return this->palabra_base;
}

string Palabra::getTraduccion(int indice){
	int size = traducciones.size();
	if(indice < size){
		return traducciones[indice];
	}else{
		return "La palabra no tiene tantas traducciones.";
	}	
}

vector <string> &Palabra::getTraducciones(){
	return traducciones;
}
