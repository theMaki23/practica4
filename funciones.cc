#include "alumno.h"


void insertar(){
	alumno a;
	ofstream fp2;
	fp2.open("alumno.bin", ios::binary|ios::app);
	a.crearAlumno();
	fp2.write((char *)&a, sizeof(a));
	fp2.close();
}


int buscarDNI(int dni){
	alumno a;
	ifstream fp1;
	fp1.open("alumno.bin",ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
		if(a.getdni()==dni){
			a.mostrardata();
			fp1.close();
			return 1;
		}
	}
	cout<<"\nalumno no existe\n";
	fp1.close();
	return 0;
}