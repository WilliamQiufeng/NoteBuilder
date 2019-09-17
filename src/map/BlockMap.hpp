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

/**
 * Block Map Documentation:
 *
 * BlockMap is an abstract class which stores blocks in an area.
 * 'template<typename Root> typename BlockMap<Root>::CompoundTagType* root' is the root tag which contains all block
 * 		data.
 * 	Here is the standard about the format of the data storage, which is below:
 * 		The format basically looks like this:
 * 			Compound 'root' {
 * 				int 'length' 	//length on x-axis
 * 				int 'width'		//width  on z-axis
 * 				int 'height'	//height on y-axis
 * 				List<List<List<int>>> 'blocks' [ // x
 * 					List<List<Compound>> [ // y
 * 						List<Compound> [ // z
 * 							Compound {
 * 								String 'block'
 * 								Compound 'data' //NBT of the block
 * 							}
 * 							...
 * 						]
 * 						...
 * 					]
 * 					...
 * 				]
 * 			}
 * 		The 'blocks' tag is a 3-D array which stores blocks. To get the block in a given relative position (Say (x,y,z))
 * 			, The result will be 'blocks'[x][y][z].
 * 		NOTE: The position of the tags in the root should be ordered.
 *
 */

#ifndef NOTEBUILDER_BLOCKMAP_HPP
#define NOTEBUILDER_BLOCKMAP_HPP

#include "Header.hpp"

namespace InGameOperation {
	class TagNameStandard {
	public:
		static std::string
				LENGTH,
				HEIGHT,
				WIDTH,
				BLOCKS,
				BLOCK,
				ENTITIES,
				DATA,
				AUTHOR,
				SIZE,
				POS,
				NBT,
				STATE,
				PALETTE,
				NAME,
				PROPERTIES,
				DATA_VERSION;
	};

	enum class RootTagIndex : unsigned int {
		LENGTH = 0,
		WIDTH = 1,
		HEIGHT = 2,
		BLOCKS = 3,
		BLOCK = 0,
		DATA = 1
	};

	template<typename Root>
	class BlockMap {
	public:
		typedef Root CompoundTagType;
		CompoundTagType root;


		static StructureBlockMap fromStructure(std::string path);

		virtual void load() = 0;

		virtual CompoundTagType &getBlock(int x, int y, int z) = 0;

		virtual int getLength() = 0, getWidth() = 0, getHeight() = 0, getSize() = 0;
	};


}

#endif //NOTEBUILDER_BLOCKMAP_HPP
