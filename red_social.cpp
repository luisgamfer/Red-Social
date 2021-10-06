/***************************************************************************/
/* DATOS DEL ALUMNO														   */
/* ----------------														   */
/*																		   */
/* APELLIDOS, NOMBRE: Gámez Fernández Luis Francisco													   */
/* DNI:	45719963B													   */
/***************************************************************************/

#include <iostream>
#include <string>
#include <array>

using namespace std;

//----------------------------------------------------------------------------
// USUARIO

//----------------------------------------------------------------------------
// Constantes
const unsigned MAX_AMIGOS = 100; // Máximo número de amigos
const unsigned MAX_MENSAJES = 1000; // Máximo número de mensajes

typedef unsigned Resul;

// Resultados de operación
const Resul OK = 0, 			// correcto
            YA_EXISTE = 1,		// el elemento ya existe
            NO_EXISTE = 2, 		// el elemento no existe
            LISTA_LLENA = 3,	// la lista está llena
            CADENA_VACIA = 4, 	// la cadena está vacía
            TIPO_INCORRECTO = 5;// El tipo de mensaje es incorrecto

//----------------------------------------------------------------------------
// Tipos

// Mensaje en la red social
struct Mensaje {
	string id; // Identificador del usuario que envía el mensaje
	string msg; // Texto del mensaje
};

typedef array<string, MAX_AMIGOS> ArrayAmigos; // Array de cadenas con identificadores de amigos
struct Amigos {
	ArrayAmigos amigos; // Array de amigos
	unsigned num_amigos; // Número de amigos
};

typedef array<Mensaje, MAX_MENSAJES> ArrayMensajes; // Array de cadenas con los mensajes del muro
struct Mensajes {
	ArrayMensajes mensajes; // Array de mensajes
	unsigned num_mensajes; // Número de mensajes
};

struct Usuario {
	string id; // Identificador del usuario
	Amigos lamigos; // Lista de amigos
	Mensajes muro; // Muro de mensajes
};
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Prototipos de funciones de usuario

//----------------------------------------------------------------------------
// Crea un usuario con identificador cadena vacía (""),
// con una lista vacía de amigos y un muro sin mensajes
// PARÁMETROS:
//		- u (S): usuario que va a inicializarse
void crear_usuario(Usuario &u);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Devuelve el identificador del usuario
string consultar_id(Usuario &u);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Devuelve la lista de amigos del usuario
// PARÁMETROS:
//		- u (E): un usuario
//		- amgs (S); lista de amigos
void consultar_amigos(const Usuario& u, Amigos &amgs);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Devuelve la lista de mensajes del muro del usuario
// PARÁMETROS:
//		- u (E): un usuario
//		- mr (S): lista de mensajes del muro del usuario 'u'
void consultar_muro(const Usuario &u, Mensajes &mr );
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Modifica el identificador del usuario
// PARÁMETROS:
//		- u (ES): un usuario
// 		- identif (E): nuevo identificador para el usuario
//		- res (S): resultado de la operación
// Si 'identif' no está vacía, se modifica el identificador
//		del usuario con el nuevo 'identif' y se devuelve
//		OK a través de 'res'.
//		Si no, se devuelve CADENA_VACIA a través de 'res'
void modificar_id(Usuario &u, const string &identif, Resul &res);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Busca un amigo en la lista de amigos del usuario
// PARÁMETROS:
//		- u (E): un usuario
//		- id_amigo (E): identificador de un amigo
//		- pos (S): posición del array donde está almacenado el amigo
//		- res (S): resultado de la operación
// Si el amigo 'id_amigo' está en la lista de amigos del usuario,
//		se devuelve su posición en el array a través de 'pos' y OK en 'res'.
//		Si no, si no existe el usuario, se devuelve NO_EXISTE a través de 'res'
//		y en 'pos' estará almacenado el número de amigos del usuario
void buscar_amigo(const Usuario &u, const string &id_amigo, unsigned &pos ,Resul &res);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Inserta un nuevo amigo en la lista de amigos del usuario
// PARÁMETROS:
//		- u (ES): un usuario
//		- id_amigo (E): identificador de un amigo
//		- res (S): resultado de la operación
// Si el 'id_amigo' no está en la lista de amigos y la lista de
//		amigos no está llena, el nuevo amigo se inserta
// 		en la lista de amigos del usuario y se devuelve OK a través de
//		'res'. Si no, si el amigo ya estaba en la lista,
//		se devuelve 'YA_EXISTE' a través de 'res'. Si no, si la lista
//		está llena, se devuelve 'LISTA_LLENA' a través de 'res'.
void anyadir_amigo(Usuario &u, const string &id_amigo, Resul &res);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Elimina un usuario de la lista de amigos del usuario
// PARÁMETROS:
//		- u (ES): un usuario
//		- id_amigo (E): identificador de un amigo
//		- res (S): resultado de la operación
// Si el 'id_amigo' está en la lista de amigos, el amigo se elimina
// 		de la lista de amigos del usuario y se devuelve OK a través de
//		'res'. Si no, si el amigo no estaba en la lista,
//		se devuelve 'NO_EXISTE' a través de 'res'.
void eliminar_amigo(Usuario &u, const string &id_amigo, Resul &res);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Publica un mensaje en el muro del usuario
// PARÁMETROS:
//		- u (ES): un usuario
//		- msg (E): un mensaje (con id de usuario y texto)
//		- res (S): resultado de la operación
// Si el 'msg' es correcto (el identificador de usuario y el texto
// 		del mensaje no están vacíos) y cabe en el muro,
//		el mensaje se inserta al final de la lista de mensajes y
//		se devuelve OK a través de 'res'.
//		Si no, si el mensaje es incorrecto (el id de usuario o el mensaje
//		están vacíos), se devuelve CADENA_VACIA a través de 'res'.
//		Si no, si el mensaje no cabe en la lista, se devuelve LISTA_LLENA
//		a través de 'res'
void publicar_msg(Usuario &u, const Mensaje& msg, Resul &res);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Saca por pantalla todos los datos del usuario, incluyendo su lista de
// amigos y todos los mensajes de su muro, en el orden en el que están
// almacenados en memoria.
/* Ejemplo de formato de salida por pantalla:
		----------------------------------------
		Identificador de usuario: Luis Mayo
		Lista de amigos:
		Ana Ruiz
		Pepe Gomez
		Johny
		Mensajes en el muro:
		[Johny]: Espero verte manyana. Confirma.
		[Ana Ruiz]:	Cena de despedida al final del mes. Contamos contigo y
		tu pareja.
		[Johny]: Curso de Android a 20 euros.
		[Johny]: Finde en Madrid?
		----------------------------------------
*/
void escribir_usuario(const Usuario &u);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// RED SOCIAL

