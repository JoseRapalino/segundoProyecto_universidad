//ATENCION ES PROBABLE QUE AL COMPILAR EL HEADER DE ERROR, YA QUE LAS LIBRERIAS SOLO SE DECLARAN EN EL MAIN PARA EVITAR EXCESO DE LIBRERIAS, CARGAR EL ARCHIVO Y COMPILAR EL MAIN.CPP

//LA SIGUIENTE TARRANGANA DE CODIGO SU UNICO FIN ES PARA MERA ESTETICA, AQUI NO SE EJECUTA NADA DEL PROYECTO

// ******** PARTE DE LA INTERFAZ DEL PROGRAMA *******



   //FUNCION GOTOXY, hace que podamos ubicar los mensajes en la pantalla mas facilmente, usando los ejes X, ejes Y
   // no interfiere con el rendimiento del programa, solo estetica
	void gotoxy(int x, int y) {
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}
		
// *************** PARTE DEL MENU ******


    
void ventana(int ejeX, int ejeY,int ejeXi, int ejeYi){

	for(int i=ejeYi; i<ejeY; i++){
		for(int j=ejeXi; j<ejeX; j++){
			
			// CREACION DE PAREDES SUPERIOR E INFENIOR Y LATERALES
			if(i==ejeYi){
				gotoxy(j,i);
				cout<<(char)205;
			}
			
			if(i==ejeY-1){
				gotoxy(j,i);
				cout<<(char)205;
			}
			
			if(j==ejeXi){
				gotoxy(j,i);
				cout<<(char)186;
			}
			
			if(j==ejeX-1){
				gotoxy(j,i);
				cout<<(char)186;
			}
			
			// SOBRE ESCRIBIR LAS ESQUINAS  
			
			if(i==ejeYi and j==ejeXi){
			gotoxy(j,i); // ESQUINA SUPERIOR IZQUIERDA
			cout<<(char)201;	
			}
			
			if(i==ejeY-1 and j==ejeXi){
			gotoxy(j,i); //ESQUINA INFERIOR IZQUIERDA
			cout<<(char)200;	
			}
			
			if(i==ejeYi and j==ejeX-1){
			gotoxy(j,i); // ESQUINA SUPERIOR DERECHA
			cout<<(char)187;	
			}
			
			if(i==ejeY-1 and j==ejeX-1){
			gotoxy(j,i); 
			cout<<(char)188;	// ESQUINA INFERIOR IZQUIERDA
			}
			
		}
	
	}

	
	
}


//funcion que muestra las opciones del menu
char menuPrincipal(){
	
		Flecha flecha;
	
		system("cls");
		
		
		//gotoxy para añadir el mensaje a la posicion deseada, color para estetica

		gotoxy(0,0); color(h,79); cout << " [ESC] para salir "; 

		color(h,142);
		ventana(71,4,40,1);
		gotoxy(43,2); color(h,142); cout << " CLUB SOCIAL LOS PROPIOS ";
		
		color(h,142);
		ventana(41,9,9,6);
		gotoxy(10,7); color(h,143); cout<<" AFILIAR UN SOCIO AL CLUB "; color(h,138); cout << "[1] ";
		
		color(h,142);
		ventana(104,9,70,6);
		gotoxy(71,7); color(h,138); cout << " [2] "; color(h,143); cout<<"REGISTRAR ASOCIADO ";
		
		color(h,142);
		ventana(41,15,9,12);
		gotoxy(17,13); color(h,143); cout<<" REGISTRAR CONSUMO "; color(h,138); cout << "[3] ";
		
		color(h,142);
		ventana(104,15,70,12);
		gotoxy(71,13); color(h,138); cout << " [4] "; color(h,143); cout<<"PAGAR UNA FACTURA ";
		
		color(h,142);
		ventana(41,21,9,18);
		gotoxy(12,19);  color(h,143); cout<<"MODIFICAR FONDOS SOCIO"; color(h,138); cout << " [5] ";
		
		color(h,142);
		ventana(104,21,70,18);
		gotoxy(71,19); color(h,138); cout << " [6] "; color(h,143); cout<<"CANCELAR SUSCRIPCIONES";
		
		color(h,142);
		ventana(41,27,9,24);
		gotoxy(12,25);  color(h,143); cout<<"MODIFICAR DATOS USUARIO"; color(h,138); cout << " [7] ";
		
		color(h,142);
		ventana(104,27,70,24);
		gotoxy(71,25); color(h,138); cout << " [8] "; color(h,143); cout<<"CONSULTAS ";
		
	
		Creaflechas(flecha,41,7,0,33,6,41,67,7,25); 
		
		Flechamover(flecha, true, true);
		
		//llama a mi funcion que verifica la suma de ejes y retorna la opcion elegida
		return conexion_menuPrincipal(flecha);
	}

//función auxiliar para determinar la opción del usuario en el menu principal.	
char conexion_menuPrincipal(Flecha & flecha){
	
	switch (flecha.ejeX+flecha.ejeY){
		
		//Según el ejeX y el ejeY en donde el usuario de "ENTER" se hará una suma en la cual se basara la opción del usuario.
			
		//Opción 1.
		case 41+7: return '1';
		//Opción 2.		
		case 67+7: return '2';
		//Opción 3.
		case 41+13: return '3';
		//Opción 4.
		case 67+13: return '4';
		//Opción 5.
		case 41+19: return '5';
		//Opción 6.
		case 67+19: return '6';
		//Opción 7.
		case 41+25: return '7';
		//Opción 8.
		case 67+25: return '8';
	
			
	}
}

//función auxiliar estetica para el el registro de afiliar socio.
void ventana_afiliar_socio(){
	
	system("cls");
	
		
		color(h,142);
		ventana(76,3,40,0);
		gotoxy(43,1); color(h,142); cout << " APARTADO AFILIACION DE SOCIO ";
		
		color(h,142);
		ventana(118,25,2,3);
	
		
		color(h,142);
		ventana(114,16,30,5);
		gotoxy(60,5); color(h,142); cout << " DATOS PERSONALES ";
		
		gotoxy(32,7); color(h,143); cout << " NOMBRE Y APELLIDO: "; 
		
		gotoxy(32,9); color(h,143); cout << " N. IDENTIFICACION";
		
		color(h,139); cout << " [C.C]: ";
	
		gotoxy(32,11); color(h,143); cout << " EDAD: ";
		
		gotoxy(32,13); color(h,143); cout << " GENERO ";
		
		color(h,139); cout << "[M/F/O]: ";
		
		
		color(h,142);
		ventana(114,23,30,16);
		gotoxy(60,16); color(h,142); cout << " DATOS FINANCIEROS ";
		
		gotoxy(32,18); color(h,143); cout << " SUSCRIPCION ";
		
		color(h,139); cout << "[VIP - 1] "; 
		
		color(h,132); cout << "[REGULAR - 0]: ";
		
		gotoxy(32,20); color(h,143); cout << " FONDOS DE CUENTA: ";
			
		color(h,138); cout << "$";	
		
		color(h,143);
		ventana(118,30,2,25);
		gotoxy(47,25); color(h,142); cout << " MENSAJES DEL SISTEMA ";
	
}

//función auxiliar estetica para mostrar la ventana de buscar un socio por asociado.
void venta_asociado_buscar_socio(Socio socios[],Asociado asociados[], Contador &contador){
		
		system("cls");

		
		color(h,142);
		ventana(80,3,40,0);
		gotoxy(43,1); color(h,142); cout << " APARTADO AFILIACION DE ASOCIADOS ";
		
		color(h,142);
		ventana(80,9,40,6);
		gotoxy(42,7); color(h,138); cout << " [1] "; color(h,143); cout<<"BUSCAR POR NOMBRE Y APELLIDO";
		
		color(h,142);
		ventana(80,18,40,15);
		gotoxy(42,16); color(h,138); cout << " [2] "; color(h,143); cout<<"BUSCAR POR CEDULA DE CIUDADANIA";
		
		color(h,142);
		ventana(80,27,40,24);
		gotoxy(42,25); color(h,138); cout << " [3] "; color(h,143); cout<<"CANCELAR BUSQUEDA DEL SOCIO";

		//creamos un struct flecha.
		Flecha flecha;
		
		//llamamos a la función para crear las flechas.
		Creaflechas(flecha,37,7,0,0,9,37,37,7,25); 
		
		//llamamos a la función mover fe
		Flechamover(flecha, false, false);
		
		int socio_pos;
		bool socioUasociado;
		
		//la función de busqueda de usuario por nombre o cedula, devuelven un indice, el cual es retornado en socio_pos 
		//y el socioUasociado que se manda por referencia, mandara true = socio y false = asociado. 
		
		
		//Según el ejeX y el ejeY en donde el usuario de "ENTER" se hará una suma en la cual se basara la opción del usuario.
		switch(flecha.ejeX+flecha.ejeY){
		
			case 37+7: //BUSQUEDA POR NOMBRE
				
				socio_pos = busqueda_usuario_nombre(socios,asociados,contador,'S',socioUasociado);
		
			break;
			
			case 37+16: //BUSQUEDA POR CEDULA
				
				socio_pos = busqueda_usuario_cedula(socios,asociados,contador,'S',socioUasociado);
			
			break;
			
			case 37+25: //SALIR CANCELAR BUSQUEDA DE SOCIO
				
				return;
		
			break;
		
		}
	
		//Si el usuario cancela la busqueda, socio_pos retornara "-1", por lo tanto lo sacamos.
		if(socio_pos == -1){
			return;
		}
		else{
			
			//Si la función ventana_afiliar_asociado == true, se crearia un nuevo asociado. 
			if(ventana_afiliar_asociado(socios, asociados,contador, socio_pos, contador.N_asociados, 'N')){
				
				socios[socio_pos].cant_asociados++;
				asociados[contador.N_asociados].datos.estado = true;
				contador.N_asociados++;
			}
			//Si la función ventana_afiliar_asociado == false, se borrara la cedula del asociado al ser cancelada la suscripción.
			else{
				
				char borrador[10] = {' ', ' ',' ',' ',' ',' ',' ',' ',' ',' '};
				
				strcpy(asociados[contador.N_asociados].datos.cedula,borrador);
				strcpy(asociados[contador.N_asociados].cedula_socio,borrador);
				
			}
			
		}
		
	
}

//función auxiliar para buscar por cedula según la opción del char usuario = S socio, A asociado, T todos y mandamos por referencia a socioUasociado  true = socio,  false = asociado 
int busqueda_usuario_cedula(Socio socios[],Asociado asociados[], Contador &contador, char usuario, bool &socioUasociado){
	
	
		system("cls");

		
		color(h,142);
		ventana(80,3,40,0);
		gotoxy(43,1); color(h,142);
		
		//condicionales referentes a la opción del usuario.
		if(usuario == 'S'){
			cout << " APARTADO MOTOR DE BUSQUEDA SOCIOS ";
		}
		else if(usuario == 'A'){
			cout << " APARTADO DE BUSQUEDA DE ASOCIADOS";
		}
		else if(usuario == 'T'){
			cout << " APARTADO DE BUSQUEDA DE USUARIOS ";
		}
		 
		
		ventana(90,15,29,5);
		
		color(h,143);
		ventana(118,30,2,25);
		gotoxy(47,25); color(h,142); cout << " MENSAJES DEL SISTEMA ";
		
		gotoxy(40,7); color(h,142); cout << " BUSCAR POR CEDULA DE CIUDADANIA [C.C] ";
		
		//Una cadena auxiliar que guardar el valor que digite el usuario para luego comparar con la cedula de un socio, asociado o todos. 
		char auxCadena[50];
		//Bool para validar si hay una coincidencia de la cedula ingresa con algún socio o asociado. true = no hay false = hay
		bool coincidencia = true;
		
		do{
			//Llamamos a la función para borrar la información anterior a esta.
			borrador_mensajes(33, 9, 85, 11, 240);
			//Llamamos a la función para borrar la información anterior a esta.
			borrador_mensajes(3, 26, 116, 28, 0);
			gotoxy(5,27); color(h,4); cout << " Si desea cancelar la busqueda presione [ESC] , para seguir con la busqueda presione cualquier otra tecla "; 
			
			gotoxy(35,10);
			
			//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
			int tecla = _getch();
					
			if(tecla == 27){
				return -1;
			}
			
			//Llamamos a la función para borrar la información anterior a esta.
			borrador_mensajes(33, 9, 85, 11, 240);
			//Llamamos a la función para borrar la información anterior a esta.
			borrador_mensajes(3, 26, 116, 28, 0);
			gotoxy(5,27); color(h,10); cout << " Esta es una busqueda precisa, debe ingresar la cedula de la persona, si no se acuerda busque por nombre "; 
			//le pedimos al usuario la cedula a buscar
			gotoxy(35,10); color(h,240); fflush(stdin); gets(auxCadena);
			//Eliminamos los espacios del inicio y del final de la cadena.
			eliminar_Espacios(auxCadena);
			
			
				if(usuario == 'S' or usuario == 'T'){ //socio
						
						//ciclo para buscar si la cedula ingresada se encuentre entre los socios ya registrados.
						for(int i = 0; i < contador.N_socios; i++){
							//condición para ver si las cadenas son iguales.
							if(strcmp(auxCadena,socios[i].datos.cedula) == 0 and socios[i].datos.estado == true){
								socioUasociado = true;
								//se encontro coincidencia.
								coincidencia = false;
								//retornamos la posición del socio.
								return i;
							}
						}
					
				}
				if(usuario == 'A' or usuario == 'T'){ //asociado
						
						//ciclo para buscar si la cedula ingresada se encuentre entre los asociados ya registrados.
						for(int i = 0; i < contador.N_asociados; i++){
							//condición para ver si las cadenas son iguales.
							if(strcmp(auxCadena,asociados[i].datos.cedula) == 0 and asociados[i].datos.estado == true){
								socioUasociado = false;
								//se encontro coincidencia.
								coincidencia = false;
								//retornamos la posición del asociado.
								return i;
							}
						}
					
					
				}
			
			//si coincidencia == true, no hubo ninguna conincidencia.
			if(coincidencia){
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(33, 9, 85, 11, 240);
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(35,27); color(h,4); cout << " No se encontro ninguna cedula parecida "; 
				getch();
			}
			else{
				break;
			}
		
		}while(true);
	
}

