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

#include "List.hpp"

namespace NBT {
	template<typename T>
	void List<T>::insert(std::size_t index, generic_type *val) {
		this->value[index] = val;
	}

	template<typename T>
	typename List<T>::generic_type *List<T>::get(std::size_t index) {
		return this->value[index];
	}

	template<typename T>
	void List<T>::add(generic_type *val) {
		this->value.push_back(val);
	}

	template<typename T>
	std::string List<T>::getType() {
		return GenericTag<T>::getType() + "L";
	}

	template<typename T>
	void List<T>::toString(std::ostringstream &os) {
		os << "[";
		auto vect = (type) this->value;
		for (typename type::iterator iter = vect.begin(); iter != vect.end(); iter++) {
			(*iter)->toString(os);
			if (iter + 1 != vect.end())
				os << ",";
		}
		os << "]";
	}

	template<typename T>
	List<T>::List() {}

	DEFINE_TEMPLATE_INIT_FOR(List)
}