//----------------------------------------------------------------------------
// CONSTANTES
const unsigned MAX_USUARIOS = 100;

typedef unsigned TipoMsg;

// Naturaleza del mensaje enviado
const TipoMsg
	PUBLICO = 0, 		// Mensaje público
	RESTRINGIDO = 1,	// Mensaje restringido a la lista de amigos
	PRIVADO = 2;			// Mensaje privado para un amigo

//----------------------------------------------------------------------------
// Tipos

typedef array<Usuario, MAX_USUARIOS> ArrayUsuarios; // Array de usuarios

struct RedSocial {
	ArrayUsuarios lusuarios; // Lista de usuario
	unsigned num_usuarios; // Número de usuarios
};

//----------------------------------------------------------------------------
// Prototipos de funciones de usuario

//----------------------------------------------------------------------------
// Crea (inicializa) la red social con la lista de usuarios vacía, es decir,
// con 'num_usuarios' igual a cero.
// PARÁMETROS:
//		- red (S): una red social
void crear_red(RedSocial &red);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Busca un usuario en la red
// PARÁMETROS:
//		- red (E): una red social
//		- id (E): identificador de un usuario
//		- pos (S): posición del array donde está almacenado el usuario
//		- res (S): resultado de la operación
// Si el usuario 'id' está en la lista de usuarios de la red social,
//		se devuelve su posición en el array a través de 'pos' y OK en 'res'.
//		Si no, si no existe el usuario, se devuelve NO_EXISTE a través de 'res'
//		y en 'pos' estará almacenado el número de usuarios actuales
// 		de la red social.
void buscar_usuario(const RedSocial &red, const string &id, unsigned &pos, Resul &res);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Inserta un nuevo usuario en la red social
// PARÁMETROS:
//		- red (ES): una red social
//		- id (E): identificador de usuario
//		- res (S): resultado de la operación
// Si el usuario con identificador 'id' no existe en la red social,
//		la lista de usuarios no está llena e 'id' no es una cadena vacía,
//		se inserta un usuario con identificador 'id' (con su lista de amigos
//		y muro vacíos) al final de la lista de usuarios de la red social.
// 		Si no, si el usuario ya existía en la red, se devuelve YA_EXISTE a través
//		de 'res'.
//		Si no, si la lista está llena, se devuelve LISTA_LLENA a través de
//		'res'.
//		Si no, si el 'id' está vacío, se devuelve CADENA_VACIA a través de
//		'res'.
void registrar(RedSocial &red, const string &id, Resul &res);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Elimina un usuario de la red social.
// PARÁMETROS:
//		- red (ES): una red social
//		- id (E): identificador de usuario
//		- res (S): resultado de la operación
// Si el usuario está registrado (existe) en la red, se elimina
//		el usuario de la red, su identificador se elimina de
//		las listas de amigos de todos los usuarios y se
// 		devuelve OK a través de 'res'.
//		Si no, se devuelve NO_EXISTE a través de 'res'.
void dar_de_baja(RedSocial &red, const string &id, Resul &res);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Hacer amigos a dos usuarios de la red. El usuario con identificador 'origen'
// recibe una petición de amistad por parte del usuario con identificador
// 'destino'. Dado el carácter "afable" de esta red social, las peticiones
// de amistad siempre son aceptadas.
// PARÁMETROS:
//		- red (ES): una red social
//		- origen (E): identificador del usuario que pide amistad
//		- destino (E): identificador del usuario que recibe la petición de
//				amistad.
// Si los usuarios con identificador 'origen' y 'destino' existen
//		en la red social, los usuarios no son amigos en este momento y las
//		listas de amigos de "origen" y "destino" no están llenas,
//		se añade 'origen' a la lista de amigos de
//		"destino" y viceversa, y se devuelve OK a través de 'res'.
//		Si no, si "origen" o "destino" no existen en la red, se devuelve
//		NO_EXISTE a través de 'res'.
//		Si no, si la lista de amigos de "origen" o de "destino" están llenas,
//		se devuelve LISTA_LLENA a través de 'res'.
void pedir_amistad(RedSocial &red, const string &origen, const string &destino, Resul &res);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Publica un mensaje en la red social.
// PARÁMETROS:
//		- red (ES): una red social
//		- id_origen (E): identificador del usuario que envía el mensaje
//		- id_destino (E): identificador del usuario que recibe el mensaje
//				si el tipo de mensaje es PRIVADO
//		- msg (E): mensaje enviado
//		- tipo (E): naturaleza del mensaje enviado
//		- res (S): resultado de la operación
// Si el usuario 'id_origen' existe en la red (si el tipo de mensaje
//		es privado, el usuario 'id_destino' debe existir en la red y tener amistad
//		con el usuario 'id_origen') y si el 'msg' no está vacío:
//      - si 'tipo' es PUBLICO, se considera un mensaje público y entonces
//				el mensaje es insertado en el muro de todos y cada uno de los
//			 	miembros de la red (excepto en el del usuario con identificador
//				‘id_origen’, que es el que lo envía) y se devuelve OK en 'res'.
//				En este caso, el parámetro ‘id_destino’ no se tiene en cuenta.
//      - si 'tipo' es RESTRINGIDO, se considera que es un mensaje restringido
//				a los amigos del usuario que lo envía y el mensaje es insertado
//			 	sólo en el muro de todos y cada uno de los usuarios amigos de
//				‘id_origen’. Se devuelve OK a través de 'res'.
//				En este caso el parámetro ‘id_destino’ no se tiene en cuenta.
//      - si 'tipo' es PRIVADO, se considera que es un mensaje privado dirigido
//				al amigo con identificador ‘id_destino’, de manera que el
//				mensaje es insertado sólo en el muro del usuario con
//				identificador ‘id_destino’. El resultado de esta operación (ya
//				sea OK o LISTA_LLENA) se devuelve a través de 'res'.
//		Si no, si el usuario 'id_origen' no existe, se devuelve NO_EXISTE
//				a travñes de 'res'; si el tipo de mensaje es PRIVADO y el
//				usuario 'id_destino' no existe en la red o los usuarios
//				'id_origen' e 'id_destino' no son amigos, se devuelve NO_EXISTE
//				a través de 'res'. Si el tipo de mensaje es incorrecto
//				(no es ni PRIVADO, ni PUBLICO, ni RESTRINGIDO) se devuelve
//				TIPO_INCORRECTO a través de 'res'.
//		Si no, si msg está vacio, se devuelve CADENA_VACIA a través de 'res'
void publicar_msg(RedSocial &red, const string &id_origen, const string &id_destino, const string &msg, const TipoMsg &tipo, Resul &res);
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Escribe por pantalla todos los datos de la red social, esto es, todos los
//		datos de todos los usuarios de la red social.
// PARÁMETROS:
// 		- red (E): una red social
/*
   El formato de salida por pantalla debe ser el siguiente:
		----------------------------------------
		Identificador de usuario: <Identificador>
		Lista de amigos:
		<Id. amigo 1>
		<Id. amigo 2>
		<Id. amigo 3>
		...
		Mensajes en el muro:
		[<Id. amigo>]: <Mensaje>
		[<Id. amigo>]: <Mensaje>
		...
		----------------------------------------
	Por ejemplo, para la figura mostrada se mostraría por pantalla:
		----------------------------------------
		Identificador de usuario: Luis Mayo
		Lista de amigos:
		Ana Ruiz
		Pepe Gomez
		Johny
		Mensajes en el muro:
		[Johny]: Espero verte manyana. Confirma.
		[Ana Ruiz]:	Cena de despedida al final del mes. Contamos contigo y
		tu pareja.
		[Johny]: Curso de Android a 20 euros.
		[Johny]: Finde en Madrid?
		----------------------------------------
		Identificador de usuario: Pepe Gomez
		Lista de amigos:
		Luis Mayo
		Mensajes en el muro:
		[Luis Mayo]: Corte de pelo en el centro a 50 euros. ­Una ganga! No te
		lo pierdas.
		----------------------------------------
		Identificador de usuario: Felipe Mesa
		Lista de amigos:
		Johny
		Mensajes en el muro:
		----------------------------------------
		Identificador de usuario: Ana Ruiz
		Lista de amigos:
		Luis Mayo
		Mensajes en el muro:
		[Luis Mayo]: Fiesta el domingo.
		[Luis Mayo]: Corte de pelo en el centro a 50 euros. ­Una ganga! No te
		lo pierdas.
		[Luis Mayo]: Te vienes al cine?
		----------------------------------------
		Identificador de usuario: Johny
		Lista de amigos:
		Felipe Mesa
		Luis Mayo
		Mensajes en el muro:
		[Luis Mayo]: Corte de pelo en el centro a 50 euros. ­Una ganga! No te
		lo pierdas.
		[Felipe Mesa]: Barcelona 1-Malaga 1. ­Empate!
		----------------------------------------
*/
void escribir_red(const RedSocial &red);
//----------------------------------------------------------------------------


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Algoritmos auxiliares de la función principal

