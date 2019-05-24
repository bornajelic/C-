#include "AngaziraniStudent.h"
#include <string>


AngaziraniStudent::AngaziraniStudent(std::string ime, std::string prezime, int radnoMjesto, Datum pocetakZaposlenja, int godina, Datum krajZaposlenja)
	: Osoba(ime,prezime),PrivremeniZaposlenik(ime,prezime,pocetakZaposlenja,radnoMjesto,krajZaposlenja),Student(ime,prezime,godina)
{
}

AngaziraniStudent::AngaziraniStudent(std::string ime, std::string prezime, int radnoMjesto, std::string pocetakZaposlenja, int godina, std::string krajZaposlenja)
	: AngaziraniStudent(ime,prezime,radnoMjesto,Datum(pocetakZaposlenja),godina,Datum(krajZaposlenja)) {}


AngaziraniStudent::~AngaziraniStudent() {}

std::string AngaziraniStudent::toString() const
{
	
	return Zaposlenik::toString() + std::to_string(this->getGodina());
}

bool AngaziraniStudent::jednak(Osoba const & o) const
{
	AngaziraniStudent const & as = dynamic_cast <AngaziraniStudent const &>(o);
	return (this->getGodina() && as.getGodina() && this->getIme() == as.getIme()
		&& this->getPrezime() == as.getPrezime() && this->getKrajZaposlenja() == as.getKrajZaposlenja() && this->getPocetakZaposlenja() == as.getPocetakZaposlenja()
		&& this->getRadnoMjesto() == as.getRadnoMjesto());
}

