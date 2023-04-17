#ifndef EXTENDED_PRECISION_INTEGERS_HPP
#define EXTENDED_PRECISION_INTEGERS_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <type_traits>

#include "config.hpp"

namespace epi {

  // Forward declare both templates:
  template <typename limb_t, typename cast_t, size_t limb_n>
  class whole_number;

  template <typename limb_t, typename cast_t, size_t limb_n>
  std::ostream &operator<<(std::ostream &, const whole_number<limb_t, cast_t, limb_n> &);

  template <typename limb_t, typename cast_t, size_t limb_n>
  class whole_number {

    private:

    limb_t limbs[limb_n];

    /// @brief whole_Number base use to represent the integer.
    static constexpr size_t LIMB_BASE = sizeof(limb_t) * 8;
    static constexpr size_t LIMB_BITS = sizeof(limb_t) * 8;

    /// @brief Total bytes of the whole_number<> type.
    static constexpr size_t BYTES = sizeof(limb_t) * limb_n;

    /// @brief Total bits of the whole_number<> type.
    static constexpr size_t BITS = BYTES * 8;

    static constexpr int LESS = -1;
    static constexpr int GREAT = 1;
    static constexpr int EQUAL = 0;

    static constexpr int compare(whole_number const &l, whole_number const &r) {
      int comparison_result = EQUAL;

      for (size_t i = 0; i < limb_n; ++i) {
        if (l.limbs[limb_n - 1 - i] < r.limbs[limb_n - 1 - i]) {
          comparison_result = LESS;
          break;
        } else if (l.limbs[limb_n - 1 - i] > r.limbs[limb_n - 1 - i]) {
          comparison_result = GREAT;
          break;
        }
      }

      return comparison_result;
    }

    public:

    /// default constuctor.
    constexpr whole_number() : limbs() {
      if constexpr (sizeof(limb_t) * 2 != sizeof(cast_t)) {
        throw std::invalid_argument(
          "In 'whole_number<limb_t, cast_t, ...>' : the sizeof(cast_t) should be 2 times the sizeof(limb_t)."
        );
      }
    }

    /// initializer list constructor.
    constexpr whole_number(std::initializer_list<limb_t> num) : whole_number() {
      if (sizeof(limb_t) * limb_n < sizeof(limb_t) * num.size()) {
        throw std::invalid_argument("initializer list has a bigger size than the defined whole_number<> type");
      }

      size_t i = limb_n - 1 - (limb_n - num.size());
      for (auto num_limb: num) {
        limbs[i--] = num_limb;
      }
    }

    /// integral constructor.
    template <typename T>
    constexpr whole_number(T num) : whole_number() {
      // TODO: add check in the future to only accept unsigned integral types

      size_t partition = sizeof(T) / sizeof(limb_t);

      for (size_t i = 0; i < partition; ++i) {
        limbs[i] = num >> (i * sizeof(limb_t) * 8);
      }
    }

    /// copy constructor.
    constexpr whole_number(whole_number const &src) : whole_number() {
      for (size_t i = 0; i < limb_n; ++i) {
        limbs[i] = src.limbs[i];
      }
    }

    /// copy assignment.
    constexpr whole_number &operator=(whole_number const &src) {
      if (this != &src) {
        for (size_t i = 0; i < limb_n; ++i) {
          limbs[i] = src.limbs[i];
        }
      }
      
      return *this;
    }

    friend std::ostream &operator<< <
      limb_t, cast_t, limb_n>(std::ostream &, const whole_number<limb_t, cast_t, limb_n> &);

    // arithmetic operators : start
    constexpr whole_number operator+(whole_number const &add) const {
      whole_number sum;
      limb_t       carry = 0;

      for (size_t i = 0; i < limb_n; ++i) {
        cast_t index_sum = (cast_t) limbs[i] + add.limbs[i] + carry;
        sum.limbs[i] = index_sum;
        carry = index_sum >> LIMB_BASE;
      }

      return sum;
    }

    constexpr whole_number &operator+=(whole_number const &add) {
      limb_t carry = 0;

      for (size_t i = 0; i < limb_n; ++i) {
        cast_t index_sum = (cast_t) limbs[i] + add.limbs[i] + carry;
        limbs[i] = index_sum;
        carry = index_sum >> LIMB_BASE;
      }

      return *this;
    }

    constexpr whole_number operator-(whole_number const &sub) const {
      whole_number diff;
      limb_t       carry = 0;

      for (size_t i = 0; i < limb_n; ++i) {
        cast_t index_diff = (cast_t) limbs[i] - sub.limbs[i] - carry;
        diff.limbs[i] = index_diff;
        carry = (index_diff >> LIMB_BASE) & 0x1;
      }

      return diff;
    }

