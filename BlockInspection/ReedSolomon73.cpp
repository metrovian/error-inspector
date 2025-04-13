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
	return (*this) * _sym.inverse();
}

ReedSolomon73::symbol ReedSolomon73::symbol::inverse() const
{
	uint8_t dat = (*this).data.to_ulong();
	uint8_t pow = 0;

	for (uint8_t i = 0; i < 7; ++i)
	{
		pow = symbol(2).power(i).data.to_ulong();

		if (dat == pow)
		{
			return symbol(2).power(7 - i);
}
	}

	return symbol(1);
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