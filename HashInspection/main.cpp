#include "Hash.h"
#include "MultiplicativeHash.h"

int main()
{
	Hash* engine = new MultiplicativeHash();

	std::vector<uint8_t> hash1 = engine->str_hash("x64/HashInspection.exe");
	std::vector<uint8_t> hash2 = engine->file_hash("x64/HashInspection.exe");

	for (uint64_t i = 0; i < hash1.size(); ++i)
	{
		std::cout 
			<< std::hex 
			<< static_cast<uint64_t>(hash1[i]) << " ";
	}
	std::cout << std::endl;

	for (uint64_t i = 0; i < hash2.size(); ++i)
	{
		std::cout
			<< std::hex
			<< static_cast<uint64_t>(hash2[i]) << " ";
	}
	std::cout << std::endl;

	return 0;
}