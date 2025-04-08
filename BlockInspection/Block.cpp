#include "Block.h"

uint64_t Block::input_block() const
{
    return 0;
}

uint64_t Block::encode_block() const
{
    return 0;
}

bool Block::encode()
{
    redc = raw;
    return true;
}

bool Block::decode()
{
    raw = redc;
    return true;
}
