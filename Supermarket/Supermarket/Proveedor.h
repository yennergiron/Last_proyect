#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Proveedores{

	string Proveedor, NIT, Direccion;
	int Telefono = 0;
	
	public: Proveedores() {
	}
	public: Proveedores(string prov_proveedor,string n_proveedor,string dir_proveedor,int tel_proveedor){;
		Proveedor = prov_proveedor;
		NIT = n_proveedor;
		Direccion = dir_proveedor;
		Telefono = tel_proveedor;
	}
	
	// METODOS
	void crear(){
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(Telefono);
		if (cn.getconectar()) {
			string  insertar = "INSERT INTO proveedores(Proveedor,NIT,Direccion,Telefono) VALUES ('" + Proveedor + "','" + NIT + "','" + Direccion + "'," + t + ")";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void mostrar(){
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {

			cout << "------------ Datos de Empleados ------------" << endl;
			string consulta = "select * from proveedores";
			const char* nuevoProveedor = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), nuevoProveedor);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(){
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string e;
		cout << "Ingrese el idProveedor a eliminar: ";
		cin >> e;
		string eliminar = "delete from supermercado.proveedores where idProveedore= '" + e + "'";
		const char* f = eliminar.c_str();
		q_estado = mysql_query(cn.getconectar(), f);

		if (!q_estado) {
			cout << "Ingreso Exitoso..." << endl;
		}
		else {
			cout << "**** Error al ingresar ****" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string id;
		string n;
		string a;
		string d;
		string t;

		cout << "Ingrese el ID a Editar: ";
		cin >> id;
		cout << "Ingrese nuevo Proveedor: ";
		cin >> n;
		cout << "Ingrese nuevo NIT: ";
		cin >> a;
		cout << "Ingrese nuevo Direccion: ";
		cin >> d;
		cout << "Ingrese nuevo Telefono: ";
		cin >> t;
		string editar = "update proveedores set Proveedor= '" + n + "', NIT= '" + a + "', Direccion= '" + d + "', Telefono= '" + t + "'";
		const char* c = editar.c_str();
		q_estado = mysql_query(cn.getconectar(), c);

		if (!q_estado) {
			cout << "Ingreso Exitoso..." << endl;
		}
		else {
			cout << "**** Error al ingresar ****" << endl;
		}
		cn.cerrar_conexion();
		
	}
};

