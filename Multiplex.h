#include"Sala.h"
#include"Pelicula.h"
#include"Tiquete.h"
#include"Horario.h"
#include <vector>
using namespace std;

struct Multiplex{
	string nombre;
	vector<Sala> salas;
	
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




