#include "../epi.hpp"
#include "wide-integer/math/wide_integer/uintwide_t.h"
#include <boost/multiprecision/cpp_int.hpp>

#include <chrono>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <random>

#ifdef _WIDENESS_BIT_NUM1
constexpr size_t WIDENESS = 128;
#elif defined(_WIDENESS_BIT_NUM2)
constexpr size_t WIDENESS = 192;
#elif defined(_WIDENESS_BIT_NUM3)
constexpr size_t WIDENESS = 256;
#elif defined(_WIDENESS_BIT_NUM4)
constexpr size_t WIDENESS = 320;
#elif defined(_WIDENESS_BIT_NUM5)
constexpr size_t WIDENESS = 512;
#elif defined(_WIDENESS_BIT_NUM6)
constexpr size_t WIDENESS = 1024;
#elif defined(_WIDENESS_BIT_NUM7)
constexpr size_t WIDENESS = 524288;
#else
constexpr size_t WIDENESS = 128;
#endif

#define _LIMBSIZE_U32

#ifdef _LIMBSIZE_U16
using uint_t = uint16_t;
using uint_tA = math::wide_integer::uintwide_t<WIDENESS, uint16_t>;
using uint_tB = epi::whole_number<uint16_t, uint64_t, (WIDENESS / (sizeof(uint_t) * 8))>;
#elif defined(_LIMBSIZE_U32)
using uint_t = uint32_t;
using uint_tA = math::wide_integer::uintwide_t<WIDENESS, uint32_t>;
using uint_tB = epi::whole_number<uint32_t, uint64_t, (WIDENESS / (sizeof(uint_t) * 8))>;
#elif defined(_LIMBSIZE_U64)
using uint_t = uint64_t;
using uint_tA = math::wide_integer::uintwide_t<WIDENESS, uint32_t>; // not supported uint64_t as limb?
using uint_tB = epi::whole_number<uint64_t, __uint128_t, (WIDENESS / (sizeof(uint_t) * 8))>;
#endif

using uint_tC = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<
  WIDENESS, WIDENESS, boost::multiprecision::cpp_integer_type::unsigned_magnitude,
  boost::multiprecision::cpp_int_check_type::unchecked, void>>;

unsigned int    seed = std::chrono::steady_clock::now().time_since_epoch().count();
std::mt19937_64 rand_engine(seed);

std::uniform_int_distribution<uint_t> rng(std::numeric_limits<uint_t>::min() + 1, std::numeric_limits<uint_t>::max());

template <typename T1, typename T2, typename T3, typename BufferT>
void memory_copy(T1 &a, T2 &b, T3 &c, BufferT *BUFFER, const size_t BufferBytes) {
  std::memcpy(&a, BUFFER, BufferBytes);
  std::memcpy(&b, BUFFER, BufferBytes);
  std::memcpy(&c, BUFFER, BufferBytes);
}

template <typename BufferT>
void randomize_buffer(BufferT *BUFFER, size_t BufferLen, size_t offset = 0) {
  BUFFER[0] = rng(rand_engine) | 1;
  for (size_t i = 1; i < BufferLen - offset; ++i) {
    BUFFER[i] = rng(rand_engine);
  }

  for (size_t i = BufferLen - offset; i < BufferLen; ++i) {
    BUFFER[i] = 0;
  }
}

template <typename T1, typename T2, typename T3>
int debug_log(
  std::string const &operation_name, T1 const &a1, T1 const &a2, T2 const &b1, T2 const &b2, T3 const &c1, T3 const &c2,
  T1 const &numA, T2 const &numB, T3 const &numC
) {
  std::cerr << "\n\n";
  std::cerr << "==================== " << operation_name << "(uint" << WIDENESS << "_t) ==================== \n\n";
  std::cerr << "a1 = " << std::hex << a1 << std::dec << "\n";
  std::cerr << "b1 = " << std::hex << b1 << std::dec << "\n";
  std::cerr << "c1 = " << std::hex << c1 << std::dec << "\n\n";

  std::cerr << "a2 = " << std::hex << a2 << std::dec << "\n";
  std::cerr << "b2 = " << std::hex << b2 << std::dec << "\n";
  std::cerr << "c2 = " << std::hex << c2 << std::dec << "\n\n";

  std::cerr << "numA = " << std::hex << numA << std::dec << "\n";
  std::cerr << "numB = " << std::hex << numB << std::dec << "\n";
  std::cerr << "numC = " << std::hex << numC << std::dec << "\n\n";

  std::cout << "memcmp = " << std::memcmp(&numA, &numB, sizeof(uint_tA)) << "\n";
  std::cout << "Failed " << operation_name << " operation\n\n";
  return 1;
}

