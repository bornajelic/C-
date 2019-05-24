#pragma once



#include "PrivremeniZaposlenik.h"
#include "Student.h"


class AngaziraniStudent : public PrivremeniZaposlenik , public Student
{
public:
	AngaziraniStudent(std::string , std::string, int, Datum, int, Datum);
	AngaziraniStudent(std::string, std::string, int, std::string, int, std::string);
	~AngaziraniStudent();
	friend bool operator==(Osoba const &left, Osoba const &right);
	friend bool operator!=(Osoba const &left, Osoba const &right);
	std::string toString() const;
protected:

	bool jednak(Osoba const &o) const;
};



