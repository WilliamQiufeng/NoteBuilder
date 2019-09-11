#include <iostream>
#include <fstream>
#include <libnbtplusplus/include/io/stream_reader.h>
#include "libnbtplusplus/include/io/izlibstream.h"
#include "generation/falling_block/FallingBlockGenerator.hpp"


void testNBT();

void testGenerator();

int main() {
	testGenerator();
	return 0;
}


void testGenerator() {
	std::ifstream istream(
			"/Users/jessiezhang/Library/Application Support/TLauncherMC/versions/fabric-loader-0.4.8+build.158-1.14.2+build.2/fabric-loader-0.4.8+build.158-1.14.2+build.2/data/minecraft/structures/fossil/spine_3.nbt",
			std::ios::binary);
	zlib::izlibstream izlibstream(istream);

	auto pair = nbt::io::read_compound(izlibstream);
	auto map = InGameOperation::StructureBlockMap();
	map.root = *pair.second;
	map.load();
	auto generator = InGameOperation::Generation::FallingBlockGenerator<InGameOperation::StructureBlockMap>();
	generator.setMap(map);
//	std::cout << generator.getSize() << std::endl;
	generator.reset_data();

	std::cout << "This nbt is made by " << map.author << ", DataVersion: " << map.DataVersion << std::endl;
}