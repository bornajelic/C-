#include "vect_Header.h"
#include <math.h>

Vect foo(Vect x) {
	x.scale(2.0);
	return x;
}


int main() {
	using std::cout;
	using std::endl;

	Vect a("a");

	cout << "prazan vektor "; 
	a.print(cout);
	cout << endl;

	a.push_back(1.0);
	cout << "Nakon 1.push_back: "; a.print(cout); cout << endl; //ne radi
	a.push_back(2.0);
	cout << "Nakon 2.push_back: "; a.print(cout); cout << endl;
	a.push_back(3.0);
	cout << "Nakon 3.push_back: "; a.print(cout); cout << endl;
	a.push_back(4.0);
	cout << "Nakon 4.push_back: "; a.print(cout); cout << endl;
	a.push_back(5.0);
	cout << "Nakon 5.push_back: "; a.print(cout); cout << endl;

	Vect b(a);
	b.ime = "b";
	b.print(cout);
	cout << " = "; a.print(cout); cout << endl;

	Vect c(6, 11.0, "c");
	c.print(cout); cout << endl;

	b = c;
	b.print(cout); cout << "  = "; c.print(cout); cout << endl;

	c = std::move(a);
	c.print(cout); cout << " = "; a.print(cout); cout << endl; // a opljackan

	std::cout << "Vect d = foo(c)\n";
	Vect d = foo(c);

	std::cout << "Vect d = foo(b)\n";
	d = foo(b);
	
	return 0;
}