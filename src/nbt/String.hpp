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

#ifndef NOTEBUILDER_STRING_HPP
#define NOTEBUILDER_STRING_HPP

#include "Tag.hpp"

namespace NBT {
	class String : public Tag {
	public:
		typedef std::string type;
		type str;

		String(const type &str);

		void replace(std::string &s1, const std::string &s2, const std::string &s3);

		void toString(std::ostringstream &os) override;

		std::string get();
	};
}

#endif //NOTEBUILDER_STRING_HPP
