#include <cstdlib> //Para usar System (refrescar la pantalla en el CLI )
#include <iostream> //Entrada y salida de datos en consola
#include"Multiplex.h" //Librería externa que está dentro del proyecto
#include <clocale> //Permitir tildes en consola
using namespace std;

//Prototipo de las funciones
void menuPrincipal();
void menuAgregarSala();
void menuEliminarSala();
void menuGenerarTiquete();
void menuMostrarSillasDisponibles();
void menuCambiarCostoTiquetes();
void menuAgregarSillas();
void menuAgregarPelicula();


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
        cout << "\t\t\t 1. Agregar Sala de Cine" <<endl;
        cout << "\t\t\t 2. Eliminar Sala de Cine" <<endl;
        cout << "\t\t\t 3. Vender Tiquete" <<endl;
        cout << "\t\t\t 4. Ver sillas disponibles en una sala" <<endl;
        cout << "\t\t\t 5. Cambiar precio de tiquetes" <<endl;
        cout << "\t\t\t 6. Agregar sillas a una sala" <<endl;
        cout << "\t\t\t 7. Agregar película" <<endl;
        cout << "\t\t\t 0. SALIR" << endl << endl;		
		
		//Lee la opcion elegida del usuario
		cout << "\tElige una opción: ";
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
				menuMostrarSillasDisponibles();
				break;
			case 5:
				menuCambiarCostoTiquetes();
				break;
			case 6:
				menuAgregarSillas();
				break;
			case 7:
				menuAgregarPelicula();
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
	
}




//Menú para agregar una sala de cine con la cantidad de sillas respectivas
void menuAgregarSala(){
	
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer la sala nueva
	string nombreSala;
	char nomSala[50];
	
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Se agregará una sala de cine nueva" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Agregar" <<endl;
        cout << "\t\t\t 2. Retroceder" <<endl;
		
		//Lee la opcion elegida del usuario
		cout << "\tElige una opción: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout << "Escribe el nombre de la sala" << endl;
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomSala,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout<< "La sala " <<nomSala << " ha sido agregada con éxito" << endl;
				cout << "Oprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				repetir = false;
				break;
			default:
				cout << "Tecla no válida";
		}
		
	}while(repetir);
	
	
	
	
}

//Menú para eliminar una sala existente
void menuEliminarSala(){
	
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Se eliminará la sala de cine escogida" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Escoger Sala" <<endl;
        cout << "\t\t\t 2. Retroceder" <<endl;
		
		//Lee la opcion elegida del usuario
		cout << "\tElige una opción: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout<< "Sala eliminada"<<endl;
				cout << "Oprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				repetir = false;
				break;	
		}
		
	}while(repetir);
	
	
}

//Menú para crear un nuevo tiquete
void menuGenerarTiquete(){
	
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Generación de nuevo tiquete" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Elegir película para el nuevo tiquete" <<endl;
        cout << "\t\t\t 2. Retroceder" <<endl;
		
		//Lee la opcion elegida del usuario
		cout << "\tElige una opción: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout<< "Los horarios y salas sugeridas para la película se están mostrando..." << endl;
				cout << "Oprime cualquier tecla para elegir un horario"<<endl;
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				cout<< "Tiquete generado exitósamente" <<endl;
				cout << "Oprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				repetir = false;
				break;	
		}
		
	}while(repetir);
	
	
}


//Menú para ver las sillas disponibles que hay en una sala 
void menuMostrarSillasDisponibles(){
	
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Sillas disponibles en salas" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Escoger Sala" <<endl;
        cout << "\t\t\t 2. Retroceder" <<endl;
		
		//Lee la opcion elegida del usuario
		cout << "\tElige una opción: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout<< "Las sillas disponibles en la sala escogida se están mostrando..." << endl;
				cout << "Oprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
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
		cout << "\n\t\t\t	Cambiar costo de tiquetes " << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Cambiar precio tiquetes Generales" <<endl;
        cout << "\t\t\t 2. Cambiar precio tiquetes Preferenciales" <<endl;
        cout << "\t\t\t 3. Retroceder" <<endl;
		
		//Lee la opcion elegida del usuario
		cout << "\tElige una opción: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout<< "Ingresa el nuevo precio de los tiquetes Generales" << endl;
//				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin >> valor; //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout<< "Los tiquetes generales ahora cuestan " << valor<< endl;
				cout << "Oprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				cout<< "Ingresa el nuevo precio de los tiquetes Preferenciales" << endl;
//				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin >> valor; //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout<< "Los tiquetes preferenciales ahora cuestan " << valor << endl;
				cout << "Oprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
				
			case 3:
				repetir = false;
				break;
		}
		
	}while(repetir);
}

//Menú para agregar una cantidad dada de sillas a una sala
void menuAgregarSillas(){
	
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer el número de sillas
	int nsillas;
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Se agregarán sillas a una sala" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Seleccionar Sala" <<endl;
        cout << "\t\t\t 2. Retroceder" <<endl;
		
		//Lee la opcion elegida del usuario
		cout << "\tElige una opción: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout << "Escribe la cantidad de sillas que deseas agregar" << endl;
				cin >> nsillas;
				cout<< "se han agregado "<< nsillas << " sillas con éxito" << endl;
				cout << "Oprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				repetir = false;
				break;
			default:
				cout << "Tecla no válida";
		}
		
	}while(repetir);
	
	
	
	
}

//Menú para agregar una pelicula al vector de peliculas
void menuAgregarPelicula(){
	
			//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer el número de sillas
	int nsillas;
	
	do{
		system("cls");
		//Titulo del menu principal
		cout << "\n\t\t\t	Se agregarán una película" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Ingresar datos de pelicula" <<endl;
        cout << "\t\t\t 2. Retroceder" <<endl;
		
		//Lee la opcion elegida del usuario
		cout << "\tElige una opción: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout<< "se está recopilando información de la pelicula..." << endl;
				cout<< "se está agregando la película..." << endl;
				cout << "Oprime cualquier tecla para continuar";
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				repetir = false;
				break;
			default:
				cout << "Tecla no válida";
		}
		
	}while(repetir);
	
	
}




