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

#include <iostream>
#include <libnbtplusplus/include/tag_string.h>
#include "FallingBlockGenerator.hpp"
#include "libanvil/include/tag/string_tag.hpp"

namespace InGameOperation::Generation {
	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::generate() {
		if (this->option.generationMethod == GenerationMethod::DEFAULT or
			this->option.generationMethod == GenerationMethod::FALLING_BLOCK_COREPLACING) {
			this->_generate_method_coreplacing();
		} else {
			//Only Co-replacing Method is supported now. Raise the error!
			throw std::runtime_error(
					"Falling Block Generator now doesn't support methods other than the Co-replacing Method!");
		}
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::_generate_method_coreplacing() {
		auto res = _generate_next_generation_block();
		this->output << res;
	}

	template<typename BlockMapType>
	std::string FallingBlockGenerator<BlockMapType>::_generate_next_generation_block() {
		if (this->option.generationMethod == GenerationMethod::DEFAULT or
			this->option.generationMethod == GenerationMethod::FALLING_BLOCK_COREPLACING) {
			this->_generate_next_generation_block_coreplacing();
		} else {
			//Only Co-replacing Method is supported now. Raise the error!
			throw std::runtime_error(
					"Falling Block Generator now doesn't support methods other than the Co-replacing Method!");
		}
	}

	template<typename BlockMapType>
	std::string FallingBlockGenerator<BlockMapType>::_generate_next_generation_block_coreplacing() {
		int self_position = this->next_gen_buffer;
		if (this->next_gen_buffer < this->size) {
			this->next_gen_buffer += this->option.maxStackHeight - Constants::STACK_FUNCTIONAL_BLOCKS;
			this->positionIndex++;
			if (positionIndex >= this->positions.size()) {
				this->positionIndex = 0;
			}
			auto res = _generate_next_generation_block_coreplacing();

		} else {

		}
		this->positionIndex--;
		if (this->positionIndex < 0) {
			this->positionIndex = this->positions.size() - 1;
		}
		return std::string();
	}


	//Constructors, setters, and getters
	template<typename BlockMapType>
	FallingBlockGenerator<BlockMapType>::FallingBlockGenerator(Option option) {
		this->option = option;
		positions = {};
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::setMap(BlockMapType map) {
		this->map = map;
		calculate_size();
	}

	template<typename BlockMapType>
	const std::vector<Data::Position> &FallingBlockGenerator<BlockMapType>::getPositions() const {
		return positions;
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::setPositions(std::vector<Data::Position> positions) {
		FallingBlockGenerator::positions = std::move(positions);
	}


	//Calculating and resetting
	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::reset_data() {
		this->current_x = this->current_y = this->current_z = this->next_gen_buffer = this->positionIndex = 0;
		calculate_size();
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::calculate_size() {
		//this->size = this->map.getWidth() * this->map.getLength() * this->map.getHeight();

		//Calculates total amount of blocks in the map that is not air.
		//O(n^3), which is very not effective and should be improved.
		this->size = 0;
		for (int x = 0; x < this->map.getLength(); x++) {
			for (int y = 0; y < this->map.getHeight(); y++) {
				for (int z = 0; z < this->map.getWidth(); z++) {
					auto block = this->map.getBlock(x, y, z);
					nbt::value name = static_cast<nbt::value &&>(block[TagNameStandard::BLOCK]);
					if (name.as<nbt::tag_string>().get() == "minecraft:air" or
						name.as<nbt::tag_string>().get() == "air") {
						continue;
					}
					this->size++;
				}
			}
		}
	}

	template<typename BlockMapType>
	int FallingBlockGenerator<BlockMapType>::getPositionIndex() const {
		return positionIndex;
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::setPositionIndex(int positionIndex) {
		FallingBlockGenerator::positionIndex = positionIndex;
	}

	template<typename BlockMapType>
	int FallingBlockGenerator<BlockMapType>::getCurrentX() const {
		return current_x;
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::setCurrentX(int currentX) {
		current_x = currentX;
	}

	template<typename BlockMapType>
	int FallingBlockGenerator<BlockMapType>::getCurrentY() const {
		return current_y;
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::setCurrentY(int currentY) {
		current_y = currentY;
	}

	template<typename BlockMapType>
	int FallingBlockGenerator<BlockMapType>::getCurrentZ() const {
		return current_z;
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::setCurrentZ(int currentZ) {
		current_z = currentZ;
	}

	template<typename BlockMapType>
	int FallingBlockGenerator<BlockMapType>::getSize() const {
		return size;
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::setSize(int size) {
		FallingBlockGenerator::size = size;
	}

	template<typename BlockMapType>
	int FallingBlockGenerator<BlockMapType>::getNextGenBuffer() const {
		return next_gen_buffer;
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::setNextGenBuffer(int nextGenBuffer) {
		next_gen_buffer = nextGenBuffer;
	}

	template
	class FallingBlockGenerator<StructureBlockMap>;
}

