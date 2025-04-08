#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

class Block
{
protected: /* data */
	std::vector<uint8_t> raw;
	std::vector<uint8_t> redc;

public: /* control */
	std::vector<uint8_t>& get_raw() { return raw; }
	std::vector<uint8_t>& get_redc() { return redc; }

protected: /* block */
	virtual uint64_t input_block() const;
	virtual uint64_t encode_block() const;

public: /* virtual */
	virtual bool encode();
	virtual bool decode();
};