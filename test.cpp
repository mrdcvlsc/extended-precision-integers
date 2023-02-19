#include <iostream>
#include <assert.h>
#include <vector>
#include "epi.hpp"

#define PRINT_RESULT

typedef epi::number<uint8_t, uint16_t, 8> uint64_8t;
typedef epi::number<uint16_t, uint32_t, 4> uint64_16t;

static std::vector<size_t> test_results;
static size_t test_number = 0;
static int final_verdict = 0;

template<typename T1, typename T2>
void mem_compare(T1 a, T2 b, size_t numBytes) {
    test_number++;
    int result = memcmp(&a, &b, numBytes);
    test_results.push_back(result);
    final_verdict |= result;
    
    if (!result) {
        std::cout << "PASSED : " << "test " << test_number;
    } else {
        std::cout << "FAILED : " << "test " << test_number;
    }

    #ifdef PRINT_RESULT
    std::cout << std::hex << "  ->  " << a << " == " << b;
    #endif

    std::cout << "\n";
}

int main() {
    epi::number<uint32_t, uint64_t, 7> test {0xff};

    std::cout << "----------------------------------------------\n";
    std::cout << "BASIC ADDITIONS : \n";
    {
        uint64_t a = 0xffffffffffffffff;
        uint64_t b = 0x1;
        uint64_t c = 0xffffffff;
        uint64_t x = a + b, y = a + c, z = a + a, m = b + c;
        uint64_t v = 0xfffffffffffffff;
        uint64_t av = a + v;

        uint64_8t a_8t = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
        uint64_8t b_8t = { 0x1 };
        uint64_8t c_8t = { 0xff, 0xff, 0xff, 0xff };
        uint64_8t x_8t = a_8t + b_8t, y_8t = a_8t + c_8t, z_8t = a_8t + a_8t, m_8t = b_8t + c_8t;
        uint64_8t v_8t = { 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
        uint64_8t av_8t = a_8t + v_8t;

        mem_compare(a, a_8t, 8);
        mem_compare(b, b_8t, 8);
        mem_compare(c, c_8t, 8);

        mem_compare(x, x_8t, 8);
        mem_compare(y, y_8t, 8);
        mem_compare(z, z_8t, 8);
        mem_compare(m, m_8t, 8);
        mem_compare(v, v_8t, 8);
        mem_compare(av, av_8t, 8);

        uint64_8t a_b = a_8t;
        uint64_8t a_c = a_8t;
        uint64_8t a_a = a_8t;
        uint64_8t a_v = a_8t;

        a_b += b_8t;
        a_c += c_8t;
        a_a += a_8t;
        a_v += v_8t;

        mem_compare(x, a_b, 8);
        mem_compare(y, a_c, 8);
        mem_compare(z, a_a, 8);
        mem_compare(av, a_v, 8);
    }

    {
        uint64_t a = 0xffffffffffffffff;
        uint64_t b = 0x1;
        uint64_t c = 0xffffffff;
        uint64_t x = a + b, y = a + c, z = a + a, m = b + c;
        uint64_t v = 0xfffffffffffffff;
        uint64_t av = a + v;

        uint64_16t a_8t = { 0xffff, 0xffff, 0xffff, 0xffff };
        uint64_16t b_8t = { 0x1 };
        uint64_16t c_8t = { 0xffff, 0xffff };
        uint64_16t x_8t = a_8t + b_8t, y_8t = a_8t + c_8t, z_8t = a_8t + a_8t, m_8t = b_8t + c_8t;
        uint64_16t v_8t = { 0xfff, 0xffff, 0xffff, 0xffff };
        uint64_16t av_8t = a_8t + v_8t;

        mem_compare(a, a_8t, 8);
        mem_compare(b, b_8t, 8);
        mem_compare(c, c_8t, 8);

        mem_compare(x, x_8t, 8);
        mem_compare(y, y_8t, 8);
        mem_compare(z, z_8t, 8);
        mem_compare(m, m_8t, 8);
        mem_compare(v, v_8t, 8);
        mem_compare(av, av_8t, 8);

        uint64_16t a_b = a_8t;
        uint64_16t a_c = a_8t;
        uint64_16t a_a = a_8t;
        uint64_16t a_v = a_8t;

        a_b += b_8t;
        a_c += c_8t;
        a_a += a_8t;
        a_v += v_8t;

        mem_compare(x, a_b, 8);
        mem_compare(y, a_c, 8);
        mem_compare(z, a_a, 8);
        mem_compare(av, a_v, 8);
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

        uint64_8t a_8t = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
        uint64_8t b_8t = { 0x1 };
        uint64_8t c_8t = { 0xff, 0xff, 0xff, 0xff };
        uint64_8t x_8t = a_8t - b_8t, y_8t = a_8t - c_8t, z_8t = a_8t - a_8t, m_8t = b_8t - c_8t;
        uint64_8t v_8t = { 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
        uint64_8t av_8t = a_8t - v_8t;

        mem_compare(a, a_8t, 8);
        mem_compare(b, b_8t, 8);
        mem_compare(c, c_8t, 8);

        mem_compare(x, x_8t, 8);
        mem_compare(y, y_8t, 8);
        mem_compare(z, z_8t, 8);
        mem_compare(m, m_8t, 8);
        mem_compare(v, v_8t, 8);
        mem_compare(av, av_8t, 8);

        uint64_8t a_b = a_8t;
        uint64_8t a_c = a_8t;
        uint64_8t a_a = a_8t;
        uint64_8t a_v = a_8t;

        a_b -= b_8t;
        a_c -= c_8t;
        a_a -= a_8t;
        a_v -= v_8t;

        mem_compare(x, a_b, 8);
        mem_compare(y, a_c, 8);
        mem_compare(z, a_a, 8);
        mem_compare(av, a_v, 8);
    }

    {
        uint64_t a = 0xffffffffffffffff;
        uint64_t b = 0x1;
        uint64_t c = 0xffffffff;
        uint64_t x = a - b, y = a - c, z = a - a, m = b - c;
        uint64_t v = 0xfffffffffffffff;
        uint64_t av = a - v;

        uint64_16t a_8t = { 0xffff, 0xffff, 0xffff, 0xffff };
        uint64_16t b_8t = { 0x1 };
        uint64_16t c_8t = { 0xffff, 0xffff };
        uint64_16t x_8t = a_8t - b_8t, y_8t = a_8t - c_8t, z_8t = a_8t - a_8t, m_8t = b_8t - c_8t;
        uint64_16t v_8t = { 0xfff, 0xffff, 0xffff, 0xffff };
        uint64_16t av_8t = a_8t - v_8t;

        mem_compare(a, a_8t, 8);
        mem_compare(b, b_8t, 8);
        mem_compare(c, c_8t, 8);

        mem_compare(x, x_8t, 8);
        mem_compare(y, y_8t, 8);
        mem_compare(z, z_8t, 8);
        mem_compare(m, m_8t, 8);
        mem_compare(v, v_8t, 8);
        mem_compare(av, av_8t, 8);

        uint64_16t a_b = a_8t;
        uint64_16t a_c = a_8t;
        uint64_16t a_a = a_8t;
        uint64_16t a_v = a_8t;

        a_b -= b_8t;
        a_c -= c_8t;
        a_a -= a_8t;
        a_v -= v_8t;

        mem_compare(x, a_b, 8);
        mem_compare(y, a_c, 8);
        mem_compare(z, a_a, 8);
        mem_compare(av, a_v, 8);
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

        uint64_8t a_8t = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
        uint64_8t b_8t = { 0x1 };
        uint64_8t c_8t = { 0xff, 0xff, 0xff, 0xff };
        uint64_8t x_8t = a_8t * b_8t, y_8t = a_8t * c_8t, z_8t = a_8t * a_8t, m_8t = b_8t * c_8t;
        uint64_8t v_8t = { 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
        uint64_8t av_8t = a_8t * v_8t;

        mem_compare(a, a_8t, 8);
        mem_compare(b, b_8t, 8);
        mem_compare(c, c_8t, 8);

        mem_compare(x, x_8t, 8);
        mem_compare(y, y_8t, 8);
        mem_compare(z, z_8t, 8);
        mem_compare(m, m_8t, 8);
        mem_compare(v, v_8t, 8);
        mem_compare(av, av_8t, 8);

        uint64_8t a_b = a_8t;
        uint64_8t a_c = a_8t;
        uint64_8t a_a = a_8t;
        uint64_8t a_v = a_8t;

        a_b *= b_8t;
        a_c *= c_8t;
        a_a *= a_8t;
        a_v *= v_8t;

        mem_compare(x, a_b, 8);
        mem_compare(y, a_c, 8);
        mem_compare(z, a_a, 8);
        mem_compare(av, a_v, 8);
    }

    {
        uint64_t a = 0xffffffffffffffff;
        uint64_t b = 0x1;
        uint64_t c = 0xffffffff;
        uint64_t x = a * b, y = a * c, z = a * a, m = b * c;
        uint64_t v = 0xfffffffffffffff;
        uint64_t av = a * v;

        uint64_16t a_8t = { 0xffff, 0xffff, 0xffff, 0xffff };
        uint64_16t b_8t = { 0x1 };
        uint64_16t c_8t = { 0xffff, 0xffff };
        uint64_16t x_8t = a_8t * b_8t, y_8t = a_8t * c_8t, z_8t = a_8t * a_8t, m_8t = b_8t * c_8t;
        uint64_16t v_8t = { 0xfff, 0xffff, 0xffff, 0xffff };
        uint64_16t av_8t = a_8t * v_8t;

        mem_compare(a, a_8t, 8);
        mem_compare(b, b_8t, 8);
        mem_compare(c, c_8t, 8);

        mem_compare(x, x_8t, 8);
        mem_compare(y, y_8t, 8);
        mem_compare(z, z_8t, 8);
        mem_compare(m, m_8t, 8);
        mem_compare(v, v_8t, 8);
        mem_compare(av, av_8t, 8);

        uint64_16t a_b = a_8t;
        uint64_16t a_c = a_8t;
        uint64_16t a_a = a_8t;
        uint64_16t a_v = a_8t;

        a_b *= b_8t;
        a_c *= c_8t;
        a_a *= a_8t;
        a_v *= v_8t;

        mem_compare(x, a_b, 8);
        mem_compare(y, a_c, 8);
        mem_compare(z, a_a, 8);
        mem_compare(av, a_v, 8);
    }

    if (!final_verdict) {
        std::cout << "\nFINAL VERDICT : PASSED\n";
        return 0;
    } else {
        std::cout << "\nFINAL VERDICT : FAILED\n";
        return 1;
    }
}