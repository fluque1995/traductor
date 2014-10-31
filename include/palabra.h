#ifndef PALABRA
#define PALABRA

#include <string>
#include <vector>

using namespace std;
/**
* @class TDA Palabra. Cada instancia de este TDA es una 
* palabra en el idioma origen, que lleva además asociada sus 
* traducciones en el idioma al que se quiere traducir.
**/
class Palabra{

private:
/**
* @brief String que representa la palabra en el idioma
* original.
*/
	string palabra_base;
/**
* @brief Vector que contiene las distintas traducciones
* que tiene la palabra_base.
*/
	vector <string> traducciones;

public:

/**
* @brief Constructor de la clase Palabra.
* @param palabra_base String que representa la palabra en
* el idioma de origen.
* @param traducciones Vector de strings que contiene las traducciones
* de la palabra origen.
* @post Se ha creado un nuevo objeto de la clase Palabra a partir
* de los parametros que se han pasado.
*/
	Palabra(string palabra_base,vector <string> traducciones);
/**
* @brief Constructor por defecto de la clase Palabra.
* @post Se ha creado un nuevo objeto de la clase Palabra, que tiene
* vacios los campos de la palabra base y el vector de traducciones.
*/
	Palabra();
/**
* @brief Sobrecarga del operador de asignacion.
* @param otra Palabra que se quiere copiar.
* @return Instancia de la clase Palabra.
* @post La palabra se ha copiado en la otra instacia.
*/
	Palabra & operator= (const Palabra &otra);
/**
* @brief Metodo que devuelve la palabra en el idioma origen.
* @return Referencia a dicho string que representa la palabra.
*/
	string &getPalabra();
/**
* @brief Metodo que devuelve una determinada traduccion del vector
* de traducciones, correspondiente al índice que se ha pasado.
* @param indice Indice con el que se busca en el vector de traducciones.
* @pre El indice debe estar entre 0 y el tamaño del vector de traducciones.
* @return String que representa la traduccion buscada.
*/
	string getTraduccion(int indice);
/**
* @brief Metodo que devuelve el vector de traducciones completo.
* @return Vector de strings con todas las traducciones.
*/
	vector <string> &getTraducciones();
/**
* @brief Sobrecarga del operador de comparacion < entre dos 
* objetos de la clase Palabra.
*/
	inline bool operator<(const Palabra &otra) const{
		return this->palabra_base < otra.palabra_base;
	}
/**
* @brief Sobrecarga del operador de comparacion < entre un 
* objeto de la clase Palabra y un string. Se compara el string
* con la palabra del idioma origen.
*/
	inline bool operator<(const string &palabra) const{
		return this->palabra_base < palabra;
	}
/**
* @brief Sobrecarga del operador de comparacion > entre dos 
* objetos de la clase Palabra.
*/
	inline bool operator>(const Palabra &otra) const{
		return this->palabra_base > otra.palabra_base;
	}
/**
* @brief Sobrecarga del operador de comparacion > entre un 
* objeto de la clase Palabra y un string. Se compara el string
* con la palabra del idioma origen.
*/
	inline bool operator>(const string &palabra) const{
		return this->palabra_base > palabra;
	}
/**
* @brief Sobrecarga del operador de comparacion <= entre dos 
* objetos de la clase Palabra.
*/
	inline bool operator<=(const Palabra &otra) const{
		return this->palabra_base <= otra.palabra_base;
	}
/**
* @brief Sobrecarga del operador de comparacion <= entre un 
* objeto de la clase Palabra y un string. Se compara el string
* con la palabra del idioma origen.
*/
	inline bool operator<=(const string &palabra) const{
		return this->palabra_base <= palabra;
	}
/**
* @brief Sobrecarga del operador de comparacion >= entre dos 
* objetos de la clase Palabra.
*/
	inline bool operator>=(const Palabra &otra) const{
		return this->palabra_base >= otra.palabra_base;
	}
/**
* @brief Sobrecarga del operador de comparacion >= entre un 
* objeto de la clase Palabra y un string. Se compara el string
* con la palabra del idioma origen.
*/
	inline bool operator>=(const string &palabra) const{
		return this->palabra_base >= palabra;
	}
/**
* @brief Sobrecarga del operador de igualdad entre dos 
* objetos de la clase Palabra.
*/
	inline bool operator==(const Palabra &otra) const{
		return this->palabra_base == otra.palabra_base;
	}
/**
* @brief Sobrecarga del operador de igualdad entre un 
* objeto de la clase Palabra y un string. Se compara el string
* con la palabra del idioma origen.
*/
	inline bool operator==(const string &palabra) const{
		return this->palabra_base == palabra;
	}

};

#endif
