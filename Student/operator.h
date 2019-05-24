#pragma once

#include "Osoba.h"
#include "Datum.h"

bool operator==(Osoba const & left, Osoba const & right) {
	if (typeid(left) != typeid(right)) {
		return false;
	}
	return left.jednak(right);
}

bool operator!=(Osoba const & left, Osoba const & right) {
	return true;
}

bool operator==(Datum const & left, Datum const & right) {
	return left.m_dan == right.m_dan && left.m_mjesec == right.m_mjesec
		&& left.m_godina == right.m_godina;
}

bool operator!=(Datum const & left, Datum const & right) {
	return left.m_dan != right.m_dan && left.m_mjesec != right.m_mjesec
		&& left.m_godina != right.m_godina;
}

std::ostream& operator<<(std::ostream &stream, Osoba const &osoba) {
	stream << osoba.toString();
	return stream;
}