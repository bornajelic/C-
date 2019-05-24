#pragma once
#include "Osoba.h"
#include "Datum.h"
class Zaposlenik : public virtual Osoba{

public:
	Zaposlenik(std::string , std::string , Datum , int );
	Zaposlenik(std::string, std::string, std::string, int); //delegating Ctor
	virtual ~Zaposlenik();
	friend bool operator==(Osoba const &left, Osoba const &right);
	friend bool operator!=(Osoba const &left, Osoba const &right);
	friend bool operator==(Datum const &left, Datum const &right);
	friend bool operator!=(Datum const &left, Datum const &right);
	int getRadnoMjesto() const;
	Datum getPocetakZaposlenja() const;
	std::string toString() const;
private :

	int m_radnoMjesto;
	Datum m_pocetakZaposlenja;

protected:

	virtual bool jednak(Osoba const &o) const;
};

