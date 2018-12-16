#include "funciones.h"
#include "basedatos.h"
#include "alumno.h"
#include "profesor.h"
#include "validacion.h"


int contadorAlumnos(){
	alumno a;
	ifstream fp1;
	int contador=0;
	fp1.open("alumno.bin",ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
			contador++;
	}
	fp1.close();
	return contador;
}


int comprobarLider(int grupo){
    alumno a;
    ifstream fp1;
    fp1.open("alumno.bin",ios::binary);
    while(fp1.read((char*)&a,sizeof(a))){
        if((a.getgrupo()==grupo)&&(a.getlider()==1)){
            cout<<"Este alumno no puede ser lider, ya hay previamente otro registrado para el mismo grupo, modificalo.\n";
            fp1.close();
            return 0;
        }
    }
    fp1.close();
    return 1;
}


int comprobarDNI(int dni){
    alumno a;
    ifstream fp1;
    fp1.open("alumno.bin",ios::binary);
    while(fp1.read((char*)&a,sizeof(a))){
        if(a.getdni()==dni){
            cout<<"Este alumno ya existe, modificalo.\n";
            fp1.close();
            return 0;
        }
    }
    
    fp1.close();
    return 1;
}































int menu(int opc, int dniprofesor)  
{
    cin>>opc;
    basedatos b;
    profesor p;
    int respuesta;
    int dni;
    char apellido1[30];
    char nombre[30];
    int grupo;
{
    do
    {
        switch (opc){

            case 0:
            exit (-1);
            break;

            case 1:

            b.insertar();      
               break;

            case 2:

            cout<<"\nSi desea buscar por DNI pulse 1, si lo desea buscar por nombre pulse 2 y si desea por el apellido pulse 3: \n";
            cin>>respuesta;
            if(respuesta==1){
                cout<<"Introduzca el dni del alumno que desea buscar: \n";
                cout<<"DNI: ";
                cin>>dni;
                b.buscarDNI(dni);
            }
            if(respuesta==2){
                cout<<"Introduzca el nombre del alumno que desea buscar: \n";
                cout<<"\nNombre: ";
                cin>>nombre;
                b.buscarNombre(nombre);
            }
            if(respuesta==3){
                cout<<"Introduzca el apellido del alumno que desea buscar: \n";
                cout<<"\nApellido: ";
                cin>>apellido1;
                b.buscarApellido1(apellido1);
            }
            break;

            case 3:{
            	b.mostrarAlumnos();
            }break;

            case 4:

            cout<<"\nSi desea borrar por DNI pulse 1 y si desea por el apellido pulse 2: \n";
            cin>>respuesta;
            if(respuesta==1){
                cout<<"Introduzca el dni del alumno que desea borrar: \n";
                cout<<"DNI: ";
                cin>>dni;
                b.borrarporDNI(dni);
            }

            if(respuesta==2){
                cout<<"Introduzca el apellido del alumno que desea borrar: \n";
                cout<<"\nApellido: ";
                cin>>apellido1;
                b.borrarporApellido1(apellido1);
            }     
             break;

            case 5:

            cout<<"\nSi desea modificar por DNI pulse 1 y si desea por el apellido pulse 2: \n";
            cin>>respuesta;
            if(respuesta==1){
                cout<<"Introduzca el dni del alumno que desea modificar: \n";
                cout<<"DNI: ";
                cin>>dni;
                b.ModificarporDNI(dni);
            }

            if(respuesta==2){
                cout<<"Introduzca el apellido del alumno que desea modificar: \n";
                cout<<"\nApellido: ";
                cin>>apellido1;
                b.modificarporApellido1(apellido1);
            }     
             break;

            case 6:

                cout<<"\nIntroduce el grupo del que desea ver sus integrantes: \n";
                cin>>grupo;
                b.mostrarGrupo(grupo);
                break;

            case 7:
                b.mostrarLider();
                break;

            case 8:
                cout<<"El fichero que desea cargar debe de estar en .bin y llamarse 'FicheroDatos'";
                b.cargarFicheroBin();
                break;
            case 9:
                cout<<"La copia de seguridad que desea cargar debe de estar en .bin y llamarse 'CopiaSeguridad'";
                b.cargarCopiaSeguridad();
                break;

            case 10:
                p.generarFicheroBin();
                break;

            case 11: {
                if(p.loginCoordinador(dniprofesor)==true){
                p.generarCopiaSeguridad();
                }
                else{
                    cout<<"No tienes permisos para ejecutar esta operacion\n";
                    
                }
            }
                break;


        }
    } while (opc <= 0 || opc > 11);} 
}








































