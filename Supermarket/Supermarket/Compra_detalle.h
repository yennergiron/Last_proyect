#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class CompraD{

	string idCompra, idproducto, cantidad, precio_unitario;

	public: CompraD(){
	}
	public: CompraD(string com_com, string prod_com, string cant_com, string precu_com){
	idCompra = com_com;
	idproducto = prod_com;
	cantidad = cant_com;
	precio_unitario = precu_com;
	}
	
	// METODOS
	void crear(){
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string  insertar = "INSERT INTO compras_detalle(idCompra,idProducto,Cantidad,Precio_costo_unitario) VALUES ('" + idCompra + "','" + idproducto + "','" + cantidad + "','" + precio_unitario + "')";
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

			cout << "------------ Datos de Compras ------------" << endl;
			string consulta = "select * from compras_detalle";
			const char* nuevaCompraD = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), nuevaCompraD);
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
		cout << "Ingrese el ID Compra Detalle a eliminar: ";
		cin >> e;
		string eliminar = "delete from supermercado.compras_detalle where idCompra_detalle= '" + e + "'";
		const char* f = eliminar.c_str();
		q_estado = mysql_query(cn.getconectar(), f);

		if (!q_estado) {
			cout << "Exitoso..." << endl;
		}
		else {
			cout << "** Error al ingresar **" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string id_com;
		string id_new;
		string pro;
		string can;
		string preu;

		cout << "Ingrese el ID Compra Detalle Editar: ";
		cin >> id_com;
		cout << "Ingrese nuevo ID Compra: ";
		cin >> id_new;
		cout << "Ingrese nuevo ID Producto: ";
		cin >> pro;
		cout << "Ingrese nueva Cantidad: ";
		cin >> can;
		cout << "Ingrese nueva Precio Unitario: ";
		cin >> preu;
		string editar = "update compras_detalle set idCompra= '" + id_new + "', idProducto= '" + pro + "', Cantidad = '" + can+ "', Precio_costo_unitario= '" + preu + "' where idCompra_detalle='" + id_com + "'";
		const char* c = editar.c_str();
		q_estado = mysql_query(cn.getconectar(), c);

		if (!q_estado) {
			cout << "Actualizacion Exitosa..." << endl;
		}
		else {
			cout << "** Error al ingresar **" << endl;
		}
		cn.cerrar_conexion();
		
	}
};

