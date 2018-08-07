#pragma once
#include "Bloc.h"

template <typename T, int L>
class NeighborStack
{
	
	int _length = 0;
	T * elements = nullptr;

public:
	NeighborStack() { elements = new T[L]; }
	~NeighborStack() { delete[] elements; }

	int length() const { return _length; }

	// blocLength > 0
	Bloc<T> getSome(int blocLength) {
		Bloc<T> bloc{ blocLength, elements + _length };
		_length += blocLength;
		return bloc;
	}

	//
	void freeSome(int blocLength) {
		_length -= blocLength;
	}


};