//función auxiliar para buscar por nombre según la opción del char usuario = S socio, A asociado, T todos y mandamos por referencia a socioUasociado  true = socio,  false = asociado 
int busqueda_usuario_nombre(Socio socios[],Asociado asociados[], Contador &contador, char usuario, bool &socioUasociado){
	
		system("cls");

		
		color(h,142);
		ventana(80,3,40,0);
		gotoxy(42,1); color(h,142); 
		
	
		//condicionales referentes a la opción del usuario.
		if(usuario == 'S'){
			
			cout << "APARTADO MOTOR DE BUSQUEDA SOCIOS";
		}
		else if(usuario == 'A'){
		
			cout << "APARTADO DE BUSQUEDA DE ASOCIADOS";
		}
		else if(usuario == 'T'){
		
			cout << "APARTADO DE BUSQUEDA DE USUARIOS";
		}
		
		ventana(90,15,29,5);
		
		color(h,143);
		ventana(118,30,2,25);
		gotoxy(47,25); color(h,142); cout << " MENSAJES DEL SISTEMA ";
		
		gotoxy(45,7); color(h,142); cout << " BUSCAR POR NOMBRE Y APELLIDO ";
		
			//Una cadena auxiliar que guardar el nombre que digite el usuario para luego comparar con el nombre de un socio, asociado o todos. 
		char auxCadena[50];
		//Variables booleanas que validan las coincidencias que existen respecto a los socios y asociados ya registrados.
		bool coincidencias_socios[contador.N_socios];
		bool coincidencias_asociados[contador.N_asociados];
		
		
		//ciclo para buscar coincidencias de los nombres entre los socios y asociados registrados. 
		do{
			
			borrador_mensajes(33, 9, 85, 11, 240);
			borrador_mensajes(3, 26, 116, 28, 0);
			gotoxy(5,27); color(h,4); cout << " Si desea cancelar la busqueda presione [ESC] , para seguir con la busqueda presione cualquier otra tecla "; 
			
			gotoxy(35,10);
			
			//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
			int tecla = _getch();
					
			if(tecla == 27){
				return -1;
			}
			
			borrador_mensajes(33, 9, 85, 11, 240);
			borrador_mensajes(3, 26, 116, 28, 0);
			gotoxy(5,27); color(h,10); cout << " Para una busqueda mas precisa ingrese el nombre completo, para una busqueda general ingrese coincidencias "; 
			
			//le pedimos al usuario el la coincidencia a buscar
			gotoxy(35,10); color(h,240); fflush(stdin); gets(auxCadena);
			//eliminamos los espacios finales e iniciales de la cadena.
			eliminar_Espacios(auxCadena);
			
			//invocamos a la función para validar si la coincidencia se encuentra entre los nombre registarados. True = no encontrado false = encontrado.
			if(buscar_usuario_porNombre(socios,asociados,contador, auxCadena, coincidencias_socios,coincidencias_asociados,usuario)){
				
				borrador_mensajes(33, 9, 85, 11, 240);
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(15,27); color(h,4); cout << " No se encontro ninguna coincidencia, sea mas especifico o busque por cedula [C.C] "; 
				getch();
			}
			else{
				break;
			}
		
		}while(true);
		
		system("cls");
		
		//color principal de fondo
		system("color 87");

		color(h,142);
		ventana(82,3,40,0);
		gotoxy(42,1); color(h,142); cout << "APARTADO MOTOR DE BUSQUEDA USUARIOS";
		
		gotoxy(5,4); color(h,142); cout << " RESULTADOS DE LA BUSQUEDA, PARA ELEGIR UN USUARIO INGRESE SU INDICE [N]: ";
		
		gotoxy(2,6); color(h,142); cout << " INDICE ";
		gotoxy(12,6); color(h,142); cout << "| NOMBRE Y APELLIDOS ";
		gotoxy(65,6); color(h,142); cout << "| AFILIACION ";
		gotoxy(80,6); color(h,142); cout << "| CEDULA [C.C] ";
		
		int y = 8;
		int n_usuarios = 0;
		
		//Si el usuario es S, se imprimen los socios que tengan coincidencias.
		if(usuario == 'S' or usuario == 'T'){
			
			for(int i = 0; i < contador.N_socios; i++){
				//solo se mostraran los socios que coincidan y tengan la suscripcion activa
				if(coincidencias_socios[i] == true and socios[i].datos.estado == true){
					gotoxy(4,y); color(h,143); cout << "["<<++n_usuarios<<"]";
					gotoxy(14,y); color(h,143); cout << socios[i].datos.nombre;
					gotoxy(67,y); color(h,139); cout << "SOCIO";
					gotoxy(82,y); color(h,139); cout << socios[i].datos.cedula;
					y+=2;
				}
			}
		}
		
		//Si el usuario es A, se imprimen los asociados que tengan coincidencias.

		if(usuario == 'A' or usuario == 'T'){
		
			for(int i = 0; i < contador.N_asociados; i++){
				//solo se mostraran los asociados que coincidan y tengan la suscripcion activa
				if(coincidencias_asociados[i] == true and asociados[i].datos.estado == true){
					
					gotoxy(4,y); color(h,143); cout << "["<<++n_usuarios<<"]";
					gotoxy(14,y); color(h,143); cout << asociados[i].datos.nombre;
					gotoxy(67,y); color(h,132); cout << "ASOCIADO";
					gotoxy(82,y); color(h,132); cout << asociados[i].datos.cedula;
				
					y+=2;
				}
			}
		}
		
		
		
		char eleccion[3];
		
		//Ciclo para la eleeción del socio o asociado al cual quiere referenciarse el usuario.
		do{
			
			borrador_mensajes(0, 0, 39, 1, 136);
			
			gotoxy(0,0); color(h,79);  cout << " [ESC] para salir , para continuar "; 
			gotoxy(0,1); color(h,79);  cout << " presione cualquier otra tecla     ";
		
			borrador_mensajes(80, 4, 100, 4, 240);
			
			//pqueño gecth antes de pedir el dato para saber si desean cancelar la eleccion
			int tecla = _getch();
			
			gotoxy(82,4); color(h,240);
					
			if(tecla == 27){
				return -1;
			}
			
			borrador_mensajes(0, 0, 39, 1, 136);
			
			gotoxy(0,0); color(h,10); cout << " Elija un indice [N] ";
			
			//pedimos la elección al usuario.
			gotoxy(82,4); color(h,240); gets(eleccion);
			
			//validamos la opción sera un número y no una letra o caracter especial.
			if(es_Entero(eleccion)){
				
				borrador_mensajes(0, 0, 39, 1, 136);
			
				gotoxy(0,0); color(h,4); cout << " Entrada invalida, para seguir  "; 
				gotoxy(0,1); color(h,4); cout << " presione cualquier otra tecla  ";
				
				getch();
				continue;
			}
			
				//validamos que la elección sea valida.	
				if(atoi(eleccion) >= 1 and atoi(eleccion) <= n_usuarios){
					
					int cont = 0;
					
					if(usuario == 'S' or usuario == 'T'){
					
						for(int i = 0; i < contador.N_socios; i++){
							//contamos la cantidad de coincidencias en los socios
							if(coincidencias_socios[i] == true){
								cont++;
							}
							//Si la conincidencia coincide con la elección, se confimara que es un socio y retornara la posición del socio en cuestion.
							if(cont == atoi(eleccion)){
								socioUasociado = true;
								return i;
							}
						}
					
					}
					
					if(usuario == 'A' or usuario == 'T'){
					
						for(int i = 0;  i < contador.N_asociados; i++){
							//contamos la cantidad de coincidencias en los asociados
							if(coincidencias_asociados[i] == true){
								cont++;
							}
							//Si la conincidencia coincide con la elección, se confimara que es un asociado y retornara la posición del asociado en cuestion.
							if(cont == atoi(eleccion)){
								socioUasociado = false;
								return i;
							}	
							
						}
					}
						
				}
				//si no encuentra la elección
				else{
					borrador_mensajes(0, 0, 39, 1, 136);
						
					gotoxy(0,0); color(h,4); cout << " Entrada invalida, para seguir  "; 
					gotoxy(0,1); color(h,4); cout << " presione cualquier otra tecla  ";
							
					getch();
				}
			
			
		}while(true);
}

