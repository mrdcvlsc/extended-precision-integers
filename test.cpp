#include "epi.hpp"
#include <assert.h>
#include <bitset>
#include <iostream>
#include <vector>

#define PRINT_RESULT

typedef epi::number<uint8_t, uint16_t, 8> uint64_8t;
typedef epi::number<uint16_t, uint32_t, 4> uint64_16t;
typedef epi::number<uint32_t, uint64_t, 2> uint64_32t;

static std::vector<size_t> test_results;
static std::vector<size_t> failed_cases;
static size_t test_number = 0;
static int final_verdict = 0;

template <typename T1, typename T2>
void assert_eq(T1 a, T2 b, size_t numBytes, std::string test_name = "");

template <typename T1, typename T2>
void assert_types(std::string test_name = "");

void assert_exp(bool A, bool B, std::string test_name = "");

int main() {
  std::cout << "----------------------------------------------\n";
  std::cout << "INTEGRAL CONSTRUCTOR : \n";
  {
    epi::number<uint32_t, uint64_t, 7> SHOULD_NOT_THROW_ERROR{0xff};
    assert_types<uint64_t, uint64_8t>();
    assert_types<uint64_t, uint64_16t>();
    assert_types<uint64_t, uint64_32t>();

    const uint64_t a = 0xabcdef0123456789;
    constexpr uint64_8t b = a;
    constexpr uint64_16t c = a;
    constexpr uint64_32t d = a;

    const uint64_t a_2 = 0xdeadbeef;
    constexpr uint64_8t b_2 = a_2;
    constexpr uint64_16t c_2 = a_2;
    constexpr uint64_32t d_2 = a_2;

    const uint64_t a_3 = 0xcafebabe00000000;
    constexpr uint64_8t b_3 = a_3;
    constexpr uint64_16t c_3 = a_3;
    constexpr uint64_32t d_3 = a_3;

    assert_eq(a, b, 8);
    assert_eq(a, c, 8);
    assert_eq(a, d, 8);

    assert_eq(a_2, b_2, 8);
    assert_eq(a_2, c_2, 8);
    assert_eq(a_2, d_2, 8);

    assert_eq(a_3, b_3, 8);
    assert_eq(a_3, c_3, 8);
    assert_eq(a_3, d_3, 8);

    assert_exp(sizeof(a) == sizeof(b), true, "integral constructor: sizeof(a) == sizeof(b), true");
    assert_exp(sizeof(a) == sizeof(c), true, "integral constructor: sizeof(a) == sizeof(c), true");
    assert_exp(sizeof(a) == sizeof(d), true, "integral constructor: sizeof(a) == sizeof(d), true");

    assert_exp(sizeof(a_2) == sizeof(b_2), true, "integral constructor: sizeof(a_2) == sizeof(b_2), true");
    assert_exp(sizeof(a_2) == sizeof(c_2), true, "integral constructor: sizeof(a_2) == sizeof(c_2), true");
    assert_exp(sizeof(a_2) == sizeof(d_2), true, "integral constructor: sizeof(a_2) == sizeof(d_2), true");

    assert_exp(sizeof(a_3) == sizeof(b_3), true, "integral constructor: sizeof(a_3) == sizeof(b_3), true");
    assert_exp(sizeof(a_3) == sizeof(c_3), true, "integral constructor: sizeof(a_3) == sizeof(c_3), true");
    assert_exp(sizeof(a_3) == sizeof(d_3), true, "integral constructor: sizeof(a_3) == sizeof(d_3), true");
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "INITIALIZER LIST CONSTRUCTOR : \n";
  {
    epi::number<uint32_t, uint64_t, 7> SHOULD_NOT_THROW_ERROR{0xff};
    assert_types<uint64_t, uint64_8t>();
    assert_types<uint64_t, uint64_16t>();
    assert_types<uint64_t, uint64_32t>();

    const uint64_t a = 0xabcdef0123456789;
    constexpr uint64_8t b = { 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89 };
    constexpr uint64_16t c = { 0xabcd, 0xef01, 0x2345, 0x6789 };
    constexpr uint64_32t d = { 0xabcdef01, 0x23456789 };;

    const uint64_t a_2 = 0xdeadbeef;
    constexpr uint64_8t b_2 = { 0xde, 0xad, 0xbe, 0xef };
    constexpr uint64_16t c_2 = { 0xdead, 0xbeef };
    constexpr uint64_32t d_2 = { 0xdeadbeef };

    const uint64_t a_3 = 0xcafebabe00000000;
    constexpr uint64_8t b_3 = { 0xca, 0xfe, 0xba, 0xbe, 0x00, 0x00, 0x00, 0x00 };
    constexpr uint64_16t c_3 = { 0xcafe, 0xbabe, 0x0000, 0x0000 };
    constexpr uint64_32t d_3 = { 0xcafebabe, 0x00000000 };

    assert_eq(a, b, 8);
    assert_eq(a, c, 8);
    assert_eq(a, d, 8);

    assert_eq(a_2, b_2, 8);
    assert_eq(a_2, c_2, 8);
    assert_eq(a_2, d_2, 8);

    assert_eq(a_3, b_3, 8);
    assert_eq(a_3, c_3, 8);
    assert_eq(a_3, d_3, 8);

    assert_exp(sizeof(a) == sizeof(b), true, "initializer_list constructor: sizeof(a) == sizeof(b), true");
    assert_exp(sizeof(a) == sizeof(c), true, "initializer_list constructor: sizeof(a) == sizeof(c), true");
    assert_exp(sizeof(a) == sizeof(d), true, "initializer_list constructor: sizeof(a) == sizeof(d), true");

    assert_exp(sizeof(a_2) == sizeof(b_2), true, "initializer_list constructor: sizeof(a_2) == sizeof(b_2), true");
    assert_exp(sizeof(a_2) == sizeof(c_2), true, "initializer_list constructor: sizeof(a_2) == sizeof(c_2), true");
    assert_exp(sizeof(a_2) == sizeof(d_2), true, "initializer_list constructor: sizeof(a_2) == sizeof(d_2), true");

    assert_exp(sizeof(a_3) == sizeof(b_3), true, "initializer_list constructor: sizeof(a_3) == sizeof(b_3), true");
    assert_exp(sizeof(a_3) == sizeof(c_3), true, "initializer_list constructor: sizeof(a_3) == sizeof(c_3), true");
    assert_exp(sizeof(a_3) == sizeof(d_3), true, "initializer_list constructor: sizeof(a_3) == sizeof(d_3), true");
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "CONSTEXPR SHIFT OPERATORS : \n";
  {
    // left shifts
    {
      uint64_t POD = 0xdeadbeefcafebabe;
      constexpr uint64_8t EPI = 0xdeadbeefcafebabe;

      uint64_t pod_a = POD >> (size_t) -2;
      uint64_t pod_b = POD >> (size_t) -1;
      uint64_t pod_c = POD >> (size_t) 0;
      uint64_t pod_d = POD >> (size_t) 1;
      uint64_t pod_e = POD >> (size_t) 2;
      uint64_t pod_f = POD >> (size_t) 31;
      uint64_t pod_g = POD >> (size_t) 32;
      uint64_t pod_h = POD >> (size_t) 33;
      uint64_t pod_i = POD >> (size_t) 63;
      uint64_t pod_j = POD >> (size_t) 64;
      uint64_t pod_k = POD >> (size_t) 65;
      uint64_t pod_l = POD >> (size_t) 66;

      constexpr uint64_8t a = EPI >> (size_t) -2;
      constexpr uint64_8t b = EPI >> (size_t) -1;
      constexpr uint64_8t c = EPI >> (size_t) 0;
      constexpr uint64_8t d = EPI >> (size_t) 1;
      constexpr uint64_8t e = EPI >> (size_t) 2;
      constexpr uint64_8t f = EPI >> (size_t) 31;
      constexpr uint64_8t g = EPI >> (size_t) 32;
      constexpr uint64_8t h = EPI >> (size_t) 33;
      constexpr uint64_8t i = EPI >> (size_t) 63;
      constexpr uint64_8t j = EPI >> (size_t) 64;
      constexpr uint64_8t k = EPI >> (size_t) 65;
      constexpr uint64_8t l = EPI >> (size_t) 66;

      assert_eq(pod_a, a, 8, "uint64_8t >> : pod_a == a");
      assert_eq(pod_b, b, 8, "uint64_8t >> : pod_b == b");
      assert_eq(pod_c, c, 8, "uint64_8t >> : pod_c == c");
      assert_eq(pod_d, d, 8, "uint64_8t >> : pod_d == d");
      assert_eq(pod_e, e, 8, "uint64_8t >> : pod_e == e");
      assert_eq(pod_f, f, 8, "uint64_8t >> : pod_f == f");
      assert_eq(pod_g, g, 8, "uint64_8t >> : pod_g == g");
      assert_eq(pod_h, h, 8, "uint64_8t >> : pod_h == h");
      assert_eq(pod_i, i, 8, "uint64_8t >> : pod_i == i");
      assert_eq(pod_j, j, 8, "uint64_8t >> : pod_j == j");
      assert_eq(pod_k, k, 8, "uint64_8t >> : pod_k == k");
      assert_eq(pod_l, l, 8, "uint64_8t >> : pod_l == l");
    }

    {
      uint64_t POD = 0xdeadbeefcafebabe;
      constexpr uint64_16t EPI = 0xdeadbeefcafebabe;

      uint64_t pod_a = POD >> (size_t) -2;
      uint64_t pod_b = POD >> (size_t) -1;
      uint64_t pod_c = POD >> (size_t) 0;
      uint64_t pod_d = POD >> (size_t) 1;
      uint64_t pod_e = POD >> (size_t) 2;
      uint64_t pod_f = POD >> (size_t) 31;
      uint64_t pod_g = POD >> (size_t) 32;
      uint64_t pod_h = POD >> (size_t) 33;
      uint64_t pod_i = POD >> (size_t) 63;
      uint64_t pod_j = POD >> (size_t) 64;
      uint64_t pod_k = POD >> (size_t) 65;
      uint64_t pod_l = POD >> (size_t) 66;

      constexpr uint64_16t a = EPI >> (size_t) -2;
      constexpr uint64_16t b = EPI >> (size_t) -1;
      constexpr uint64_16t c = EPI >> (size_t) 0;
      constexpr uint64_16t d = EPI >> (size_t) 1;
      constexpr uint64_16t e = EPI >> (size_t) 2;
      constexpr uint64_16t f = EPI >> (size_t) 31;
      constexpr uint64_16t g = EPI >> (size_t) 32;
      constexpr uint64_16t h = EPI >> (size_t) 33;
      constexpr uint64_16t i = EPI >> (size_t) 63;
      constexpr uint64_16t j = EPI >> (size_t) 64;
      constexpr uint64_16t k = EPI >> (size_t) 65;
      constexpr uint64_16t l = EPI >> (size_t) 66;

      assert_eq(pod_a, a, 8, "uint64_16t >> : pod_a == a");
      assert_eq(pod_b, b, 8, "uint64_16t >> : pod_b == b");
      assert_eq(pod_c, c, 8, "uint64_16t >> : pod_c == c");
      assert_eq(pod_d, d, 8, "uint64_16t >> : pod_d == d");
      assert_eq(pod_e, e, 8, "uint64_16t >> : pod_e == e");
      assert_eq(pod_f, f, 8, "uint64_16t >> : pod_f == f");
      assert_eq(pod_g, g, 8, "uint64_16t >> : pod_g == g");
      assert_eq(pod_h, h, 8, "uint64_16t >> : pod_h == h");
      assert_eq(pod_i, i, 8, "uint64_16t >> : pod_i == i");
      assert_eq(pod_j, j, 8, "uint64_16t >> : pod_j == j");
      assert_eq(pod_k, k, 8, "uint64_16t >> : pod_k == k");
      assert_eq(pod_l, l, 8, "uint64_16t >> : pod_l == l");
    }

    {
      uint64_t POD = 0xdeadbeefcafebabe;
      constexpr uint64_32t EPI = 0xdeadbeefcafebabe;

      uint64_t pod_a = POD >> (size_t) -2;
      uint64_t pod_b = POD >> (size_t) -1;
      uint64_t pod_c = POD >> (size_t) 0;
      uint64_t pod_d = POD >> (size_t) 1;
      uint64_t pod_e = POD >> (size_t) 2;
      uint64_t pod_f = POD >> (size_t) 31;
      uint64_t pod_g = POD >> (size_t) 32;
      uint64_t pod_h = POD >> (size_t) 33;
      uint64_t pod_i = POD >> (size_t) 63;
      uint64_t pod_j = POD >> (size_t) 64;
      uint64_t pod_k = POD >> (size_t) 65;
      uint64_t pod_l = POD >> (size_t) 66;

      constexpr uint64_32t a = EPI >> (size_t) -2;
      constexpr uint64_32t b = EPI >> (size_t) -1;
      constexpr uint64_32t c = EPI >> (size_t) 0;
      constexpr uint64_32t d = EPI >> (size_t) 1;
      constexpr uint64_32t e = EPI >> (size_t) 2;
      constexpr uint64_32t f = EPI >> (size_t) 31;
      constexpr uint64_32t g = EPI >> (size_t) 32;
      constexpr uint64_32t h = EPI >> (size_t) 33;
      constexpr uint64_32t i = EPI >> (size_t) 63;
      constexpr uint64_32t j = EPI >> (size_t) 64;
      constexpr uint64_32t k = EPI >> (size_t) 65;
      constexpr uint64_32t l = EPI >> (size_t) 66;

      assert_eq(pod_a, a, 8, "uint64_32t >> : pod_a == a");
      assert_eq(pod_b, b, 8, "uint64_32t >> : pod_b == b");
      assert_eq(pod_c, c, 8, "uint64_32t >> : pod_c == c");
      assert_eq(pod_d, d, 8, "uint64_32t >> : pod_d == d");
      assert_eq(pod_e, e, 8, "uint64_32t >> : pod_e == e");
      assert_eq(pod_f, f, 8, "uint64_32t >> : pod_f == f");
      assert_eq(pod_g, g, 8, "uint64_32t >> : pod_g == g");
      assert_eq(pod_h, h, 8, "uint64_32t >> : pod_h == h");
      assert_eq(pod_i, i, 8, "uint64_32t >> : pod_i == i");
      assert_eq(pod_j, j, 8, "uint64_32t >> : pod_j == j");
      assert_eq(pod_k, k, 8, "uint64_32t >> : pod_k == k");
      assert_eq(pod_l, l, 8, "uint64_32t >> : pod_l == l");
    }

    // right shifts
    {
      uint64_t POD = 0xdeadbeefcafebabe;
      constexpr uint64_8t EPI = 0xdeadbeefcafebabe;

      uint64_t pod_a = POD << (size_t) -2;
      uint64_t pod_b = POD << (size_t) -1;
      uint64_t pod_c = POD << (size_t) 0;
      uint64_t pod_d = POD << (size_t) 1;
      uint64_t pod_e = POD << (size_t) 2;
      uint64_t pod_f = POD << (size_t) 31;
      uint64_t pod_g = POD << (size_t) 32;
      uint64_t pod_h = POD << (size_t) 33;
      uint64_t pod_i = POD << (size_t) 63;
      uint64_t pod_j = POD << (size_t) 64;
      uint64_t pod_k = POD << (size_t) 65;
      uint64_t pod_l = POD << (size_t) 66;

      constexpr uint64_8t a = EPI << (size_t) -2;
      constexpr uint64_8t b = EPI << (size_t) -1;
      constexpr uint64_8t c = EPI << (size_t) 0;
      constexpr uint64_8t d = EPI << (size_t) 1;
      constexpr uint64_8t e = EPI << (size_t) 2;
      constexpr uint64_8t f = EPI << (size_t) 31;
      constexpr uint64_8t g = EPI << (size_t) 32;
      constexpr uint64_8t h = EPI << (size_t) 33;
      constexpr uint64_8t i = EPI << (size_t) 63;
      constexpr uint64_8t j = EPI << (size_t) 64;
      constexpr uint64_8t k = EPI << (size_t) 65;
      constexpr uint64_8t l = EPI << (size_t) 66;

      assert_eq(pod_a, a, 8, "uint64_8t << : pod_a == a");
      assert_eq(pod_b, b, 8, "uint64_8t << : pod_b == b");
      assert_eq(pod_c, c, 8, "uint64_8t << : pod_c == c");
      assert_eq(pod_d, d, 8, "uint64_8t << : pod_d == d");
      assert_eq(pod_e, e, 8, "uint64_8t << : pod_e == e");
      assert_eq(pod_f, f, 8, "uint64_8t << : pod_f == f");
      assert_eq(pod_g, g, 8, "uint64_8t << : pod_g == g");
      assert_eq(pod_h, h, 8, "uint64_8t << : pod_h == h");
      assert_eq(pod_i, i, 8, "uint64_8t << : pod_i == i");
      assert_eq(pod_j, j, 8, "uint64_8t << : pod_j == j");
      assert_eq(pod_k, k, 8, "uint64_8t << : pod_k == k");
      assert_eq(pod_l, l, 8, "uint64_8t << : pod_l == l");
    }

    {
      uint64_t POD = 0xdeadbeefcafebabe;
      constexpr uint64_16t EPI = 0xdeadbeefcafebabe;

      uint64_t pod_a = POD << (size_t) -2;
      uint64_t pod_b = POD << (size_t) -1;
      uint64_t pod_c = POD << (size_t) 0;
      uint64_t pod_d = POD << (size_t) 1;
      uint64_t pod_e = POD << (size_t) 2;
      uint64_t pod_f = POD << (size_t) 31;
      uint64_t pod_g = POD << (size_t) 32;
      uint64_t pod_h = POD << (size_t) 33;
      uint64_t pod_i = POD << (size_t) 63;
      uint64_t pod_j = POD << (size_t) 64;
      uint64_t pod_k = POD << (size_t) 65;
      uint64_t pod_l = POD << (size_t) 66;

      constexpr uint64_16t a = EPI << (size_t) -2;
      constexpr uint64_16t b = EPI << (size_t) -1;
      constexpr uint64_16t c = EPI << (size_t) 0;
      constexpr uint64_16t d = EPI << (size_t) 1;
      constexpr uint64_16t e = EPI << (size_t) 2;
      constexpr uint64_16t f = EPI << (size_t) 31;
      constexpr uint64_16t g = EPI << (size_t) 32;
      constexpr uint64_16t h = EPI << (size_t) 33;
      constexpr uint64_16t i = EPI << (size_t) 63;
      constexpr uint64_16t j = EPI << (size_t) 64;
      constexpr uint64_16t k = EPI << (size_t) 65;
      constexpr uint64_16t l = EPI << (size_t) 66;

      assert_eq(pod_a, a, 8, "uint64_16t << : pod_a == a");
      assert_eq(pod_b, b, 8, "uint64_16t << : pod_b == b");
      assert_eq(pod_c, c, 8, "uint64_16t << : pod_c == c");
      assert_eq(pod_d, d, 8, "uint64_16t << : pod_d == d");
      assert_eq(pod_e, e, 8, "uint64_16t << : pod_e == e");
      assert_eq(pod_f, f, 8, "uint64_16t << : pod_f == f");
      assert_eq(pod_g, g, 8, "uint64_16t << : pod_g == g");
      assert_eq(pod_h, h, 8, "uint64_16t << : pod_h == h");
      assert_eq(pod_i, i, 8, "uint64_16t << : pod_i == i");
      assert_eq(pod_j, j, 8, "uint64_16t << : pod_j == j");
      assert_eq(pod_k, k, 8, "uint64_16t << : pod_k == k");
      assert_eq(pod_l, l, 8, "uint64_16t << : pod_l == l");
    }

    {
      uint64_t POD = 0xdeadbeefcafebabe;
      constexpr uint64_32t EPI = 0xdeadbeefcafebabe;

      uint64_t pod_a = POD << (size_t) -2;
      uint64_t pod_b = POD << (size_t) -1;
      uint64_t pod_c = POD << (size_t) 0;
      uint64_t pod_d = POD << (size_t) 1;
      uint64_t pod_e = POD << (size_t) 2;
      uint64_t pod_f = POD << (size_t) 31;
      uint64_t pod_g = POD << (size_t) 32;
      uint64_t pod_h = POD << (size_t) 33;
      uint64_t pod_i = POD << (size_t) 63;
      uint64_t pod_j = POD << (size_t) 64;
      uint64_t pod_k = POD << (size_t) 65;
      uint64_t pod_l = POD << (size_t) 66;

      constexpr uint64_32t a = EPI << (size_t) -2;
      constexpr uint64_32t b = EPI << (size_t) -1;
      constexpr uint64_32t c = EPI << (size_t) 0;
      constexpr uint64_32t d = EPI << (size_t) 1;
      constexpr uint64_32t e = EPI << (size_t) 2;
      constexpr uint64_32t f = EPI << (size_t) 31;
      constexpr uint64_32t g = EPI << (size_t) 32;
      constexpr uint64_32t h = EPI << (size_t) 33;
      constexpr uint64_32t i = EPI << (size_t) 63;
      constexpr uint64_32t j = EPI << (size_t) 64;
      constexpr uint64_32t k = EPI << (size_t) 65;
      constexpr uint64_32t l = EPI << (size_t) 66;

      assert_eq(pod_a, a, 8, "uint64_32t << : pod_a == a");
      assert_eq(pod_b, b, 8, "uint64_32t << : pod_b == b");
      assert_eq(pod_c, c, 8, "uint64_32t << : pod_c == c");
      assert_eq(pod_d, d, 8, "uint64_32t << : pod_d == d");
      assert_eq(pod_e, e, 8, "uint64_32t << : pod_e == e");
      assert_eq(pod_f, f, 8, "uint64_32t << : pod_f == f");
      assert_eq(pod_g, g, 8, "uint64_32t << : pod_g == g");
      assert_eq(pod_h, h, 8, "uint64_32t << : pod_h == h");
      assert_eq(pod_i, i, 8, "uint64_32t << : pod_i == i");
      assert_eq(pod_j, j, 8, "uint64_32t << : pod_j == j");
      assert_eq(pod_k, k, 8, "uint64_32t << : pod_k == k");
      assert_eq(pod_l, l, 8, "uint64_32t << : pod_l == l");
    }
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "SHIFT OPERATORS : \n";
  {
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
        assert_eq(PODs[i], EPIs[i], 8, "assert_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          assert_eq(
              PODs[i] << j, EPIs[i] << j, 8,
              "assert_eq : iter = " + std::to_string(i) + "  |  uint64_8t << shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          assert_eq(
              PODs[i] >> j, EPIs[i] >> j, 8,
              "assert_eq : iter = " + std::to_string(i) + "  |  uint64_8t >> shift = " + std::to_string(j)
          );
        }
      }
    }

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
        assert_eq(PODs[i], EPIs[i], 8, "assert_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          assert_eq(
              PODs[i] << j, EPIs[i] << j, 8,
              "assert_eq : iter = " + std::to_string(i) + "  | uint64_16t << shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          assert_eq(
              PODs[i] >> j, EPIs[i] >> j, 8,
              "assert_eq : iter = " + std::to_string(i) + "  | uint64_16t >> shift = " + std::to_string(j)
          );
        }
      }
    }

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
        assert_eq(PODs[i], EPIs[i], 8, "assert_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          assert_eq(
              PODs[i] << j, EPIs[i] << j, 8,
              "assert_eq : iter = " + std::to_string(i) + "  | uint64_32t << shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          assert_eq(
              PODs[i] >> j, EPIs[i] >> j, 8,
              "assert_eq : iter = " + std::to_string(i) + "  | uint64_32t >> shift = " + std::to_string(j)
          );
        }
      }
    }

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
        assert_eq(PODs[i], EPIs[i], 8, "assert_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_8t test = EPIs[i];
          assert_eq(
              PODs[i] << j, (test <<= j), 8,
              "assert_eq : iter = " + std::to_string(i) + "  |  uint64_8t <<= shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_8t test = EPIs[i];
          assert_eq(
              PODs[i] >> j, (test >>= j), 8,
              "assert_eq : iter = " + std::to_string(i) + "  |  uint64_8t >>= shift = " + std::to_string(j)
          );
        }
      }
    }

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
        assert_eq(PODs[i], EPIs[i], 8, "assert_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_16t test = EPIs[i];
          assert_eq(
              PODs[i] << j, (test <<= j), 8,
              "assert_eq : iter = " + std::to_string(i) + "  |  uint64_16t <<= shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_16t test = EPIs[i];
          assert_eq(
              PODs[i] >> j, (test >>= j), 8,
              "assert_eq : iter = " + std::to_string(i) + "  |  uint64_16t >>= shift = " + std::to_string(j)
          );
        }
      }
    }

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
        assert_eq(PODs[i], EPIs[i], 8, "assert_eq : iter = " + std::to_string(i));
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_32t test = EPIs[i];
          assert_eq(
              PODs[i] << j, (test <<= j), 8,
              "assert_eq : iter = " + std::to_string(i) + "  |  uint64_32t <<= shift = " + std::to_string(j)
          );
        }
      }

      for (size_t i = 0; i < 8; i++) {
        for (int j = -2; j < 66; ++j) {
          uint64_32t test = EPIs[i];
          assert_eq(
              PODs[i] >> j, (test >>= j), 8,
              "assert_eq : iter = " + std::to_string(i) + "  |  uint64_32t >>= shift = " + std::to_string(j)
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

      assert_eq(a, (uint64_t) 0x0, 8);
      assert_eq(b, (uint64_t) 0x1, 8);
      assert_eq(c, (uint64_t) 0xff, 8);
      assert_eq(d, (uint64_t) 0xffff, 8);
      assert_eq(e, (uint64_t) 0xffffffff, 8);
      assert_eq(f, (uint64_t) 0xffffffffffffffff, 8);

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

      assert_exp(a_l_b, true, "a < b, true");
      assert_exp(a_le_b, true, "a <= b, true");
      assert_exp(b_l_c, true, "b < c, true");
      assert_exp(b_le_c, true, "b <= c, true");
      assert_exp(c_l_d, true, "c < d, true");
      assert_exp(c_le_d, true, "c <= d, true");
      assert_exp(d_l_e, true, "d < e, true");
      assert_exp(d_le_e, true, "d <= e, true");
      assert_exp(e_l_f, true, "e < f, true");
      assert_exp(e_le_f, true, "e <= f, true");

      assert_exp(a_g_b, false, "a > b, false");
      assert_exp(a_ge_b, false, "a >= b, false");
      assert_exp(b_g_c, false, "b > c, false");
      assert_exp(b_ge_c, false, "b >= c, false");
      assert_exp(c_g_d, false, "c > d, false");
      assert_exp(c_ge_d, false, "c >= d, false");
      assert_exp(d_g_e, false, "d > e, false");
      assert_exp(d_ge_e, false, "d >= e, false");
      assert_exp(e_g_f, false, "e > f, false");
      assert_exp(e_ge_f, false, "e >= f, false");

      assert_exp(b_l_a, false, "b < a, false");
      assert_exp(b_le_a, false, "b <= a, false");
      assert_exp(c_l_b, false, "c < b, false");
      assert_exp(c_le_b, false, "c <= b, false");
      assert_exp(d_l_c, false, "d < c, false");
      assert_exp(d_le_c, false, "d <= c, false");
      assert_exp(e_l_d, false, "e < d, false");
      assert_exp(e_le_d, false, "e <= d, false");
      assert_exp(f_l_e, false, "f < e, false");
      assert_exp(f_le_e, false, "f <= e, false");

      assert_exp(b_g_a, true, "b > a, true");
      assert_exp(b_ge_a, true, "b >= a, true");
      assert_exp(c_g_b, true, "c > b, true");
      assert_exp(c_ge_b, true, "c >= b, true");
      assert_exp(d_g_c, true, "d > c, true");
      assert_exp(d_ge_c, true, "d >= c, true");
      assert_exp(e_g_d, true, "e > d, true");
      assert_exp(e_ge_d, true, "e >= d, true");
      assert_exp(f_g_e, true, "f > e, true");
      assert_exp(f_ge_e, true, "f >= e, true");

      assert_exp(a_eq_a, true, "a == a, true");
      assert_exp(b_eq_b, true, "b == b, true");
      assert_exp(c_eq_c, true, "c == c, true");
      assert_exp(d_eq_d, true, "d == d, true");
      assert_exp(e_eq_e, true, "e == e, true");
      assert_exp(f_eq_f, true, "f == f, true");

      assert_exp(a_le_a, true, "a <= a, true");
      assert_exp(b_le_b, true, "b <= b, true");
      assert_exp(c_le_c, true, "c <= c, true");
      assert_exp(d_le_d, true, "d <= d, true");
      assert_exp(e_le_e, true, "e <= e, true");
      assert_exp(f_le_f, true, "f <= f, true");

      assert_exp(a_ge_a, true, "a >= a, true");
      assert_exp(b_ge_b, true, "b >= b, true");
      assert_exp(c_ge_c, true, "c >= c, true");
      assert_exp(d_ge_d, true, "d >= d, true");
      assert_exp(e_ge_e, true, "e >= e, true");
      assert_exp(f_ge_f, true, "f >= f, true");
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

      assert_eq(a, (uint64_t) 0x0, 8);
      assert_eq(b, (uint64_t) 0x1, 8);
      assert_eq(c, (uint64_t) 0xff, 8);
      assert_eq(d, (uint64_t) 0xffff, 8);
      assert_eq(e, (uint64_t) 0xffffffff, 8);
      assert_eq(f, (uint64_t) 0xffffffffffffffff, 8);

      assert_exp(a < b, true, "a < b, true");
      assert_exp(a <= b, true, "a <= b, true");
      assert_exp(b < c, true, "b < c, true");
      assert_exp(b <= c, true, "b <= c, true");
      assert_exp(c < d, true, "c < d, true");
      assert_exp(c <= d, true, "c <= d, true");
      assert_exp(d < e, true, "d < e, true");
      assert_exp(d <= e, true, "d <= e, true");
      assert_exp(e < f, true, "e < f, true");
      assert_exp(e <= f, true, "e <= f, true");

      assert_exp(a > b, false, "a > b, false");
      assert_exp(a >= b, false, "a >= b, false");
      assert_exp(b > c, false, "b > c, false");
      assert_exp(b >= c, false, "b >= c, false");
      assert_exp(c > d, false, "c > d, false");
      assert_exp(c >= d, false, "c >= d, false");
      assert_exp(d > e, false, "d > e, false");
      assert_exp(d >= e, false, "d >= e, false");
      assert_exp(e > f, false, "e > f, false");
      assert_exp(e >= f, false, "e >= f, false");

      assert_exp(b < a, false, "b < a, false");
      assert_exp(b <= a, false, "b <= a, false");
      assert_exp(c < b, false, "c < b, false");
      assert_exp(c <= b, false, "c <= b, false");
      assert_exp(d < c, false, "d < c, false");
      assert_exp(d <= c, false, "d <= c, false");
      assert_exp(e < d, false, "e < d, false");
      assert_exp(e <= d, false, "e <= d, false");
      assert_exp(f < e, false, "f < e, false");
      assert_exp(f <= e, false, "f <= e, false");

      assert_exp(b > a, true, "b > a, true");
      assert_exp(b >= a, true, "b >= a, true");
      assert_exp(c > b, true, "c > b, true");
      assert_exp(c >= b, true, "c >= b, true");
      assert_exp(d > c, true, "d > c, true");
      assert_exp(d >= c, true, "d >= c, true");
      assert_exp(e > d, true, "e > d, true");
      assert_exp(e >= d, true, "e >= d, true");
      assert_exp(f > e, true, "f > e, true");
      assert_exp(f >= e, true, "f >= e, true");

      assert_exp(a == a, true, "a == a, true");
      assert_exp(b == b, true, "b == b, true");
      assert_exp(c == c, true, "c == c, true");
      assert_exp(d == d, true, "d == d, true");
      assert_exp(e == e, true, "e == e, true");
      assert_exp(f == f, true, "f == f, true");

      assert_exp(a <= a, true, "a <= a, true");
      assert_exp(b <= b, true, "b <= b, true");
      assert_exp(c <= c, true, "c <= c, true");
      assert_exp(d <= d, true, "d <= d, true");
      assert_exp(e <= e, true, "e <= e, true");
      assert_exp(f <= f, true, "f <= f, true");

      assert_exp(a >= a, true, "a >= a, true");
      assert_exp(b >= b, true, "b >= b, true");
      assert_exp(c >= c, true, "c >= c, true");
      assert_exp(d >= d, true, "d >= d, true");
      assert_exp(e >= e, true, "e >= e, true");
      assert_exp(f >= f, true, "f >= f, true");
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


      assert_eq(a, (uint64_t) 0x0, 8);
      assert_eq(b, (uint64_t) 0x1, 8);
      assert_eq(c, (uint64_t) 0xff, 8);
      assert_eq(d, (uint64_t) 0xffff, 8);
      assert_eq(e, (uint64_t) 0xffffffff, 8);
      assert_eq(f, (uint64_t) 0xffffffffffffffff, 8);

      assert_exp(a < b, true, "a < b, true");
      assert_exp(a <= b, true, "a <= b, true");
      assert_exp(b < c, true, "b < c, true");
      assert_exp(b <= c, true, "b <= c, true");
      assert_exp(c < d, true, "c < d, true");
      assert_exp(c <= d, true, "c <= d, true");
      assert_exp(d < e, true, "d < e, true");
      assert_exp(d <= e, true, "d <= e, true");
      assert_exp(e < f, true, "e < f, true");
      assert_exp(e <= f, true, "e <= f, true");

      assert_exp(a > b, false, "a > b, false");
      assert_exp(a >= b, false, "a >= b, false");
      assert_exp(b > c, false, "b > c, false");
      assert_exp(b >= c, false, "b >= c, false");
      assert_exp(c > d, false, "c > d, false");
      assert_exp(c >= d, false, "c >= d, false");
      assert_exp(d > e, false, "d > e, false");
      assert_exp(d >= e, false, "d >= e, false");
      assert_exp(e > f, false, "e > f, false");
      assert_exp(e >= f, false, "e >= f, false");

      assert_exp(b < a, false, "b < a, false");
      assert_exp(b <= a, false, "b <= a, false");
      assert_exp(c < b, false, "c < b, false");
      assert_exp(c <= b, false, "c <= b, false");
      assert_exp(d < c, false, "d < c, false");
      assert_exp(d <= c, false, "d <= c, false");
      assert_exp(e < d, false, "e < d, false");
      assert_exp(e <= d, false, "e <= d, false");
      assert_exp(f < e, false, "f < e, false");
      assert_exp(f <= e, false, "f <= e, false");

      assert_exp(b > a, true, "b > a, true");
      assert_exp(b >= a, true, "b >= a, true");
      assert_exp(c > b, true, "c > b, true");
      assert_exp(c >= b, true, "c >= b, true");
      assert_exp(d > c, true, "d > c, true");
      assert_exp(d >= c, true, "d >= c, true");
      assert_exp(e > d, true, "e > d, true");
      assert_exp(e >= d, true, "e >= d, true");
      assert_exp(f > e, true, "f > e, true");
      assert_exp(f >= e, true, "f >= e, true");

      assert_exp(a == a, true, "a == a, true");
      assert_exp(b == b, true, "b == b, true");
      assert_exp(c == c, true, "c == c, true");
      assert_exp(d == d, true, "d == d, true");
      assert_exp(e == e, true, "e == e, true");
      assert_exp(f == f, true, "f == f, true");

      assert_exp(a <= a, true, "a <= a, true");
      assert_exp(b <= b, true, "b <= b, true");
      assert_exp(c <= c, true, "c <= c, true");
      assert_exp(d <= d, true, "d <= d, true");
      assert_exp(e <= e, true, "e <= e, true");
      assert_exp(f <= f, true, "f <= f, true");

      assert_exp(a >= a, true, "a >= a, true");
      assert_exp(b >= b, true, "b >= b, true");
      assert_exp(c >= c, true, "c >= c, true");
      assert_exp(d >= d, true, "d >= d, true");
      assert_exp(e >= e, true, "e >= e, true");
      assert_exp(f >= f, true, "f >= f, true");
    }
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "BASIC ADDITIONS : \n";
  {
    {
      uint64_t a = 0xffffffffffffffff;
      uint64_t b = 0x1;
      uint64_t c = 0xffffffff;
      uint64_t x = a + b, y = a + c, z = a + a, m = b + c;
      uint64_t v = 0xfffffffffffffff;
      uint64_t av = a + v;

      constexpr uint64_8t a_8t = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
      constexpr uint64_8t b_8t = {0x1};
      constexpr uint64_8t c_8t = {0xff, 0xff, 0xff, 0xff};
      constexpr uint64_8t x_8t = a_8t + b_8t, y_8t = a_8t + c_8t, z_8t = a_8t + a_8t, m_8t = b_8t + c_8t;
      constexpr uint64_8t v_8t = {0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
      constexpr uint64_8t av_8t = a_8t + v_8t;

      assert_eq(a, a_8t, 8);
      assert_eq(b, b_8t, 8);
      assert_eq(c, c_8t, 8);

      assert_eq(x, x_8t, 8);
      assert_eq(y, y_8t, 8);
      assert_eq(z, z_8t, 8);
      assert_eq(m, m_8t, 8);
      assert_eq(v, v_8t, 8);
      assert_eq(av, av_8t, 8);

      uint64_8t a_b = a_8t;
      uint64_8t a_c = a_8t;
      uint64_8t a_a = a_8t;
      uint64_8t a_v = a_8t;

      a_b += b_8t;
      a_c += c_8t;
      a_a += a_8t;
      a_v += v_8t;

      assert_eq(x, a_b, 8);
      assert_eq(y, a_c, 8);
      assert_eq(z, a_a, 8);
      assert_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff;
      uint64_t b = 0x1;
      uint64_t c = 0xffffffff;
      uint64_t x = a + b, y = a + c, z = a + a, m = b + c;
      uint64_t v = 0xfffffffffffffff;
      uint64_t av = a + v;

      constexpr uint64_16t a_8t = {0xffff, 0xffff, 0xffff, 0xffff};
      constexpr uint64_16t b_8t = {0x1};
      constexpr uint64_16t c_8t = {0xffff, 0xffff};
      constexpr uint64_16t x_8t = a_8t + b_8t, y_8t = a_8t + c_8t, z_8t = a_8t + a_8t, m_8t = b_8t + c_8t;
      constexpr uint64_16t v_8t = {0xfff, 0xffff, 0xffff, 0xffff};
      constexpr uint64_16t av_8t = a_8t + v_8t;

      assert_eq(a, a_8t, 8);
      assert_eq(b, b_8t, 8);
      assert_eq(c, c_8t, 8);

      assert_eq(x, x_8t, 8);
      assert_eq(y, y_8t, 8);
      assert_eq(z, z_8t, 8);
      assert_eq(m, m_8t, 8);
      assert_eq(v, v_8t, 8);
      assert_eq(av, av_8t, 8);

      uint64_16t a_b = a_8t;
      uint64_16t a_c = a_8t;
      uint64_16t a_a = a_8t;
      uint64_16t a_v = a_8t;

      a_b += b_8t;
      a_c += c_8t;
      a_a += a_8t;
      a_v += v_8t;

      assert_eq(x, a_b, 8);
      assert_eq(y, a_c, 8);
      assert_eq(z, a_a, 8);
      assert_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff;
      uint64_t b = 0x1;
      uint64_t c = 0xffffffff;
      uint64_t x = a + b, y = a + c, z = a + a, m = b + c;
      uint64_t v = 0xfffffffffffffff;
      uint64_t av = a + v;

      constexpr uint64_32t a_8t = {0xffffffff, 0xffffffff};
      constexpr uint64_32t b_8t = {0x1};
      constexpr uint64_32t c_8t = {0xffffffff};
      constexpr uint64_32t x_8t = a_8t + b_8t, y_8t = a_8t + c_8t, z_8t = a_8t + a_8t, m_8t = b_8t + c_8t;
      constexpr uint64_32t v_8t = {0xfffffff, 0xffffffff};
      constexpr uint64_32t av_8t = a_8t + v_8t;

      assert_eq(a, a_8t, 8);
      assert_eq(b, b_8t, 8);
      assert_eq(c, c_8t, 8);

      assert_eq(x, x_8t, 8);
      assert_eq(y, y_8t, 8);
      assert_eq(z, z_8t, 8);
      assert_eq(m, m_8t, 8);
      assert_eq(v, v_8t, 8);
      assert_eq(av, av_8t, 8);

      uint64_32t a_b = a_8t;
      uint64_32t a_c = a_8t;
      uint64_32t a_a = a_8t;
      uint64_32t a_v = a_8t;

      a_b += b_8t;
      a_c += c_8t;
      a_a += a_8t;
      a_v += v_8t;

      assert_eq(x, a_b, 8);
      assert_eq(y, a_c, 8);
      assert_eq(z, a_a, 8);
      assert_eq(av, a_v, 8);
    }
  }

  // #############################################################
  std::cout << "\n----------------------------------------------\n";
  std::cout << "BASIC SUBTRACTIONS\n";
  {
    {
      uint64_t a = 0xffffffffffffffff;
      uint64_t b = 0x1;
      uint64_t c = 0xffffffff;
      uint64_t x = a - b, y = a - c, z = a - a, m = b - c;
      uint64_t v = 0xfffffffffffffff;
      uint64_t av = a - v;

      constexpr uint64_8t a_8t = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
      constexpr uint64_8t b_8t = {0x1};
      constexpr uint64_8t c_8t = {0xff, 0xff, 0xff, 0xff};
      constexpr uint64_8t x_8t = a_8t - b_8t, y_8t = a_8t - c_8t, z_8t = a_8t - a_8t, m_8t = b_8t - c_8t;
      constexpr uint64_8t v_8t = {0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
      constexpr uint64_8t av_8t = a_8t - v_8t;

      assert_eq(a, a_8t, 8);
      assert_eq(b, b_8t, 8);
      assert_eq(c, c_8t, 8);

      assert_eq(x, x_8t, 8);
      assert_eq(y, y_8t, 8);
      assert_eq(z, z_8t, 8);
      assert_eq(m, m_8t, 8);
      assert_eq(v, v_8t, 8);
      assert_eq(av, av_8t, 8);

      uint64_8t a_b = a_8t;
      uint64_8t a_c = a_8t;
      uint64_8t a_a = a_8t;
      uint64_8t a_v = a_8t;

      a_b -= b_8t;
      a_c -= c_8t;
      a_a -= a_8t;
      a_v -= v_8t;

      assert_eq(x, a_b, 8);
      assert_eq(y, a_c, 8);
      assert_eq(z, a_a, 8);
      assert_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff;
      uint64_t b = 0x1;
      uint64_t c = 0xffffffff;
      uint64_t x = a - b, y = a - c, z = a - a, m = b - c;
      uint64_t v = 0xfffffffffffffff;
      uint64_t av = a - v;

      constexpr uint64_16t a_8t = {0xffff, 0xffff, 0xffff, 0xffff};
      constexpr uint64_16t b_8t = {0x1};
      constexpr uint64_16t c_8t = {0xffff, 0xffff};
      constexpr uint64_16t x_8t = a_8t - b_8t, y_8t = a_8t - c_8t, z_8t = a_8t - a_8t, m_8t = b_8t - c_8t;
      constexpr uint64_16t v_8t = {0xfff, 0xffff, 0xffff, 0xffff};
      constexpr uint64_16t av_8t = a_8t - v_8t;

      assert_eq(a, a_8t, 8);
      assert_eq(b, b_8t, 8);
      assert_eq(c, c_8t, 8);

      assert_eq(x, x_8t, 8);
      assert_eq(y, y_8t, 8);
      assert_eq(z, z_8t, 8);
      assert_eq(m, m_8t, 8);
      assert_eq(v, v_8t, 8);
      assert_eq(av, av_8t, 8);

      uint64_16t a_b = a_8t;
      uint64_16t a_c = a_8t;
      uint64_16t a_a = a_8t;
      uint64_16t a_v = a_8t;

      a_b -= b_8t;
      a_c -= c_8t;
      a_a -= a_8t;
      a_v -= v_8t;

      assert_eq(x, a_b, 8);
      assert_eq(y, a_c, 8);
      assert_eq(z, a_a, 8);
      assert_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff;
      uint64_t b = 0x1;
      uint64_t c = 0xffffffff;
      uint64_t x = a - b, y = a - c, z = a - a, m = b - c;
      uint64_t v = 0xfffffffffffffff;
      uint64_t av = a - v;

      constexpr uint64_32t a_8t = { 0xffffffff, 0xffffffff };
      constexpr uint64_32t b_8t = { 0x1 };
      constexpr uint64_32t c_8t = { 0xffffffff };
      constexpr uint64_32t x_8t = a_8t - b_8t, y_8t = a_8t - c_8t, z_8t = a_8t - a_8t, m_8t = b_8t - c_8t;
      constexpr uint64_32t v_8t = { 0xfffffff, 0xffffffff };
      constexpr uint64_32t av_8t = a_8t - v_8t;

      assert_eq(a, a_8t, 8);
      assert_eq(b, b_8t, 8);
      assert_eq(c, c_8t, 8);

      assert_eq(x, x_8t, 8);
      assert_eq(y, y_8t, 8);
      assert_eq(z, z_8t, 8);
      assert_eq(m, m_8t, 8);
      assert_eq(v, v_8t, 8);
      assert_eq(av, av_8t, 8);

      uint64_32t a_b = a_8t;
      uint64_32t a_c = a_8t;
      uint64_32t a_a = a_8t;
      uint64_32t a_v = a_8t;

      a_b -= b_8t;
      a_c -= c_8t;
      a_a -= a_8t;
      a_v -= v_8t;

      assert_eq(x, a_b, 8);
      assert_eq(y, a_c, 8);
      assert_eq(z, a_a, 8);
      assert_eq(av, a_v, 8);
    }
  }

  // #############################################################
  std::cout << "\n----------------------------------------------\n";
  std::cout << "BASIC MULTIPLICATION\n";
  {
    {
      uint64_t a = 0xffffffffffffffff;
      uint64_t b = 0x1;
      uint64_t c = 0xffffffff;
      uint64_t x = a * b, y = a * c, z = a * a, m = b * c;
      uint64_t v = 0xfffffffffffffff;
      uint64_t av = a * v;

      constexpr uint64_8t a_8t = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
      constexpr uint64_8t b_8t = {0x1};
      constexpr uint64_8t c_8t = {0xff, 0xff, 0xff, 0xff};
      constexpr uint64_8t x_8t = a_8t * b_8t, y_8t = a_8t * c_8t, z_8t = a_8t * a_8t, m_8t = b_8t * c_8t;
      constexpr uint64_8t v_8t = {0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
      constexpr uint64_8t av_8t = a_8t * v_8t;

      assert_eq(a, a_8t, 8);
      assert_eq(b, b_8t, 8);
      assert_eq(c, c_8t, 8);

      assert_eq(x, x_8t, 8);
      assert_eq(y, y_8t, 8);
      assert_eq(z, z_8t, 8);
      assert_eq(m, m_8t, 8);
      assert_eq(v, v_8t, 8);
      assert_eq(av, av_8t, 8);

      uint64_8t a_b = a_8t;
      uint64_8t a_c = a_8t;
      uint64_8t a_a = a_8t;
      uint64_8t a_v = a_8t;

      a_b *= b_8t;
      a_c *= c_8t;
      a_a *= a_8t;
      a_v *= v_8t;

      assert_eq(x, a_b, 8);
      assert_eq(y, a_c, 8);
      assert_eq(z, a_a, 8);
      assert_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff;
      uint64_t b = 0x1;
      uint64_t c = 0xffffffff;
      uint64_t x = a * b, y = a * c, z = a * a, m = b * c;
      uint64_t v = 0xfffffffffffffff;
      uint64_t av = a * v;

      constexpr uint64_16t a_8t = {0xffff, 0xffff, 0xffff, 0xffff};
      constexpr uint64_16t b_8t = {0x1};
      constexpr uint64_16t c_8t = {0xffff, 0xffff};
      constexpr uint64_16t x_8t = a_8t * b_8t, y_8t = a_8t * c_8t, z_8t = a_8t * a_8t, m_8t = b_8t * c_8t;
      constexpr uint64_16t v_8t = {0xfff, 0xffff, 0xffff, 0xffff};
      constexpr uint64_16t av_8t = a_8t * v_8t;

      assert_eq(a, a_8t, 8);
      assert_eq(b, b_8t, 8);
      assert_eq(c, c_8t, 8);

      assert_eq(x, x_8t, 8);
      assert_eq(y, y_8t, 8);
      assert_eq(z, z_8t, 8);
      assert_eq(m, m_8t, 8);
      assert_eq(v, v_8t, 8);
      assert_eq(av, av_8t, 8);

      uint64_16t a_b = a_8t;
      uint64_16t a_c = a_8t;
      uint64_16t a_a = a_8t;
      uint64_16t a_v = a_8t;

      a_b *= b_8t;
      a_c *= c_8t;
      a_a *= a_8t;
      a_v *= v_8t;

      assert_eq(x, a_b, 8);
      assert_eq(y, a_c, 8);
      assert_eq(z, a_a, 8);
      assert_eq(av, a_v, 8);
    }

    {
      uint64_t a = 0xffffffffffffffff;
      uint64_t b = 0x1;
      uint64_t c = 0xffffffff;
      uint64_t x = a * b, y = a * c, z = a * a, m = b * c;
      uint64_t v = 0xfffffffffffffff;
      uint64_t av = a * v;

      constexpr uint64_32t a_8t = { 0xffffffff, 0xffffffff };
      constexpr uint64_32t b_8t = { 0x1 };
      constexpr uint64_32t c_8t = { 0xffffffff };
      constexpr uint64_32t x_8t = a_8t * b_8t, y_8t = a_8t * c_8t, z_8t = a_8t * a_8t, m_8t = b_8t * c_8t;
      constexpr uint64_32t v_8t = { 0xfffffff, 0xffffffff };
      constexpr uint64_32t av_8t = a_8t * v_8t;

      assert_eq(a, a_8t, 8);
      assert_eq(b, b_8t, 8);
      assert_eq(c, c_8t, 8);

      assert_eq(x, x_8t, 8);
      assert_eq(y, y_8t, 8);
      assert_eq(z, z_8t, 8);
      assert_eq(m, m_8t, 8);
      assert_eq(v, v_8t, 8);
      assert_eq(av, av_8t, 8);

      uint64_32t a_b = a_8t;
      uint64_32t a_c = a_8t;
      uint64_32t a_a = a_8t;
      uint64_32t a_v = a_8t;

      a_b *= b_8t;
      a_c *= c_8t;
      a_a *= a_8t;
      a_v *= v_8t;

      assert_eq(x, a_b, 8);
      assert_eq(y, a_c, 8);
      assert_eq(z, a_a, 8);
      assert_eq(av, a_v, 8);
    }
  }

  if (!final_verdict) {
    std::cout << "\nFINAL VERDICT : PASSED\n";
    return 0;
  } else {
    std::cout << "\nFINAL VERDICT : FAILED\n\n";

    std::cout << "Failed on test cases : ";

    for (auto e: failed_cases) {
      std::cout << std::dec << e << ", ";
    }

    return 1;
  }
}

// #############################################################

template <typename T1, typename T2>
void assert_eq(T1 a, T2 b, size_t numBytes, std::string test_name) {
  test_number++;
  int result = memcmp(&a, &b, numBytes);
  test_results.push_back(result);
  final_verdict |= result;

  if (!result) {
    std::cout << "PASSED : "
              << "test " << std::dec << test_number << " (" << test_name << ")";
  } else {
    std::cout << "!!! FAILED : "
              << "test " << std::dec << test_number << " (" << test_name << ")";
    
    failed_cases.push_back(test_number);
  }

#ifdef PRINT_RESULT
  std::cout << std::hex << "  ->  " << a << " == " << b;
#endif

  std::cout << "\n";
}

template <typename T1, typename T2>
void assert_types(std::string test_name) {
  test_number++;
  bool result = sizeof(T1) != sizeof(T2);
  test_results.push_back(result);
  final_verdict |= result;

  if (!result) {
    std::cout << "PASSED : "
              << "test " << std::dec << test_number << " (" << test_name << ")";
  } else {
    std::cout << "!!! FAILED : "
              << "test " << std::dec << test_number << " (" << test_name << ")";

    failed_cases.push_back(test_number);
  }

#ifdef PRINT_RESULT
  std::cout << std::hex << "  ->  " << sizeof(T1) << " ::type_equality:: " << sizeof(T2);
#endif

  std::cout << "\n";
}

void assert_exp(bool A, bool B, std::string test_name) {
  test_number++;
  bool result = A != B;
  test_results.push_back(result);
  final_verdict |= result;

  if (!result) {
    std::cout << "PASSED : "
              << "test " << std::dec << test_number << " (" << test_name << ")";
  } else {
    std::cout << "!!! FAILED : "
              << "test " << std::dec << test_number << " (" << test_name << ")";

    failed_cases.push_back(test_number);
  }

#ifdef PRINT_RESULT
  std::cout << std::hex << "  ->  " << A << " :::: " << B;
#endif

  std::cout << "\n";
}