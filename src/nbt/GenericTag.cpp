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

#include "Header.hpp"
#include "GenericTag.hpp"

#define IF_TYPE_IS(type) if(typeid(T) == typeid(type))
#define ELSE_IF_TYPE_IS(type) else IF_TYPE_IS(type)

namespace NBT {
	template<typename T>
	typename GenericTag<T>::type &GenericTag<T>::get() {
		return value;
	}

	template<typename T>
	TypeName GenericTag<T>::getType() {
		IF_TYPE_IS(int) {
			return {INT};
		} ELSE_IF_TYPE_IS(short) {
			return {SHORT};
		} ELSE_IF_TYPE_IS(long) {
			return {LONG};
		} ELSE_IF_TYPE_IS(unsigned char) {
			return {BYTE};
		} ELSE_IF_TYPE_IS(float) {
			return {FLOAT};
		} ELSE_IF_TYPE_IS(double) {
			return {DOUBLE};
		}
	}

	template<typename T>
	char GenericTag<T>::getArrayPrefix() {

		IF_TYPE_IS(int) {
			return 'I';
		} ELSE_IF_TYPE_IS(long) {
			return 'L';
		} ELSE_IF_TYPE_IS(unsigned char) {
			return 'B';
		} ELSE_IF_TYPE_IS(double) {
			return 'D';
		} ELSE_IF_TYPE_IS(float) {
			return 'F';
		} ELSE_IF_TYPE_IS(short) {
			return 'S';
		} else {
			throw std::runtime_error("Generic Array Element Type not supported by minecraft.");
		}
	}

	template<typename T>
	GenericTag<T>::GenericTag(type value):value(value) {}

	template<typename T>
	void GenericTag<T>::toString(std::ostringstream &os) {
		os << value;
		if (typeid(T) != typeid(int)) {
			os << getArrayPrefix();
		}
	}


	DEFINE_TEMPLATE_INIT_FOR(GenericTag)

}
#undef IF_TYPE_IS
#undef ELSE_IF_TYPE_IS