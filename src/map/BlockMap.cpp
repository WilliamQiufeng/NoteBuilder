//
// Created by Qiufeng54321 on 2019-09-03.
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

#include "BlockMap.hpp"
#include "StructureBlockMap.hpp"

namespace InGameOperation {
	std::string
			TagNameStandard::LENGTH = "length",
			TagNameStandard::HEIGHT = "height",
			TagNameStandard::WIDTH = "width",
			TagNameStandard::BLOCKS = "blocks",
			TagNameStandard::BLOCK = "block",
			TagNameStandard::ENTITIES = "entities",
			TagNameStandard::DATA = "data",
			TagNameStandard::AUTHOR = "author",
			TagNameStandard::SIZE = "size",
			TagNameStandard::POS = "pos",
			TagNameStandard::STATE = "state",
			TagNameStandard::PALETTE = "palette",
			TagNameStandard::DATA_VERSION = "DataVersion";

	template<typename Root>
	StructureBlockMap BlockMap<Root>::fromStructure(std::string path) {
		BlockMap map;
		return map;
	}

	template<typename Root>
	typename BlockMap<Root>::CompoundTagType &BlockMap<Root>::getBlock(int x, int y, int z) {
		return nullptr;
	}
}