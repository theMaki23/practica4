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
	char apellidosnombre[100];
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

	char* getApellidosNombre(){
		strcpy(apellidosnombre, apellido1);
		strcat(apellidosnombre," ");
		strcat(apellidosnombre, apellido2);
		strcat(apellidosnombre,", ");
		strcat(apellidosnombre, nombre);
		return apellidosnombre;
	}

	inline void setdni(int x){dni=x;}
	inline void setnombre(char x[30]){strcpy(nombre,x);}
	inline void setapellido1(char x[30]){strcpy(apellido1,x);}
	inline void setapellido2(char x[30]){strcpy(apellido2,x);}
	inline void settelefono(int x){telefono=x;}
	inline void setemail(char x[30]){strcpy(email,x);}
	inline void setpostal(int x){postal=x;}
	inline void setcurso(int x){curso=x;}
	inline void setgrupo(int x){grupo=x;}
	void setlider(int x){
		if(x==0 || x==1){
			lider=x;
		}
	}
	
};





#endif
