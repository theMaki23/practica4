#ifndef PROFESOR_H
#define PROFESOR_H
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;


class Profesor{
 private:
 	string nombre, apellido, contrasena;
 	int rol, dni;

 public:
 	Profesor(){};
 	void iniciar_sesion();
 	


};

#endif