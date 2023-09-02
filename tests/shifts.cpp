#include "../include/epi/epi.hpp"

#include <iostream>
#include <string>

#include "small_test.hpp"

typedef epi::whole_number<uint8_t, uint16_t, 64>  uint64_8t;
typedef epi::whole_number<uint16_t, uint32_t, 64> uint64_16t;
typedef epi::whole_number<uint32_t, uint64_t, 64> uint64_32t;

int main() {
    smlts::test t;

    const uint64_t CONSTEXPR_POD = 0xdeadbeefcafebabe;

    // uint64_t r_pod_a = CONSTEXPR_POD >> -2, r_pod_b = CONSTEXPR_POD >> -1, r_pod_c = CONSTEXPR_POD >> 0,
    //          r_pod_d = CONSTEXPR_POD >> 1, r_pod_e = CONSTEXPR_POD >> 2, r_pod_f = CONSTEXPR_POD >> 31,
    //          r_pod_g = CONSTEXPR_POD >> 32, r_pod_h = CONSTEXPR_POD >> 33, r_pod_i = CONSTEXPR_POD >> 63,
    //          r_pod_j = CONSTEXPR_POD >> 64, r_pod_k = CONSTEXPR_POD >> 65, r_pod_l = CONSTEXPR_POD >> 66;

    // uint64_t l_pod_a = CONSTEXPR_POD << -2, l_pod_b = CONSTEXPR_POD << -1, l_pod_c = CONSTEXPR_POD << 0,
    //          l_pod_d = CONSTEXPR_POD << 1, l_pod_e = CONSTEXPR_POD << 2, l_pod_f = CONSTEXPR_POD << 31,
    //          l_pod_g = CONSTEXPR_POD << 32, l_pod_h = CONSTEXPR_POD << 33, l_pod_i = CONSTEXPR_POD << 63,
    //          l_pod_j = CONSTEXPR_POD << 64, l_pod_k = CONSTEXPR_POD << 65, l_pod_l = CONSTEXPR_POD << 66;

    uint64_t r_pod_c = CONSTEXPR_POD >> 0, r_pod_d = CONSTEXPR_POD >> 1, r_pod_e = CONSTEXPR_POD >> 2,
             r_pod_f = CONSTEXPR_POD >> 31, r_pod_g = CONSTEXPR_POD >> 32, r_pod_h = CONSTEXPR_POD >> 33,
             r_pod_i = CONSTEXPR_POD >> 63;

    uint64_t l_pod_c = CONSTEXPR_POD << 0, l_pod_d = CONSTEXPR_POD << 1, l_pod_e = CONSTEXPR_POD << 2,
             l_pod_f = CONSTEXPR_POD << 31, l_pod_g = CONSTEXPR_POD << 32, l_pod_h = CONSTEXPR_POD << 33,
             l_pod_i = CONSTEXPR_POD << 63;

    // left shifts
    {
        constexpr uint64_8t EPI = 0xdeadbeefcafebabe;

        // constexpr uint64_8t a = EPI >> -2, b = EPI >> -1, c = EPI >> 0, d = EPI >> 1, e = EPI >> 2, f = EPI >> 31,
        //                     g = EPI >> 32, h = EPI >> 33, i = EPI >> 63, j = EPI >> 64, k = EPI >> 65, l = EPI >> 66;

        constexpr uint64_8t c = EPI >> 0, d = EPI >> 1, e = EPI >> 2, f = EPI >> 31, g = EPI >> 32, h = EPI >> 33,
                            i = EPI >> 63;

        t.cmp_eq(CONSTEXPR_POD, EPI, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_a, a, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_b, b, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_c, c, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_d, d, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_e, e, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_f, f, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_g, g, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_h, h, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_i, i, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_j, j, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_k, k, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_l, l, 8, __FILE__, __LINE__);
    }

    {
        constexpr uint64_16t EPI = 0xdeadbeefcafebabe;

        // constexpr uint64_16t a = EPI >> -2, b = EPI >> -1, c = EPI >> 0, d = EPI >> 1, e = EPI >> 2, f = EPI >> 31,
        //                      g = EPI >> 32, h = EPI >> 33, i = EPI >> 63, j = EPI >> 64, k = EPI >> 65, l = EPI >>
        //                      66;

        constexpr uint64_16t c = EPI >> 0, d = EPI >> 1, e = EPI >> 2, f = EPI >> 31, g = EPI >> 32, h = EPI >> 33,
                             i = EPI >> 63;

        t.cmp_eq(CONSTEXPR_POD, EPI, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_a, a, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_b, b, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_c, c, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_d, d, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_e, e, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_f, f, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_g, g, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_h, h, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_i, i, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_j, j, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_k, k, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_l, l, 8, __FILE__, __LINE__);
    }

    {
        constexpr uint64_32t EPI = 0xdeadbeefcafebabe;

        // constexpr uint64_32t a = EPI >> -2, b = EPI >> -1, c = EPI >> 0, d = EPI >> 1, e = EPI >> 2, f = EPI >> 31,
        //                      g = EPI >> 32, h = EPI >> 33, i = EPI >> 63, j = EPI >> 64, k = EPI >> 65, l = EPI >>
        //                      66;

        constexpr uint64_32t c = EPI >> 0, d = EPI >> 1, e = EPI >> 2, f = EPI >> 31, g = EPI >> 32, h = EPI >> 33,
                             i = EPI >> 63;

        t.cmp_eq(CONSTEXPR_POD, EPI, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_a, a, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_b, b, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_c, c, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_d, d, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_e, e, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_f, f, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_g, g, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_h, h, 8, __FILE__, __LINE__);
        t.cmp_eq(r_pod_i, i, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_j, j, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_k, k, 8, __FILE__, __LINE__);
        // t.cmp_eq(r_pod_l, l, 8, __FILE__, __LINE__);
    }

    // right shifts
    {
        constexpr uint64_8t EPI = 0xdeadbeefcafebabe;

        // constexpr uint64_8t a = EPI << -2, b = EPI << -1, c = EPI << 0, d = EPI << 1, e = EPI << 2, f = EPI << 31,
        //                     g = EPI << 32, h = EPI << 33, i = EPI << 63, j = EPI << 64, k = EPI << 65, l = EPI << 66;

        constexpr uint64_8t c = EPI << 0, d = EPI << 1, e = EPI << 2, f = EPI << 31, g = EPI << 32, h = EPI << 33,
                            i = EPI << 63;

        t.cmp_eq(CONSTEXPR_POD, EPI, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_a, a, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_b, b, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_c, c, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_d, d, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_e, e, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_f, f, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_g, g, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_h, h, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_i, i, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_j, j, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_k, k, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_l, l, 8, __FILE__, __LINE__);
    }

    {
        constexpr uint64_16t EPI = 0xdeadbeefcafebabe;

        // constexpr uint64_16t a = EPI << -2, b = EPI << -1, c = EPI << 0, d = EPI << 1, e = EPI << 2, f = EPI << 31,
        //                      g = EPI << 32, h = EPI << 33, i = EPI << 63, j = EPI << 64, k = EPI << 65, l = EPI <<
        //                      66;

        constexpr uint64_16t c = EPI << 0, d = EPI << 1, e = EPI << 2, f = EPI << 31, g = EPI << 32, h = EPI << 33,
                             i = EPI << 63;

        t.cmp_eq(CONSTEXPR_POD, EPI, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_a, a, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_b, b, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_c, c, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_d, d, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_e, e, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_f, f, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_g, g, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_h, h, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_i, i, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_j, j, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_k, k, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_l, l, 8, __FILE__, __LINE__);
    }

    {
        constexpr uint64_32t EPI = 0xdeadbeefcafebabe;

        // constexpr uint64_32t a = EPI << -2, b = EPI << -1, c = EPI << 0, d = EPI << 1, e = EPI << 2, f = EPI << 31,
        //                      g = EPI << 32, h = EPI << 33, i = EPI << 63, j = EPI << 64, k = EPI << 65, l = EPI <<
        //                      66;

        constexpr uint64_32t c = EPI << 0, d = EPI << 1, e = EPI << 2, f = EPI << 31, g = EPI << 32, h = EPI << 33,
                             i = EPI << 63;

        t.cmp_eq(CONSTEXPR_POD, EPI, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_a, a, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_b, b, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_c, c, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_d, d, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_e, e, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_f, f, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_g, g, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_h, h, 8, __FILE__, __LINE__);
        t.cmp_eq(l_pod_i, i, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_j, j, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_k, k, 8, __FILE__, __LINE__);
        // t.cmp_eq(l_pod_l, l, 8, __FILE__, __LINE__);
    }

    const uint64_t PODs[8] = {
      0xdeadbeefcafebabe,
      0xffffffffffffffff,
      0xffffffff00000000,
      0xffffffffffffffff,
      0xabcdef0123456789,
      0x9876543210fedcba,
      0b1010101010101010101010101010101010101010101010101010101010101010,
      0b101010101010101010101010101010101010101010101010101010101010101,
    };

    {
        constexpr uint64_8t EPIs[8] = {
          0xdeadbeefcafebabe,
          0xffffffffffffffff,
          0xffffffff00000000,
          0xffffffffffffffff,
          0xabcdef0123456789,
          0x9876543210fedcba,
          0b1010101010101010101010101010101010101010101010101010101010101010,
          0b101010101010101010101010101010101010101010101010101010101010101};

        for (size_t i = 0; i < 8; ++i) {
            t.cmp_eq(PODs[i], EPIs[i], 8, __FILE__, __LINE__);
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                t.cmp_eq(PODs[i] << j, EPIs[i] << j, 8, __FILE__, __LINE__);
            }
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                t.cmp_eq(PODs[i] >> j, EPIs[i] >> j, 8, __FILE__, __LINE__);
            }
        }
    }

    {
        constexpr uint64_16t EPIs[8] = {
          0xdeadbeefcafebabe,
          0xffffffffffffffff,
          0xffffffff00000000,
          0xffffffffffffffff,
          0xabcdef0123456789,
          0x9876543210fedcba,
          0b1010101010101010101010101010101010101010101010101010101010101010,
          0b101010101010101010101010101010101010101010101010101010101010101};

        for (size_t i = 0; i < 8; ++i) {
            t.cmp_eq(PODs[i], EPIs[i], 8, __FILE__, __LINE__);
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                t.cmp_eq(PODs[i] << j, EPIs[i] << j, 8, __FILE__, __LINE__);
            }
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                t.cmp_eq(PODs[i] >> j, EPIs[i] >> j, 8, __FILE__, __LINE__);
            }
        }
    }

    {
        constexpr uint64_32t EPIs[8] = {
          0xdeadbeefcafebabe,
          0xffffffffffffffff,
          0xffffffff00000000,
          0xffffffffffffffff,
          0xabcdef0123456789,
          0x9876543210fedcba,
          0b1010101010101010101010101010101010101010101010101010101010101010,
          0b101010101010101010101010101010101010101010101010101010101010101};

        for (size_t i = 0; i < 8; ++i) {
            t.cmp_eq(PODs[i], EPIs[i], 8, __FILE__, __LINE__);
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                t.cmp_eq(PODs[i] << j, EPIs[i] << j, 8, __FILE__, __LINE__);
            }
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                t.cmp_eq(PODs[i] >> j, EPIs[i] >> j, 8, __FILE__, __LINE__);
            }
        }
    }

    {
        constexpr uint64_8t EPIs[8] = {
          0xdeadbeefcafebabe,
          0xffffffffffffffff,
          0xffffffff00000000,
          0xffffffffffffffff,
          0xabcdef0123456789,
          0x9876543210fedcba,
          0b1010101010101010101010101010101010101010101010101010101010101010,
          0b101010101010101010101010101010101010101010101010101010101010101};

        for (size_t i = 0; i < 8; ++i) {
            t.cmp_eq(PODs[i], EPIs[i], 8, __FILE__, __LINE__);
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                uint64_8t test = EPIs[i];
                t.cmp_eq(PODs[i] << j, (test <<= j), 8, __FILE__, __LINE__);
            }
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                uint64_8t test = EPIs[i];
                t.cmp_eq(PODs[i] >> j, (test >>= j), 8, __FILE__, __LINE__);
            }
        }
    }

    {
        constexpr uint64_16t EPIs[8] = {
          0xdeadbeefcafebabe,
          0xffffffffffffffff,
          0xffffffff00000000,
          0xffffffffffffffff,
          0xabcdef0123456789,
          0x9876543210fedcba,
          0b1010101010101010101010101010101010101010101010101010101010101010,
          0b101010101010101010101010101010101010101010101010101010101010101};

        for (size_t i = 0; i < 8; ++i) {
            t.cmp_eq(PODs[i], EPIs[i], 8, __FILE__, __LINE__);
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                uint64_16t test = EPIs[i];
                t.cmp_eq(PODs[i] << j, (test <<= j), 8, __FILE__, __LINE__);
            }
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                uint64_16t test = EPIs[i];
                t.cmp_eq(PODs[i] >> j, (test >>= j), 8, __FILE__, __LINE__);
            }
        }
    }

    {
        constexpr uint64_32t EPIs[8] = {
          0xdeadbeefcafebabe,
          0xffffffffffffffff,
          0xffffffff00000000,
          0xffffffffffffffff,
          0xabcdef0123456789,
          0x9876543210fedcba,
          0b1010101010101010101010101010101010101010101010101010101010101010,
          0b101010101010101010101010101010101010101010101010101010101010101};

        for (size_t i = 0; i < 8; ++i) {
            t.cmp_eq(PODs[i], EPIs[i], 8, __FILE__, __LINE__);
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                uint64_32t test = EPIs[i];
                t.cmp_eq(PODs[i] << j, (test <<= j), 8, __FILE__, __LINE__);
            }
        }

        for (size_t i = 0; i < 8; i++) {
            // for (int j = -2; j < 66; ++j) {
            for (int j = 0; j < 63; ++j) {
                uint64_32t test = EPIs[i];
                t.cmp_eq(PODs[i] >> j, (test >>= j), 8, __FILE__, __LINE__);
            }
        }
    }

    return t.get_final_verdict("SHIFT OPERATIONS");
}