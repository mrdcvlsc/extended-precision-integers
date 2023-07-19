#include <iostream>
#include <chrono>
#include <cstring>

#include "../epi.hpp"
#include "wide-integer/math/wide_integer/uintwide_t.h"

using uint524288A_t = math::wide_integer::uintwide_t<524288U, std::uint32_t>;
using uint524288B_t = epi::whole_number<uint32_t, uint64_t, 16384>;

template <typename T, size_t N>
T fib() {
  T t1 = 0, t2 = 1;
  T nth = t1 + t2;
  T sum = t1 + t2 + nth;

  for (size_t i = 3; i < N; ++i) {
    nth = t1 + t2;
    sum += nth;
    t1 = t2;
    t2 = nth;
  }

  return sum;
}

template <typename T, size_t N>
T fib_dif() {
  T t1 = 0, t2 = 1;
  T nth = t1 - t2;
  T sum = t1 - t2 - nth;

  for (size_t i = 3; i < N; ++i) {
    nth = t1 - t2;
    sum -= nth;
    t1 = t2;
    t2 = nth;
  }

  return sum;
}

template <typename T, size_t N>
T fib_mul() {
  T t1 = 2, t2 = 3;
  T nth = t1 * t2;
  T prd = t1 * t2 * nth;

  for (size_t i = 2; i < N; ++i) {
    nth = t1 * t2;
    prd *= nth;
    t1 = t2;
    t2 = nth;
  }

  return prd;
}

template <typename T, size_t N>
T div_test() {
  T max = 0;
  max -= 1;

  for (size_t i = 1; i < N; ++i) {
    max /= i;
  }

  return max;
}

template <typename T, size_t N>
T mod_test() {
  T max = 0;
  max -= 1;

  for (size_t i = 1; i < N; ++i) {
    max %= i;
  }

  return max;
}