//función para afiliar un asociado, la cual recibe la posicón del socio al cual va ser afiliado.
bool ventana_afiliar_asociado(Socio socios[], Asociado asociados[],Contador &contador, int socio_pos, int asociado_pos, char usuario){
	
		system("cls");
		
		//usuario = N, nuevo asociado a afiliar, E, editar asociado ya registrado
		
		//color principal de fondo
		system("color 87");
		
		color(h,142);
		ventana(76,3,40,0);
		gotoxy(45,1); color(h,142); 
		
		if(usuario == 'N'){
			asociado_pos = contador.N_asociados;
			cout << " AFILIACION DE ASOCIADO ";
		}
		else{
			cout << " EDITAR INFO. DE ASOCIADO ";
			
			gotoxy(82,9); color(h,142); cout<<asociados[asociado_pos].datos.cedula;
		}
		
		
		
		color(h,142);
		ventana(116,25,4,3);
	
		
		color(h,142);
		ventana(54,25,4,3);
		gotoxy(20,3); color(h,142); cout << " DATOS DEL SOCIO ";
		
		color(h,143);
		ventana(27,17,6,5);
		//llamamos la función para mostrar la foto del socio en cuestión.
		fotos_perfil(7, 6,240,socios[socio_pos].foto);
		gotoxy(9,17); color(h,142); cout << "FOTO DEL SOCIO";
		
		gotoxy(30,5); color(h,143); cout << "CEDULA DE CIUDADANIA";
		gotoxy(30,7); color(h,139); cout << "C.C: "<< socios[socio_pos].datos.cedula;
		
		gotoxy(30,10); color(h,143); cout << "EDAD: "<< socios[socio_pos].datos.edad;
		
		gotoxy(30,13); color(h,143); cout << "TIPO DE SUSCRIPCION";
		
		//codincional que diferencia de un socio VIP Y REGULAR
		if(socios[socio_pos].suscripcion){
			gotoxy(30,15); color(h,139); cout << "[ V.I.P ]";
		}
		else{
			gotoxy(30,15); color(h,132); cout << "[ REGULAR ]";
		}
	
		gotoxy(6,19); color(h,143); cout << "NOMBRE Y APELLIDO DEL SOCIO" ;
		
		gotoxy(6,21); color(h,143); cout << socios[socio_pos].datos.nombre;
		
		
		gotoxy(75,3); color(h,142); cout << " DATOS DEL ASOCIADO ";
		
		
		gotoxy(55,5); color(h,143); cout << " NOMBRE Y APELLIDO: "; 
		
		gotoxy(55,9); color(h,143); cout << " N. IDENTIFICACION ";
		
		color(h,139); cout << "[C.C]: ";
		
		gotoxy(55,13); color(h,143); cout << " EDAD: ";
		
		gotoxy(55,17); color(h,143); cout << " GENERO ";
		
		color(h,139); cout << "[M/F/O]: ";
		
		gotoxy(55,21); color(h,143); cout << " PARENTESCO: ";
	
		color(h,143);
		ventana(118,30,2,25);
		gotoxy(47,25); color(h,142); cout << " MENSAJES DEL SISTEMA ";
		
		//apartado de ingresar nombre, while infinito para poder hacer todas las validaciones necesarias
		while(1){	
			
				gotoxy(75,5); color(h,142); cout << "                                       ";
		
				borrador_mensajes(3, 26, 116, 28, 0);
				
				if(usuario == 'N'){
					
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la afiliacion presione [ESC] , para seguir presione cualquier otra tecla "; 
				
				}
				else{
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la edicion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				}
				
				
				gotoxy(75,5);
				//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return false;
				}
				
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(40,27); color(h,10); cout << " INGRESE EL NOMBRE DEL ASOCIADO ";
				//le pedimos el nombre de asociado
				gotoxy(75,5); color(h,142); fflush(stdin); gets(asociados[asociado_pos].datos.nombre);
				//eliminamos los espacios finales e inicales del nombre. 
				eliminar_Espacios(asociados[asociado_pos].datos.nombre);
			
				bool no_num = false;
				
				//validacion del tamaño del nombre, no puede estar vacio ni superar 50 caracteres
				while(strlen(asociados[asociado_pos].datos.nombre) > 50 or strlen(asociados[asociado_pos].datos.nombre) <= 1){
					gotoxy(75,5); color(h,142); cout << "                                       ";
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(20,27); color(h,4); cout << " ENTRADA INVALIDA, 50 ES EL MAXIMO DE CARACTERES DEL NOMBRE Y 1 EL MINIMO";
					//le volvemos a pedir el nombre de asociado
					gotoxy(75,5); color(h,142); fflush(stdin); gets(asociados[asociado_pos].datos.nombre);
					eliminar_Espacios(asociados[asociado_pos].datos.nombre);
				}
				//validacion para que no ingresen numeros en el nombre
				while(es_Char(asociados[asociado_pos].datos.nombre)){
					gotoxy(75,5); color(h,142); cout << "                                       ";
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(40,27); color(h,4); cout << " ENTRADA INVALIDA, CARACTERES NUMERICOS";
					//si hay un caracter númerico volvemos true.
					no_num = true;
					//le volvemos a pedir el nombre de asociado
					gotoxy(75,5); color(h,142); fflush(stdin); gets(asociados[asociado_pos].datos.nombre);
					eliminar_Espacios(asociados[asociado_pos].datos.nombre);
				}
				
				if(no_num == true){
					continue;
				}
		
				break;
		
		}
		//se trasnforma en mayusculas toda la cadena para mejor manejo de la misma
		strupr(asociados[asociado_pos].datos.nombre);
		
		
			//INTRODUCIR IDENTIFICACION
	if(usuario == 'N'){
		
		bool cedula_noValida = false;
		
		do{
			
				gotoxy(82,9); color(h,142); cout << "                             ";
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(5,27); color(h,4); cout << " Si desea cancelar la afiliacion presione [ESC] , para seguir presione cualquier otra tecla "; 
				
				gotoxy(82,9);
				
				//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return false;
				}
				
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(20,27); color(h,10); cout << " INGRESAR NUMERO DE IDENTIFICACION DE LA PERSONA C.C [ 3 - 9 DIGITOS ] ";
				
				//un bool que mas abajo se mandara por referencia en la funcion validar_Cedula_Socio
				if(cedula_noValida == true){
					
					gotoxy(82,9); color(h,142); cout << "                             ";
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(30,27); color(h,4); cout << " LA CEDULA INGRESADA YA ESTA REGISTRADA ";
					gotoxy(82,9);
	
				}
			
			
				//se pide la cadena de cedula
				gotoxy(82,9); color(h,142); fflush(stdin); gets(asociados[asociado_pos].datos.cedula);
				
				eliminar_Espacios(asociados[asociado_pos].datos.cedula);
				
				//verificar que la cedula ingresada sea de tipo numerico
				while(es_Entero(asociados[asociado_pos].datos.cedula)){
					gotoxy(82,9); color(h,142); cout << "                             ";
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(30,27); color(h,4); cout << " ENTRADA INVALIDA, CARACTERES NO NUMERICOS";
					//le pedimos de vuelta la cedula. 
					gotoxy(82,9); color(h,142); fflush(stdin); gets(asociados[asociado_pos].datos.cedula);
					eliminar_Espacios(asociados[asociado_pos].datos.cedula);
				}
	
			
			//funcion que valida que no exista una cedula ya agregada en los datos de socios
		}while(validar_cedula_ingreso(socios, asociados ,contador, asociados[asociado_pos].datos.cedula,cedula_noValida));
		
	}
		
		
		
		//INTRODUCIR EDAD
		
		
		do{	
				gotoxy(63,13); color(h,142); cout << "                               ";
		
				borrador_mensajes(3, 26, 116, 28, 0);
					
				if(usuario == 'N'){
					
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la afiliacion presione [ESC] , para seguir presione cualquier otra tecla "; 
				
				}
				else{
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la edicion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				}
			
				gotoxy(63,13);
				
				//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return false;
				}
				
				gotoxy(63,13); color(h,142); cout << "                               ";
		
				
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(30,27); color(h,10); cout << " INTRODUCIR EDAD, LA EDAD VALIDA ES DE [ 18 - 120 ]";
				//le volvemos a pedir la edad
				gotoxy(63,13); color(h,142); fflush(stdin); gets(asociados[asociado_pos].datos.edad);	
				eliminar_Espacios(asociados[asociado_pos].datos.edad);
				
				//valida que la edad sea de caracter numerico
				if(es_Entero(asociados[asociado_pos].datos.edad)){
					continue;
				}
			
				//valida que la persona sea mayor de edad y no tan viejo juajauja
				if(atoi(asociados[asociado_pos].datos.edad)>=18 and atoi(asociados[asociado_pos].datos.edad) <= 120){
					break;
				}
				
		}while(true);
		
		//INTRODUCIR GENERO
			
		
		do{
			
				borrador_mensajes(3, 26, 116, 28, 0);
				
				if(usuario == 'N'){
					
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la afiliacion presione [ESC] , para seguir presione cualquier otra tecla "; 
				
				}
				else{
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la edicion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				}
			
				gotoxy(73,17);
				
				//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return false;
				}
				
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(20,27); color(h,10); cout << " INTRODUCIR GENERO M [masculino] - F [femenino] - O [otro]";
				//le pedimos el sexo.
				gotoxy(73,17); color(h,142); fflush(stdin); gets(asociados[asociado_pos].datos.sexo);
				eliminar_Espacios(asociados[asociado_pos].datos.sexo);
			
			//validar que sea letra
			while(es_Char(asociados[asociado_pos].datos.sexo)){
				gotoxy(73,17); color(h,142); cout << "                                    ";
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(30,27); color(h,4); cout << " ENTRADA INVALIDA, CARACTERES NUMERICOS";
				gotoxy(73,17); color(h,142); fflush(stdin);  gets(asociados[asociado_pos].datos.sexo);
				eliminar_Espacios(asociados[asociado_pos].datos.sexo);
			}
		
			//validar que sea un solo caracter
			while(strlen(asociados[asociado_pos].datos.sexo) > 1){
				gotoxy(73,17); color(h,142); cout << "                                    ";
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(20,27); color(h,4); cout << " ENTRADA INVALIDA, LAS OPCIONES SON M [masculino] - F [femenino] - O [otro] ";
				gotoxy(73,17); color(h,142); fflush(stdin);  gets(asociados[asociado_pos].datos.sexo);
				eliminar_Espacios(asociados[asociado_pos].datos.sexo);
			}
			
			//el caracter se pasa a mayuscula
			asociados[asociado_pos].datos.sexo[0] = toupper(asociados[asociado_pos].datos.sexo[0]);
			
			//se valida que este en el rango
			while(asociados[asociado_pos].datos.sexo[0] != 'M' and asociados[asociado_pos].datos.sexo[0] != 'F' and asociados[asociado_pos].datos.sexo[0] != 'O'){
				gotoxy(73,17); color(h,142); cout << "                                    ";
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(20,27); color(h,4); cout << " ENTRADA INVALIDA, LAS OPCIONES SON M [masculino] - F [femenino] - O [otro] ";
				//le volvemos a pedir el sexo.
				gotoxy(73,17); color(h,142); fflush(stdin);  gets(asociados[asociado_pos].datos.sexo);
				eliminar_Espacios(asociados[asociado_pos].datos.sexo);
				asociados[asociado_pos].datos.sexo[0] = toupper(asociados[asociado_pos].datos.sexo[0]);
			
			}
	
		//repite hasta la opción sea valida.	
		}while(asociados[asociado_pos].datos.sexo[0] != 'M' and asociados[asociado_pos].datos.sexo[0] != 'F' and asociados[asociado_pos].datos.sexo[0] != 'O');
		
		//INTRODUCIR PARENTEZCO
		
			while(1){	
			
				gotoxy(69,21); color(h,142); cout << "                                       ";
		
				borrador_mensajes(3, 26, 116, 28, 0);
				
				if(usuario == 'N'){
					
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la afiliacion presione [ESC] , para seguir presione cualquier otra tecla "; 
				
				}
				else{
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la edicion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				}
				gotoxy(69,21);
				//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return false;
				}
				
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(40,27); color(h,10); cout << " INGRESE EL PARENTESO DEL ASOCIADO CON EL SOCIO";
				//le pedimos el parantesco
				gotoxy(69,21); color(h,142); fflush(stdin); gets(asociados[asociado_pos].parentesco);
				
				eliminar_Espacios(asociados[asociado_pos].parentesco);
			
				bool no_num = false;
				
				//validacion del tamaño del nombre, no puede estar vacio ni superar 50 caracteres
				while(strlen(asociados[asociado_pos].parentesco) > 50 or strlen(asociados[asociado_pos].parentesco) <= 1){
					gotoxy(69,21); color(h,142); cout << "                                       ";
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(20,27); color(h,4); cout << " ENTRADA INVALIDA, 50 ES EL MAXIMO DE CARACTERES DEL NOMBRE Y 1 EL MINIMO";
					//le volvemos a a pedir el parantesco
					gotoxy(69,21); color(h,142); fflush(stdin); gets(asociados[asociado_pos].parentesco);
					eliminar_Espacios(asociados[asociado_pos].parentesco);
				}
				//validacion para que no ingresen numeros en el nombre
				while(es_Char(asociados[asociado_pos].parentesco)){
					gotoxy(69,21); color(h,142); cout << "                                       ";
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(40,27); color(h,4); cout << " ENTRADA INVALIDA, CARACTERES NUMERICOS";
					//si hay un caracter númerico mandamos true.
					no_num = true;
					//le volvemos a a pedir el parantesco
					gotoxy(69,21); color(h,142); fflush(stdin); gets(asociados[asociado_pos].parentesco);
					eliminar_Espacios(asociados[asociado_pos].parentesco);
				}
				
				if(no_num == true){
					continue;
				}
		
				break;
		
		}
		//se trasnforma en mayusculas toda la cadena para mejor manejo de la misma
		strupr(asociados[asociado_pos].parentesco);
		
		//se vincula la cedula del socio con el asociado
		strcpy(asociados[asociado_pos].cedula_socio,socios[socio_pos].datos.cedula);
	
	return true;
}


	
void cancelar_suscripcion_socio(Socio socios[],Asociado asociados[], Contador &contador){

	
		system("cls");
		
		color(h,142);
		ventana(80,3,40,0);
		gotoxy(44,1); color(h,142); cout << " APARTADO ELIMINAR USUARIO ";
		
		color(h,142);
		ventana(80,9,40,6);
		gotoxy(42,7); color(h,138); cout << " [1] "; color(h,143); cout<<"BUSCAR POR NOMBRE Y APELLIDO";
		
		color(h,142);
		ventana(80,18,40,15);
		gotoxy(42,16); color(h,138); cout << " [2] "; color(h,143); cout<<"BUSCAR POR CEDULA DE CIUDADANIA";
		
		color(h,142);
		ventana(80,27,40,24);
		gotoxy(42,25); color(h,138); cout << " [3] "; color(h,143); cout<<"CANCELAR BUSQUEDA DEL USUARIO";

		//creamos un struct flecha.
		Flecha flecha;
		
		//llamamos a la función para crear las flechas.
		Creaflechas(flecha,37,7,0,0,9,37,37,7,25); 
		
		//llamamos a la función mover fe
		Flechamover(flecha, false, false);
		
		int socio_pos;
		bool socioUasociado;
		//Según el ejeX y el ejeY en donde el usuario de "ENTER" se hará una suma en la cual se basara la opción del usuario.
		switch(flecha.ejeX+flecha.ejeY){
		
			case 37+7: //BUSQUEDA POR NOMBRE
				
				socio_pos = busqueda_usuario_nombre(socios,asociados,contador,'T',socioUasociado);
		
			break;
			
			case 37+16: //BUSQUEDA POR CEDULA
				
				socio_pos = busqueda_usuario_cedula(socios,asociados,contador,'T',socioUasociado);
			
			break;
			
			case 37+25: //SALIR CANCELAR BUSQUEDA DE SOCIO
				
				return;
		
			break;
		
		}
	
		//Si el usuario cancela la busqueda, socio_pos retornara "-1", por lo tanto lo sacamos.
		if(socio_pos == -1){
			return;
		}
		else{
			
			system("cls");
			system("color 87");
			
			
			color(h,142);
			ventana(84,25,31,3);
			gotoxy(48,3); color(h,142); cout << " DATOS DEL USUARIO ";
			
			if(socioUasociado == true){
					
				color(h,142);
				ventana(76,3,40,0);
				gotoxy(43,1); color(h,142); cout << " CANCELAR SUSCRIPCION SOCIO ";
				
				color(h,143);
				ventana(54,17,33,5);
				fotos_perfil(34, 6,240,socios[socio_pos].foto);
				gotoxy(35,17); color(h,143); cout << "FOTO DEL SOCIO";
				
				gotoxy(56,5); color(h,143); cout << "CEDULA DE CIUDADANIA";
				
				gotoxy(56,7); color(h,139); cout << "C.C: "<< socios[socio_pos].datos.cedula;
				
				gotoxy(56,10); color(h,143); cout << "EDAD: "<< socios[socio_pos].datos.edad;
				
				
				gotoxy(56,13); color(h,143); cout << "TIPO DE SUSCRIPCION";
				
				if(socios[socio_pos].suscripcion){
					gotoxy(56,15); color(h,139); cout << "[ V.I.P ]";
				}
				else{
					gotoxy(56,15); color(h,132); cout << "[ REGULAR ]";
				}
				
				gotoxy(35,19); color(h,138); cout << "FONDOS: "<< socios[socio_pos].fondos; 
				
				gotoxy(35,21); color(h,143); cout << "NOMBRE Y APELLIDO DEL SOCIO" ;
				
				gotoxy(35,23); color(h,143); cout << socios[socio_pos].datos.nombre;
				
				color(h,143);
				ventana(118,30,2,25);
				gotoxy(47,25); color(h,142); cout << " MENSAJES DEL SISTEMA ";
				
					gotoxy(20,27); color(h,10); cout << " [1] DESEO CANCELAR O [2] NO DESEO CANCELAR ";
						
					gotoxy(87,4); color(h,142); cout << " DESEA CANCELAR LA SUSCRIPCION";
						
					gotoxy(97,6); color(h,142); cout << " 1. SI ";
						
					gotoxy(97,8); color(h,142); cout << " 2. NO ";
					
					gotoxy(87,10); color(h,142); cout << " DIGITE UNA OPCION: "; 
				
				char opc; 
					
					while(1){
						color(h,142);
						ventana(118,12,86,3);
						//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(107,10); color(h,142); cout << "   ";
						//Imprimimos una información de ayuda al usuario. 
						gotoxy(5,27); color(h,4); cout << " Si no desea cancelar la suscripcion presione [ESC] , para seguir presione cualquier otra tecla "; 
						
						gotoxy(52,7);
						//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
						int tecla = _getch();
						
						//Validamos que si el usurio presiones "ESC", se cancela el registro de la suscripción.	
						if(tecla == 27){
							return;
						}
						
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(107,10); color(h,142); cout << "   ";
						//Imprimimos una información de ayuda al usuario. 
						gotoxy(3,27); color(h,10); cout << " al eliminar su cuenta, se eliminaran todos los asociados a su nombre, si esta de acuerdo digite [1] "; 
						
							
						gotoxy(107,10); color(h,142); cin>>opc;
					
						
						if(opc != '1' and opc != '2'){
							borrador_mensajes(3, 26, 116, 28, 0);
							gotoxy(107,10); color(h,142); cout << "   ";
							gotoxy(30,27); color(h,4); cout << " OPCION INVALIDA, DIGITE UNA VALIDA [1] O [2]";
							getch();	
						}else{
							
							if(opc == '1' and socios[socio_pos].deuda > 0 ){
								borrador_mensajes(3, 26, 116, 28, 0);
								gotoxy(107,10); color(h,142); cout << "   ";
								gotoxy(30,27); color(h,4); cout << " TRAMITE INVALIDO, SOCIO CON FACTURAS PENDIENTES POR PAGAR ";
								getch();
							}
							else{
								
								break;
							}
							
						}
						
					}
	
					switch(opc){
						
						case '1':
							
							socios[socio_pos].datos.estado = false;
							 
							for(int i = 0; i < contador.N_asociados; i++){
								
								if(strcmp(socios[socio_pos].datos.cedula,asociados[i].cedula_socio) == 0){
									asociados[i].datos.estado = false;
								}
							}
							
							color(h,142);
							ventana(118,20,86,13);
										
											//INTRODUCIR AÑO
							while(1){
							
								setlocale(LC_ALL,"spanish");
								gotoxy(94,13); color(h,142); cout << " FECHA DE RETIRO ";
								gotoxy(87,14); color(h,142); cout << " AÑO: ";
								gotoxy(87,16); color(h,142); cout << " MES: ";
								gotoxy(87,18); color(h,142); cout << " DIA: ";
								setlocale(LC_ALL,"C");
							
								gotoxy(95,14); color(h,142); cout << "         ";
						
								borrador_mensajes(3, 26, 116, 28, 0);
								gotoxy(5,27); color(h,4); cout << " Si desea cancelar la fecha presione [ESC] , para seguir presione cualquier otra tecla "; 
								
								gotoxy(95,14);
								//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
								int tecla = _getch();
									
								if(tecla == 27){
									return;
								}
								
								borrador_mensajes(3, 26, 116, 28, 0);
								gotoxy(25,27); color(h,10); cout << " Ingrese el año en que se retira [1900] - [2100] ";
								
								gotoxy(95,14); color(h,142); fflush(stdin); gets(socios[socio_pos].year);
								
								eliminar_Espacios(socios[socio_pos].year);
							
								if(es_Entero(socios[socio_pos].year)){
									continue;
								}
								
								if(atoi(socios[socio_pos].year) > 1900 and atoi(socios[socio_pos].year) < 2100){	
									break;
								}
								
								
								
									
							}
							//INTRODUCIR MES
							while(1){
							
								setlocale(LC_ALL,"spanish");
								gotoxy(94,13); color(h,142); cout << " FECHA DE RETIRO ";
								gotoxy(87,14); color(h,142); cout << " AÑO: ";
								gotoxy(87,16); color(h,142); cout << " MES: ";
								gotoxy(87,18); color(h,142); cout << " DIA: ";
								setlocale(LC_ALL,"C");
							
								gotoxy(95,16); color(h,142); cout << "         ";
						
								borrador_mensajes(3, 26, 116, 28, 0);
								gotoxy(5,27); color(h,4); cout << " Si desea cancelar la fecha presione [ESC] , para seguir presione cualquier otra tecla "; 
								
								gotoxy(95,16);
								//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
								int tecla = _getch();
									
								if(tecla == 27){
									return;
								}
								
								borrador_mensajes(3, 26, 116, 28, 0);
								gotoxy(25,27); color(h,10); cout << " Ingrese el mes [1-12] que se retira";
								
								gotoxy(95,16); color(h,142); fflush(stdin); gets(socios[socio_pos].mes);
								
								eliminar_Espacios(socios[socio_pos].mes);
							
								if(es_Entero(socios[socio_pos].mes)){
									continue;
								}
								
								if(!(atoi(socios[socio_pos].mes) >= 1 and atoi(socios[socio_pos].mes) <= 12)){
									
									borrador_mensajes(3, 26, 116, 28, 0);
									gotoxy(95,16); color(h,142); cout << "       ";
									gotoxy(30,27); color(h,4); cout << " MES INVALIDO, DIGITE UNO VALIDO [1-12]";
									getch();
									continue;
								}
								
								break;
						}
						
						//INTRODUCIR DIA
						while(1){
							
								setlocale(LC_ALL,"spanish");
								gotoxy(94,13); color(h,142); cout << " FECHA DE RETIRO ";
								gotoxy(87,14); color(h,142); cout << " AÑO: ";
								gotoxy(87,16); color(h,142); cout << " MES: ";
								gotoxy(87,18); color(h,142); cout << " DIA: ";
								setlocale(LC_ALL,"C");
							
								gotoxy(95,18); color(h,142); cout << "         ";
						
								borrador_mensajes(3, 26, 116, 28, 0);
								gotoxy(5,27); color(h,4); cout << " Si desea cancelar la fecha presione [ESC] , para seguir presione cualquier otra tecla "; 
								
								gotoxy(95,18);
								//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
								int tecla = _getch();
									
								if(tecla == 27){
									return;
								}
								
								borrador_mensajes(3, 26, 116, 28, 0);
								gotoxy(25,27); color(h,10); cout << " Ingrese el dia [1 - 31] que se retiro ";
								
								gotoxy(95,18); color(h,142); fflush(stdin); gets(socios[socio_pos].dia);
								
								eliminar_Espacios(socios[socio_pos].dia);
							
								if(es_Entero(socios[socio_pos].dia)){
									continue;
								}
								
								if(!(atoi(socios[socio_pos].dia) >= 1 and atoi(socios[socio_pos].dia) <= 31)){
									borrador_mensajes(3, 26, 116, 28, 0);
									gotoxy(95,18); color(h,142); cout << "       ";
									gotoxy(30,27); color(h,4); cout << " DIA INVALIDO, DIGITE UNO VALIDO [1-31]";
									getch();
									continue;
								}
								
								break;
						}
											
						break;
						
						case '2':
								
							return;
								
							break;	
							
						}
					
				}
				else{
					color(h,142);
					ventana(76,3,40,0);
					gotoxy(49,1); color(h,142); cout << " ELIMINAR ASOCIADO ";
					
					gotoxy(48,5); color(h,143); cout << "CEDULA DE CIUDADANIA";
					
					gotoxy(54,8); color(h,139); cout << "C.C: "<< asociados[socio_pos].datos.cedula;
					
					gotoxy(54,11); color(h,143); cout << "EDAD: "<< asociados[socio_pos].datos.edad;
					
					gotoxy(42,14); color(h,143); cout << "NOMBRE Y APELLIDO DEL ASOCIADO" ;
					
					gotoxy(55,17); color(h,143); cout << asociados[socio_pos].datos.nombre;
					
					gotoxy(53,20); color(h,143); cout << "PARENTESCO ";
					
					gotoxy(50,23); color(h,143); cout << asociados[socio_pos].parentesco;
					
					color(h,143);
				ventana(118,30,2,25);
				gotoxy(47,25); color(h,142); cout << " MENSAJES DEL SISTEMA ";
				
					gotoxy(20,27); color(h,10); cout << " [1] DESEO ELIMINAR O [2] NO DESEO ELIMINAR ";
						
					gotoxy(87,4); color(h,142); cout << " DESEA ELIMINAR ASOCIADO";
						
					gotoxy(97,6); color(h,142); cout << " 1. SI ";
						
					gotoxy(97,8); color(h,142); cout << " 2. NO ";
					
					gotoxy(87,10); color(h,142); cout << " DIGITE UNA OPCION: "; 
				
				char opc; 
					
					while(1){
						
						color(h,142);
						
						ventana(118,12,86,3);
						
						//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(107,10); color(h,142); cout << "   ";
						//Imprimimos una información de ayuda al usuario. 
						gotoxy(5,27); color(h,4); cout << " Si no desea eliminar el asociado presione [ESC] , para seguir presione cualquier otra tecla "; 
						
						gotoxy(52,7);
						//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
						int tecla = _getch();
						
						//Validamos que si el usurio presiones "ESC", se cancela el registro de la suscripción.	
						if(tecla == 27){
							return;
						}
						
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(107,10); color(h,142); cout << "   ";
						//Imprimimos una información de ayuda al usuario. 
						gotoxy(5,27); color(h,10); cout << " para eliminar su cuenta, ingrese [1] "; 
						
					
						gotoxy(107,10); color(h,142); cin>>opc;
					
						
						if(opc != '1' and opc != '2'){
							borrador_mensajes(3, 26, 116, 28, 0);
							gotoxy(107,10); color(h,142); cout << "   ";
							gotoxy(30,27); color(h,4); cout << " OPCION INVALIDA, DIGITE UNA VALIDA [1] O [2]";
							getch();	
						}else{
						
							if(opc == '1' and socios[socio_pos].deuda > 0 ){
								borrador_mensajes(3, 26, 116, 28, 0);
								gotoxy(107,10); color(h,142); cout << "   ";
								gotoxy(30,27); color(h,4); cout << " TRAMITE INVALIDO, SU SOCIO TIENE FACTURAS PENDIENTES POR PAGAR ";
								getch();
							}
							else{
								
								break;
							}
							
						}
						
					}
					
					switch(opc){
						case '1':
							
							for(int i = 0;  i < contador.N_socios; i++){
								
								if(strcmp(asociados[socio_pos].cedula_socio,socios[i].datos.cedula) == 0){
									socios[i].cant_asociados--;
								}
								
							}
							
							asociados[socio_pos].datos.estado = false;
						
							break;
						case '2':
							
							return;
							
							break;
				}
			
					getch();	
				}
		
			}
		
		}
		
