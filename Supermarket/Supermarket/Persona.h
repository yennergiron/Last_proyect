#pragma once
#include <iostream>

using namespace std;

class Persona{
	// atributos
	protected: string Nombres, Apellidos, Direccion, DPI, Genero, Fecha_nacimiento;
	protected: int Telefono = 0;
		 // costructor
	public: Persona() {

	}
	public: Persona(string nom, string ape, string dir, int tel, string dpi, string gen, string fn) {
		Nombres = nom;
		Apellidos = ape;
		Direccion = dir;
		Telefono = tel;
		DPI = dpi;
		Genero = gen;
		Fecha_nacimiento = fn;
	}

	void crear() {
		cout << Nombres << endl;
		cout << Apellidos << endl;
		cout << Direccion << endl;
		cout << Telefono << endl;
		cout << DPI << endl;
		cout << Genero << endl;
		cout << Fecha_nacimiento << endl;
		}

	void mostrar() {
		cout << Nombres << endl;
		cout << Apellidos << endl;
		cout << Direccion << endl;
		cout << Telefono << endl;
		cout << DPI << endl;
		cout << Genero << endl;
		cout << Fecha_nacimiento << endl;
	}

	void eliminar() {
		cout << Nombres << endl;
		cout << Apellidos << endl;
		cout << Direccion << endl;
		cout << Telefono << endl;
		cout << DPI << endl;
		cout << Genero << endl;
		cout << Fecha_nacimiento << endl;
	}

	void actualizar() {
		cout << Nombres << endl;
		cout << Apellidos << endl;
		cout << Direccion << endl;
		cout << Telefono << endl;
		cout << DPI << endl;
		cout << Genero << endl;
		cout << Fecha_nacimiento << endl;

	}
};

