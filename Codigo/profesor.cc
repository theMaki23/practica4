#include "profesor.h"
#include "alumno.h"
#include "basedatos.h"



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