void estado_de_cuenta(Socio socios[],Asociado asociados[],Contador &contador, Factura facturas[]){
				system("cls");
				system("color 87");
				
				color(h,142);
				ventana(80,3,40,0);
				gotoxy(42,1); color(h,142); cout << " APARTADO ESTADO DE CUENTA  ";
				
				color(h,142);
				ventana(80,9,40,6);
				gotoxy(42,7); color(h,138); cout << " [1] "; color(h,143); cout<<"BUSCAR POR NOMBRE Y APELLIDO";
				
				color(h,142);
				ventana(80,18,40,15);
				gotoxy(42,16); color(h,138); cout << " [2] "; color(h,143); cout<<"BUSCAR POR CEDULA DE CIUDADANIA";
				
				color(h,142);
				ventana(80,27,40,24);
				gotoxy(42,25); color(h,138); cout << " [3] "; color(h,143); cout<<"CANCELAR BUSQUEDA DEL SOCIO";
		
				
				Flecha flecha;
				//llamamos a la función para crear las flechas.
				Creaflechas(flecha,37,7,0,0,9,37,37,7,25); 
				
				//llamamos a la función mover fe
				Flechamover(flecha, false, false);
				
				int socio_pos;
				bool socioUasociado;
				//Según el ejeX y el ejeY en donde el usuario de "ENTER" se hará una suma en la cual se basara la opción del usuario.
				switch(flecha.ejeX+flecha.ejeY){
				
					case 37+7: //BUSQUEDA POR NOMBRE
						
						socio_pos = busqueda_usuario_nombre(socios,asociados,contador,'S',socioUasociado);
				
					break;
					
					case 37+16: //BUSQUEDA POR CEDULA
						
						socio_pos = busqueda_usuario_cedula(socios,asociados,contador,'S',socioUasociado);
					
					break;
					
					case 37+25: //SALIR CANCELAR BUSQUEDA DE SOCIO
						
						return;
				
					break;
				
				}
			
				//Si el usuario cancela la busqueda, socio_pos retornara "-1", por lo tanto lo sacamos.
				if(socio_pos == -1){
					return;
				}
				else{
					system("cls");
					
					system("color 87");
						
					color(h,142);
					ventana(76,3,40,0);
					gotoxy(45,1); color(h,142); cout << " ESTADO DE CUENTA ";
					
					color(h,142);
					ventana(116,25,4,3);
				
					
					color(h,142);
					ventana(54,25,4,3);
					gotoxy(20,3); color(h,142); cout << " DATOS DEL SOCIO ";
					
					color(h,143);
					ventana(27,17,6,5);
					//llamamos la función para mostrar la foto del socio en cuestión.
					fotos_perfil(7, 6,240,socios[socio_pos].foto);
					gotoxy(9,17); color(h,142); cout << "FOTO DEL SOCIO";
					
					gotoxy(30,5); color(h,143); cout << "CEDULA DE CIUDADANIA";
					gotoxy(30,7); color(h,139); cout << "C.C: "<< socios[socio_pos].datos.cedula;
					
					gotoxy(30,10); color(h,143); cout << "EDAD: "<< socios[socio_pos].datos.edad;
					
					gotoxy(30,13); color(h,143); cout << "TIPO DE SUSCRIPCION";
					
					//codincional que diferencia de un socio VIP Y REGULAR
					if(socios[socio_pos].suscripcion){
						gotoxy(30,15); color(h,139); cout << "[ V.I.P ]";
					}
					else{
						gotoxy(30,15); color(h,132); cout << "[ REGULAR ]";
					}
				
					gotoxy(6,19); color(h,143); cout << "NOMBRE Y APELLIDO DEL SOCIO" ;
					
					gotoxy(6,21); color(h,143); cout << socios[socio_pos].datos.nombre;
					
					gotoxy(6,23); color(h,138); cout << "FONDOS DISPONIBLES: $"<<std::fixed<<std::setprecision(2)<<(socios[socio_pos].fondos-socios[socio_pos].deuda);
						
					gotoxy(72,3); color(h,142); cout<< " FACTURAS DEL SOCIO";
					gotoxy(55,5); color(h,142); cout << "| INDICE ";
					gotoxy(65,5); color(h,142); cout << "| CONCEPTO";
					gotoxy(85,5); color(h,142); cout << "| FECHA";
					gotoxy(94,5); color(h,142); cout << " | VALOR"; 
					
					int y = 6;
					int n_facts = 0;
		
			
						for(int i = 0; i < contador.N_facturas; i++){
								
							if(strcmp(facturas[i].cedula_consumidor,socios[socio_pos].datos.cedula) == 0 and facturas[i].estado == true){
								
								gotoxy(58,y); color(h,139); cout << "["<<++n_facts<<"]";
								gotoxy(67,y); color(h,143); cout << facturas[i].concepto;
								gotoxy(85,y); color(h,143); cout << facturas[i].dia <<"/"<< facturas[i].mes <<"/"<< facturas[i].year;
								gotoxy(97,y); color(h,138); cout <<"$"<<std::fixed<<std::setprecision(2)<<facturas[i].valor;
								
								y+=2;
								
							}
					
						}
					getch();
		}
}

//función auxiliar de estetica para la realización del registro de facturas o consumos de un socio o asaciado.
void ventana_registrar_consumo(Socio socios[],Factura facturas[],Asociado asociados[], Contador &contador){
	
		system("cls");

		
		color(h,142);
		ventana(80,3,40,0);
		gotoxy(45,1); color(h,142); cout << " APARTADO REGISTRAR CONSUMO ";
		
		gotoxy(30,5); color(h,142); cout << " Para realizar una factura primero debe buscar a la  ";
		gotoxy(30,7); color(h,142); cout << " persona que realizara el consumo para poder asignarselo ";
		
		color(h,142);
		ventana(80,13,40,10);
		gotoxy(42,11); color(h,138); cout << " [1] "; color(h,143); cout<<"BUSCAR POR NOMBRE Y APELLIDO";
		
		color(h,142);
		ventana(80,20,40,17);
		gotoxy(42,18); color(h,138); cout << " [2] "; color(h,143); cout<<"BUSCAR POR CEDULA DE CIUDADANIA";
		
		color(h,142);
		ventana(80,27,40,24);
		gotoxy(42,25); color(h,138); cout << " [3] "; color(h,143); cout<<"CANCELAR CREACION FACTURA";
	
		//creamos la flecha de selección.
		Flecha flecha;
		
		Creaflechas(flecha,37,11,0,0,7,37,37,11,25); 
		
		Flechamover(flecha, false, false);
		
		//guardamos la ubicación del usuario.
		int user_pos;
		bool socioUasociado;
		
		switch(flecha.ejeX+flecha.ejeY){
		
			case 37+11: //BUSQUEDA POR NOMBRE
				
				user_pos = busqueda_usuario_nombre(socios,asociados,contador,'T',socioUasociado);
				
		
			break;
			
			case 37+18: //BUSQUEDA POR CEDULA
				
				user_pos = busqueda_usuario_cedula(socios,asociados,contador,'T',socioUasociado);
			
			break;
			
			case 37+25: //SALIR CANCELAR REGISTRO DE CONSUMO
				
				return;
		
			break;
		
		}
		
		if(user_pos == -1){
			return;
		}
		else{
			
			//llamamos la función registrar consumo para hacar una nueva factura.
			if(registrar_consumo(socios,asociados,facturas,contador, user_pos, socioUasociado)){
				
				facturas[contador.N_facturas].id_factura = contador.N_facturas;
				facturas[contador.N_facturas].estado = true;		
				contador.N_facturas++;			
			}else{
				char borrador[10] = {' ', ' ',' ',' ',' ',' ',' ',' ',' ',' '};
				strcpy(facturas[contador.N_facturas].cedula_consumidor,borrador);
			}
			
		
		}
	
	
	
}
//función para registrar una factura o concsumo de para de un socio o asociado.
bool registrar_consumo(Socio socios[],Asociado asociados[],Factura facturas[],Contador &contador, int user_pos,bool socioUasociado){
	
	
		system("cls");
		
		//color principal de fondo
		system("color 87");
		
		color(h,142);
		ventana(76,3,40,0);
		gotoxy(45,1); color(h,142); cout << " FACTURA DE VENTA ";
		
		color(h,143);
		ventana(118,30,2,25);
		gotoxy(47,25); color(h,142); cout << " MENSAJES DEL SISTEMA ";
		borrador_mensajes(3, 26, 116, 28, 0);
		
		color(h,142);
		ventana(118,25,2,3);
	
		
		color(h,142);
		ventana(40,25,2,3);
		gotoxy(5,3); color(h,142); cout << " DATOS DEL CONSUMIDOR ";
		
		
		
		if(socioUasociado){
			
			//se enlaza la cedula del consumidor de la factura con el comprador socio
			
			strcpy(facturas[contador.N_facturas].cedula_consumidor,socios[user_pos].datos.cedula);
			
			gotoxy(4,5); color(h,143); cout << "CEDULA DE CIUDADANIA";
			gotoxy(4,7); color(h,139); cout << "C.C: "<< socios[user_pos].datos.cedula;
			
			gotoxy(4,10); color(h,143); cout << "TIPO DE AFILIACION: ";
			
			color(h,139); cout << "SOCIO";
			
			gotoxy(4,13); color(h,143); cout << "TIPO DE SUSCRIPCION";
			
			if(socios[user_pos].suscripcion){
				gotoxy(4,15); color(h,139); cout << "[ V.I.P ]";
			}
			else{
				gotoxy(4,15); color(h,132); cout << "[ REGULAR ]";
			}
		
			gotoxy(4,19); color(h,143); cout << "NOMBRE Y APELLIDO DEL SOCIO" ;
			
			gotoxy(4,21); color(h,143); cout << socios[user_pos].datos.nombre;
			
			
			color(h,142);
			gotoxy(45,10); color(h,143); cout << " CEDULA DEL CONSUMIDOR: ";
			
			color(h,139); cout << "C.C "<<socios[user_pos].datos.cedula;
			
				
		}
		else{
			
			
				//se enlaza la cedula del consumidor de la factura con el comprador asociado
			
			strcpy(facturas[contador.N_facturas].cedula_consumidor,asociados[user_pos].cedula_socio);
			
			
			gotoxy(4,5); color(h,143); cout << "CEDULA DE CIUDADANIA";
			gotoxy(4,7); color(h,139); cout << "C.C: "<< asociados[user_pos].datos.cedula;
			
			gotoxy(4,10); color(h,143); cout << "TIPO DE AFILIACION: ";
			
			color(h,132); cout << " ASOCIADO ";
			
			gotoxy(4,13); color(h,143); cout << "CEDULA DEL SOCIO VINCULADO";
			gotoxy(4,15); color(h,139); cout << "C.C: "<< asociados[user_pos].cedula_socio;
			
			gotoxy(4,19); color(h,143); cout << "NOMBRE Y APELLIDO DEL ASOCIADO" ;
			
			gotoxy(4,21); color(h,143); cout << asociados[user_pos].datos.nombre;
			
			color(h,142);
			gotoxy(45,10); color(h,143); cout << " CEDULA DEL CONSUMIDOR: ";
			
			color(h,139); cout << "C.C "<<asociados[user_pos].datos.cedula;
		}
		
		
		color(h,142);
		gotoxy(55,3); color(h,142); cout << " DATOS DE LA FACTURA ";
		
		color(h,142);
		gotoxy(45,7); color(h,143); cout << " NUMERO DE FACTURA: ";
		
		color(h,139); cout << "#"<<contador.N_facturas;
		
		color(h,142);
		gotoxy(45,16); color(h,143); cout << " CONCEPTO: ";
		
		color(h,142);
		gotoxy(45,19); color(h,138); cout << " VALOR CONSUMO: $";
		
		//INTRODUCIR AÑO
		while(1){
			
				setlocale(LC_ALL,"spanish");
				gotoxy(45,13); color(h,143); cout << " AÑO: ";
				gotoxy(60,13); color(h,143); cout << " MES: ";
				gotoxy(75,13); color(h,143); cout << " DIA: ";
				setlocale(LC_ALL,"C");
			
				gotoxy(52,13); color(h,142); cout << "         ";
		
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(5,27); color(h,4); cout << " Si desea cancelar la venta presione [ESC] , para seguir presione cualquier otra tecla "; 
				
				gotoxy(52,13);
				//pqueño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return false;
				}
				
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(25,27); color(h,10); cout << " Ingrese el año en que se realizó la factura ";
				
				gotoxy(52,13); color(h,142); fflush(stdin); gets(facturas[contador.N_facturas].year);
				
				eliminar_Espacios(facturas[contador.N_facturas].year);
			
				if(es_Entero(facturas[contador.N_facturas].year)){
					continue;
				}
				
				if(atoi(facturas[contador.N_facturas].year) > 1900 and atoi(facturas[contador.N_facturas].year) < 2100){
					break;
				}
				
				
		}
		//INTRODUCIR MES
		while(1){
			
				setlocale(LC_ALL,"spanish");
				gotoxy(45,13); color(h,143); cout << " AÑO: ";
				gotoxy(60,13); color(h,143); cout << " MES: ";
				gotoxy(75,13); color(h,143); cout << " DIA: ";
				setlocale(LC_ALL,"C");
			
				gotoxy(67,13); color(h,142); cout << "         ";
		
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(5,27); color(h,4); cout << " Si desea cancelar la venta presione [ESC] , para seguir presione cualquier otra tecla "; 
				
				gotoxy(67,13);
				//pqueño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return false;
				}
				
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(25,27); color(h,10); cout << " Ingrese el mes [1-12] en que se realizó la factura ";
				
				gotoxy(67,13); color(h,142); fflush(stdin); gets(facturas[contador.N_facturas].mes);
				
				eliminar_Espacios(facturas[contador.N_facturas].mes);
			
				if(es_Entero(facturas[contador.N_facturas].mes)){
					continue;
				}
				
				if(!(atoi(facturas[contador.N_facturas].mes) >= 1 and atoi(facturas[contador.N_facturas].mes) <= 12)){
					continue;
				}
				
				break;
		}
		
		//INTRODUCIR DIA
		while(1){
			
				setlocale(LC_ALL,"spanish");
				gotoxy(45,13); color(h,143); cout << " AÑO: ";
				gotoxy(60,13); color(h,143); cout << " MES: ";
				gotoxy(75,13); color(h,143); cout << " DIA: ";
				setlocale(LC_ALL,"C");
			
				gotoxy(82,13); color(h,142); cout << "         ";
		
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(5,27); color(h,4); cout << " Si desea cancelar la venta presione [ESC] , para seguir presione cualquier otra tecla "; 
				
				gotoxy(82,13);
				//pqueño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return false;
				}
				
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(25,27); color(h,10); cout << " Ingrese el dia [1 - 31] en que se realizó la factura ";
				
				gotoxy(82,13); color(h,142); fflush(stdin); gets(facturas[contador.N_facturas].dia);
				
				eliminar_Espacios(facturas[contador.N_facturas].dia);
			
				if(es_Entero(facturas[contador.N_facturas].dia)){
					continue;
				}
				
				if(!(atoi(facturas[contador.N_facturas].dia) >= 1 and atoi(facturas[contador.N_facturas].dia) <= 31)){
					continue;
				}
				
				break;
		}
		
		
		// INTRODUCIR CONCEPTO
		
			while(1){	
			
				gotoxy(57,16); color(h,142); cout << "                                       ";
		
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(5,27); color(h,4); cout << " Si desea cancelar la venta presione [ESC] , para seguir presione cualquier otra tecla "; 
				
				gotoxy(57,16);
				//pqueño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return false;
				}
				
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(5,27); color(h,10); cout << " Ingrese el concepto de la factura, ejemplo: 4 coca-colas, 3 hamburguesas doble carne. ";
				
				gotoxy(57,16); color(h,142); fflush(stdin); gets(facturas[contador.N_facturas].concepto);
				
				eliminar_Espacios(facturas[contador.N_facturas].concepto);
				
				//validacion del tamaño del concepto,
				if(strlen(facturas[contador.N_facturas].concepto) <= 1 or strlen(facturas[contador.N_facturas].concepto) > 50){
					gotoxy(57,16); color(h,142); cout << "                                       ";
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(20,27); color(h,4); cout << " ENTRADA INVALIDA, 50 ES EL MAXIMO DE CARACTERES DEL NOMBRE Y 1 EL MINIMO";
					gotoxy(57,16); color(h,142); fflush(stdin); gets(facturas[contador.N_facturas].concepto);
					eliminar_Espacios(facturas[contador.N_facturas].concepto);
				}
				else{
					break;
				}
		
		}
		
		
		
		//INGRESAR VALOR
		
		
			/*
			cuando un usuario va realizar un consumo hay que validar que hayan los fondos suficienmtes para poder ser pagada la factura
			, al momomento de realizarse se guardara la deuda y la factura quedara con estado de PENDIENTE 	
		*/
		
		char numAux[32]; //la cant de digitos de un numero float son 32 bit =  32 digitos incluyendo el signo

		//socio
		if(socioUasociado){
			
			do{
				
				do{
					
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la venta presione [ESC] , para seguir presione cualquier otra tecla "; 
				
					gotoxy(63,19); color(h,142); cout << "                              ";		
				
					gotoxy(63,19);
					
					int tecla = _getch();
						
					if(tecla == 27){
					
						return false;
					}
					
				
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(25,27); color(h,10); cout << " PARA QUE LA COMPRA SEA VALIDA, EL SOCIO DEBE TENER LOS FONDOS NECESARIOS ";	
					
					
					gotoxy(63,19); color(h,142); cout << "                              ";		
					gotoxy(63,19); color(h,138); fflush(stdin); gets(numAux);	
					eliminar_Espacios(numAux);
					
				}while(validar_float(numAux));
				
				float disponible = socios[user_pos].fondos - socios[user_pos].deuda;
				
				if(atof(numAux) <= 0){
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(20,27); color(h,4); cout << " LA FACTURA NO PUEDE TENER VALORES NEGATIVOS O CERO";	
						getch();
				}
				else if(((socios[user_pos].fondos - socios[user_pos].deuda) - atof(numAux)) < 0 ){
					
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(20,27); color(h,4); cout << " FONDOS INSUFICIENTES, SU DISPONIBLE ES: $"<< std::fixed << std::setprecision(2) << disponible;	
						getch();
				}
				else{
					break;
				}
					
			}while(true);
			
			//se acumula en la deuda
			socios[user_pos].deuda += atof(numAux); 
			facturas[contador.N_facturas].valor = atof(numAux);
		}
		else{ //asociado
			
			do{
				do{
					
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(5,27); color(h,4); cout << " Si desea cancelar la venta presione [ESC] , para seguir presione cualquier otra tecla "; 
					
						gotoxy(63,19); color(h,142); cout << "                              ";		
					
						gotoxy(63,19);
						
						int tecla = _getch();
							
						if(tecla == 27){
						
							return false;
						}
						
					
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(25,27); color(h,10); cout << " PARA QUE LA COMPRA SEA VALIDA, EL SOCIO DEBE TENER LOS FONDOS NECESARIOS ";	
						
						
						gotoxy(63,19); color(h,142); cout << "                              ";		
						gotoxy(63,19); color(h,138); fflush(stdin); gets(numAux);	
						eliminar_Espacios(numAux);
					
				}while(validar_float(numAux));
				
				
				int socio_pos = 0;
				
				for(int i = 0; i<contador.N_socios; i++){
					
					if((strcmp(asociados[user_pos].cedula_socio, socios[i].datos.cedula) == 0)){
						
						socio_pos = i;
							
					}
				}
				
				float disponible = socios[socio_pos].fondos - socios[socio_pos].deuda;
				
				
				if(atof(numAux) <= 0){
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(20,27); color(h,4); cout << " LA FACTURA NO PUEDE TENER VALORES NEGATIVOS O CERO";
						getch();	
				}
				
				else if(((socios[socio_pos].fondos - socios[socio_pos].deuda) - atof(numAux)) < 0 ){
					
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(20,27); color(h,4); cout << " FONDOS INSUFICIENTES, SU DISPONIBLE ES: $"<< std::fixed << std::setprecision(2) << disponible;	
						getch();
				}
				else{
					//se acumula en la deuda
					socios[socio_pos].deuda += atof(numAux); 
					facturas[contador.N_facturas].valor = atof(numAux);
					break;
				}
					
			}while(true);
			
			
		}
		
		
	
	return true;
	
}

