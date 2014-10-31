#ifndef TRADUCTOR
#define TRADUCTOR

#include <iostream>
#include "palabra.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;
/**
* @class TDA Traductor. Cada instancia de este TDA es 
* un diccionario traductor que contiene todas las palabras de un 
* idioma junto con sus traducciones en el idioma al que se quiere
* traducir.
*/
class Traductor{
private:

	vector <Palabra> conjunto_palabras;

public:
/**
* @brief Constructor por defecto de la clase traductor.
* Crea un traductor vacio, que no contiene ninguna palabra.
*/	
	Traductor();
/**
* @brief Metodo que permite agregar un objeto de la clase Palabra
* al final del Traductor.
*/
	void insertarPalabra(Palabra nueva);
/**
* @brief Metodo que permite construir una instancia de la clase
* Palabra a partir de una linea. Este metodo es auxiliar a la 
* sobrecarga del operator>>(istream &input, Traductor &traductor).
* @param linea String que contiene una linea a partir de la cual
* se crea la nueva Palabra.
* @return Objeto de la clase Palabra que se ha creado. 
*/
	Palabra construirPalabra(string linea);
/**
* @brief Metodo que devuelve la posicion de una determinada Palabra
* en el traductor, a partir del string que se ha pasado. Este metodo
* es auxiliar al metodo getTraducciones(string palabra).
* @param palabra Palabra que se tiene que buscar dentro del traductor.
* @return Si el algoritmo encuentra la palabra dentro del traductor,
* devuelve el indice en el que esta la palabra. Si no, devuelve el
* valor -1.
*/
	int posicion(string palabra);
/**
* @brief Sobrecarga del operador de entrada de datos. Permite que
* se rellene un traductor con objetos de la clase palabra a partir
* de un archivo que se pasa.
* @param input Archivo al que se accede para crear el traductor.
* @param traductor Traductor que se va a rellenar.
* @pre El archivo de entrada tiene que tener el siguiente esquema
* en cada linea:
* palabra_base;traduccion;traduccion;...
* @post traductor tiene que tener un objeto de la clase Palabra
* por cada linea del archivo de entrada, y ademas estar ordenado.
* @return Se devuelve el archivo de entrada, para que pueda
* utilizarse de nuevo.
*/
	friend istream & operator>>(istream &input, Traductor &traductor);
/**
* @brief Metodo que devuelve todas las traducciones de una palabra.
* Busca si hay alguna palabra en el Traductor que tenga como palabra
* base el string que se pasa como argumento, y si existe una
* coincidencia, devolver el vector de traducciones asociado.
* @param palabra String que representa la palabra sobre la que se
* busca la traduccion.
* @return Un vector de strings con las traducciones buscadas.
*/
	vector <string> getTraducciones(string palabra);
/**
* @brief Metodo que ordena el traductor. Utiliza para ordenar la 
* funcion ordenar(int inicio, int final).
*/
	void ordenar();
/**
* @brief Metodo que ordena un traductor desde la posicion que se
* pasa como inicio hasta la posicion que se pasa como final.
* @param inicio Punto de inicio a partir del que se ordena el 
* traductor.
* @param final Punto hasta el que se ordena el traductor.
*/
	void ordenar(int inicio, int final);
/**
* @brief Metodo que comprueba si el traductor esta ordenado.
* @return Devuelve true si el traductor esta ordenado.
*/
	bool isSorted();

};

#endif