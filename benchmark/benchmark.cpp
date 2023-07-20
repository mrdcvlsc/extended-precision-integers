#include <chrono>
#include <cstring>
#include <iostream>
#include <random>

#include "../epi.hpp"
#include "boost/include/boost/multiprecision/cpp_int.hpp"
#include "wide-integer/math/wide_integer/uintwide_t.h"

// _ARITHMETIC, _ASSIGN_ARITHMETIC, _SHIFTS

#ifdef _WIDENESS_128BIT
constexpr size_t WIDENESS = 128;
#elif defined(_WIDENESS_192BIT)
constexpr size_t WIDENESS = 192;
#elif defined(_WIDENESS_256BIT)
constexpr size_t WIDENESS = 256;
#elif defined(_WIDENESS_320BIT)
constexpr size_t WIDENESS = 320;
#elif defined(_WIDENESS_512BIT)
constexpr size_t WIDENESS = 512;
#elif defined(_WIDENESS_1024BIT)
constexpr size_t WIDENESS = 1024;
#elif defined(_WIDENESS_524288BIT)
constexpr size_t WIDENESS = 524288;
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
using uint_tA = math::wide_integer::uintwide_t<WIDENESS, uint64_t>;
using uint_tB = epi::whole_number<uint64_t, uint64_t, (WIDENESS / (sizeof(uint_t) * 8))>;
#endif

using uint_tC = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<
  WIDENESS, WIDENESS, boost::multiprecision::cpp_integer_type::unsigned_magnitude,
  boost::multiprecision::cpp_int_check_type::unchecked, void>>;

