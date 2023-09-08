#include <iostream>
#include <string>

#include "../include/epi/epi.hpp"
#include "small_test.hpp"

using uint64_8t = epi::whole_number<std::uint8_t, std::uint16_t, 64UL>;
using uint64_16t = epi::whole_number<std::uint16_t, std::uint32_t, 64UL>;
using uint64_32t = epi::whole_number<std::uint32_t, std::uint64_t, 64UL>;

int main() {
    smlts::test t;

    epi::whole_number<uint32_t, uint64_t, 224> SHOULD_NOT_THROW_ERROR{0xff};
    SHOULD_NOT_THROW_ERROR++;

    t.cmp_ts<uint64_t, uint64_8t>(__FILE__, __LINE__);
    t.cmp_ts<uint64_t, uint64_16t>(__FILE__, __LINE__);
    t.cmp_ts<uint64_t, uint64_32t>(__FILE__, __LINE__);

    const uint64_t       a = 0xabcdef0123456789;
    constexpr uint64_8t  b = a;
    constexpr uint64_16t c = a;
    constexpr uint64_32t d = a;

    const uint64_t       a_2 = 0xdeadbeef;
    constexpr uint64_8t  b_2 = a_2;
    constexpr uint64_16t c_2 = a_2;
    constexpr uint64_32t d_2 = a_2;

    const uint64_t       a_3 = 0xcafebabe00000000;
    constexpr uint64_8t  b_3 = a_3;
    constexpr uint64_16t c_3 = a_3;
    constexpr uint64_32t d_3 = a_3;

    t.cmp_eq(a, b, 8, __FILE__, __LINE__);
    t.cmp_eq(a, c, 8, __FILE__, __LINE__);
    t.cmp_eq(a, d, 8, __FILE__, __LINE__);

    t.cmp_eq(a_2, b_2, 8, __FILE__, __LINE__);
    t.cmp_eq(a_2, c_2, 8, __FILE__, __LINE__);
    t.cmp_eq(a_2, d_2, 8, __FILE__, __LINE__);

    t.cmp_eq(a_3, b_3, 8, __FILE__, __LINE__);
    t.cmp_eq(a_3, c_3, 8, __FILE__, __LINE__);
    t.cmp_eq(a_3, d_3, 8, __FILE__, __LINE__);

    t.cmp_exp(sizeof(a) == sizeof(b), true, __FILE__, __LINE__);
    t.cmp_exp(sizeof(a) == sizeof(c), true, __FILE__, __LINE__);
    t.cmp_exp(sizeof(a) == sizeof(d), true, __FILE__, __LINE__);

    t.cmp_exp(sizeof(a_2) == sizeof(b_2), true, __FILE__, __LINE__);
    t.cmp_exp(sizeof(a_2) == sizeof(c_2), true, __FILE__, __LINE__);
    t.cmp_exp(sizeof(a_2) == sizeof(d_2), true, __FILE__, __LINE__);

    t.cmp_exp(sizeof(a_3) == sizeof(b_3), true, __FILE__, __LINE__);
    t.cmp_exp(sizeof(a_3) == sizeof(c_3), true, __FILE__, __LINE__);
    t.cmp_exp(sizeof(a_3) == sizeof(d_3), true, __FILE__, __LINE__);

    return t.get_final_verdict("INTEGRAL CONSTRUCTOR");
}