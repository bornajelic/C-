#include "Student.h"

Student::Student(std::string ime, std::string prezime, int godina) : Osoba(ime,prezime),m_godina(godina) {}


Student::~Student(){}

int Student::getGodina() const{
	return this->m_godina;
}

std::string Student::toString() const
{
	
	return Osoba::toString()+  " " + std::to_string(this->getGodina());
}

bool Student::jednak(Osoba const & o) const
{
	Student const &student = dynamic_cast<Student const &>(o);
	return (this->getGodina() == student.getGodina() && this->getIme() == student.getIme() && this->getPrezime() == student.getPrezime());
}