void consultar_un_socio(Socio socios[],Asociado asociados[],Contador &contador){
	
				system("cls");
				system("color 87");
				
				color(h,142);
				ventana(80,3,40,0);
				gotoxy(42,1); color(h,142); cout << " APARTADO INFORMACION DE SOCIO  ";
				
				color(h,142);
				ventana(80,9,40,6);
				gotoxy(42,7); color(h,138); cout << " [1] "; color(h,143); cout<<"BUSCAR POR NOMBRE Y APELLIDO";
				
				color(h,142);
				ventana(80,18,40,15);
				gotoxy(42,16); color(h,138); cout << " [2] "; color(h,143); cout<<"BUSCAR POR CEDULA DE CIUDADANIA";
				
				color(h,142);
				ventana(80,27,40,24);
				gotoxy(42,25); color(h,138); cout << " [3] "; color(h,143); cout<<"CANCELAR BUSQUEDA DEL SOCIO";
		
				Flecha flecha;
				//llamamos a la función para crear las flechas.
				Creaflechas(flecha,37,7,0,0,9,37,37,7,25); 
				
				//llamamos a la función mover fe
				Flechamover(flecha, false, false);
				
				int socio_pos;
				bool socioUasociado;
				//Según el ejeX y el ejeY en donde el usuario de "ENTER" se hará una suma en la cual se basara la opción del usuario.
				switch(flecha.ejeX+flecha.ejeY){
				
					case 37+7: //BUSQUEDA POR NOMBRE
						
						socio_pos = busqueda_usuario_nombre(socios,asociados,contador,'S',socioUasociado);
				
					break;
					
					case 37+16: //BUSQUEDA POR CEDULA
						
						socio_pos = busqueda_usuario_cedula(socios,asociados,contador,'S',socioUasociado);
					
					break;
					
					case 37+25: //SALIR CANCELAR BUSQUEDA DE SOCIO
						
						return;
				
					break;
				
				}
			
				//Si el usuario cancela la busqueda, socio_pos retornara "-1", por lo tanto lo sacamos.
				if(socio_pos == -1){
					return;
				}
				else{
					system("cls");
					
					system("color 87");
						
					color(h,142);
					ventana(76,3,40,0);
					gotoxy(45,1); color(h,142); cout << " INFORMACION DEL SOCIO ";
					
					color(h,142);
					ventana(116,25,4,3);
				
					
					color(h,142);
					ventana(54,25,4,3);
					gotoxy(20,3); color(h,142); cout << " DATOS DEL SOCIO ";
					
					color(h,143);
					ventana(27,17,6,5);
					//llamamos la función para mostrar la foto del socio en cuestión.
					fotos_perfil(7, 6,240,socios[socio_pos].foto);
					gotoxy(9,17); color(h,142); cout << "FOTO DEL SOCIO";
					
					gotoxy(30,5); color(h,143); cout << "CEDULA DE CIUDADANIA";
					gotoxy(30,7); color(h,139); cout << "C.C: "<< socios[socio_pos].datos.cedula;
					
					gotoxy(30,10); color(h,143); cout << "EDAD: "<< socios[socio_pos].datos.edad;
					
					gotoxy(30,13); color(h,143); cout << "TIPO DE SUSCRIPCION";
					
					//codincional que diferencia de un socio VIP Y REGULAR
					if(socios[socio_pos].suscripcion){
						gotoxy(30,15); color(h,139); cout << "[ V.I.P ]";
					}
					else{
						gotoxy(30,15); color(h,132); cout << "[ REGULAR ]";
					}
				
					gotoxy(6,19); color(h,143); cout << "NOMBRE Y APELLIDO DEL SOCIO" ;
					
					gotoxy(6,21); color(h,143); cout << socios[socio_pos].datos.nombre;
						
					gotoxy(74,3); color(h,142); cout<< " ASOCIADOS DEL SOCIO";
					gotoxy(55,5); color(h,142); cout << "| NOMBRE/APELLIDO ";
					gotoxy(74,5); color(h,142); cout << " | C.C ";
					gotoxy(85,5); color(h,142); cout << " | EDAD";
					gotoxy(94,5); color(h,142); cout << "| PARENTESCO"; 
					
					int y = 6;
					for(int i = 0; i < contador.N_asociados; i++){
					//solo se mostraran los asociados que coincidan y tengan la suscripcion activa
						if(strcmp(socios[socio_pos].datos.cedula,asociados[i].cedula_socio) == 0 and asociados[i].datos.estado == true ){
						
						gotoxy(57,y); color(h,143); cout << asociados[i].datos.nombre;
						gotoxy(77,y); color(h,139); cout << asociados[i].datos.cedula;
						gotoxy(88,y); color(h,139); cout << asociados[i].datos.edad;
						gotoxy(96,y); color(h,139); cout << asociados[i].parentesco;
					
						y+=2;
						}
					}
					getch();
				}	
}

int busqueda_numero_factura(Factura facturas[], Contador &contador){
	
		system("cls");

		
		color(h,142);
		ventana(80,3,40,0);
		gotoxy(42,1); color(h,142);
	
		cout << "APARTADO MOTOR DE BUSQUEDA FACTURAS";
		
		ventana(90,15,29,5);
		
		color(h,143);
		ventana(118,30,2,25);
		gotoxy(47,25); color(h,142); cout << " MENSAJES DEL SISTEMA ";
		
		gotoxy(40,7); color(h,142); cout << " BUSCAR POR NUMERO DE FACTURA [#] ";
		
		char auxCadena[50];
		bool coincidencia = true;
		
		do{
			
			borrador_mensajes(33, 9, 85, 11, 240);
			borrador_mensajes(3, 26, 116, 28, 0);
			gotoxy(5,27); color(h,4); cout << " Si desea cancelar la busqueda presione [ESC] , para seguir con la busqueda presione cualquier otra tecla "; 
			
			gotoxy(35,10);
			
			//pqueño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
			int tecla = _getch();
					
			if(tecla == 27){
				return -1;
			}
			
			borrador_mensajes(33, 9, 85, 11, 240);
			borrador_mensajes(3, 26, 116, 28, 0);
			gotoxy(5,27); color(h,10); cout << " debe ingresar el numero de factura, si no se acuerda busque a la persona que la consumio "; 
			
			gotoxy(35,10); color(h,240); fflush(stdin); gets(auxCadena);
			
			eliminar_Espacios(auxCadena);
			
			if(es_Entero(auxCadena)){
				borrador_mensajes(33, 9, 85, 11, 240);
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(35,27); color(h,4); cout << " ENTRADA INVALIDA, CARACTERES NO NUMERICOS "; 
				getch();
				continue;
			}	
			
			for(int i = 0; i < contador.N_facturas; i++){
			
				if(atoi(auxCadena) == facturas[i].id_factura and facturas[i].estado == true){
					coincidencia = false;
					return i;
				}
			}
					
				
			
			if(coincidencia){
				
				borrador_mensajes(33, 9, 85, 11, 240);
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(35,27); color(h,4); cout << " No se encontro ninguna factura parecida "; 
				getch();
			}
			else{
				break;
			}
		
		}while(true);
	
}

int ver_facturas_socio(Socio socios[],Asociado asociados[],Factura facturas[], Contador &contador, int user_pos){
		
		system("cls");
		
		//color principal de fondo
		system("color 87");

		color(h,142);
		ventana(80,3,40,0);
		gotoxy(43,1); color(h,142); cout << " APARTADO VER FACTURAS ";
		
		gotoxy(5,4); color(h,142); cout << "RESULTADOS DE LA BUSQUEDA, PARA ELEGIR UNA FACTURA INGRESE SU INDICE [N]:";
		
		gotoxy(2,6); color(h,142); cout << " INDICE ";
		gotoxy(12,6); color(h,142); cout << "| NOMBRE DEL CONSUMIDOR ";
		gotoxy(45,6); color(h,142); cout << "| AFILIACION ";
		gotoxy(70,6); color(h,142); cout << "| CEDULA [C.C] ";
		gotoxy(85,6); color(h,142); cout << "| VALOR ";
		
		int y = 8;
		
		bool coincidencias_facturas[contador.N_facturas];
		int n_facts = 0;
		
			
		for(int i = 0; i < contador.N_facturas; i++){
				
			if(strcmp(facturas[i].cedula_consumidor,socios[user_pos].datos.cedula) == 0 and facturas[i].estado == true){
				gotoxy(4,y); color(h,139); cout << "["<<++n_facts<<"]";
				gotoxy(14,y); color(h,143); cout << socios[user_pos].datos.nombre;
				gotoxy(47,y); color(h,139); cout << "SOCIO";
				gotoxy(72,y); color(h,139); cout << socios[user_pos].datos.cedula;
				gotoxy(87,y); color(h,138); cout <<"$"<<std::fixed<<std::setprecision(2)<<facturas[i].valor;
				y+=2;
				
				coincidencias_facturas[i] = true;
			}
			else{
				coincidencias_facturas[i] = false;
			}
		}
	
		
		char eleccion[3];
		
		do{
			
			borrador_mensajes(0, 0, 39, 1, 136);
			
			gotoxy(0,0); color(h,79);  cout << " [ESC] para salir , para continuar "; 
			gotoxy(0,1); color(h,79);  cout << " presione cualquier otra tecla     ";
		
			borrador_mensajes(80, 4, 100, 4, 240);
			
			//pqueño gecth antes de pedir el dato para saber si desean cancelar la eleccion
			int tecla = _getch();
			
			gotoxy(82,4); color(h,240);
					
			if(tecla == 27){
				return -1;
			}
			
			borrador_mensajes(0, 0, 39, 1, 136);
			
			gotoxy(0,0); color(h,10); cout << " Elija un indice [N] ";
			
			gotoxy(82,4); color(h,240); gets(eleccion);
			
			if(es_Entero(eleccion)){
				
				borrador_mensajes(0, 0, 39, 1, 136);
			
				gotoxy(0,0); color(h,4); cout << " Entrada invalida, para seguir  "; 
				gotoxy(0,1); color(h,4); cout << " presione cualquier otra tecla  ";
				
				getch();
				continue;
			}
			
					
				if(atoi(eleccion) >= 1 and atoi(eleccion) <= n_facts){
					
					int cont = 0;
						
						for(int i = 0; i < contador.N_facturas; i++){
							
							if(coincidencias_facturas[i] == true){
								cont++;
							}
							
							if(cont == atoi(eleccion)){
								return i;
							}
						}
					
					}	
				
				else{
					borrador_mensajes(0, 0, 39, 1, 136);
						
					gotoxy(0,0); color(h,4); cout << " Entrada invalida, para seguir  "; 
					gotoxy(0,1); color(h,4); cout << " presione cualquier otra tecla  ";
							
					getch();
				}
			
			
		}while(true);
	
}

