#include "funciones.h"
#include "basedatos.h"
#include "alumno.h"
#include "profesor.h"
#include "validacion.h"


bool validarDNI(char *dni){
	if(strlen(dni)==8){
		for(int i=0; i<8; i++){ //El 8 es porque consideramos que el DNI es solo la parte numerica 
			if(isalpha(dni[i])){
				return false;
			}
		}
		return true;
	}
return false;
}


bool validartelefono(char *telefono){
	if(strlen(telefono)==9){
		for(int i=0; i<9; i++){
			if(isalpha(telefono[i])){
				return false;
			}
		}
		return true;
	}
return false;
}



bool validarpalabra(char *cadena){
	for(int i=0; i<strlen(cadena); i++){
		if(!isalpha(cadena[i])){
			return false;
		}
	}
return true;
}


bool validarCP(char *CP){
	if(strlen(CP)==5){
		for(int i=0; i<5; i++){
			if(isalpha(CP[i])){
				return false;
			}
		}
		return true;
	}
return false;
}

bool validarcurso(char *curso){
 int i_curso;
	if(strlen(curso)==1){
		if(isalpha(curso[0])){
			return false;
		}
		i_curso = atoi(curso);
			if((i_curso<2)||(i_curso>4)){
				return false;
			}
		return true;
	}
return false;
}


bool validargrupo(char *grupo){
 int i_grupo;
	if(strlen(grupo)<4){
		for(int i=0; i<strlen(grupo); i++){
			if(isalpha(grupo[i])){
				return false;
			}
		}
		i_grupo = atoi(grupo);
			if(curso==0){
				return false;
			}
		return true;
	}
return false;
}

bool validarlider(char *lider){
 int i_lider;
	if(strlen(lider)==1){
		if(isalpha(lider[0])){
			return false;
		}
		i_lider = atoi(lider);
			if((i_lider<0)||(i_lider>1)){
				return false;
			}
		return true;
	}
return false;
}