#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

class profesor{
	char nombre[20];
	int dni;
	char contrasena[30];
	int rol;
	
public:

	int getDNI(){
		return dni;
	}
	char* getnombre(){
		return nombre;
	}
	int getrol(){
		return rol;
	}
	char* getcontrasena(){
		return contrasena;
	}
	void mostrarDatos(){
		cout<<dni<<" "<<nombre<<" "<<rol<<" "<<contrasena<<" \n";
	}
	bool loginProfesor(int dni, char contrasena[30]);
	void generarFichero();
};





#endif
