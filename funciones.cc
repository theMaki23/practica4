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

void cargarCopiaSeguridad(){
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
		cout<<"copia de seguridad vacia\n";
	}
	fp1.close();
	fp2.close();
	remove("alumno.bin");
	rename("auxiliar.bin","alumno.bin");
}


void ModificarporDNI(int dni){
	fstream fp;
	alumno a;
	int contador=0;
	int x;
	fp.open("alumno.bin",ios::in|ios::out);
	while(fp.read((char*)&a, sizeof(a))&& contador==0){
		if(a.getdni()==dni){
			a.mostrardata();
			cout<<"\n Introduce los nuevos datos del alumno: \n";
			a.crearAlumno();
			fp.seekp((-1*sizeof(a)),ios::cur);
			fp.write((char*)&a, sizeof(a));
			contador++;
		}
	}
	if(contador==0){
		cout<<"Alumno no existe\n";
	}
	fp.close();
}


int modificarporApellido1(char apellido1[30]){
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
		cout<<"Alumno se repite, introduzca su dni: \n";
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
			cout<<"\n Introduce los nuevos datos del alumno: \n";
			a.crearAlumno();
			fp.seekp((-1*sizeof(a)),ios::cur);
			fp.write((char*)&a, sizeof(a));
		}
	}

	}
	if(contador==0){
		cout<<"Alumno no existe\n";
	}
	fp.close();
	return 1;
}


void generarFichero(){
	ofstream fp1;
	ifstream fp2;
	fp1.open("basedatos.md",ios::app);
	alumno a;
	int contador=0;
	fp2.open("alumno.bin",ios::in|ios::out);
	while(fp2.read((char*)&a, sizeof(a))){
		contador++;
		fp1<<a.getdni() <<" "<<a.getnombre()<<" "<<a.getapellido1()<<" "<<a.getapellido2()<<" "<<a.gettelefono()<<" "<<a.getemail()<<" "<<a.getpostal()<<" "<<a.getcurso()<<" "<<a.getgrupo()<<" "<<a.getlider()<<"\n";
	}
	if(contador==0){
		cout<<"base de datos vacia";
	}
	fp1.close();
	fp2.close();
}






