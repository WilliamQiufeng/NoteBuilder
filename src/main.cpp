#include <iostream>
#include "nbt/Tag.hpp"
#include <nbt/GenericTag.hpp>
#include <nbt/CompoundTag.hpp>
#include <nbt/String.hpp>
#include <nbt/Array.hpp>
#include <nbt/List.hpp>

void testNBT();

int main() {
	testNBT();
	return 0;
}

void testNBT() {
	using namespace NBT;
	auto *compoundTag = new CompoundTag;
	compoundTag->set("hi", new String("hello"));
	auto *subCompound = new CompoundTag();
	auto *array = new IntArray;
	array->add(new GenericTag<int>(2));
	array->add(new GenericTag<int>(3));
	auto *list = new List<long>;
	list->add(new GenericTag<long>(1402738));
	subCompound->set("arr", array);
	subCompound->set("list", list);
	compoundTag->set("sub", subCompound);
	std::cout << ((String *) compoundTag->get("hi"))->get() << std::endl;
	std::ostringstream oss;
	compoundTag->toString(oss);
	std::cout << oss.str() << std::endl;
}