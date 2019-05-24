#include "Osoba.h"
#include "operator.h"

bool Osoba::jednak(Osoba const & o) const
{
	return (this->getIme() == o.getIme() && this->getPrezime() == o.getPrezime());
}

Osoba::Osoba(std::string ime, std::string prezime) : m_ime(ime), m_prezime(prezime) {
	cout << "OSOBA Ctor\n";
}


Osoba::~Osoba() {}

std::string Osoba::getIme() const {
	return this->m_ime;
}

std::string Osoba::getPrezime() const {
	return this->m_prezime;
}

std::string Osoba::toString() const
{
	return this->getIme() + " " + this->getPrezime() + "\n";
}


