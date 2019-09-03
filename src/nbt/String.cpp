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

#include "String.hpp"

void NBT::String::replace(std::string &s1, const std::string &s2, const std::string &s3) {
	std::string::size_type pos = 0;
	std::string::size_type a = s2.size();
	std::string::size_type b = s3.size();
	while ((pos = s1.find(s2, pos)) != std::string::npos) {
		s1.replace(pos, a, s3);
		pos += b;
	}
}

void NBT::String::toString(std::ostringstream &os) {
	os << "\"";
	//Unescape string
	auto strcpy = str;
	replace(strcpy, "\n", "\\n");
	replace(strcpy, "\"", "\\\"");
	os << strcpy;
	os << "\"";
}

std::string NBT::String::get() {
	return str;
}

NBT::String::String(const NBT::String::type &str) : str(str) {}