std::string libA = "[`wide-integer`](https://github.com/ckormanyos/wide-integer)";
std::string libB = "[`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers)";
std::string libC = "[`boost::multiprecision`](https://github.com/boostorg/multiprecision)";

void print_average(std::string const &operation_symbol, size_t aveA, size_t aveB, size_t aveC) {
  std::cout << "| " << libA << " | **" << operation_symbol << "** | " << aveA << " ns |\n";
  std::cout << "| " << libB << " | **" << operation_symbol << "** | " << aveB << " ns |\n";
  std::cout << "| " << libC << " | **" << operation_symbol << "** | " << aveC << " ns |\n";
  std::cout << "| ................................. | ........ | ............ |\n";
}

int main() {
  constexpr size_t cold_runs = 512;
  constexpr size_t mul_cold_runs = 32;
  constexpr size_t div_cold_runs = 32;

  constexpr size_t add_iteration = 256;
  constexpr size_t sub_iteration = 256;
  constexpr size_t mul_iteration = 16;
  constexpr size_t div_iteration = 16;

  constexpr size_t shift_iteration = 256;

  constexpr size_t assigns_iteration = 256;

  if constexpr (sizeof(uint_tA) != sizeof(uint_tB)) {
    std::cout << "Invalid Sizes Detected\n\n";
    return 1;
  }

  constexpr size_t BUFFER_LEN = sizeof(uint_tA) / sizeof(uint_t);
  uint_t           BUFFER[BUFFER_LEN] = {};

  uint_tA a1 = 0, a2 = 0;
  uint_tB b1 = 0, b2 = 0;
  uint_tC c1 = 0, c2 = 1;

#if defined(_BLOCK_1)

  std::cout << "# Benchmark for **uint" << WIDENESS << "_t**\n\n";

  {
    std::cout << "### uint" << WIDENESS << "_t Arithmetic Operations : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + add_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1 + c2;
      auto    endC = std::chrono::high_resolution_clock::now();
      auto    durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1 + b2;
      auto    endB = std::chrono::high_resolution_clock::now();
      auto    durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1 + a2;
      auto    endA = std::chrono::high_resolution_clock::now();
      auto    durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= cold_runs) {
        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          return debug_log("add", a1, a2, b1, b2, c1, c2, numA, numB, numC);
        }
      }
    }

    size_t aveA = totalA / add_iteration, aveB = totalB / add_iteration, aveC = totalC / add_iteration;

    std::cout << "| Library | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    print_average("`+`", aveA, aveB, aveC);
  }

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + sub_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1 - c2;
      auto    endC = std::chrono::high_resolution_clock::now();
      auto    durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1 - b2;
      auto    endB = std::chrono::high_resolution_clock::now();
      auto    durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1 - a2;
      auto    endA = std::chrono::high_resolution_clock::now();
      auto    durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= cold_runs) {
        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          return debug_log("sub", a1, a2, b1, b2, c1, c2, numA, numB, numC);
        }
      }
    }

    size_t aveA = totalA / sub_iteration, aveB = totalB / sub_iteration, aveC = totalC / sub_iteration;
    print_average("`-`", aveA, aveB, aveC);
  }

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < mul_cold_runs + mul_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1 * c2;
      auto    endC = std::chrono::high_resolution_clock::now();
      auto    durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1 * b2;
      auto    endB = std::chrono::high_resolution_clock::now();
      auto    durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1 * a2;
      auto    endA = std::chrono::high_resolution_clock::now();
      auto    durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= mul_cold_runs) {

        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          return debug_log("mul", a1, a2, b1, b2, c1, c2, numA, numB, numC);
        }
      }
    }

    size_t aveA = totalA / mul_iteration, aveB = totalB / mul_iteration, aveC = totalC / mul_iteration;
    print_average("`*`", aveA, aveB, aveC);
  }

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < div_cold_runs + div_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1 / c2;
      auto    endC = std::chrono::high_resolution_clock::now();
      auto    durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1 / b2;
      auto    endB = std::chrono::high_resolution_clock::now();
      auto    durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1 / a2;
      auto    endA = std::chrono::high_resolution_clock::now();
      auto    durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= div_cold_runs) {

        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          return debug_log("div", a1, a2, b1, b2, c1, c2, numA, numB, numC);
        }
      }
    }

    size_t aveA = totalA / div_iteration, aveB = totalB / div_iteration, aveC = totalC / div_iteration;
    print_average("`/`", aveA, aveB, aveC);
  }

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < div_cold_runs + div_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1 % c2;
      auto    endC = std::chrono::high_resolution_clock::now();
      auto    durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1 % b2;
      auto    endB = std::chrono::high_resolution_clock::now();
      auto    durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1 % a2;
      auto    endA = std::chrono::high_resolution_clock::now();
      auto    durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= div_cold_runs) {

        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          return debug_log("mod", a1, a2, b1, b2, c1, c2, numA, numB, numC);
        }
      }
    }

    size_t aveA = totalA / div_iteration, aveB = totalB / div_iteration, aveC = totalC / div_iteration;
    print_average("`%`", aveA, aveB, aveC);
  }

