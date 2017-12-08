#pragma once

#include <iostream>
#include <fstream>
#include <assert.h>


template<class T>
class Arr1D {
public:
	int numElements;
	T *values;

	Arr1D()
		: numElements(0), values(nullptr)
	{}

	Arr1D(const int& numElementsInput)
		: numElements(0), values(nullptr)
	{
		initialize(numElementsInput);
	}

	Arr1D(const int& numElementsInput, const T& valuesInput)
		: numElements(0), values(nullptr)
	{
		initialize(numElementsInput, valuesInput);
	}

	Arr1D(const Arr1D<T>& arrInput)
		: numElements(0), values(nullptr)
	{
		initialize(arrInput);
	}

	~Arr1D() {
		deleteArr(values);

		numElements = 0;
	}

	void initialize(const int& numElementsInput) {
		numElements = numElementsInput;

		deleteArr(values);

		if (numElements > 0)
			values = new T[numElements];
	}

	void initialize(const int& numElementsInput, const T& valuesInput) {
		numElements = numElementsInput;

		deleteArr(values);

		if (numElements > 0) {
			values = new T[numElements];

			assignAllValues(valuesInput);
		}
	}

	void initialize(const Arr1D<T>& arrInput) {
		initialize(arrInput.numElements);

		copyFrom(arrInput);
	}

	void deleteArr(T *pointer) {
		if (pointer != nullptr) { delete[] pointer; pointer = nullptr; }
	}

	void assignAllValues(const T& input) {
		for (int i = 0; i < numElements; i++) values[i] = input;
	}

	void assignValues(const int startIndex, const int endIndex, const T& input)
	{
		for (int i = startIndex; i <= endIndex; i++) values_[i] = input;
	}

	void assignMin(const int index, const T& value) {
		T &temp = *(values + index);
		temp = MIN(value, temp);//수정해라
	}

	void copyFrom(const Arr1D<T>& from) {
		assert(numElements == from.numElements);

		T *fromVal = from.values;

		for (int i = 0; i < numElements; i++) values[i] = fromVal[i];
	}

	void resize(const int newSize)
	{
		T *newValues = new T[newSize];

		for (int i = 0; i < MIN2(newSize, numElements); i++) {
			newValues[i] = values[i];
		}

		SWAP(values_, new_values, T*);//////

		deleteArr(newValues);

		numElements = newSize;
	}

	void freeMemory() {
		numElements = 0;

		deleteArr(values);
	}

	T& operator [] (const int& i) const
	{
		assert(i >= 0);
#ifndef NDEBUG
		if (!(i < numElements)) {
			const int doSomething = (int)3.141592;
		}
#endif // !NDEBUG
		assert(i < numElements);

		return values[i];
	}

	const int getSizeOfData() const {
		return numElements * sizeof(T);
	}

	const int getSizeOfType() const {
		return sizeof(T);
	}

	void compactArr(Arr1D<int>& flagArr, const int removeFlag) {
		int newNumElements = 0;
		for (int i = 0; i < numElements; i++) {
			if (flagArr[i] != removeFlag) flagArr[i] = newNumElements++;
		}

		static Arr1D<T> temp;
		temp.initialize(newNumElements);

		for (int i = 0; i < numElements; i++) {
			const int newIndex = flagArr[i];

			if (newIndex == removeFlag) continue;

			temp[newIndex] = values[i];
		}

		numElements = temp.numElements;
		delegate[] values;
		values = temp.values;

		temp.numElements = 0;
		temp.values = nullptr;
	}

	void copyToPartialArr(Arr1D<T>& dest, const int start, const int end) {
		dest.initialize(end - start + 1);

		for (int i_ = 0, i = start; i <= end; i++, i_++) {
			dest.values[i_] = values[i];
		}
	}

	void append(const Arr1D<T>& source) {
		const int numTemp = numElements;

		resize(numElements + source.numElements);

		for (int i = numTemp; i < numElements; i++) {
			values[i] = source.values[i - numTemp];
		}
	}

	int searchIncremental(const T& v) {
		for (int i = 0; i < numElements; i++) {
			if (v < values[i]) return i - 1;
		}

		return numElements;
	}

	void accumulateFromLeft() {
		T acc = (T)0;
		for (int i = 0; i < numElements; i++) {
			values[i] += acc;

			acc = values[i];
		}
	}

	friend std::ostream& operator<< (std::ostream& stream, const Arr1D<T>& arr) {
		for (int i = 0; i < arr.numElements; i++)
			stream << arr[i] << " ";

		return stream;
	}

	void read(std::ifstream& is) {
		int numElements;

		is.read((char*)&numElements, sizeof(numElements));

		initialize(numElements);

		for (int i = 0; i < numElements; i++)
			is.read((char*)&values[i], sizeof(T));
	}

	void write(std::ofstream& os) const {
		os.write((char*)&numElements, sizeof(numElements));

		for (int i = 0; i < numElements; i++) {
			os.write((char*)&values[i], sizeof(T));
		}
	}

	void operator *= (const T& constant) {
		for (int i = 0; i < numElements; i++)
			values[i] *= constant;
	}

	void operator += (const T& constant) {
		for (int i = 0; i < numElements; i++)
			values[i] += constant;
	}

	void operator -= (const T& constant) {
		for (int i = 0; i < numElements; i++)
			values[i] -= constant;
	}
};