#include "basedatos.h"
#include "alumno.h"
#include "profesor.h"
#include "funciones.h"

void basedatos::insertar(){
	alumno a;
	ofstream fp2;
	fp2.open("alumno.bin", ios::binary|ios::app);
	if(contadorAlumnos()<150){
	a.crearAlumno();
	fp2.write((char *)&a, sizeof(a));
	fp2.close();
	}
	else{
		cout<<"Base de datos llena, borre algun alumno";
	}
}


int basedatos::buscarDNI(int dni){
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
	cout<<"alumno no existe\n";
	fp1.close();
	return 0;
}


int basedatos::buscarNombre(char nombre[30]){
	alumno a;
	ifstream fp1;
	int contador=0;
	fp1.open("alumno.bin",ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
		if(strcmp(a.getnombre(),nombre)==0){
			contador++;
			a.mostrardata();
		}
	}
	if(contador>1){
		int dni;
		cout<<"\nAlumno se repite introduzca su dni: \n";
		cin>>dni;
		buscarDNI(dni);
	}
	if(contador==0){
		cout<<"\nalumno no existe\n";
	}
	fp1.close();
}


int basedatos::buscarApellido1(char apellido1[30]){
	alumno a;
	ifstream fp1;
	int contador=0;
	fp1.open("alumno.bin",ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
		if(strcmp(a.getapellido1(),apellido1)==0){
			contador++;
			a.mostrardata();
		}
	}
	if(contador>1){
		int dni;
		cout<<"\nAlumno se repite introduzca su dni: \n";
		cin>>dni;
		buscarDNI(dni);
	}
	if(contador==0){
		cout<<"\nalumno no existe\n";
	}
	fp1.close();
}

void basedatos::borrarporDNI(int dni){
	alumno a;
	int contador=0;
	ifstream fp1;
	fp1.open("alumno.bin",ios::binary);
	ofstream fp2;
	fp2.open("auxiliar.bin", ios::out|ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
		if(a.getdni()!=dni){
			fp2.write((char*)&a,sizeof(a));
		}
		else{
			contador++;
		}
	}
	if(contador==0){
		cout<<"\nalumno no existe, nada que borrar\n";
	}
	fp1.close();
	fp2.close();
	remove("alumno.bin");
	rename("auxiliar.bin","alumno.bin");
}


int basedatos::borrarporApellido1(char apellido1[30]){
	alumno a;
	int contador=0;
	ifstream fp1;
	fp1.open("alumno.bin",ios::binary);
	ofstream fp2;
	fp2.open("auxiliar.bin", ios::out|ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
		if(strcmp(a.getapellido1(),apellido1)!=0){
			fp2.write((char*)&a,sizeof(a));
		}
		else{
			contador++;
		}
	}
	if(contador==0){
		cout<<"\nalumno no existe, nada que borrar\n";
	}
	if(contador>1){
		cout<<"el alumno que desea borrar se repite, introduzca su dni: \n";
		int dni;
		cin>>dni;
		borrarporDNI(dni);
		return 1;
	}
	fp1.close();
	fp2.close();
	remove("alumno.bin");
	rename("auxiliar.bin","alumno.bin");
	return 0;
}


void basedatos::mostrarGrupo(int grupo){
	alumno a;
	ifstream fp1;
	int contador=0;
	fp1.open("alumno.bin",ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
		if(a.getgrupo()==grupo){
			contador++;
			a.mostrardata();
		}
	}
	if(contador==0){
		cout<<"grupo no existe \n";
	}
	fp1.close();
}

void basedatos::mostrarLider(){
	alumno a;
	ifstream fp1;
	int contador=0;
	fp1.open("alumno.bin",ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
		if(a.getlider()==1){
			contador++;
			a.mostrardata();
		}
	}
	if(contador==0){
		cout<<"\nno hay ningun lider registrado \n";
	}
	fp1.close();
}

void basedatos::cargarFicheroBin(){
	alumno a;
	int contador=0;
	ifstream fp1;
	fp1.open("ficheroDatos.bin",ios::binary);
	ofstream fp2;
	fp2.open("auxiliar.bin", ios::out|ios::binary);
	while(fp1.read((char*)&a,sizeof(a))&&(contador<150)){
			fp2.write((char*)&a,sizeof(a));
			contador++;
	}
	if(contador==0){
		cout<<"fichero vacio\n";
	}
	fp1.close();
	fp2.close();
	remove("alumno.bin");
	rename("auxiliar.bin","alumno.bin");
}

void basedatos::cargarCopiaSeguridad(){
	alumno a;
	int contador=0;
	ifstream fp1;
	fp1.open("CopiaSeguridad.bin",ios::binary);
	ofstream fp2;
	fp2.open("auxiliar.bin", ios::out|ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
			fp2.write((char*)&a,sizeof(a));
			contador++;
	}
	if(contador==0){
		cout<<"\ncopia de seguridad vacia\n";
	}
	fp1.close();
	fp2.close();
	remove("alumno.bin");
	rename("auxiliar.bin","alumno.bin");
}

void basedatos::ModificarporDNI(int dni){
	fstream fp;
	alumno a;
	int contador=0;
	int x;
	fp.open("alumno.bin",ios::in|ios::out);
	while(fp.read((char*)&a, sizeof(a))&& contador==0){
		if(a.getdni()==dni){
			a.mostrardata();
			cout<<"\nIntroduce los nuevos datos del alumno: \n";
			a.crearAlumno();
			fp.seekp((-1*sizeof(a)),ios::cur);
			fp.write((char*)&a, sizeof(a));
			contador++;
		}
	}
	if(contador==0){
		cout<<"\nAlumno no existe\n";
	}
	fp.close();
}

int basedatos::modificarporApellido1(char apellido1[30]){
	fstream fp;
	int dni;
	alumno a;
	int contador=0;
	int x;
	fp.open("alumno.bin",ios::in|ios::out);
	while(fp.read((char*)&a, sizeof(a))){
		if(strcmp(a.getapellido1(),apellido1)==0){
			contador++;
		}
	}
	if(contador>1){
		cout<<"\nAlumno se repite, introduzca su dni: \n";
		cin>>dni;
		ModificarporDNI(dni);
		return 0;
	}
	if(contador==1){
		fp.clear();
		fp.seekp(0,ios_base::beg);
		while(fp.read((char*)&a, sizeof(a))){
		if(strcmp(a.getapellido1(),apellido1)==0){
			a.mostrardata();
			cout<<"\nIntroduce los nuevos datos del alumno: \n";
			a.crearAlumno();
			fp.seekp((-1*sizeof(a)),ios::cur);
			fp.write((char*)&a, sizeof(a));
		}
	}

	}
	if(contador==0){
		cout<<"\nAlumno no existe\n";
	}
	fp.close();
	return 1;
}