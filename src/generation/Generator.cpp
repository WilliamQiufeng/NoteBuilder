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

#include "Generator.hpp"
#include "map/StructureBlockMap.hpp"

namespace InGameOperation::Generation {
	template<typename OutputType, typename BlockMapType>
	typename Generation<OutputType, BlockMapType>::output_t &Generation<OutputType, BlockMapType>::getOutput() {
		return output;
	}

	template<typename OutputType, typename BlockMapType>
	const Option &Generation<OutputType, BlockMapType>::getOption() const {
		return option;
	}

	template<typename OutputType, typename BlockMapType>
	void Generation<OutputType, BlockMapType>::setOption(const Option &option) {
		Generation::option = option;
	}

	template<typename OutputType, typename BlockMapType>
	BlockMapType Generation<OutputType, BlockMapType>::getMap() const {
		return map;
	}

	template<typename OutputType, typename BlockMapType>
	void Generation<OutputType, BlockMapType>::setMap(BlockMapType map) {
		Generation::map = map;
	}

	template
	class Generation<std::ostringstream, StructureBlockMap>;
}