#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <bitset>

class Block
{
protected: /* data */
	std::vector<uint8_t> raw;
	std::vector<uint8_t> redc;

protected: /* bitset */
	template <uint8_t N> std::vector<std::bitset<N>> transform(std::vector<uint8_t> _bytes);
	template <uint8_t N> std::vector<uint8_t> inverse(std::vector<std::bitset<N>> _bits);

public: /* control */
	std::vector<uint8_t>& get_raw() { return raw; }
	std::vector<uint8_t>& get_redc() { return redc; }

protected: /* block */
	virtual uint64_t input_block() const { return 0; };
	virtual uint64_t encode_block() const { return 0; };

public: /* virtual */
	virtual bool encode();
	virtual bool decode();
};

template<uint8_t N>
inline std::vector<std::bitset<N>> Block::transform(std::vector<uint8_t> _bytes)
{
	std::vector<std::bitset<N>> ret;
	
	uint8_t cap = 0;

	for (uint64_t i = 0; i < _bytes.size(); i++)
	{
		uint8_t bit = 1;

		for (uint64_t j = 0; j < 8; ++j)
		{
			if (!cap)
			{
				ret.push_back(std::bitset<N>(0));
				cap = N;
			}

			ret.back()[N - (cap--)] = (_bytes[i] & bit) ? 1 : 0;
			bit <<= 1;
		}
	}

	return ret;
}

template<uint8_t N>
inline std::vector<uint8_t> Block::inverse(std::vector<std::bitset<N>> _bits)
{
	std::vector<uint8_t> ret;
	return ret;
}
