#include <iostream>
#include <string>

#include "../include/epi/epi.hpp"
#include "small_test.hpp"

using uint64_8t = epi::whole_number<std::uint8_t, std::uint16_t, 64UL>;
using uint64_16t = epi::whole_number<std::uint16_t, std::uint32_t, 64UL>;
using uint64_32t = epi::whole_number<std::uint32_t, std::uint64_t, 64UL>;

int main() {
    smlts::test t;

    const uint64_t       has_value_a = 0xabcdef0123456789;
    constexpr uint64_8t  has_value_b = has_value_a;
    constexpr uint64_16t has_value_c = has_value_a;
    constexpr uint64_32t has_value_d = has_value_a;

    const uint64_t       zero_value_a = 0x00;
    constexpr uint64_8t  zero_value_b = zero_value_a;
    constexpr uint64_16t zero_value_c = zero_value_a;
    constexpr uint64_32t zero_value_d = zero_value_a;

    if (has_value_b) {
        t.pass(__FILE__, __LINE__);
    } else {
        t.fail(__FILE__, __LINE__);
    }

    if (!zero_value_b) {
        t.pass(__FILE__, __LINE__);
    } else {
        t.fail(__FILE__, __LINE__);
    }

    if (has_value_c) {
        t.pass(__FILE__, __LINE__);
    } else {
        t.fail(__FILE__, __LINE__);
    }

    if (!zero_value_c) {
        t.pass(__FILE__, __LINE__);
    } else {
        t.fail(__FILE__, __LINE__);
    }

    if (has_value_d) {
        t.pass(__FILE__, __LINE__);
    } else {
        t.fail(__FILE__, __LINE__);
    }

    if (!zero_value_d) {
        t.pass(__FILE__, __LINE__);
    } else {
        t.fail(__FILE__, __LINE__);
    }

    // AND: BOTH TRUE
    if (has_value_b && has_value_b) {
        t.pass(__FILE__, __LINE__);
    } else {
        t.fail(__FILE__, __LINE__);
    }

    if (has_value_c && has_value_c) {
        t.pass(__FILE__, __LINE__);
    } else {
        t.fail(__FILE__, __LINE__);
    }

    if (has_value_d && has_value_d) {
        t.pass(__FILE__, __LINE__);
    } else {
        t.fail(__FILE__, __LINE__);
    }

    // AND: RIGHT FALSE, LEFT TRUE
    if (has_value_b && zero_value_b) {
        t.fail(__FILE__, __LINE__);
    } else {
        t.pass(__FILE__, __LINE__);
    }

    if (has_value_c && zero_value_c) {
        t.fail(__FILE__, __LINE__);
    } else {
        t.pass(__FILE__, __LINE__);
    }

    if (has_value_d && zero_value_d) {
        t.fail(__FILE__, __LINE__);
    } else {
        t.pass(__FILE__, __LINE__);
    }

    t.cmp_exp((bool) has_value_b, true, __FILE__, __LINE__);
    t.cmp_exp((bool) has_value_c, true, __FILE__, __LINE__);
    t.cmp_exp((bool) has_value_d, true, __FILE__, __LINE__);

    t.cmp_exp((bool) zero_value_b, false, __FILE__, __LINE__);
    t.cmp_exp((bool) zero_value_c, false, __FILE__, __LINE__);
    t.cmp_exp((bool) zero_value_d, false, __FILE__, __LINE__);

    return t.get_final_verdict("BOOLEAN OPERATOR");
}