#include "alumno.h"

int main()
{


char apellido1[30];

cargarFicheroBin();
cout<<"Introduce el apellido del alumno que desea buscar: \n";
cin>>apellido1;
buscarApellido1(apellido1);
return 0;
}