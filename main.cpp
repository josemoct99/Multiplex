#include <cstdlib> //Para usar System (refrescar la pantalla en el CLI )
#include <iostream> //Entrada y salida de datos en consola
#include"Multiplex.h" //Librer�a externa que est� dentro del proyecto
#include <clocale> //Permitir tildes en consola
using namespace std;

//Instancia del multiplex (Objeto de Multiplex)
Multiplex miMultiplex;
//Prototipo de las funciones
void menuPrincipal();
void menuAgregarSala();//
void menuEliminarSala();//
void menuGenerarTiquete();
void menuCambiarCostoTiquetes();
void menuAgregarSillas();//
void menuAgregarPelicula();//


//Main del programa
int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	menuPrincipal();
	
}


//Funci�n para el Menu principal
void menuPrincipal(){
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	
	do{
		system("cls");
		
		// la flecha antes que cualquier cosa
		
		
		//Titulo del menu principal
		cout << "\n\t\t\t	Bienvendio al administrador del cine Multiplex" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Agregar Sala de Cine" <<endl;
        cout << "\t\t\t 2. Eliminar Sala de Cine" <<endl;
        cout << "\t\t\t 3. Vender Tiquete" <<endl;
        cout << "\t\t\t 4. Cambiar precio de tiquetes" <<endl;
        cout << "\t\t\t 5. Agregar sillas a una sala" <<endl;
        cout << "\t\t\t 6. Agregar pel�cula" <<endl;
        cout << "\t\t\t 0. SALIR" << endl << endl;		
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				menuAgregarSala();
				break;
			case 2:
				menuEliminarSala();
				break;
			case 3:
				menuGenerarTiquete();
				break;
			case 4:
				menuCambiarCostoTiquetes();
				break;
			case 5:
				menuAgregarSillas();
				break;
			case 6:
				menuAgregarPelicula();
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
	
}




//Men� para agregar una sala de cine con la cantidad de sillas respectivas
void menuAgregarSala(){
	
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer la sala nueva
	char nomSala[50];
	int cantSillasTotal;
	int cantSillasGenerales;
	
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Se agregar� una sala de cine nueva" << endl << endl;
		//Texto de salas actuales
		cout << "\t\t\tCantidad de salas actuales: " << miMultiplex.cantSalas << endl;
		miMultiplex.listarSalas();
		cout << "\t\t\t--------------------------------------------" << endl;
		//Opciones del menu
		cout << "\t\t\tOpciones:" <<endl;
        cout << "\t\t\t1. Agregar" <<endl;
        cout << "\t\t\t2. Retroceder" <<endl;
		cout << "\t\t\t--------------------------------------------" << endl;
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n:";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout << "\t\t\tEscribe el nombre de la sala" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomSala,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				
				//Comprueba si la sala existe o no
				if(miMultiplex.comprobarNombreSala(nomSala) == true){
					cout << "\t\t\tEscibe la cantidad de sillas de la sala" << endl << "\t\t\t";
					cin >> cantSillasTotal;
					//Obtiene las sillas generales siempre y cuando sean menores a la cantidad de sillas totales ingresadas
					do{
						cout << "\t\t\tEscibe la cantidad de sillas generales, deben ser menor o igual que "<< cantSillasTotal << endl << "\t\t\t";
						cin >> cantSillasGenerales;
					}while(cantSillasGenerales>cantSillasTotal);
					

					
						miMultiplex.agregarSala(nomSala, cantSillasTotal, cantSillasGenerales);
						cout<< "\t\t\tLa sala generada '" <<nomSala << "' tiene " << cantSillasTotal << " sillas , " << cantSillasGenerales << " son generales y " << cantSillasTotal-cantSillasGenerales << " preferenciales" << endl;	
				}else{
					cout << "\t\t\tLa sala '" << nomSala << "' ya existe, no fue posible generarla" << endl;
				}
				
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 2:
				repetir = false;
				break;
			default:
				cout << "Tecla no v�lida";
		}
		
	}while(repetir);
	
	
	
	
}

//Men� para eliminar una sala existente
void menuEliminarSala(){
	
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable que guarda la sala a eliminar
	int numSala;
	
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Se eliminar� la sala de cine escogida" << endl << endl;
		//Texto previo
		cout << "\t\t\tCantidad de salas actuales: " << miMultiplex.cantSalas << endl;
		miMultiplex.listarSalas();
		cout << "\t\t\t--------------------------------------------" << endl;
		//Opciones del menu
		cout << "\t\t\tOpciones:" <<endl;
        cout << "\t\t\t 1. Elminar una sala" <<endl;
        cout << "\t\t\t 2. Retroceder" <<endl;
		cout << "\t\t\t--------------------------------------------" << endl;
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: ";
		cin >> opcion;
		cout << "\t\t\t--------------------------------------------" << endl;
		
		//Alternativas
		switch(opcion){
			case 1:
				if(miMultiplex.cantSalas>0){
					cout << "\t\t\tEscribe el n�mero asociado a la sala para eliminar: " << endl << "\t\t\t";
					cin >> numSala;
					if(numSala > 0 && numSala <= miMultiplex.cantSalas){
						miMultiplex.eliminarSala(numSala);
						cout<< "\t\t\tSala " << numSala << " eliminada correctamente"<<endl;
					}else{
						cout<< "\t\t\tEl n�mero no coincide con una sala existente"<<endl;	
					}
				
				}else{
					cout << "\t\t\tDebe haber al menos una sala para poder eliminarse" << endl;
				}
					cout << "\t\t\tOprime cualquier tecla para continuar";
					system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
					break;
			case 2:
				repetir = false;
				break;	
		}
		
	}while(repetir);
	
	
}

