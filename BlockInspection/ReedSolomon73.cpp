#include "ReedSolomon73.h"

ReedSolomon73::symbol ReedSolomon73::symbol::operator+(const symbol& _sym) const
{
	return symbol(data ^ _sym.data);
}

ReedSolomon73::symbol ReedSolomon73::symbol::operator-(const symbol& _sym) const
{
	return symbol(data ^ _sym.data);
}

ReedSolomon73::symbol ReedSolomon73::symbol::operator*(const symbol& _sym) const
{
	std::bitset<3> ret(0);

	for (uint8_t i = 0; i < 3; ++i)
	{
		for (uint8_t j = 0; j < 3; ++j)
		{
			uint8_t rdeg1 = (i + j) % 3;
			uint8_t rdeg2 = (i + j) % 3 + 1;

			ret[rdeg1] = ret[rdeg1] ^ (data[i] & _sym.data[j]);

			if ((i + j) / 3)
			{
				ret[rdeg2] = ret[rdeg2] ^ (data[i] & _sym.data[j]);
			}
		}
	}

	return symbol(ret);
}

ReedSolomon73::symbol ReedSolomon73::symbol::operator/(const symbol& _sym) const
{
	return symbol();
}

ReedSolomon73::symbol ReedSolomon73::symbol::inverse() const
{
	return symbol();
}

ReedSolomon73::symbol ReedSolomon73::symbol::power(uint8_t _num) const
{
	symbol ret(1);

	for (uint8_t i = 0; i < _num; ++i)
	{
		ret = ret * (*this);
	}

	return ret;
}

bool ReedSolomon73::encode()
{
	return true;
}

bool ReedSolomon73::decode()
{
	return true;
}