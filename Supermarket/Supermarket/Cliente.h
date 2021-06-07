#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Persona.h"
#include "ConexionBD.h"

using namespace std;

class Cliente : Persona{

	string NIT, Correo_electronico, Fecha_ingreso;

	   // constructor
	public: Cliente(){
	}
	public: Cliente(string nom_cliente,string ape_cliente,string n_cliente,string gen_cliente,int tel_cliente,string em_cliente,string fi_cliente):Persona(){
		NIT = n_cliente;
		Correo_electronico = em_cliente;
		Fecha_ingreso = fi_cliente;
	}

	// METODOS
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(Telefono);
		if (cn.getconectar()) {
			string  insertar = "INSERT INTO clientes(Nombres,Apellidos,NIT,Genero,Telefono,Correo_electronico,Fecha_ingreso) VALUES ('" + Nombres + "','" + Apellidos + "','" + NIT + "'," + Genero + ",'" + t + "','" + Correo_electronico + "',current_timestamp())";
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

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from clientes";
			const char* nuevoCliente = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), nuevoCliente);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
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
		cout << "Ingrese el idCliente a eliminar: ";
		cin >> e;
		string eliminar = "delete from supermercado.clientes where idCliente= '" + e + "'";
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

	void actualizar(){
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string id;
		string no;
		string ap;
		string nt;
		string ge;
		string te;
		string ce;
		string fin;

		cout << "Ingrese el ID a Editar: ";
		cin >> id; 
		cout << "Ingrese nuevo Nombres: ";
		cin >> no;
		cout << "Ingrese nueva Apellidos: ";
		cin >> ap;
		cout << "Ingrese nuevo NIT: ";
		cin >> nt;
		cout << "Ingrese nuevo Genero: ";
		cin >> ge;
		cout << "Ingrese nuevo Telefono: ";
		cin >> te;
		cout << "Ingrese nuevo Correo electronico: ";
		cin >> ce;
		cout << "Ingrese nueva Fecha de ingreso: ";
		cin >> fin;
		string editar = "update clientes set Nombres= '" + no + "', Apellidos= '" + ap + "', NIT= '" + nt + "', Genero= '" + ge + "', Telefono= '" + te + "', Correo_electronico= '" + ce + "',Fecha_ingreso= current_timestamp() where idCliente='" + id + "'";
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