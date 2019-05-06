#pragma once
#ifndef __VECT_REALLOC_H_IS_INCLUDDED__
#define __VECT_REALLOC_H_IS_INCLUDDED__

#include <iostream>
#include <string>

//Klasa Vect implementira vektor dinamicki alociranih double-ova kojima
//je pridruzen jedan string (ime varijable)
//Klasa vrsi realokaciju kada vise nema dovoljno mjesta za novi element
//implementira metodu push_back, Implemenetirana je potpuna kontrola kopiranja
//te neke uobicajene metode

class Vect {

private:

	double *mdata; //pokazivac na prvi element;
	double *mfirst_free; //pokazivac na prvo slobodno mjesto
	double *mend; //pokazivac na kraj alociranog prostora(jedno iza posljednjeg)

				  //vraca true ako imamo prostora za jos jedan element
	bool has_space() const {
		return (size() == capacity()) ? false : true;
	}

	//oslobodi zauzet prostor(pomocu alokatora)
	void free();

	//realociraj na novu lokaciju, povecaj dimenziju vektora 2 puta
	//ako je vektor prazan, dodaj jedan element
	void reallocate();

	//alokator ne mora imati pristup varijablama clanicama klsae pa ga cinimo
	//statickim.
	static std::allocator<double> alloc;

public:
	//konstruktor i delegirajuce verzije
	Vect(size_t n, double v, std::string const &ime);
	Vect(size_t n, double v) : Vect(n, v, "") {}
	explicit Vect(size_t n) : Vect(n, 0.0, "") {}
	explicit Vect(std::string const &ime) : Vect(0, 0.0, ime) {
		printf("Usao u konstruktor!\n");
	}

	//kontrola kopiranja
	Vect(const Vect &v); //CCtor
	Vect(Vect &&v) noexcept; //MCTor
	
	Vect& operator=(const Vect& v);  //OP
	Vect& operator=(Vect &&v) noexcept; //MOP

	~Vect() {
		std::cout << "Dtor\n";
		free();
	}

	//dohvat elementa
	double const& operator[](size_t i) const {
		return mdata[i];
	}
	double& operator[](size_t i) {
		return mdata[i];
	}

	//push_back kao u std::vector. Eventualno izaziva realokaciju citavog vektora
	void push_back(double);

	//utility rutine
	double norm2() const;
	Vect& scale(double aplha);
	void print(std::ostream & out) const;

	std::string ime;//ime vektora je javna varijabla

	//info
	size_t size() const {
		return mfirst_free - mdata;
	}
	size_t capacity() const {
		return mend - mdata;
	}




};
#endif