#include "Block.h"

int main()
{
	Block* engine = new Block();

	std::vector<uint8_t> raw = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };

	engine->get_raw() = raw;
	engine->encode();

	engine->get_redc().back() = 0xFF;
	engine->decode();

	for (uint64_t i = 0; i < raw.size(); i++)
	{
		std::cout 
			<< std::hex << std::setw(2) << std::setfill('0') 
			<< static_cast<uint64_t>(raw[i]) << " ";
	}
	std::cout << std::endl;

	for (uint64_t i = 0; i < engine->get_raw().size(); i++)
	{
		std::cout 
			<< std::hex << std::setw(2) << std::setfill('0') 
			<< static_cast<uint64_t>(engine->get_raw()[i]) << " ";
	}
	std::cout << std::endl;

	return 0;
}