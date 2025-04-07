#include "Block.h"

bool Block::set_raw(const std::vector<uint8_t>& _raw)
{
	raw = _raw;
	return true;
}

bool Block::set_redc(const std::vector<uint8_t>& _redc)
{
	redc = _redc;
	return true;
}