//------------------------------------------------------------------------------
// Escribe por pantalla el resultado de una operación
void escribir_resultado(Resul res) {
	switch (res) {
	case OK:
		cout << "Operación realizada correctamente" << endl;
		break;
	case NO_EXISTE:
		cout << "El usuario no existe en la lista" << endl;
		break;
	case YA_EXISTE:
		cout << "El usuario ya existe en la lista" << endl;
		break;
	case CADENA_VACIA:
		cout << "La cadena está vacía" << endl;
		break;
	case LISTA_LLENA:
		cout << "La lista está llena" << endl;
		break;
	case TIPO_INCORRECTO:
		cout << "El tipo de mensaje es incorrecto" << endl;
		break;
	default:
		cout << "Resultado desconocido" << endl;
	}
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Muestra por pantalla la red social
void mostrar(const RedSocial &r) {
	cout << endl;

	escribir_red(r);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Registra un nuevo usuario en la red social
void registrar_nuevo_usuario(RedSocial &r) {
	Resul res;
	string id;

	cout << "Identificador del usuario: ";
	getline(cin, id);

	registrar(r, id, res);
	escribir_resultado(res);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Da de baja un usuario de la red social
void dar_de_baja_usuario(RedSocial &r) {
	Resul res;
	string id;

	cout << "Identificador del usuario: ";
	getline(cin, id);

	dar_de_baja(r, id, res);
	escribir_resultado(res);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Gestiona uan petición de amistad entre usuarios de la red social
void solicitar_amistad(RedSocial &r) {
	Resul res;
	string id1, id2;

	cout << "Usuario que emite la petición de amistad: ";
	getline(cin, id1);
	cout << "Usuario que recibe la petición de amistad: ";
	getline(cin, id2);

	pedir_amistad(r, id1, id2, res);
	escribir_resultado(res);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void leer_tipo_msg(TipoMsg &tipo_msg) {
	do {
		cout << "Tipo de mensaje (0=publico, 1=amigos, 2=privado): ";
		cin >> tipo_msg;
		if (tipo_msg > 2) {
			cout << "Tipo inválido. Vuelva a intentarlo" << endl;
		}
	} while (tipo_msg > 2);
	cin.ignore();
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Publica un mensaje en la red social
void publicar_mensaje(RedSocial &r) {
	Resul res;
	string id1, id2 = "", msg;
	TipoMsg tipo_msg;

	cout << "Identificador del usuario que publica el mensaje: ";
	getline(cin, id1);
	leer_tipo_msg(tipo_msg);

	if (tipo_msg == PRIVADO) {
		cout << "Identificador del usuario que recibe el mensaje privado: ";
		getline(cin, id2);
	}

	cout << "Escriba el mensaje a publicar: ";
	getline(cin, msg);

	publicar_msg(r, id1, id2, msg, tipo_msg, res);
	escribir_resultado(res);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Escribe los datos de un usuario de la red
void consultar_datos_usuario(const RedSocial &r) {
	Resul res;
	string id;
	unsigned pos;

	cout << "Identificador del usuario: ";
	getline(cin, id);

	buscar_usuario(r, id, pos, res);
	escribir_resultado(res);
	if (res == OK) {
		escribir_usuario(r.lusuarios[pos]);
	}
}
//------------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Escribe por pantalla el menú de opciones del programa principal
char menu()
{
	cout << endl;
	cout << "0.- Fin" << endl;
	cout << "1.- Mostrar Red" << endl;
	cout << "2.- Registrar nuevo usuario" << endl;
	cout << "3.- Dar de baja usuario de la red" << endl;
	cout << "4.- Peticion de amistad." << endl;
	cout << "5.- Publicar mensaje" << endl;
	cout << "6.- Consultar datos de un usuario" << endl;
	char op;
	cin.clear();
	do {
		cout << "    Opcion ? ";
		cin >> op;
	} while (op < '0' || op > '6');
	cout << endl;
	cin.ignore();
	return op;
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Introduce datos iniciales en la red social para que sirvan de prueba
void cargar(RedSocial &r) {
	r.num_usuarios = 5;
	// Luis Mayo
	r.lusuarios[0].id = "Luis Mayo";
	r.lusuarios[0].lamigos.num_amigos = 3;
	r.lusuarios[0].lamigos.amigos[0] = "Ana Ruiz";
	r.lusuarios[0].lamigos.amigos[1] = "Pepe Gomez";
	r.lusuarios[0].lamigos.amigos[2] = "Johny";
	r.lusuarios[0].muro.num_mensajes = 4;
	r.lusuarios[0].muro.mensajes[0].id = "Johny";
	r.lusuarios[0].muro.mensajes[0].msg = "Espero verte manyana. Confirma.";
	r.lusuarios[0].muro.mensajes[1].id = "Ana Ruiz";
	r.lusuarios[0].muro.mensajes[1].msg = string("Cena de despedida al ") +
	                                      "final del mes. Contamos contigo " +
	                                      "y tu pareja.";
	r.lusuarios[0].muro.mensajes[2].id = "Johny";
	r.lusuarios[0].muro.mensajes[2].msg = "Curso de Android a 20 euros.";
	r.lusuarios[0].muro.mensajes[3].id = "Johny";
	r.lusuarios[0].muro.mensajes[3].msg = "Finde en Madrid?";
	// Pepe Gomez
	r.lusuarios[1].id = "Pepe Gomez";
	r.lusuarios[1].lamigos.num_amigos = 1;
	r.lusuarios[1].lamigos.amigos[0] = "Luis Mayo";
	r.lusuarios[1].muro.num_mensajes = 1;
	r.lusuarios[1].muro.mensajes[0].id = "Luis Mayo";
	r.lusuarios[1].muro.mensajes[0].msg = string("Corte de pelo en el") +
	                                      " centro a 50 euros. ¡Una " +
	                                      "ganga! No te lo pierdas";
	// Felipe Mesa
	r.lusuarios[2].id = "Felipe Mesa";
	r.lusuarios[2].lamigos.num_amigos = 1;
	r.lusuarios[2].lamigos.amigos[0] = "Johny";
	r.lusuarios[2].muro.num_mensajes = 0;
	// Ana Ruiz
	r.lusuarios[3].id = "Ana Ruiz";
	r.lusuarios[3].lamigos.num_amigos = 1;
	r.lusuarios[3].lamigos.amigos[0] = "Luis Mayo";
	r.lusuarios[3].muro.num_mensajes = 3;
	r.lusuarios[3].muro.mensajes[0].id = "Luis Mayo";
	r.lusuarios[3].muro.mensajes[0].msg = "Fiesta el domingo";
	r.lusuarios[3].muro.mensajes[1].id = "Luis Mayo";
	r.lusuarios[3].muro.mensajes[1].msg = string("Corte de pelo en el") +
	                                      " centro a 50 euros. ¡Una " +
	                                      "ganga! No te lo pierdas";
	r.lusuarios[3].muro.mensajes[2].id = "Luis Mayo";
	r.lusuarios[3].muro.mensajes[2].msg = "¿Te vienes al cine?";
	// Johny
	r.lusuarios[4].id = "Johny";
	r.lusuarios[4].lamigos.num_amigos = 2;
	r.lusuarios[4].lamigos.amigos[0] = "Felipe Mesa";
	r.lusuarios[4].lamigos.amigos[1] = "Luis Mayo";
	r.lusuarios[4].muro.num_mensajes = 2;
	r.lusuarios[4].muro.mensajes[0].id = "Luis Mayo";
	r.lusuarios[4].muro.mensajes[0].msg = string("Corte de pelo en el") +
	                                      " centro a 50 euros. ¡Una " +
	                                      "ganga! No te lo pierdas";

	r.lusuarios[4].muro.mensajes[1].id = "Felipe Mesa";
	r.lusuarios[4].muro.mensajes[1].msg = "Barcelona 1-Malaga 1. Empate!";
}
//--------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Algoritmo principal
int main() {
	// declaración del nuevo objeto r de tipo 'RedSocial' e invocación
	// al CONSTRUCTOR POR DEFECTO
	RedSocial r;
	char op;

	crear_red(r);
	cargar(r); // Carga unos datos iniciales para probar la red social

	do {
		op = menu();
		switch (op) {
		case '1':
			mostrar(r);
			break;
		case '2':
			registrar_nuevo_usuario(r);
			break;
		case '3':
			dar_de_baja_usuario(r);
			break;
		case '4':
			solicitar_amistad(r);
			break;
		case '5':
			publicar_mensaje(r);
			break;
		case '6':
			consultar_datos_usuario(r);
			break;
		}
	} while (op != '0');
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// IMPLEMENTACIÓN DE LOS SUBPROGRAMAS

// USUARIO

//----------------------------------------------------------------------------
// Crea un usuario con identificador cadena vacía (""),
// con una lista vacía de amigos y un muro sin mensajes
// PARÁMETROS:
//		- u (S): usuario que va a inicializarse
void crear_usuario(Usuario &u) {
    u.id = "";
    u.lamigos.num_amigos=0;
    u.muro.num_mensajes=0;

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Devuelve el identificador del usuario
string consultar_id(Usuario &u) {
    return u.id;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Devuelve la lista de amigos del usuario
// PARÁMETROS:
//		- u (E): un usuario
//		- amgs (S){} lista de amigos
void consultar_amigos(const Usuario &u, Amigos &amgs) {
   amgs = u.lamigos;


}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Devuelve la lista de mensajes del muro del usuario
// PARÁMETROS:
//		- u (E): un usuario
//		- mr (S): lista de mensajes del muro del usuario 'u'
void consultar_muro(const Usuario &u, Mensajes &mr ) {
    mr = u.muro;
}
//----------------------------------------------------------------------------

// Modifica el identificador del usuario
// PARÁMETROS:
//		- u (ES): un usuario
// 		- identif (E): nuevo identificador para el usuario
//		- res (S): resultado de la operación
// Si 'identif' no está vacía, se modifica el identificador
//		del usuario con el nuevo 'identif' y se devuelve
//		OK a través de 'res'.
//		Si no, se devuelve CADENA_VACIA a través de 'res'
void modificar_id(Usuario &u, const string &identif, Resul &res) {

    if (identif != ""){
        u.id = identif;
        res = OK;
    }else {
        res = CADENA_VACIA;
    }

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Busca un amigo en la lista de amigos del usuario
// PARÁMETROS:
//		- u (E): un usuario
//		- id_amigo (E): identificador de un amigo
//		- pos (S): posición del array donde está almacenado el amigo
//		- res (S): resultado de la operación
// Si el amigo 'id_amigo' está en la lista de amigos del usuario,
//		se devuelve su posición en el array a través de 'pos' y OK en 'res'.
//		Si no, si no existe el usuario, se devuelve NO_EXISTE a través de 'res'
//		y en 'pos' estará almacenado el número de amigos del usuario
void buscar_amigo(const Usuario &u, const string &id_amigo, unsigned &pos ,Resul &res) {
    unsigned i = 0;

    while ((i<unsigned (u.lamigos.num_amigos)) && (id_amigo != u.lamigos.amigos[i])){
            i++;
    }
        if (id_amigo == u.lamigos.amigos[i]){
            res = OK;
            pos = i;
        }else {
            res = NO_EXISTE;
            pos = u.lamigos.num_amigos;
        }



}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Inserta un nuevo amigo en la lista de amigos del usuario
// PARÁMETROS:
//		- u (ES): un usuario
//		- id_amigo (E): identificador de un amigo
//		- res (S): resultado de la operación
// Si el 'id_amigo' no está en la lista de amigos y la lista de
//		amigos no está llena, el nuevo amigo se inserta
// 		en la lista de amigos del usuario y se devuelve OK a través de
//		'res'. Si no, si el amigo ya estaba en la lista,
//		se devuelve 'YA_EXISTE' a través de 'res'. Si no, si la lista
//		está llena, se devuelve 'LISTA_LLENA' a través de 'res'.
void anyadir_amigo(Usuario &u, const string &id_amigo, Resul &res) {
    unsigned i = 0;

    unsigned posic;
    Resul resB;
    buscar_amigo(u, id_amigo, posic, resB);

    if ((resB == NO_EXISTE) && (u.lamigos.num_amigos < MAX_AMIGOS)){

        u.lamigos.amigos[u.lamigos.num_amigos] = id_amigo;
        u.lamigos.num_amigos++;
        res = OK;

    }else if ((resB == OK)){

        res = YA_EXISTE;

    }else if (u.lamigos.num_amigos >= MAX_AMIGOS){

        res = LISTA_LLENA;
    }

}

   /* while ((i< unsigned (u.lamigos.num_amigos)&& (id_amigo != u.lamigos.amigos[i]))){
        i++;
        if ((id_amigo != u.lamigos.amigos[i]) && (u.lamigos.num_amigos != MAX_AMIGOS)){
            u.lamigos.num_amigos++;
            u.lamigos.amigos[i] = id_amigo;
            res = OK;

        }else if (id_amigo == u.lamigos.amigos[i]){
            res = YA_EXISTE;

        }else {//if (u.lamigos.num_amigos == MAX_AMIGOS){
            res = LISTA_LLENA;

        }
    } */

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Elimina un usuario de la lista de amigos del usuario
// PARÁMETROS:
//		- u (ES): un usuario
//		- id_amigo (E): identificador de un amigo
//		- res (S): resultado de la operación
// Si el 'id_amigo' está en la lista de amigos, el amigo se elimina
// 		de la lista de amigos del usuario y se devuelve OK a través de
//		'res'. Si no, si el amigo no estaba en la lista,
//		se devuelve 'NO_EXISTE' a través de 'res'.
void eliminar_amigo(Usuario &u, const string &id_amigo, Resul &res) {

    unsigned posic;
    Resul resB;
    buscar_amigo(u, id_amigo, posic, resB);
    cout << posic  << "hh" << endl;
    cout << u.lamigos.num_amigos-1 << "zz" << endl;

    if (resB == OK){

        for (unsigned i = posic ; i < unsigned (u.lamigos.num_amigos) ; i++){

            u.lamigos.amigos[i] = u.lamigos.amigos[i+1];
            cout << "hola4444" << endl;
        }
        cout << "hola3" << endl;
        u.lamigos.num_amigos--;
        res = OK;

    } else {
        cout << "hola 42" << endl;
        res = NO_EXISTE;

    }




   /* while ((i< unsigned (u.lamigos.num_amigos) && (id_amigo != u.lamigos.amigos[i]))){
        i++;
        if (id_amigo == u.lamigos.amigos[i]){

            u.lamigos.amigos[i] = u.lamigos.amigos [u.lamigos.num_amigos-1];
            u.lamigos.num_amigos--;
            res = OK;
        }else if (id_amigo != u.lamigos.amigos [i]){

            res = NO_EXISTE;
        }

    } */

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Publica un mensaje en el muro del usuario
// PARÁMETROS:
//		- u (ES): un usuario
//		- msg (E): un mensaje (con id de usuario y texto)
//		- res (S): resultado de la operación
// Si el 'msg' es correcto (el identificador de usuario y el texto
// 		del mensaje no están vacíos) y cabe en el muro,
//		el mensaje se inserta al final de la lista de mensajes y
//		se devuelve OK a través de 'res'.
//		Si no, si el mensaje es incorrecto (el id de usuario o el mensaje
//		están vacíos), se devuelve CADENA_VACIA a través de 'res'.
//		Si no, si el mensaje no cabe en la lista, se devuelve LISTA_LLENA
//		a través de 'res'
void publicar_msg(Usuario &u, const Mensaje &msg, Resul &res) { //REVISAR!!!! //[u.muro.num_mensajes+1??] o [u.muro.num_mensajes??]

    if ((msg.id != "") && (msg.msg != "") && (u.muro.num_mensajes < MAX_MENSAJES)){

        u.muro.mensajes[u.muro.num_mensajes] = msg;
        u.muro.num_mensajes++;
        res = OK;

    }else if ((msg.id == "") || (msg.msg == "")) {

        res = CADENA_VACIA;

    }else if ((u.muro.num_mensajes == MAX_MENSAJES)){

        res = LISTA_LLENA;
    }

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Saca por pantalla todos los datos del usuario, incluyendo su lista de
// amigos y todos los mensajes de su muro, en el orden en el que están
// almacenados en memoria.
/* Ejemplo de formato de salida por pantalla:
		----------------------------------------
		Identificador de usuario: Luis Mayo
		Lista de amigos:
		Ana Ruiz
		Pepe Gomez
		Johny
		Mensajes en el muro:
		[Johny]: Espero verte manyana. Confirma.
		[Ana Ruiz]:	Cena de despedida al final del mes. Contamos contigo y
		tu pareja.
		[Johny]: Curso de Android a 20 euros.
		[Johny]: Finde en Madrid?
		----------------------------------------
*/
void escribir_usuario(const Usuario &u) {
    cout << "Identificador de usuario: " << u.id << endl;
    cout << "Lista de amigos: " << endl;

    for (unsigned i = 0 ; i < u.lamigos.num_amigos ; i++){
        cout << u.lamigos.amigos[i] << endl;
    }

    cout << "Mensajes en el muro: " << endl;

    for (unsigned i = 0 ; i < u.muro.num_mensajes ; i++){
            cout << "[ " << u.muro.mensajes[i].id << " ]" << ": " << u.muro.mensajes[i].msg << endl;


    }
}
//----------------------------------------------------------------------------

// RED SOCIAL

//----------------------------------------------------------------------------
// Crea (inicializa) la red social con la lista de usuarios vacía, es decir,
// con 'num_usuarios' igual a cero.
// PARÁMETROS:
//		- red (S): una red social
void crear_red(RedSocial &red) {

    red.num_usuarios = 0;

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Busca un usuario en la red
// PARÁMETROS:
//		- red (E): una red social
//		- id (E): identificador de un usuario
//		- pos (S): posición del array donde está almacenado el usuario
//		- res (S): resultado de la operación
// Si el usuario 'id' está en la lista de usuarios de la red social,
//		se devuelve su posición en el array a través de 'pos' y OK en 'res'.
//		Si no, si no existe el usuario, se devuelve NO_EXISTE a través de 'res'
//		y en 'pos' estará almacenado el número de usuarios actuales
// 		de la red social.
void buscar_usuario(const RedSocial &red, const string &id, unsigned &pos, Resul &res) {
    unsigned i = 0;
    while ((i < unsigned (red.num_usuarios)) && (id != red.lusuarios[i].id)){
    //        cout << red.lusuarios[i].id << endl;
        i++;
    }

        if (id==red.lusuarios[i].id && !id.empty()){

            pos = i;
            res = OK;

        }else if (id != red.lusuarios[i].id) {
            res = NO_EXISTE;
            pos = red.num_usuarios;

        }

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Inserta un nuevo usuario en la red social
// PARÁMETROS:
//		- red (ES): una red social
//		- id (E): identificador de usuario
//		- res (S): resultado de la operación
// Si el usuario con identificador 'id' no existe en la red social,
//		la lista de usuarios no está llena e 'id' no es una cadena vacía,
//		se inserta un usuario con identificador 'id' (con su lista de amigos
//		y muro vacíos) al final de la lista de usuarios de la red social.
// 		Si no, si el usuario ya existía en la red, se devuelve YA_EXISTE a través
//		de 'res'.
//		Si no, si la lista está llena, se devuelve LISTA_LLENA a través de
//		'res'.
//		Si no, si el 'id' está vacío, se devuelve CADENA_VACIA a través de
//		'res'.
void registrar(RedSocial &red, const string &id, Resul &res) {

    unsigned posici;
    Resul resuB;
    Usuario u;

    buscar_usuario(red, id, posici, resuB);

    if ((resuB == NO_EXISTE) && (red.num_usuarios < MAX_USUARIOS) && (id != "")){

        red.lusuarios[red.num_usuarios].id = id;
        red.num_usuarios++;
        res = OK;

    }else if (resuB == OK){

        res = YA_EXISTE;

    }else if (red.num_usuarios >= MAX_USUARIOS){

        res = LISTA_LLENA;

    }else if ( id == ""){

        res = CADENA_VACIA;
    }

   /* while ((i < unsigned (red.num_usuarios)) && (id != red.lusuarios[i].id)){

        if ((id != red.lusuarios[i].id) && (red.num_usuarios != MAX_USUARIOS) && (id != "")){
            red.lusuarios[num_usuarios+1] = u;
            red.num_usuarios++;

        }else if (id == red.lusuarios[i].id){
            res = YA_EXISTE;

        }else if (red.num_usuarios == MAX_USUARIOS){
            res = LISTA_LLENA;

        }else if (id == ""){
            res = CADENA_VACIA;

        }
    } */
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Elimina un usuario de la red social.
// PARÁMETROS:
//		- red (ES): una red social
//		- id (E): identificador de usuario
//		- res (S): resultado de la operación
// Si el usuario está registrado (existe) en la red, se elimina
//		el usuario de la red, su identificador se elimina de
//		las listas de amigos de todos los usuarios y se
// 		devuelve OK a través de 'res'.
//		Si no, se devuelve NO_EXISTE a través de 'res'.
void dar_de_baja(RedSocial &red, const string &id, Resul &res) {
    unsigned i;
    unsigned j;
    unsigned posici;
    unsigned posi;
    Resul resuB;
    Resul resuA;
    Resul resuC;
    Usuario aux;

    buscar_usuario(red, id, posici, resuB);
    Usuario u;
    u.id = id;

    if (resuB == OK){
            u = red.lusuarios[posici];

            if (u.lamigos.num_amigos!= 0){

            for (j = 0; j < unsigned (red.num_usuarios); j++){
                    cout << "Hola" << endl;

                    buscar_usuario(red, u.lamigos.amigos[j], posi, resuA); //

                    if (posi != red.num_usuarios){

                        aux = red.lusuarios[posi];
                            cout << "hola1 " << aux.id << endl;
                        eliminar_amigo(aux, id, resuC);
                    }

             for (i = posici; i < unsigned (red.num_usuarios-1); i++){

                red.lusuarios[posici] = red.lusuarios [posici+1];
            }

            }
            }else{

            for (i = posici; i < unsigned (red.num_usuarios-1); i++){

                red.lusuarios[posici] = red.lusuarios [posici+1];
            }
            }
            red.num_usuarios--;

       res = OK;


    }else {

        res = NO_EXISTE;

    }

    /*while ((i < unsigned (red.num_usuarios)) && (id != red.lusuarios[i].id)){
        i++;
        if (id == red.lusuarios[i].id){
            red.lusuarios[num_usuarios] = red.lusuarios [num_usuarios-1];
            num_usuarios--;

            for (unsigned j = 0 ; j < unsigned (red.num_usuarios) ; j++){

                red.lusuarios[j].lamigos

            }
        }else{

        res = NO_EXISTE;

    }*/
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Hacer amigos a dos usuarios de la red. El usuario con identificador 'origen'
// recibe una petición de amistad por parte del usuario con identificador
// 'destino'. Dado el carácter "afable" de esta red social, las peticiones
// de amistad siempre son aceptadas.
// PARÁMETROS:
//		- red (ES): una red social
//		- origen (E): identificador del usuario que pide amistad
//		- destino (E): identificador del usuario que recibe la petición de
//				amistad.
// Si los usuarios con identificador 'origen' y 'destino' existen
//		en la red social, los usuarios no son amigos en este momento y las
//		listas de amigos de "origen" y "destino" no están llenas,
//		se añade 'origen' a la lista de amigos de
//		"destino" y viceversa, y se devuelve OK a través de 'res'.
//		Si no, si "origen" o "destino" no existen en la red, se devuelve
//		NO_EXISTE a través de 'res'.
//		Si no, si la lista de amigos de "origen" o de "destino" están llenas,
//		se devuelve LISTA_LLENA a través de 'res'.
void pedir_amistad(RedSocial &red, const string &origen, const string &destino, Resul &res) { //FALTA EN PARAMETROS EL RESULTADO
    // No me añade a la persona
    unsigned i = 0;
    unsigned pos1;
    unsigned pos2;
    unsigned pos3;
    unsigned pos4;

    Resul resB;
    Resul resC;
    Resul resD;
    Resul resE;
    Resul resF;
    Usuario u;
    u.id = origen;
    Usuario z;
    z.id = destino;


    buscar_usuario(red, origen, pos3, resC);
    buscar_usuario(red, destino, pos4, resD);

    if ((resC == OK) && (resD == OK)) {

        buscar_amigo(z, origen, pos2, resB);

        if ((resB == NO_EXISTE) && (u.lamigos.num_amigos<MAX_AMIGOS) && (z.lamigos.num_amigos<MAX_AMIGOS)){

            anyadir_amigo(red.lusuarios[pos3], destino, resE);
            anyadir_amigo(red.lusuarios[pos4], origen, resF);
            res = OK;
        }
        else{

            res = NO_EXISTE;
        }

    }else if ((u.lamigos.num_amigos == MAX_AMIGOS) && (z.lamigos.num_amigos == MAX_AMIGOS)){

        res = LISTA_LLENA;

    }

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Publica un mensaje en la red social.
// PARÁMETROS:
//		- red (ES): una red social
//		- id_origen (E): identificador del usuario que envía el mensaje
//		- id_destino (E): identificador del usuario que recibe el mensaje
//				si el tipo de mensaje es PRIVADO
//		- msg (E): mensaje enviado
//		- tipo (E): naturaleza del mensaje enviado
//		- res (S): resultado de la operación
// Si el usuario 'id_origen' existe en la red (si el tipo de mensaje
//		es privado, el usuario 'id_destino' debe existir en la red y tener amistad
//		con el usuario 'id_origen') y si el 'msg' no está vacío:
//      - si 'tipo' es PUBLICO, se considera un mensaje público y entonces
//				el mensaje es insertado en el muro de todos y cada uno de los
//			 	miembros de la red (excepto en el del usuario con identificador
//				‘id_origen’, que es el que lo envía) y se devuelve OK en 'res'.
//				En este caso, el parámetro ‘id_destino’ no se tiene en cuenta.
//      - si 'tipo' es RESTRINGIDO, se considera que es un mensaje restringido
//				a los amigos del usuario que lo envía y el mensaje es insertado
//			 	sólo en el muro de todos y cada uno de los usuarios amigos de
//				‘id_origen’. Se devuelve OK a través de 'res'.
//				En este caso el parámetro ‘id_destino’ no se tiene en cuenta.
//      - si 'tipo' es PRIVADO, se considera que es un mensaje privado dirigido
//				al amigo con identificador ‘id_destino’, de manera que el
//				mensaje es insertado sólo en el muro del usuario con
//				identificador ‘id_destino’. El resultado de esta operación (ya
//				sea OK o LISTA_LLENA) se devuelve a través de 'res'.
//		Si no, si el usuario 'id_origen' no existe, se devuelve NO_EXISTE
//				a travñes de 'res'; si el tipo de mensaje es PRIVADO y el
//				usuario 'id_destino' no existe en la red o los usuarios
//				'id_origen' e 'id_destino' no son amigos, se devuelve NO_EXISTE
//				a través de 'res'. Si el tipo de mensaje es incorrecto
//				(no es ni PRIVADO, ni PUBLICO, ni RESTRINGIDO) se devuelve
//				TIPO_INCORRECTO a través de 'res'.
//		Si no, si msg está vacio, se devuelve CADENA_VACIA a través de 'res'
void publicar_msg(RedSocial &red, const string &id_origen, const string &id_destino, const string &msg, const TipoMsg &tipo, Resul &res ) { //FALTA O SOBRA LLAVE

    Mensaje msg1;
    msg1.msg = msg;
    Usuario u;
    u.id = id_origen;

    Usuario z;
    z.id = id_destino;

    Usuario aux;

    unsigned j;
    unsigned posici; //inicializadas a 0?
    unsigned posi;
    unsigned posic;
    unsigned pos;
    unsigned pos1;
    Resul resA;
    Resul resB;
    Resul resC;
    Resul resD;
    Resul resE;
    Resul resF;

    buscar_usuario(red, id_origen, posici, resB);
    buscar_usuario(red, id_destino, posic, resA);
    buscar_amigo(u, id_destino,pos1, resC);

    if ((resB == OK) && !msg1.msg.empty()){


            if (tipo == PUBLICO){

                for (unsigned i = 0 ; i< red.num_usuarios; i++){

                        //red.lusuarios[i].id != id_origen
                    if (i != posici){
                    publicar_msg(red.lusuarios[i], msg1, resD);

                    }
                }
                res = OK;

            } else if (tipo == RESTRINGIDO){

                for (j = 0; j < unsigned (red.num_usuarios); j++){

                     buscar_usuario(red, u.lamigos.amigos[j], pos, resE);


                    if (pos != red.num_usuarios){

                            aux = red.lusuarios[pos];
                            publicar_msg(aux , msg1, resF);

                    }

                }
                    res = OK;
                }


        } else if (tipo == PRIVADO){

                z.muro.mensajes[z.muro.num_mensajes+1].msg = msg1.msg;
                z.muro.mensajes[z.muro.num_mensajes+1].id = msg1.id;
                z.muro.num_mensajes++;

                if (z.muro.num_mensajes != MAX_MENSAJES){

                    res = OK;
                } else if (z.muro.num_mensajes == MAX_MENSAJES){

                    res = LISTA_LLENA;

                }

            } else if (resB == NO_EXISTE){

        res = NO_EXISTE;

    }else if ((tipo == PRIVADO) && (resA == NO_EXISTE) || (resC == NO_EXISTE)){


        res = NO_EXISTE;

    }else if ((tipo != PUBLICO) && (tipo != RESTRINGIDO) && (tipo != PRIVADO)){


        res = TIPO_INCORRECTO;

    }else if (msg1.msg == ""){

        res = CADENA_VACIA;

    }
    }
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Escribe por pantalla todos los datos de la red social, esto es, todos los
//		datos de todos los usuarios de la red social.
// PARÁMETROS:
// 		- red (E): una red social
/*
   El formato de salida por pantalla debe ser el siguiente:
		----------------------------------------
		Identificador de usuario: <Identificador>
		Lista de amigos:
		<Id. amigo 1>
		<Id. amigo 2>
		<Id. amigo 3>
		...
		Mensajes en el muro:
		[<Id. amigo>]: <Mensaje>
		[<Id. amigo>]: <Mensaje>
		...
		----------------------------------------
	Por ejemplo, para la figura mostrada se mostraría por pantalla:
		----------------------------------------
		Identificador de usuario: Luis Mayo
		Lista de amigos:
		Ana Ruiz
		Pepe Gomez
		Johny
		Mensajes en el muro:
		[Johny]: Espero verte manyana. Confirma.
		[Ana Ruiz]:	Cena de despedida al final del mes. Contamos contigo y
		tu pareja.
		[Johny]: Curso de Android a 20 euros.
		[Johny]: Finde en Madrid?
		----------------------------------------
		Identificador de usuario: Pepe Gomez
		Lista de amigos:
		Luis Mayo
		Mensajes en el muro:
		[Luis Mayo]: Corte de pelo en el centro a 50 euros. ­Una ganga! No te
		lo pierdas.
		----------------------------------------
		Identificador de usuario: Felipe Mesa
		Lista de amigos:
		Johny
		Mensajes en el muro:
		----------------------------------------
		Identificador de usuario: Ana Ruiz
		Lista de amigos:
		Luis Mayo
		Mensajes en el muro:
		[Luis Mayo]: Fiesta el domingo.
		[Luis Mayo]: Corte de pelo en el centro a 50 euros. ­Una ganga! No te
		lo pierdas.
		[Luis Mayo]: Te vienes al cine?
		----------------------------------------
		Identificador de usuario: Johny
		Lista de amigos:
		Felipe Mesa
		Luis Mayo
		Mensajes en el muro:
		[Luis Mayo]: Corte de pelo en el centro a 50 euros. ­Una ganga! No te
		lo pierdas.
		[Felipe Mesa]: Barcelona 1-Malaga 1. ­Empate!
		----------------------------------------
*/
void escribir_red(const RedSocial &red) {

    for (unsigned i = 0 ; i < unsigned (red.num_usuarios) ; i++){

        escribir_usuario(red.lusuarios[i]);
        cout << endl;


    }


    /*for (unsigned i = 0; j < unsigned (red.num_usuarios); i++ ){


        cout << "Identificador de usuario: " << u.id << endl;
        cout << "Lista de amigos: " << endl;
        for (unsigned j = 0 ; j< unsigned (u.lamigos.num_amigos) ; j++){

            cout << u.lamigos.amigos[j] << endl;
        }

        cout << "Mensajes en el muro: " << endl;
        for (unsigned z = 0; z < unsigned (u.muro.num_mensajes) ; z++){

            cout << [u.muro.mensajes[z].id] << ": " << u.muro.mensajes[z].msg << endl;
        }


    }*/



}
//----------------------------------------------------------------------------
