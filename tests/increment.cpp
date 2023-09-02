#include "../include/epi/epi.hpp"

#include <iostream>
#include <string>

#include "small_test.hpp"

typedef epi::whole_number<uint8_t, uint16_t, 64>  uint64_8t;
typedef epi::whole_number<uint16_t, uint32_t, 64> uint64_16t;
typedef epi::whole_number<uint32_t, uint64_t, 64> uint64_32t;

int main() {
    smlts::test t;

    {
        uint64_t   test = 0x00;
        uint64_8t  test_8t = {0x00};
        uint64_8t  test_16t = {0x00};
        uint64_32t test_32t = {0x00};

        while (test < 200) {
            test++;
            test_8t++;
            test_16t++;
            test_32t++;
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
            ++test;
            ++test_8t;
            ++test_16t;
            ++test_32t;
        }

        int comp1 = std::memcmp(&test, &test_8t, sizeof(uint64_t));
        int comp2 = std::memcmp(&test, &test_16t, sizeof(uint64_t));
        int comp3 = std::memcmp(&test, &test_32t, sizeof(uint64_t));

        t.cmp_exp(comp1 == 0, true, __FILE__, __LINE__);
        t.cmp_exp(comp2 == 0, true, __FILE__, __LINE__);
        t.cmp_exp(comp3 == 0, true, __FILE__, __LINE__);
    }

    return t.get_final_verdict("INCREMENT");
}