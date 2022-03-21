#include <cstdlib> //Para usar System (refrescar la pantalla en el CLI )
#include <iostream> //Entrada y salida de datos en consola
#include"Multiplex.h" //Librería externa que está dentro del proyecto
#include <clocale> //Permitir tildes en consola
using namespace std;

//Instancia del multiplex (Objeto de Multiplex)
Multiplex miMultiplex;
//Prototipo de las funciones
void menuPrincipal();
void menuSalas();//
void menuTiquetes();
void menuCambiarCostoTiquetes();
void menuPeliculasFunciones();//


//Main del programa
int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	menuPrincipal();
	
}


//Función para el Menu principal
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
        cout << "\t\t\t 1. Ir a Salas de Cine" <<endl;
        cout << "\t\t\t 2. Ir a tiquetes" <<endl;
        cout << "\t\t\t 3. Ir a películas y Funciones" <<endl;
        cout << "\t\t\t 0. SALIR" << endl << endl;		
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opción: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				menuSalas();
				break;
			case 2:
				menuTiquetes();
				break;
			case 3:
				menuPeliculasFunciones();
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
	
}




//Menú para agregar una sala de cine con la cantidad de sillas respectivas
void menuSalas(){
	
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer la sala nueva
	char nomSala[50];
	int cantSillasTotal;
	int cantSillasGenerales;
	//Variable que guarda la sala a eliminar
	int numSalaEliminar;
	//Variable para leer el número de sillas a agregar
	int nsillas;
	//Variable para saber  cuantas generales agregar
	int sillasGenerales;
	//Variable para saber a que sala agregar sillas
	int numSala;
	
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Se agregará una sala de cine nueva" << endl << endl;
		//Texto de salas actuales
		cout << "\t\t\tCantidad de salas actuales: " << miMultiplex.cantSalas << endl;
		miMultiplex.listarSalas();
		cout << "\t\t\t--------------------------------------------" << endl;
		//Opciones del menu
		cout << "\t\t\tOpciones:" <<endl;
        cout << "\t\t\t1. Agregar Nueva Sala" <<endl;
        cout << "\t\t\t2. Eliminar Sala" <<endl;
        cout << "\t\t\t3. Añadir sillas a Sala" <<endl;
        cout << "\t\t\t4. Retroceder" <<endl;
		cout << "\t\t\t--------------------------------------------" << endl;
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opción:";
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
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				if(miMultiplex.cantSalas>0){
					cout << "\t\t\tEscribe el número asociado a la sala para eliminar: " << endl << "\t\t\t";
					cin >> numSalaEliminar;
					if(numSalaEliminar > 0 && numSalaEliminar <= miMultiplex.cantSalas){
						miMultiplex.eliminarSala(numSalaEliminar);
						cout<< "\t\t\tSala " << numSalaEliminar << " eliminada correctamente"<<endl;
					}else{
						cout<< "\t\t\tEl número no coincide con una sala existente"<<endl;	
					}
				
				}else{
					cout << "\t\t\tDebe haber al menos una sala para poder eliminarse" << endl;
				}
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 3:
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
						cout<< "\t\t\tSe han agregado "<< nsillas << " sillas con éxito, " << sillasGenerales << " son generales y " << nsillas-sillasGenerales << " son preferenciales" << endl;
						
					}else{
						cout<< "\t\t\tEl número no coincide con una sala existente"<<endl;	
					}
				}else{
					cout << "\t\t\tDebe haber al menos una sala para poder agregar una película" << endl;
				}
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 4:
				repetir = false;
				break;
			default:
				cout << "Tecla no válida";
				repetir = false;
		}
		
	}while(repetir);
	
	
	
	
}


