// Supermarket.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "Empleado.h"
#include "Cliente.h"
#include "Puesto.h"
#include "proveedor.h"
#include "Marca.h"
#include "Producto.h"

using namespace  std;

void menu();
void menuEmpleado();
void menuCliente();
void menuPuesto();
void menuProveedores();
void menuMarcas();
void menuProducto();

void ingresarEmpleado() {
	string  nom, ape, dir, dpi, gen, fn, idp, fil, fi, n, em;
	int tel;
	cout << "Ingrese Nombres:"; cin>> nom;
	cout << "Ingrese Apellidos:"; cin>> ape;
	cout << "Ingrese Direccion:"; cin>> dir;
	cout << "Ingrese Telefono:"; cin >> tel; cin.ignore();
	cout << "Ingrese DPI:"; cin >> dpi;
	cout << "Ingrese Genero:"; cin >> gen;
	cout << "Ingrese Fecha_nacimiento:"; cin >> fn;
	cout << "Ingrese idPuesto:"; cin >> idp;
	cout << "Ingrese Fecha_inicio_labores:"; cin >> fil;
	cout << "Ingrese Fecha_ingreso:"; cin >> fi;
	
	Empleado nuevoEmpleado = Empleado(nom, ape, dir, tel, dpi, gen, fn, idp, fil, fi);
	nuevoEmpleado.crear();
}
void mostrarEmpleado() {
	Empleado nuevoEmpleado = Empleado();
	nuevoEmpleado.mostrar();
}
void eliminarEmpleado() {
	Empleado nuevoEmpleado = Empleado();
	nuevoEmpleado.eliminar();
}
void actualizarEmpleado() {
	Empleado nuevoEmpleado = Empleado();
	nuevoEmpleado.actualizar();
}

void ingresarCliente() {
	string nom, ape, n, gen, em, fi;
	int tel;
	cout << "Ingrese Nombres:"; cin >> nom;
	cout << "Ingrese Apellidos:"; cin >> ape;
	cout << "Ingrese NIT:"; cin >> n;
	cout << "Ingrese Genero:"; cin >> gen;
	cout << "Ingrese Telefono:"; cin >> tel; cin.ignore();
	cout << "Ingrese Correo Electronico:"; cin >> em;
	cout << "Ingrese Fecha Ingreso:"; cin >> fi;

	Cliente nuevoCliente = Cliente(nom, ape, n, gen, tel, em, fi);
	nuevoCliente.crear();
}
void mostrarCliente() {
	Cliente nuevoCliente = Cliente();
	nuevoCliente.mostrar();
}
void eliminarCliente() {
	Cliente nuevoCliente = Cliente();
	nuevoCliente.eliminar();
}
void actualizarCliente() {
	Cliente nuevoCliente = Cliente();
	nuevoCliente.actualizar();
}

void ingresarPuesto(){
	string pue;
	cout << "Ingrese Puesto:"; cin >> pue;

	Puesto nuevoPuesto = Puesto(pue);
	nuevoPuesto.crear();
}
void mostrarPuesto() {
	Puesto nuevoPuesto = Puesto();
	nuevoPuesto.mostrar();
}
void eliminarPuesto() {
	Puesto nuevoPuesto = Puesto();
	nuevoPuesto.eliminar();
}
void actualizarPuesto() {
	Puesto nuevoPuesto = Puesto();
	nuevoPuesto.actualizar();
}

void ingresarProveedor() {
	string prov, n, dir;
	int tel;
	cout << "Ingrese Proveedor:"; cin >> prov;
	cout << "Ingrese NIT: "; cin >> n;
	cout << "Ingrese Direccion: "; cin >> dir;
	cout << "Ingrese Telefono:"; cin >> tel; cin.ignore();

	Proveedores nuevoProveedor = Proveedores(prov,n,dir,tel);
	nuevoProveedor.crear();
}
void mostrarProveedor() {
	Proveedores nuevoProveedor = Proveedores();
	nuevoProveedor.mostrar();
}
void eliminarProveedor() {
	Proveedores nuevoProveedor = Proveedores();
	nuevoProveedor.eliminar();
}
void actualizarProveedor() {
	Proveedores nuevoProveedor = Proveedores();
	nuevoProveedor.actualizar();
}

void ingresarMarca () {
	string mar;
	cout << "Ingrese Marca:"; cin >> mar;

	Marcas nuevaMarca = Marcas(mar);
	nuevaMarca.crear();
}
void mostrarMarca() {
	Marcas nuevaMarca = Marcas();
	nuevaMarca.mostrar();
}
void eliminarMarca() {
	Marcas nuevaMarca = Marcas();
	nuevaMarca.eliminar();
}
void actualizarMarca() {
	Marcas nuevaMarca = Marcas();
	nuevaMarca.actualizar();
}

void ingresarProducto() {
	string prod, idmar, desc, ima, pc, pv, ex, fi;
	cout << "Ingrese Producto:"; cin >> prod;
	cout << "Ingrese ID Marca:"; cin >> idmar;
	cout << "Ingrese Descripcion:"; cin >> desc;
	cout << "Ingrese Imagen:"; cin >> ima;
	cout << "Ingrese Precio de Costo:"; cin >> pc;
	cout << "Ingrese Precio de Venta:"; cin >> pv;
	cout << "Ingrese Existencia:"; cin >> ex;
	cout << "Ingrese Fecha de Ingreso:"; cin >> fi;

	Productos nuevoProducto = Productos(prod, idmar, desc, ima, pc, pv, ex, fi);
	nuevoProducto.crear();
}
void mostrarProducto() {
	Productos nuevoProducto = Productos();
	nuevoProducto.mostrar();
}
void eliminarProducto() {
	Productos nuevoProducto = Productos();
	nuevoProducto.eliminar();
}
void actualizarProducto() {
	Productos nuevoProducto = Productos();
	nuevoProducto.actualizar();
}


