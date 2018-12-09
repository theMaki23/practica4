#include "profesor.h"

void iniciar_sesion(int dni){
		Profesor a;
	ifstream fp1;
	fp1.open("credenciales.bin",ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
		if(a.dni()==dni){
			cout<<"hola";
			fp1.close();
		}
	}
	cout<<"\nalumno no existe\n";
	fp1.close();
}

void insertar(){
	profesor p;
	ofstream fp2;
	fp2.open("credenciales.bin", ios::binary|ios::app);
	p.crearProfesor();
	fp2.write((char *)&p, sizeof(p));
	fp2.close();
}



void mostrarBIN(){
	profesor p;
	ifstream fp1;
	fp1.open("credenciales.bin",ios::binary);
	while(fp1.read((char*)&p,sizeof(p))){
		p.mostrarDatos();
	}
	fp1.close();
}