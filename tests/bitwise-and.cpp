#include <iostream>
#include <string>

#include "../include/epi/epi.hpp"
#include "small_test.hpp"

using uint64_8t = epi::whole_number<std::uint8_t, std::uint16_t, 64UL>;
using uint64_16t = epi::whole_number<std::uint16_t, std::uint32_t, 64UL>;
using uint64_32t = epi::whole_number<std::uint32_t, std::uint64_t, 64UL>;

int main() {
    smlts::test t;

    constexpr uint64_t a_pod = 0xdeadbeefcafebabe;
    constexpr uint64_t b_pod = 0xabcdef0123456789;

    constexpr uint64_8t  a_8t = a_pod, b_8t = b_pod;
    constexpr uint64_16t a_16t = a_pod, b_16t = b_pod;
    constexpr uint64_32t a_32t = a_pod, b_32t = b_pod;

    constexpr uint64_t   c_pod = a_pod & b_pod;
    constexpr uint64_8t  c_8t = a_8t & b_8t;
    constexpr uint64_16t c_16t = a_16t & b_16t;
    constexpr uint64_32t c_32t = a_32t & b_32t;

    t.cmp_eq(c_8t, c_pod, 8, __FILE__, __LINE__);
    t.cmp_eq(c_16t, c_pod, 8, __FILE__, __LINE__);
    t.cmp_eq(c_32t, c_pod, 8, __FILE__, __LINE__);

    constexpr uint64_t   d_pod = b_pod & a_pod;
    constexpr uint64_8t  d_8t = b_8t & a_8t;
    constexpr uint64_16t d_16t = b_16t & a_16t;
    constexpr uint64_32t d_32t = b_32t & a_32t;

    t.cmp_eq(d_8t, d_pod, 8, __FILE__, __LINE__);
    t.cmp_eq(d_16t, d_pod, 8, __FILE__, __LINE__);
    t.cmp_eq(d_32t, d_pod, 8, __FILE__, __LINE__);

    uint64_t   a_copy_pod = a_pod;
    uint64_8t  a_copy_8t = a_8t;
    uint64_16t a_copy_16t = a_16t;
    uint64_32t a_copy_32t = a_32t;

    a_copy_pod &= b_pod;
    a_copy_8t &= b_8t;
    a_copy_16t &= b_16t;
    a_copy_32t &= b_32t;

    t.cmp_eq(a_copy_8t, a_copy_pod, 8, __FILE__, __LINE__);
    t.cmp_eq(a_copy_16t, a_copy_pod, 8, __FILE__, __LINE__);
    t.cmp_eq(a_copy_32t, a_copy_pod, 8, __FILE__, __LINE__);

    uint64_t   mask_pod = 0xffffffffffffffff;
    uint64_8t  mask_8t = mask_pod;
    uint64_16t mask_16t = mask_pod;
    uint64_32t mask_32t = mask_pod;

    uint64_t   b_copy_pod = b_pod;
    uint64_8t  b_copy_8t = b_8t;
    uint64_16t b_copy_16t = b_16t;
    uint64_32t b_copy_32t = b_32t;

    b_copy_pod &= mask_pod;
    b_copy_8t &= mask_8t;
    b_copy_16t &= mask_16t;
    b_copy_32t &= mask_32t;

    t.cmp_eq(b_copy_8t, b_copy_pod, 8, __FILE__, __LINE__);
    t.cmp_eq(b_copy_16t, b_copy_pod, 8, __FILE__, __LINE__);
    t.cmp_eq(b_copy_32t, b_copy_pod, 8, __FILE__, __LINE__);

    return t.get_final_verdict("BITWISE AND");
}