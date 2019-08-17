#include <iostream>
#include "region_file_reader.hpp"

int main() {
	region_file_reader reader;
	reader = region_file_reader(
			"/Users/jessiezhang/Library/Application Support/TLauncherMC/saves/1_13/region/r.0.0.mca");
	reader.read();
	// iterate through all possible chunks within a region
	for (unsigned int z = 0; z < 32; ++z) {
		for (unsigned int x = 0; x < 32; ++x) {

			// this keeps an exception from being thrown
			// when a non-existant chunk is requested
			if (!reader.is_filled(x, z)) {
				std::cout << "Chunk " << x << ", " << z << " is not filled!" << std::endl;
				continue;
			}

			// if everything goes well, retrieve the block/height data
			auto blocks = reader.get_blocks_at(x, z);
			auto heights = reader.get_heightmap_at(x, z);
			auto biomes = reader.get_biomes_at(x, z);

			std::cout << "block amount: " << blocks.size() << ", height amount: " << heights.size() << std::endl;

			// ...
			for (auto &block : blocks) {
				std::cout << "Block at " << x << ", " << z << ": " << block << std::endl;
			}
			for (auto &height : heights) {
				std::cout << "Height at " << x << ", " << z << ": " << height << std::endl;
			}
			for (auto &height : heights) {
				std::cout << "Biome at " << x << ", " << z << ": " << (int) height << std::endl;
			}
		}
	}
	return 0;
}