//Menú para crear un nuevo tiquete
void menuTiquetes(){
	
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Numero de la sala para escoger
	int numSala;
	//Número de pelicula para escoger
	int numPeli;
	//Número de la función para escoger
	int numFuncion;
	//Número de la silla a comprar
	int numSilla;
	
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Generación de nuevo tiquete" << endl << endl;
		//Texto de salas actuales
		cout << "\t\t\tCantidad de salas actuales: " << miMultiplex.cantSalas << endl;
		miMultiplex.listarSalas();
		cout << "\t\t\t--------------------------------------------" << endl;
		//Opciones del menu principal
		cout << "\t\t\tOpciones:" <<endl;
        cout << "\t\t\t 1. Elegir película para nuevo tiquete" <<endl;
        cout << "\t\t\t 2. Elegir sala para ver disponibilidad de sillas" <<endl;
        cout << "\t\t\t 3. Cambiar precio de tiquetes" <<endl;
        cout << "\t\t\t 4. Retroceder" <<endl;
		cout << "\t\t\t--------------------------------------------" << endl;
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opción: ";
		cin >> opcion;
		cout << "\t\t\t--------------------------------------------" << endl;
		
		//Alternativas
		switch(opcion){
			case 1:
				if(miMultiplex.cantPelis>0){
					
				
				cout << "\t\t\t Las Peliculas disponibles son: " << endl;
				cout << "\t\t\t--------------------------------------------" << endl;
				miMultiplex.listarPeliculas();
				cout << "\t\t\t--------------------------------------------" << endl;
				cout << "\t\t\tEscribe el código de la película: " << endl << "\t\t\t";
				cin >> numPeli;
				cout<< "\t\t\tLos horarios y salas sugeridas para la película se muestran: " << endl;
				cout << "\t\t\t********************************************************" << endl;
				miMultiplex.listarFuncionesPelicula(miMultiplex.getPelicula(numPeli).nombre);
				cout << "\t\t\tEscribe el código de la función : " << endl << "\t\t\t";
				cin >> numFuncion;
				
				if(miMultiplex.existeFuncion(int_to_string(numFuncion))){
					cin >> numSilla;
					if(miMultiplex.comprarTiqueteFuncion(int_to_string(numFuncion), int_to_string(numSilla))){
						cout << "\t\t\tSilla comprada con éxito" << endl;
					}else{
						cout << "\t\t\tLa silla está ocupada, no se ha podido comprar" << endl;
					}
					
				}else{
					cout << "La funcion no existe";
				}
				
				}else{
					cout << "\t\t\tNo hay películas agregadas aún" << endl;
				}
				
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				if(miMultiplex.cantSalas>0){	
					cout << "\t\t\tEscribe el numero asociado a la sala para ver su información" << endl << "\t\t\t";
					cin >> numSala;
					
					if(numSala > 0 && numSala <= miMultiplex.cantSalas){
						cout << "\t\t\t--------------------------------------------" << endl;
						cout << "\t\t\tPara la sala '" << miMultiplex.getSala(numSala).nombre << "' estas son las Funciones disponibles: " << endl;
						cout << "\t\t\t********************************************************" << endl;
						cout << miMultiplex.getSala(numSala).listarFuncionesConSillas();
					}else{
							cout<< "\t\t\tEl número no coincide con una sala existente"<<endl;	
					}
				}else{
					cout << "\t\t\tDebe haber al menos una sala para poder ver sillas disponibles" << endl;
				}
				
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 3:
				menuCambiarCostoTiquetes();
				break;
			case 4:
				repetir = false;
				break;	
		}
		
	}while(repetir);
	
	
}

//Menú para cambiar el costo del tiquete dada una categoría 
void menuCambiarCostoTiquetes(){
	
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	int valor;
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\t\t\t	Cambiar costo de tiquetes " << endl << endl;
		cout << "\t\t\tCosto de tiquetes Generales: " << costoGeneral << endl;
		cout << "\t\t\tCosto de tiquetes Preferenciales: " << costoPreferencial << endl;
		
		//Opciones del menu principal
		cout << "\t\t\tOpciones:" <<endl;
        cout << "\t\t\t 1. Cambiar precio tiquetes Generales" <<endl;
        cout << "\t\t\t 2. Cambiar precio tiquetes Preferenciales" <<endl;
        cout << "\t\t\t 3. Retroceder" <<endl;
		cout << "\t\t\t--------------------------------------------" << endl;
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opción: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout<< "\t\t\tIngresa el nuevo precio de los tiquetes Generales" << endl;
//				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin >> valor; //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				costoGeneral = valor;
				cout<< "\t\t\tLos tiquetes generales ahora cuestan " << costoGeneral<< endl;
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				cout<< "\t\t\tIngresa el nuevo precio de los tiquetes Preferenciales" << endl;
//				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin >> valor; //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				costoPreferencial = valor;
				cout<< "\t\t\tLos tiquetes preferenciales ahora cuestan " << costoPreferencial << endl;
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
				
			case 3:
				repetir = false;
				break;
		}
		
	}while(repetir);
}


