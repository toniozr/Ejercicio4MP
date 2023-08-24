#pragma once
#include <string>
using namespace std;

class Tramesa
{
public:
	Tramesa() : m_fitxer(""), m_data("") {};
	Tramesa(const string& fitxer, const string& data) : m_fitxer(fitxer), m_data(data) {}
	void setFitxer(const string& fitxer) { m_fitxer = fitxer; }
	void setData(const string& data) { m_data = data; }
	string getFitxer() const { return m_fitxer; }
	string getData() const { return m_data; }

	Tramesa& operator=(const Tramesa& other)
	{
	    if (this != &other) {
	        m_fitxer = other.m_fitxer;
	        m_data = other.m_data;
	    }
	    return *this;
	}


private:
	string m_fitxer;
	string m_data;
};

