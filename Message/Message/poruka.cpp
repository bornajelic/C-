#include "Poruka.h"
#include <iostream>
#include <algorithm>
#include <sstream>
Kategorija::Kategorija(std::string const &opis){
	mOpis = opis;
}

Kategorija::~Kategorija()
{
}

void Kategorija::dodaj_poruku(Poruka *p) { //ova funkcija mora biti pozvana automatski sa funkcijojm Poruka::dodaj()
	this -> mPorukeSet.insert(p);
}

void Kategorija::ukloni_poruku(Poruka *p) {
	
	std::set<Poruka*>::iterator to_delete = this->mPorukeSet.begin();
	for (to_delete; to_delete != mPorukeSet.end(); ++to_delete) {
		if (*to_delete == p) {
			this->mPorukeSet.erase(to_delete);
			//delete *to_delete;
			break;
		}
	}
}



std::set<Poruka*> Kategorija::getMPorukeSet() {
	return mPorukeSet;
}




//class Poruka

Poruka::Poruka(std::string const &sadrzaj) {
	mSadrzaj = sadrzaj;
}

Poruka::Poruka(Poruka const &p) {
	std::cout << "Poruka copy constr..\n";
	mSadrzaj = p.mSadrzaj;
	mKategorijeSet = p.mKategorijeSet;
}
Poruka::Poruka(Poruka &&p) { //??
	std::cout << "Poruka move constr..\n";
	this->mKategorijeSet = p.mKategorijeSet;
	this->mSadrzaj = p.mSadrzaj;
}

Poruka& Poruka::operator=(Poruka const &p) { //rvalue reference(assigment op)
	std::cout << "Poruka assigment operator..\n";
	if (this != &p) { //sto znaci *this = p
		this->mSadrzaj = p.mSadrzaj;
		this->mKategorijeSet = p.mKategorijeSet;
	}
	return *this;
}

Poruka& Poruka::operator=(Poruka &&p) { //?? mora se i micati iz seta, odnosno promijeniti
	std::cout << "Poruka MOVE assigment operator..\n";
	if (this != &p) {
		*this = p;	
	}
	return *this;
}

Poruka::~Poruka()
{
	std::cout << "DELETE\n";
}

void Poruka::dodaj(Kategorija &k) { //dodaj poruku u danu kategoriju
	k.dodaj_poruku(this);

	Kategorija *pk = &k;
	mKategorijeSet.insert(pk);
}

void Poruka::ukloni(Kategorija &k) { //ukloni poruku iz dane kategorije
	this->mKategorijeSet.erase(&k);
	k.ukloni_poruku(this);
}


std::string Poruka::kategorije() const {

	std::string tmp;
	std::stringstream ss;
	std::set<Kategorija*>::iterator it_outer;
	for (it_outer = mKategorijeSet.begin(); it_outer != mKategorijeSet.end(); ++it_outer) {
		std::string str = "";
		ss << (*it_outer)->opis() << " ";
		}

	tmp = ss.str();
	return tmp;
}




