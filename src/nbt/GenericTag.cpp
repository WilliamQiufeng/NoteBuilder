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

namespace NBT {
	template<typename T>
	typename GenericTag<T>::type &GenericTag<T>::get() {
		return value;
	}

	template<typename T>
	std::string GenericTag<T>::getType() {
		return typeid(type).name();
	}

	template<typename T>
	char GenericTag<T>::getArrayPrefix() {
#define IF_TYPE_IS(type) if(typeid(T) == typeid(type))
#define ELSE_IF_TYPE_IS(type) else IF_TYPE_IS(type)

		IF_TYPE_IS(int) {
			return 'I';
		} ELSE_IF_TYPE_IS(long) {
			return 'L';
		} ELSE_IF_TYPE_IS(char) {
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
#undef IF_TYPE_IS
#undef ELSE_IF_TYPE_IS
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

/*
	void replace_all(std::string & s, std::string const & t, std::string const & w) {
		std::string::size_type pos = s.find(t), t_size = t.size(), r_size = w.size();
		while (pos != std::string::npos) { // found
			s.replace(pos, t_size, w);
			pos = s.find(t, pos + r_size);
		}

		*//*————————————————
		版权声明：本文为CSDN博主「CodeArhat」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
		原文链接：https://blog.csdn.net/CodeArhat/article/details/6850536*//*
	}*/

	DEFINE_TEMPLATE_INIT_FOR(GenericTag)

}