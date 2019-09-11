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

/**
 * This file introduces an abstract class that is used to turn other nbt classes into storage using classes under 'nbt'
 * 		folder.
 */

#ifndef NOTEBUILDER_NBTSTANDARDIZER_HPP
#define NOTEBUILDER_NBTSTANDARDIZER_HPP

#include "nbt/CompoundTag.hpp"

namespace NBT::Converter {
	template<typename FromNBTRootType, typename ToNBTTRootType>
	class Convert {
	public:
		typedef FromNBTRootType from_type;
		typedef ToNBTTRootType to_type;

		virtual to_type convert(from_type from) = 0;
	};
//	template<typename FromNBTRootType> class Convert<FromNBTRootType, CompoundTag>;
}

#endif //NOTEBUILDER_NBTSTANDARDIZER_HPP
