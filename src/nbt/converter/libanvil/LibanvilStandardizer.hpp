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

#ifndef NOTEBUILDER_LIBANVILSTANDARDIZER_HPP
#define NOTEBUILDER_LIBANVILSTANDARDIZER_HPP

#include "nbt/converter/NBTStandardizer.hpp"
#include "nbt/IncludeAllNBT.hpp"
#include "libanvil/include/tag/compound_tag.hpp"
#include "libanvil/include/tag/list_tag.hpp"
#include "libanvil/include/tag/int_array_tag.hpp"
#include "libanvil/include/tag/long_array_tag.hpp"
#include "libanvil/include/tag/byte_array_tag.hpp"

namespace NBT::Converter {
	template
	class Convert<compound_tag, CompoundTag>;

	class LibanvilStandardizer : public Convert<compound_tag, CompoundTag> {
	public:
		to_type convert(from_type from) override;

		template<typename type>
		List convert(list_tag list);

		Array<int> convert(int_array_tag arr);

		Array<long> convert(long_array_tag arr);

		Array<unsigned char> convert(byte_array_tag arr);


	};
}

#endif //NOTEBUILDER_LIBANVILSTANDARDIZER_HPP
