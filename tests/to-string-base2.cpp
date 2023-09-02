#include "../include/epi/epi.hpp"

#include <cassert>
#include <iostream>
#include <string>

#include "small_test.hpp"

typedef epi::whole_number<uint8_t, uint16_t, 64>  uint64_8t;
typedef epi::whole_number<uint16_t, uint32_t, 64> uint64_16t;
typedef epi::whole_number<uint32_t, uint64_t, 64> uint64_32t;

int main() {
    smlts::test t;

    {
        constexpr uint64_8t  num01;
        constexpr uint64_16t num02;
        constexpr uint64_32t num03;

        t.assertion(num01.to_string_base2() == std::string("0"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base2() == std::string("0"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base2() == std::string("0"), __FILE__, __LINE__);
    }

    {
        constexpr uint64_8t  num01 = 1;
        constexpr uint64_16t num02 = 1;
        constexpr uint64_32t num03 = 1;

        t.assertion(num01.to_string_base2() == std::string("1"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base2() == std::string("1"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base2() == std::string("1"), __FILE__, __LINE__);
    }

    {
        constexpr uint64_8t  num01 = 255;
        constexpr uint64_16t num02 = 255;
        constexpr uint64_32t num03 = 255;

        t.assertion(num01.to_string_base2() == std::string("11111111"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base2() == std::string("11111111"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base2() == std::string("11111111"), __FILE__, __LINE__);
    }

    {
        constexpr uint64_8t  num01 = 65535;
        constexpr uint64_16t num02 = 65535;
        constexpr uint64_32t num03 = 65535;

        t.assertion(num01.to_string_base2() == std::string("1111111111111111"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base2() == std::string("1111111111111111"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base2() == std::string("1111111111111111"), __FILE__, __LINE__);
    }

    {
        constexpr uint64_8t  num01("4294967295");
        constexpr uint64_16t num02("4294967295");
        constexpr uint64_32t num03("4294967295");

        t.assertion(num01.to_string_base2() == std::string("11111111111111111111111111111111"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base2() == std::string("11111111111111111111111111111111"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base2() == std::string("11111111111111111111111111111111"), __FILE__, __LINE__);
    }

    {
        constexpr uint64_8t  num01("18446744073709551615");
        constexpr uint64_16t num02("18446744073709551615");
        constexpr uint64_32t num03("18446744073709551615");

        t.assertion(
          num01.to_string_base2() == std::string("1111111111111111111111111111111111111111111111111111111111111111"),
          __FILE__, __LINE__
        );
        t.assertion(
          num02.to_string_base2() == std::string("1111111111111111111111111111111111111111111111111111111111111111"),
          __FILE__, __LINE__
        );
        t.assertion(
          num03.to_string_base2() == std::string("1111111111111111111111111111111111111111111111111111111111111111"),
          __FILE__, __LINE__
        );
    }

    {
        constexpr epi::whole_number<uint8_t, uint16_t, 512>  num1("0xdead0cafe0feed0beef01234567890deed00aabbccddeeff");
        constexpr epi::whole_number<uint16_t, uint32_t, 512> num2("0xdead0cafe0feed0beef01234567890deed00aabbccddeeff");
        constexpr epi::whole_number<uint32_t, uint64_t, 512> num3("0xdead0cafe0feed0beef01234567890deed00aabbccddeeff");
        // constexpr epi::whole_number<uint64_t, __uint128_t, 512>
        // num4("0xdead0cafe0feed0beef01234567890deed00aabbccddeeff");

        t.assertion(
          num1.to_string_base2() ==
            std::string(
              "11011110101011010000110010101111111000001111111011101101000010111110111011110000000100100011010001010110"
              "0111100010010000110111101110110100000000101010101011101111001100110111011110111011111111"
            ),
          __FILE__, __LINE__
        );
        t.assertion(
          num2.to_string_base2() ==
            std::string(
              "11011110101011010000110010101111111000001111111011101101000010111110111011110000000100100011010001010110"
              "0111100010010000110111101110110100000000101010101011101111001100110111011110111011111111"
            ),
          __FILE__, __LINE__
        );
        t.assertion(
          num3.to_string_base2() ==
            std::string(
              "11011110101011010000110010101111111000001111111011101101000010111110111011110000000100100011010001010110"
              "0111100010010000110111101110110100000000101010101011101111001100110111011110111011111111"
            ),
          __FILE__, __LINE__
        );
        // t.assertion(num4.to_string_base2() ==
        // std::string("110111101010110100001100101011111110000011111110111011010000101111101110111100000001001000110100010101100111100010010000110111101110110100000000101010101011101111001100110111011110111011111111"),
        // __FILE__, __LINE__);
    }

    return t.get_final_verdict("TO STRING BASE 2");
}