#ifndef BASEDATOS_H
#define BASEDATOS_H

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;


class basedatos{

	int limite;

public:

	void setlimite(){
		limite=150;
	}
	int getlimite(){
		return limite;
	}
	void insertar();
	int buscarDNI(int dni);
	int buscarNombre(char nombre[30]);
	int buscarApellido1(char apellido1[30]);
	void borrarporDNI(int dni);
	int borrarporApellido1(char apellido1[30]);
	void mostrarGrupo(int grupo);
	void mostrarLider();
	void cargarFicheroBin();
	void cargarCopiaSeguridad();
	void ModificarporDNI(int dni);
	int modificarporApellido1(char apellido1[30]);
	void generarFichero();
	void generarCopiaSeguridad();
};



#endif