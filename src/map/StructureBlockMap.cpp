//
// Created by Qiufeng54321 on 2019-09-05.
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

#include "StructureBlockMap.hpp"
#include "value.h"
#include "tag_compound.h"
#include "tag_list.h"

InGameOperation::StructureBlockMap::CompoundTagType &InGameOperation::StructureBlockMap::getBlock(int x, int y, int z) {

	nbt::value listTag = static_cast<nbt::value &&>(root.at(TagNameStandard::BLOCKS));
	nbt::value x_list = static_cast<nbt::value &&>(listTag.as<nbt::tag_list>()[x]);
	nbt::value y_list = static_cast<nbt::value &&>(x_list.as<nbt::tag_list>()[y]);
	nbt::value z_ = static_cast<nbt::value &&>(y_list.as<nbt::tag_list>()[z]);
	auto &target_block = z_.as<nbt::tag_compound>();
	return target_block;
//	std::stringstream ss;
//	ss << "Block not found at: ("
//	   << x << ", " << y << ", " << z << ")";
//	throw std::runtime_error(ss.str());
}

void InGameOperation::StructureBlockMap::load() {

}

int InGameOperation::StructureBlockMap::getLength() {
	nbt::value len = static_cast<nbt::value &&>(root.at(TagNameStandard::LENGTH));
	return (int) len;
}

int InGameOperation::StructureBlockMap::getWidth() {
	nbt::value len = static_cast<nbt::value &&>(root.at(TagNameStandard::WIDTH));
	return (int) len;
}

int InGameOperation::StructureBlockMap::getHeight() {
	nbt::value len = static_cast<nbt::value &&>(root.at(TagNameStandard::HEIGHT));
	return (int) len;
}
