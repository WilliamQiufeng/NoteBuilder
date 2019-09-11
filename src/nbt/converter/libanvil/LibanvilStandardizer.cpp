//
// Created by Qiufeng54321 on 2019-09-10.
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

#include "LibanvilStandardizer.hpp"

namespace NBT::Converter {
	CompoundTag LibanvilStandardizer::convert(compound_tag from) {

		return Convert<compound_tag, CompoundTag>::to_type();
	}

	template<typename type>
	List LibanvilStandardizer::convert(list_tag list) {
		switch (list.type) {
			case list_tag::INT:
				break;
			case list_tag::LONG:
				break;
			case list_tag::SHORT:
				break;
			case list_tag::FLOAT:
				break;
			case list_tag::DOUBLE:
				break;
			case list_tag::BYTE:
				break;
			case list_tag::INT_ARRAY:
				break;
			case list_tag::LONG_ARRAY:
				break;
			case list_tag::BYTE_ARRAY:
				break;
			case list_tag::LIST:

				break;
			case list_tag::COMPOUND:
				break;
			case list_tag::STRING:
				break;
		}
		return List(Tag::Types::BASIC);
	}

	Array<int> LibanvilStandardizer::convert(int_array_tag arr) {
		return Array<int>();
	}

	Array<long> LibanvilStandardizer::convert(long_array_tag arr) {
		return Array<long>();
	}

	Array<unsigned char> LibanvilStandardizer::convert(byte_array_tag arr) {
		return Array<unsigned char>();
	}
}


