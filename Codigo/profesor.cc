#include "profesor.h"
#include "alumno.h"
#include "basedatos.h"
#include "validacion.h"


void profesor::generarFicheroBin(){
	ofstream fp1;
	ifstream fp2;
	fp1.open("ficheroDatos.bin",ios::app);
	alumno a;
	int contador=0;
	fp2.open("alumno.bin",ios::in|ios::out);
	while(fp2.read((char*)&a, sizeof(a))){
		contador++;
		fp1.write((char*)&a, sizeof(a));
	}
		
	if(contador==0){
		cout<<"\nBase de datos vacia";
	}
	fp1.close();
	fp2.close();
}


void profesor::generarCopiaSeguridad(){
	ofstream fp1;
	ifstream fp2;
	fp1.open("CopiaSeguridad.bin",ios::out);
	alumno a;
	int contador=0;
	fp2.open("alumno.bin",ios::in|ios::out);
	while(fp2.read((char*)&a, sizeof(a))){
		contador++;
		fp1.write((char*)&a, sizeof(a));
	}
		
	if(contador==0){
		cout<<"\nBase de datos vacia";
	}
	fp1.close();
	fp2.close();
}

bool profesor::loginProfesor(int dni, char contrasena[30]){
	profesor p;
	ifstream fp1;
	int contador=0;
	fp1.open("credenciales.bin",ios::binary);
	while(fp1.read((char*)&p,sizeof(p))){
		if( (p.getDNI()==dni) && (strcmp(p.getcontrasena(),contrasena)==0)){
			fp1.close();
			return true;
		}
	}
	fp1.close();
	return false;
}

bool profesor::loginCoordinador(int dniprofesor){
	profesor p;
	ifstream fp1;
	int contador=0;
	fp1.open("credenciales.bin", ios::binary);
	while(fp1.read((char*)&p,sizeof(p))){
		if((p.getDNI()==dni) && (p.getrol()==1)){
			fp1.close();
			return true;
		}
	}
	fp1.close();
	return false;
}

