#pragma once
#ifndef OSOBA_H
#define OSOBA_H
#include <iostream>
#include <string>
using std::cout;
using std::endl;
class Osoba {

private:

	std::string m_ime;
	std::string m_prezime;

protected:

	bool jednak(Osoba const &o) const;

public:
	Osoba(std::string, std::string);
	virtual ~Osoba();
	friend bool operator==(Osoba const &left, Osoba const &right);
	friend bool operator!=(Osoba const &left, Osoba const &right);
	std::string getIme() const;
	std::string getPrezime() const;
	std::string toString() const;
};


#endif