int main() {
  std::string libA = "[`wide-integer`](https://github.com/ckormanyos/wide-integer)";
  std::string libB = "[`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers)";
  std::string libC = "[`boost::multiprecision`](https://github.com/boostorg/multiprecision)";

  unsigned int    seed = std::chrono::steady_clock::now().time_since_epoch().count();
  std::mt19937_64 rand_engine(seed);

  std::uniform_int_distribution<uint_t> rng(std::numeric_limits<uint_t>::min() + 1, std::numeric_limits<uint_t>::max());

  constexpr size_t cold_runs = 10;
  constexpr size_t mul_cold_runs = 1;
  constexpr size_t div_cold_runs = 1;

  constexpr size_t add_iteration = 10;
  constexpr size_t sub_iteration = 10;
  constexpr size_t mul_iteration = 3;
  constexpr size_t div_iteration = 3;

  constexpr size_t shift_iteration = 10;

  constexpr size_t assigns_iteration = 10;

  if constexpr (sizeof(uint_tA) != sizeof(uint_tB)) {
    std::cout << "Invalid Sizes Detected\n\n";
    return 1;
  }

  constexpr size_t BUFFER_LEN = sizeof(uint_tA) / sizeof(uint_t);
  uint_t           BUFFER[BUFFER_LEN] = {};

// _ARITHMETIC, _ASSIGNED_ARITHMETIC, _SHIFTS

#if defined(_ARITHMETIC)

  std::cout << "## **uint" << WIDENESS << "_t**\n\n";

  {
    std::cout << "## add operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + add_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization add operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed add operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / add_iteration;
    size_t aveB = totalB / add_iteration;
    size_t aveC = totalC / add_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **+** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **+** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **+** | " << aveC << " nanoseconds |\n\n";
  }

  {
    std::cout << "## sub operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + sub_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization sub operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed sub operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / sub_iteration;
    size_t aveB = totalB / sub_iteration;
    size_t aveC = totalC / sub_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **-** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **-** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **-** | " << aveC << " nanoseconds |\n\n";
  }

  {
    std::cout << "## mul operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < mul_cold_runs + mul_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization mul operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed mul operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / mul_iteration;
    size_t aveB = totalB / mul_iteration;
    size_t aveC = totalC / mul_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | ***** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | ***** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | ***** | " << aveC << " nanoseconds |\n\n";
  }

  {
    std::cout << "## div operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < div_cold_runs + div_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization div operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed div operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / div_iteration;
    size_t aveB = totalB / div_iteration;
    size_t aveC = totalC / div_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **/** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **/** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **/** | " << aveC << " nanoseconds |\n\n";
  }

  {
    std::cout << "## mod operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < div_cold_runs + div_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization div operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed div operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / div_iteration;
    size_t aveB = totalB / div_iteration;
    size_t aveC = totalC / div_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **%** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **%** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **%** | " << aveC << " nanoseconds |\n\n";
  }

// _ARITHMETIC, _ASSIGNED_ARITHMETIC, _SHIFTS
#elif defined(_ASSIGNED_ARITHMETIC)

  {
    std::cout << "## assign add operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + add_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization assign_add operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed assign add operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / add_iteration;
    size_t aveB = totalB / add_iteration;
    size_t aveC = totalC / add_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **+=** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **+=** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **+=** | " << aveC << " nanoseconds |\n\n";
  }

  {
    std::cout << "## assign sub operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + sub_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization assign sub operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed assign sub operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / sub_iteration;
    size_t aveB = totalB / sub_iteration;
    size_t aveC = totalC / sub_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **-=** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **-=** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **-=** | " << aveC << " nanoseconds |\n\n";
  }

  {
    std::cout << "## assign mul operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < mul_cold_runs + mul_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization assign mul operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed assign mul operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / mul_iteration;
    size_t aveB = totalB / mul_iteration;
    size_t aveC = totalC / mul_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | ***=** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | ***=** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | ***=** | " << aveC << " nanoseconds |\n\n";
  }

  {
    std::cout << "## assign div operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < div_cold_runs + div_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization assign div operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed assign div operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / div_iteration;
    size_t aveB = totalB / div_iteration;
    size_t aveC = totalC / div_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **/=** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **/=** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **/=** | " << aveC << " nanoseconds |\n\n";
  }

  {
    std::cout << "## assign mod operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < div_cold_runs + div_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization assign mod operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed assign mod operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / div_iteration;
    size_t aveB = totalB / div_iteration;
    size_t aveC = totalC / div_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **%=** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **%=** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **%=** | " << aveC << " nanoseconds |\n\n";
  }

#elif defined(_SHIFTS)
  //

  {
    std::cout << "## left shift operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + shift_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization left shift operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed left shift operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / shift_iteration;
    size_t aveB = totalB / shift_iteration;
    size_t aveC = totalC / shift_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **<<** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **<<** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **<<** | " << aveC << " nanoseconds |\n\n";
  }

  {
    std::cout << "## right shift operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + shift_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization right shift operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed right shift operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / shift_iteration;
    size_t aveB = totalB / shift_iteration;
    size_t aveC = totalC / shift_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **>>** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **>>** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **>>** | " << aveC << " nanoseconds |\n\n";
  }

  // //

  {
    std::cout << "## assign left shift operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + shift_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization assign left shift operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed assign left shift operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / shift_iteration;
    size_t aveB = totalB / shift_iteration;
    size_t aveC = totalC / shift_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **<<=** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **<<=** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **<<=** | " << aveC << " nanoseconds |\n\n";
  }

  {
    std::cout << "## assign right shift operation : \n\n";
    size_t totalA = 0, totalB = 0, totalC = 0;

    for (size_t i = 0; i < cold_runs + shift_iteration; ++i) {
      uint_tA a1 = 0, a2 = 0;
      uint_tB b1 = 0, b2 = 0;
      uint_tC c1 = 0, c2 = 0;

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a1, BUFFER, sizeof(BUFFER));
      std::memcpy(&b1, BUFFER, sizeof(BUFFER));
      std::memcpy(&c1, BUFFER, sizeof(BUFFER));

      BUFFER[0] = rng(rand_engine) ^ 1;
      for (size_t j = 1; j < BUFFER_LEN; ++j) {
        BUFFER[j] = rng(rand_engine);
      }

      std::memcpy(&a2, BUFFER, sizeof(BUFFER));
      std::memcpy(&b2, BUFFER, sizeof(BUFFER));
      std::memcpy(&c2, BUFFER, sizeof(BUFFER));

      if (std::memcmp(&a1, &b1, sizeof(uint_tA)) | std::memcmp(&a1, &c1, sizeof(uint_tA))) {
        std::cout << "Initialization assign right shift operation errorsss\n\n";
        return 1;
      }

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
        uint_t *blimb = (uint_t *) &numB;
        uint_t *climb = (uint_t *) &numC;

        bool boostfalse = false;
        for (size_t i = 0; i < sizeof(uint_tA); ++i) {
          if (!blimb[sizeof(uint_tA) - 1 - i]) {
            climb[sizeof(uint_tA) - 1 - i] = 0x00;
          } else {
            break;
          }
        }

        totalA += durA.count();
        totalB += durB.count();
        totalC += durC.count();

        if (std::memcmp(&numA, &numB, sizeof(uint_tA))) {
          std::cout << "memcmp = " << std::memcmp(&numA, &numC, sizeof(uint_tA)) << "\n";
          std::cout << "Failed assign right shift operation\n\n";
          return 1;
        }
      }
    }

    size_t aveA = totalA / shift_iteration;
    size_t aveB = totalB / shift_iteration;
    size_t aveC = totalC / shift_iteration;

    std::cout << "| Lib | Operator | Average |\n";
    std::cout << "| --- | --- | --- |\n";
    std::cout << "| " << libA << " | **>>=** | " << aveA << " nanoseconds |\n";
    std::cout << "| " << libB << " | **>>=** | " << aveB << " nanoseconds |\n";
    std::cout << "| " << libC << " | **>>=** | " << aveC << " nanoseconds |\n\n";
  }
#endif

  return 0;
}