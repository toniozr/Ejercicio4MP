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


