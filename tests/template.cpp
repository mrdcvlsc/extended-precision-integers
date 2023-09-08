#include <iostream>
#include <string>

#include "../include/epi/epi.hpp"
#include "small_test.hpp"

using uint64_8t = epi::whole_number<std::uint8_t, std::uint16_t, 64UL>;
using uint64_16t = epi::whole_number<std::uint16_t, std::uint32_t, 64UL>;
using uint64_32t = epi::whole_number<std::uint32_t, std::uint64_t, 64UL>;

int main() {
    smlts::test t;

    return t.get_final_verdict("NO TEST JUST A TEMPLATE");
}