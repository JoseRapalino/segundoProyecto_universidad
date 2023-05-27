
//Creamos un struct que almacene los datos personales, ya sea de un socio o un asociado.
struct Datos_personales{
	
	char nombre[100]; //cadena de los nombres de los socios o asociados.
	char cedula[10]; 
	char sexo[10];
	char edad[3];
	bool estado; //afiliado o cancelado
	
};
//Creamos un struct Socio que almacene las cualidades de un socio junto a sus datos personales.
struct Socio{
	
	int foto;
	float fondos; //Fondos disponibles de los socios.
	float deuda; //Deudas de facturas registrar por un socio o un asociado de este.
	bool suscripcion; // true = vip,  false = regular
	Datos_personales datos; //hereda los atributos de datos_personales
	//fecha de retiro
	char year[5];
	char dia[5];
	char mes[5];
	int cant_asociados;  //contador que llevara la cantidad de asociados

};

//Creamos un struct Asociado que almacene las cualidades de un Asociado junto a sus datos personales.
struct Asociado{

	Datos_personales datos; //hereda los atributos de datos_personales
	char parentesco[20];
	char cedula_socio[10]; //el primary-key de cada asociado
	
};

//struct de las facturas

struct Factura{
	
	int id_factura; //Numero de la factura.
	char cedula_consumidor[10]; //Cedula del que registrar la factura.
	char concepto[50]; //El motivo de la factura.
	float valor; //Valor de la factura.
	bool estado; // true = pendiente y false = pagado.
	
	//Fecha de la expedición de la factura.
	char dia[5];
	char mes[5];
	char year[5]; 
};

//struct de contadores globales
struct Contador{
	int N_socios; //Número de socios registrados.
	int N_asociados; //Número de asocidos registrados.
	int N_sociosVip; //Número de socios vip registrados.
	int N_sociosRegular; //Número de socios regulares registrados.
	int N_facturas; ////Número de facturas registradas.
};


//struct ESTETICO para manejar el cursor de la interfaz
struct Flecha{
	
	int ejeX ,ejeY ,auxX ,auxY ,tecla ,saltoY ,saltoX , limiteXi , limiteYi , limiteXf, limiteYf;
	std::string flechacaracter,borrador;
	
};

//funcion usada en afiliar_socio para validar la entrada de una nueva cedula
bool validar_cedula_ingreso(Socio socios[], Asociado asociados[],Contador &contador, char auxCedula[], bool &no_valido);

//funcion principal del punto [1]
void afiliar_socio(Socio socios[],Asociado asociados[], Contador &contador, int socio_pos, char usuario);

//funcion auxiliar de afiliar_Socio que verifica si se puede ingresar V.I.P
bool validar_regisvip(int sociosRegulares, int sociosVIP);

//funcion auxiliar para validar la entrada de INT
bool es_Entero(char cadena[]);

//funcion auxiliar para validar la entrada de CHAR
bool es_Char(char cadena[]);

//funcion auxiliar para validar la entrada de FLOAT
bool validar_float(char num[]);

//Función para buscar por nombre a un cliente registrado.
bool buscar_usuario_porNombre(Socio socios[],Asociado asociados[], Contador &contador, char auxCadena[], bool coincidencias_socios[],bool coincidencias_asociados[], char usuario);

//Función para buscar por cedula a un cliente registrado.
int busqueda_usuario_cedula(Socio socios[],Asociado asociados[], Contador &contador, char usuario, bool &socioUasociado);

//Función para registrar el consumo de una factura, ya sea de un socio o un asodiado.
bool registrar_consumo(Socio socios[],Asociado asociados[],Factura facturas[],Contador &contador, int user_pos,bool socioUasociado);

void ventana_pagar_factura(Socio socios[],Factura facturas[],Asociado asociados[], Contador &contador);

int busqueda_numero_factura(Factura facturas[], Contador &contador);

int ver_facturas_socio(Socio socios[],Asociado asociados[],Factura facturas[], Contador &contador, int user_pos);
void estado_de_cuenta(Socio socios[],Asociado asociados[],Contador &contador, Factura facturas[]);
void consultas(Socio socios[], Asociado asociados[],Contador &contador,Factura facturas[]);
//función para cancelar suscripción de un socio o eliminar un asociado
void cancelar_suscripcion_socio(Socio socios[],Asociado asociados[], Contador &contador);

void ventana_socios_activos(Socio socios[],Asociado asociados[],Contador &contador);

