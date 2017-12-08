#pragma once

#include "VectorND.h"

template<class T>
class Matrix {
public:
	int rows;
	int cols;
	T *values;

	Matrix()
		: values(nullptr), rows(0), cols(0)
	{}

	void initialize(const int& m, const int& n, const bool init = true);

	void multiply(const VectorND<T>& vector, VectorND<T>& result) const;
	void multiplyTransposed(const VectorND<T>& vector, VectorND<T>& result) const;

	int get1DIndex(const int& row, const int& col)const;
	T& getValue(const int& row, const int& col) const;

	void deleteSafe(T *pointer);

	void cout();
};