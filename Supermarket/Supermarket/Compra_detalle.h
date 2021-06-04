#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class VentaD{

	string idVenta, idProducto, Cantidad, Precio_unitario;

	public: VentaD(){
	}
	public: VentaD(string ven_ventad, string prod_ventad, string cant_ventad, string precu_ventad){
	idVenta = ven_ventad;
	idProducto = prod_ventad;
	Cantidad = cant_ventad;
	Precio_unitario = precu_ventad;
	}
	
	// METODOS
	void crear(){
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string  insertar = "INSERT INTO ventas_detalle(idVenta,idProducto,Cantidad,Precio_unitario) VALUES ('" + idVenta + "','" + idProducto + "','" + Cantidad + "','" + Precio_unitario + "')";
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

			cout << "------------ Datos de Marcas ------------" << endl;
			string consulta = "select * from ventas_detalle";
			const char* nuevaVentad = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), nuevaVentad);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << endl;
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
		cout << "Ingrese el ID Venta Detalle a eliminar: ";
		cin >> e;
		string eliminar = "delete from supermercado.ventas_detalle where idVenta_detalle= '" + e + "'";
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
		string m;
		string d;
		string im;

		cout << "Ingrese el ID Venta Detalle Editar: ";
		cin >> id;
		cout << "Ingrese nuevo ID Venta: ";
		cin >> n;
		cout << "Ingrese nuevo ID Producto: ";
		cin >> m;
		cout << "Ingrese nueva Cantidad: ";
		cin >> d;
		cout << "Ingrese nueva Precio Unitario: ";
		cin >> im;
		string editar = "update ventas_detalle set idVenta= '" + n + "', idProducto= '" + m + "', Cantidad = '" + d + "', Precio_unitario= '" + im + "' where idVenta_detalle='" + id + "'";
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