#elif defined(_BLOCK_2)

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + add_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1;
      numC += c2;
      auto endC = std::chrono::high_resolution_clock::now();
      auto durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1;
      numB += b2;
      auto endB = std::chrono::high_resolution_clock::now();
      auto durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1;
      numA += a2;
      auto endA = std::chrono::high_resolution_clock::now();
      auto durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= cold_runs) {
        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          return debug_log("add assign", a1, a2, b1, b2, c1, c2, numA, numB, numC);
        }
      }
    }

    size_t aveA = totalA / add_iteration, aveB = totalB / add_iteration, aveC = totalC / add_iteration;
    print_average("`+=`", aveA, aveB, aveC);
  }

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + sub_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1;
      numC -= c2;
      auto endC = std::chrono::high_resolution_clock::now();
      auto durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1;
      numB -= b2;
      auto endB = std::chrono::high_resolution_clock::now();
      auto durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1;
      numA -= a2;
      auto endA = std::chrono::high_resolution_clock::now();
      auto durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= cold_runs) {
        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          return debug_log("sub assign", a1, a2, b1, b2, c1, c2, numA, numB, numC);
        }
      }
    }

    size_t aveA = totalA / sub_iteration, aveB = totalB / sub_iteration, aveC = totalC / sub_iteration;
    print_average("`-=`", aveA, aveB, aveC);
  }

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < mul_cold_runs + mul_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1;
      numC *= c2;
      auto endC = std::chrono::high_resolution_clock::now();
      auto durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1;
      numB *= b2;
      auto endB = std::chrono::high_resolution_clock::now();
      auto durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1;
      numA *= a2;
      auto endA = std::chrono::high_resolution_clock::now();
      auto durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= mul_cold_runs) {

        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          return debug_log("mul assign", a1, a2, b1, b2, c1, c2, numA, numB, numC);
        }
      }
    }

    size_t aveA = totalA / mul_iteration, aveB = totalB / mul_iteration, aveC = totalC / mul_iteration;
    print_average("`*=`", aveA, aveB, aveC);
  }

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < div_cold_runs + div_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1;
      numC /= c2;
      auto endC = std::chrono::high_resolution_clock::now();
      auto durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1;
      numB /= b2;
      auto endB = std::chrono::high_resolution_clock::now();
      auto durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1;
      numA /= a2;
      auto endA = std::chrono::high_resolution_clock::now();
      auto durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= div_cold_runs) {

        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          return debug_log("div assign", a1, a2, b1, b2, c1, c2, numA, numB, numC);
        }
      }
    }

    size_t aveA = totalA / div_iteration, aveB = totalB / div_iteration, aveC = totalC / div_iteration;
    print_average("`/=`", aveA, aveB, aveC);
  }

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < div_cold_runs + div_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1;
      numC %= c2;
      auto endC = std::chrono::high_resolution_clock::now();
      auto durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1;
      numB %= b2;
      auto endB = std::chrono::high_resolution_clock::now();
      auto durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1;
      numA %= a2;
      auto endA = std::chrono::high_resolution_clock::now();
      auto durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= div_cold_runs) {

        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          return debug_log("mod assign", a1, a2, b1, b2, c1, c2, numA, numB, numC);
        }
      }
    }

    size_t aveA = totalA / div_iteration, aveB = totalB / div_iteration, aveC = totalC / div_iteration;
    print_average("`%=`", aveA, aveB, aveC);
    std::cout << "\n";
  }

