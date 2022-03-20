using namespace std;
//A continuaci�n solo son plantillas para tomar la info para las dias y horarios disponibles

//Arreglo de d�as disponibles para esa semana de marzo
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
	//Id de la funci�n
	string id;
	//Nombre de Pelicula de la funci�n
	string peli;
	//Nombre de Sala  de la funci�n
	string sala;
	//Fecha  de la funci�n
	string dia;
	//Hora  de la funci�n
	string hora;
	
	//Devuelve un string con toda la informaci�n de la funci�n
	string mostrarInfo(){
		return "\t\t\tID de la funci�n: " + id + "\n\t\t\tPel�cula: " + peli + "\n\t\t\tSala: " + sala + "\n\t\t\tFecha y Hora: " + dia + " - " + hora + "\n";
	}
	
	//Se asgina un d�a de la semana a la variable dia
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
	
	
};

