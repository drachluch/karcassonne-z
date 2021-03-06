#pragma once
#include <string>

namespace kar {

	template <typename T, int L>
	struct Array {
		using Element = T;
	private:
		T ts[L];
		int _length = 0;
	public:
		Array() = default;
		~Array() = default;

		Array & operator=(const Array & arr) {
			_length = arr._length;
			memcpy(ts, arr.ts, sizeof(ts));
			return *this;
		}

		int length() const { return _length; }

		void addLength(int i) {
			if (_length + i >= 0)
				_length += i;
			else
				throw "Array (addLength) : length can't be negativ.";
		}

		T & operator[](int i) {
			if (i < 0 || i >= _length || i >= L)
				throw "Array : out of bound d";
			return ts[i];
		}

		const T & operator[](int i) const {
			if (i < 0 || i >= _length)
				throw "Array : out of bound e";
			return ts[i];
		}

		T & last() {
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

		void cleanse() {
			_length = 0;
		}

		int getIndex(const T * p) const {
			return (int)(p - ts);
		}

		int indexOf(const T & e) const {
			for (auto i = 0; i < _length; i++)
				if (ts[i] == e)
					return i;
			return -1;
		}

		bool find(const T & e) const {
			for (auto i = 0; i < _length; i++)
				if (ts[i] == e)
					return true;
			return false;
		}
	};

}
