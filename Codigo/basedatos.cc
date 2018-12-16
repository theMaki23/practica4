#include "basedatos.h"
#include "alumno.h"
#include "profesor.h"
#include "funciones.h"
#include "validacion.h"

void basedatos::insertar(){
	alumno a;
	int dni;
	int grupo;
	int lider;
	ofstream fp2;
	ifstream fp1;
	fp2.open("alumno.bin", ios::binary|ios::app);
	fp1.open("alumno.bin",ios::binary);
	if(contadorAlumnos()<150){
	a.crearAlumno();
	grupo=a.getgrupo();
	dni=a.getdni();
	if(comprobarDNI(dni)==1){
			if(comprobarLider(grupo)==1){
				fp2.write((char *)&a, sizeof(a));
				fp2.close();
			}
	}
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
	cout<<"Alumno no existe\n";
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
		cout<<"\nAlumno se repite, introduzca su dni: \n";
		cin>>dni;
		buscarDNI(dni);
	}
	if(contador==0){
		cout<<"\nAlumno no existe\n";
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
		cout<<"\nAlumno no existe\n";
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
		cout<<"\nAlumno no existe, nada que borrar\n";
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
		cout<<"\nAlumno no existe, nada que borrar\n";
	}
	if(contador>1){
		cout<<"El alumno que desea borrar se repite, introduzca su dni: \n";
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
		cout<<"Grupo no existe \n";
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
		cout<<"\nNo hay ningun lider registrado \n";
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
		cout<<"Fichero vacio\n";
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
		cout<<"\nCopia de seguridad vacia\n";
	}
	fp1.close();
	fp2.close();
	remove("alumno.bin");
	rename("auxiliar.bin","alumno.bin");
}

void basedatos::ModificarporDNI(int dni){
	fstream fp;
	int grupo;
	alumno a;
	int contador=0;
	int x;
	fp.open("alumno.bin",ios::in|ios::out);
	while(fp.read((char*)&a, sizeof(a))&& contador==0){
		if(a.getdni()==dni){
			a.mostrardata();
			cout<<"\nIntroduce los nuevos datos del alumno: \n";
			a.crearAlumno();
			grupo=a.getgrupo();
			contador++;
			if(comprobarLider(grupo)==1){
			fp.seekp((-1*sizeof(a)),ios::cur);
			fp.write((char*)&a, sizeof(a));
			}
		}
	}

	if(contador==0){
		cout<<"\nAlumno no existe\n";
	}
	fp.close();
}

int basedatos::modificarporApellido1(char apellido1[30]){
	fstream fp;
	int grupo;
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
			grupo=a.getgrupo();
			if(comprobarLider(grupo)==1){
			fp.seekp((-1*sizeof(a)),ios::cur);
			fp.write((char*)&a, sizeof(a));
			}
		}
	}

	}
	if(contador==0){
		cout<<"\nAlumno no existe\n";
	}
	fp.close();
	return 1;
}

	//MOSTRARALUMNOS

void cambiaFormato(){	 //cambia alumno.bin a basedatos.txt
	ofstream fp1;
	ifstream fp2;
	fp1.open("basedatos.txt",ios::out);
	alumno a;
	int contador=0;
	fp2.open("alumno.bin",ios::in|ios::out);
	while(fp2.read((char*)&a, sizeof(a))){
		contador++;
		fp1<<a.getdni() <<","<<a.getnombre()<<","<<a.getapellido1()<<","<<a.getapellido2()<<","<<a.gettelefono()<<","<<a.getemail()<<","<<a.getpostal()<<","<<a.getcurso()<<","<<a.getgrupo()<<","<<a.getlider()<<"\n";
	}
	if(contador==0){
		cout<<"base de datos vacia";
	}
	fp1.close();
	fp2.close();
}

void basedatos::leeAlumnos(){		//pasa los alumnos de basedatos.txt a la lista alumnos_
	alumnos_.clear();

	alumno a;
	int dni, telefono, postal, curso, grupo, lider;
	char nombre[30], apellido1[30], apellido2[30], email[20];

	cambiaFormato();

	char linea_leida[50];
    ifstream fichero("basedatos.txt");

    //atoi para convertir char en int 
	while(fichero.getline(linea_leida, 256, ',')){
		a.setdni(atoi(linea_leida));

		fichero.getline(linea_leida, 256, ',');
		a.setnombre(linea_leida);

		fichero.getline(linea_leida, 256, ',');
		a.setapellido1(linea_leida);

		fichero.getline(linea_leida, 256, ',');
		a.setapellido2(linea_leida);

		fichero.getline(linea_leida, 256, ',');
		a.settelefono(atoi(linea_leida));

		fichero.getline(linea_leida, 256, ',');
		a.setemail(linea_leida);

		fichero.getline(linea_leida, 256, ',');
		a.setpostal(atoi(linea_leida));

		fichero.getline(linea_leida, 256, ',');
		a.setcurso(atoi(linea_leida));

		fichero.getline(linea_leida, 256, ',');
		a.setgrupo(atoi(linea_leida));

		fichero.getline(linea_leida, 256, '\n');
		a.setlider(atoi(linea_leida));

		alumnos_.push_back(a); //insertamos el jugador en la lista
	}
		
	fichero.close();
}