bool pagar_factura(Socio socios[],Factura facturas[],Asociado asociados[], Contador &contador,int user_pos, int fact_pos){
	
		system("cls");
		system("color 87");
		
	
		color(h,142);
		ventana(76,3,40,0);
		gotoxy(50,1); color(h,142); cout << " PAGAR FACTURA ";
		
		color(h,142);
		ventana(84,25,31,3);
		gotoxy(47,3); color(h,142); cout << " DATOS DE LA FACTURA ";
	
		gotoxy(48,5); color(h,143); cout << "NUMERO DE FACTURA: ";
		
		color(h,139); cout << "#" << fact_pos;
		
		gotoxy(43,7); color(h,143); cout << "CEDULA DE CIUDADANIA CONSUMIDOR";
		gotoxy(52,9); color(h,139); cout << "C.C: "<< facturas[fact_pos].cedula_consumidor;
		
		gotoxy(46,11); color(h,143); cout << "FECHA:  "<< facturas[fact_pos].dia <<" / "<< facturas[fact_pos].mes <<" / "<< facturas[fact_pos].year;
		
		gotoxy(54,13); color(h,143); cout << "CONCEPTO";
		
		gotoxy(54,15); color(h,139); cout << facturas[fact_pos].concepto;
		
		
		gotoxy(43,17); color(h,138); cout << "VALOR DE LA FACTURA: $"<<std::fixed<<std::setprecision(2)<<facturas[fact_pos].valor; 
		
		color(h,143);
		ventana(118,30,2,25);
		gotoxy(47,25); color(h,142); cout << " MENSAJES DEL SISTEMA ";
		
		
		gotoxy(35,21); color(h,143); cout << " INGRESE LA OPCION: " ;
	
		//INTRODUCIR GENERO
			
		char auxCadena[5];
		
		do{
			
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(5,27); color(h,4); cout << " Si desea cancelar el pago presione [ESC] , para seguir presione cualquier otra tecla "; 
				
			
				gotoxy(55,21);
				
				//pqueño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return false;
				}
				
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(20,27); color(h,10); cout << " INTRODUCIR [S] PARA PAGAR LA FACTURA, [N] PARA CANCELAR";
			
			gotoxy(55,21); color(h,142); fflush(stdin); gets(auxCadena);
			eliminar_Espacios(auxCadena);
			
			//validar que sea un solo caracter
			while(strlen(auxCadena) != 1){
				gotoxy(55,21); color(h,142); cout << "                       ";
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(20,27); color(h,4); cout << " ENTRADA INVALIDA, LAS OPCIONES ES [S] PARA PAGAR, [N] PARA CANCELAR";
				gotoxy(55,21); color(h,142); fflush(stdin);  gets(auxCadena);
				eliminar_Espacios(auxCadena);
			}
			
			//validar que sea letra
			while(es_Char(auxCadena)){
				gotoxy(55,21); color(h,142); cout << "                       ";
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(30,27); color(h,4); cout << " ENTRADA INVALIDA, CARACTERES NUMERICOS";
				gotoxy(55,21); color(h,142); fflush(stdin);  gets(auxCadena);
				eliminar_Espacios(auxCadena);
			}
		
			
			//el caracter se pasa a mayuscula
			strupr(auxCadena);
			
		}while(auxCadena[0] != 'S' and auxCadena[0] != 'N');
		
		if(auxCadena[0] == 'S'){
			socios[user_pos].deuda -= facturas[fact_pos].valor;
			facturas[fact_pos].estado = false;
			float disponible = socios[user_pos].fondos - socios[user_pos].deuda;
			borrador_mensajes(3, 26, 116, 28, 0);
			gotoxy(30,27); color(h,10); cout << " SU NUEVO DISPONIBLE ES: $"<<std::fixed<<std::setprecision(2)<<disponible << "  , presione para cerrar";
			getch();
		}
		else{
			return false;
		}
		
	return true;
	
}

void ventana_pagar_factura(Socio socios[],Factura facturas[],Asociado asociados[], Contador &contador){
	
		system("cls");

		
		color(h,142);
		ventana(80,3,40,0);
		gotoxy(45,1); color(h,142); cout << " APARTADO PAGAR FACTURAS ";
		
		gotoxy(30,5); color(h,142); cout << " Para pagar una factura primero debe buscar al  ";
		gotoxy(30,7); color(h,142); cout << " socio que la consumio o por numero de factura ";
		
		color(h,142);
		ventana(80,13,40,10);
		gotoxy(42,11); color(h,138); cout << " [1] "; color(h,143); cout<<"BUSCAR POR NOMBRE Y APELLIDO";
		
		color(h,142);
		ventana(80,18,40,15);
		gotoxy(42,16); color(h,138); cout << " [2] "; color(h,143); cout<<"BUSCAR POR CEDULA DE CIUDADANIA";
		
		color(h,142);
		ventana(80,23,40,20);
		gotoxy(42,21); color(h,138); cout << " [3] "; color(h,143); cout<<"BUSCAR POR NUMERO DE FACTURA";
		
		color(h,142);
		ventana(80,28,40,25);
		gotoxy(42,26); color(h,138); cout << " [4] "; color(h,143); cout<<"CANCELAR CREACION FACTURA";
	
		Flecha flecha;
		
		Creaflechas(flecha,37,11,0,0,5,37,37,11,26); 
		
		Flechamover(flecha, false, false);
		
		int user_pos = -2, fact_pos = -2;
		bool socioUasociado;
		
		switch(flecha.ejeX+flecha.ejeY){
		
			case 37+11: //BUSQUEDA POR NOMBRE
				
				user_pos = busqueda_usuario_nombre(socios,asociados,contador,'S',socioUasociado);
				
		
			break;
			
			case 37+16: //BUSQUEDA POR CEDULA
				
				user_pos = busqueda_usuario_cedula(socios,asociados,contador,'S',socioUasociado);
			
			break;
			
			case 37+21: //BUSQUEDA POR NUMERO DE FACTURA
				
				fact_pos = busqueda_numero_factura(facturas,contador);
			
			break;
			
			case 37+25: //SALIR CANCELAR REGISTRO DE CONSUMO
				
				return;
		
			break;
		
		}
		
		if(user_pos == -1){
			return;
		}
		else if(user_pos >= 0){
			
			fact_pos = ver_facturas_socio(socios,asociados,facturas, contador, user_pos);
		
		}
		
		if(fact_pos == -1){
			return;
		}
		else if(fact_pos >= 0){
			
			 pagar_factura(socios,facturas,asociados,contador,user_pos,fact_pos);
			
		}
	
	
}


void ventana_modificar_usuario(Socio socios[],Asociado asociados[], Contador &contador){
	
	
		system("cls");

		
		color(h,142);
		ventana(80,3,40,0);
		gotoxy(45,1); color(h,142); cout << " APARTADO MODIFICAR USUARIO ";
		
		gotoxy(20,5); color(h,142); cout << " Para modificar una cuenta debe buscar a la persona para poder editarla";
		
		color(h,142);
		ventana(80,13,40,10);
		gotoxy(42,11); color(h,138); cout << " [1] "; color(h,143); cout<<"BUSCAR POR NOMBRE Y APELLIDO";
		
		color(h,142);
		ventana(80,20,40,17);
		gotoxy(42,18); color(h,138); cout << " [2] "; color(h,143); cout<<"BUSCAR POR CEDULA DE CIUDADANIA";
		
		color(h,142);
		ventana(80,27,40,24);
		gotoxy(42,25); color(h,138); cout << " [3] "; color(h,143); cout<<"CANCELAR EDITAR CUENTA";
	
		//creamos la flecha de selección.
		Flecha flecha;
		
		Creaflechas(flecha,37,11,0,0,7,37,37,11,25); 
		
		Flechamover(flecha, false, false);
		
		//guardamos la ubicación del usuario.
		int user_pos;
		bool socioUasociado;
		
		switch(flecha.ejeX+flecha.ejeY){
		
			case 37+11: //BUSQUEDA POR NOMBRE
				
				user_pos = busqueda_usuario_nombre(socios,asociados,contador,'T',socioUasociado);
				
		
			break;
			
			case 37+18: //BUSQUEDA POR CEDULA
				
				user_pos = busqueda_usuario_cedula(socios,asociados,contador,'T',socioUasociado);
			
			break;
			
			case 37+25: //SALIR CANCELAR REGISTRO DE CONSUMO
				
				return;
		
			break;
		
		}
		
		if(user_pos == -1){
			return;
		}
		else{
			
			if(socioUasociado == true){
				afiliar_socio(socios,asociados, contador,user_pos,'E');
			}
			else{
				
				int socio_pos;
				
				for(int i = 0; i < contador.N_socios; i ++){
					if(strcmp(asociados[user_pos].cedula_socio,socios[i].datos.cedula) == 0){
						socio_pos = i;
					}
				}
				
				ventana_afiliar_asociado(socios, asociados,contador, socio_pos, user_pos, 'E');
				
			}
			
			
		}

}

void consultas(Socio socios[], Asociado asociados[],Contador &contador,Factura facturas[]){

		Flecha flecha;
	
		system("cls");
			system("color 87");
		
		//gotoxy para añadir el mensaje a la posicion deseada, color para estetica

		gotoxy(0,0); color(h,79); cout << " [ESC] para salir "; 

		color(h,142);
		ventana(71,4,40,1);
		gotoxy(51,2); color(h,142); cout << "CONSULTAS ";
		
		color(h,142);
		ventana(41,9,9,6);
		gotoxy(14,7); color(h,143); cout<<" INFORMACION DEL SOCIO"; color(h,138); cout << "[1] ";
		
		color(h,142);
		ventana(104,9,70,6);
		gotoxy(71,7); color(h,138); cout << " [2] "; color(h,143); cout<<"ESTADO DE CUENTA ";
		
		color(h,142);
		ventana(41,15,9,12);
		gotoxy(14,13); color(h,143); cout<<" ASOCIADOS DE UN SOCIO"; color(h,138); cout << "[3] ";
		
		color(h,142);
		ventana(104,15,70,12);
		gotoxy(71,13); color(h,138); cout << " [4] "; color(h,143); cout<<"SOCIOS ACTIVOS ";
		
		color(h,142);
		ventana(41,21,9,18);
		gotoxy(18,19);  color(h,143); cout<<" SOCIOS RETIRADOS"; color(h,138); cout << " [5] ";
		
		color(h,142);
		ventana(104,21,70,18);
		gotoxy(71,19); color(h,138); cout << " [6] "; color(h,143); cout<<"FACTURAS PENDIENTES A PAGAR";
	
		
	
		Creaflechas(flecha,41,7,0,33,6,41,67,7,19); 
		
		Flechamover(flecha, true, false);
		
		switch (flecha.ejeX+flecha.ejeY){
		
		//Información del socio.
		case 41+7: 
				
			consultar_un_socio(socios,asociados,contador);
			
			break;
		//Estado de cuenta.		
		case 67+7: 
			
			estado_de_cuenta(socios,asociados,contador,facturas);	
			
			break;
		//La lista de personas autorizadas por un socio.
		case 41+13: 
			
			consultar_un_socio(socios,asociados,contador);
			
			break;
		//Listado de Socios Activos.
		case 67+13: 
		
			ventana_socios_activos(socios,asociados,contador);
		
			break;
		//Listado de Socios Retirados.
		case 41+19: 
		
			 listado_socios_retirados(socios,asociados,contador);
		
			break;
		//Listado de Facturas Pendiente Por Pagar:.
		case 67+19: 
		
			listado_facturas_pendientes(facturas, contador);
		
			break;
		}
}

void ventana_socios_activos(Socio socios[],Asociado asociados[],Contador &contador){
	system("cls");
	system("color 87");
	

		color(h,142);
		ventana(82,3,40,0);
		gotoxy(55,1); color(h,142); cout << "SOCIOS ACTIVOS";
		

		gotoxy(10,3); color(h,143); cout << "| NOMBRE/APELLIDO";
		
		gotoxy(30,3); color(h,143); cout << "| C.C";
		
		gotoxy(40,3); color(h,143); cout << "| SUSCRIPCION";
		
		gotoxy(56,3); color(h,143); cout << "| FONDOS DISPONIBLES";
		
		gotoxy(80,3); color(h,143); cout << "| CANTIDAD DE ASOCIADOS"; 
		
		Socio aux;
		Socio temp[contador.N_socios];
		
		for(int i=0; i< contador.N_socios; i++){
			temp[i] = socios[i];
		}	
		 
		for(int i = 0; i < contador.N_socios-1; i++){
			
			for(int j = i + 1; j < contador.N_socios; j++){
				
				if(strcmp(temp[i].datos.nombre,temp[j].datos.nombre) > 0 and temp[i].datos.estado == true){
					
					aux = temp[i];
					temp[i] = temp[j];
					temp[j] = aux;	
					
				}
					
			}
			
		}
		
		int y = 5;
		
		for(int i = 0; i < contador.N_socios; i++){
			
			if(temp[i].datos.estado == true){
				gotoxy(12,y); color(h,143); cout<<temp[i].datos.nombre;
				gotoxy(32,y); color(h,139); cout<<temp[i].datos.cedula;
				if(temp[i].suscripcion==true){
				gotoxy(44,y); color(h,139); cout<<"[V.I.P]";	
				}else{
				gotoxy(43,y); color(h,132); cout<<"[REGULAR]";	
				}
				gotoxy(62,y); color(h,138); cout<<"$"<<std::fixed<<std::setprecision(2)<<(temp[i].fondos-socios[i].deuda);
				
				gotoxy(92,y); color(h,143); cout << temp[i].cant_asociados;
				y+=2;	
			}
		
		}
	
	getch();
}






