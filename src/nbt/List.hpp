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

#ifndef NOTEBUILDER_LIST_HPP
#define NOTEBUILDER_LIST_HPP

#include "GenericTag.hpp"

namespace NBT {
	/**
	 * WARNING!!
	 * The template here should be a tag type!
	 * @tparam T
	 */
	class List : public Tag {
	public:
		List(Tag::Types element_type);

		Tag::Types element_type;

		TypeName getElementType();

		TypeName getDynamicType();
		DEFINE_LIST_CLASS_MEMBERS(List)
	};
}

#endif //NOTEBUILDER_LIST_HPP
