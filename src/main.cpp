#include <iostream>
#include <fstream>
#include "nbt/Tag.hpp"
#include <nbt/GenericTag.hpp>
#include <nbt/CompoundTag.hpp>
#include <nbt/String.hpp>
#include <nbt/Array.hpp>
#include <nbt/List.hpp>
#include <nbt/NBT.hpp>
#include <libnbtplusplus/include/io/stream_reader.h>
#include "generation/falling_block/FallingBlockGenerator.hpp"


void testNBT();

void testGenerator();

int main() {
	testGenerator();
	return 0;
}

void testNBT() {
	using namespace NBT;
	auto *compoundTag = new CompoundTag;
	compoundTag->set("hi", new String("\"hello\n\""));
	auto *subCompound = new CompoundTag();
	auto *array = new IntArray;
	array->add(new GenericTag<int>(2));
	array->add(new GenericTag<int>(3));
	auto *list = new List(Tag::Types::LONG);
	list->add(new GenericTag<long>(LONG_MAX));
	subCompound->set("arr", array);
	subCompound->set("list", list);
	compoundTag->set("sub", subCompound);
	std::cout << ((String *) compoundTag->get("hi"))->get() << std::endl;
	std::ostringstream oss;
	compoundTag->toString(oss);
	std::cout << oss.str() << std::endl;
}

void testGenerator() {
	std::ifstream istream(
			"/Users/jessiezhang/Library/Application Support/TLauncherMC/versions/fabric-loader-0.4.8+build.158-1.14.2+build.2/fabric-loader-0.4.8+build.158-1.14.2+build.2/data/minecraft/structures/underwater_ruin/big_brick_1.nbt");
	nbt::io::stream_reader streamReader(istream);
	auto pair = streamReader.read_compound();
	auto map = InGameOperation::StructureBlockMap();
	map.root = *pair.second;
	auto generator = InGameOperation::Generation::FallingBlockGenerator<InGameOperation::StructureBlockMap>();
	generator.setMap(map);
	std::cout << generator.getSize() << std::endl;
	generator.reset_data();
}