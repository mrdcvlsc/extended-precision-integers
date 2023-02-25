#include "epi.hpp"
#include "small_test.hpp"
#include <assert.h>
#include <bitset>
#include <iostream>
#include <vector>

typedef epi::number<uint8_t, uint16_t, 8>  uint64_8t;
typedef epi::number<uint16_t, uint32_t, 4> uint64_16t;
typedef epi::number<uint32_t, uint64_t, 2> uint64_32t;

int main() {
  smlts::test t;

  std::cout << "----------------------------------------------\n";
  std::cout << "INTEGRAL CONSTRUCTOR : \n";
  {
    epi::number<uint32_t, uint64_t, 7> SHOULD_NOT_THROW_ERROR{0xff};
    t.cmp_ts<uint64_t, uint64_8t>();
    t.cmp_ts<uint64_t, uint64_16t>();
    t.cmp_ts<uint64_t, uint64_32t>();

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

    t.cmp_eq(a, b, 8);
    t.cmp_eq(a, c, 8);
    t.cmp_eq(a, d, 8);

    t.cmp_eq(a_2, b_2, 8);
    t.cmp_eq(a_2, c_2, 8);
    t.cmp_eq(a_2, d_2, 8);

    t.cmp_eq(a_3, b_3, 8);
    t.cmp_eq(a_3, c_3, 8);
    t.cmp_eq(a_3, d_3, 8);

    t.cmp_exp(sizeof(a) == sizeof(b), true, "integral constructor: sizeof(a) == sizeof(b), true");
    t.cmp_exp(sizeof(a) == sizeof(c), true, "integral constructor: sizeof(a) == sizeof(c), true");
    t.cmp_exp(sizeof(a) == sizeof(d), true, "integral constructor: sizeof(a) == sizeof(d), true");

    t.cmp_exp(sizeof(a_2) == sizeof(b_2), true, "integral constructor: sizeof(a_2) == sizeof(b_2), true");
    t.cmp_exp(sizeof(a_2) == sizeof(c_2), true, "integral constructor: sizeof(a_2) == sizeof(c_2), true");
    t.cmp_exp(sizeof(a_2) == sizeof(d_2), true, "integral constructor: sizeof(a_2) == sizeof(d_2), true");

    t.cmp_exp(sizeof(a_3) == sizeof(b_3), true, "integral constructor: sizeof(a_3) == sizeof(b_3), true");
    t.cmp_exp(sizeof(a_3) == sizeof(c_3), true, "integral constructor: sizeof(a_3) == sizeof(c_3), true");
    t.cmp_exp(sizeof(a_3) == sizeof(d_3), true, "integral constructor: sizeof(a_3) == sizeof(d_3), true");
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "INITIALIZER LIST CONSTRUCTOR : \n";
  {
    epi::number<uint32_t, uint64_t, 7> SHOULD_NOT_THROW_ERROR{0xff};
    t.cmp_ts<uint64_t, uint64_8t>();
    t.cmp_ts<uint64_t, uint64_16t>();
    t.cmp_ts<uint64_t, uint64_32t>();

    const uint64_t       a = 0xabcdef0123456789;
    constexpr uint64_8t  b = {0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89};
    constexpr uint64_16t c = {0xabcd, 0xef01, 0x2345, 0x6789};
    constexpr uint64_32t d = {0xabcdef01, 0x23456789};
    ;

    const uint64_t       a_2 = 0xdeadbeef;
    constexpr uint64_8t  b_2 = {0xde, 0xad, 0xbe, 0xef};
    constexpr uint64_16t c_2 = {0xdead, 0xbeef};
    constexpr uint64_32t d_2 = {0xdeadbeef};

    const uint64_t       a_3 = 0xcafebabe00000000;
    constexpr uint64_8t  b_3 = {0xca, 0xfe, 0xba, 0xbe, 0x00, 0x00, 0x00, 0x00};
    constexpr uint64_16t c_3 = {0xcafe, 0xbabe, 0x0000, 0x0000};
    constexpr uint64_32t d_3 = {0xcafebabe, 0x00000000};

    t.cmp_eq(a, b, 8);
    t.cmp_eq(a, c, 8);
    t.cmp_eq(a, d, 8);

    t.cmp_eq(a_2, b_2, 8);
    t.cmp_eq(a_2, c_2, 8);
    t.cmp_eq(a_2, d_2, 8);

    t.cmp_eq(a_3, b_3, 8);
    t.cmp_eq(a_3, c_3, 8);
    t.cmp_eq(a_3, d_3, 8);

    t.cmp_exp(sizeof(a) == sizeof(b), true, "initializer_list constructor: sizeof(a) == sizeof(b), true");
    t.cmp_exp(sizeof(a) == sizeof(c), true, "initializer_list constructor: sizeof(a) == sizeof(c), true");
    t.cmp_exp(sizeof(a) == sizeof(d), true, "initializer_list constructor: sizeof(a) == sizeof(d), true");

    t.cmp_exp(sizeof(a_2) == sizeof(b_2), true, "initializer_list constructor: sizeof(a_2) == sizeof(b_2), true");
    t.cmp_exp(sizeof(a_2) == sizeof(c_2), true, "initializer_list constructor: sizeof(a_2) == sizeof(c_2), true");
    t.cmp_exp(sizeof(a_2) == sizeof(d_2), true, "initializer_list constructor: sizeof(a_2) == sizeof(d_2), true");

    t.cmp_exp(sizeof(a_3) == sizeof(b_3), true, "initializer_list constructor: sizeof(a_3) == sizeof(b_3), true");
    t.cmp_exp(sizeof(a_3) == sizeof(c_3), true, "initializer_list constructor: sizeof(a_3) == sizeof(c_3), true");
    t.cmp_exp(sizeof(a_3) == sizeof(d_3), true, "initializer_list constructor: sizeof(a_3) == sizeof(d_3), true");
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "CONSTEXPR SHIFT OPERATORS : \n";
  {
    // left shifts
    {
      uint64_t POD = 0xdeadbeefcafebabe;
      uint64_t pod_c = POD >> 0, pod_d = POD >> 1, pod_e = POD >> 2, pod_f = POD >> 31, pod_g = POD >> 32,
               pod_h = POD >> 33, pod_i = POD >> 63;

      // uint64_t pod_a = POD >> -2, pod_b = POD >> -1, pod_c = POD >> 0, pod_d = POD >> 1, pod_e = POD >> 2,
      //          pod_f = POD >> 31, pod_g = POD >> 32, pod_h = POD >> 33, pod_i = POD >> 63, pod_j = POD >> 64,
      //          pod_k = POD >> 65, pod_l = POD >> 66;

      constexpr uint64_8t EPI = 0xdeadbeefcafebabe, c = EPI >> 0, d = EPI >> 1, e = EPI >> 2, f = EPI >> 31,
                          g = EPI >> 32, h = EPI >> 33, i = EPI >> 63;

      // constexpr uint64_8t EPI = 0xdeadbeefcafebabe, a = EPI >> -2, b = EPI >> -1, c = EPI >> 0, d = EPI >> 1,
      //                     e = EPI >> 2, f = EPI >> 31, g = EPI >> 32, h = EPI >> 33, i = EPI >> 63, j = EPI >> 64,
      //                     k = EPI >> 65, l = EPI >> 66;

      t.cmp_eq(POD, EPI, 8, "uint64_8t : POD == EPI");
      // t.cmp_eq(pod_a, a, 8, "uint64_8t >> -2 : pod_a == a");
      // t.cmp_eq(pod_b, b, 8, "uint64_8t >> -1 : pod_b == b");
      t.cmp_eq(pod_c, c, 8, "uint64_8t >> 0 : pod_c == c");
      t.cmp_eq(pod_d, d, 8, "uint64_8t >> 1 : pod_d == d");
      t.cmp_eq(pod_e, e, 8, "uint64_8t >> 2 : pod_e == e");
      t.cmp_eq(pod_f, f, 8, "uint64_8t >> 31 : pod_f == f");
      t.cmp_eq(pod_g, g, 8, "uint64_8t >> 32 : pod_g == g");
      t.cmp_eq(pod_h, h, 8, "uint64_8t >> 33 : pod_h == h");
      t.cmp_eq(pod_i, i, 8, "uint64_8t >> 63 : pod_i == i");
      // t.cmp_eq(pod_j, j, 8, "uint64_8t >> 64 : pod_j == j");
      // t.cmp_eq(pod_k, k, 8, "uint64_8t >> 65 : pod_k == k");
      // t.cmp_eq(pod_l, l, 8, "uint64_8t >> 66 : pod_l == l");
    }

    {
      uint64_t POD = 0xdeadbeefcafebabe;
      uint64_t pod_c = POD >> 0, pod_d = POD >> 1, pod_e = POD >> 2, pod_f = POD >> 31, pod_g = POD >> 32,
               pod_h = POD >> 33, pod_i = POD >> 63;

      // uint64_t pod_a = POD >> -2, pod_b = POD >> -1, pod_c = POD >> 0, pod_d = POD >> 1, pod_e = POD >> 2,
      //          pod_f = POD >> 31, pod_g = POD >> 32, pod_h = POD >> 33, pod_i = POD >> 63, pod_j = POD >> 64,
      //          pod_k = POD >> 65, pod_l = POD >> 66;

      constexpr uint64_16t EPI = 0xdeadbeefcafebabe, c = EPI >> 0, d = EPI >> 1, e = EPI >> 2, f = EPI >> 31,
                           g = EPI >> 32, h = EPI >> 33, i = EPI >> 63;

      // constexpr uint64_16t EPI = 0xdeadbeefcafebabe, a = EPI >> -2, b = EPI >> -1, c = EPI >> 0, d = EPI >> 1,
      //                      e = EPI >> 2, f = EPI >> 31, g = EPI >> 32, h = EPI >> 33, i = EPI >> 63, j = EPI >> 64,
      //                      k = EPI >> 65, l = EPI >> 66;

      t.cmp_eq(POD, EPI, 8, "uint64_8t : POD == EPI");
      // t.cmp_eq(pod_a, a, 8, "uint64_16t >> -2 : pod_a == a");
      // t.cmp_eq(pod_b, b, 8, "uint64_16t >> -1 : pod_b == b");
      t.cmp_eq(pod_c, c, 8, "uint64_16t >> 0 : pod_c == c");
      t.cmp_eq(pod_d, d, 8, "uint64_16t >> 1 : pod_d == d");
      t.cmp_eq(pod_e, e, 8, "uint64_16t >> 2 : pod_e == e");
      t.cmp_eq(pod_f, f, 8, "uint64_16t >> 31 : pod_f == f");
      t.cmp_eq(pod_g, g, 8, "uint64_16t >> 32 : pod_g == g");
      t.cmp_eq(pod_h, h, 8, "uint64_16t >> 33 : pod_h == h");
      t.cmp_eq(pod_i, i, 8, "uint64_16t >> 63 : pod_i == i");
      // t.cmp_eq(pod_j, j, 8, "uint64_16t >> 64 : pod_j == j");
      // t.cmp_eq(pod_k, k, 8, "uint64_16t >> 65 : pod_k == k");
      // t.cmp_eq(pod_l, l, 8, "uint64_16t >> 66 : pod_l == l");
    }

    {
      uint64_t POD = 0xdeadbeefcafebabe;
      uint64_t pod_c = POD >> 0, pod_d = POD >> 1, pod_e = POD >> 2, pod_f = POD >> 31, pod_g = POD >> 32,
               pod_h = POD >> 33, pod_i = POD >> 63;

      // uint64_t pod_a = POD >> -2, pod_b = POD >> -1, pod_c = POD >> 0, pod_d = POD >> 1, pod_e = POD >> 2,
      //          pod_f = POD >> 31, pod_g = POD >> 32, pod_h = POD >> 33, pod_i = POD >> 63, pod_j = POD >> 64,
      //          pod_k = POD >> 65, pod_l = POD >> 66;

      constexpr uint64_32t EPI = 0xdeadbeefcafebabe, c = EPI >> 0, d = EPI >> 1, e = EPI >> 2, f = EPI >> 31,
                           g = EPI >> 32, h = EPI >> 33, i = EPI >> 63;

      // constexpr uint64_32t EPI = 0xdeadbeefcafebabe, a = EPI >> -2, b = EPI >> -1, c = EPI >> 0, d = EPI >> 1,
      //                      e = EPI >> 2, f = EPI >> 31, g = EPI >> 32, h = EPI >> 33, i = EPI >> 63, j = EPI >> 64,
      //                      k = EPI >> 65, l = EPI >> 66;

      t.cmp_eq(POD, EPI, 8, "uint64_8t : POD == EPI");
      // t.cmp_eq(pod_a, a, 8, "uint64_32t >> -2 : pod_a == a");
      // t.cmp_eq(pod_b, b, 8, "uint64_32t >> -1 : pod_b == b");
      t.cmp_eq(pod_c, c, 8, "uint64_32t >> 0 : pod_c == c");
      t.cmp_eq(pod_d, d, 8, "uint64_32t >> 1 : pod_d == d");
      t.cmp_eq(pod_e, e, 8, "uint64_32t >> 2 : pod_e == e");
      t.cmp_eq(pod_f, f, 8, "uint64_32t >> 31 : pod_f == f");
      t.cmp_eq(pod_g, g, 8, "uint64_32t >> 32 : pod_g == g");
      t.cmp_eq(pod_h, h, 8, "uint64_32t >> 33 : pod_h == h");
      t.cmp_eq(pod_i, i, 8, "uint64_32t >> 63 : pod_i == i");
      // t.cmp_eq(pod_j, j, 8, "uint64_32t >> 64 : pod_j == j");
      // t.cmp_eq(pod_k, k, 8, "uint64_32t >> 65 : pod_k == k");
      // t.cmp_eq(pod_l, l, 8, "uint64_32t >> 66 : pod_l == l");
    }

    // right shifts
    {
      // uint64_t POD = 0xdeadbeefcafebabe;
      // uint64_t pod_a = POD << -2, pod_b = POD << -1, pod_c = POD << 0, pod_d = POD << 1, pod_e = POD << 2,
      //          pod_f = POD << 31, pod_g = POD << 32, pod_h = POD << 33, pod_i = POD << 63, pod_j = POD << 64,
      //          pod_k = POD << 65, pod_l = POD << 66;

      uint64_t POD = 0xdeadbeefcafebabe;
      uint64_t pod_c = POD << 0, pod_d = POD << 1, pod_e = POD << 2, pod_f = POD << 31, pod_g = POD << 32,
               pod_h = POD << 33, pod_i = POD << 63;

      constexpr uint64_8t EPI = 0xdeadbeefcafebabe, c = EPI << 0, d = EPI << 1, e = EPI << 2, f = EPI << 31,
                          g = EPI << 32, h = EPI << 33, i = EPI << 63;

      // constexpr uint64_8t EPI = 0xdeadbeefcafebabe, a = EPI << -2, b = EPI << -1, c = EPI << 0, d = EPI << 1,
      //                     e = EPI << 2, f = EPI << 31, g = EPI << 32, h = EPI << 33, i = EPI << 63, j = EPI << 64,
      //                     k = EPI << 65, l = EPI << 66;

      t.cmp_eq(POD, EPI, 8, "uint64_8t : POD == EPI");
      // t.cmp_eq(pod_a, a, 8, "uint64_8t << -2 : pod_a == a");
      // t.cmp_eq(pod_b, b, 8, "uint64_8t << -1 : pod_b == b");
      t.cmp_eq(pod_c, c, 8, "uint64_8t << 0 : pod_c == c");
      t.cmp_eq(pod_d, d, 8, "uint64_8t << 1 : pod_d == d");
      t.cmp_eq(pod_e, e, 8, "uint64_8t << 2 : pod_e == e");
      t.cmp_eq(pod_f, f, 8, "uint64_8t << 31 : pod_f == f");
      t.cmp_eq(pod_g, g, 8, "uint64_8t << 32 : pod_g == g");
      t.cmp_eq(pod_h, h, 8, "uint64_8t << 33 : pod_h == h");
      t.cmp_eq(pod_i, i, 8, "uint64_8t << 63 : pod_i == i");
      // t.cmp_eq(pod_j, j, 8, "uint64_8t << 64 : pod_j == j");
      // t.cmp_eq(pod_k, k, 8, "uint64_8t << 65 : pod_k == k");
      // t.cmp_eq(pod_l, l, 8, "uint64_8t << 66 : pod_l == l");
    }

    {
      // uint64_t POD = 0xdeadbeefcafebabe;
      // uint64_t pod_a = POD << -2, pod_b = POD << -1, pod_c = POD << 0, pod_d = POD << 1, pod_e = POD << 2,
      //          pod_f = POD << 31, pod_g = POD << 32, pod_h = POD << 33, pod_i = POD << 63, pod_j = POD << 64,
      //          pod_k = POD << 65, pod_l = POD << 66;

      uint64_t POD = 0xdeadbeefcafebabe;
      uint64_t pod_c = POD << 0, pod_d = POD << 1, pod_e = POD << 2, pod_f = POD << 31, pod_g = POD << 32,
               pod_h = POD << 33, pod_i = POD << 63;

      constexpr uint64_16t EPI = 0xdeadbeefcafebabe, c = EPI << 0, d = EPI << 1, e = EPI << 2, f = EPI << 31,
                           g = EPI << 32, h = EPI << 33, i = EPI << 63;

      // constexpr uint64_16t EPI = 0xdeadbeefcafebabe, a = EPI << -2, b = EPI << -1, c = EPI << 0, d = EPI << 1,
      //                      e = EPI << 2, f = EPI << 31, g = EPI << 32, h = EPI << 33, i = EPI << 63, j = EPI << 64,
      //                      k = EPI << 65, l = EPI << 66;

      t.cmp_eq(POD, EPI, 8, "uint64_8t : POD == EPI");
      // t.cmp_eq(pod_a, a, 8, "uint64_16t << -2 : pod_a == a");
      // t.cmp_eq(pod_b, b, 8, "uint64_16t << -1 : pod_b == b");
      t.cmp_eq(pod_c, c, 8, "uint64_16t << 0 : pod_c == c");
      t.cmp_eq(pod_d, d, 8, "uint64_16t << 1 : pod_d == d");
      t.cmp_eq(pod_e, e, 8, "uint64_16t << 2 : pod_e == e");
      t.cmp_eq(pod_f, f, 8, "uint64_16t << 31 : pod_f == f");
      t.cmp_eq(pod_g, g, 8, "uint64_16t << 32 : pod_g == g");
      t.cmp_eq(pod_h, h, 8, "uint64_16t << 33 : pod_h == h");
      t.cmp_eq(pod_i, i, 8, "uint64_16t << 63 : pod_i == i");
      // t.cmp_eq(pod_j, j, 8, "uint64_16t << 64 : pod_j == j");
      // t.cmp_eq(pod_k, k, 8, "uint64_16t << 65 : pod_k == k");
      // t.cmp_eq(pod_l, l, 8, "uint64_16t << 66 : pod_l == l");
    }

    {
      // uint64_t POD = 0xdeadbeefcafebabe;
      // uint64_t pod_a = POD << -2, pod_b = POD << -1, pod_c = POD << 0, pod_d = POD << 1, pod_e = POD << 2,
      //          pod_f = POD << 31, pod_g = POD << 32, pod_h = POD << 33, pod_i = POD << 63, pod_j = POD << 64,
      //          pod_k = POD << 65, pod_l = POD << 66;

      uint64_t POD = 0xdeadbeefcafebabe;
      uint64_t pod_c = POD << 0, pod_d = POD << 1, pod_e = POD << 2, pod_f = POD << 31, pod_g = POD << 32,
               pod_h = POD << 33, pod_i = POD << 63;

      constexpr uint64_32t EPI = 0xdeadbeefcafebabe, c = EPI << 0, d = EPI << 1, e = EPI << 2, f = EPI << 31,
                           g = EPI << 32, h = EPI << 33, i = EPI << 63;

      // constexpr uint64_32t EPI = 0xdeadbeefcafebabe, a = EPI << -2, b = EPI << -1, c = EPI << 0, d = EPI << 1,
      //                      e = EPI << 2, f = EPI << 31, g = EPI << 32, h = EPI << 33, i = EPI << 63, j = EPI << 64,
      //                      k = EPI << 65, l = EPI << 66;

      t.cmp_eq(POD, EPI, 8, "uint64_8t : POD == EPI");
      // t.cmp_eq(pod_a, a, 8, "uint64_32t << -2 : pod_a == a");
      // t.cmp_eq(pod_b, b, 8, "uint64_32t << -1 : pod_b == b");
      t.cmp_eq(pod_c, c, 8, "uint64_32t << 0 : pod_c == c");
      t.cmp_eq(pod_d, d, 8, "uint64_32t << 1 : pod_d == d");
      t.cmp_eq(pod_e, e, 8, "uint64_32t << 2 : pod_e == e");
      t.cmp_eq(pod_f, f, 8, "uint64_32t << 31 : pod_f == f");
      t.cmp_eq(pod_g, g, 8, "uint64_32t << 32 : pod_g == g");
      t.cmp_eq(pod_h, h, 8, "uint64_32t << 33 : pod_h == h");
      t.cmp_eq(pod_i, i, 8, "uint64_32t << 63 : pod_i == i");
      // t.cmp_eq(pod_j, j, 8, "uint64_32t << 64 : pod_j == j");
      // t.cmp_eq(pod_k, k, 8, "uint64_32t << 65 : pod_k == k");
      // t.cmp_eq(pod_l, l, 8, "uint64_32t << 66 : pod_l == l");
    }
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "SHIFT OPERATORS : \n";
  {
    const uint64_t PODs[8] = {
      0xdeadbeefcafebabe,
      0xffffffffffffffff,
      0xffffffff00000000,
      0xffffffffffffffff,
      0xabcdef0123456789,
      0x9876543210fedcba,
      0b1010101010101010101010101010101010101010101010101010101010101010,
      0b101010101010101010101010101010101010101010101010101010101010101};
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
        t.cmp_eq(PODs[i], EPIs[i], 8, "t.cmp_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          t.cmp_eq(
            PODs[i] << j, EPIs[i] << j, 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  |  uint64_8t << shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          t.cmp_eq(
            PODs[i] >> j, EPIs[i] >> j, 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  |  uint64_8t >> shift = " + std::to_string(j)
          );
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
        t.cmp_eq(PODs[i], EPIs[i], 8, "t.cmp_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          t.cmp_eq(
            PODs[i] << j, EPIs[i] << j, 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  | uint64_16t << shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          t.cmp_eq(
            PODs[i] >> j, EPIs[i] >> j, 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  | uint64_16t >> shift = " + std::to_string(j)
          );
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
        t.cmp_eq(PODs[i], EPIs[i], 8, "t.cmp_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          t.cmp_eq(
            PODs[i] << j, EPIs[i] << j, 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  | uint64_32t << shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          t.cmp_eq(
            PODs[i] >> j, EPIs[i] >> j, 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  | uint64_32t >> shift = " + std::to_string(j)
          );
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
        t.cmp_eq(PODs[i], EPIs[i], 8, "t.cmp_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_8t test = EPIs[i];
          t.cmp_eq(
            PODs[i] << j, (test <<= j), 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  |  uint64_8t <<= shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_8t test = EPIs[i];
          t.cmp_eq(
            PODs[i] >> j, (test >>= j), 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  |  uint64_8t >>= shift = " + std::to_string(j)
          );
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
        t.cmp_eq(PODs[i], EPIs[i], 8, "t.cmp_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_16t test = EPIs[i];
          t.cmp_eq(
            PODs[i] << j, (test <<= j), 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  |  uint64_16t <<= shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_16t test = EPIs[i];
          t.cmp_eq(
            PODs[i] >> j, (test >>= j), 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  |  uint64_16t >>= shift = " + std::to_string(j)
          );
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
        t.cmp_eq(PODs[i], EPIs[i], 8, "t.cmp_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_32t test = EPIs[i];
          t.cmp_eq(
            PODs[i] << j, (test <<= j), 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  |  uint64_32t <<= shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_32t test = EPIs[i];
          t.cmp_eq(
            PODs[i] >> j, (test >>= j), 8,
            "t.cmp_eq : iter = " + std::to_string(i) + "  |  uint64_32t >>= shift = " + std::to_string(j)
          );
        }
      }
    }
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "RELATIONAL OPERATORS : \n";
  {
    {
      constexpr uint64_8t a = (uint64_t) 0x0;
      constexpr uint64_8t b = (uint64_t) 0x1;
      constexpr uint64_8t c = (uint64_t) 0xff;
      constexpr uint64_8t d = (uint64_t) 0xffff;
      constexpr uint64_8t e = (uint64_t) 0xffffffff;
      constexpr uint64_8t f = (uint64_t) 0xffffffffffffffff;

      std::cout << "constexpr uint64_8t a = " << std::hex << a << "\n";
      std::cout << "constexpr uint64_8t b = " << std::hex << b << "\n";
      std::cout << "constexpr uint64_8t c = " << std::hex << c << "\n";
      std::cout << "constexpr uint64_8t d = " << std::hex << d << "\n";
      std::cout << "constexpr uint64_8t e = " << std::hex << e << "\n";
      std::cout << "constexpr uint64_8t f = " << std::hex << f << "\n";

      t.cmp_eq(a, (uint64_t) 0x0, 8);
      t.cmp_eq(b, (uint64_t) 0x1, 8);
      t.cmp_eq(c, (uint64_t) 0xff, 8);
      t.cmp_eq(d, (uint64_t) 0xffff, 8);
      t.cmp_eq(e, (uint64_t) 0xffffffff, 8);
      t.cmp_eq(f, (uint64_t) 0xffffffffffffffff, 8);

      constexpr bool a_l_b = a < b;
      constexpr bool a_le_b = a <= b;
      constexpr bool b_l_c = b < c;
      constexpr bool b_le_c = b <= c;
      constexpr bool c_l_d = c < d;
      constexpr bool c_le_d = c <= d;
      constexpr bool d_l_e = d < e;
      constexpr bool d_le_e = d <= e;
      constexpr bool e_l_f = e < f;
      constexpr bool e_le_f = e <= f;
      constexpr bool a_g_b = a > b;
      constexpr bool a_ge_b = a >= b;
      constexpr bool b_g_c = b > c;
      constexpr bool b_ge_c = b >= c;
      constexpr bool c_g_d = c > d;
      constexpr bool c_ge_d = c >= d;
      constexpr bool d_g_e = d > e;
      constexpr bool d_ge_e = d >= e;
      constexpr bool e_g_f = e > f;
      constexpr bool e_ge_f = e >= f;
      constexpr bool b_l_a = b < a;
      constexpr bool b_le_a = b <= a;
      constexpr bool c_l_b = c < b;
      constexpr bool c_le_b = c <= b;
      constexpr bool d_l_c = d < c;
      constexpr bool d_le_c = d <= c;
      constexpr bool e_l_d = e < d;
      constexpr bool e_le_d = e <= d;
      constexpr bool f_l_e = f < e;
      constexpr bool f_le_e = f <= e;
      constexpr bool b_g_a = b > a;
      constexpr bool b_ge_a = b >= a;
      constexpr bool c_g_b = c > b;
      constexpr bool c_ge_b = c >= b;
      constexpr bool d_g_c = d > c;
      constexpr bool d_ge_c = d >= c;
      constexpr bool e_g_d = e > d;
      constexpr bool e_ge_d = e >= d;
      constexpr bool f_g_e = f > e;
      constexpr bool f_ge_e = f >= e;
      constexpr bool a_eq_a = a == a;
      constexpr bool b_eq_b = b == b;
      constexpr bool c_eq_c = c == c;
      constexpr bool d_eq_d = d == d;
      constexpr bool e_eq_e = e == e;
      constexpr bool f_eq_f = f == f;
      constexpr bool a_le_a = a <= a;
      constexpr bool b_le_b = b <= b;
      constexpr bool c_le_c = c <= c;
      constexpr bool d_le_d = d <= d;
      constexpr bool e_le_e = e <= e;
      constexpr bool f_le_f = f <= f;
      constexpr bool a_ge_a = a >= a;
      constexpr bool b_ge_b = b >= b;
      constexpr bool c_ge_c = c >= c;
      constexpr bool d_ge_d = d >= d;
      constexpr bool e_ge_e = e >= e;
      constexpr bool f_ge_f = f >= f;

      t.cmp_exp(a_l_b, true, "a < b, true");
      t.cmp_exp(a_le_b, true, "a <= b, true");
      t.cmp_exp(b_l_c, true, "b < c, true");
      t.cmp_exp(b_le_c, true, "b <= c, true");
      t.cmp_exp(c_l_d, true, "c < d, true");
      t.cmp_exp(c_le_d, true, "c <= d, true");
      t.cmp_exp(d_l_e, true, "d < e, true");
      t.cmp_exp(d_le_e, true, "d <= e, true");
      t.cmp_exp(e_l_f, true, "e < f, true");
      t.cmp_exp(e_le_f, true, "e <= f, true");

      t.cmp_exp(a_g_b, false, "a > b, false");
      t.cmp_exp(a_ge_b, false, "a >= b, false");
      t.cmp_exp(b_g_c, false, "b > c, false");
      t.cmp_exp(b_ge_c, false, "b >= c, false");
      t.cmp_exp(c_g_d, false, "c > d, false");
      t.cmp_exp(c_ge_d, false, "c >= d, false");
      t.cmp_exp(d_g_e, false, "d > e, false");
      t.cmp_exp(d_ge_e, false, "d >= e, false");
      t.cmp_exp(e_g_f, false, "e > f, false");
      t.cmp_exp(e_ge_f, false, "e >= f, false");

      t.cmp_exp(b_l_a, false, "b < a, false");
      t.cmp_exp(b_le_a, false, "b <= a, false");
      t.cmp_exp(c_l_b, false, "c < b, false");
      t.cmp_exp(c_le_b, false, "c <= b, false");
      t.cmp_exp(d_l_c, false, "d < c, false");
      t.cmp_exp(d_le_c, false, "d <= c, false");
      t.cmp_exp(e_l_d, false, "e < d, false");
      t.cmp_exp(e_le_d, false, "e <= d, false");
      t.cmp_exp(f_l_e, false, "f < e, false");
      t.cmp_exp(f_le_e, false, "f <= e, false");

      t.cmp_exp(b_g_a, true, "b > a, true");
      t.cmp_exp(b_ge_a, true, "b >= a, true");
      t.cmp_exp(c_g_b, true, "c > b, true");
      t.cmp_exp(c_ge_b, true, "c >= b, true");
      t.cmp_exp(d_g_c, true, "d > c, true");
      t.cmp_exp(d_ge_c, true, "d >= c, true");
      t.cmp_exp(e_g_d, true, "e > d, true");
      t.cmp_exp(e_ge_d, true, "e >= d, true");
      t.cmp_exp(f_g_e, true, "f > e, true");
      t.cmp_exp(f_ge_e, true, "f >= e, true");

      t.cmp_exp(a_eq_a, true, "a == a, true");
      t.cmp_exp(b_eq_b, true, "b == b, true");
      t.cmp_exp(c_eq_c, true, "c == c, true");
      t.cmp_exp(d_eq_d, true, "d == d, true");
      t.cmp_exp(e_eq_e, true, "e == e, true");
      t.cmp_exp(f_eq_f, true, "f == f, true");

      t.cmp_exp(a_le_a, true, "a <= a, true");
      t.cmp_exp(b_le_b, true, "b <= b, true");
      t.cmp_exp(c_le_c, true, "c <= c, true");
      t.cmp_exp(d_le_d, true, "d <= d, true");
      t.cmp_exp(e_le_e, true, "e <= e, true");
      t.cmp_exp(f_le_f, true, "f <= f, true");

      t.cmp_exp(a_ge_a, true, "a >= a, true");
      t.cmp_exp(b_ge_b, true, "b >= b, true");
      t.cmp_exp(c_ge_c, true, "c >= c, true");
      t.cmp_exp(d_ge_d, true, "d >= d, true");
      t.cmp_exp(e_ge_e, true, "e >= e, true");
      t.cmp_exp(f_ge_f, true, "f >= f, true");
    }

    {
      constexpr uint64_16t a = (uint64_t) 0x0;
      constexpr uint64_16t b = (uint64_t) 0x1;
      constexpr uint64_16t c = (uint64_t) 0xff;
      constexpr uint64_16t d = (uint64_t) 0xffff;
      constexpr uint64_16t e = (uint64_t) 0xffffffff;
      constexpr uint64_16t f = (uint64_t) 0xffffffffffffffff;

      std::cout << "uint64_316t a = " << std::hex << a << "\n";
      std::cout << "uint64_316t b = " << std::hex << b << "\n";
      std::cout << "uint64_316t c = " << std::hex << c << "\n";
      std::cout << "uint64_316t d = " << std::hex << d << "\n";
      std::cout << "uint64_316t e = " << std::hex << e << "\n";
      std::cout << "uint64_316t f = " << std::hex << f << "\n";

      t.cmp_eq(a, (uint64_t) 0x0, 8);
      t.cmp_eq(b, (uint64_t) 0x1, 8);
      t.cmp_eq(c, (uint64_t) 0xff, 8);
      t.cmp_eq(d, (uint64_t) 0xffff, 8);
      t.cmp_eq(e, (uint64_t) 0xffffffff, 8);
      t.cmp_eq(f, (uint64_t) 0xffffffffffffffff, 8);

      t.cmp_exp(a < b, true, "a < b, true");
      t.cmp_exp(a <= b, true, "a <= b, true");
      t.cmp_exp(b < c, true, "b < c, true");
      t.cmp_exp(b <= c, true, "b <= c, true");
      t.cmp_exp(c < d, true, "c < d, true");
      t.cmp_exp(c <= d, true, "c <= d, true");
      t.cmp_exp(d < e, true, "d < e, true");
      t.cmp_exp(d <= e, true, "d <= e, true");
      t.cmp_exp(e < f, true, "e < f, true");
      t.cmp_exp(e <= f, true, "e <= f, true");

      t.cmp_exp(a > b, false, "a > b, false");
      t.cmp_exp(a >= b, false, "a >= b, false");
      t.cmp_exp(b > c, false, "b > c, false");
      t.cmp_exp(b >= c, false, "b >= c, false");
      t.cmp_exp(c > d, false, "c > d, false");
      t.cmp_exp(c >= d, false, "c >= d, false");
      t.cmp_exp(d > e, false, "d > e, false");
      t.cmp_exp(d >= e, false, "d >= e, false");
      t.cmp_exp(e > f, false, "e > f, false");
      t.cmp_exp(e >= f, false, "e >= f, false");

      t.cmp_exp(b < a, false, "b < a, false");
      t.cmp_exp(b <= a, false, "b <= a, false");
      t.cmp_exp(c < b, false, "c < b, false");
      t.cmp_exp(c <= b, false, "c <= b, false");
      t.cmp_exp(d < c, false, "d < c, false");
      t.cmp_exp(d <= c, false, "d <= c, false");
      t.cmp_exp(e < d, false, "e < d, false");
      t.cmp_exp(e <= d, false, "e <= d, false");
      t.cmp_exp(f < e, false, "f < e, false");
      t.cmp_exp(f <= e, false, "f <= e, false");

      t.cmp_exp(b > a, true, "b > a, true");
      t.cmp_exp(b >= a, true, "b >= a, true");
      t.cmp_exp(c > b, true, "c > b, true");
      t.cmp_exp(c >= b, true, "c >= b, true");
      t.cmp_exp(d > c, true, "d > c, true");
      t.cmp_exp(d >= c, true, "d >= c, true");
      t.cmp_exp(e > d, true, "e > d, true");
      t.cmp_exp(e >= d, true, "e >= d, true");
      t.cmp_exp(f > e, true, "f > e, true");
      t.cmp_exp(f >= e, true, "f >= e, true");

      t.cmp_exp(a == a, true, "a == a, true");
      t.cmp_exp(b == b, true, "b == b, true");
      t.cmp_exp(c == c, true, "c == c, true");
      t.cmp_exp(d == d, true, "d == d, true");
      t.cmp_exp(e == e, true, "e == e, true");
      t.cmp_exp(f == f, true, "f == f, true");

      t.cmp_exp(a <= a, true, "a <= a, true");
      t.cmp_exp(b <= b, true, "b <= b, true");
      t.cmp_exp(c <= c, true, "c <= c, true");
      t.cmp_exp(d <= d, true, "d <= d, true");
      t.cmp_exp(e <= e, true, "e <= e, true");
      t.cmp_exp(f <= f, true, "f <= f, true");

      t.cmp_exp(a >= a, true, "a >= a, true");
      t.cmp_exp(b >= b, true, "b >= b, true");
      t.cmp_exp(c >= c, true, "c >= c, true");
      t.cmp_exp(d >= d, true, "d >= d, true");
      t.cmp_exp(e >= e, true, "e >= e, true");
      t.cmp_exp(f >= f, true, "f >= f, true");
    }

    {
      constexpr uint64_32t a = (uint64_t) 0x0;
      constexpr uint64_32t b = (uint64_t) 0x1;
      constexpr uint64_32t c = (uint64_t) 0xff;
      constexpr uint64_32t d = (uint64_t) 0xffff;
      constexpr uint64_32t e = (uint64_t) 0xffffffff;
      constexpr uint64_32t f = (uint64_t) 0xffffffffffffffff;

      std::cout << "uint64_32t a = " << std::hex << a << "\n";
      std::cout << "uint64_32t b = " << std::hex << b << "\n";
      std::cout << "uint64_32t c = " << std::hex << c << "\n";
      std::cout << "uint64_32t d = " << std::hex << d << "\n";
      std::cout << "uint64_32t e = " << std::hex << e << "\n";
      std::cout << "uint64_32t f = " << std::hex << f << "\n";

      t.cmp_eq(a, (uint64_t) 0x0, 8);
      t.cmp_eq(b, (uint64_t) 0x1, 8);
      t.cmp_eq(c, (uint64_t) 0xff, 8);
      t.cmp_eq(d, (uint64_t) 0xffff, 8);
      t.cmp_eq(e, (uint64_t) 0xffffffff, 8);
      t.cmp_eq(f, (uint64_t) 0xffffffffffffffff, 8);

      t.cmp_exp(a < b, true, "a < b, true");
      t.cmp_exp(a <= b, true, "a <= b, true");
      t.cmp_exp(b < c, true, "b < c, true");
      t.cmp_exp(b <= c, true, "b <= c, true");
      t.cmp_exp(c < d, true, "c < d, true");
      t.cmp_exp(c <= d, true, "c <= d, true");
      t.cmp_exp(d < e, true, "d < e, true");
      t.cmp_exp(d <= e, true, "d <= e, true");
      t.cmp_exp(e < f, true, "e < f, true");
      t.cmp_exp(e <= f, true, "e <= f, true");

      t.cmp_exp(a > b, false, "a > b, false");
      t.cmp_exp(a >= b, false, "a >= b, false");
      t.cmp_exp(b > c, false, "b > c, false");
      t.cmp_exp(b >= c, false, "b >= c, false");
      t.cmp_exp(c > d, false, "c > d, false");
      t.cmp_exp(c >= d, false, "c >= d, false");
      t.cmp_exp(d > e, false, "d > e, false");
      t.cmp_exp(d >= e, false, "d >= e, false");
      t.cmp_exp(e > f, false, "e > f, false");
      t.cmp_exp(e >= f, false, "e >= f, false");

      t.cmp_exp(b < a, false, "b < a, false");
      t.cmp_exp(b <= a, false, "b <= a, false");
      t.cmp_exp(c < b, false, "c < b, false");
      t.cmp_exp(c <= b, false, "c <= b, false");
      t.cmp_exp(d < c, false, "d < c, false");
      t.cmp_exp(d <= c, false, "d <= c, false");
      t.cmp_exp(e < d, false, "e < d, false");
      t.cmp_exp(e <= d, false, "e <= d, false");
      t.cmp_exp(f < e, false, "f < e, false");
      t.cmp_exp(f <= e, false, "f <= e, false");

      t.cmp_exp(b > a, true, "b > a, true");
      t.cmp_exp(b >= a, true, "b >= a, true");
      t.cmp_exp(c > b, true, "c > b, true");
      t.cmp_exp(c >= b, true, "c >= b, true");
      t.cmp_exp(d > c, true, "d > c, true");
      t.cmp_exp(d >= c, true, "d >= c, true");
      t.cmp_exp(e > d, true, "e > d, true");
      t.cmp_exp(e >= d, true, "e >= d, true");
      t.cmp_exp(f > e, true, "f > e, true");
      t.cmp_exp(f >= e, true, "f >= e, true");

      t.cmp_exp(a == a, true, "a == a, true");
      t.cmp_exp(b == b, true, "b == b, true");
      t.cmp_exp(c == c, true, "c == c, true");
      t.cmp_exp(d == d, true, "d == d, true");
      t.cmp_exp(e == e, true, "e == e, true");
      t.cmp_exp(f == f, true, "f == f, true");

      t.cmp_exp(a <= a, true, "a <= a, true");
      t.cmp_exp(b <= b, true, "b <= b, true");
      t.cmp_exp(c <= c, true, "c <= c, true");
      t.cmp_exp(d <= d, true, "d <= d, true");
      t.cmp_exp(e <= e, true, "e <= e, true");
      t.cmp_exp(f <= f, true, "f <= f, true");

      t.cmp_exp(a >= a, true, "a >= a, true");
      t.cmp_exp(b >= b, true, "b >= b, true");
      t.cmp_exp(c >= c, true, "c >= c, true");
      t.cmp_exp(d >= d, true, "d >= d, true");
      t.cmp_exp(e >= e, true, "e >= e, true");
      t.cmp_exp(f >= f, true, "f >= f, true");
    }
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "BASIC ADDITIONS : \n";
  {
    {
      uint64_t a = 0xffffffffffffffff, b = 0x1, c = 0xffffffff, x = a + b, y = a + c, z = a + a, m = b + c,
               v = 0xfffffffffffffff, av = a + v;

      constexpr uint64_8t a_8t = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, b_8t = {0x1},
                          c_8t = {0xff, 0xff, 0xff, 0xff}, x_8t = a_8t + b_8t, y_8t = a_8t + c_8t, z_8t = a_8t + a_8t,
                          m_8t = b_8t + c_8t, v_8t = {0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
                          av_8t = a_8t + v_8t;

      t.cmp_eq(a, a_8t, 8);
      t.cmp_eq(b, b_8t, 8);
      t.cmp_eq(c, c_8t, 8);

      t.cmp_eq(x, x_8t, 8);
      t.cmp_eq(y, y_8t, 8);
      t.cmp_eq(z, z_8t, 8);
      t.cmp_eq(m, m_8t, 8);
      t.cmp_eq(v, v_8t, 8);
      t.cmp_eq(av, av_8t, 8);

      uint64_8t a_b = a_8t, a_c = a_8t, a_a = a_8t, a_v = a_8t;

      a_b += b_8t;
      a_c += c_8t;
      a_a += a_8t;
      a_v += v_8t;

      t.cmp_eq(x, a_b, 8);
      t.cmp_eq(y, a_c, 8);
      t.cmp_eq(z, a_a, 8);
      t.cmp_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff, b = 0x1, c = 0xffffffff, x = a + b, y = a + c, z = a + a, m = b + c,
               v = 0xfffffffffffffff, av = a + v;

      constexpr uint64_16t a_8t = {0xffff, 0xffff, 0xffff, 0xffff}, b_8t = {0x1}, c_8t = {0xffff, 0xffff},
                           x_8t = a_8t + b_8t, y_8t = a_8t + c_8t, z_8t = a_8t + a_8t, m_8t = b_8t + c_8t,
                           v_8t = {0xfff, 0xffff, 0xffff, 0xffff}, av_8t = a_8t + v_8t;

      t.cmp_eq(a, a_8t, 8);
      t.cmp_eq(b, b_8t, 8);
      t.cmp_eq(c, c_8t, 8);

      t.cmp_eq(x, x_8t, 8);
      t.cmp_eq(y, y_8t, 8);
      t.cmp_eq(z, z_8t, 8);
      t.cmp_eq(m, m_8t, 8);
      t.cmp_eq(v, v_8t, 8);
      t.cmp_eq(av, av_8t, 8);

      uint64_16t a_b = a_8t, a_c = a_8t, a_a = a_8t, a_v = a_8t;

      a_b += b_8t;
      a_c += c_8t;
      a_a += a_8t;
      a_v += v_8t;

      t.cmp_eq(x, a_b, 8);
      t.cmp_eq(y, a_c, 8);
      t.cmp_eq(z, a_a, 8);
      t.cmp_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff, b = 0x1, c = 0xffffffff, x = a + b, y = a + c, z = a + a, m = b + c,
               v = 0xfffffffffffffff, av = a + v;

      constexpr uint64_32t a_8t = {0xffffffff, 0xffffffff}, b_8t = {0x1}, c_8t = {0xffffffff}, x_8t = a_8t + b_8t,
                           y_8t = a_8t + c_8t, z_8t = a_8t + a_8t, m_8t = b_8t + c_8t, v_8t = {0xfffffff, 0xffffffff},
                           av_8t = a_8t + v_8t;

      t.cmp_eq(a, a_8t, 8);
      t.cmp_eq(b, b_8t, 8);
      t.cmp_eq(c, c_8t, 8);

      t.cmp_eq(x, x_8t, 8);
      t.cmp_eq(y, y_8t, 8);
      t.cmp_eq(z, z_8t, 8);
      t.cmp_eq(m, m_8t, 8);
      t.cmp_eq(v, v_8t, 8);
      t.cmp_eq(av, av_8t, 8);

      uint64_32t a_b = a_8t, a_c = a_8t, a_a = a_8t, a_v = a_8t;

      a_b += b_8t;
      a_c += c_8t;
      a_a += a_8t;
      a_v += v_8t;

      t.cmp_eq(x, a_b, 8);
      t.cmp_eq(y, a_c, 8);
      t.cmp_eq(z, a_a, 8);
      t.cmp_eq(av, a_v, 8);
    }
  }

  // #############################################################
  std::cout << "\n----------------------------------------------\n";
  std::cout << "BASIC SUBTRACTIONS\n";
  {
    {
      uint64_t a = 0xffffffffffffffff, b = 0x1, c = 0xffffffff, x = a - b, y = a - c, z = a - a, m = b - c,
               v = 0xfffffffffffffff, av = a - v;

      constexpr uint64_8t a_8t = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, b_8t = {0x1},
                          c_8t = {0xff, 0xff, 0xff, 0xff}, x_8t = a_8t - b_8t, y_8t = a_8t - c_8t, z_8t = a_8t - a_8t,
                          m_8t = b_8t - c_8t, v_8t = {0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
                          av_8t = a_8t - v_8t;

      t.cmp_eq(a, a_8t, 8);
      t.cmp_eq(b, b_8t, 8);
      t.cmp_eq(c, c_8t, 8);

      t.cmp_eq(x, x_8t, 8);
      t.cmp_eq(y, y_8t, 8);
      t.cmp_eq(z, z_8t, 8);
      t.cmp_eq(m, m_8t, 8);
      t.cmp_eq(v, v_8t, 8);
      t.cmp_eq(av, av_8t, 8);

      uint64_8t a_b = a_8t, a_c = a_8t, a_a = a_8t, a_v = a_8t;

      a_b -= b_8t;
      a_c -= c_8t;
      a_a -= a_8t;
      a_v -= v_8t;

      t.cmp_eq(x, a_b, 8);
      t.cmp_eq(y, a_c, 8);
      t.cmp_eq(z, a_a, 8);
      t.cmp_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff, b = 0x1, c = 0xffffffff, x = a - b, y = a - c, z = a - a, m = b - c,
               v = 0xfffffffffffffff, av = a - v;

      constexpr uint64_16t a_8t = {0xffff, 0xffff, 0xffff, 0xffff}, b_8t = {0x1}, c_8t = {0xffff, 0xffff},
                           x_8t = a_8t - b_8t, y_8t = a_8t - c_8t, z_8t = a_8t - a_8t, m_8t = b_8t - c_8t,
                           v_8t = {0xfff, 0xffff, 0xffff, 0xffff}, av_8t = a_8t - v_8t;

      t.cmp_eq(a, a_8t, 8);
      t.cmp_eq(b, b_8t, 8);
      t.cmp_eq(c, c_8t, 8);

      t.cmp_eq(x, x_8t, 8);
      t.cmp_eq(y, y_8t, 8);
      t.cmp_eq(z, z_8t, 8);
      t.cmp_eq(m, m_8t, 8);
      t.cmp_eq(v, v_8t, 8);
      t.cmp_eq(av, av_8t, 8);

      uint64_16t a_b = a_8t, a_c = a_8t, a_a = a_8t, a_v = a_8t;

      a_b -= b_8t;
      a_c -= c_8t;
      a_a -= a_8t;
      a_v -= v_8t;

      t.cmp_eq(x, a_b, 8);
      t.cmp_eq(y, a_c, 8);
      t.cmp_eq(z, a_a, 8);
      t.cmp_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff, b = 0x1, c = 0xffffffff, x = a - b, y = a - c, z = a - a, m = b - c,
               v = 0xfffffffffffffff, av = a - v;

      constexpr uint64_32t a_8t = {0xffffffff, 0xffffffff}, b_8t = {0x1}, c_8t = {0xffffffff}, x_8t = a_8t - b_8t,
                           y_8t = a_8t - c_8t, z_8t = a_8t - a_8t, m_8t = b_8t - c_8t, v_8t = {0xfffffff, 0xffffffff},
                           av_8t = a_8t - v_8t;

      t.cmp_eq(a, a_8t, 8);
      t.cmp_eq(b, b_8t, 8);
      t.cmp_eq(c, c_8t, 8);

      t.cmp_eq(x, x_8t, 8);
      t.cmp_eq(y, y_8t, 8);
      t.cmp_eq(z, z_8t, 8);
      t.cmp_eq(m, m_8t, 8);
      t.cmp_eq(v, v_8t, 8);
      t.cmp_eq(av, av_8t, 8);

      uint64_32t a_b = a_8t, a_c = a_8t, a_a = a_8t, a_v = a_8t;

      a_b -= b_8t;
      a_c -= c_8t;
      a_a -= a_8t;
      a_v -= v_8t;

      t.cmp_eq(x, a_b, 8);
      t.cmp_eq(y, a_c, 8);
      t.cmp_eq(z, a_a, 8);
      t.cmp_eq(av, a_v, 8);
    }
  }

  // #############################################################
  std::cout << "\n----------------------------------------------\n";
  std::cout << "BASIC MULTIPLICATION\n";
  {
    {
      uint64_t a = 0xffffffffffffffff, b = 0x1, c = 0xffffffff, x = a * b, y = a * c, z = a * a, m = b * c,
               v = 0xfffffffffffffff, av = a * v;

      constexpr uint64_8t a_8t = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, b_8t = {0x1},
                          c_8t = {0xff, 0xff, 0xff, 0xff}, x_8t = a_8t * b_8t, y_8t = a_8t * c_8t, z_8t = a_8t * a_8t,
                          m_8t = b_8t * c_8t, v_8t = {0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
                          av_8t = a_8t * v_8t;

      t.cmp_eq(a, a_8t, 8);
      t.cmp_eq(b, b_8t, 8);
      t.cmp_eq(c, c_8t, 8);

      t.cmp_eq(x, x_8t, 8);
      t.cmp_eq(y, y_8t, 8);
      t.cmp_eq(z, z_8t, 8);
      t.cmp_eq(m, m_8t, 8);
      t.cmp_eq(v, v_8t, 8);
      t.cmp_eq(av, av_8t, 8);

      uint64_8t a_b = a_8t, a_c = a_8t, a_a = a_8t, a_v = a_8t;

      a_b *= b_8t;
      a_c *= c_8t;
      a_a *= a_8t;
      a_v *= v_8t;

      t.cmp_eq(x, a_b, 8);
      t.cmp_eq(y, a_c, 8);
      t.cmp_eq(z, a_a, 8);
      t.cmp_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff, b = 0x1, c = 0xffffffff, x = a * b, y = a * c, z = a * a, m = b * c,
               v = 0xfffffffffffffff, av = a * v;

      constexpr uint64_16t a_8t = {0xffff, 0xffff, 0xffff, 0xffff}, b_8t = {0x1}, c_8t = {0xffff, 0xffff},
                           x_8t = a_8t * b_8t, y_8t = a_8t * c_8t, z_8t = a_8t * a_8t, m_8t = b_8t * c_8t,
                           v_8t = {0xfff, 0xffff, 0xffff, 0xffff}, av_8t = a_8t * v_8t;

      t.cmp_eq(a, a_8t, 8);
      t.cmp_eq(b, b_8t, 8);
      t.cmp_eq(c, c_8t, 8);

      t.cmp_eq(x, x_8t, 8);
      t.cmp_eq(y, y_8t, 8);
      t.cmp_eq(z, z_8t, 8);
      t.cmp_eq(m, m_8t, 8);
      t.cmp_eq(v, v_8t, 8);
      t.cmp_eq(av, av_8t, 8);

      uint64_16t a_b = a_8t, a_c = a_8t, a_a = a_8t, a_v = a_8t;

      a_b *= b_8t;
      a_c *= c_8t;
      a_a *= a_8t;
      a_v *= v_8t;

      t.cmp_eq(x, a_b, 8);
      t.cmp_eq(y, a_c, 8);
      t.cmp_eq(z, a_a, 8);
      t.cmp_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff, b = 0x1, c = 0xffffffff, x = a * b, y = a * c, z = a * a, m = b * c,
               v = 0xfffffffffffffff, av = a * v;

      constexpr uint64_32t a_8t = {0xffffffff, 0xffffffff}, b_8t = {0x1}, c_8t = {0xffffffff}, x_8t = a_8t * b_8t,
                           y_8t = a_8t * c_8t, z_8t = a_8t * a_8t, m_8t = b_8t * c_8t, v_8t = {0xfffffff, 0xffffffff},
                           av_8t = a_8t * v_8t;

      t.cmp_eq(a, a_8t, 8);
      t.cmp_eq(b, b_8t, 8);
      t.cmp_eq(c, c_8t, 8);

      t.cmp_eq(x, x_8t, 8);
      t.cmp_eq(y, y_8t, 8);
      t.cmp_eq(z, z_8t, 8);
      t.cmp_eq(m, m_8t, 8);
      t.cmp_eq(v, v_8t, 8);
      t.cmp_eq(av, av_8t, 8);

      uint64_32t a_b = a_8t, a_c = a_8t, a_a = a_8t, a_v = a_8t;

      a_b *= b_8t;
      a_c *= c_8t;
      a_a *= a_8t;
      a_v *= v_8t;

      t.cmp_eq(x, a_b, 8);
      t.cmp_eq(y, a_c, 8);
      t.cmp_eq(z, a_a, 8);
      t.cmp_eq(av, a_v, 8);
    }
  }

  return t.get_final_verdict();
}