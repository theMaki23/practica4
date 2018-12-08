#ifndef BIN_H
#define BIN_H

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
	void crearProfesor(){
		cout <<"Introduce dni: \n";
		cin >>dni;
		cout <<"Introduce nombre: \n";
		cin>>nombre;
		cout<<"Introduce rol: \n";
		cin>>rol;
		cout<<"Introduce contrasena: \n";
		cin>>contrasena;
	}
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
};

void insertar();
void mostrarBIN();






#endif