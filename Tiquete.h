#include"escritura.h"
using namespace std;

struct Tiquete{
	string id;
	
	string datosFuncion;
	
	string silla;
	
	string categoriaSilla;
	
	string costo;
	
	void realizarTiquete(){
		string texto = "";
		texto += "\t\tID del tiquete: " + id + "\n";
		texto += "\t\tDatos de la Función: \n" + datosFuncion + "\n";
		texto += "\t\tSilla comprada: " + silla + "\n";
		texto += "\t\tTipo de silla: " + categoriaSilla + "\n";
		texto += "\t\tCosto del tiquete: " + costo + "\n";
		
		crearArchivoTiquete(id);
		escribirArchivoTiquete(texto);
		cerrarArchivoTiquete();
		cout << "\t\t\tTiquete generado con éxito" << endl;
	}
	
};