void listado_socios_retirados(Socio socios[],Asociado asociados[],Contador &contador);

void listado_facturas_pendientes(Factura facturas[], Contador &contador);

//********************* DECLARACION FUNCIONES ESTETICAS *************

//funciones respecto al cursor flecha
void Creaflechas(Flecha & flecha, int ejeX ,  int ejeY  ,int tecla , int saltoX ,int saltoY ,int limiteXi, int limiteXf, int limiteYi, int limiteYf );
void Flechamover(Flecha & flecha, bool simetria, bool si_hora);

//Reloj estetico
void Hora();

//Usara los ejes para devolver la opción elegida
char conexion_menuPrincipal(Flecha & flecha);

//ventana estetica de la opción afiliar_socio
void ventana_afiliar_socio();

//función estetica donde se guarda a la familia simpsom
void fotos_perfil(int x, int i, int col, int n);

//función que retorna un numero ramdon
int ramdonNum(int start, int end);
//función aumentar fondos.
void ventana_aumentar_fondos_socio(Socio socios[],Asociado asociados[], Contador &contador);
//función creadora de ventanas
void ventana(int ejeX, int ejeY,int ejeXi, int ejeYi);

//función que va ligada a afiliar_socio, estetica pero recibe la decision del usuario para guardar al socio.
bool ventana_contrato(Socio socios[],Contador &contador);

//función que va ligada a afiliar_asociado, la cual es totalmente estetica.
bool ventana_afiliar_asociado(Socio socios[], Asociado asociados[],Contador &contador, int socio_pos, int asociado_pos, char usuario);

//función auxiliar estetica, a la hora de mostrar la ventana de asociado buscando un socio.
void venta_asociado_buscar_socio(Socio socios[],Asociado asociados[], Contador &contador);

//función auxiliar estetica, la cual se encarga de borrar los espacios de mensajes.
void borrador_mensajes(int xi, int yi, int xf, int yf, int col);

//función que recibe los structs de socios y asociados, junto a los cantadores y una variable bool, con la cual 
//identificar si el usurio ingresado sea un socio o asociado.
int busqueda_usuario_nombre(Socio socios[],Asociado asociados[], Contador &contador, char usuario, bool &socioUasociado);

//función auxiliar de estetica, utilizada para limpiar espacios.
void eliminar_Espacios(char cadena[]);

//función estetica con la cual registramos el consumo de un factura, ya sea de un socio o asociado.
void ventana_registrar_consumo(Socio socios[],Factura facturas[],Asociado asociados[], Contador &contador);

void pantalladeinicio(int x, int y);

void salirPro(int x, int y, int i);

