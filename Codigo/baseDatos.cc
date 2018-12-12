//baseDatos.cc
#include "baseDatos.h"
#include <iostream>
#include <cstdlib>

using namespace std;



void muestra(const list<Alumno>& L){		//muestra la lista de alumnos (ordenarla antes con .sort() --- Basada en alumno.h Javi, cambiar funiciones si utilizamos otro alumno.h)
	list<Alumno>::const_iterator it=L.begin();
	cout<<"LISTA ALUMNOS"<<endl;

	//de cada alumno se mostrara DNI -- Nombrecompleto -- Curso -- email -- equipo -- lider -- telefono -- direccion
	for(int k=0; it!=L.end(); it++, k++){
		cout<<it->getDNI()<<"	"<<it->getApellidosNombre()<<"	"<<it->getCurso()<<"	"<<it->getEmail()<<"	"<<it->getEquipo()<<"	"<<it->getLider()<<"	"<<it->getTelefono()<<"	"<<it->getDireccion()<<endl;
	}
}

bool AscendenteNombre(const Alumno& A, const Alumno& B){	// A-B-C-...-Z
	return A.getApellidosNombre() < B.getApellidosNombre();
}

bool DescendenteNombre(const Alumno& A, const Alumno& B){	// Z-Y-X-...-A
	return A.getApellidosNombre() > B.getApellidosNombre();
}

bool AscendenteDNI(const Alumno& A, const Alumno& B){	//0-1-2-...
	return A.getDNI() < B.getDNI();
}

bool DescendenteDNI(const Alumno& A, const Alumno& B){ 	//999...-...-0
	return A.getDNI() > B.getDNI();
}

bool AscendenteCurso(const Alumno& A, const Alumno& B){	//0-1-2-...
	return A.getCurso() < B.getCurso();
}

bool DescendenteCurso(const Alumno& A, const Alumno& B){ 	//999...-...-0
	return A.getCurso() > B.getCurso();
}



void BaseDatos::MostrarAlumnos(){
	int dato, orden;

	cout<<"Elige el dato por el cual quieres que se muestren los alumnos ordenadamente:   (1, 2 o 3)"<<endl;
	cout<<"1.- Apellidos y nombre"<<endl;
	cout<<"2.- DNI"<<endl;
	cout<<"3.- Curso mas alto por el que esté matriculado"<<endl;
	cin>>dato;

	cout<<"\nElige el orden en el que se muestran:   (1 o 2)"<<endl;
	cout<<"1.- Ascendente"<<endl;
	cout<<"2.- Descendente"<<endl;
	cin>>orden;

	if((dato==1 || dato==2 || dato==3) && (orden==1 || orden==2)){
		switch(dato){
			//Apellidos y nombre
			case 1:{
				if(orden==1){	//Ascendente
					alumnos_.sort(AscendenteNombre);	//.sort() ordena la lista
					muestra(alumnos_);	//muestra la lista segun este ordenada, en este caso ya estará ordenada segun le impuse antes
				}else{		// Descendente
					alumnos_.sort(DescendenteNombre);
					muestra(alumnos_);
				}
			}

			//DNI
			case 2:{
				if(orden==1){	//Ascendente
					alumnos_.sort(AscendenteDNI);
					muestra(alumnos_);
				}else{	//Descendente
					alumnos_.sort(DescendenteDNI);
					muestra(alumnos_);
				}
			}

			//Curso
			case 3:{
				if(orden==1){	//Ascendente
					alumnos_.sort(AscendenteCurso);
					muestra(alumnos_);
				}else{	//Descendente
					alumnos_.sort(DescendenteCurso);
					muestra(alumnos_);
				}
			}
		}//END switch

	}else{
		cout<<"ERROR. Debe elegir un dato con un numero del 1 al 3 y un orden con 1 o 2."<<endl;
	}
}