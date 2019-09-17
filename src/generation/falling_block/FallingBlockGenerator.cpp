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
#include "libnbtplusplus/include/tag_list.h"


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
			this->_generate_next_generation_block_coreplacing(0, 0);
		} else {
			//Only Co-replacing Method is supported now. Raise the error!
			throw std::runtime_error(
					"Falling Block Generator now doesn't support methods other than the Co-replacing Method!");
		}
		return "";
	}

	template<typename BlockMapType>
	std::string FallingBlockGenerator<BlockMapType>::_generate_next_generation_block_coreplacing(int gen_buffer,
																								 int positionIndex) {
		//TODO: finish the generation block algorithm
		std::string prefix = "/setblock ";
		std::string result;
		if (gen_buffer < this->map.getSize()) {
			result = _generate_next_generation_block_coreplacing(
					gen_buffer + this->option.maxStackHeight - Constants::STACK_FUNCTIONAL_BLOCKS,
					(positionIndex + 1 >= positions.size() ?
					 0 : positionIndex + 1));

		} else {

		}

		for (int sub_index = 0;
			 gen_buffer + sub_index < this->map.getSize() and
			 sub_index < this->option.maxStackHeight - Constants::STACK_FUNCTIONAL_BLOCKS; sub_index++) {

		}
		return std::string();
	}

	template<typename BlockMapType>
	std::string FallingBlockGenerator<BlockMapType>::_generate_generation_stack(nbt::tag_list::iterator begin,
																				nbt::tag_list::iterator end,
																				Data::Position target_base_pos) {
		std::vector<std::string> block_generation_commands;
		for (; begin != end; begin++) {
			nbt::tag_compound &block = begin->as<nbt::tag_compound>();
			nbt::tag_compound &palette = this->map.getPalette(block);
			nbt::tag_compound &nbt = block[TagNameStandard::NBT].as<nbt::tag_compound>();
			std::stringstream generation_command_sstream;
			generation_command_sstream << "/setblock "
									   << target_base_pos.x << " " << target_base_pos.y << " " << target_base_pos.z
									   << " " << (std::string) palette[TagNameStandard::NAME]
									   << nbt;
			block_generation_commands.push_back(generation_command_sstream.str());
		}
		std::ostringstream ostringstream;
		ostringstream << "/setblock "
					  << target_base_pos.x << " " << target_base_pos.y << " " << target_base_pos.z
					  << " minecraft:command_block";
		return std::string();
	}

	//Constructors, setters, and getters
	template<typename BlockMapType>
	FallingBlockGenerator<BlockMapType>::FallingBlockGenerator(Option option) {
		static_assert(std::is_base_of<BlockMap<nbt::tag_compound>, BlockMapType>::value, "The type of BlockMapType must"
																						 "be derived from BlockMap");
		this->option = option;
		positions = {};
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::setMap(BlockMapType map) {
		this->map = map;
	}

	template<typename BlockMapType>
	const std::vector<Data::Position> &FallingBlockGenerator<BlockMapType>::getPositions() const {
		return positions;
	}

	template<typename BlockMapType>
	void FallingBlockGenerator<BlockMapType>::setPositions(std::vector<Data::Position> positions) {
		FallingBlockGenerator::positions = std::move(positions);
	}


	template
	class FallingBlockGenerator<StructureBlockMap>;
}