//Menú para agregar una pelicula al vector de peliculas
void menuPeliculasFunciones(){
	
			//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer el nombre de la pelicula
	char nombrePeli[50];
	//Variable para leer el numero de sala, día y hora
	int numSala, numDia, numHora;
	//Variable para leer pelicula existente
	int numPeli;
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Se agregará una película" << endl << endl;
		cout << "\t\t\tCantidad de salas actuales: " << miMultiplex.cantSalas << endl;
		miMultiplex.listarSalas();
		cout << "\t\t\t--------------------------------------------" << endl;
		//Opciones del menu
		cout << "\t\t\tOpciones:" <<endl;
        cout << "\t\t\t 1. Elegir sala para la película nueva" <<endl;
        cout << "\t\t\t 2. Elegir una película existente" <<endl;
        cout << "\t\t\t 3. Retroceder" <<endl;
		cout << "\t\t\t--------------------------------------------" << endl;
		
		cout << "\t\t\tElige una opción: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				if(miMultiplex.cantSalas>0){
				cout << "\t\t\tEscribe el numero asociado a la sala" << endl << "\t\t\t";
				cin >> numSala;
				
				if(numSala > 0 && numSala <= miMultiplex.cantSalas){	
					cout << "\t\t\t--------------------------------------------" << endl;
					cout << "\t\t\tCantidad de funciones en la sala: " <<  miMultiplex.salas[numSala-1].cantFunciones << endl << endl;
					cout << miMultiplex.getSala(numSala).listarFunciones();
					
					cout << "\t\t\t--------------------------------------------" << endl;
					cout << "\t\t\tEscribe el nombre de la pelicula" << endl << "\t\t\t";
					cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
					cin.getline(nombrePeli,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
					cout << "\t\t\t--------------------------------------------" << endl;
					cout << "\t\t\tListado de Días y horas:" << endl;
					cout << "\t\t\t--------------------------------------------" << endl;
					cout << "\t\t\tDías de la semana: " << endl;
					mostrarDias();
					
					
					cout << "\t\t\t--------------------------------------------" << endl;
					cout << "\t\t\tHoras del día: " << endl;
					mostrarHoras();
					
					
					cout << "\t\t\tNúmero asociado al día:" << endl << "\t\t\t";
					cin >> numDia;
					
					cout << "\t\t\tNúmero asociado a la hora:" << endl << "\t\t\t";
					cin >> numHora;
					
					if(miMultiplex.getSala(numSala).funcionNuevaDisponible(dias[numDia-1], horas[numHora-1])){
						miMultiplex.agregarPelicula(nombrePeli, miMultiplex.getSala(numSala), dias[numDia-1], horas[numHora-1]);
						cout << "\t\t\tLa película ha sido agregada correctamente, nueva función generada" << endl << "\t\t\t";
					}else{
						cout << "\t\t\tLa función ya existe, no fue posible crearla" << endl << "\t\t\t";
					}
					
					}else{
						cout<< "\t\t\tEl número no coincide con una sala existente"<<endl;	
					}
					
				}else{
					cout << "\t\t\tDebe haber al menos una sala para poder agregar una película" << endl;
				}
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				if(miMultiplex.cantPelis>0){
					if(miMultiplex.cantSalas>0){
						cout << "\t\t\t Las Peliculas disponibles son: " << endl;
						cout << "\t\t\t--------------------------------------------" << endl;
						miMultiplex.listarPeliculas();
						cout << "\t\t\t--------------------------------------------" << endl;
						cout << "\t\t\tEscribe el numero asociado a la película " << endl << "\t\t\t";
						cin >> numPeli;
						
						cout << "\t\t\tEscribe el numero asociado a la sala" << endl << "\t\t\t";
						cin >> numSala;
						
						
				
						if(numSala > 0 && numSala <= miMultiplex.cantSalas){
							cout << "\t\t\t--------------------------------------------" << endl;
							cout << "\t\t\tCantidad de funciones en la sala: " <<  miMultiplex.salas[numSala-1].cantFunciones << endl << endl;
							cout << miMultiplex.getSala(numSala).listarFunciones();
							
							cout << "\t\t\t--------------------------------------------" << endl;
							cout << "\t\t\tListado de Días y horas:" << endl;
							cout << "\t\t\t--------------------------------------------" << endl;
							cout << "\t\t\tDías de la semana: " << endl;
							mostrarDias();
							
							
							cout << "\t\t\t--------------------------------------------" << endl;
							cout << "\t\t\tHoras del día: " << endl;
							mostrarHoras();
							
							
							cout << "\t\t\tNúmero asociado al día:" << endl << "\t\t\t";
							cin >> numDia;
							
							cout << "\t\t\tNúmero asociado a la hora:" << endl << "\t\t\t";
							cin >> numHora;
							
							if(miMultiplex.getSala(numSala).funcionNuevaDisponible(dias[numDia-1], horas[numHora-1])){
								miMultiplex.agregarFuncion(miMultiplex.getPelicula(numPeli).nombre, miMultiplex.getSala(numSala), dias[numDia-1], horas[numHora-1]);
								cout << "\t\t\tLa nueva función generada correctamente" << endl << "\t\t\t";
							}else{
								cout << "\t\t\tLa función ya existe, no fue posible crearla" << endl << "\t\t\t";
							}
							
						}else{
								cout<< "\t\t\tEl número no coincide con una sala existente"<<endl;	
						}
						
					}else{
						cout << "\t\t\tDebe haber al menos una sala para poder agregar una película" << endl;
					}
				
				}else{
					cout << "\t\t\tNo hay películas agregadas " << endl;
				}
				
				
				cout << "\t\t\tOprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 3:
				repetir = false;
				break;
			default:
				cout << "Tecla no válida";
		}
		
	}while(repetir);
	
	
}




