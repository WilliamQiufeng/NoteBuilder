//
// Created by Qiufeng54321 on 2019-09-09.
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

#ifndef NOTEBUILDER_GENERATIONOPTION_HPP
#define NOTEBUILDER_GENERATIONOPTION_HPP

namespace InGameOperation::Generation {
	enum class GenerationMethod {
		DEFAULT,
		FALLING_BLOCK_COREPLACING,
		FALLING_BLOCK_RECURSIVE_BUILDING
	};

	struct Option {
		GenerationMethod generationMethod;
		int maxStackHeight;//Used in FallingBlockGenerator
		Option(GenerationMethod generationMethod = GenerationMethod::DEFAULT, int maxStackHeight = 16);
	};
}

#endif //NOTEBUILDER_GENERATIONOPTION_HPP
