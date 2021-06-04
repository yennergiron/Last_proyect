#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class VentaM {

	string nFactura, Serie, Fecha_factura, id_Cliente, id_Empleado, Fecha_ingreso;

public: VentaM () {
}
public: VentaM(string nfac_ventam, string ser_ventam, string fechf_ventam, string idcx_ventam, string idemp_ventam, string fi_ventam) {
	nFactura = nfac_ventam;
	Serie = ser_ventam;
	Fecha_factura = fechf_ventam;
	id_Cliente = idcx_ventam;
	id_Empleado = idemp_ventam;
	Fecha_ingreso = fi_ventam;
}

	  // METODOS
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getconectar()) {
			  string  insertar = "INSERT INTO ventas(NoFactura,Serie,Fecha_factura,idCliente,idEmpleado,Fecha_ingreso) VALUES ('" + nFactura + "','" + Serie + "','" + Fecha_factura + "','" + id_Cliente + "','" + id_Empleado + "',current_timestamp());";
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

			  cout << "------------ Datos de Marcas ------------" << endl;
			  string consulta = "select * from ventas";
			  const char* nuevaVentaM = consulta.c_str();
			  q_estado = mysql_query(cn.getconectar(), nuevaVentaM);
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

	  void eliminar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();

		  cn.abrir_conexion();
		  string e;
		  cout << "Ingrese el ID Venta a eliminar: ";
		  cin >> e;
		  string eliminar = "delete from supermercado.ventas where idVenta= '" + e + "'";
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
		  string pc;

		  cout << "Ingrese el ID Venta a Editar: ";
		  cin >> id;
		  cout << "Ingrese nuevo Numero de Factura: ";
		  cin >> n;
		  cout << "Ingrese nueva Serie: ";
		  cin >> m;
		  cout << "Ingrese nueva Fecha de Factura: ";
		  cin >> d;
		  cout << "Ingrese nuevo ID Cliente: ";
		  cin >> im;
		  cout << "Ingrese nuevo ID Empleado: ";
		  cin >> pc;
		  string editar = "update ventas set NoFactura= '" + n + "', Serie= '" + m + "', Fecha_factura = '" + d + "', idCliente= '" + im + "', idEmpleado= '" + pc + "',Fecha_ingreso= current_timestamp() where idVenta='" + id + "'";
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
