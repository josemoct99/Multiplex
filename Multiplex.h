#include"Sala.h"
#include"Pelicula.h"
#include"Tiquete.h"
#include <vector>
using namespace std;

struct Multiplex{
	
	//Nombre del Multiplex
	string nombre;
	//Cantidad de salas en el multiplex
	int cantSalas;
	//Arreglo de Salas (inicialmente tiene 0)
	Sala* salas;
	//Cantidad de peliculas en el multiplex
	int cantPelis;
	//Arreglo de Peliculas (inicialmente tiene 0)
	Pelicula* peliculas;
	//Cantidad de tiquetes en el multiplex
	int cantTiquetes;
	//Arreglo de tiquetes (inicialmente tiene 0)
	Tiquete* tiquetes;
	//Costo de los tiquetes preferenciales
	int costoPreferencial;
	//Costo de los tiquetes generales
	int costoGeneral;
	//ID para las funciones en general
	int idFuncion;
	
	//Constructor de Multiplex (Se llama una sola vez, al momento de hacer un objeto de esta estructura)
	Multiplex(){
		cantSalas = 0;
		cantPelis = 0;
		cantTiquetes = 0;
		costoPreferencial = 12000;
		costoGeneral = 8000;
		salas = new Sala[cantSalas];
		peliculas = new Pelicula[cantPelis];
		tiquetes = new Tiquete[cantTiquetes];
	}
	
	//Obtener una sala de cine
	Sala & getSala(int numSala){
		for(int i=0; i<cantSalas; i++){
			if ((i+1) == numSala){
				return salas[i];
			}
		}
	}
	
	

	//Comprobar que la sala a�adida no exista
	bool comprobarNombreSala(string nombre){
		for(int i=0; i<cantSalas ; i++){
			if(salas[i].nombre == nombre){
				return false;
			}
		}
		return true;
	}
	
	
	//------------------------------------------------------
	string sugerencias(Pelicula peli);

	void agregarSala(string nombre, int numSillas, int numGenerales){
		//Se comienza construyendo un objeto Sala
		Sala salaNueva;
		salaNueva.nombre = nombre;
		
		
		//Ahora se agregan sillas por medio de la estructura Sala
		agregarSillas(salaNueva, numSillas, numGenerales);
		
		//Se agrega una sala al arreglo de salas en el multiplex
		//Se hace un arreglo temporal con un espacio m�s para agregar la sala
		Sala* temp = new Sala[cantSalas+1];
		//Se pasan las salas anteriores al nuevo arreglo temporal
		for(int i=0; i<cantSalas;i++){
			temp[i] = salas[i];
		}
		//Se aumenta la variable que cuenta la cantidad de salas
		cantSalas++;
		//Se elimina el espacio en memoria ocupado por el arreglo de salas
		delete[] salas;
		salas = NULL;
		//Se hace que apunte al nuevo espacio creado por medio del arreglo temporal
		salas = temp;
		//Se agrega al final el nuevo elemento, es decir la sala nueva
		salas[cantSalas-1] = salaNueva;
	}
	
	void eliminarSala(int numSala){
		int cont = 0;
		Sala* temp = new Sala[cantSalas-1];
		
		for(int i=0; i<cantSalas;i++){
			
			if((i+1) != numSala){
				temp[cont] = salas[i];
				cont++;
			}
		}
		
		cantSalas --;
		delete[] salas;
		salas = NULL;
		
		salas = temp;
	}
	
	
	void generarTiquete(Sala scine, Pelicula peli, string categoria);
	string mostrarSillasDisponibles(Sala scine);
	void cambiarCostoTiquetes(string categoria, int valor);
	
	void agregarSillas(Sala &sala, int cantidad, int numGenerales){
		for(int i=0; i<cantidad;i++){ //Agrego la cantidad total de sillas pedidas
			if(i<numGenerales){
				sala.agregarSilla("General"); //Si a�n no llego a la cantidade sillas generales se van agregando de tipo general
			}else{
				sala.agregarSilla("Preferencial");	//Una vez se pase ese numero se termina de agregar sillas preferenciales
			}
		}
	}
	
	void agregarPelicula(string peli, Sala &sala, string fecha, string hora){
		idFuncion++;
		
		Pelicula peliTemp;
		peliTemp.nombre = peli;
		
		//Se agrega una pelicula al arreglo de salas en el multiplex
		//Se hace un arreglo temporal con un espacio m�s para agregar la pelicula
		Pelicula* temp = new Pelicula[cantPelis+1];
		//Se pasan las salas anteriores al nuevo arreglo temporal
		for(int i=0; i<cantPelis;i++){
			temp[i] = peliculas[i];
		}
		//Se aumenta la variable que cuenta la cantidad de peliculas
		cantPelis++;
		//Se elimina el espacio en memoria ocupado por el arreglo de peliculas
		delete[] peliculas;
		peliculas = NULL;
		//Se hace que apunte al nuevo espacio creado por medio del arreglo temporal
		peliculas = temp;
		//Se agrega al final el nuevo elemento, es decir la pelicula nueva
		peliculas[cantPelis-1] = peliTemp;
		
		//Se agrega finalmente la funci�n nueva
		sala.agregarFuncion(peli, fecha, hora, idFuncion);

	}
	
	//------------------------------------------------------
	void listarSalas(){
		for(int i=0; i<cantSalas;i++){
			cout << "\t\t\t"<<(i+1) <<". Sala '" <<salas[i].nombre << "' "; 
			cout << "con una cantidad de " << salas[i].cantSillas << " sillas" << endl;
		}
	}
	
	void listarPeliculas(){
		for(int i=0; i<cantPelis;i++){
			cout << "\t\t\t"<<(i+1) <<". Pelicula: '" <<peliculas[i].nombre << endl; 
			cout << "\t\t\tFunciones disponibles: " << endl;
			
			for(int j=0; j < cantSalas ; j++){
				for(int k=0; k < salas[j].cantFunciones ; k++){
					if(salas[j].funciones[k].peli == peliculas[i].nombre){
						cout << "\t\t\t" << salas[j].funciones[k].mostrarInfo();
						cout << "\t\t\tSillas Generales disponibles: "<< salas[j].funciones[k].sillasGDisponibles() <<  endl;
						cout << "\t\t\tSillas Preferenciales disponibles: "<< salas[j].funciones[k].sillasPDisponibles() <<  endl;
					}
				}
			}
			cout << "\t\t\t************************************************" << endl;
		}
	}
	
		
};