void listado_facturas_pendientes(Factura facturas[], Contador &contador){


	system("cls");
					
		system("color 87");
						
		color(h,142);
		ventana(85,3,40,0);
		gotoxy(45,1); color(h,142); cout << " LISTADO DE FACTURAS POR PAGAR ";
	
		gotoxy(2,5); color(h,142); cout << " INDICE ";
		gotoxy(12,5); color(h,142); cout << "| CEDULA CONSUMIDOR ";
		gotoxy(40,5); color(h,142); cout << " | CONCEPTO ";
		gotoxy(70,5); color(h,142); cout << " | FECHA";
		gotoxy(90,5); color(h,142); cout << "| VALOR"; 
	
					
		Factura aux_fact[contador.N_facturas];
		
		for(int i = 0; i < contador.N_facturas; i++){
			 aux_fact[i] = facturas[i];
		}
		
	    
	     for (int i = 0; i < contador.N_facturas - 1; i++) {
	        for (int j = 0; j < contador.N_facturas - i - 1; j++) {
	            if (atoi(aux_fact[j].dia) > atoi(aux_fact[j + 1].dia)) {
	                Factura temp = aux_fact[j];
	                aux_fact[j] = aux_fact[j + 1];
	                aux_fact[j + 1] = temp;
	            }
	        }
	    }
	    
	    for (int i = 0; i < contador.N_facturas - 1; i++) {
	        for (int j = 0; j < contador.N_facturas - i - 1; j++) {
	            if (atoi(aux_fact[j].mes) > atoi(aux_fact[j + 1].mes)) {
	                Factura temp = aux_fact[j];
	                aux_fact[j] = aux_fact[j + 1];
	                aux_fact[j + 1] = temp;
	            }
	        }
	    }
	    
	    for (int i = 0; i < contador.N_facturas - 1; i++) {
	        for (int j = 0; j < contador.N_facturas - i - 1; j++) {
	            if (atoi(aux_fact[j].year) > atoi(aux_fact[j + 1].year)) {
	                Factura temp = aux_fact[j];
	                aux_fact[j] = aux_fact[j + 1];
	                aux_fact[j + 1] = temp;
	            }
	        }
	    }
	    
	   
					
		int y = 6;
		int cont = 0;
		float monto = 0;
		for(int i = 0; i < contador.N_facturas; i++){
			//solo se mostraran los socios que coincidan y tengan la suscripcion desactivada
			if(aux_fact[i].estado == true){
						
					gotoxy(4,y); color(h,143); cout <<"[" << ++cont << "]";
					gotoxy(14,y); color(h,143); cout << aux_fact[i].cedula_consumidor;
					gotoxy(42,y); color(h,139); cout << aux_fact[i].concepto;
					gotoxy(72,y); color(h,143); cout << aux_fact[i].dia <<"/"<< aux_fact[i].mes <<"/"<< aux_fact[i].year;
					
					monto += aux_fact[i].valor;
					
					gotoxy(92,y); color(h,139); cout <<"$" << std::fixed << std::setprecision(2) << aux_fact[i].valor;
					
					y+=2;
				}
			}
			
	gotoxy(15,y); color(h,139); cout <<" NUMERO DE FACTURAS POR COBRAR "<< cont << " , MONTO TOTAL DE LAS CUENTAS A COBRAR:"; color(h,138); cout <<" $"<< std::fixed << std::setprecision(2) << monto;
	
	getch();





}


void listado_socios_retirados(Socio socios[],Asociado asociados[],Contador &contador){
	
		system("cls");
					
		system("color 87");
						
		color(h,142);
		ventana(76,3,40,0);
		gotoxy(45,1); color(h,142); cout << " LISTADO DE SOCIOS RETIRADOS ";
	
		gotoxy(2,5); color(h,142); cout << " INDICE ";
		gotoxy(12,5); color(h,142); cout << "| NOMBRE Y APELLIDO ";
		gotoxy(37,5); color(h,142); cout << " | CEDULA [C.C] ";
		gotoxy(53,5); color(h,142); cout << " | EDAD";
		gotoxy(63,5); color(h,142); cout << "| SUSCRIPCION"; 
		gotoxy(78,5); color(h,142); cout << "| FECHA RETIRO"; 
		gotoxy(98,5); color(h,142); cout << "| CANTIDAD ASOCIADOS"; 
		
		
					
		Socio aux_Socio[contador.N_socios];
		
		for(int i = 0; i < contador.N_socios; i++){
			aux_Socio[i] = socios[i];
		}
		
		for (int i = 0; i < contador.N_socios - 1; i++) {
	        for (int j = 0; j < contador.N_socios - i - 1; j++) {
	            if (aux_Socio[j].cant_asociados < aux_Socio[j + 1].cant_asociados) {
	                Socio temp = aux_Socio[j];
	                aux_Socio[j] = aux_Socio[j + 1];
	                aux_Socio[j + 1] = temp;
	            }
	        }
	    }
					
		int y = 6;
		int cont = 0;
		for(int i = 0; i < contador.N_socios; i++){
			//solo se mostraran los socios que coincidan y tengan la suscripcion desactivada
			if(aux_Socio[i].datos.estado == false){
						
					gotoxy(4,y); color(h,143); cout <<"[" << ++cont << "]";
					gotoxy(14,y); color(h,143); cout << aux_Socio[i].datos.nombre;
					gotoxy(39,y); color(h,139); cout << aux_Socio[i].datos.cedula;
					gotoxy(55,y); color(h,139); cout << aux_Socio[i].datos.edad;
					
					gotoxy(65,y); color(h,139);
					
					if(aux_Socio[i].suscripcion == true){
						cout << "[V.I.P]";	
					}
					else{
						cout << "[REGULAR]";
					}
					
					gotoxy(80,y); color(h,143); cout << aux_Socio[i].dia <<"/"<< aux_Socio[i].mes <<"/"<< aux_Socio[i].year;
					gotoxy(100,y); color(h,143); cout << aux_Socio[i].cant_asociados;
							
					
					y+=2;
				}
			}
	
	getch();
}

//función para modificar los fondos actuales de un socio.
void ventana_aumentar_fondos_socio(Socio socios[],Asociado asociados[],Contador &contador){
		
		system("cls");
		
		color(h,142);
		ventana(80,3,40,0);
		gotoxy(42,1); color(h,142); cout << " APARTADO AUMENTAR FONDOS DEL SOCIO  ";
		
		color(h,142);
		ventana(80,9,40,6);
		gotoxy(42,7); color(h,138); cout << " [1] "; color(h,143); cout<<"BUSCAR POR NOMBRE Y APELLIDO";
		
		color(h,142);
		ventana(80,18,40,15);
		gotoxy(42,16); color(h,138); cout << " [2] "; color(h,143); cout<<"BUSCAR POR CEDULA DE CIUDADANIA";
		
		color(h,142);
		ventana(80,27,40,24);
		gotoxy(42,25); color(h,138); cout << " [3] "; color(h,143); cout<<"CANCELAR BUSQUEDA DEL SOCIO";

		//creamos un struct flecha.
		Flecha flecha;
		
		//llamamos a la función para crear las flechas.
		Creaflechas(flecha,37,7,0,0,9,37,37,7,25); 
		
		//llamamos a la función mover fe
		Flechamover(flecha, false, false);
		
		int socio_pos;
		bool socioUasociado;
		//Según el ejeX y el ejeY en donde el usuario de "ENTER" se hará una suma en la cual se basara la opción del usuario.
		switch(flecha.ejeX+flecha.ejeY){
		
			case 37+7: //BUSQUEDA POR NOMBRE
				
				socio_pos = busqueda_usuario_nombre(socios,asociados,contador,'S',socioUasociado);
		
			break;
			
			case 37+16: //BUSQUEDA POR CEDULA
				
				socio_pos = busqueda_usuario_cedula(socios,asociados,contador,'S',socioUasociado);
			
			break;
			
			case 37+25: //SALIR CANCELAR BUSQUEDA DE SOCIO
				
				return;
		
			break;
		
		}
	
		//Si el usuario cancela la busqueda, socio_pos retornara "-1", por lo tanto lo sacamos.
		if(socio_pos == -1){
			return;
		}
		else{
			
		system("cls");
		system("color 87");
		
	
		color(h,142);
		ventana(76,3,40,0);
		gotoxy(43,1); color(h,142); cout << " MODIFICAR FONDOS DE LA CUENTA ";
		
		color(h,142);
		ventana(84,25,31,3);
		gotoxy(47,3); color(h,142); cout << " DATOS DEL AFILIADO ";
		
		color(h,143);
		ventana(54,17,33,5);
		fotos_perfil(34, 6,240,socios[socio_pos].foto);
		
		gotoxy(35,17); color(h,143); cout << "FOTO DEL SOCIO";
		
		gotoxy(56,5); color(h,143); cout << "CEDULA DE CIUDADANIA";
		gotoxy(56,7); color(h,139); cout << "C.C: "<< socios[socio_pos].datos.cedula;
		
		gotoxy(56,10); color(h,143); cout << "EDAD: "<< socios[socio_pos].datos.edad;
		
		gotoxy(56,13); color(h,143); cout << "TIPO DE SUSCRIPCION";
		
		if(socios[socio_pos].suscripcion){
			gotoxy(56,15); color(h,139); cout << "[ V.I.P ]";
		}
		else{
			gotoxy(56,15); color(h,132); cout << "[ REGULAR ]";
		}
		
		gotoxy(35,19); color(h,138); cout << "FONDOS NUEVOS: $"; 
		
		gotoxy(35,21); color(h,143); cout << "NOMBRE Y APELLIDO DEL AFILIADO" ;
		
		gotoxy(35,23); color(h,143); cout << socios[socio_pos].datos.nombre;
			
		color(h,143);
		ventana(118,30,2,25);
		gotoxy(47,25); color(h,142); cout << " MENSAJES DEL SISTEMA ";
		
		
		
		
		
		char numAux[32]; //la cant de digitos de un numero float son 32 bit =  32 digitos incluyendo el signo

		if(socios[socio_pos].suscripcion == true){
			
			do{
				
				do{
				
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la suscripcion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				
					gotoxy(52,19); color(h,142); cout << "                    ";		
				
					gotoxy(52,19);
					
					//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
					int tecla = _getch();
						
					if(tecla == 27){
					
						return;
					}
					
					
					
					
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(25,27); color(h,10); cout << " FONDOS V.I.P desde $1,000,000 hasta $5,000,000  ";	
					
					
					gotoxy(52,19); color(h,142); cout << "                    ";	
					//pedimos el fondo del socio vip.		
					gotoxy(52,19);  color(h,138); fflush(stdin); gets(numAux);
					//Eliminamos los espacios del inicio y del final de la cadena.	
					eliminar_Espacios(numAux);
					
				}while(validar_float(numAux));
				
				
				
				if(atof(numAux) < 1000000){
						//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(20,27); color(h,4); cout << " FONDOS INFERIORES, EL MONTO MINIMO ES DE $1,000,000 cop ";
						getch();	
						continue;
				}
				else if(atof(numAux) > 5000000){
						//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(20,27); color(h,4); cout << " FONDOS EXCEDEN EL LIMITE, EL MONTO MAXIMO ES DE $5,000,000 cop  ";
						getch();
						continue; 
				}
			
					//Validamos que el socio no tenga deudas pendientes.
					if(socios[socio_pos].deuda > 0){
						//Llamamos a la función para borrar la información anterior a esta.
							borrador_mensajes(3, 26, 116, 28, 0);
							gotoxy(25,27); color(h,4); cout << " TRAMITE FALLIDO, USTED TIENE DEUDAS PENDIENTES ";
							getch(); 
					}else{
							break;
					}
			
			}while(true);
			
			
			socios[socio_pos].fondos = atof(numAux); 
		}
		else{
			
			do{
				do{
						//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(5,27); color(h,4); cout << " Si desea cancelar la suscripcion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
					
						gotoxy(52,19); color(h,142); cout << "                    ";		
					
						gotoxy(52,19);
				
						int tecla = _getch();
							
						if(tecla == 27){
							
							return;
						}
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);	
					gotoxy(25,27); color(h,10); cout << " FONDOS REGULAR desde $300,000 hasta $2,000,000 ";
							
					gotoxy(52,19); color(h,142); cout << "                    ";		
					//pedimos el el fondo regular.
					gotoxy(52,19); color(h,138); fflush(stdin); gets(numAux);
					
					//Eliminamos los espacios del inicio y del final de la cadena.
					eliminar_Espacios(numAux);		
					
				}while(validar_float(numAux));
				
				if(atof(numAux) < 300000){
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(20,27); color(h,4); cout << " FONDOS INFERIORES, EL MONTO INICIAL ES MINIMO DE $300,000 cop  ";
					getch();
					continue;	
				}
				else if(atof(numAux) > 2000000){
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(20,27); color(h,4); cout << " FONDOS EXCEDEN EL LIMITE, EL MONTO MAXIMO ES DE $2,000,000 cop  ";
					getch();
					continue;  
				}
				
				//Validamos que el socio no tenga deudas pendientes.
				if(socios[socio_pos].deuda > 0){
					//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(25,27); color(h,4); cout << " TRAMITE FALLIDO, USTED TIENE DEUDAS PENDIENTES ";
						getch(); 
				}else{
						break;
				}
			
			
					
			}while(true);
	
		
			//Pasamos la cadena a float.
			socios[socio_pos].fondos = atof(numAux); 
			
			}
		
			getch();
		}
	
}
//función auxiliar de estetica, la cual tiene el contrado de afaliación de un socio.
bool ventana_contrato(Socio socios[],Contador &contador){
	
	
		system("cls");
		
		color(h,142);
		ventana(118,30,2,1);
		gotoxy(35,1); color(h,142); cout << " CONTRATO AFILIACION AL CLUB SOCIAL LOS PROPIOS ";
		
		color(h,142);
		ventana(54,25,4,3);
		gotoxy(20,3); color(h,142); cout << " DATOS DEL AFILIADO ";
		
		color(h,143);
		ventana(27,17,6,5);
		fotos_perfil(7, 6,240,socios[contador.N_socios].foto);
		
		gotoxy(9,17); color(h,143); cout << "FOTO DEL SOCIO";
		
		gotoxy(30,5); color(h,143); cout << "CEDULA DE CIUDADANIA";
		gotoxy(30,7); color(h,139); cout << "C.C: "<< socios[contador.N_socios].datos.cedula;
		
		gotoxy(30,10); color(h,143); cout << "EDAD: "<< socios[contador.N_socios].datos.edad;
		
		gotoxy(30,13); color(h,143); cout << "TIPO DE SUSCRIPCION";
		
		if(socios[contador.N_socios].suscripcion){
			gotoxy(30,15); color(h,139); cout << "[ V.I.P ]";
		}
		else{
			gotoxy(30,15); color(h,132); cout << "[ REGULAR ]";
		}
		
		gotoxy(6,19); color(h,138); cout << "FONDOS BASE: $" << std::fixed << std::setprecision(2) << socios[contador.N_socios].fondos;
		
		gotoxy(6,21); color(h,143); cout << "NOMBRE Y APELLIDO DEL AFILIADO" ;
		
		gotoxy(6,23); color(h,143); cout << socios[contador.N_socios].datos.nombre;
		
		
		color(h,132);
			gotoxy(55,13);
		   	cout<<"EL CLUB SOCIAL LOS PROPIOS";
		   	
		color(h,143);
			gotoxy(55,4);
		   	cout<<"LOS DATOS PERSONALES AQUI RECOLECTADOS SERAN RECOLECTADOS,"; 
		   	
		   	gotoxy(55,5);
		   	cout<<"ALMACENADOS, PROCESADOS, USADOS,COMPILADOS,"; 
		   	
		   	gotoxy(55,6);
		   	cout<<"TRANSMITIDOS, TRANSFERIDOS, ACTUALIZADOS Y"; 
		   	
		   	gotoxy(55,7);
		   	cout<<"DISPUESTOS CONFORME LO ESTABLECE LA LEY 1581 DE 2012,"; 	
		   	
		   	gotoxy(55,8);
		   	cout<<"EL DECRETO 1377 DE 2013, COMPILADO EN EL CAPITULO ";
		   	
		   	gotoxy(55,9);
		   	cout<<"25 DEL DECRETO 1074 DE 2015  (UNICO REGLAMENTARIO ";
		   	
		   	gotoxy(55,10);
		   	cout<<"DEL SECTOR COMERCIO, INDUSTRIA Y TURISMO) Y LA ";
		   	
			gotoxy(55,11);
		   	cout<<"POLITICA DE TRATAMIENTO Y PROTECCION DE DATOS PERSONALES";
		   	
		   	gotoxy(55,12);
		   	cout<<"DEL MINISTERIO DE JUSTICIA Y DEL DERECHO";
		   	
		   	gotoxy(82,13); 
			cout<<"COMO RESPONSABLE ";
		   	
			gotoxy(55,14);
		   	cout<<"DEL TRATAMIENTO DE LOS DATOS PERSONALES AQUI ";
		   	
		   	gotoxy(55,15);
		   	cout<<"CONSIGNADOS, EN CUMPLIMIENTO DE LA LEY 1581 DE 2012 Y ";
		   	
		   	gotoxy(55,16);
		   	cout<<"DEL DECRETO 1377 DE 2013 INFORMA AL TITULAR DE ";
		   	
		   	gotoxy(55,17);
		   	cout<<"LOS DATOS PERSONALES QUE LE ASISTEN LOS SIGUIENTES DERECHOS: " ;
		   	
		   	gotoxy(55,18);
		   	cout<<"ACCEDER A SUS DATOS PERSONALES; CONOCER," ;
		   	
		   	gotoxy(55,19);
		   	cout<<"ACTUALIZAR Y RECTIFICAR SUS DATOS PERSONALES; SOLICITAR ";
		   	
		   	gotoxy(55,20);
		   	cout<<"PRUEBA DE LA AUTORIZACION OTORGADA; REVOCAR LA ";
	 	
		   	gotoxy(55,21);
		   	cout<<"AUTORIZACION Y/O SOLICITAR LA SUPRESION DEL DATO, ";
		   	
		   	gotoxy(55,22);
		   	cout<<"PRESENTAR QUEJAS ANTE LA SUPERINTENDENCIA DE ";
		   	
		   	gotoxy(55,23);
		   	cout<<"INDUSTRIA Y COMERCIO Y EN GENERAL TODOS LOS";
		   	
		   	gotoxy(55,24);
		   	cout<<"DERECHOS CONSIGNADOS EN EL ARTICULO 8 DE LA LEY 1581 DE 2012";
		color(h,142);
		ventana(43,29,23,26);
		gotoxy(25,27); color(h,142); cout << " NO ACEPTO ";
		
		color(h,142);
		ventana(100,29,60,26);
		gotoxy(62,27); color(h,142); cout << " ACEPTO LOS TERMINOS Y CONDICIONES";
	
	Flecha flecha;
	
	Creaflechas(flecha,20,27,0,37,0,20,57,27,27); 
		
	Flechamover(flecha, false,false);
	
	char borrador[10] = {' ', ' ',' ',' ',' ',' ',' ',' ',' ',' '};
	
	switch(flecha.ejeX+flecha.ejeY){
		
		//Si la opción es NO, borramos la información antes suministrada por el usuario en la base de datos.
		case 20+27: 
		
			if(socios[contador.N_socios].suscripcion){
				contador.N_sociosVip--;
			}else{
				contador.N_sociosRegular--;
			}
			
			strcpy(socios[contador.N_socios].datos.cedula,borrador);
	
		return true;
		
		//Si, creamos un nuevo socio.
		case 57+27: 
			
			socios[contador.N_socios].cant_asociados = 0;
			socios[contador.N_socios].datos.estado = true;
			socios[contador.N_socios].deuda = 0;
			contador.N_socios++; 
		
		return false;
		
	}
	
	
}
//función auxliar de estectica, para borrar mensajes de manera más fácil.
void borrador_mensajes(int xi, int yi, int xf, int yf, int col){
	
	//ciclo para rellenar el mensaje de " ". 
	for(int y = yi; y <= yf; y++){
		for(int x = xi; x <= xf; x++){
			gotoxy(x,y); color(h,col); cout << " ";
		}
	}
	
	
}


