#include <iostream>
#include <string>

#include "small_test.hpp"

typedef epi::whole_number<uint8_t, uint16_t, 64>  uint64_8t;
typedef epi::whole_number<uint16_t, uint32_t, 64> uint64_16t;
typedef epi::whole_number<uint32_t, uint64_t, 64> uint64_32t;

int main() {
  smlts::test t;

  {
    constexpr epi::whole_number<uint8_t, uint16_t, 128>     num1("5634002666979036418341388015");
    constexpr epi::whole_number<uint16_t, uint32_t, 128>    num2("5634002666979036418341388015");
    constexpr epi::whole_number<uint32_t, uint64_t, 128>    num3("5634002666979036418341388015");
    constexpr epi::whole_number<uint64_t, __uint128_t, 128> num4("5634002666979036418341388015");

    constexpr epi::whole_number<uint8_t, uint16_t, 128> num5(
      "0b100100011010001010110011110001001000011111110111011010000110111101010110100001011111011101111"
    );
    constexpr epi::whole_number<uint16_t, uint32_t, 128> num6(
      "0b100100011010001010110011110001001000011111110111011010000110111101010110100001011111011101111"
    );
    constexpr epi::whole_number<uint32_t, uint64_t, 128> num7(
      "0b100100011010001010110011110001001000011111110111011010000110111101010110100001011111011101111"
    );
    constexpr epi::whole_number<uint64_t, __uint128_t, 128> num8(
      "0b100100011010001010110011110001001000011111110111011010000110111101010110100001011111011101111"
    );

    constexpr epi::whole_number<uint8_t, uint16_t, 128>     num9("0o4432126361103767320675264137357");
    constexpr epi::whole_number<uint16_t, uint32_t, 128>    num10("0o4432126361103767320675264137357");
    constexpr epi::whole_number<uint32_t, uint64_t, 128>    num11("0o4432126361103767320675264137357");
    constexpr epi::whole_number<uint64_t, __uint128_t, 128> num12("0o4432126361103767320675264137357");

    constexpr epi::whole_number<uint8_t, uint16_t, 128>     num13("0x1234567890feed0dead0beef");
    constexpr epi::whole_number<uint16_t, uint32_t, 128>    num14("0x1234567890feed0dead0beef");
    constexpr epi::whole_number<uint32_t, uint64_t, 128>    num15("0x1234567890feed0dead0beef");
    constexpr epi::whole_number<uint64_t, __uint128_t, 128> num16("0x1234567890feed0dead0beef");

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

    constexpr epi::whole_number<uint8_t, uint16_t, 64>  int1("15059734848003423983");
    constexpr epi::whole_number<uint16_t, uint32_t, 64> int2("15059734848003423983");
    constexpr epi::whole_number<uint32_t, uint64_t, 64> int3("15059734848003423983");

    constexpr epi::whole_number<uint8_t, uint16_t, 64> int4(
      "0b1101000011111110111011010000110111101010110100001011111011101111"
    );
    constexpr epi::whole_number<uint16_t, uint32_t, 64> int5(
      "0b1101000011111110111011010000110111101010110100001011111011101111"
    );
    constexpr epi::whole_number<uint32_t, uint64_t, 64> int6(
      "0b1101000011111110111011010000110111101010110100001011111011101111"
    );

    constexpr epi::whole_number<uint8_t, uint16_t, 64>  int7("0o1503767320675264137357");
    constexpr epi::whole_number<uint16_t, uint32_t, 64> int8("0o1503767320675264137357");
    constexpr epi::whole_number<uint32_t, uint64_t, 64> int9("0o1503767320675264137357");

    constexpr epi::whole_number<uint8_t, uint16_t, 64>  int10("0xd0feed0dead0beef");
    constexpr epi::whole_number<uint16_t, uint32_t, 64> int11("0xd0feed0dead0beef");
    constexpr epi::whole_number<uint32_t, uint64_t, 64> int12("0xd0feed0dead0beef");

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
    constexpr epi::whole_number<uint8_t, uint16_t, 128>     num1("2");
    constexpr epi::whole_number<uint16_t, uint32_t, 128>    num2("2");
    constexpr epi::whole_number<uint32_t, uint64_t, 128>    num3("2");
    constexpr epi::whole_number<uint64_t, __uint128_t, 128> num4("2");

    constexpr epi::whole_number<uint8_t, uint16_t, 128>     num5("0b10");
    constexpr epi::whole_number<uint16_t, uint32_t, 128>    num6("0b10");
    constexpr epi::whole_number<uint32_t, uint64_t, 128>    num7("0b10");
    constexpr epi::whole_number<uint64_t, __uint128_t, 128> num8("0b10");

    constexpr epi::whole_number<uint8_t, uint16_t, 128>     num9("0o2");
    constexpr epi::whole_number<uint16_t, uint32_t, 128>    num10("0o2");
    constexpr epi::whole_number<uint32_t, uint64_t, 128>    num11("0o2");
    constexpr epi::whole_number<uint64_t, __uint128_t, 128> num12("0o2");

    constexpr epi::whole_number<uint8_t, uint16_t, 128>     num13("0x2");
    constexpr epi::whole_number<uint16_t, uint32_t, 128>    num14("0x2");
    constexpr epi::whole_number<uint32_t, uint64_t, 128>    num15("0x2");
    constexpr epi::whole_number<uint64_t, __uint128_t, 128> num16("0x2");

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

    constexpr epi::whole_number<uint8_t, uint16_t, 64>  int1("255");
    constexpr epi::whole_number<uint16_t, uint32_t, 64> int2("255");
    constexpr epi::whole_number<uint32_t, uint64_t, 64> int3("255");

    constexpr epi::whole_number<uint8_t, uint16_t, 64>  int4("0b11111111");
    constexpr epi::whole_number<uint16_t, uint32_t, 64> int5("0b11111111");
    constexpr epi::whole_number<uint32_t, uint64_t, 64> int6("0b11111111");

    constexpr epi::whole_number<uint8_t, uint16_t, 64>  int7("0o377");
    constexpr epi::whole_number<uint16_t, uint32_t, 64> int8("0o377");
    constexpr epi::whole_number<uint32_t, uint64_t, 64> int9("0o377");

    constexpr epi::whole_number<uint8_t, uint16_t, 64>  int10("0xff");
    constexpr epi::whole_number<uint16_t, uint32_t, 64> int11("0xff");
    constexpr epi::whole_number<uint32_t, uint64_t, 64> int12("0xff");

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
