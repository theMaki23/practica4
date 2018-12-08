#include "bin.h"

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