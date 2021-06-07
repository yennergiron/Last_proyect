#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Persona.h"
#include "ConexionBD.h"

using namespace std;

class Empleado : Persona{

	string idPuesto, Fecha_inicio_labores, Fecha_ingreso;
	
	public: Empleado() {
	}
	public: Empleado(string nom_empleado,string ape_empleado,string dir_empleado,int tel_empleado,string dpi_empleado,string gen_empleado,string fn_empleado,string idp_empleado,string fil_empleado,string fi_empleado):Persona(nom_empleado,ape_empleado,dir_empleado,tel_empleado,dpi_empleado,gen_empleado,fn_empleado){
		idPuesto = idp_empleado;
		Fecha_inicio_labores = fil_empleado;
		Fecha_ingreso = fi_empleado;
	}
	
	// METODOS
	void crear(){
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(Telefono);
		if (cn.getconectar()) {
			string  insertar = "INSERT INTO empleados(Nombres,Apellidos,Direccion,Telefono,DPI, Genero,Fecha_nacimiento, idPuesto,Fecha_inicio_labores,Fecha_ingreso) VALUES ('" + Nombres + "','" + Apellidos + "','" + Direccion + "'," + t + ",'" + DPI + "','" + Genero + "','" + Fecha_nacimiento + "', '" + idPuesto + "', '" + Fecha_inicio_labores + "',current_timestamp())";
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
			string consulta = "select * from empleados";
			const char* nuevoEmpleado = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), nuevoEmpleado);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "\t" << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << "," << fila[9] << "," << fila[10] << endl;
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
		cout << "Ingrese el idEmpleado a eliminar: ";
		cin >> e;
		string eliminar = "delete from supermercado.empleados where idEmpleado='" + e + "'";
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
		string DP;
		string g;
		string fn;
		string ip;
		string fi;
		string la;

		cout << "Ingrese el ID a Editar: ";
		cin >> id;
		cout << "Ingrese nuevo Nombres: ";
		cin >> n;
		cout << "Ingrese nueva Apellidos: ";
		cin >> a;
		cout << "Ingrese nuevo Direccion: ";
		cin >> d;
		cout << "Ingrese nuevo Telefono: ";
		cin >> t;
		cout << "Ingrese nuevo DPI: ";
		cin >> DP;
		cout << "Ingrese nuevo Genero: ";
		cin >> g;
		cout << "Ingrese nuevo Fecha de Nacimiento: ";
		cin >> fn;
		cout << "Ingrese nuevo idPuesto: ";
		cin >> ip;
		cout << "Ingrese nueva Fecha incio de Labores: ";
		cin >> la;
		cout << "Ingrese nueva Fecha de ingreso: ";
		cin >> fi;
		string editar = "update empleados set Nombres= '" + n + "', Apellidos= '" + a + "', Direccion= '" + d + "', Telefono= '" + t + "', DPI= '" + DP + "', Genero= '" + g + "', Fecha_nacimiento= '" + fn + "', idPuesto = '" + ip + "', Fecha_inicio_labores= '" + la + "',Fecha_ingreso= current_timestamp() where idEmpleado='" + id + "'";
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
	