// Supermarket.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <stdlib.h>
#include "Empleado.h"
#include "Cliente.h"
#include "Puesto.h"
#include "proveedor.h"
#include "Marca.h"
#include "Producto.h"
#include "Venta_detalle.h"
#include "Venta_Master.h"
#include "Compra_detalle.h"
#include "Compra_Master.h"

using namespace  std;

void menu();
void menuEmpleado();
void menuCliente();
void menuPuesto();
void menuProveedores();
void menuMarcas();
void menuProducto();
void menuVentad();
void menuVentaM();
void menuCompraD();
void menuCompraM();

void ingresarEmpleado() {
	string  nom, ape, dir, dpi, gen, fn, idp, fil, fi, n, em;
	int tel;
	cout << "\tIngrese Nombres:"; cin>> nom;
	cout << "\tIngrese Apellidos:"; cin>> ape;
	cout << "\tIngrese Direccion:"; cin>> dir;
	cout << "\tIngrese Telefono:"; cin >> tel; cin.ignore();
	cout << "\tIngrese DPI:"; cin >> dpi;
	cout << "\tIngrese Genero:"; cin >> gen;
	cout << "\tIngrese Fecha_nacimiento AAAA/MM/DD:"; cin >> fn;
	cout << "\tIngrese idPuesto (numero) :"; cin >> idp;
	cout << "\tIngrese Fecha_inicio_labores AAAA/MM/DD:"; cin >> fil;
	cout << "\tIngrese Fecha_ingreso AAAA/MM/DD:"; cin >> fi;
	
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
	cout << "\tIngrese Nombres:"; cin >> nom;
	cout << "\tIngrese Apellidos:"; cin >> ape;
	cout << "\tIngrese NIT:"; cin >> n; cin.ignore();
	cout << "\tIngrese Genero:"; cin >> gen;
	cout << "\tIngrese Telefono:"; cin >> tel; cin.ignore();
	cout << "\tIngrese Correo Electronico:"; cin >> em;
	cout << "\tIngrese Fecha Ingreso AAAA/MM/DD:"; cin >> fi;

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
	cout << "\tIngrese Puesto:"; cin >> pue;

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
	cout << "\tIngrese Proveedor:"; cin >> prov;
	cout << "\tIngrese NIT: "; cin >> n;
	cout << "\tIngrese Direccion: "; cin >> dir;
	cout << "\tIngrese Telefono:"; cin >> tel; cin.ignore();

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
	cout << "\tIngrese Marca:"; cin >> mar;

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
	cout << "\tIngrese Producto:"; cin >> prod;
	cout << "\tIngrese ID Marca (numero de ID):"; cin >> idmar;
	cout << "\tIngrese Descripcion:"; cin >> desc;
	cout << "\tIngrese Imagen:"; cin >> ima;
	cout << "\tIngrese Precio de Costo:"; cin >> pc;
	cout << "\tIngrese Precio de Venta:"; cin >> pv;
	cout << "\tIngrese Existencia:"; cin >> ex;
	cout << "\tIngrese Fecha de Ingreso AAAA/MM/DD:"; cin >> fi;

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

void ingresarVentad() {
	string idven, idprod, cant, precu;
	cout << "\tIngrese ID Venta:"; cin >> idven;
	cout << "\tIngrese ID Producto:"; cin >> idprod;
	cout << "\tIngrese Cantidad:"; cin >> cant;
	cout << "\tIngrese Precio Unitario:"; cin >> precu;

	VentaD nuevaVentad = VentaD(idven, idprod, cant, precu);
	nuevaVentad.crear();
}
void mostrarVentad() {
	VentaD nuevaVentad = VentaD();
	nuevaVentad.mostrar();
}
void eliminarVentad() {
	VentaD nuevaVentad = VentaD();
	nuevaVentad.eliminar();
}
void actualizarVentad() {
	VentaD nuevaVentad = VentaD();
	nuevaVentad.actualizar();
}

void ingresarVentaM() {
	string nofac, ser, ffac, idcx, idem, fi;
	cout << "\tIngrese Numero de Factura:"; cin >> nofac;
	cout << "\tIngrese Serie:"; cin >> ser;
	cout << "\tIngrese Fecha de la Factura AAAA/MM/DD:"; cin >> ffac;
	cout << "\tIngrese ID del Cliente:"; cin >> idcx;
	cout << "\tINgrese ID del Empleado: "; cin >> idem;
	cout << "\tIngrese Fecha de Ingreso AAAA/MM/DD: "; cin >> fi;

	VentaM nuevaVentaM = VentaM(nofac, ser, ffac, idcx, idem, fi);
	nuevaVentaM.crear();
}
void mostrarVentaM() {
	VentaM nuevaVentaM = VentaM();
	nuevaVentaM.mostrar();
}
void eliminarVentaM() {
	VentaM nuevaVentaM = VentaM();
	nuevaVentaM.eliminar();
}
void actualizarVentaM() {
	VentaM nuevaVentaM = VentaM();
	nuevaVentaM.actualizar();
}

void ingresarCompraD() {
	string idco, idprod, cant, precoun;
	cout << "\tIngrese ID de la Compra:"; cin >> idco;
	cout << "\tIngrese ID del producto:"; cin >> idprod;
	cout << "\tIngrese Cantidad:"; cin >> cant;
	cout << "\tIngrese el Precio Costo Unitario:"; cin >> precoun;

	CompraD nuevaCompraD = CompraD(idco, idprod, cant, precoun);
	nuevaCompraD.crear();
}
void mostrarCompraD() {
	CompraD nuevaCompraD = CompraD();
	nuevaCompraD.mostrar();
}
void eliminarCompraD() {
	CompraD nuevaCompraD = CompraD();
	nuevaCompraD.eliminar();
}
void actualizarCompraD() {
	CompraD nuevaCompraD = CompraD();
	nuevaCompraD.actualizar();
}

void ingresarCompraM() {
	string nocom, idprov, feo, fei;
	cout << "\tIngrese No de Orden de la Compra:"; cin >> nocom;
	cout << "\tIngrese ID del Proveedor:"; cin >> idprov;
	cout << "\tIngrese Fecha de la Orden AAAA/MM/DD:"; cin >> feo;
	cout << "\tIngrese Fecha de Ingreso AAAA/MM/DD:"; cin >> fei;

	CompraM nuevaCompraM = CompraM(nocom, idprov, feo, fei);
	nuevaCompraM.crear();
}
void mostrarCompraM() {
	CompraM nuevaCompraM = CompraM();
	nuevaCompraM.mostrar();
}
void eliminarCompraM() {
	CompraM nuevaCompraM = CompraM();
	nuevaCompraM.eliminar();
}
void actualizarCompraM() {
	CompraM nuevaCompraM = CompraM();
	nuevaCompraM.actualizar();
}

int main(){
	
	system("color FD");

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
		case 7: menuVentad(); break;
		case 8: menuVentaM(); break;
		case 9: menuCompraD(); break;
		case 10: menuCompraM(); break;
		case 11: exit(1);
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 11);
	return 0;
}

