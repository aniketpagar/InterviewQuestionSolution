/****************************************************************************
File name: endian_conversion.cpp

Author: babajr
*****************************************************************************/


/* Big Endian and Little Endian Conversion */
/*
res = ((num & 0xFF000000) >> 24) |
      ((num & 0x00FF0000) >> 8) |
      ((num & 0x0000FF00) << 8) |
      ((num & 0x000000FF) << 24);

*/
#include<stdio.h>
#include<stdint.h>

int main(void)
{
    uint32_t num = 0x12345678;
    uint32_t res = 0;

    printf("Original Number: %x\n", num);

    res = ((num & 0xFF000000) >> 24) |
    ((num & 0x00FF0000) >> 8) |
    ((num & 0x0000FF00) << 8) |
    ((num & 0x000000FF) << 24);

    printf("Modified Number: %x\n", res);

    return 0;
}
