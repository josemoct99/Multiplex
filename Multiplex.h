#include"Sala.h"
#include"Pelicula.h"
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
	//Costo de los tiquetes preferenciales

	int idFuncion;
	//ID para las tiquetes en general
	int idTiquete;
	
	//Constructor de Multiplex (Se llama una sola vez, al momento de hacer un objeto de esta estructura)
	Multiplex(){
		cantSalas = 0;
		cantPelis = 0;
		costoPreferencial = 12000;
		costoGeneral = 8000;
		salas = new Sala[cantSalas];
		peliculas = new Pelicula[cantPelis];
	}
	
	//Obtener una sala de cine
	Sala & getSala(int numSala){
		for(int i=0; i<cantSalas; i++){
			if ((i+1) == numSala){
				return salas[i];
			}
		}
	}
	
	Pelicula & getPelicula(int numPeli){
		for(int i=0; i<cantPelis; i++){
			if ((i+1) == numPeli){
				return peliculas[i];
			}
		}		
	}
	
	bool existeFuncion(string id){
		for(int j=0; j < cantSalas ; j++){
			for(int k=0; k < salas[j].cantFunciones ; k++){
				if(salas[j].funciones[k].id == id){
					cout << "\t\t\tElije entre las siguientes sillas: " << endl;
					cout << "\t\t\tGenerales: " << endl;
					salas[j].funciones[k].mostrarSillasGDisponibles();
					cout << endl;
					cout << "\t\t\tPreferenciales: " << endl;
					salas[j].funciones[k].mostrarsillasPDisponibles();
					cout << endl << "\t\t\t";
					return true;
				}				
			}
		}
		return false;
	}
	
	
	bool comprarTiqueteFuncion(string idFunc, string idSilla){
		for(int j=0; j < cantSalas ; j++){
			for(int k=0; k < salas[j].cantFunciones ; k++){
				if(salas[j].funciones[k].id == idFunc){
					if(salas[j].funciones[k].comprarSilla(idSilla)){
						return true;
					}
				}				
			}
		}
		return false;
	}

	//Comprobar que la sala añadida no exista
	bool comprobarNombreSala(string nombre){
		for(int i=0; i<cantSalas ; i++){
			if(salas[i].nombre == nombre){
				return false;
			}
		}
		return true;
	}
	
	bool comprobarNombrePelicula(string nombre){
		for(int i=0; i<cantPelis ; i++){
			if(peliculas[i].nombre == nombre){
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
		//Se hace un arreglo temporal con un espacio más para agregar la sala
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
				sala.agregarSilla("General"); //Si aún no llego a la cantidade sillas generales se van agregando de tipo general
			}else{
				sala.agregarSilla("Preferencial");	//Una vez se pase ese numero se termina de agregar sillas preferenciales
			}
		}
	}
	
	
	void agregarPelicula(string peli, Sala &sala, string fecha, string hora){
		
		Pelicula peliTemp;
		peliTemp.nombre = peli;
		
		//Se agrega una pelicula al arreglo de salas en el multiplex
		//Se hace un arreglo temporal con un espacio más para agregar la pelicula
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
		
		//Se agrega finalmente la función nueva
		agregarFuncion(peli, sala, fecha, hora);

	}
	
	void agregarFuncion(string peli, Sala &sala, string fecha, string hora){
		idFuncion++;
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
			cout << "\t\t\t["<<(i+1) <<"]. Pelicula: '" <<peliculas[i].nombre  << "'"<< endl; 
		}
	}
	
	void listarFuncionesPelicula(string nombrePeli){
		for(int j=0; j < cantSalas ; j++){
			for(int k=0; k < salas[j].cantFunciones ; k++){
				if(salas[j].funciones[k].peli == nombrePeli){
					cout << salas[j].funciones[k].mostrarInfo();
					cout << "\t\t\tSillas Generales disponibles: "<< salas[j].funciones[k].sillasGDisponibles() <<  endl;
					cout << "\t\t\tSillas Preferenciales disponibles: "<< salas[j].funciones[k].sillasPDisponibles() <<  endl;
					cout << "\t\t\t************************************************" << endl;
				}
			}
		}
		cout << "\t\t\t************************************************" << endl;
	}
	
		
};








