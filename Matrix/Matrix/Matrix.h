#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H
#include <initializer_list>
#include <array>
#include <stdexcept>
//Matrix with static dimensions, realloc. not possible

template <int rows, int cols>
class Matrix {

private:
	//remembering elements written by columns
	std::array<double, rows*cols> mData;

public:

	Matrix() = default;
	Matrix(std::initializer_list<std::initializer_list<double>>);
	Matrix(double);
	Matrix(const Matrix<rows, cols> & orig) = default;

	//index operators
	double & operator()(unsigned int i, unsigned int j) {
		return this->mData[i*cols + j];
	}
	double const & operator() (unsigned int i, unsigned int j) const {
		return this->mData[i*cols + j];
	}
	
	// +=,-= operators
	Matrix& operator+=(Matrix<rows, cols> &);
	Matrix& operator-=(Matrix<rows, cols> &);
	Matrix& operator=(const Matrix &);

	explicit
		operator bool() const {
		for (int i = 0; i < rows*cols; ++i) {
			if (this->mData[i] != 0) {
				return 0;
			}
			else
				return 1;
		}
	}


	void zero() {
		for (unsigned int i = 0; i < mData.size(); ++i) {
			mData[i] = 0;
		}
	}

	void eye() {
		for (unsigned int i = 0; i < mData.size(); ++i) {
			mData[i] = 1;
		}
	}
};


//=================CONSTRUCTORS====================//

template<int rows, int cols>
Matrix<rows, cols>::Matrix(double d) {
	for (size_t i = 0; i < mData.size(); ++i) {
		this->mData[i] = d;
	}
}

template<int rows, int cols>
Matrix<rows, cols>::Matrix(std::initializer_list<std::initializer_list<double>> list) {
	int counter = 0;
	for (auto i : list) {
		for (auto j : i) {
			this->mData[counter++] = j;
		}
	}
}


//=================END OF CONSTRUCTORS====================//

//=================OPERATORS=============================//

//ostream operator
template<int rows, int cols>
std::ostream& operator<<(std::ostream &cout, Matrix<rows, cols> &m) {
	for (int i = 0; i < rows; ++i) {
		cout << "| ";
		for (int j = 0; j < cols; ++j) {
			
			cout<< m(i, j) << " " ;
			if (j == cols - 1) {
				cout << "|";
			}
			else {
				cout << " ";
			}

		}
		cout << "\n";
	}
	cout << "\n";
	return cout;
}
template <int rows, int cols>
Matrix<rows, cols>& Matrix<rows, cols>::operator=(const Matrix<rows, cols> &other) {
	if (this != &other) {
		this->mData = other.mData;
	}
	return *this;
}

// + operator
template <int rows, int cols>
Matrix<rows, cols> operator+(Matrix<rows, cols> &a, Matrix<rows, cols> &b) {
	Matrix<rows, cols> m(0);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			m(i, j) = a(i, j) + b(i, j);
		}
	}
	return m;
}

// - operator
template <int rows, int cols>
Matrix<rows, cols> operator-(Matrix<rows, cols> &a, Matrix<rows, cols> &b) {
	Matrix<rows, cols> m(0);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			m(i, j) = a(i, j) - b(i, j);
		}
	}
	return m;
}

// += operator
template <int rows, int cols>
Matrix<rows, cols>& Matrix<rows, cols>:: operator+=(Matrix<rows, cols> &a) {

	for (int i = 0; i < rows*cols; ++i) {
		this->mData[i] += a.mData[i];
	}
	return *this;
}
template <int rows, int cols>
Matrix<rows, cols>& Matrix<rows, cols>:: operator-=(Matrix<rows, cols> &a) {

	for (int i = 0; i < rows*cols; ++i) {
		this->mData[i] -= a.mData[i];
	}
	return *this;
}



 //* operator /multiplying scalar from left
template <int rows, int cols>
Matrix<rows, cols> operator*(const double &d, Matrix<rows, cols> &other) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			other(i, j) *= d;
		}
	}
	return other;
}

// *operator /multiplying scalar from right
template <int rows, int cols>
Matrix<rows, cols> operator*(Matrix<rows, cols> &other, const double &d) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			other(i, j) *= d;
		}
	}
	return other;
}

// operator * // matrix * matrix

template <int rows, int cols, int tmp>
Matrix<rows, cols> operator*( Matrix<rows, tmp> &c,  Matrix<tmp, cols> &d) {
	Matrix <rows, cols> m(0);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			for (int k = 0; k < tmp; ++k) {
				m(i, j) += c(i, k) * d(k, j);
			}
		}
	}
	return m;
}


#endif
