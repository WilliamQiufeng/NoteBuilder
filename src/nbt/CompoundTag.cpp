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

#include "CompoundTag.hpp"

namespace NBT {
	void CompoundTag::set(std::string key, Tag *val) {
		children[key] = val;
	}

	Tag *CompoundTag::get(std::string key) {
		return children[key];
	}


	CompoundTag::type CompoundTag::get() {
		return children;
	}

	std::string CompoundTag::getType() {
		return "Compound";
	}

	void CompoundTag::toString(std::ostringstream &os) {
		os << "{";
		auto last = children.end();
		last--;
		for (auto iter = children.begin(); iter != children.end(); iter++) {
			os << "\"" << iter->first << "\"";
			os << ":";
			iter->second->toString(os);
			if (iter != last) {
				os << ",";
			}
		}
		os << "}";;
	}

}