#elif defined(_BLOCK_3)

  {
    std::cout << "### uint" << WIDENESS << "_t Shift Operations : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + shift_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1 << 1;
      auto    endC = std::chrono::high_resolution_clock::now();
      auto    durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1 << 1;
      auto    endB = std::chrono::high_resolution_clock::now();
      auto    durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1 << 1;
      auto    endA = std::chrono::high_resolution_clock::now();
      auto    durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= cold_runs) {
        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numB, sizeof(uint_tA)) << "\n";
          std::cout << "Failed left shift operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / shift_iteration, aveB = totalB / shift_iteration, aveC = totalC / shift_iteration;

    std::cout << "| Library | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    print_average("`<<`", aveA, aveB, aveC);
  }

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + shift_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1 >> 1;
      auto    endC = std::chrono::high_resolution_clock::now();
      auto    durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1 >> 1;
      auto    endB = std::chrono::high_resolution_clock::now();
      auto    durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1 >> 1;
      auto    endA = std::chrono::high_resolution_clock::now();
      auto    durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= cold_runs) {
        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numB, sizeof(uint_tA)) << "\n";
          std::cout << "Failed right shift operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / shift_iteration, aveB = totalB / shift_iteration, aveC = totalC / shift_iteration;
    print_average("`>>`", aveA, aveB, aveC);
  }

  // //

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + shift_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1;
      numC <<= 1;
      auto endC = std::chrono::high_resolution_clock::now();
      auto durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1;
      numB <<= 1;
      auto endB = std::chrono::high_resolution_clock::now();
      auto durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1;
      numA <<= 1;
      auto endA = std::chrono::high_resolution_clock::now();
      auto durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= cold_runs) {
        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numB, sizeof(uint_tA)) << "\n";
          std::cout << "Failed assign left shift operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / shift_iteration, aveB = totalB / shift_iteration, aveC = totalC / shift_iteration;
    print_average("`<<=`", aveA, aveB, aveC);
  }

  {
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + shift_iteration; ++i) {
      randomize_buffer(BUFFER, BUFFER_LEN);
      memory_copy(a1, b1, c1, BUFFER, sizeof(BUFFER));

      randomize_buffer(BUFFER, BUFFER_LEN, 1);
      memory_copy(a2, b2, c2, BUFFER, sizeof(BUFFER));

      auto    startC = std::chrono::high_resolution_clock::now();
      uint_tC numC = c1;
      numC >>= 1;
      auto endC = std::chrono::high_resolution_clock::now();
      auto durC = std::chrono::duration_cast<std::chrono::nanoseconds>(endC - startC);

      auto    startB = std::chrono::high_resolution_clock::now();
      uint_tB numB = b1;
      numB >>= 1;
      auto endB = std::chrono::high_resolution_clock::now();
      auto durB = std::chrono::duration_cast<std::chrono::nanoseconds>(endB - startB);

      auto    startA = std::chrono::high_resolution_clock::now();
      uint_tA numA = a1;
      numA >>= 1;
      auto endA = std::chrono::high_resolution_clock::now();
      auto durA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA);

      if (i >= cold_runs) {
        totalA += durA.count(), totalB += durB.count(), totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numB, sizeof(uint_tA)) << "\n";
          std::cout << "Failed assign right shift operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / shift_iteration, aveB = totalB / shift_iteration, aveC = totalC / shift_iteration;
    print_average("`>>=`", aveA, aveB, aveC);
    std::cout << "\n";
  }
#endif

  return 0;
}