// ********** FUNCION DEL PUNTO 1 - AFILIAR SOCIO ***************
// recibe el struct de socio y el de contador para saber en que posicion guardarlo
void afiliar_socio(Socio socios[],Asociado asociados[], Contador &contador, int socio_pos, char usuario){
	
	//char usuario = N, nuevo socio guardar, E, editar socio ya existente
	
	//INTRODUCIR NOMBRE SOCIO

	do{
		
		//se llama a la ventana estetica
		system("color 87");
		ventana_afiliar_socio();
		
			if(usuario == 'N'){
				socio_pos = contador.N_socios;
			}
			
			if(usuario == 'E'){
				
				color(h,142);
				ventana(76,3,40,0);
				gotoxy(43,1); color(h,142); cout << " APARTADO MODIFICAR INFO SOCIO";
				
				gotoxy(58,9); color(h,142); cout<<socios[socio_pos].datos.cedula;
					
				//pide el dato
				gotoxy(70,18); color(h,142);
					
				if(socios[socio_pos].suscripcion == true){
					cout<<" [V.I.P]";
				}
				else{
					cout<<" [REGULAR]";
				}
				
				gotoxy(52,20); color(h,138); cout<<std::fixed<<std::setprecision(2)<<socios[socio_pos].fondos;
					
			}
		
		//Asignamos el color 
		color(h,143); ventana(27,17,6,5);
		
		if(usuario == 'N'){
			//generamos una foto de manera random, basandos en la familia simpson.
			socios[socio_pos].foto = ramdonNum(1, 5);
		}
		
		//imprimimos la foto.
		fotos_perfil(7, 6,240,socios[socio_pos].foto);
		
		gotoxy(9,17); color(h,142); cout << "FOTO DEL SOCIO";
	
		
		//apartado de ingresar nombre, while infinito para poder hacer todas las validaciones necesarias
		while(1){	
				
				gotoxy(52,7); color(h,142); cout << "                                                         ";
				
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				
				//Imprimimos una información de ayuda al usuario. 
			
				if(usuario == 'N'){
					
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la suscripcion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				
				}
				else{
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la edicion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				}
				
				
				gotoxy(52,7);
				//pqueño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
				
				//Validamos que si el usurio presiones "ESC", se cancela el registro de la suscripción.	
				if(tecla == 27){
					return;
				}
				
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				
				gotoxy(40,27); color(h,10); cout << " INGRESE EL NOMBRE DEL SOCIO ";
				
				//Guardamos el nombre que digite el usuario.
				gotoxy(52,7); color(h,142); fflush(stdin); gets(socios[socio_pos].datos.nombre);
				
				//Eliminamos los espacios del inicio y del final de la cadena.
				eliminar_Espacios(socios[socio_pos].datos.nombre);
				
				//Variable para validar que el nombre no contenga ningún tipo de número.
				bool no_num = false;
				
				//validacion del tamaño del nombre, no puede estar vacio ni superar 50 caracteres
				while(strlen(socios[socio_pos].datos.nombre) > 50 or strlen(socios[socio_pos].datos.nombre) <= 1){
					gotoxy(52,7); color(h,142); cout << "                                                         ";
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(20,27); color(h,4); cout << " ENTRADA INVALIDA, 50 ES EL MAXIMO DE CARACTERES DEL NOMBRE Y 1 EL MINIMO";
					//Como el nombre anterior fue invalido, le volvemos a pedir el nombre.
					gotoxy(52,7); color(h,142); fflush(stdin); gets(socios[socio_pos].datos.nombre);
					//Eliminamos los espacios del inicio y del final de la cadena.
					eliminar_Espacios(socios[socio_pos].datos.nombre);
				}
				//validacion para que no ingresen numeros en el nombre
				while(es_Char(socios[socio_pos].datos.nombre)){
					gotoxy(52,7); color(h,142); cout << "                                                         ";
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(40,27); color(h,4); cout << " ENTRADA INVALIDA, CARACTERES NUMERICOS";
					no_num = true;
					//Como el nombre anterior fue invalido, le volvemos a pedir el nombre.
					gotoxy(52,7); color(h,142); fflush(stdin); gets(socios[socio_pos].datos.nombre);
					//Eliminamos los espacios del inicio y del final de la cadena.
					eliminar_Espacios(socios[socio_pos].datos.nombre);
				}
				
				if(no_num == true){
					continue;
				}
		
				break;
		
		}
		//se trasnforma en mayusculas toda la cadena para mejor manejo de la misma
		strupr(socios[socio_pos].datos.nombre);
	
	
	//INTRODUCIR IDENTIFICACION
	if(usuario == 'N'){
		
			//Variable para validar que la cedula no sea invalida.
		bool cedula_noValida = false;
		
		do{
			
				gotoxy(58,9); color(h,142); cout << "                                      ";
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(5,27); color(h,4); cout << " Si desea cancelar la suscripcion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				
				gotoxy(58,9);
				
				//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return;
				}
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(20,27); color(h,10); cout << " INGRESAR NUMERO DE IDENTIFICACION DE LA PERSONA C.C [ 3 - 9 DIGITOS ] ";
				
				//un bool que mas abajo se mandara por referencia en la funcion validar_Cedula_Socio
				if(cedula_noValida == true){
					
					gotoxy(58,9); color(h,142); cout << "                                      ";
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(30,27); color(h,4); cout << " LA CEDULA INGRESADA YA ESTA REGISTRADA ";
					gotoxy(58,9);
	
				}
			
			
				//se pide la cadena de cedula
				gotoxy(58,9); color(h,142); fflush(stdin); gets(socios[socio_pos].datos.cedula);
				
				//Eliminamos los espacios del inicio y del final de la cadena.
				eliminar_Espacios(socios[socio_pos].datos.cedula);
				
				//verificar que la cedula ingresada sea de tipo numerico
				while(es_Entero(socios[socio_pos].datos.cedula)){
					gotoxy(58,9); color(h,142); cout << "                                      ";
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(30,27); color(h,4); cout << " ENTRADA INVALIDA, CARACTERES NO NUMERICOS";
					//Como la cedula anterior fue invalida, le volvemos a pedir el cedula.
					gotoxy(58,9); color(h,142); fflush(stdin); gets(socios[socio_pos].datos.cedula);
					//Eliminamos los espacios del inicio y del final de la cadena.
					eliminar_Espacios(socios[socio_pos].datos.cedula);
				}
	
			
			//funcion que valida que no exista una cedula ya agregada en los datos de socios
		}while(validar_cedula_ingreso(socios, asociados,contador, socios[socio_pos].datos.cedula,cedula_noValida));
		
		
	}

	
		
		//INTRODUCIR EDAD
		
		
		do{	
				gotoxy(40,11); color(h,142); cout << "                                      ";
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				
				if(usuario == 'N'){
					
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la suscripcion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				
				}
				else{
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la edicion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				}
				
			
				gotoxy(40,11);
				
				//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return;
				}
				
				gotoxy(40,11); color(h,142); cout << "                                      ";
		
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(30,27); color(h,10); cout << " INTRODUCIR EDAD, LA EDAD VALIDA ES DE [ 18 - 120 ]";
				//Guardas la edad que digite el usuario.
				gotoxy(40,11); color(h,142); fflush(stdin); gets(socios[socio_pos].datos.edad);
				//Eliminamos los espacios del inicio y del final de la cadena.	
				eliminar_Espacios(socios[socio_pos].datos.edad);
				
				//valida que la edad sea de caracter numerico
				if(es_Entero(socios[socio_pos].datos.edad)){
					continue;
				}
			
				//valida que la persona sea mayor de edad y no tan viejo juajauja
				if(atoi(socios[socio_pos].datos.edad)>=18 and atoi(socios[socio_pos].datos.edad) <= 120){
					break;
				}
				
		}while(true);
		
		//INTRODUCIR GENERO
			
		
		do{
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				
				if(usuario == 'N'){
					
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la suscripcion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				
				}
				else{
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la edicion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
				}
				
			
				gotoxy(50,13);
				
				//pqueño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
				int tecla = _getch();
					
				if(tecla == 27){
					return;
				}
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(20,27); color(h,10); cout << " INTRODUCIR GENERO M [masculino] - F [femenino] - O [otro]";
			
			//Guardamos el sexo del socio.
			gotoxy(50,13); color(h,142); fflush(stdin); gets(socios[socio_pos].datos.sexo);
			//Eliminamos los espacios del inicio y del final de la cadena.
			eliminar_Espacios(socios[socio_pos].datos.sexo);
			
			//validar que sea letra
			while(es_Char(socios[socio_pos].datos.sexo)){
				gotoxy(50,13); color(h,142); cout << "                                                        ";
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(30,27); color(h,4); cout << " ENTRADA INVALIDA, CARACTERES NUMERICOS";
				//Como el sexo anterior fue invalido, volvemos a pedirlo.
				gotoxy(50,13); color(h,142); fflush(stdin); gets(socios[socio_pos].datos.sexo);
				//Eliminamos los espacios del inicio y del final de la cadena.
				eliminar_Espacios(socios[socio_pos].datos.sexo);
			}
		
			//validar que sea un solo caracter
			while(strlen(socios[socio_pos].datos.sexo) > 1){
				gotoxy(50,13); color(h,142); cout << "                                                    ";
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(20,27); color(h,4); cout << " ENTRADA INVALIDA, LAS OPCIONES SON M [masculino] - F [femenino] - O [otro] ";
				//Como el sexo anterior fue invalido, volvemos a pedirlo.
				gotoxy(50,13); color(h,142); fflush(stdin); gets(socios[socio_pos].datos.sexo);
				//Eliminamos los espacios del inicio y del final de la cadena.
				eliminar_Espacios(socios[socio_pos].datos.sexo);
			}
			
			//el caracter se pasa a mayuscula
			socios[socio_pos].datos.sexo[0] = toupper(socios[socio_pos].datos.sexo[0]);
			
			//se valida que este en el rango
			while(socios[socio_pos].datos.sexo[0] != 'M' and socios[socio_pos].datos.sexo[0] != 'F' and socios[socio_pos].datos.sexo[0] != 'O'){
				gotoxy(50,13); color(h,142); cout << "                                                    ";
				//Llamamos a la función para borrar la información anterior a esta.
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(20,27); color(h,4); cout << " ENTRADA INVALIDA, LAS OPCIONES SON M [masculino] - F [femenino] - O [otro] ";
				//Como el sexo anterior fue invalido, volvemos a pedirlo.
				gotoxy(50,13); color(h,142); fflush(stdin); gets(socios[socio_pos].datos.sexo);
				//Eliminamos los espacios del inicio y del final de la cadena.
				eliminar_Espacios(socios[socio_pos].datos.sexo);
				//Pasamos la el sexo digitado a mayúscula.
				socios[socio_pos].datos.sexo[0] = toupper(socios[socio_pos].datos.sexo[0]);
			}
	
			
		}while(socios[socio_pos].datos.sexo[0] != 'M' and socios[socio_pos].datos.sexo[0] != 'F' and socios[socio_pos].datos.sexo[0] != 'O');
		
	
		//INTRODUCIR SUSCRIPCION
		if(usuario == 'N'){
		static int vip = 0, regular = 0; 		
			do{
			
				//auxiliar de la suscripcion
				char suscripcion_Aux[5];
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(5,27); color(h,4); cout << " Si desea cancelar la suscripcion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
					
				
					gotoxy(70,18);
					
					//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
					int tecla = _getch();
						
					if(tecla == 27){
						return;
					}
				//Llamamos a la función para borrar la información anterior a esta.	
				borrador_mensajes(3, 26, 116, 28, 0);
				gotoxy(10,27); color(h,10); cout << " [1] PARA V.I.P (min. $1,000,000 - max. $5,000,000)  [0] PARA REGULAR (min. $300,000 - max. $2,000,000) ";
			
			
				//pide el dato
				gotoxy(70,18); color(h,142); fflush(stdin); gets(suscripcion_Aux);
				
				//Eliminamos los espacios del inicio y del final de la cadena.
				eliminar_Espacios(suscripcion_Aux);
				
				//valida que solo sea la entrada no sea nula ni  mayor a un caracter
				if(strlen(suscripcion_Aux) == 0 or strlen(suscripcion_Aux) > 1){
					gotoxy(70,18); color(h,142); cout << "                                        ";
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(30,27); color(h,4); cout << " ENTRADA INVALIDA, NO CORRESPONDE A LAS OPCIONES ";
					continue;
				}
				
				//valida que solo ingresen 1 o 0
				if(suscripcion_Aux[0] != '0' and suscripcion_Aux[0] != '1'){
					
					gotoxy(70,18); color(h,142); cout << "                                        ";
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(30,27); color(h,4); cout << " ENTRADA INVALIDA, NO CORRESPONDE A LAS OPCIONES ";
					continue;
				}
				
				fflush(stdin);
				//valida que se pueda ingresar V.I.P ( por cada 3 socios regulares se puede ingresar 2 V.I.P )	
				if(regular >= 3){
					 
					 if(vip >= 1){
					 	vip = 0 ;
					 	regular = 0;
					 	
					 }
					 //si se puede ingresar V.I.P y el usuario eligio 1 de vip, se guarda
					if(suscripcion_Aux[0] == '1'){
						socios[socio_pos].suscripcion = true;
						//se aumenta el contador de socios V.I.P
						vip++;
						break;
					}
				}
				//si NO se puede ingresar V.I.P y el usuario elijio 1 de vip, se le pide el dato de nuevo
				else if(suscripcion_Aux[0] == '1'){
					gotoxy(70,18); color(h,142); cout << "                                        ";
					//Llamamos a la función para borrar la información anterior a esta.
					borrador_mensajes(3, 26, 116, 28, 0);
					gotoxy(7,27); color(h,4); cout << " POR EL MOMENTO EL REGISTRO DE SOCIOS V.I.P ESTA DESHABILITADO, HASTA EL NUEVO INGRESO DE SOCIOS REGULARES";
					getch();
					continue;
				}
				// si el usuario eligio 0 de regular, no hay ninguna restriccion con esto, asi que se guarda
				if(suscripcion_Aux[0] == '0'){
					socios[socio_pos].suscripcion = false; 
					//se aumenta el contador de socios regulares
					regular++;
					break;
				}
				
				
			}while(true);	
			
		}
	
		
		
			
		
		//INGRESAR FONDOS
		
		
		/*	
		Cuando un nuevo socio se afilia al club, debe contar con un fondo inicial para cubrir sus consumos y
		los de las personas afiliadas, El monto del fondo inicial se determina según el tipo de suscripción del
		socio: los socios regulares con $300.000 y los socios VIP con $1.000.000. Los socios pueden aumentar
		sus fondos, pero tienen una restricción máxima, que también depende del tipo de suscripción, de la
		siguiente manera: regulares $2 ´000.000 y VIP $5 ´000.000.*/
		
		if(usuario == 'N'){
			
			char numAux[32]; //la cant de digitos de un numero float son 32 bit =  32 digitos incluyendo el signo

			if(socios[socio_pos].suscripcion == true){
				
				do{
					
					do{
						//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(5,27); color(h,4); cout << " Si desea cancelar la suscripcion presione [ESC] , para seguir con la afiliacion presione cualquier otra tecla "; 
					
						gotoxy(52,20); color(h,142); cout << "                              ";		
					
						gotoxy(52,20);
						
						//pequeño gecth antes de pedir el dato para saber si desean cancelar la suscripcion
						int tecla = _getch();
							
						if(tecla == 27){
						
							contador.N_sociosVip--;
						
							return;
						}
						
						//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(25,27); color(h,10); cout << " FONDOS V.I.P desde $1,000,000 hasta $5,000,000  ";	
						
						
						gotoxy(52,20); color(h,142); cout << "                              ";
						//pedimos el fondo del socio vip.		
						gotoxy(52,20); color(h,138); fflush(stdin); gets(numAux);
						//Eliminamos los espacios del inicio y del final de la cadena.	
						eliminar_Espacios(numAux);
						
					}while(validar_float(numAux));
					
					if(atof(numAux) < 1000000){
							//Llamamos a la función para borrar la información anterior a esta.
							borrador_mensajes(3, 26, 116, 28, 0);
							gotoxy(20,27); color(h,4); cout << " FONDOS INSUFICIENTES, EL MONTO MINIMO ES DE $1,000,000 cop  ";	
					}
					else if(atof(numAux) > 5000000){
							//Llamamos a la función para borrar la información anterior a esta.
							borrador_mensajes(3, 26, 116, 28, 0);
							gotoxy(20,27); color(h,4); cout << " FONDOS EXCEDEN EL LIMITE, EL MONTO MAXIMO ES DE $5,000,000 cop  "; 
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
						
							gotoxy(52,20); color(h,142); cout << "                              ";		
						
							gotoxy(52,20);
					
							int tecla = _getch();
								
							if(tecla == 27){
								
								contador.N_sociosRegular--;
								
								return;
							}
						//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);	
						gotoxy(25,27); color(h,10); cout << " FONDOS REGULAR desde $300,000 hasta $2,000,000 ";
								
						gotoxy(52,20); color(h,142); cout << "                              ";		
						//pedimos el el fondo regular.
						gotoxy(52,20); color(h,138); fflush(stdin); gets(numAux);
						
						//Eliminamos los espacios del inicio y del final de la cadena.
						eliminar_Espacios(numAux);		
						
					}while(validar_float(numAux));
					
					if(atof(numAux) < 300000){
						//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(20,27); color(h,4); cout << " FONDOS INSUFICIENTES, EL MONTO MINIMO ES DE $300,000 cop  ";
					}
					else if(atof(numAux) > 2000000){
						//Llamamos a la función para borrar la información anterior a esta.
						borrador_mensajes(3, 26, 116, 28, 0);
						gotoxy(20,27); color(h,4); cout << " FONDOS EXCEDEN EL LIMITE, EL MONTO MAXIMO ES DE $2,000,000 cop  ";  
					}else{
						break;
					}
						
				}while(true);
		
			
				//Pasamos la cadena a float.
				socios[socio_pos].fondos = atof(numAux); 
				
			}
			
			
		}
		
		if(usuario == 'E'){
			return;
		}
		
		
	}while(ventana_contrato(socios,contador));	
	
}

