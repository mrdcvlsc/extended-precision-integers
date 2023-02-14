#include <iostream>
#include "epi.hpp"

typedef epi::number<unsigned char, unsigned short, 4> myuint32_t;
typedef epi::number<uint64_t, __uint128_t, 2> uint128_t;
typedef epi::number<uint32_t, uint64_t, 6> uint192_t;
typedef epi::number<uint64_t, __uint128_t, 4> uint256_t;

int main() {

    myuint32_t z = {0xfe, 0xed, 0x1, 0xb};
    std::cout << std::hex << z << "\n";

    uint128_t a = {0xffffffffffffffff, 0xdeadbeef};
    std::cout << std::dec << a << "\n";

    std::cout << std::hex << a << "\n";

    uint256_t b = {0xff, 0xfa, 0xfb, 0xfc};
    std::cout << std::oct  << b << "\n";

    uint192_t c = {0xfeedbeef, 0xdeadcafe};
    std::cout << std::dec << c << "\n";

    return 0;
}