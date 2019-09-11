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

#ifndef NOTEBUILDER_COMPOUNDTAG_HPP
#define NOTEBUILDER_COMPOUNDTAG_HPP

#include "Tag.hpp"

namespace NBT {
	class CompoundTag : public Tag {
	public:
		typedef std::map<std::string, Tag *> type;
		type children;

		void set(std::string key, Tag *val);

		Tag *get(std::string key);

		type get();

		static TypeName getType();

		void toString(std::ostringstream &os) override;
	};
}

#endif //NOTEBUILDER_COMPOUNDTAG_HPP
