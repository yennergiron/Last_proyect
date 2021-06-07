#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class CompraM {

	string orden_com, id_proveedor, Fecha_orden, fecha_ingreso;

public: CompraM() {
}
public: CompraM(string orden_c, string id_proveer, string Fecha_or, string fecha_in) {
	orden_com = orden_c;
	id_proveedor = id_proveer;
	Fecha_orden = Fecha_or;
	fecha_ingreso = fecha_in;
}

	  // METODOS
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getconectar()) {
			  string  insertar = "INSERT INTO compras(No_orden_compra,idProveedor,Fecha_orden,Fecha_ingreso) VALUES ('" + orden_com + "','" + id_proveedor + "','" + Fecha_orden + "',current_timestamp());";
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

	  void mostrar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getconectar()) {

			  cout << "------------ Datos de Compras ------------" << endl;
			  string consulta = "select * from compras";
			  const char* nuevaCompraM = consulta.c_str();
			  q_estado = mysql_query(cn.getconectar(), nuevaCompraM);
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

	  void eliminar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();

		  cn.abrir_conexion();
		  string e;
		  cout << "Ingrese el ID Compra a eliminar: ";
		  cin >> e;
		  string eliminar = "delete from supermercado.compras where idCompra= '" + e + "'";
		  const char* f = eliminar.c_str();
		  q_estado = mysql_query(cn.getconectar(), f);

		  if (!q_estado) {
			  cout << "Eliminacion Exitosa..." << endl;
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
		  string orden_new;
		  string idp;
		  string ord;


		  cout << "Ingrese el ID Compra a Editar: ";
		  cin >> id_com;
		  cout << "Ingrese nuevo Orden de Compra: ";
		  cin >> orden_new;
		  cout << "Ingrese nuevo ID Proveedor: ";
		  cin >> idp;
		  cout << "Ingrese nueva Fecha Orden: ";
		  cin >> ord;
		  string editar = "update compras set No_orden_compra= '" + orden_new + "', idProveedor= '" + idp + "', Fecha_orden = '" + ord + "',Fecha_ingreso= current_timestamp() where idCompra='" + id_com + "'";
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
