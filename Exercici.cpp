#include "Exercici.h"
#include <fstream>
#include <iostream>
using namespace std;


void Exercici::inicialitzaEstudiants(const string& fitxerEstudiants)
{
	ifstream fitxer;
	fitxer.open(fitxerEstudiants);
	if(!fitxer.is_open())
	{
		cout << "Fitxer: '" << fitxerEstudiants << "' no s'ha obert correctament a la funció inicialitzaEstudiants" << endl;
	}
	else
	{
		fitxer >> m_nEstudiants;
		m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
		string niu;
		int i = 0;
		while(!fitxer.eof() && i < m_nEstudiants)
		{
			fitxer >> niu;
			m_lliuraments[i].setNiu(niu);
			i++;
		}
	}
}

bool Exercici::afegeixTramesa(const string& niu, const string& fitxer, const string& data)
{
	int posicio = 0;
	bool trobat = false;
	while(!trobat && posicio < m_nEstudiants)
	{
		if (m_lliuraments[posicio].getNiu() == niu) { trobat = true; }
		else { posicio++; }
	}
	if (trobat) { m_lliuraments[posicio].afegeixTramesa(fitxer, data); }
	else
	{
		LliuramentsEstudiant* aux = new LliuramentsEstudiant[m_nEstudiants + 1];
		for(int i = 0; i < m_nEstudiants; i++)
		{
			aux[i] = m_lliuraments[i];
		}
		delete[] m_lliuraments;
		m_lliuraments = aux;
		m_nEstudiants++;
		m_lliuraments[m_nEstudiants - 1].afegeixTramesa(fitxer, data);
	}
	return trobat;
}


