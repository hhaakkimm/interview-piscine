#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
    value &= 1;
    parkingRow |= (value << pos);
    return (parkingRow & ~(!value << pos));
}
