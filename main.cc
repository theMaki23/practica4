#include "alumno.h"

int main()
{


int dni;


cout<<"Introduce el dni del alumno que desea modificar: \n";
cin>>dni;
buscarDNI(dni);
ModificarporDNI(dni);
buscarDNI(dni);
return 0;
}