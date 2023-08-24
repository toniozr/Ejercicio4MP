#include "LliuramentsEstudiant.h"

void LliuramentsEstudiant::afegeixTramesa(const string& fitxer, const string& data)
{
	Tramesa novaTramesa(fitxer, data);
	m_trameses.push_front(novaTramesa);

	return;
}


bool LliuramentsEstudiant::eliminaTramesa(const string& data)
{
	bool found = false;

	forward_list<Tramesa>::iterator it = m_trameses.begin(), prev = m_trameses.before_begin();

	while(!found && it != m_trameses.end())
	{
		if(it->m_data == data)
		{
			found = true;
			m_trameses.erase_after(prev);
		}
		else
		{
			it++;
			prev++;
		}
	}

	return found;

}

bool LliuramentsEstudiant::consultaTramesa(const string& data, string& fitxer)
{
	bool found = false;

	forward_list<Tramesa>::iterator it = m_trameses.begin();

	while(!found && it != m_trameses.end())
	{
		if(it->m_data == data)
		{
			fitxer = it->m_fitxer;
			found = true;
		}
		else
			it++;
	}

	return found;
}















