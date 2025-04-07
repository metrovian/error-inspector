#pragma once
#include <iostream>
#include <vector>

class Block
{
protected: /* data */
	std::vector<uint8_t> raw;
	std::vector<uint8_t> redc;

public: /* control */
	bool set_raw(const std::vector<uint8_t>& _raw);
	bool set_redc(const std::vector<uint8_t>& _redc);

protected: /* block */
	virtual uint64_t input_block() const = 0;
	virtual uint64_t encode_block() const = 0;

public: /* virtual */
	virtual bool encode() = 0;
	virtual bool decode() = 0;
};