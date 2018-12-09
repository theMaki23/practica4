#include "alumno.h"

int main()
{


char apellido[30];


cout<<"Introduce el apellido del alumno que desea modificar: \n";
cin>>apellido;
buscarApellido1(apellido);
modificarporApellido1(apellido);
buscarApellido1(apellido);
return 0;
}