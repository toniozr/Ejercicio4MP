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


bool Exercici::consultaTramesa(const string& niu, const string& data, string& fitxer)
{
	int posicio = 0;
	bool trobat = false;
	while (!trobat && posicio < m_nEstudiants)
	{
		if (m_lliuraments[posicio].getNiu() == niu) { trobat = true; }
		else { posicio++; }
	}
	if (trobat)
	{
		trobat = m_lliuraments[posicio].consultaTramesa(data, fitxer);
	}
	return trobat;
}


bool Exercici::eliminaTramesa(const string& niu, const string& data)
{
	bool trobatIeliminat = false;

	for(int i = 0; i < m_nEstudiants; i++)
	{
		if(m_lliuraments[i].getNiu() == niu)
		{
			trobatIeliminat = m_lliuraments[i].eliminaTramesa(data);
			break;
		}
	}

	return trobatIeliminat;
}

Exercici::Exercici(const Exercici& e)
{

	this->m_dataLimit = e.m_dataLimit;
	this->m_descripcio = e.m_descripcio;
	this->m_nEstudiants = e.m_nEstudiants;
	if(e.m_lliuraments != nullptr)
	{
		this->m_lliuraments = new LliuramentsEstudiant[this->m_nEstudiants];
		for(int i = 0; i < this->m_nEstudiants; i++)
		{
			this->m_lliuraments[i] = e.m_lliuraments[i];
		}
	}
	else
		this->m_lliuraments = nullptr;


}

Exercici::~Exercici()
{
	if(this->m_lliuraments != nullptr)
		delete[] m_lliuraments;
}




