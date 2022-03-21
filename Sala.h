#include"FuncionCine.h"
#include <sstream>
using namespace std;


struct Sala{
	//Nombre unico de la sala
	string nombre;
	//Cantidade sillas en la sala
	int cantSillas;
	//Arreglo de sillas en la sala 
	Silla* sillas; 
	//Cantidad de funciones en la sala
	int cantFunciones;
	//Arreglo de funciones en la sala
	FuncionCine* funciones; 
	
	//Constructor de la estructura Sala
	Sala(){
		cantSillas = 0;
		cantFunciones = 0;
		sillas = new Silla[cantSillas];
		funciones = new FuncionCine[cantFunciones];
	}
	
	//Metodo para agregar una silla a la sala
	void agregarSilla(string categoria){
		//Se hace el objeto silla con disponibilidad
		Silla sillaNueva;
		sillaNueva.id = int_to_string(cantSillas+1); //Acá es para emepzar el id desde 1
		sillaNueva.categoria = categoria;
		sillaNueva.disponible = true;
		
		//Ahora se agrega el objeto al arreglo de sillas
		//Se hace un arreglo temporal con un espacio más para agregar la silla
		Silla* temp = new Silla[cantSillas+1];
		//Se pasan las sillas anteriores al nuevo arreglo temporal
		for(int i=0; i<cantSillas;i++){
			temp[i] = sillas[i];
		}
		//Se aumenta la variable que cuenta la cantidad de sillas
		cantSillas++;
		//Se elimina el espacio en memoria ocupado por el arreglo de sillas
		delete[] sillas;
		sillas = NULL;
		//Se hace que apunte al nuevo espacio creado por medio del arreglo temporal
		sillas = temp;
		//Se agrega al final el nuevo elemento, es decir la silla nueva
		sillas[cantSillas-1] = sillaNueva;
	}
	
	string listarFunciones(){
		string lista = "";
		for(int i=0; i<cantFunciones;i++){
			lista += funciones[i].mostrarInfo() + "\n";
		}
		return lista;
	}
	
	
	
	string listarFuncionesConSillas(){
		string lista = "";
		for(int i=0; i<cantFunciones;i++){
			lista += funciones[i].mostrarInfo() + "\n";
			lista += "\t\t\tSillas Generales disponibles: " + funciones[i].sillasGDisponibles() + "\n";
			lista += "\t\t\tSillas Preferenciales disponibles: " + funciones[i].sillasPDisponibles() + "\n";
			lista += "\t\t\t******************************************************** \n";
		}
		return lista;
	}
	
	void agregarFuncion(string peli, string dia, string hora, int idFuncion){
		//Se hace el objeto FuncionCine
		FuncionCine funcionNueva;
		funcionNueva.id = int_to_string(idFuncion);
		funcionNueva.peli = peli;
		funcionNueva.dia = dia;
		funcionNueva.hora = hora;
		funcionNueva.sala = nombre;
		
		//Se copia las sillas del cine para pasarla a la función
		Silla* tempS = new Silla[cantSillas];
		
		for(int i=0; i<cantSillas;i++){
			tempS[i] = sillas[i];
		}
		//*tempS = *sillas;
		//Se pasa la copia de sillas a la función nueva
		funcionNueva.setSillas(tempS, cantSillas);
		

		
		//Ahora se agrega el objeto al arreglo de funciones
		//Se hace un arreglo temporal con un espacio más para agregar la silla
		FuncionCine* tempF = new FuncionCine[cantFunciones+1];
		//Se pasan las funciones anteriores al nuevo arreglo temporal
		for(int i=0; i<cantFunciones;i++){
			tempF[i] = funciones[i];
		}
		//Se aumenta la variable que cuenta la cantidad de funciones
		cantFunciones++;
		//Se elimina el espacio en memoria ocupado por el arreglo de funciones
		delete[] funciones;
		funciones = NULL;
		//Se hace que apunte al nuevo espacio creado por medio del arreglo temporal
		funciones = tempF;
		//Se agrega al final el nuevo elemento, es decir la silla nueva
		funciones[cantFunciones-1] = funcionNueva;
		
		
		
	}
	
	bool funcionNuevaDisponible(string dia, string hora){
		
		for(int i=0; i<cantFunciones;i++){
			if((funciones[i].dia == dia && funciones[i].hora == hora)){
				return false;
			}
		}
		return true;
	}
	
	void listarSillasDisponibles(string idFuncion){
		
	}
	
};


