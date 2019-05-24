#pragma once
#pragma once
#include "Osoba.h"
#include <string>
class Student : public virtual Osoba
{
public:

	Student(std::string, std::string, int);
	virtual ~Student();
	int getGodina() const;
	friend bool operator==(Osoba const &left, Osoba const &right);
	friend bool operator!=(Osoba const &left, Osoba const &right);
	std::string toString() const;
private:

	int m_godina;

protected:

	virtual bool jednak(Osoba const &o) const;
};