//función auxiliar par validar que la cadena no este fuera del rango, que no se encuentra registrada en otro socio o asociado y que no sea un caracter especial.
bool validar_cedula_ingreso(Socio socios[], Asociado asociados[],Contador &contador, char auxCedula[], bool &no_valido){
	
	//Guardamos el tamaño de la cadena.
	int size_AuxCedula = strlen(auxCedula);
	
	//llamamos a la función es_Entero para validar que no sea una letra o caracter especial.
	if(es_Entero(auxCedula)){
		return true;
	}
	//validamos que la cedula no sea menor a 3 ni mayor a 9 espacios.
	else if(!(size_AuxCedula >= 3 and size_AuxCedula <= 9)){
		return true;
	}
	
	else{
		
		//for para validar que la cedula no sea igual a la de otro socio.
		for(int i = 0; i < contador.N_socios; i++){
			
			if(!strcmp(socios[i].datos.cedula,auxCedula) and socios[i].datos.estado == true){
				no_valido = true;
				return true;
			}
	
		}
		
		//for para validar que la cedula no sea igual a la de otro asociado.
		for(int i = 0; i < contador.N_asociados; i++){
			
			if(!strcmp(asociados[i].datos.cedula,auxCedula) and asociados[i].datos.estado == true){
				no_valido = true;
				return true;
			}
	
		}
	}
	
	no_valido = false;
	return false;
}



