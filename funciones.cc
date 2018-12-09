#include "alumno.h"


void insertar(){
	alumno a;
	ofstream fp2;
	fp2.open("ficheroDatos.bin", ios::binary|ios::app);
	a.crearAlumno();
	fp2.write((char *)&a, sizeof(a));
	fp2.close();
}


int buscarDNI(int dni){
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


int buscarNombre(char nombre[30]){
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
		cout<<"Alumno se repite introduzca su dni: \n";
		cin>>dni;
		buscarDNI(dni);
	}
	if(contador==0){
		cout<<"alumno no existe\n";
	}
	fp1.close();
}

int buscarApellido1(char apellido1[30]){
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
		cout<<"Alumno se repite introduzca su dni: \n";
		cin>>dni;
		buscarDNI(dni);
	}
	if(contador==0){
		cout<<"alumno no existe\n";
	}
	fp1.close();
}

void borrarporDNI(int dni){
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
		cout<<"alumno no existe, nada que borrar\n";
	}
	fp1.close();
	fp2.close();
	remove("alumno.bin");
	rename("auxiliar.bin","alumno.bin");
}


int borrarporApellido1(char apellido1[30]){
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
		cout<<"alumno no existe, nada que borrar\n";
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


void mostrarGrupo(int grupo){
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


void mostrarLider(){
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
		cout<<"no hay ningun lider registrado \n";
	}
	fp1.close();
}

void cargarFicheroBin(){
	alumno a;
	int contador=0;
	ifstream fp1;
	fp1.open("ficheroDatos.bin",ios::binary);
	ofstream fp2;
	fp2.open("auxiliar.bin", ios::out|ios::binary);
	while(fp1.read((char*)&a,sizeof(a))){
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



