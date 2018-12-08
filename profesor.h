#ifndef PROGRAMA_H_
#define PROGRAMA_H_
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


class Profesor{
 private:
 	string nombre_, apellido_;
 	int rol_, DNI_;

 public:
 	Profesor();
 	void iniciar_sesion();


};