//función auxiliar para validar que no se pueda ingresar 2 socios vip sin antes crearse 5 socios regulares. 
bool validar_regisvip(int numSociosRegulares, int numSociosVIP){
    
  // Verificar el número total de socios
    int totalSocios = numSociosVIP + numSociosRegulares;
    

    // Calcular el número máximo de socios VIP permitidos
    int maxSociosVIP = (totalSocios / 5) * 2;

    // Verificar el número máximo de socios VIP
    if (numSociosVIP > 2 || numSociosVIP > maxSociosVIP) {
        return false;
    }

    // Verificar el número máximo de socios regulares por cada 5 socios
    int maxSociosRegulares = (totalSocios / 5) * 3;
    if (numSociosRegulares > maxSociosRegulares) {
        return false;
    }

    // Si todas las condiciones se cumplen, la entrada es válida
    return true;

}


//función que recibe los datos de socios y asociados, a su vez recibe una cadena de caracteres de nombre para comparar con los ya registrados en socios y asociados
//también mandamos dos arrays boleanos de coincidencias socios y asociados y char usuario S = socios a buscar , A = asociados a buscar y T = todos los usuarios. 
bool buscar_usuario_porNombre(Socio socios[],Asociado asociados[], Contador &contador, char auxCadena[], bool coincidencias_socios[],bool coincidencias_asociados[], char usuario){
	
	//Pasamos la cadena a mayúscula para comparar.
	strupr(auxCadena);
	
	//Buscamos las coincidencias de los socios S = socios o T = todos.
	if(usuario == 'S' or usuario == 'T'){
		
		//for para buscar si el socio se encuentra registrado.	
		for(int i = 0; i < contador.N_socios; i++){
			
			//guardamos el tamaño de la cadena.	
			int size_auxCadena = strlen(auxCadena);
			//for que compara caracter por caracter, si son iguales en todos las iteriaciones el socio se encuentra. 
			for(int k = 0; auxCadena[k] != '\0'; k++){
				if(auxCadena[k] == socios[i].datos.nombre[k]){
					size_auxCadena--;
				}
			}
			
			//Y si el tamaño de la cadena fue 0, hubo coincidencia con el socio en la posición I.	
			if(size_auxCadena == 0){
				//Mandamos un true en la posición I del socio, para mandar que existe.
				coincidencias_socios[i] = true;
			}
			
			else{
				//Mandamos un true en la posición I del socio, para mandar que no existe.
				coincidencias_socios[i] = false;
			}
				
		}
		
	}
	
	//Buscamos las coincidencias de los asociados A = asociados o T = todos.
	if(usuario == 'A' or usuario == 'T'){
		
		//for para buscar si el asociado se encuentra registrado.	
		for(int i = 0; i < contador.N_asociados; i++){
			
			//guardamos el tamaño de la cadena.		
			int size_auxCadena = strlen(auxCadena);
			
			//for que compara caracter por caracter, si son iguales en todos las iteriaciones el asociado se encuentra. 
			for(int k = 0; auxCadena[k] != '\0'; k++){
				if(auxCadena[k] == asociados[i].datos.nombre[k]){
					size_auxCadena--;
				}
			}
			
			//Y si el tamaño de la cadena fue 0, hubo coincidencia con el asociado en la posición I.	
			if(size_auxCadena == 0){
				//Mandamos un true en la posición I del asociado, para mandar que existe una coincidencia.
				coincidencias_asociados[i] = true;
			}
			else{
				//Mandamos un true en la posición I del asociado, para mandar que no existe no coincidencia.
				coincidencias_asociados[i] = false;
			}
				
		}
	
	}
	

	if(usuario == 'S' or usuario == 'T'){
		
		//For para validar que existan coincidencias ya encontraadas en los socios.
		for(int i = 0; i < contador.N_socios; i++){
			if(coincidencias_socios[i] == true){
				return false; //hay un socio con coincidencia
			}
		}
	}
	if(usuario == 'A' or usuario == 'T'){	
		
		//For para validar que existan coincidencias ya encontraadas en los asociados.
		for(int i = 0; i < contador.N_asociados; i++){
			if(coincidencias_asociados[i] == true){
				return false; //hay un asociado con coincidencia
			}
		}
	}
	
	return true;
	
}

