//
// Created by Qiufeng54321 on 2019-09-02.
// Copyright (C) 2019  Qiufeng54321
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include "Array.hpp"

namespace NBT {
	template<typename T>
	void Array<T>::insert(std::size_t index, typename Array<T>::generic_type *val) {
		this->value[index] = val;
	}

	template<typename T>
	typename Array<T>::generic_type *Array<T>::get(std::size_t index) {
		return this->value[index];
	}

	template<typename T>
	void Array<T>::add(typename Array<T>::generic_type *val) {
		this->value.push_back(val);
	}

	template<typename T>
	TypeName Array<T>::getType() {
		if (typeid(T) == typeid(int))
			return {INT_ARRAY};
		else if (typeid(T) == typeid(long))
			return {LONG_ARRAY};
		else if (typeid(T) == typeid(unsigned char))
			return {BYTE_ARRAY};
		else
			throw std::runtime_error("Not recognized array type");
	}

	template<typename T>
	void Array<T>::toString(std::ostringstream &os) {
		os << "[";
		os << generic_type::getArrayPrefix() << ";";
		auto vect = (type) this->value;
		for (typename type::iterator iter = vect.begin(); iter != vect.end(); iter++) {
			(*iter)->toString(os);
			if (iter + 1 != vect.end())
				os << ",";
		}
		os << "]";
	}

	template<typename T>
	Array<T>::Array() = default;

	DEFINE_TEMPLATE_INIT_FOR(Array)
}