//Men� para crear un nuevo tiquete
void menuGenerarTiquete(){
	
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Numero de la sala para escoger
	int numSala;
	//N�mero de pelicula para escoger
	int numPeli;
	
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Generaci�n de nuevo tiquete" << endl << endl;
		//Texto de salas actuales
		cout << "\t\t\tCantidad de salas actuales: " << miMultiplex.cantSalas << endl;
		miMultiplex.listarSalas();
		cout << "\t\t\t--------------------------------------------" << endl;
		//Opciones del menu principal
		cout << "\t\t\tOpciones:" <<endl;
        cout << "\t\t\t 1. Elegir pel�cula para el nuevo tiquete" <<endl;
        cout << "\t\t\t 2. Elegir sala para ver disponibilidad de sillas" <<endl;
        cout << "\t\t\t 3. Retroceder" <<endl;
		cout << "\t\t\t--------------------------------------------" << endl;
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: ";
		cin >> opcion;
		cout << "\t\t\t--------------------------------------------" << endl;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout << "\t\t\t Las Peliculas disponibles son: " << endl;
				miMultiplex.listarPeliculas();
				cout<< "\t\t\tLos horarios y salas sugeridas para la pel�cula se est�n mostrando..." << endl;
				
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 2:
				if(miMultiplex.cantSalas>0){	
					cout << "\t\t\tEscribe el numero asociado a la sala para ver su informaci�n" << endl << "\t\t\t";
					cin >> numSala;
					
					if(numSala > 0 && numSala <= miMultiplex.cantSalas){
						cout << "\t\t\t--------------------------------------------" << endl;
						cout << "\t\t\tPara la sala '" << miMultiplex.getSala(numSala).nombre << "' estas son las Funciones disponibles: " << endl;
						cout << "\t\t\t********************************************************" << endl;
						cout << miMultiplex.getSala(numSala).listarFuncionesConSillas();
					}else{
							cout<< "\t\t\tEl n�mero no coincide con una sala existente"<<endl;	
					}
				}else{
					cout << "\t\t\tDebe haber al menos una sala para poder ver sillas disponibles" << endl;
				}
				
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 3:
				repetir = false;
				break;	
		}
		
	}while(repetir);
	
	
}

//Men� para cambiar el costo del tiquete dada una categor�a 
void menuCambiarCostoTiquetes(){
	
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	int valor;
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Cambiar costo de tiquetes " << endl << endl;
		//Opciones del menu principal
		cout << "\t\t\tOpciones:" <<endl;
        cout << "\t\t\t 1. Cambiar precio tiquetes Generales" <<endl;
        cout << "\t\t\t 2. Cambiar precio tiquetes Preferenciales" <<endl;
        cout << "\t\t\t 3. Retroceder" <<endl;
		cout << "\t\t\t--------------------------------------------" << endl;
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout<< "Ingresa el nuevo precio de los tiquetes Generales" << endl;
//				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin >> valor; //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout<< "Los tiquetes generales ahora cuestan " << valor<< endl;
				cout << "Oprime cualquier tecla para continuar";
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 2:
				cout<< "Ingresa el nuevo precio de los tiquetes Preferenciales" << endl;
//				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin >> valor; //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout<< "Los tiquetes preferenciales ahora cuestan " << valor << endl;
				cout << "Oprime cualquier tecla para continuar";
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
				
			case 3:
				repetir = false;
				break;
		}
		
	}while(repetir);
}