//fución para  validar de '.' flotantes y ',' recibe una cadena de caracteres.
bool validar_float(char num[]){
	
	int cant_puntos = 0, cant_comas = 0;
	bool borrar_comas = false;
	bool cientos_millones = false;
	

	//For que recorrera todo la cadena.
	for(int i = 0; num[i] != '\0'; i++){
		
		// Si en la posición 0 de la cadena es un número no valido. 
		if(num[i] == ',' and i != 0){
			
			if(strlen(num) == 5 and num[1] == ',' ){
				borrar_comas = true;
			}	
			else if(strlen(num) == 6 and num[2] == ',' ){
				borrar_comas = true;
			}
			
			//Al conocer que el fondo minimo el cual es 300,000 sabemos que solo puede haber una "," en la posición [3].
			else if(strlen(num) == 7 and num[3] == ',' ){
				
				//Mandamos true al encontrar comas en la posición [3].
				borrar_comas = true;
			}
			//Al conocer que el fondo máximo el cual es 5,000,000 sabemos que solo puede haber dos "," en la posición [1] y [4].
			else if((strlen(num) == 9 and num[1] == ',') or (strlen(num) == 8 and num[4] == ',' and cant_comas == 1)){
				cant_comas++;
				//Mandamos true al encontrar comas en la posición [1] y en la posición [4].
				borrar_comas = true;
			}
			
		}
		
		//Si borrar_comas = true
		if(borrar_comas){
			
			//for para eliminar las comas.
			for(int k = i; num[k] != '\0'; k++){
					
					//Codiicional que elimina la coma y acorta la cadena.	
					if(num[k+1] == '\0'){
						num[k] = '\0';
					}
					else{
						char aux = num[k+1];
						num[k] = aux;
					}
							
			}
			
			borrar_comas = false;
			
		}
		
		//Si en la posición 0 de la cadena hay un "." es invalido.
		if(num[i] == '.' and i == 0){
			return true;
		}
		//Si hay más de un "." seria invalido, ya un número decimal solo puede tener una.
		if(cant_puntos > 1){
		
			return true;
		}
		//cada que encuentre una coma, se suma la cantida de puntos.
		if(num[i] == '.'){
			cant_puntos++;
		}
		
		//Validamos que no sea un caracter especial.
		else if(!isdigit(num[i])){
		
			return true;
		}
		
	}
	
	return false;
	
}

