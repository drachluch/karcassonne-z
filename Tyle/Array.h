#pragma once


template <typename T, int L>
struct Array {
private:
	T ts[L];
	int _length = 0;
public:
	Array() = default;
	~Array() = default;
	
	int length() const { return _length; }

	void addLength(int i) {
		if (_length + i >= 0)
			_length += i;
		else
			throw "Array (addLength) : length can't be negativ.";
	}
	
	T & operator[](int i)  {
		if (i < 0 || i >= _length)
			throw "Array : out of bound d";
		return ts[i];
	}

	const T & operator[](int i) const  {
		if (i < 0 || i >= _length)
			throw "Array : out of bound e";
		return ts[i];
	}
	
	T & last()  {
		if (_length <= 0)
			throw "Array : empty, no last element";
		return ts[_length - 1];
	}
	
	const T & last() const {
		if (_length <= 0)
			throw "Array : empty, no last element";
		return ts[_length - 1];
	}

	void push(const T & e) {
		_length++;
		last() = e;
	}

	const T & pop() {
		if (_length <= 0)
			throw "Array : empty, can't pop";
		_length--;
		return ts[_length];
	}
};


