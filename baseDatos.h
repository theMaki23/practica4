//baseDatos.h

#include <list>
#include <string>
#include "alumno.h"

class BaseDatos{
private:
	list <Alumno> alumnos_;
public:
	void MostrarAlumnos();
}