//función auxiliar para validar que la cadena que se pida no contenga letras o caracteres especiales.
bool es_Entero(char cadena[]){
	
	for(int i = 0; i < strlen(cadena); i++){
					
		if(!(isdigit(cadena[i]))){
			return true;
		}
	}
	return false;
}

//función para validar que la cadena ingresa sea una cadena de caracteres sin números ni caracteres especiales.
bool es_Char(char cadena[]){
	
	//for para recorrer caracter por caracter la cadena y validar que no sea un número ni caracter especial.
	for(int i = 0; i < strlen(cadena); i++){
		
		//condicial para validar que el caracter no sea un espacio.
		if(cadena[i] != ' '){
			if(!(isalpha(cadena[i]))){
				return true;
			}
		}			
		
	}
	return false;
	
}

//función para eliminar los espacio del comienzo y del final.
void eliminar_Espacios(char cadena[]) {
	
	//Se decleclara inicio = la primer posición de la cadena que sea difirente de un espacio o tabulación.
	//Se declaclara final =  la ultima posición de la cadena que sea difirente de un espacio o tabulación.
    int i, j, inicio, final;
    
    //for desde el inicio de la cada cadena en la cual se guardaara la primera posición de esta que no sea un espacio o tabulación.
    for (i = 0; cadena[i] == ' ' || cadena[i] == '\t'; i++) {}
    
    inicio = i;
    
    //for desde el final de la cada cadena en la cual se guardaara la ultima posición de esta que no sea un espacio o tabulación.
    for (i = strlen(cadena) - 1; i >= 0 && (cadena[i] == ' ' || cadena[i] == '\t'); i--) {}
    
    final = i;
    
    //for para organizar la cadena.
    for (i = inicio, j = 0; i <= final; i++, j++) {
        cadena[j] = cadena[i];
    }
    
    cadena[j] = '\0';
}
