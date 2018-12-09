#include "profesor.h"

void Profesor::iniciar_sesion(int dni){
		Profesor a;
	ifstream fp1;
	fp1.open("credenciales.bin",ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
		if(a.getdni()==dni){
			cout<<"Comprobar la contraseña";
			fp1.close();
		}
	}
	cout<<"\nDNI incorrecto, inicie de nuevo el programa \n";
	fp1.close();
	exit(-1);
}


void Profesor::insertar(){
	Profesor p;
	ofstream fp2;
	fp2.open("credenciales.bin", ios::binary|ios::app);
	p.crearProfesor();
	fp2.write((char *)&p, sizeof(p));
	fp2.close();
}


void Profesor::mostrarBIN(){
	Profesor p;
	ifstream fp1;
	fp1.open("credenciales.bin",ios::binary);
	while(fp1.read((char*)&p,sizeof(p))){
		p.mostrarDatos();
	}
	fp1.close();
}