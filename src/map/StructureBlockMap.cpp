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

#include <libnbtplusplus/include/tag_array.h>
#include "libnbtplusplus/include/tag_string.h"
#include "libnbtplusplus/include/tag_primitive.h"
#include <iostream>
#include "StructureBlockMap.hpp"
#include "value.h"
#include "tag_compound.h"
#include "tag_list.h"

InGameOperation::StructureBlockMap::CompoundTagType &InGameOperation::StructureBlockMap::getBlock(int x, int y, int z) {
	auto &target_block = blocks[x][y][z];
	return target_block;
//	std::stringstream ss;
//	ss << "Block not found at: ("
//	   << x << ", " << y << ", " << z << ")";
//	throw std::runtime_error(ss.str());
}

void InGameOperation::StructureBlockMap::load() {
	nbt::tag_string &author_str = root[TagNameStandard::AUTHOR].as<nbt::tag_string>();
	this->author = author_str.get();

	this->DataVersion = (int32_t) root[TagNameStandard::DATA_VERSION];

	nbt::tag_list &block_list = root[TagNameStandard::BLOCKS].as<nbt::tag_list>();
	nbt::tag_list &entity_list = root[TagNameStandard::ENTITIES].as<nbt::tag_list>();
	nbt::tag_list &palette_list = root[TagNameStandard::PALETTE].as<nbt::tag_list>();
	nbt::tag_list &size = root[TagNameStandard::SIZE].as<nbt::tag_list>();
	this->size = {(int32_t) size[0], (int32_t) size[1], (int32_t) size[2]};

	for (auto &i : block_list) {
		//Get the block
		nbt::tag_compound &block = i.as<nbt::tag_compound>();

		//Get the block's position
		nbt::tag_list &pos_arr = block[TagNameStandard::POS].as<nbt::tag_list>();

//		//Get the state of the block
//		auto stateInt = (int32_t)block[TagNameStandard::STATE];
//
//		//Set extra info(nbt)
//		nbt::tag_compound& targ_block_nbt = palette_list[stateInt].as<nbt::tag_compound>();

		//Insert empty map if not exist
		_insertAtMap(this->blocks, (int32_t) pos_arr[0], std::map<int, std::map<int, nbt::tag_compound>>());
		_insertAtMap(this->blocks[(int32_t) pos_arr[0]], (int32_t) pos_arr[1], std::map<int, nbt::tag_compound>());


		std::cout << block << std::endl;

		this->blocks[(int32_t) pos_arr[0]][(int32_t) pos_arr[1]][(int32_t) pos_arr[2]] = block;
	}

	for (auto &i : entity_list) {
		//Get the entity
		nbt::tag_compound &entity = i.as<nbt::tag_compound>();

		//Get the entity's position
		nbt::tag_list &pos_arr = entity[TagNameStandard::POS].as<nbt::tag_list>();

		//Insert empty map if not exist
		_insertAtMap(this->entities, (int32_t) pos_arr[0], std::map<int, std::map<int, nbt::tag_compound>>());
		_insertAtMap(this->entities[(int32_t) pos_arr[0]], (int32_t) pos_arr[1], std::map<int, nbt::tag_compound>());


		std::cout << entity << std::endl;

		this->entities[(int32_t) pos_arr[0]][(int32_t) pos_arr[1]][(int32_t) pos_arr[2]] = entity;
	}

	for (auto &pal : palette_list) {
		std::cout << pal << std::endl;
		palette.push_back(pal.as<nbt::tag_compound>());
	}
}

int InGameOperation::StructureBlockMap::getLength() {
	return size.x;
}

int InGameOperation::StructureBlockMap::getWidth() {
	return size.z;
}

int InGameOperation::StructureBlockMap::getHeight() {
	return size.y;
}

int InGameOperation::StructureBlockMap::getSize() {
	//Calculates total amount of blocks in the map that is not air.
	auto &list = root[TagNameStandard::BLOCKS].as<nbt::tag_list>();
	return list.size();
}

template<typename MapKey, typename MapValue>
void InGameOperation::StructureBlockMap::_insertAtMap(std::map<MapKey, MapValue> &map, MapKey key, MapValue value) {
	typename std::map<MapKey, MapValue>::iterator res = map.find(key);
	if (res == map.end()) {
		map[key] = value;
	}
}

InGameOperation::StructureBlockMap::CompoundTagType &InGameOperation::StructureBlockMap::getPalette(int state) {
	return palette[state];
}

nbt::tag_compound &InGameOperation::StructureBlockMap::getPalette(nbt::tag_compound &fromBlock) {
	return getPalette((int32_t) fromBlock[TagNameStandard::STATE]);
}
