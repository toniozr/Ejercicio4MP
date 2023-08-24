#include "LliuramentsEstudiant.h"

void LliuramentsEstudiant::afegeixTramesa(const string& fitxer, const string& data)
{
	Tramesa novaTramesa(fitxer, data);
	m_trameses.push_front(novaTramesa);

	return;
}
