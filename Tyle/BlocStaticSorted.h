#pragma once

namespace kar {
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
}
