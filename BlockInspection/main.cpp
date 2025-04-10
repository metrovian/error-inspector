#include "Block.h"
#include "Hamming74.h"
#include "Hadamard32.h"
#include "Expander84.h"

int main()
{
	Block* engine = new Expander84();

	std::vector<uint8_t> raw = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10 };

	engine->get_raw() = raw;
	engine->encode();

	engine->get_redc().front() ^= (1 << 2);
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