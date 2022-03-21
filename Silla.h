using namespace std;
	
	//Costo de los tiquetes generales
	int costoPreferencial;
	//Costo de los tiquetes generales
	int costoGeneral;
	
struct Silla{
	//ID de la Silla
	string id;
	//Es Verdadero si está disponible o falso de lo contrario
	bool disponible;
	//Categoria de la silla
	string categoria;
	//Costo de la silla
	int costo;
	
	void generarCosto(){
		if(categoria=="General"){
			costo = costoGeneral;
		}else{
			costo = costoPreferencial;
		}
	}
	
};
