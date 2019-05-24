#include "Datum.h"
#include <string>


Datum::Datum(std::string input) {
	try {
		m_dan = std::stoi(input.substr(0, 2));
		m_mjesec = std::stoi(input.substr(3, 2));
		m_godina = std::stoi(input.substr(6, 4));
	}
	catch (std::exception ex) {
		std::cout << "Exception in Datum constructor!";
	}

}

int Datum::getDan() {
	return this->m_dan;
}

int Datum::getMjesec() {
	return this->m_mjesec;
}

int Datum::getGodina() {
	return this->m_godina;
}

std::string Datum::toString() {
	return std::to_string(m_dan) + ":" + std::to_string(m_mjesec) + ":" + std::to_string(m_godina);
}