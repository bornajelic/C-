#pragma once
#ifndef PORUKA_H_INCLUDED
#define PORUKA_H_INCLUDED

#include <string>
#include <set>

class Poruka;

class Kategorija {

private:
	//pokazivaci na poruke u kategoriji
	std::set<Poruka*> mPorukeSet; //set je jedna kategorija
	//opis kategorije
	std::string mOpis;

public:

	explicit Kategorija(std::string const &opis);
	//zabranjeno kopiranje
	Kategorija(Kategorija const&) = delete;
	Kategorija(Kategorija &&) = delete;
	//assigment operator
	Kategorija& operator=(Kategorija const &) = delete;
	Kategorija& operator=(Kategorija &&) = delete;
	~Kategorija();

	
	void dodaj_poruku(Poruka *);
	void ukloni_poruku(Poruka *);
	std::set<Poruka*> getMPorukeSet();
	std::string opis() const {
		return mOpis;
	}
 };

class Poruka {
	friend class Kategorija;

private:
	std::string mSadrzaj;
	std::set<Kategorija*> mKategorijeSet;

public:
	explicit Poruka(std::string const &sadrzaj = "");
	Poruka(Poruka const &);
	Poruka(Poruka &&);
	Poruka& operator=(Poruka const&);
	Poruka& operator=(Poruka&&);
	~Poruka();

	void dodaj(Kategorija&);
	void ukloni(Kategorija&);
	std::set<Kategorija*> getKategorijaSet() {
		return mKategorijeSet;
	}
	std::string sadrzaj() const {
		return mSadrzaj;
	}
	std::string kategorije() const;

};

#endif