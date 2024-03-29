#include <cassert>
#include <iostream>
#include <string>

#include "../include/epi/epi.hpp"
#include "small_test.hpp"

using uint64_8t = epi::whole_number<std::uint8_t, std::uint16_t, 64UL>;
using uint64_16t = epi::whole_number<std::uint16_t, std::uint32_t, 64UL>;
using uint64_32t = epi::whole_number<std::uint32_t, std::uint64_t, 64UL>;

int main() {
    smlts::test t;

    {
        constexpr uint64_8t  num01;
        constexpr uint64_16t num02;
        constexpr uint64_32t num03;

        t.assertion(num01.to_string_base8() == std::string("0"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base8() == std::string("0"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base8() == std::string("0"), __FILE__, __LINE__);
    }

    {
        constexpr uint64_8t  num01 = 1;
        constexpr uint64_16t num02 = 1;
        constexpr uint64_32t num03 = 1;

        t.assertion(num01.to_string_base8() == std::string("1"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base8() == std::string("1"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base8() == std::string("1"), __FILE__, __LINE__);
    }

    {
        constexpr uint64_8t  num01 = 255;
        constexpr uint64_16t num02 = 255;
        constexpr uint64_32t num03 = 255;

        t.assertion(num01.to_string_base8() == std::string("377"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base8() == std::string("377"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base8() == std::string("377"), __FILE__, __LINE__);
    }

    {
        constexpr uint64_8t  num01 = 65535;
        constexpr uint64_16t num02 = 65535;
        constexpr uint64_32t num03 = 65535;

        t.assertion(num01.to_string_base8() == std::string("177777"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base8() == std::string("177777"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base8() == std::string("177777"), __FILE__, __LINE__);
    }

    {
        constexpr uint64_8t  num01("4294967295");
        constexpr uint64_16t num02("4294967295");
        constexpr uint64_32t num03("4294967295");

        t.assertion(num01.to_string_base8() == std::string("37777777777"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base8() == std::string("37777777777"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base8() == std::string("37777777777"), __FILE__, __LINE__);
    }

    {
        constexpr uint64_8t  num01("18446744073709551615");
        constexpr uint64_16t num02("18446744073709551615");
        constexpr uint64_32t num03("18446744073709551615");

        t.assertion(num01.to_string_base8() == std::string("1777777777777777777777"), __FILE__, __LINE__);
        t.assertion(num02.to_string_base8() == std::string("1777777777777777777777"), __FILE__, __LINE__);
        t.assertion(num03.to_string_base8() == std::string("1777777777777777777777"), __FILE__, __LINE__);
    }

    {
        constexpr epi::whole_number<uint8_t, uint16_t, 512>  num1("0xdead0cafe0feed0beef01234567890deed00aabbccddeeff");
        constexpr epi::whole_number<uint16_t, uint32_t, 512> num2("0xdead0cafe0feed0beef01234567890deed00aabbccddeeff");
        constexpr epi::whole_number<uint32_t, uint64_t, 512> num3("0xdead0cafe0feed0beef01234567890deed00aabbccddeeff");

#ifdef ENV_64BIT_EXTENDED
        constexpr epi::whole_number<uint64_t, __uint128_t, 512> num4(
          "0xdead0cafe0feed0beef01234567890deed00aabbccddeeff"
        );
#endif

        t.assertion(
          num1.to_string_base8() == std::string("6752641453760376732057567401106425474220675664005253571467367377"),
          __FILE__, __LINE__
        );
        t.assertion(
          num2.to_string_base8() == std::string("6752641453760376732057567401106425474220675664005253571467367377"),
          __FILE__, __LINE__
        );
        t.assertion(
          num3.to_string_base8() == std::string("6752641453760376732057567401106425474220675664005253571467367377"),
          __FILE__, __LINE__
        );

#ifdef ENV_64BIT_EXTENDED
        t.assertion(
          num4.to_string_base8() == std::string("6752641453760376732057567401106425474220675664005253571467367377"),
          __FILE__, __LINE__
        );
#endif
    }

    return t.get_final_verdict("TO STRING BASE 8");
}