#include "Zaposlenik.h"



Zaposlenik::Zaposlenik(std::string ime, std::string prezime, Datum pocetakZaposlenja, int radnoMjesto) : Osoba(ime,prezime), m_pocetakZaposlenja(pocetakZaposlenja),m_radnoMjesto(radnoMjesto) 
{
	std::cout << "ZAPOSLENIK Ctor\n";
}

Zaposlenik::Zaposlenik(std::string ime, std::string prezime, std::string pocetakZaposlenja, int radnoMjesto) : Zaposlenik(ime,prezime,Datum(pocetakZaposlenja),radnoMjesto) {}
Zaposlenik::~Zaposlenik(){}

int Zaposlenik::getRadnoMjesto() const {
	return this->m_radnoMjesto;
}

Datum Zaposlenik::getPocetakZaposlenja() const {
	return this->m_pocetakZaposlenja;
}

std::string Zaposlenik::toString() const
{
	return Osoba::toString() + std::to_string(this->getRadnoMjesto()) + this->getPocetakZaposlenja().toString();
}

bool Zaposlenik::jednak(Osoba const & o) const
{
	Zaposlenik const &zaposlenik = dynamic_cast<Zaposlenik const &>(o);
	return(this->getIme() == zaposlenik.getIme() && this->getPrezime() == zaposlenik.getPrezime() && this->getPocetakZaposlenja() == zaposlenik.getPocetakZaposlenja() && this->getRadnoMjesto() == zaposlenik.getRadnoMjesto());
	
}