//Men� para agregar una cantidad dada de sillas a una sala
void menuAgregarSillas(){
	
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer el n�mero de sillas
	int nsillas;
	//Variable para saber  cuantas son generales
	int sillasGenerales;
	//Variable para leer el numero de la sala
	int numSala;
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Se agregar�n sillas a una sala" << endl << endl;
		//Texto de salas actuales
		cout << "\t\t\tCantidad de salas actuales: " << miMultiplex.cantSalas << endl;
		miMultiplex.listarSalas();
		cout << "\t\t\t--------------------------------------------" << endl;
		//Opciones del menu principal
		cout << "\t\t\tOpciones:" <<endl;
        cout << "\t\t\t 1. Seleccionar Sala" <<endl;
        cout << "\t\t\t 2. Retroceder" <<endl;
		cout << "\t\t\t--------------------------------------------" << endl;
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				
				if(miMultiplex.cantSalas>0){	
					cout << "\t\t\tEscribe el numero asociado a la sala para agregar sillas " << endl << "\t\t\t";
					cin >> numSala;
					
					if(numSala > 0 && numSala <= miMultiplex.cantSalas){
						
					cout << "\t\t\tEscribe la cantidad de sillas que deseas agregar" << endl <<  "\t\t\t";
					cin >> nsillas;
					
						do{
							cout << "\t\t\tEscibe la cantidad de sillas generales, deben ser menor o igual que "<< nsillas << endl << "\t\t\t";
							cin >> sillasGenerales;
						}while(sillasGenerales>nsillas || sillasGenerales<0);
						miMultiplex.agregarSillas(miMultiplex.getSala(numSala), nsillas, sillasGenerales);
						cout<< "\t\t\tSe han agregado "<< nsillas << " sillas con �xito, " << sillasGenerales << " son generales y " << nsillas-sillasGenerales << " son preferenciales" << endl;
						
					}else{
						cout<< "\t\t\tEl n�mero no coincide con una sala existente"<<endl;	
					}
				}else{
					cout << "\t\t\tDebe haber al menos una sala para poder agregar una pel�cula" << endl;
				}

				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 2:
				repetir = false;
				break;
			default:
				cout << "Tecla no v�lida";
		}
		
	}while(repetir);
	
	
	
	
}

//Men� para agregar una pelicula al vector de peliculas
void menuAgregarPelicula(){
	
			//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer el nombre de la pelicula
	char nombrePeli[50];
	//Variable para leer el numero de sala, d�a y hora
	int numSala, numDia, numHora;
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Se agregar� una pel�cula" << endl << endl;
		cout << "\t\t\tCantidad de salas actuales: " << miMultiplex.cantSalas << endl;
		miMultiplex.listarSalas();
		cout << "\t\t\t--------------------------------------------" << endl;
		//Opciones del menu
		cout << "\t\t\tOpciones:" <<endl;
        cout << "\t\t\t 1. Elegir sala para la pel�cula" <<endl;
        cout << "\t\t\t 2. Retroceder" <<endl;
		cout << "\t\t\t--------------------------------------------" << endl;
		
		cout << "\t\t\tElige una opci�n: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				if(miMultiplex.cantSalas>0){
				cout << "\t\t\tEscribe el numero asociado a la sala para la pelicula " << endl << "\t\t\t";
				cin >> numSala;
				
				if(numSala > 0 && numSala <= miMultiplex.cantSalas){	
					cout << "\t\t\t--------------------------------------------" << endl;
					cout << "\t\t\tCantidad de funciones en la sala: " <<  miMultiplex.salas[numSala-1].cantFunciones << endl;
					cout << miMultiplex.getSala(numSala).listarFunciones();
					
					cout << "\t\t\t--------------------------------------------" << endl;
					cout << "\t\t\tEscribe el nombre de la pelicula" << endl << "\t\t\t";
					cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
					cin.getline(nombrePeli,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
					cout << "\t\t\t--------------------------------------------" << endl;
					cout << "\t\t\tListado de D�as y horas:" << endl;
					cout << "\t\t\t--------------------------------------------" << endl;
					cout << "\t\t\tD�as de la semana: " << endl;
					mostrarDias();
					
					
					cout << "\t\t\t--------------------------------------------" << endl;
					cout << "\t\t\tHoras del d�a: " << endl;
					mostrarHoras();
					
					
					cout << "\t\t\tN�mero asociado al d�a:" << endl << "\t\t\t";
					cin >> numDia;
					
					cout << "\t\t\tN�mero asociado a la hora:" << endl << "\t\t\t";
					cin >> numHora;
					
					if(miMultiplex.getSala(numSala).funcionNuevaDisponible(dias[numDia-1], horas[numHora-1])){
						miMultiplex.agregarPelicula(nombrePeli, miMultiplex.getSala(numSala), dias[numDia-1], horas[numHora-1]);
						cout << "\t\t\tLa pel�cula ha sido agregada correctamente, nueva funci�n generada" << endl << "\t\t\t";
					}else{
						cout << "\t\t\tLa funci�n ya existe, no fue posible crearla" << endl << "\t\t\t";
					}
					
					}else{
						cout<< "\t\t\tEl n�mero no coincide con una sala existente"<<endl;	
					}
					
				}else{
					cout << "\t\t\tDebe haber al menos una sala para poder agregar una pel�cula" << endl;
				}
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 2:
				repetir = false;
				break;
			default:
				cout << "Tecla no v�lida";
		}
		
	}while(repetir);
	
	
}




