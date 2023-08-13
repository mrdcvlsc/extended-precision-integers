#include <iostream>
#include <string>

#include "small_test.hpp"

typedef epi::whole_number<uint8_t, uint16_t, 64>  uint64_8t;
typedef epi::whole_number<uint16_t, uint32_t, 64> uint64_16t;
typedef epi::whole_number<uint32_t, uint64_t, 64> uint64_32t;

int main() {
  smlts::test t;

  epi::whole_number<uint32_t, uint64_t, 224> SHOULD_NOT_THROW_ERROR{0xff};
  SHOULD_NOT_THROW_ERROR++;

  t.cmp_ts<uint64_t, uint64_8t>(__FILE__, __LINE__);
  t.cmp_ts<uint64_t, uint64_16t>(__FILE__, __LINE__);
  t.cmp_ts<uint64_t, uint64_32t>(__FILE__, __LINE__);

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

  return t.get_final_verdict("INITIALIZER LIST CONSTRUCTOR");
}