int main() {
  constexpr size_t cold_runs = 5;
  constexpr size_t recorded_iterations = 5;

  constexpr size_t fibsum_nth = 3;
  constexpr size_t fibmul_nth = 3;
  constexpr size_t fibdiv_nth = 3;

  std::cout << "Addition : Cold Runs - fib\n";

  for (size_t i = 0; i < cold_runs + recorded_iterations; ++i) {
    auto startA = std::chrono::high_resolution_clock::now();
    uint524288A_t numA = fib<uint524288A_t, fibsum_nth>();
    auto endA = std::chrono::high_resolution_clock::now();
    auto durA = std::chrono::duration_cast<std::chrono::milliseconds>(endA - startA);

    auto startB = std::chrono::high_resolution_clock::now();
    uint524288B_t numB = fib<uint524288B_t, fibsum_nth>();
    auto endB = std::chrono::high_resolution_clock::now();
    auto durB = std::chrono::duration_cast<std::chrono::milliseconds>(endB - startB);

    if (i == cold_runs) {
      std::cout << "Benchmarking Started - fib\n\n";
    }

    if (i > cold_runs) {
      std::cout << "--------------------------------------\n";
      std::cout << "A : fib of " << fibsum_nth << " took " << durA.count() << " milliseconds\n";
      std::cout << "B : fib of " << fibsum_nth << " took " << durB.count() << " milliseconds\n";

      if(std::memcmp(&numA, &numB, sizeof(numA))) {
        throw "failed addition tests";
      }
    }
  }

  std::cout << "\n\nSubtraction : Cold Runs - fib_dif\n";
  for (size_t i = 0; i < cold_runs + recorded_iterations; ++i) {
    auto startA = std::chrono::high_resolution_clock::now();
    uint524288A_t numA = fib_dif<uint524288A_t, fibsum_nth>();
    auto endA = std::chrono::high_resolution_clock::now();
    auto durA = std::chrono::duration_cast<std::chrono::milliseconds>(endA - startA);

    auto startB = std::chrono::high_resolution_clock::now();
    uint524288B_t numB = fib_dif<uint524288B_t, fibsum_nth>();
    auto endB = std::chrono::high_resolution_clock::now();
    auto durB = std::chrono::duration_cast<std::chrono::milliseconds>(endB - startB);

    if (i == cold_runs) {
      std::cout << "Benchmarking Started - fib_dif\n\n";
    }

    if (i > cold_runs) {
      std::cout << "--------------------------------------\n";
      std::cout << "A : fib_dif of " << fibsum_nth << " took " << durA.count() << " milliseconds\n";
      std::cout << "B : fib_dif of " << fibsum_nth << " took " << durB.count() << " milliseconds\n";

      if(std::memcmp(&numA, &numB, sizeof(numA))) {
        throw "failed subtraction tests";
      }
    }
  }

  std::cout << "\n\nMultiplication : Cold Runs - fib_mul\n";
  for (size_t i = 0; i < cold_runs + recorded_iterations; ++i) {
    auto startA = std::chrono::high_resolution_clock::now();
    uint524288A_t numA = fib_mul<uint524288A_t, fibmul_nth>();
    auto endA = std::chrono::high_resolution_clock::now();
    auto durA = std::chrono::duration_cast<std::chrono::milliseconds>(endA - startA);

    auto startB = std::chrono::high_resolution_clock::now();
    uint524288B_t numB = fib_mul<uint524288B_t, fibmul_nth>();
    auto endB = std::chrono::high_resolution_clock::now();
    auto durB = std::chrono::duration_cast<std::chrono::milliseconds>(endB - startB);

    if (i == cold_runs) {
      std::cout << "Benchmarking Started - fib_mul\n\n";
    }

    if (i > cold_runs) {
      std::cout << "--------------------------------------\n";
      std::cout << "A : fib_mul of " << fibmul_nth << " took " << durA.count() << " milliseconds\n";
      std::cout << "B : fib_mul of " << fibmul_nth << " took " << durB.count() << " milliseconds\n";

      if(std::memcmp(&numA, &numB, sizeof(numA))) {
        throw "failed multiplication tests";
      }
    }
  }

  std::cout << "\n\nDivision : Cold Runs - div_test\n";
  for (size_t i = 0; i < cold_runs + recorded_iterations; ++i) {
    auto startA = std::chrono::high_resolution_clock::now();
    uint524288A_t numA = div_test<uint524288A_t, fibdiv_nth>();
    auto endA = std::chrono::high_resolution_clock::now();
    auto durA = std::chrono::duration_cast<std::chrono::milliseconds>(endA - startA);

    auto startB = std::chrono::high_resolution_clock::now();
    uint524288B_t numB = div_test<uint524288B_t, fibdiv_nth>();
    auto endB = std::chrono::high_resolution_clock::now();
    auto durB = std::chrono::duration_cast<std::chrono::milliseconds>(endB - startB);

    if (i == cold_runs) {
      std::cout << "Benchmarking Started - div_test\n\n";
    }

    if (i > cold_runs) {
      std::cout << "--------------------------------------\n";
      std::cout << "A : div_test of " << fibdiv_nth << " took " << durA.count() << " milliseconds\n";
      std::cout << "B : div_test of " << fibdiv_nth << " took " << durB.count() << " milliseconds\n";

      if(std::memcmp(&numA, &numB, sizeof(numA))) {
        throw "failed multiplication tests";
      }
    }
  }

  std::cout << "\n\nModulo : Cold Runs - mod_test\n";
  for (size_t i = 0; i < cold_runs + recorded_iterations; ++i) {
    auto startA = std::chrono::high_resolution_clock::now();
    uint524288A_t numA = mod_test<uint524288A_t, fibdiv_nth>();
    auto endA = std::chrono::high_resolution_clock::now();
    auto durA = std::chrono::duration_cast<std::chrono::milliseconds>(endA - startA);

    auto startB = std::chrono::high_resolution_clock::now();
    uint524288B_t numB = mod_test<uint524288B_t, fibdiv_nth>();
    auto endB = std::chrono::high_resolution_clock::now();
    auto durB = std::chrono::duration_cast<std::chrono::milliseconds>(endB - startB);

    if (i == cold_runs) {
      std::cout << "Benchmarking Started - mod_test\n\n";
    }

    if (i > cold_runs) {
      std::cout << "--------------------------------------\n";
      std::cout << "A : mod_test of " << fibdiv_nth << " took " << durA.count() << " milliseconds\n";
      std::cout << "B : mod_test of " << fibdiv_nth << " took " << durB.count() << " milliseconds\n";

      if(std::memcmp(&numA, &numB, sizeof(numA))) {
        throw "failed multiplication tests";
      }
    }
  }
}