#include "vect_Header.h"
#include <cmath>


std::allocator<double> Vect::alloc;

Vect::Vect(size_t n, double v, std::string const &vec_name)
	:ime(vec_name), mdata(nullptr), mfirst_free(nullptr), mend(nullptr)
{
	std::cerr << "Ctor" << std::endl;
	if (n > 0) {
		mdata = alloc.allocate(n); //alocirao mjesta za n doubleova
		for (size_t i = 0; i < n; ++i) {
			alloc.construct(mdata + i, v); //konstruira object in allocated storage
		}
		mfirst_free = mend = mdata + n;
	}
	
}
// CCtor
Vect::Vect(const Vect &v) { 
	std::cout << "CTOR\n";
	this->ime = v.ime;
	this->mdata = alloc.allocate(v.capacity());

	for (size_t i = 0; i < v.size(); ++i) {
		alloc.construct(mdata + i, v.mdata[i]);
	}
	this->mend = mdata + v.capacity();
	this->mfirst_free = mdata + v.size();
}

//MCtor
Vect::Vect(Vect &&v) noexcept
	:ime(std::move(v.ime)), mfirst_free(v.mfirst_free), mdata(v.mdata),
	mend(v.mend)
{
	v.mdata = v.mend = v.mfirst_free = nullptr;
}

//OP(assigment operator)
Vect& Vect::operator=(const Vect& v) {
	std::cout << "\nOP!\n";
	if (this != &v) {
		if (v.capacity() != this->capacity()) { //storage cannot be reused
			free();
			this->ime = v.ime;
			this->mdata = alloc.allocate(v.capacity());
			this->mend = mdata + v.capacity();
			this->mfirst_free = mdata + v.size();
		}
		for (size_t i = 0; i < v.size(); ++i) {
			//*(this->mdata + i) = mdata[i];
			alloc.construct(mdata + i, v.mdata[i]);
		}
		
	}
	return *this;
}

Vect& Vect::operator=(Vect &&v) noexcept {
	std::cout << "MOP!\n";
	if (this != &v) {
		free();
		ime = std::move(v.ime);
		mdata = std::exchange(v.mdata, nullptr);
		mfirst_free = std::exchange(v.mfirst_free, nullptr);
		mend =	std::exchange(v.mend, nullptr);
	}
	return *this;
}


void Vect::print(std::ostream& out) const {
	out << ime << ": (" << size() << "," << capacity() << ") ";
	for (size_t i = 0; i < size(); ++i) {
		out << mdata[i];
		if (i + 1 < size()) {
			out << ",";
		}
	}
}

void Vect::free() {
	
	for (size_t j = 0; j < this->size(); ++j) { //obrisi stari
		alloc.destroy(this->mdata + j);
	}
	alloc.deallocate(this->mdata, this->capacity());

}

void Vect::reallocate() {

	int resize = this->size() ? 2 * this->size() : 1;
	double *tmpTraverse = alloc.allocate(resize);
	double *tmpStart = tmpTraverse;

	for (size_t i = 0; i < this->size(); ++i) {
		alloc.construct(tmpTraverse++, mdata[i]);
	}
	free();
	this->mdata = tmpStart;
	this->mend = tmpStart + resize;
	this->mfirst_free = tmpTraverse;


}
void Vect::push_back(double x) {
	std::cout << "push bek\n";
	if (!has_space()) {
		std::cout << "Ulazim u realoc\n";
		reallocate();	
	}
	alloc.construct(mfirst_free++, x);
}

double Vect::norm2() const {
	double res = 0;
	for (size_t i = 0; i < this->size(); ++i) {
		res += pow(*(this->mdata +i), 2);
	}
	return sqrt(pow(res, 2));
}

Vect& Vect::scale(double alpha) {
	for (size_t i = 0; i != this->size(); ++i) {
		mdata[i] *= alpha;
	}
	return *this;
}

