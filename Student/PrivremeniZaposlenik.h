#pragma once
#include "Zaposlenik.h"

class PrivremeniZaposlenik : public  Zaposlenik {

public:

	PrivremeniZaposlenik(std::string ,std::string, Datum, int, Datum);
	PrivremeniZaposlenik(std::string, std::string, std::string, int, std::string);
	virtual ~PrivremeniZaposlenik();
	friend bool operator==(Osoba const &left, Osoba const &right);
	friend bool operator!=(Osoba const &left, Osoba const &right);
	Datum getKrajZaposlenja() const;
	std::string toString() const;
private:

	Datum m_krajZaposlenja;

protected:

	bool jednak(Osoba const &o) const;
};