void menu() {

	int opc;
	system("cls");
	cout << "\n\t************************************";
	cout << "\n\t\t----Bienvenidos---- " << endl;
		cout << "\n\t1. Tabla Empleado. " << endl;
		cout << "\t2. Tabla Cliente. " << endl;
		cout << "\t3. Tabla Puesto. " << endl;
		cout << "\t4. Tabla Proveedores. " << endl;
		cout << "\t5. Tabla Marcas. " << endl;
		cout << "\t6. Tabla Productos. " << endl;
		cout << "\t7. Tabla Ventas Detalle. " << endl;
		cout << "\t8. Tabla Venta Maestro. " << endl;
		cout << "\t9. Tabla Compras Detalle. " << endl;
		cout << "\t10. Tabla Compra Maestro. " << endl;
		cout << "\t11. Salida del Sistema" << endl;
		cout << "\n\t************************************";

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
	} while (opc != 5);
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
	} while (opc != 5);
}

void menuVentad() {

	int opc;

	do {
		cout << "\n\t1. Ingresar datos. " << endl;
		cout << "\t2. Ver datos. " << endl;
		cout << "\t3. Eliminar datos. " << endl;
		cout << "\t4. Actualizar datos. " << endl;
		cout << "\t5. Regresar al menu principal " << endl;

		cout << "\nDigite opcion: "; cin >> opc;

		switch (opc) {
		case 1: ingresarVentad(); break;
		case 2: mostrarVentad(); break;
		case 3: eliminarVentad(); break;
		case 4: actualizarVentad(); break;
		case 5:	main(); break;
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 5);
}

void menuVentaM() {

	int opc;

	do {
		cout << "\n\t1. Ingresar datos. " << endl;
		cout << "\t2. Ver datos. " << endl;
		cout << "\t3. Eliminar datos. " << endl;
		cout << "\t4. Actualizar datos. " << endl;
		cout << "\t5. Regresar al menu principal " << endl;

		cout << "\nDigite opcion: "; cin >> opc;

		switch (opc) {
		case 1: ingresarVentaM(); break;
		case 2: mostrarVentaM(); break;
		case 3: eliminarVentaM(); break;
		case 4: actualizarVentaM(); break;
		case 5:	main(); break;
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 5);
}

void menuCompraD() {

	int opc;

	do {
		cout << "\n\t1. Ingresar datos. " << endl;
		cout << "\t2. Ver datos. " << endl;
		cout << "\t3. Eliminar datos. " << endl;
		cout << "\t4. Actualizar datos. " << endl;
		cout << "\t5. Regresar al menu principal " << endl;

		cout << "\nDigite opcion: "; cin >> opc;

		switch (opc) {
		case 1: ingresarCompraD(); break;
		case 2: mostrarCompraD(); break;
		case 3: eliminarCompraD(); break;
		case 4: actualizarCompraD(); break;
		case 5:	main(); break;
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 5);
}

void menuCompraM() {

	int opc;

	do {
		cout << "\n\t1. Ingresar datos. " << endl;
		cout << "\t2. Ver datos. " << endl;
		cout << "\t3. Eliminar datos. " << endl;
		cout << "\t4. Actualizar datos. " << endl;
		cout << "\t5. Regresar al menu principal " << endl;

		cout << "\nDigite opcion: "; cin >> opc;

		switch (opc) {
		case 1: ingresarCompraM(); break;
		case 2: mostrarCompraM(); break;
		case 3: eliminarCompraM(); break;
		case 4: actualizarCompraM(); break;
		case 5:	main(); break;
		default: cout << "opcion no valida... "; break;
		}
		system("pause");
		system("cls");
	} while (opc != 5);
}