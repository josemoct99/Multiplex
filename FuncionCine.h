#include"Silla.h"

#include <sstream>
using namespace std;
//funcion para convertir int a string
string int_to_string(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}


//A continuación solo son plantillas para tomar la info para las dias y horarios disponibles

//Arreglo de días disponibles para esa semana de marzo
string dias[7] = {"21/03/2022", "22/03/2022", "23/03/2022", "24/03/2022", "25/03/2022", "26/03/2022", "27/03/2022"};
//Arretglo de horas disponibles 
string horas[5] = {"8:00 a.m", "12:00 p.m", "4:00 p.m", "7:00 p.m", "10:00 p.m"};

void mostrarDias(){
	for(int i=0; i<7; i++){
		cout << "\t\t\t[" << (i+1) << "]" << dias[i] << endl;
	}
}

void mostrarHoras(){
	for(int i=0; i<5; i++){
		cout << "\t\t\t[" << (i+1) << "]" << horas[i] << endl;
	}
}

struct FuncionCine{
	//Id de la función
	string id;
	//Nombre de Pelicula de la función
	string peli;
	//Nombre de Sala  de la función
	string sala;
	//Fecha  de la función
	string dia;
	//Hora  de la función
	string hora;
	//Cantidad de sillas para la funcion especifica
	int cantSillas;
	//Sillas para la función específica
	Silla* sillas;
	
	
	
	//Poner cantidad de sillas
	void setSillas(Silla* sillas, int cantSillas){
		this->sillas = sillas;
		this->cantSillas = cantSillas;
	}
	
	//Devuelve un string con toda la información de la función
	string mostrarInfo(){
		return "\t\t\tID de la función: " + id + "\n\t\t\tPelícula: " + peli + "\n\t\t\tSala: " + sala + "\n\t\t\tFecha y Hora: " + dia + " - " + hora + "\n";
	}
	/*
	//Se asgina un día de la semana a la variable dia
	void setFecha(int numFecha){
		for(int i=0; i<sizeof(dias);i++){
			if((i+1) == numFecha){
				dia = dias[i];
			}
		}
	}
	
	//Se le asigna una hora a la variable hora
	void setHora(int numHora){
		for(int i=0; i<sizeof(dias);i++){
			if((i+1) == numHora){
				hora = horas[i];
			}
		}
	}
	*/
	
	string sillasGDisponibles(){
		string texto;
		int contador = 0;
		for(int i=0; i<cantSillas;i++){
			if(sillas[i].disponible && sillas[i].cagetoria == "General"){
				contador++;
			}
		}
		texto = int_to_string(contador);
		texto += " sillas disponibles \n";
		return texto;
	}
	
		string sillasPDisponibles(){
		string texto;
		int contador = 0;
		for(int i=0; i<cantSillas;i++){
			if(sillas[i].disponible && sillas[i].cagetoria == "Preferencial"){
				contador++;
			}
		}
		texto = int_to_string(contador);
		texto += " sillas disponibles \n";
		return texto;
	}
	
};

