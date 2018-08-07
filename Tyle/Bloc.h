#pragma once
#include <string>

template <typename T>
struct Bloc
{
	int length = 0;
	T * elements = nullptr;
	T & operator[](int idx) { return elements[idx]; }
	const T & operator[](int idx) const { return elements[idx]; }
};

template <typename T, int L>
class BlocStatic
{
	T elements[L];

public:
	BlocStatic(const T & e) { reset(e); }
	BlocStatic(const BlocStatic & b) { memcpy(elements, b.elements, sizeof(elements)); }
	~BlocStatic() = default;

	T & operator[](int idx) { return elements[idx]; }
	const T & operator[](int idx) const { return elements[idx]; }

	void reset(const T & e) { for (T & t : elements) t = e; }

	BlocStatic & operator+=(const BlocStatic & b) { for (int i = 0; i < L; i++) elements[i] += b.elements[i]; return *this; }
	BlocStatic & operator=(const BlocStatic & b) { memcpy(elements, b.elements, sizeof(elements)); return *this; }

	const T max() const {
		T m = elements[0];
		for (int i = 1; i < L; i++)
			if (m < elements[i])
				m = elements[i];
		return m;
	}
};

template <typename T, int L>
class BlocStaticSorted
{
	int _length = 0;
	T elements[L];

public:
	BlocStaticSorted() = default;
	~BlocStaticSorted() = default;

	int length() const { return _length; }
	void cleanse() { _length = 0; }
	const T & operator[](int idx) const { return elements[idx]; }
	
	// return {E i / elements[i] == e}
	bool find(const T & e) const {
		int min = 0;
		int max = _length;

		while (max - min > 1) {
			int mid = (max + min) / 2;
			if (elements[mid] < e)
				min = mid;
			else
				max = mid;
		}

		return min < _length && elements[min] == e;
	}

	void insert(const T & e) {
		if (find(e))
			return;

		auto i = _length - 1;
		for (; i >= 0 && elements[i] > e; i--)
			elements[i + 1] = elements[i];
		elements[i + 1] = e;

		_length++;
	}

};


