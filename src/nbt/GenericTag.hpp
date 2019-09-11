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

#ifndef NOTEBUILDER_GENERICTAG_HPP
#define NOTEBUILDER_GENERICTAG_HPP

#include "Tag.hpp"

namespace NBT {
	template<typename T>
	class GenericTag : public Tag {
	public:
		typedef T type;
		T value;

		explicit GenericTag(type value);

		type &get();

		static TypeName getType();

		static char getArrayPrefix();

		void toString(std::ostringstream &os) override;


//		void replace_all(std::string & s, std::string const & t, std::string const & w);
	};


}

#endif //NOTEBUILDER_GENERICTAG_HPP
