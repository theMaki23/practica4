#include "alumno.h"
#include "basedatos.h"
#include "profesor.h"
#include "funciones.h"
#include "validacion.h"

int main()
{
profesor p;

int dniprofesor;
char contrasenaprofesor[30];
int opc=0;

cout<<"Bienvenido, introduzca su dni y contrasena para empezar: \n";
cout<<"DNI: ";
cin>>dniprofesor;
cout<<"Contrasena: ";
cin>>contrasenaprofesor;
cout<<"\n";


if(p.loginProfesor(dniprofesor, contrasenaprofesor)==true){
int i;
cout<<"\nBIENVENIDO";
for(i=0;i<999999999;i++){
cout << "\nElija una opcion:\n " << endl;
cout << "0.Salir del programa\n"<<"1.Insertar un alumno\n"<<"2.Buscar un alumno\n"<<"3.Mostrar alumnos de forma ordenada\n"<<"4.Borrar alumno\n"<<"5.Modificar alumno\n"<<"6.Mostrar un grupo\n"<<"7.Mostrar lideres\n"<<"8.Cargar un fichero\n"<<"9.Cargar una copia de seguridad\n"<<"10.Generar un fichero de datos\n"<<"11.Generar una copia de seguridad\n\n";
menu(opc, dniprofesor);
}

return 0;
}
else{
	cout<<"Usuario no autorizado por el sistema\n";
}
}