//funcion de mover el cursor de la pantalla
void Flechamover(Flecha & flecha, bool simetria, bool si_hora){ //CONFIGURACION DEL MOVIMIENTO DE LAS FLECHAS
	
	int basura;
		color(h,142);
		gotoxy(flecha.auxX,flecha.auxY); 
		
		if(simetria){
			flecha.flechacaracter = "<==";
			cout<<flecha.flechacaracter;
		}else{
			cout<<flecha.flechacaracter;
		}
		

		do{
			if(_kbhit()){
			
						basura = _getch();
						
						color(h,142);
						 
						if(basura == 224){
							//borramos la flecha en su posicion anterior
							flecha.tecla = _getch();
							
							gotoxy(flecha.auxX,flecha.auxY); 
							
							cout<<flecha.borrador;
							
							if(flecha.tecla==72){ //TECLA DIRRECION ARRIBA
								flecha.ejeY -= flecha.saltoY;
								
								if(flecha.ejeY < flecha.limiteYi){ // DECLARACION DEL LIMITE
								//SE CONTROLA QUE LA FLECHA NO SOBRE PASE LOS LIMITES PRE ESTABLECIDOS			
									flecha.ejeY= flecha.limiteYi; 
									
									gotoxy(flecha.auxX , flecha.auxY);
									
									cout<<flecha.borrador;
								}
								
								gotoxy(flecha.ejeX , flecha.ejeY);
								cout<<flecha.flechacaracter;
			
							}
							else if(flecha.tecla==80){ //TECLA DIRRECIONAL ABAJO
								flecha.ejeY += flecha.saltoY;
								
								if(flecha.ejeY > flecha.limiteYf){ // DECLARACION DEL LIMITE
							//SE CONTROLA QUE LA FLECHA NO SOBRE PASE LOS LIMITES PRE ESTABLECIDOS			
									flecha.ejeY= flecha.limiteYf;
									
									gotoxy(flecha.auxX , flecha.auxY);
									
									cout<<flecha.borrador;
								}
								
								gotoxy(flecha.ejeX , flecha.ejeY);
								cout<<flecha.flechacaracter;
								
			
							}
							else if(flecha.tecla==75){ //TECLA DIRECCIONAL IZQUIERDA
							
								if(simetria){
									flecha.flechacaracter = "<==";
								}
							
								flecha.ejeX -= flecha.saltoX;
								if(flecha.ejeX < flecha.limiteXi){ // DECLARACION DEL LIMITE
							//SE CONTROLA QUE LA FLECHA NO SOBRE PASE LOS LIMITES PRE ESTABLECIDOS	
									flecha.ejeX= flecha.limiteXi;
									
									gotoxy(flecha.auxX , flecha.auxY);
									
									cout<<flecha.borrador;
								}
								gotoxy(flecha.ejeX , flecha.ejeY);
								cout<<flecha.flechacaracter;
			
							}
							else if(flecha.tecla==77){ //TECLA DIRECCIONAL DERECHA
								
								if(simetria){
									flecha.flechacaracter = "==>";
								}
								
								flecha.ejeX += flecha.saltoX;
								if(flecha.ejeX > flecha.limiteXf){ // DECLARACION DEL LIMITE
									
							//SE CONTROLA QUE LA FLECHA NO SOBRE PASE LOS LIMITES PRE ESTABLECIDOS
									flecha.ejeX= flecha.limiteXf;
									
									gotoxy(flecha.auxX , flecha.auxY);
									
									cout<<flecha.borrador;
								}
								gotoxy(flecha.ejeX , flecha.ejeY);
								
								cout<<flecha.flechacaracter;
			
							}
							
							flecha.auxX=flecha.ejeX;
							flecha.auxY=flecha.ejeY;
								
						}
					
				}
				
				if(si_hora){
					Hora();	
				}
				
				if(basura == 27){
					system("cls");
					system("color 0B");
					salirPro(5, 5, 9);
					exit(0);
				}
			
			}while(basura != 13);
		
	 // ESTE CICLO SE MUEVE HASTA QUE EL USUARIO DE ENTER 

}

//asignador de parametros para adaptar el cursor a cualquier menu
void Creaflechas(Flecha & flecha, int ejeX ,  int ejeY  ,int tecla , int saltoX ,int saltoY ,int limiteXi, int limiteXf, int limiteYi, int limiteYf ){ //FUNCION CREADORA DEL MOVIMIENTO DE LAS FLECHAS

	flecha.ejeX = ejeX;
	flecha.ejeY = ejeY;
	flecha.auxX = flecha.ejeX;
	flecha.auxY = flecha.ejeY;
	flecha.tecla = tecla ;
	flecha.saltoX = saltoX;
	flecha.saltoY = saltoY;
	flecha.limiteXi = limiteXi;
	flecha.limiteXf = limiteXf;
	flecha.limiteYi = limiteYi;
	flecha.limiteYf = limiteYf;
	flecha.flechacaracter = "==>";
	flecha.borrador = "   ";
	
}
//funcion estetica para el reloj en el programa
void Hora(){ // FUNCION PARA IMPORTAR LA HORA ACTUAL DEL COMPUTADOR AL PROGRAMA

		time_t Horactual=time(NULL);	
		char *Hora=ctime(&Horactual);
		gotoxy(43,28); color(h,143);
		cout<<Hora;
		Sleep(100);
	
	
}


//funcion ramdon N
int ramdonNum(int start, int end){
	//def para n random
	srand(time(0));
	return start + rand() % end;
}

void fotos_perfil(int x, int i, int col, int n){

	if(n == 1){
		
		gotoxy(x,i++); color(h,col); cout << "                   ";
		gotoxy(x,i++); color(h,col); cout << "    |\\/\\/\\/|       ";
		gotoxy(x,i++); color(h,col); cout << "    |      |       ";
		gotoxy(x,i++); color(h,col); cout << "    | (o)(o)       ";
		gotoxy(x,i++); color(h,col); cout << "    C      _)      ";
		gotoxy(x,i++); color(h,col); cout << "     |  ___|       ";
		gotoxy(x,i++); color(h,col); cout << "     |   /         ";
		gotoxy(x,i++); color(h,col); cout << "    /____\\         ";
		gotoxy(x,i++); color(h,col); cout << "   /      \\        ";
		gotoxy(x,i++); color(h,col); cout << "                   ";
	}
	else if(n == 2){
		
		gotoxy(x,i++); color(h,col); cout << "     __&__         ";
		gotoxy(x,i++); color(h,col); cout << "    /     \\        ";
		gotoxy(x,i++); color(h,col); cout << "   |       |       ";
		gotoxy(x,i++); color(h,col); cout << "   |  (o)(o)       ";
		gotoxy(x,i++); color(h,col); cout << "   c   .---_)      ";
		gotoxy(x,i++); color(h,col); cout << "    | |.___|       ";
		gotoxy(x,i++); color(h,col); cout << "    |  \\__/        ";
		gotoxy(x,i++); color(h,col); cout << "    /_____\\        ";
		gotoxy(x,i++); color(h,col); cout << "   /_____/ \\       ";
		gotoxy(x,i++); color(h,col); cout << "  /         \\      ";
	}
	else if(n == 3){
		
		gotoxy(x,i++); color(h,col); cout << "          (####)   ";
		gotoxy(x,i++); color(h,col); cout << "       (#######)   ";
		gotoxy(x,i++); color(h,col); cout << "     (#########)   ";
		gotoxy(x,i++); color(h,col); cout << "      (o)(o)(##)   ";
		gotoxy(x,i++); color(h,col); cout << "    ,_c     (##)   ";
		gotoxy(x,i++); color(h,col); cout << "   /____,   (##)   ";
		gotoxy(x,i++); color(h,col); cout << "     \\     (#)     ";
		gotoxy(x,i++); color(h,col); cout << "      |    |       ";
		gotoxy(x,i++); color(h,col); cout << "      oooooo       ";
		gotoxy(x,i++); color(h,col); cout << "     /      \\      "; 
	}
	else if(n == 4){
		
		gotoxy(x,i++); color(h,col); cout << "                   ";
		gotoxy(x,i++); color(h,col); cout << " /\\ /\\  /\\         ";       
		gotoxy(x,i++); color(h,col); cout << " | v  \\/  \\---.    ";
		gotoxy(x,i++); color(h,col); cout << "  \\_        /      "; 
		gotoxy(x,i++); color(h,col); cout << "   (o)(o)  <__.    ";
		gotoxy(x,i++); color(h,col); cout << "   _c         /    ";
		gotoxy(x,i++); color(h,col); cout << "  /____,   )  \\    ";
		gotoxy(x,i++); color(h,col); cout << "   \\     /----'    ";
		gotoxy(x,i++); color(h,col); cout << "    ooooo          ";
		gotoxy(x,i++); color(h,col); cout << "   /     \\         ";
	}
	else if(n == 5){
		
		gotoxy(x,i++); color(h,col); cout << "                   ";
		gotoxy(x,i++); color(h,col); cout << "        /\\         ";
		gotoxy(x,i++); color(h,col); cout << "  .----/  \\----.   ";             
		gotoxy(x,i++); color(h,col); cout << "   \\          /    ";
		gotoxy(x,i++); color(h,col); cout << " .--\\ (o)(o) /__.  ";
		gotoxy(x,i++); color(h,col); cout << "  \\     ()     /   ";
		gotoxy(x,i++); color(h,col); cout << "   >   (c_)   <    ";
		gotoxy(x,i++); color(h,col); cout << "  /___\\____/___\\   ";
		gotoxy(x,i++); color(h,col); cout << "     /|    |\\      ";
		gotoxy(x,i++); color(h,col); cout << "    /        \\     ";
	}

	
}


void pantalladeinicio(int x, int y){ // Función para imprimir la pantalla de inicio.   
    
	system("cls"); 
    
    for(int i=0; i<15; i++){    //For para ir cambiando los colores.
              //Variable que va aplicando el color.
        color(h, i);
	
        gotoxy(30, 0);
            cout<<"                                                      _ _  \n";
        gotoxy(30, 1);
            cout<<" _____ _____ _____ __ __ _____ _____ _____ _____    _| | |_    ___ \n";
        gotoxy(30, 2);  
            cout<<"|  _  | __  |     |  |  |   __|     |_   _|     |  |_     _|  |_  | \n";
        gotoxy(30, 3);  
            cout<<"|   __|    -|  |  |_   _|   __|   --| | | |  |  |  |_     _|  |  _| \n";
        gotoxy(30, 4);
            cout<<"|__|  |__|__|_____| |_| |_____|_____| |_| |_____|    |_|_|    |___| \n";
                                                                        

    	gotoxy(28, 6); 
        cout<<"    __ _____ _____ _____    _____ _____ _____ _____ __    _ _____ _____ \n";
        gotoxy(28, 7); 
   		cout<<"   |  |     |   __|   __|  | __  |  _  |  _  |  _  |  |  | |   | |     | \n";
   		gotoxy(28, 8); 
		cout<<"| |_| |  |  |__   |   __|  |    -|     |   __|     |  |__| | | | |  |  | \n";
		gotoxy(28, 9); 		
		cout<<"|_____|_____|_____|_____|  |__|__|__|__|__|  |__|__|_____|_|_|___|_____| \n";
        gotoxy(55, 10); 
        cout<<"Codigo:0222220010 \n";
        


            Sleep(200);
        
        }  

}



void salirPro(int x, int y, int i){
	
		gotoxy(x,y++); color(h,i); cout <<" _______ _______ ___     ___ _______ __    _ ______  _______   \n";
		gotoxy(x,y++); color(h,i); cout <<"|       |       |   |   |   |       |  |  | |      ||       |  \n";
		gotoxy(x,y++); color(h,i); cout <<"|  _____|   _   |   |   |   |    ___|   |_| |  _    |   _   | \n";
		gotoxy(x,y++); color(h,i); cout <<"| |_____|  |_|  |   |   |   |   |___|       | | |   |  | |  |  \n";
		gotoxy(x,y++); color(h,i); cout <<"|_____  |       |   |___|   |    ___|  _    | |_|   |  |_|  |  \n";
		gotoxy(x,y++); color(h,i); cout <<" _____| |   _   |       |   |   |___| | |   |       |       |  \n";
		gotoxy(x,y++); color(h,i); cout <<"|_______|__| |__|_______|___|_______|_|  |__|______||_______| \n";
		
		y+= 3;
		
		gotoxy(x,y++); color(h,i); cout <<" ______  _______ ___        _______ ______   _______ _______ ______   _______ __   __ _______  \n";		
		gotoxy(x,y++); color(h,i); cout <<"|      ||       |   |      |       |    _ | |       |       |    _ | |       |  |_|  |       |\n";		
		gotoxy(x,y++); color(h,i); cout <<"|  _    |    ___|   |      |    _  |   | || |   _   |    ___|   | || |   _   |       |   _   |\n";	
		gotoxy(x,y++); color(h,i); cout <<"| | |   |   |___|   |      |   |_| |   |_||_|  | |  |   | __|   |_||_|  |_|  |       |  |_|  |\n";	
		gotoxy(x,y++); color(h,i); cout <<"| |_|   |    ___|   |___   |    ___|    __  |  |_|  |   ||  |    __  |       |       |       |\n";	
		gotoxy(x,y++); color(h,i); cout <<"|       |   |___|       |  |   |   |   |  | |       |   |_| |   |  | |   _   | ||_|| |   _   |\n";	
		gotoxy(x,y++); color(h,i); cout <<"|______||_______|_______|  |___|   |___|  |_|_______|_______|___|  |_|__| |__|_|   |_|__| |__|\n";
		
	}

