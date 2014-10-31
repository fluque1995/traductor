SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebatraductor
# ************ Generación de documentación ******************
documentacion:

	@doxygen doc/doxys/Doxyfile > /dev/null
	@echo 'Generando documentacion...'

# ************ Compilación de módulos ************
$(BIN)/pruebatraductor: $(OBJ)/traductor.o $(OBJ)/palabra.o $(OBJ)/pruebatraductor.o

	@$(CXX) $(OBJ)/traductor.o $(OBJ)/palabra.o $(OBJ)/pruebatraductor.o -o $(BIN)/pruebatraductor
	@echo 'Generando el archivo ejecutable...'

$(OBJ)/traductor.o: $(SRC)/traductor.cpp

	@$(CXX) $(CPPFLAGS) $(SRC)/traductor.cpp -o $(OBJ)/traductor.o
	@echo 'Generando archivo objeto "traductor.o"...'

$(OBJ)/palabra.o: $(SRC)/palabra.cpp

	@$(CXX) $(CPPFLAGS) $(SRC)/palabra.cpp -o $(OBJ)/palabra.o
	@echo 'Generando archivo objeto "palabra.o"...'

$(OBJ)/pruebatraductor.o: $(SRC)/pruebatraductor.cpp

	@$(CXX) $(CPPFLAGS) $(SRC)/pruebatraductor.cpp -o $(OBJ)/pruebatraductor.o	
	@echo 'Generando archivo objeto "pruebatraductor.o"...'

# ************ Limpieza ************
clean:
	@-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ 2> /dev/null
	@echo 'Eliminando archivos sobrantes...'

mrproper: clean
	@-rm $(BIN)/* doxygen/html/* 2> /dev/null
	@echo 'Eliminando archivos de documentacion...'