    constexpr whole_number &operator-=(whole_number const &sub) {
      limb_t carry = 0;

      for (size_t i = 0; i < limb_n; ++i) {
        cast_t index_diff = (cast_t) limbs[i] - sub.limbs[i] - carry;
        limbs[i] = index_diff;
        carry = (index_diff >> LIMB_BASE) & 0x1;
      }

      return *this;
    }

    // pre-fix increment/decrement
    constexpr whole_number &operator++() {
      constexpr whole_number CONSTEXPR_ONE = { 0x01 };
      return *this += CONSTEXPR_ONE;
    }

    constexpr whole_number &operator--() {
      constexpr whole_number CONSTEXPR_ONE = { 0x01 };
      return *this -= CONSTEXPR_ONE;
    }

    // post-fix increment/decrement
    constexpr whole_number operator++(int) {
      whole_number prev = *this;
      ++*this;
      return prev;
    }

    constexpr whole_number operator--(int) {
      whole_number prev = *this;
      --*this;
      return prev;
    }

    constexpr whole_number operator*(whole_number const &mul) const {
      whole_number prod;
      limb_t       carry = 0;

      for (size_t i = 0; i < limb_n; ++i) {
        cast_t index_prod = (cast_t) limbs[i] * mul.limbs[0] + carry;
        prod.limbs[i] = index_prod;
        carry = index_prod >> LIMB_BASE;
      }

      for (size_t i = 1; i < limb_n; ++i) {
        carry = 0;
        for (size_t j = 0; j < limb_n - i; ++j) {
          cast_t index_prod = (cast_t) limbs[j] * mul.limbs[i] + prod.limbs[i + j] + carry;
          prod.limbs[i + j] = index_prod;
          carry = (index_prod >> LIMB_BASE);
        }
      }

      return prod;
    }

    constexpr whole_number &operator*=(whole_number const &mul) {
      *this = *this * mul;
      return *this;
    }
    // arithmetic operators : end

    // relational operators : start
    constexpr bool operator==(whole_number const &op) const {
      return !compare(*this, op);
    }

    constexpr bool operator!=(whole_number const &op) const {
      return compare(*this, op);
    }

    constexpr bool operator<(whole_number const &op) const {
      return compare(*this, op) == LESS;
    }

    constexpr bool operator>(whole_number const &op) const {
      return compare(*this, op) == GREAT;
    }

    constexpr bool operator<=(whole_number const &op) const {
      return compare(*this, op) <= EQUAL;
    }

    constexpr bool operator>=(whole_number const &op) const {
      return compare(*this, op) >= EQUAL;
    }

    // relational operators : end

    // shift operators : start

    constexpr whole_number &operator<<=(size_t lshift) {
      return (*this = *this << lshift);
    }

    constexpr whole_number operator<<(size_t lshift) const {
      whole_number result;

      size_t lshift_internal = lshift % BITS;
      size_t limb_shifts = lshift_internal / LIMB_BITS;
      size_t bit_shifts = lshift_internal % LIMB_BITS;
      size_t i = 0;

      cast_t shifted_index = 0;

      for (; i < limb_n - 1 - limb_shifts; ++i) {
        // memcpy alternative
        shifted_index = limbs[i + 1];
        shifted_index <<= LIMB_BITS;
        shifted_index |= limbs[i];

        // apply shifts
        shifted_index <<= bit_shifts;
        result.limbs[i + limb_shifts] |= shifted_index;
        result.limbs[i + limb_shifts + 1] = (shifted_index >> LIMB_BITS);
      }

      limb_t last_shifted_limb = limbs[i];
      last_shifted_limb <<= bit_shifts;
      result.limbs[i + limb_shifts] |= last_shifted_limb;

      return result;
    }

    constexpr whole_number &operator>>=(size_t rshift) {
      return (*this = *this >> rshift);
    }

    constexpr whole_number operator>>(size_t rshift) const {
      whole_number result;

      size_t rshift_internal = rshift % BITS;
      size_t limb_shifts = rshift_internal / LIMB_BITS;
      size_t bit_shifts = rshift_internal % LIMB_BITS;
      size_t i = 0;

      cast_t shifted_index = 0;

      for (; i < limb_n - 1 - limb_shifts; ++i) {
        // memcpy alternative
        shifted_index = limbs[limb_n - 1 - i];
        shifted_index <<= LIMB_BITS;
        shifted_index |= limbs[limb_n - 2 - i];

        // apply shifts
        shifted_index >>= bit_shifts;
        result.limbs[limb_n - 2 - i - limb_shifts] = shifted_index;
        result.limbs[limb_n - 1 - i - limb_shifts] |= (shifted_index >> LIMB_BITS);
      }

      limb_t last_shifted_limb = limbs[limb_n - 1 - i];
      last_shifted_limb >>= bit_shifts;
      result.limbs[0] |= last_shifted_limb;

      return result;
    }

    // shift operators : end

  }; // whole_number class : end

