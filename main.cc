#include "alumno.h"

int main()
{
/*
insertar();
insertar();
*/
insertar();
int dni;
char apellido1[30];
char nombre[30];
int grupo;
/*
cout<<"Introduce el nombre del alumno que desea buscar: ";
cin>>nombre;
buscarNombre(nombre);
cout<<"Introduce el dni del alumno que desea buscar: ";
cin>>dni;
buscarDNI(dni);

cout<<"Introduce el apellido del alumno que desea buscar: \n";
cin>>apellido1;
buscarApellido1(apellido1);

cout<<"Introduce el apellido del alumno que desea borrar: \n";
cin>>apellido1;
borrarporApellido1(apellido1);

cout<<"Introduce el dni del alumno que desea borrar: \n";
cin>>dni;
borrarporDNI(dni);
*/
cout<<"Introduce el grupo del que desea ver sus integrantes: \n";
cin>>grupo;
mostrarGrupo(grupo);
mostrarLider();
return 0;
}