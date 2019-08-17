#include <iostream>
#include "region_file_reader.hpp"

int main() {
	std::cout << "Hello, World!" << std::endl;
	region_file_reader reader;
	reader = region_file_reader(
			"/Users/jessiezhang/Library/Application Support/TLauncherMC/saves/&3Loading___/region/r.-1.-2.mca");
	reader.read();
	auto blocks = reader.get_blocks_at(0, 0);
	for (auto &item : blocks) {
		std::cout << "Block ID: " << item << std::endl;
	}
	return 0;
}