  template <typename limb_t, typename cast_t, size_t limb_n>
  std::ostream &operator<<(std::ostream &out, const whole_number<limb_t, cast_t, limb_n> &num) {

    if (out.flags() & std::ios_base::hex) {
      auto             prev_ios_width = out.width();
      auto             prev_ios_fill = out.fill();
      constexpr size_t padding = sizeof(limb_t) * 2;

      if constexpr (std::is_same<limb_t, char>::value || std::is_same<limb_t, unsigned char>::value) {
        size_t i = 0;
        for (; i < limb_n; ++i) {
          if (num.limbs[limb_n - 1 - i]) {
            std::cout << (unsigned int) num.limbs[limb_n - 1 - i];
            i++;
            break;
          } else if (i == limb_n - 1 && !num.limbs[limb_n - 1 - i]) {
            std::cout << 0x0;
          }
        }

        for (; i < limb_n; ++i) {
          out << std::setfill('0') << std::setw(padding) << std::right << (unsigned int) num.limbs[limb_n - 1 - i];
        }
        out << std::setfill(prev_ios_fill) << std::setw(prev_ios_width) << std::dec;
      } else {
        size_t i = 0;
        for (; i < limb_n; ++i) {
          if (num.limbs[limb_n - 1 - i]) {
            std::cout << num.limbs[limb_n - 1 - i];
            i++;
            break;
          } else if (i == limb_n - 1 && !num.limbs[limb_n - 1 - i]) {
            std::cout << 0x0;
          }
        }

        for (; i < limb_n; ++i) {
          out << std::setfill('0') << std::setw(padding) << std::right << num.limbs[limb_n - 1 - i];
        }
        out << std::setfill(prev_ios_fill) << std::setw(prev_ios_width) << std::dec;
      }
    } else if (out.flags() & std::ios_base::oct) {
      // print oct
      std::cout << "printing to oct is not supported yet\n";
    } else {
      // print dec
      std::cout << "printing to dec is not supported yet\n";
    }

    return out;
  }

// predefined types
#if defined(ENV_64BIT_EXTENDED)
  typedef whole_number<uint64_t, __uint128_t, 2>   uint128_t;
  typedef whole_number<uint64_t, __uint128_t, 3>   uint192_t;
  typedef whole_number<uint64_t, __uint128_t, 4>   uint256_t;
  typedef whole_number<uint64_t, __uint128_t, 5>   uint320_t;
  typedef whole_number<uint64_t, __uint128_t, 8>   uint512_t;
  typedef whole_number<uint64_t, __uint128_t, 16>  uint1024_t;
  typedef whole_number<uint64_t, __uint128_t, 32>  uint2048_t;
  typedef whole_number<uint64_t, __uint128_t, 64>  uint4096_t;
  typedef whole_number<uint64_t, __uint128_t, 128> uint8192_t;
  typedef whole_number<uint64_t, __uint128_t, 256> uint16384_t;
  typedef whole_number<uint64_t, __uint128_t, 512> uint32768_t;

#elif defined(ENV_64BIT)
  typedef whole_number<uint32_t, uint64_t, 4>    uint128_t;
  typedef whole_number<uint32_t, uint64_t, 6>    uint192_t;
  typedef whole_number<uint32_t, uint64_t, 8>    uint256_t;
  typedef whole_number<uint32_t, uint64_t, 10>   uint320_t;
  typedef whole_number<uint32_t, uint64_t, 16>   uint512_t;
  typedef whole_number<uint32_t, uint64_t, 32>   uint1024_t;
  typedef whole_number<uint32_t, uint64_t, 64>   uint2048_t;
  typedef whole_number<uint32_t, uint64_t, 128>  uint4096_t;
  typedef whole_number<uint32_t, uint64_t, 256>  uint8192_t;
  typedef whole_number<uint32_t, uint64_t, 512>  uint16384_t;
  typedef whole_number<uint32_t, uint64_t, 1024> uint32768_t;
#elif defined(ENV_32BIT)
  typedef whole_number<uint16_t, uint32_t, 4>    uint64_t;
  typedef whole_number<uint16_t, uint32_t, 8>    uint128_t;
  typedef whole_number<uint16_t, uint32_t, 12>   uint192_t;
  typedef whole_number<uint16_t, uint32_t, 16>   uint256_t;
  typedef whole_number<uint16_t, uint32_t, 20>   uint320_t;
  typedef whole_number<uint16_t, uint32_t, 32>   uint512_t;
  typedef whole_number<uint16_t, uint32_t, 64>   uint1024_t;
  typedef whole_number<uint16_t, uint32_t, 128>  uint2048_t;
  typedef whole_number<uint16_t, uint32_t, 256>  uint4096_t;
  typedef whole_number<uint16_t, uint32_t, 512>  uint8192_t;
  typedef whole_number<uint16_t, uint32_t, 1024> uint16384_t;
  typedef whole_number<uint16_t, uint32_t, 2048> uint32768_t;
#endif

} // namespace epi

#endif