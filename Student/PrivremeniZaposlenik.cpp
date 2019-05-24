#include "PrivremeniZaposlenik.h"



PrivremeniZaposlenik::PrivremeniZaposlenik(std::string ime, std::string prezime, Datum pocetakZaposlenja, int radnoMjesto, Datum krajZaposlenja)
	: Osoba(ime,prezime), Zaposlenik(ime, prezime, pocetakZaposlenja, radnoMjesto), m_krajZaposlenja(krajZaposlenja) 
{
	std::cout << "PRIVREMENI ZAPOSLENIK - Ctor\n";
}

PrivremeniZaposlenik::PrivremeniZaposlenik(std::string ime, std::string prezime, std::string pocetakZaposlenja, int radnoMjesto, std::string krajZaposlenja) 
	: PrivremeniZaposlenik(ime,prezime,Datum(pocetakZaposlenja),radnoMjesto,Datum(krajZaposlenja)) {}


PrivremeniZaposlenik::~PrivremeniZaposlenik(){}


Datum PrivremeniZaposlenik::getKrajZaposlenja() const{
	return this->m_krajZaposlenja;
}

std::string PrivremeniZaposlenik::toString() const
{
	/*Datum d1(this->getPocetakZaposlenja());
	Datum d2(this->getKrajZaposlenja());
	return this->getIme() + " " + this->getPrezime() + std::to_string(this->getRadnoMjesto()) + " " + d1.toString() + " " + d2.toString();*/

	return Zaposlenik::toString() + this->getKrajZaposlenja().toString();
}

bool PrivremeniZaposlenik::jednak(Osoba const & o) const
{
	PrivremeniZaposlenik const &pz = dynamic_cast<PrivremeniZaposlenik const&>(o);
	return (this->getIme() == pz.getIme() && this->getPrezime() == pz.getPrezime() && this->getKrajZaposlenja() == pz.getKrajZaposlenja() && this->getPocetakZaposlenja() == pz.getPocetakZaposlenja() && this->getRadnoMjesto() == pz.getRadnoMjesto());
}

