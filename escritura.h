#include <fstream> 
using namespace std;

ofstream archivoTiquete;


void crearArchivoTiquete(string id){
	archivoTiquete.open("Tiquete_"+ id + "_MULTIPLEX.txt", ios::out);//Acá iría añadido el id del tiquete
}

void escribirArchivoTiquete(string texto){
	archivoTiquete << "\t\t\tTIQUETE DE MULTIPLEX \n";
	archivoTiquete << texto;
}

void cerrarArchivoTiquete(){
	archivoTiquete.close();
}

