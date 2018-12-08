#include "alumno.h"


void insertar(){
	alumno a;
	ofstream fp2;
	fp2.open("alumno.bin", ios::binary|ios::app);
	a.crearAlumno();
	fp2.write((char *)&a, sizeof(a));
	fp2.close();
}