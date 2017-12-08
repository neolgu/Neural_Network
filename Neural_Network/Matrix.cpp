#include <assert.h>
#include "Matrix.h"

template<class T>
void Matrix<T>::initialize(const int& m, const int& n, const bool init = true) {
	const int numAllOld = rows * cols;

	rows = m;
	cols = n;

	deleteSafe(values);

	const int numAll = rows * cols;

	if (numAll != numAllOld) {
		assert((double)rows * (double)cols <= (double)INT_MAX);

		values = new T[numAll];

		if (init == true)
			for (int i = 0; i < numAll; i++)
				values[i] = (T)0;
	}
}

template<class T>
void Matrix<T>::deleteSafe(T *pointer) {
	if (pointer != nullptr) { delete[] pointer; pointer = nullptr; }
}

template<class T>
void Matrix<T>::multiply(const VectorND<T>& vector, VectorND<T>& result) const {
	assert(rows <= result.numDimension);
	assert(cols <= vector.numDimension);

	for (int r = 0; r < rows; r++) {
		result.values[r] = (T)0;

		int i = r * cols;
		T temp;

		for (int c = 0; c < cols; c++, i++) {
			temp = values[i];
			temp *= vector.values[c];

			result.values[r] += temp;
		}
	}
}

template<class T>
void Matrix<T>::multiplyTransposed(const VectorND<T>& vector, VectorND<T>& result) const {
	assert(rows <= vector.numDimension);
	assert(cols <= result.numDimension);

	for (int c = 0; c < cols; c++) {
		result.values[c] = (T)0;

		for (int r = 0, i = c; r < rows; r++, i += cols) {
			result.values[c] += values[i] * vector.values[r];
		}
	}
}

template<class T>
void Matrix<T>::cout() {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			std::cout << getValue(r, c) << " ";
		}
		std::cout << std::endl;
	}
}

template<class T>
int Matrix<T>::get1DIndex(const int& row, const int& col) const {
	assert(row >= 0);
	assert(col >= 0);
	assert(row < rows);
	assert(row < cols);

	return col + row * cols;
}

template<class T>
T& Matrix<T>::getValue(const int& row, const int& col) const{
	return values[get1DIndex(row, col)];
}

template class Matrix<float>;
template class Matrix<double>;