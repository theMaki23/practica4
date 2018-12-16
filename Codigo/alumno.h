#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include "validacion.h"

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
		char cadena[30];
		char opcion[1];

		do{
		cout<<"Introduce dni valido, compuesto por solo 8 numeros: \n";
		cin>>cadena;
		}while(!validarDNI(cadena));
		dni=atoi(cadena);

		do{
		cout <<"Introduce nombre: \n";
		cin>>cadena;
		}while(!validarpalabra(cadena));
		strcpy(nombre,cadena);

		do{
		cout<<"Introduce primer apellido: \n";
		cin>>cadena;
		}while(!validarpalabra(cadena));
		strcpy(apellido1,cadena);

		do{
		cout<<"Introduce segundo apellido: \n";
		cin>>cadena;
		}while(!validarpalabra(cadena));
		strcpy(apellido2,cadena);

		do{
		cout<<"Introduce telefono: \n";
		cin>>cadena;
		}while(!validartelefono(cadena));
		telefono=atoi(cadena);

		cout<<"Introduce email: \n";
		cin>>email;

		do{
		cout<<"Introduce codigo postal: \n";
		cin>>cadena;
		}while(!validarCP(cadena));
		postal=atoi(cadena);

		do{
		cout<<"Introuduce curso mas alto matriculado: \n";
		cin>>cadena;
		}while(!validarcurso(cadena));
		curso=atoi(cadena);

		grupo= 0;
		lider= 0;
		
		cout<<"¿Desea introducir su grupo y si es lider ahora? s/n \n";
		cin>>opcion;

		if(strcmp(opcion,"s")==0){

			do{
				cout<<"Introduce grupo: \n";
				cin>>cadena;
			}while(!validargrupo(cadena));
			grupo=atoi(cadena);

			do{
				cout<<"Introuduce si es lider o no, lider=1; no lider=0: \n";
				cin>>cadena;
			}while(!validarlider(cadena));
			lider=atoi(cadena);
		}
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
		cout <<"\n"<< "DNI: "<< dni <<"\nNombre: "<<nombre<<"\nPrimer apellido: "<<apellido1<<"\nSegundo apellido: "<<apellido2<<"\nTelefono: "<<telefono<<"\nEmail:  "<<email<<"\nCodigo postal: "<<postal<<"\nCurso mas alto matriculado: "<<curso<<"\nGrupo: "<<grupo<<"\nLider (1=si, 0=no): "<<lider<<"\n";
	}
};





#endif
