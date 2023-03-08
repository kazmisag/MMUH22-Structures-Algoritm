#include <iostream>
#include <stdint.h>

int main()
{
    uint8_t raw_data = 0b01010011; // =83

    uint8_t signal1 = raw_data & 0x3; // bit operation

    uint8_t signal2 = raw_data & 0b11111000;

    printf("%d\n%d", signal1, signal2);

// Extract a desired signal 10 using shift operator
    signal2 = (raw_data & 0xF8) >>3;
    printf("\n%d\n%d", signal1, signal2);

    printf("\n%d",0xF8);

    uint8_t s1 = 3;
    uint8_t s2 = 10;

    s1 |= (s2<<3);
    
    printf("\nraw data from s1 OR s2: %d", s1);

    return 0;
}