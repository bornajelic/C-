#pragma once


#include <iostream>
struct Datum {

	int m_dan;
	int m_mjesec;
	int m_godina;

	Datum(std::string);
	int getDan();
	int getMjesec();
	int getGodina();
	std::string toString();
};

