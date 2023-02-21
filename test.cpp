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
static size_t test_number = 0;
static int final_verdict = 0;

template <typename T1, typename T2>
void assert_eq(T1 a, T2 b, size_t numBytes, std::string test_name = "");

template <typename T1, typename T2>
void assert_types(std::string test_name = "");

void assert_exp(bool A, bool B, std::string test_name = "");

int main() {
  std::cout << "----------------------------------------------\n";
  std::cout << "CONSTRUCTORS AND SIZES : \n";
  {
    epi::number<uint32_t, uint64_t, 7> SHOULD_NOT_THROW_ERROR{0xff};
    assert_types<uint64_t, uint64_8t>();
    assert_types<uint64_t, uint64_16t>();
    assert_types<uint64_t, uint64_32t>();

    uint64_t a = 0xabcdef0123456789;
    uint64_8t b = a;
    uint64_16t c = a;
    uint64_32t d = a;

    uint64_t a_2 = 0xdeadbeef;
    uint64_8t b_2 = a_2;
    uint64_16t c_2 = a_2;
    uint64_32t d_2 = a_2;

    uint64_t a_3 = 0xcafebabe00000000;
    uint64_8t b_3 = a_3;
    uint64_16t c_3 = a_3;
    uint64_32t d_3 = a_3;

    assert_eq(a, b, 8);
    assert_eq(a, c, 8);
    assert_eq(a, d, 8);

    assert_eq(a_2, b_2, 8);
    assert_eq(a_2, c_2, 8);
    assert_eq(a_2, d_2, 8);

    assert_eq(a_3, b_3, 8);
    assert_eq(a_3, c_3, 8);
    assert_eq(a_3, d_3, 8);
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "SHIFT OPERATORS : \n";
  {
    uint64_t PODs[8] = {
        0xdeadbeefcafebabe,
        0xffffffffffffffff,
        0xffffffff00000000,
        0xffffffffffffffff,
        0xabcdef0123456789,
        0x9876543210fedcba,
        0b1010101010101010101010101010101010101010101010101010101010101010,
        0b101010101010101010101010101010101010101010101010101010101010101};

    uint64_8t EPIs[8] = {
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
            "assert_eq : iter = " + std::to_string(i) + "  |  << shift = " + std::to_string(j)
        );
      }
    }

    for (size_t i = 0; i < 8; i++) {
      for (int j = -2; j < 66; ++j) {
        assert_eq(
            PODs[i] >> j, EPIs[i] >> j, 8,
            "assert_eq : iter = " + std::to_string(i) + "  |  >> shift = " + std::to_string(j)
        );
      }
    }
  }

  {
    uint64_t PODs[8] = {
        0xdeadbeefcafebabe,
        0xffffffffffffffff,
        0xffffffff00000000,
        0xffffffffffffffff,
        0xabcdef0123456789,
        0x9876543210fedcba,
        0b1010101010101010101010101010101010101010101010101010101010101010,
        0b101010101010101010101010101010101010101010101010101010101010101};

    uint64_16t EPIs[8] = {
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
            "assert_eq : iter = " + std::to_string(i) + "  |  << shift = " + std::to_string(j)
        );
      }
    }

    for (size_t i = 0; i < 8; i++) {
      for (int j = -2; j < 66; ++j) {
        assert_eq(
            PODs[i] >> j, EPIs[i] >> j, 8,
            "assert_eq : iter = " + std::to_string(i) + "  |  >> shift = " + std::to_string(j)
        );
      }
    }
  }

  {
    uint64_t PODs[8] = {
        0xdeadbeefcafebabe,
        0xffffffffffffffff,
        0xffffffff00000000,
        0xffffffffffffffff,
        0xabcdef0123456789,
        0x9876543210fedcba,
        0b1010101010101010101010101010101010101010101010101010101010101010,
        0b101010101010101010101010101010101010101010101010101010101010101};

    uint64_32t EPIs[8] = {
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
            "assert_eq : iter = " + std::to_string(i) + "  |  << shift = " + std::to_string(j)
        );
      }
    }

    for (size_t i = 0; i < 8; i++) {
      for (int j = -2; j < 66; ++j) {
        assert_eq(
            PODs[i] >> j, EPIs[i] >> j, 8,
            "assert_eq : iter = " + std::to_string(i) + "  |  >> shift = " + std::to_string(j)
        );
      }
    }
  }

  std::cout << "----------------------------------------------\n";
  std::cout << "RELATIONAL OPERATORS : \n";
  {
    {
      uint64_8t a = 0x0;
      uint64_8t b = 0x1;
      uint64_8t c = 0xff;
      uint64_8t d = 0xffff;
      uint64_8t e = 0xffffffff;
      uint64_8t f = 0xffffffffffffffff;

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
    uint64_t a = 0xffffffffffffffff;
    uint64_t b = 0x1;
    uint64_t c = 0xffffffff;
    uint64_t x = a + b, y = a + c, z = a + a, m = b + c;
    uint64_t v = 0xfffffffffffffff;
    uint64_t av = a + v;

    uint64_8t a_8t = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    uint64_8t b_8t = {0x1};
    uint64_8t c_8t = {0xff, 0xff, 0xff, 0xff};
    uint64_8t x_8t = a_8t + b_8t, y_8t = a_8t + c_8t, z_8t = a_8t + a_8t, m_8t = b_8t + c_8t;
    uint64_8t v_8t = {0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    uint64_8t av_8t = a_8t + v_8t;

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

    uint64_16t a_8t = {0xffff, 0xffff, 0xffff, 0xffff};
    uint64_16t b_8t = {0x1};
    uint64_16t c_8t = {0xffff, 0xffff};
    uint64_16t x_8t = a_8t + b_8t, y_8t = a_8t + c_8t, z_8t = a_8t + a_8t, m_8t = b_8t + c_8t;
    uint64_16t v_8t = {0xfff, 0xffff, 0xffff, 0xffff};
    uint64_16t av_8t = a_8t + v_8t;

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

  // #############################################################
  std::cout << "\n----------------------------------------------\n";
  std::cout << "BASIC SUBTRACTIONS\n";
  {
    uint64_t a = 0xffffffffffffffff;
    uint64_t b = 0x1;
    uint64_t c = 0xffffffff;
    uint64_t x = a - b, y = a - c, z = a - a, m = b - c;
    uint64_t v = 0xfffffffffffffff;
    uint64_t av = a - v;

    uint64_8t a_8t = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    uint64_8t b_8t = {0x1};
    uint64_8t c_8t = {0xff, 0xff, 0xff, 0xff};
    uint64_8t x_8t = a_8t - b_8t, y_8t = a_8t - c_8t, z_8t = a_8t - a_8t, m_8t = b_8t - c_8t;
    uint64_8t v_8t = {0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    uint64_8t av_8t = a_8t - v_8t;

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

    uint64_16t a_8t = {0xffff, 0xffff, 0xffff, 0xffff};
    uint64_16t b_8t = {0x1};
    uint64_16t c_8t = {0xffff, 0xffff};
    uint64_16t x_8t = a_8t - b_8t, y_8t = a_8t - c_8t, z_8t = a_8t - a_8t, m_8t = b_8t - c_8t;
    uint64_16t v_8t = {0xfff, 0xffff, 0xffff, 0xffff};
    uint64_16t av_8t = a_8t - v_8t;

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

  // #############################################################
  std::cout << "\n----------------------------------------------\n";
  std::cout << "BASIC MULTIPLICATION\n";
  {
    uint64_t a = 0xffffffffffffffff;
    uint64_t b = 0x1;
    uint64_t c = 0xffffffff;
    uint64_t x = a * b, y = a * c, z = a * a, m = b * c;
    uint64_t v = 0xfffffffffffffff;
    uint64_t av = a * v;

    uint64_8t a_8t = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    uint64_8t b_8t = {0x1};
    uint64_8t c_8t = {0xff, 0xff, 0xff, 0xff};
    uint64_8t x_8t = a_8t * b_8t, y_8t = a_8t * c_8t, z_8t = a_8t * a_8t, m_8t = b_8t * c_8t;
    uint64_8t v_8t = {0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    uint64_8t av_8t = a_8t * v_8t;

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

    uint64_16t a_8t = {0xffff, 0xffff, 0xffff, 0xffff};
    uint64_16t b_8t = {0x1};
    uint64_16t c_8t = {0xffff, 0xffff};
    uint64_16t x_8t = a_8t * b_8t, y_8t = a_8t * c_8t, z_8t = a_8t * a_8t, m_8t = b_8t * c_8t;
    uint64_16t v_8t = {0xfff, 0xffff, 0xffff, 0xffff};
    uint64_16t av_8t = a_8t * v_8t;

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

  if (!final_verdict) {
    std::cout << "\nFINAL VERDICT : PASSED\n";
    return 0;
  } else {
    std::cout << "\nFINAL VERDICT : FAILED\n";
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
              << "test " << test_number << " (" << test_name << ")";
  } else {
    std::cout << "!!! FAILED : "
              << "test " << test_number << " (" << test_name << ")";
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
              << "test " << test_number << " (" << test_name << ")";
  } else {
    std::cout << "!!! FAILED : "
              << "test " << test_number << " (" << test_name << ")";
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
              << "test " << test_number << " (" << test_name << ")";
  } else {
    std::cout << "!!! FAILED : "
              << "test " << test_number << " (" << test_name << ")";
  }

#ifdef PRINT_RESULT
  std::cout << std::hex << "  ->  " << A << " :::: " << B;
#endif

  std::cout << "\n";
}