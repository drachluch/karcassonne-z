#pragma once

namespace kar {
	template <typename T>
	struct Bloc
	{
		int length = 0;
		T * elements = nullptr;
		T & operator[](int idx) { return elements[idx]; }
		const T & operator[](int idx) const { return elements[idx]; }
	};

}
