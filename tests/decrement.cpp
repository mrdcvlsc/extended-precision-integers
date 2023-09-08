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
        uint64_t   test = 0x00;
        uint64_8t  test_8t = {0x00};
        uint64_8t  test_16t = {0x00};
        uint64_32t test_32t = {0x00};

        while (test < 200) {
            test--;
            test_8t--;
            test_16t--;
            test_32t--;
        }

        int comp1 = std::memcmp(&test, &test_8t, sizeof(uint64_t));
        int comp2 = std::memcmp(&test, &test_16t, sizeof(uint64_t));
        int comp3 = std::memcmp(&test, &test_32t, sizeof(uint64_t));

        t.cmp_exp(comp1 == 0, true, __FILE__, __LINE__);
        t.cmp_exp(comp2 == 0, true, __FILE__, __LINE__);
        t.cmp_exp(comp3 == 0, true, __FILE__, __LINE__);
    }

    {
        uint64_t   test = 0x00;
        uint64_8t  test_8t = {0x00};
        uint64_8t  test_16t = {0x00};
        uint64_32t test_32t = {0x00};

        while (test < 200) {
            --test;
            --test_8t;
            --test_16t;
            --test_32t;
        }

        int comp1 = std::memcmp(&test, &test_8t, sizeof(uint64_t));
        int comp2 = std::memcmp(&test, &test_16t, sizeof(uint64_t));
        int comp3 = std::memcmp(&test, &test_32t, sizeof(uint64_t));

        t.cmp_exp(comp1 == 0, true, __FILE__, __LINE__);
        t.cmp_exp(comp2 == 0, true, __FILE__, __LINE__);
        t.cmp_exp(comp3 == 0, true, __FILE__, __LINE__);
    }

    return t.get_final_verdict("DECREMENT");
}