#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

class alumno{
	int dni;
	char nombre[30];
	char apellido1[30];
	char apellido2[30];
	int telefono;
	char email[20];
	int postal;
	int curso;
	int grupo;
	int lider;
public:
	void crearAlumno(){
		cout <<"Introduce dni: \n";
		cin >>dni;
		cout <<"Introduce nombre: \n";
		cin>>nombre;
		cout<<"Introduce apellido1: \n";
		cin>>apellido1;
		cout<<"Introduce apellido2: \n";
		cin>>apellido2;
		cout<<"introudce telefono: \n";
		cin>>telefono;
		cout<<"introudce email: \n";
		cin>>email;
		cout<<"introduce codigo postal: \n";
		cin>>postal;
		cout<<"introudce curso mas alto matriculado: \n";
		cin>>curso;
		cout<<"Introduce grupo: \n";
		cin>>grupo;
		cout<<"introudce si es lider o no, lider=1; no lider=0: \n";
		cin>>lider;
	}
	int getdni(){
		return dni;
	}
	char* getnombre(){
		return nombre;
	}
	char* getapellido1(){
		return apellido1;
	}
	char* getapellido2(){
		return apellido2;
	}
	int gettelefono(){
		return telefono;
	}
	char* getemail(){
		return email;
	}
	int getpostal(){
		return postal;
	}
	int getcurso(){
		return curso;
	}
	int getgrupo(){
		return grupo;
	}
	int getlider(){
		return lider;
	}

	void mostrardata(){
		cout << dni <<" "<<nombre<<" "<<apellido1<<" "<<apellido2<<" "<<telefono<<" "<<email<<" "<<postal<<" "<<curso<<" "<<grupo<<" "<<lider<<"\n";
	}
};

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




#endif
