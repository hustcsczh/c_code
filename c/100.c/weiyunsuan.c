#include <stdio.h>

int main()
{

    unsigned short k;
    scanf("%hu", &k);

    // 将k的高4位与低4位提取出来
    unsigned short high_bits = k & 0xF000; // 高4位
    unsigned short low_bits = k & 0x000F;  // 低4位

    // 高低4位位置交换
    high_bits = high_bits >> 12;
    low_bits = low_bits << 12;
    unsigned short q;
    unsigned short mask = 0xF0; // 二进制数11110000表示高四位和第四位都为0的位掩码
    q = k & mask;
    unsigned short result = (high_bits | low_bits) | q;
    printf("%hu", result);
    return 0;
}
