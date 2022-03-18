#include"Silla.h"
#include"Horario.h"
using namespace std;

struct Sala{
	//Nombre unico de la sala
	string nombre;
	//Cantidade sillas en la sala
	int cantSillas;
	//Arreglo de sillas en la sala 
	Silla* sillas; 
	//Cantidad de horarios en la sala
	int cantHorarios;
	//Arreglo de horarios en la sala
	Horario* horarios; 
	
	//Constructor de la estructura Sala
	Sala(){
		cantSillas = 0;
		cantHorarios = 0;
		sillas = new Silla[cantSillas];
		horarios = new Horario[cantHorarios];
	}
	
	//Metodo para agregar una silla a la sala
	void agregarSilla(string categoria){
		//Se hace el objeto silla con disponibilidad
		Silla sillaNueva;
		sillaNueva.id = cantSillas+1; //Acá es para emepzar el id desde 1
		sillaNueva.cagetoria = categoria;
		sillaNueva.disponible = false;
		
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
	
};


