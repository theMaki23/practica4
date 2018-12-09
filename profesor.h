#ifndef PROFESOR_H
#define PROFESOR_H
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;


class Profesor{
 private:
 	string nombre, apellido1, contrasena;
 	int rol, dni;

 public:
 	Profesor(){};

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

 	void iniciar_sesion();

 	int getdni(){
		return dni;
	}

	string get_nombre(){
		return nombre;
	}

	string get_apellido1(){
		return apellido1;
	}

	int get_rol(){
		return rol;
	}

	string getcontrasena(){
		return contrasena;
	}

	void mostrarDatos(){
		cout<<dni<<" "<<nombre<<" "<<rol<<" "<<contrasena<<" \n";
	}


	void insertar();

	void mostrarBIN();
};

#endif