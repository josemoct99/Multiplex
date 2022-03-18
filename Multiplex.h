#include"Sala.h"
#include"Pelicula.h"
#include"Tiquete.h"
#include"Horario.h"
#include <vector>
using namespace std;

struct Multiplex{
	
	//Nombre del Multiplex
	string nombre;
	//Cantidad de salas en el multiplex
	int cantSalas = 0;
	//Arreglo de Salas (inicialmente tiene 0)
	Sala* salas = new Sala[cantSalas];
	//Cantidad de peliculas en el multiplex
	int cantPelis = 0;
	//Arreglo de Peliculas (inicialmente tiene 0)
	Pelicula* peliculas = new Pelicula[cantPelis];
	
	void prueba(string s){
		cout << s <<endl;
	}
	
	
	string sugerencias(Pelicula peli);
	//------------------------------------------------------
	void agregarSala(string nombre, int sillas);
	void eliminarSala(Sala scine);
	void generarTiquete(Sala scine, Pelicula peli, string categoria);
	string mostrarSillasDisponibles(Sala scine);
	void cambiarCostoTiquetes(string categoria, int valor);
	void agregarSillas(Sala scine, int cantidad);
	void agregarPelicula(string peli, Sala scine, Horario horario);
	
	
	
};



Multiplex miMultiplex;




