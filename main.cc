#include "alumno.h"

 int main()
{
	/*
insertar();
insertar();
insertar();
*/
int dni;
char apellido1[30];
char nombre[30];
cout<<"Introduce el nombre del alumno que desea buscar: ";
cin>>nombre;
buscarNombre(nombre);
cout<<"Introduce el dni del alumno que desea buscar: ";
cin>>dni;
buscarDNI(dni);
cout<<"Introduce el apellido del alumno que desea buscar: ";
cin>>apellido1;
buscarApellido1(apellido1);
return 0;
}