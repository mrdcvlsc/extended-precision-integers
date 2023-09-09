#include <iostream>
#include <string>

#include "../include/epi/epi.hpp"
#include "small_test.hpp"

using uint64_8t = epi::whole_number<std::uint8_t, std::uint16_t, 64UL>;
using uint64_16t = epi::whole_number<std::uint16_t, std::uint32_t, 64UL>;
using uint64_32t = epi::whole_number<std::uint32_t, std::uint64_t, 64UL>;

using uint128_8t = epi::whole_number<std::uint8_t, std::uint16_t, 128UL>;
using uint128_16t = epi::whole_number<std::uint16_t, std::uint32_t, 128UL>;
using uint128_32t = epi::whole_number<std::uint32_t, std::uint64_t, 128UL>;

#ifndef ENV_64BIT_EXTENDED
// using uint128_64t = epi::whole_number<std::uint64_t, __uint128_t, 128UL>;
using uint128_64t = epi::whole_number<std::uint32_t, std::uint64_t, 128UL>;
#else
using uint128_64t = epi::whole_number<std::uint32_t, std::uint64_t, 128UL>;
#endif

int main() {
    smlts::test t;

    {
        constexpr uint128_8t  num1("5634002666979036418341388015");
        constexpr uint128_16t num2("5634002666979036418341388015");
        constexpr uint128_32t num3("5634002666979036418341388015");

        constexpr uint128_64t num4("5634002666979036418341388015");

        constexpr uint128_8t num5(
          "0b100100011010001010110011110001001000011111110111011010000110111101010110100001011111011101111"
        );
        constexpr uint128_16t num6(
          "0b100100011010001010110011110001001000011111110111011010000110111101010110100001011111011101111"
        );
        constexpr uint128_32t num7(
          "0b100100011010001010110011110001001000011111110111011010000110111101010110100001011111011101111"
        );

        constexpr uint128_64t num8(
          "0b100100011010001010110011110001001000011111110111011010000110111101010110100001011111011101111"
        );

        constexpr uint128_8t  num9("0o4432126361103767320675264137357");
        constexpr uint128_16t num10("0o4432126361103767320675264137357");
        constexpr uint128_32t num11("0o4432126361103767320675264137357");
        constexpr uint128_64t num12("0o4432126361103767320675264137357");

        constexpr uint128_8t  num13("0x1234567890feed0dead0beef");
        constexpr uint128_16t num14("0x1234567890feed0dead0beef");
        constexpr uint128_32t num15("0x1234567890feed0dead0beef");
        constexpr uint128_64t num16("0x1234567890feed0dead0beef");

        t.cmp_eq(num1, num2, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num2, num3, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num3, num4, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num4, num5, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num5, num6, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num6, num7, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num7, num8, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num8, num9, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num9, num10, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num10, num11, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num11, num12, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num12, num13, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num13, num14, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num14, num15, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num15, num16, 128 / 8, __FILE__, __LINE__);

        const uint64_t int0 = 15059734848003423983ULL;

        constexpr uint64_8t  int1("15059734848003423983");
        constexpr uint64_16t int2("15059734848003423983");
        constexpr uint64_32t int3("15059734848003423983");

        constexpr uint64_8t  int4("0b1101000011111110111011010000110111101010110100001011111011101111");
        constexpr uint64_16t int5("0b1101000011111110111011010000110111101010110100001011111011101111");
        constexpr uint64_32t int6("0b1101000011111110111011010000110111101010110100001011111011101111");

        constexpr uint64_8t  int7("0o1503767320675264137357");
        constexpr uint64_16t int8("0o1503767320675264137357");
        constexpr uint64_32t int9("0o1503767320675264137357");

        constexpr uint64_8t  int10("0xd0feed0dead0beef");
        constexpr uint64_16t int11("0xd0feed0dead0beef");
        constexpr uint64_32t int12("0xd0feed0dead0beef");

        t.cmp_eq(int0, int1, 8, __FILE__, __LINE__);
        t.cmp_eq(int1, int2, 8, __FILE__, __LINE__);
        t.cmp_eq(int2, int3, 8, __FILE__, __LINE__);
        t.cmp_eq(int3, int4, 8, __FILE__, __LINE__);
        t.cmp_eq(int4, int5, 8, __FILE__, __LINE__);
        t.cmp_eq(int5, int6, 8, __FILE__, __LINE__);
        t.cmp_eq(int6, int7, 8, __FILE__, __LINE__);
        t.cmp_eq(int7, int8, 8, __FILE__, __LINE__);
        t.cmp_eq(int8, int9, 8, __FILE__, __LINE__);
        t.cmp_eq(int9, int10, 8, __FILE__, __LINE__);
        t.cmp_eq(int10, int11, 8, __FILE__, __LINE__);
        t.cmp_eq(int11, int12, 8, __FILE__, __LINE__);
    }

    {
        constexpr uint128_8t  num1("2");
        constexpr uint128_16t num2("2");
        constexpr uint128_32t num3("2");
        constexpr uint128_64t num4("2");

        constexpr uint128_8t  num5("0b10");
        constexpr uint128_16t num6("0b10");
        constexpr uint128_32t num7("0b10");
        constexpr uint128_64t num8("0b10");

        constexpr uint128_8t  num9("0o2");
        constexpr uint128_16t num10("0o2");
        constexpr uint128_32t num11("0o2");
        constexpr uint128_64t num12("0o2");

        constexpr uint128_8t  num13("0x2");
        constexpr uint128_16t num14("0x2");
        constexpr uint128_32t num15("0x2");
        constexpr uint128_64t num16("0x2");

        t.cmp_eq(num1, num2, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num2, num3, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num3, num4, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num4, num5, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num5, num6, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num6, num7, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num7, num8, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num8, num9, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num9, num10, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num10, num11, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num11, num12, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num12, num13, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num13, num14, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num14, num15, 128 / 8, __FILE__, __LINE__);
        t.cmp_eq(num15, num16, 128 / 8, __FILE__, __LINE__);

        const uint64_t int0 = 255ULL;

        constexpr uint64_8t  int1("255");
        constexpr uint64_16t int2("255");
        constexpr uint64_32t int3("255");

        constexpr uint64_8t  int4("0b11111111");
        constexpr uint64_16t int5("0b11111111");
        constexpr uint64_32t int6("0b11111111");

        constexpr uint64_8t  int7("0o377");
        constexpr uint64_16t int8("0o377");
        constexpr uint64_32t int9("0o377");

        constexpr uint64_8t  int10("0xff");
        constexpr uint64_16t int11("0xff");
        constexpr uint64_32t int12("0xff");

        t.cmp_eq(int0, int1, 8, __FILE__, __LINE__);
        t.cmp_eq(int1, int2, 8, __FILE__, __LINE__);
        t.cmp_eq(int2, int3, 8, __FILE__, __LINE__);
        t.cmp_eq(int3, int4, 8, __FILE__, __LINE__);
        t.cmp_eq(int4, int5, 8, __FILE__, __LINE__);
        t.cmp_eq(int5, int6, 8, __FILE__, __LINE__);
        t.cmp_eq(int6, int7, 8, __FILE__, __LINE__);
        t.cmp_eq(int7, int8, 8, __FILE__, __LINE__);
        t.cmp_eq(int8, int9, 8, __FILE__, __LINE__);
        t.cmp_eq(int9, int10, 8, __FILE__, __LINE__);
        t.cmp_eq(int10, int11, 8, __FILE__, __LINE__);
        t.cmp_eq(int11, int12, 8, __FILE__, __LINE__);
    }

    return t.get_final_verdict("STRING_VIEW CONSTRUCTOR");
}
