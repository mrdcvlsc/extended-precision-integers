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
        constexpr uint64_8t a = (uint64_t) 0x0;
        constexpr uint64_8t b = (uint64_t) 0x1;
        constexpr uint64_8t c = (uint64_t) 0xff;
        constexpr uint64_8t d = (uint64_t) 0xffff;
        constexpr uint64_8t e = (uint64_t) 0xffffffff;
        constexpr uint64_8t f = (uint64_t) 0xffffffffffffffff;

        t.cmp_eq(a, (uint64_t) 0x0, 8, __FILE__, __LINE__);
        t.cmp_eq(b, (uint64_t) 0x1, 8, __FILE__, __LINE__);
        t.cmp_eq(c, (uint64_t) 0xff, 8, __FILE__, __LINE__);
        t.cmp_eq(d, (uint64_t) 0xffff, 8, __FILE__, __LINE__);
        t.cmp_eq(e, (uint64_t) 0xffffffff, 8, __FILE__, __LINE__);
        t.cmp_eq(f, (uint64_t) 0xffffffffffffffff, 8, __FILE__, __LINE__);

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

        t.cmp_exp(a_l_b, true, __FILE__, __LINE__);
        t.cmp_exp(a_le_b, true, __FILE__, __LINE__);
        t.cmp_exp(b_l_c, true, __FILE__, __LINE__);
        t.cmp_exp(b_le_c, true, __FILE__, __LINE__);
        t.cmp_exp(c_l_d, true, __FILE__, __LINE__);
        t.cmp_exp(c_le_d, true, __FILE__, __LINE__);
        t.cmp_exp(d_l_e, true, __FILE__, __LINE__);
        t.cmp_exp(d_le_e, true, __FILE__, __LINE__);
        t.cmp_exp(e_l_f, true, __FILE__, __LINE__);
        t.cmp_exp(e_le_f, true, __FILE__, __LINE__);

        t.cmp_exp(a_g_b, false, __FILE__, __LINE__);
        t.cmp_exp(a_ge_b, false, __FILE__, __LINE__);
        t.cmp_exp(b_g_c, false, __FILE__, __LINE__);
        t.cmp_exp(b_ge_c, false, __FILE__, __LINE__);
        t.cmp_exp(c_g_d, false, __FILE__, __LINE__);
        t.cmp_exp(c_ge_d, false, __FILE__, __LINE__);
        t.cmp_exp(d_g_e, false, __FILE__, __LINE__);
        t.cmp_exp(d_ge_e, false, __FILE__, __LINE__);
        t.cmp_exp(e_g_f, false, __FILE__, __LINE__);
        t.cmp_exp(e_ge_f, false, __FILE__, __LINE__);

        t.cmp_exp(b_l_a, false, __FILE__, __LINE__);
        t.cmp_exp(b_le_a, false, __FILE__, __LINE__);
        t.cmp_exp(c_l_b, false, __FILE__, __LINE__);
        t.cmp_exp(c_le_b, false, __FILE__, __LINE__);
        t.cmp_exp(d_l_c, false, __FILE__, __LINE__);
        t.cmp_exp(d_le_c, false, __FILE__, __LINE__);
        t.cmp_exp(e_l_d, false, __FILE__, __LINE__);
        t.cmp_exp(e_le_d, false, __FILE__, __LINE__);
        t.cmp_exp(f_l_e, false, __FILE__, __LINE__);
        t.cmp_exp(f_le_e, false, __FILE__, __LINE__);

        t.cmp_exp(b_g_a, true, __FILE__, __LINE__);
        t.cmp_exp(b_ge_a, true, __FILE__, __LINE__);
        t.cmp_exp(c_g_b, true, __FILE__, __LINE__);
        t.cmp_exp(c_ge_b, true, __FILE__, __LINE__);
        t.cmp_exp(d_g_c, true, __FILE__, __LINE__);
        t.cmp_exp(d_ge_c, true, __FILE__, __LINE__);
        t.cmp_exp(e_g_d, true, __FILE__, __LINE__);
        t.cmp_exp(e_ge_d, true, __FILE__, __LINE__);
        t.cmp_exp(f_g_e, true, __FILE__, __LINE__);
        t.cmp_exp(f_ge_e, true, __FILE__, __LINE__);

        t.cmp_exp(a_eq_a, true, __FILE__, __LINE__);
        t.cmp_exp(b_eq_b, true, __FILE__, __LINE__);
        t.cmp_exp(c_eq_c, true, __FILE__, __LINE__);
        t.cmp_exp(d_eq_d, true, __FILE__, __LINE__);
        t.cmp_exp(e_eq_e, true, __FILE__, __LINE__);
        t.cmp_exp(f_eq_f, true, __FILE__, __LINE__);

        t.cmp_exp(a_le_a, true, __FILE__, __LINE__);
        t.cmp_exp(b_le_b, true, __FILE__, __LINE__);
        t.cmp_exp(c_le_c, true, __FILE__, __LINE__);
        t.cmp_exp(d_le_d, true, __FILE__, __LINE__);
        t.cmp_exp(e_le_e, true, __FILE__, __LINE__);
        t.cmp_exp(f_le_f, true, __FILE__, __LINE__);

        t.cmp_exp(a_ge_a, true, __FILE__, __LINE__);
        t.cmp_exp(b_ge_b, true, __FILE__, __LINE__);
        t.cmp_exp(c_ge_c, true, __FILE__, __LINE__);
        t.cmp_exp(d_ge_d, true, __FILE__, __LINE__);
        t.cmp_exp(e_ge_e, true, __FILE__, __LINE__);
        t.cmp_exp(f_ge_f, true, __FILE__, __LINE__);
    }

    {
        constexpr uint64_16t a = (uint64_t) 0x0;
        constexpr uint64_16t b = (uint64_t) 0x1;
        constexpr uint64_16t c = (uint64_t) 0xff;
        constexpr uint64_16t d = (uint64_t) 0xffff;
        constexpr uint64_16t e = (uint64_t) 0xffffffff;
        constexpr uint64_16t f = (uint64_t) 0xffffffffffffffff;

        t.cmp_eq(a, (uint64_t) 0x0, 8, __FILE__, __LINE__);
        t.cmp_eq(b, (uint64_t) 0x1, 8, __FILE__, __LINE__);
        t.cmp_eq(c, (uint64_t) 0xff, 8, __FILE__, __LINE__);
        t.cmp_eq(d, (uint64_t) 0xffff, 8, __FILE__, __LINE__);
        t.cmp_eq(e, (uint64_t) 0xffffffff, 8, __FILE__, __LINE__);
        t.cmp_eq(f, (uint64_t) 0xffffffffffffffff, 8, __FILE__, __LINE__);

        t.cmp_exp(a < b, true, __FILE__, __LINE__);
        t.cmp_exp(a <= b, true, __FILE__, __LINE__);
        t.cmp_exp(b < c, true, __FILE__, __LINE__);
        t.cmp_exp(b <= c, true, __FILE__, __LINE__);
        t.cmp_exp(c < d, true, __FILE__, __LINE__);
        t.cmp_exp(c <= d, true, __FILE__, __LINE__);
        t.cmp_exp(d < e, true, __FILE__, __LINE__);
        t.cmp_exp(d <= e, true, __FILE__, __LINE__);
        t.cmp_exp(e < f, true, __FILE__, __LINE__);
        t.cmp_exp(e <= f, true, __FILE__, __LINE__);

        t.cmp_exp(a > b, false, __FILE__, __LINE__);
        t.cmp_exp(a >= b, false, __FILE__, __LINE__);
        t.cmp_exp(b > c, false, __FILE__, __LINE__);
        t.cmp_exp(b >= c, false, __FILE__, __LINE__);
        t.cmp_exp(c > d, false, __FILE__, __LINE__);
        t.cmp_exp(c >= d, false, __FILE__, __LINE__);
        t.cmp_exp(d > e, false, __FILE__, __LINE__);
        t.cmp_exp(d >= e, false, __FILE__, __LINE__);
        t.cmp_exp(e > f, false, __FILE__, __LINE__);
        t.cmp_exp(e >= f, false, __FILE__, __LINE__);

        t.cmp_exp(b < a, false, __FILE__, __LINE__);
        t.cmp_exp(b <= a, false, __FILE__, __LINE__);
        t.cmp_exp(c < b, false, __FILE__, __LINE__);
        t.cmp_exp(c <= b, false, __FILE__, __LINE__);
        t.cmp_exp(d < c, false, __FILE__, __LINE__);
        t.cmp_exp(d <= c, false, __FILE__, __LINE__);
        t.cmp_exp(e < d, false, __FILE__, __LINE__);
        t.cmp_exp(e <= d, false, __FILE__, __LINE__);
        t.cmp_exp(f < e, false, __FILE__, __LINE__);
        t.cmp_exp(f <= e, false, __FILE__, __LINE__);

        t.cmp_exp(b > a, true, __FILE__, __LINE__);
        t.cmp_exp(b >= a, true, __FILE__, __LINE__);
        t.cmp_exp(c > b, true, __FILE__, __LINE__);
        t.cmp_exp(c >= b, true, __FILE__, __LINE__);
        t.cmp_exp(d > c, true, __FILE__, __LINE__);
        t.cmp_exp(d >= c, true, __FILE__, __LINE__);
        t.cmp_exp(e > d, true, __FILE__, __LINE__);
        t.cmp_exp(e >= d, true, __FILE__, __LINE__);
        t.cmp_exp(f > e, true, __FILE__, __LINE__);
        t.cmp_exp(f >= e, true, __FILE__, __LINE__);

        t.cmp_exp(a == a, true, __FILE__, __LINE__);
        t.cmp_exp(b == b, true, __FILE__, __LINE__);
        t.cmp_exp(c == c, true, __FILE__, __LINE__);
        t.cmp_exp(d == d, true, __FILE__, __LINE__);
        t.cmp_exp(e == e, true, __FILE__, __LINE__);
        t.cmp_exp(f == f, true, __FILE__, __LINE__);

        t.cmp_exp(a <= a, true, __FILE__, __LINE__);
        t.cmp_exp(b <= b, true, __FILE__, __LINE__);
        t.cmp_exp(c <= c, true, __FILE__, __LINE__);
        t.cmp_exp(d <= d, true, __FILE__, __LINE__);
        t.cmp_exp(e <= e, true, __FILE__, __LINE__);
        t.cmp_exp(f <= f, true, __FILE__, __LINE__);

        t.cmp_exp(a >= a, true, __FILE__, __LINE__);
        t.cmp_exp(b >= b, true, __FILE__, __LINE__);
        t.cmp_exp(c >= c, true, __FILE__, __LINE__);
        t.cmp_exp(d >= d, true, __FILE__, __LINE__);
        t.cmp_exp(e >= e, true, __FILE__, __LINE__);
        t.cmp_exp(f >= f, true, __FILE__, __LINE__);
    }

    {
        constexpr uint64_32t a = (uint64_t) 0x0;
        constexpr uint64_32t b = (uint64_t) 0x1;
        constexpr uint64_32t c = (uint64_t) 0xff;
        constexpr uint64_32t d = (uint64_t) 0xffff;
        constexpr uint64_32t e = (uint64_t) 0xffffffff;
        constexpr uint64_32t f = (uint64_t) 0xffffffffffffffff;

        t.cmp_eq(a, (uint64_t) 0x0, 8, __FILE__, __LINE__);
        t.cmp_eq(b, (uint64_t) 0x1, 8, __FILE__, __LINE__);
        t.cmp_eq(c, (uint64_t) 0xff, 8, __FILE__, __LINE__);
        t.cmp_eq(d, (uint64_t) 0xffff, 8, __FILE__, __LINE__);
        t.cmp_eq(e, (uint64_t) 0xffffffff, 8, __FILE__, __LINE__);
        t.cmp_eq(f, (uint64_t) 0xffffffffffffffff, 8, __FILE__, __LINE__);

        t.cmp_exp(a < b, true, __FILE__, __LINE__);
        t.cmp_exp(a <= b, true, __FILE__, __LINE__);
        t.cmp_exp(b < c, true, __FILE__, __LINE__);
        t.cmp_exp(b <= c, true, __FILE__, __LINE__);
        t.cmp_exp(c < d, true, __FILE__, __LINE__);
        t.cmp_exp(c <= d, true, __FILE__, __LINE__);
        t.cmp_exp(d < e, true, __FILE__, __LINE__);
        t.cmp_exp(d <= e, true, __FILE__, __LINE__);
        t.cmp_exp(e < f, true, __FILE__, __LINE__);
        t.cmp_exp(e <= f, true, __FILE__, __LINE__);

        t.cmp_exp(a > b, false, __FILE__, __LINE__);
        t.cmp_exp(a >= b, false, __FILE__, __LINE__);
        t.cmp_exp(b > c, false, __FILE__, __LINE__);
        t.cmp_exp(b >= c, false, __FILE__, __LINE__);
        t.cmp_exp(c > d, false, __FILE__, __LINE__);
        t.cmp_exp(c >= d, false, __FILE__, __LINE__);
        t.cmp_exp(d > e, false, __FILE__, __LINE__);
        t.cmp_exp(d >= e, false, __FILE__, __LINE__);
        t.cmp_exp(e > f, false, __FILE__, __LINE__);
        t.cmp_exp(e >= f, false, __FILE__, __LINE__);

        t.cmp_exp(b < a, false, __FILE__, __LINE__);
        t.cmp_exp(b <= a, false, __FILE__, __LINE__);
        t.cmp_exp(c < b, false, __FILE__, __LINE__);
        t.cmp_exp(c <= b, false, __FILE__, __LINE__);
        t.cmp_exp(d < c, false, __FILE__, __LINE__);
        t.cmp_exp(d <= c, false, __FILE__, __LINE__);
        t.cmp_exp(e < d, false, __FILE__, __LINE__);
        t.cmp_exp(e <= d, false, __FILE__, __LINE__);
        t.cmp_exp(f < e, false, __FILE__, __LINE__);
        t.cmp_exp(f <= e, false, __FILE__, __LINE__);

        t.cmp_exp(b > a, true, __FILE__, __LINE__);
        t.cmp_exp(b >= a, true, __FILE__, __LINE__);
        t.cmp_exp(c > b, true, __FILE__, __LINE__);
        t.cmp_exp(c >= b, true, __FILE__, __LINE__);
        t.cmp_exp(d > c, true, __FILE__, __LINE__);
        t.cmp_exp(d >= c, true, __FILE__, __LINE__);
        t.cmp_exp(e > d, true, __FILE__, __LINE__);
        t.cmp_exp(e >= d, true, __FILE__, __LINE__);
        t.cmp_exp(f > e, true, __FILE__, __LINE__);
        t.cmp_exp(f >= e, true, __FILE__, __LINE__);

        t.cmp_exp(a == a, true, __FILE__, __LINE__);
        t.cmp_exp(b == b, true, __FILE__, __LINE__);
        t.cmp_exp(c == c, true, __FILE__, __LINE__);
        t.cmp_exp(d == d, true, __FILE__, __LINE__);
        t.cmp_exp(e == e, true, __FILE__, __LINE__);
        t.cmp_exp(f == f, true, __FILE__, __LINE__);

        t.cmp_exp(a <= a, true, __FILE__, __LINE__);
        t.cmp_exp(b <= b, true, __FILE__, __LINE__);
        t.cmp_exp(c <= c, true, __FILE__, __LINE__);
        t.cmp_exp(d <= d, true, __FILE__, __LINE__);
        t.cmp_exp(e <= e, true, __FILE__, __LINE__);
        t.cmp_exp(f <= f, true, __FILE__, __LINE__);

        t.cmp_exp(a >= a, true, __FILE__, __LINE__);
        t.cmp_exp(b >= b, true, __FILE__, __LINE__);
        t.cmp_exp(c >= c, true, __FILE__, __LINE__);
        t.cmp_exp(d >= d, true, __FILE__, __LINE__);
        t.cmp_exp(e >= e, true, __FILE__, __LINE__);
        t.cmp_exp(f >= f, true, __FILE__, __LINE__);
    }

    return t.get_final_verdict("RELATIONAL OPERATORS");
}