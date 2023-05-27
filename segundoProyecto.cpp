//importamos todas las librerias a utilizar
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cctype>
#include <iomanip>

//Metodos que me ayudaran a darle colores a la interfaz
		
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define color SetConsoleTextAttribute	
#define h hConsole

//metodos del standard
using std::cin; using std::endl; using std::cout;

//declaracion de algunas funciones a usar
void gotoxy(int x, int y);

//llamamos a las librerias propias
#include "funciones_logicas_proyecto.h"
#include "funciones_graficas_proyecto.h"

//el main de todo el programa
int main() {
	
	//hacemos un array de struct socios de tamaño 100.	
	Socio socios[100];
	
	//hacemos un array de struct asociados de tamaño 100.	
	Asociado asociados[100];
	
	//hacemos un array de struct facturas de tamaño 100.	
	Factura facturas[100];
	
	
	//strcut que llevara a todos los contadores, los inicializamos
	Contador contador;
	contador.N_asociados = 0;
	contador.N_socios = 0;
	contador.N_sociosVip = 0;
	contador.N_sociosRegular = 0;
	contador.N_facturas = 0;
	
	pantalladeinicio(0,0);
	
	system("cls");
	
	//loop infinito del programa, solo se rompe cuando el usuario elija
	while(1){
		
		//color principal de fondo
		system("color 87");
		
		//llama y recibe la opcion que elija el usuario, ver "graficas.h" line 102
		char opcion_principal =	menuPrincipal();
		
		// ************ AFILIAR UN SOCIO AL CLUB **************
		if(opcion_principal == '1'){
			
			//llamada de la funcion que afiliara y verificara los datos del usuario, ver "funciones.h" linea 70
			afiliar_socio(socios,asociados, contador,contador.N_socios,'N');
		
		}
		// ************ Registrar Asociado **************
		else if(opcion_principal == '2'){
				
			venta_asociado_buscar_socio(socios,asociados, contador);
			
		}
		// ************ Registrar Consumo **************
		else if(opcion_principal == '3'){
			ventana_registrar_consumo(socios,facturas,asociados, contador);
		
		}
		// ************ Pagar Una Factura **************  
		else if(opcion_principal == '4'){
			ventana_pagar_factura(socios,facturas,asociados, contador);
		}
		// ************ Aumentar Fondos de la Cuenta De Un Socio **************
		else if(opcion_principal == '5'){
			
			ventana_aumentar_fondos_socio(socios,asociados,contador);
		}
		// ************ Cancelar Suscripción Socio **************
		else if(opcion_principal == '6'){
			cancelar_suscripcion_socio(socios,asociados,contador);
		}
		// ************ Modificar Información Socio **************
		else if(opcion_principal == '7'){
			ventana_modificar_usuario(socios,asociados,contador);
			
		}
		// ************ Consultas: **************
		else if(opcion_principal == '8'){
			consultas(socios, asociados, contador,facturas);
		}
	
	}
	
	
	return 0;
}
