#include"Silla.h"
#include"Tiquete.h"
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

	//ID para las funciones en general
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
	//Cantidad de tiquetes en la funcion
	int cantTiquetes;
	//Arreglo de tiquetes (inicialmente tiene 0)
	Tiquete* tiquetes;
	//Cantidad de tiquetes general
	static int idTiquetes;
	
	
	FuncionCine(){
		cantTiquetes = 0;
		tiquetes = new Tiquete[cantTiquetes];
	}
	
	//Poner cantidad de sillas
	void setSillas(Silla* sillasN, int cantSillasN){
		sillas = sillasN;
		cantSillas = cantSillasN;
	}
	
	//Devuelve un string con toda la información de la función
	string mostrarInfo(){
		return "\t\t\tID de la función: " + id + "\n\t\t\tPelícula: " + peli + "\n\t\t\tSala: " + sala + "\n\t\t\tFecha y Hora: " + dia + " - " + hora + "\n";
	}
	
	void generarTiquete(string idSilla, string categoria, string costo){
		FuncionCine::idTiquetes++;
		Tiquete tiqueteNuevo;
		tiqueteNuevo.id = int_to_string(idTiquetes);
		tiqueteNuevo.datosFuncion = mostrarInfo();
		tiqueteNuevo.costo = costo;
		tiqueteNuevo.categoriaSilla = categoria;
		tiqueteNuevo.silla = idSilla;
		
		//Ahora se agrega el objeto al arreglo de tiquetes
		//Se hace un arreglo temporal con un espacio más para agregar la tiquete
		Tiquete* temp = new Tiquete[cantTiquetes+1];
		//Se pasan las tiquetes anteriores al nuevo arreglo temporal
		for(int i=0; i<cantTiquetes;i++){
			cout << "T" << i << endl;
			temp[i] = tiquetes[i];
		}
		//Se aumenta la variable que cuenta la cantidad de tiquetes
		FuncionCine::cantTiquetes++;
		//Se elimina el espacio en memoria ocupado por el arreglo de tiquetes
		delete[] tiquetes;
		tiquetes = NULL;
		//Se hace que apunte al nuevo espacio creado por medio del arreglo temporal
		tiquetes = temp;
		//Se agrega al final el nuevo elemento, es decir la tiquete nueva
		tiquetes[cantTiquetes-1] = tiqueteNuevo;
		
		tiqueteNuevo.realizarTiquete();
	}
	
	//ComprarSillas
	bool comprarSilla(string id){
		for(int i=0; i<cantSillas;i++){
			if(sillas[i].id == id && sillas[i].disponible){
				sillas[i].generarCosto();
				sillas[i].disponible = false;
				generarTiquete(sillas[i].id, sillas[i].categoria, int_to_string(sillas[i].costo));
				return true;
			}
		}
		return false;
	}
	
	//----------------------------------------------------------------------
	
	string sillasGDisponibles(){
		string texto;
		int contador = 0;
		for(int i=0; i<cantSillas;i++){
			if(sillas[i].disponible && sillas[i].categoria == "General"){
				contador++;
			}
		}
		texto = int_to_string(contador);
		texto += " sillas disponibles";
		return texto;
	}
	
	string sillasPDisponibles(){
		string texto;
		int contador = 0;
		for(int i=0; i<cantSillas;i++){
			if(sillas[i].disponible && sillas[i].categoria == "Preferencial"){
				contador++;
			}
		}
		texto = int_to_string(contador);
		texto += " sillas disponibles";
		return texto;
	}
	
	
	//----------------------------------------------------------
	void mostrarSillasGDisponibles(){
		cout << "\t\t\t- ";
		for(int i=0; i<cantSillas;i++){
			if(sillas[i].disponible && sillas[i].categoria == "General"){
				cout << sillas[i].id << " - ";
			}
		}
	}
	
	void mostrarsillasPDisponibles(){
		cout << "\t\t\t- ";
		for(int i=0; i<cantSillas;i++){
			if(sillas[i].disponible && sillas[i].categoria == "Preferencial"){
				cout << sillas[i].id << " - ";
			}
		}
	}
};

int FuncionCine::idTiquetes = 0;

