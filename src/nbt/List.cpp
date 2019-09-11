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

#include <utility>

namespace NBT {
	void List::insert(std::size_t index, generic_type *val) {
		this->value[index] = val;
	}

	typename List::generic_type *List::get(std::size_t index) {
		return this->value[index];
	}

	void List::add(generic_type *val) {
		this->value.push_back(val);
	}

	TypeName List::getType() {
		return {LIST};
	}

	void List::toString(std::ostringstream &os) {
		os << "[";
		auto vect = (type) this->value;
		for (auto iter = vect.begin(); iter != vect.end(); iter++) {
			(*iter)->toString(os);
			if (iter + 1 != vect.end())
				os << ",";
		}
		os << "]";
	}

	TypeName List::getElementType() {
		//T::getType();
		return {element_type};
	}

	TypeName List::getDynamicType() {
		return {LIST, {getElementType()}};
	}

	List::List(Tag::Types element_type) {
		this->element_type = element_type;
	};

	//DEFINE_TEMPLATE_INIT_FOR(List)
}