void basedatos::muestra(list<alumno>& L){	//muestra la lista de alumnos (ordenarla antes con .sort() --- Basada en alumno.h Javi, cambiar funiciones si utilizamos otro alumno.h)
	list<alumno>::iterator it=L.begin();
	cout<<"LISTA ALUMNOS\n"<<endl;

	//de cada alumno se mostrara DNI -- Nombrecompleto -- Curso -- email -- equipo -- lider -- telefono -- direccion
	for(int k=0; it!=L.end(); it++, k++){
		cout<<it->getdni()<<" "<<it->getapellido1()<<" "<<it->getapellido2()<<" "<<it->getnombre()<<" "<<it->getcurso()<<" "<<it->getemail()<<" "<<it->getgrupo()<<" "<<it->getlider()<<" "<<it->gettelefono()<<" "<<it->getpostal()<<endl;
	}
}

bool AscendenteNombre(alumno& A, alumno& B){	// A-B-C-...-Z
	return A.getApellidosNombre() < B.getApellidosNombre();
}

bool DescendenteNombre(alumno& A, alumno& B){	// Z-Y-X-...-A
	return A.getApellidosNombre() > B.getApellidosNombre();
}

bool AscendenteDNI(alumno& A, alumno& B){	//0-1-2-...
	return A.getdni() < B.getdni();
}

bool DescendenteDNI(alumno& A, alumno& B){ 	//999...-...-0
	return A.getdni() > B.getdni();
}

bool AscendenteCurso(alumno& A, alumno& B){	//0-1-2-...
	return A.getcurso() < B.getcurso();
}

bool DescendenteCurso(alumno& A, alumno& B){ 	//999...-...-0
	return A.getcurso() > B.getcurso();
}


void basedatos::mostrarAlumnos(){
	int dato, orden;
	cambiaFormato();	//pasamos alumnos.bin a basedatos.txt, para mas tarde obtener datos de basedatos.txt
	leeAlumnos(); //pasamos basedatos.txt a la lista alumnos_

	cout<<"Elige el dato por el cual quieres que se muestren los alumnos ordenadamente:   (1, 2 o 3)"<<endl;
	cout<<"1.- Apellidos y nombre"<<endl;
	cout<<"2.- DNI"<<endl;
	cout<<"3.- Curso mas alto por el que esté matriculado"<<endl;
	cin>>dato;

	cout<<"\nElige el orden en el que se muestran:   (1 o 2)"<<endl;
	cout<<"1.- Ascendente"<<endl;
	cout<<"2.- Descendente"<<endl;
	cin>>orden;

	if((dato==1 || dato==2 || dato==3) && (orden==1 || orden==2)){
		switch(dato){
			//Apellidos y nombre
			case 1:{
				if(orden==1){	//Ascendente
					cout<<"\nApellidos nombre ascendente\n\n";
					alumnos_.sort(AscendenteNombre);	//.sort() ordena la lista
					muestra(alumnos_);	//muestra la lista segun este ordenada, en este caso ya estará ordenada segun le impuse antes
				}else{		// Descendente
					cout<<"\nApellidos nombre descendente\n\n";
					alumnos_.sort(DescendenteNombre);
					muestra(alumnos_);
				}
			}break;

			//DNI
			case 2:{
				if(orden==1){	//Ascendente
					cout<<"\nDNI ascendente\n\n";
					alumnos_.sort(AscendenteDNI);
					muestra(alumnos_);
				}else{	//Descendente
					cout<<"\nDNI descendente\n\n";
					alumnos_.sort(DescendenteDNI);
					muestra(alumnos_);
				}
			}break;

			//Curso
			case 3:{
				if(orden==1){	//Ascendente
					cout<<"\nCurso ascendente\n\n";
					alumnos_.sort(AscendenteCurso);
					muestra(alumnos_);
				}else{	//Descendente
					cout<<"\nCurso descendente\n\n";
					alumnos_.sort(DescendenteCurso);
					muestra(alumnos_);
				}
			}break;
		}//END switch

	}else{
		cout<<"ERROR. Debe elegir un dato con un numero del 1 al 3 y un orden con 1 o 2."<<endl;
	}
}