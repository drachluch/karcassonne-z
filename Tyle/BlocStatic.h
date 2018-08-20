#pragma once
#include <string>

namespace kar {
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
		BlocStatic & operator-=(const BlocStatic & b) { for (int i = 0; i < L; i++) elements[i] -= b.elements[i]; return *this; }
		BlocStatic & operator=(const BlocStatic & b) { memcpy(elements, b.elements, sizeof(elements)); return *this; }

		auto max() const {
			T m = elements[0];
			for (int i = 1; i < L; i++)
				if (m < elements[i])
					m = elements[i];
			return m;
		}

		auto length() const { return L; }
	};
	

}