int main(){
	
	/*menu();*/

	int opc;

	do {
		menu();
		cin >> opc;

		switch (opc) {
		case 1: menuEmpleado(); break;
		case 2: menuCliente(); break;
		case 3: menuPuesto(); break;
		case 4: menuProveedores(); break;
		case 5: menuMarcas(); break;
		case 6: menuProducto(); break;
		case 7: exit(1);
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 7);
	return 0;
}

void menu() {

	int opc;
		cout << "\n\t1. Tabla Empleado. " << endl;
		cout << "\t2. Tabla Cliente. " << endl;
		cout << "\t3. Tabla Puesto. " << endl;
		cout << "\t4. Tabla Proveedores. " << endl;
		cout << "\t5. Tabla Marcas. " << endl;
		cout << "\t6. Tabla Productos. " << endl;
		cout << "\t7. Tabla sin funcion. " << endl;
		cout << "\t8. Tabla sin funcion. " << endl;
		cout << "\t9. Tabla sin funcion. " << endl;
		cout << "\t10. Tabla sin funcion. " << endl;
		cout << "\t11. Salir" << endl;

		cout << "\nDigite opcion: ";
		
		}
	
void menuEmpleado() {

	int opc;

	do {
		cout << "\n\t1. Ingresar datos. " << endl;
		cout << "\t2. Ver datos. " << endl;
		cout << "\t3. Eliminar datos. " << endl;
		cout << "\t4. Actualizar datos. " << endl;
		cout << "\t5. Regresar al menu principal " << endl;

		cout << "\nDigite opcion: "; cin >> opc;

		switch (opc) {
		case 1: ingresarEmpleado(); break;
		case 2: mostrarEmpleado(); break;
		case 3: eliminarEmpleado(); break;
		case 4: actualizarEmpleado(); break;
		case 5:	main(); break;
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 5);
}

void menuCliente() {

	int opc;

	do {
		cout << "\n\t1. Ingresar datos. " << endl;
		cout << "\t2. Ver datos. " << endl;
		cout << "\t3. Eliminar datos. " << endl;
		cout << "\t4. Actualizar datos. " << endl;
		cout << "\t5. Regresar al menu principal " << endl;

		cout << "\nDigite opcion: "; cin >> opc;

		switch (opc) {
		case 1: ingresarCliente(); break;
		case 2: mostrarCliente(); break;
		case 3: eliminarCliente(); break;
		case 4: actualizarCliente(); break;
		case 5:	main(); break;
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 5);
}

void menuPuesto(){

	int opc;

	do {
		cout << "\n\t1. Ingresar datos. " << endl;
		cout << "\t2. Ver datos. " << endl;
		cout << "\t3. Eliminar datos. " << endl;
		cout << "\t4. Actualizar datos. " << endl;
		cout << "\t5. Regresar al menu principal " << endl;

		cout << "\nDigite opcion: "; cin >> opc;

		switch (opc) {
		case 1: ingresarPuesto(); break;
		case 2: mostrarPuesto(); break;
		case 3: eliminarPuesto(); break;
		case 4: actualizarPuesto(); break;
		case 5:	main(); break;
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 5);
}

void menuProveedores() {

	int opc;

	do {
		cout << "\n\t1. Ingresar datos. " << endl;
		cout << "\t2. Ver datos. " << endl;
		cout << "\t3. Eliminar datos. " << endl;
		cout << "\t4. Actualizar datos. " << endl;
		cout << "\t5. Regresar al menu principal " << endl;

		cout << "\nDigite opcion: "; cin >> opc;

		switch (opc) {
		case 1: ingresarProveedor(); break;
		case 2: mostrarProveedor(); break;
		case 3: eliminarProveedor(); break;
		case 4: actualizarProveedor(); break;
		case 5:	main(); break;
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 5);
}

void menuMarcas() {

	int opc;

	do {
		cout << "\n\t1. Ingresar datos. " << endl;
		cout << "\t2. Ver datos. " << endl;
		cout << "\t3. Eliminar datos. " << endl;
		cout << "\t4. Actualizar datos. " << endl;
		cout << "\t5. Regresar al menu principal " << endl;

		cout << "\nDigite opcion: "; cin >> opc;

		switch (opc) {
		case 1: ingresarMarca(); break;
		case 2: mostrarMarca(); break;
		case 3: eliminarMarca(); break;
		case 4: actualizarMarca(); break;
		case 5:	main(); break;
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 6);
}

void menuProducto() {

	int opc;

	do {
		cout << "\n\t1. Ingresar datos. " << endl;
		cout << "\t2. Ver datos. " << endl;
		cout << "\t3. Eliminar datos. " << endl;
		cout << "\t4. Actualizar datos. " << endl;
		cout << "\t5. Regresar al menu principal " << endl;

		cout << "\nDigite opcion: "; cin >> opc;

		switch (opc) {
		case 1: ingresarProducto(); break;
		case 2: mostrarProducto(); break;
		case 3: eliminarProducto(); break;
		case 4: actualizarProducto(); break;
		case 5:	main(); break;
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 6);
}