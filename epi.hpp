#ifndef EXTENDED_PRECISION_INTEGERS_HPP
#define EXTENDED_PRECISION_INTEGERS_HPP

#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <type_traits>

#include "config.hpp"

namespace epi {

  /// @brief Template Class for creating any fixed arbitrary sized whole numbers.
  ///
  /// @note Example: an unsigned 128 bit integer is equal to whole_number<uint32_t, uint64_t, 4>,
  /// this is because 32 * 4 = 128 so basically we just used four uint32_t to represent a uint128_t.
  ///
  /// @tparam limb_t any unsigned integral types.
  /// @tparam cast_t unsigned integral types that is exactly two times bigger than limb_t.
  /// @tparam limb_n number of limbs a whole number representation will have.
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

    static constexpr int LIMB_OCCUPATION_ZERO = 0;
    static constexpr int LIMB_OCCUPATION_ONE = 1;
    static constexpr int LIMB_OCCUPATION_MULTIPLE = 2;

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

    /// @return 0 - if a zero integer, return 1 - if has one limb, return 2 - if has higher limb value occupations.
    constexpr int is_one_limb() const {
      limb_t upper_values = 0;
      for (size_t i = 1; i < limb_n; ++i) {
        upper_values |= limbs[i];
      }

      if (upper_values) {
        return 2; // has multiple limbs occupied by some value.
      }

      return (false ^ limbs[0]); // 0 or 1
    }

    // divs

    constexpr whole_number bit_long_div(whole_number const &divisor) const {
      constexpr size_t MS_LIMB = limb_n - 1;
      whole_number     quotient = {0}, remainder = {0};
      limb_t           remainder_bit = 0, one_bit = 1;
      size_t           index = 0, shift_value = 0;

      for (size_t i = 0; i < BITS; ++i) {
        index = MS_LIMB - i / LIMB_BITS;
        shift_value = i % LIMB_BITS;

        remainder = remainder << 1;
        remainder_bit = limbs[index] << shift_value;
        remainder_bit >>= LIMB_BITS - 1;

        remainder.limbs[0] |= remainder_bit;

        if (remainder >= divisor) {
          remainder -= divisor;
          quotient.limbs[index] |= (one_bit << ((LIMB_BITS - 1) - shift_value));
        }
      }

      return quotient;
    }

    constexpr whole_number &self_bit_long_div(whole_number const &divisor) {
      constexpr size_t MS_LIMB = limb_n - 1;
      whole_number     remainder = {0};
      limb_t           remainder_bit = 0, one_bit = 1;
      size_t           index = 0, shift_value = 0;

      limb_t partial_quotient = 0;
      size_t prev_index = MS_LIMB - 0 / LIMB_BITS;

      for (size_t i = 0; i < BITS; ++i) {
        index = MS_LIMB - i / LIMB_BITS;
        shift_value = i % LIMB_BITS;

        remainder = remainder << 1;
        remainder_bit = limbs[index] << shift_value;
        remainder_bit >>= LIMB_BITS - 1;

        remainder.limbs[0] |= remainder_bit;

        if (prev_index != index) {
          limbs[prev_index] = partial_quotient;
          partial_quotient = 0;
          prev_index = index;
        }

        if (remainder >= divisor) {
          remainder -= divisor;
          partial_quotient |= (one_bit << ((LIMB_BITS - 1) - shift_value));
        }
      }

      limbs[prev_index] = partial_quotient;

      return *this;
    }

    constexpr whole_number div_by_1limb(limb_t divisor) const {
      whole_number quotient;
      cast_t       remainder = 0;

      remainder = limbs[limb_n - 1] % divisor;
      remainder <<= LIMB_BITS;
      quotient.limbs[limb_n - 1] = limbs[limb_n - 1] / divisor;

      for (size_t i = 1; i < limb_n; ++i) {
        remainder |= limbs[limb_n - 1 - i];
        quotient.limbs[limb_n - 1 - i] = remainder / divisor;
        remainder = (remainder % divisor) << LIMB_BITS;
      }

      return quotient;
    }

    constexpr whole_number &self_div_by_1limb(limb_t divisor) {
      cast_t remainder = 0;

      remainder = limbs[limb_n - 1] % divisor;
      remainder <<= LIMB_BITS;
      limbs[limb_n - 1] = limbs[limb_n - 1] / divisor;

      for (size_t i = 1; i < limb_n; ++i) {
        remainder |= limbs[limb_n - 1 - i];
        limbs[limb_n - 1 - i] = remainder / divisor;
        remainder = (remainder % divisor) << LIMB_BITS;
      }

      return *this;
    }

    // mods

    constexpr whole_number bit_long_mod(whole_number const &divisor) const {
      constexpr size_t MS_LIMB = limb_n - 1;
      whole_number     remainder = {0};
      limb_t           remainder_bit = 0;

      for (size_t i = 0; i < BITS; ++i) {
        remainder = remainder << 1;
        remainder_bit = limbs[MS_LIMB - i / LIMB_BITS] << i % LIMB_BITS;
        remainder_bit >>= LIMB_BITS - 1;

        remainder.limbs[0] |= remainder_bit;

        if (remainder >= divisor) {
          remainder -= divisor;
        }
      }

      return remainder;
    }

    constexpr limb_t mod_by_1limb(limb_t divisor) const {
      cast_t remainder = 0;

      remainder = limbs[limb_n - 1] % divisor;
      remainder <<= LIMB_BITS;

      for (size_t i = 1; i < limb_n; ++i) {
        remainder |= limbs[limb_n - 1 - i];
        remainder = (remainder % divisor) << LIMB_BITS;
      }

      return remainder >> LIMB_BITS;
    }

    public:

    /// default constuctor.
    constexpr whole_number() : limbs() {
      static_assert(
        std::is_unsigned_v<limb_t>,
        "limb_t should be an unsigned integral type"
      );

      static_assert(
        std::is_unsigned_v<cast_t>,
        "cast_t should be an unsigned integral type"
      );

      static_assert(
        sizeof(limb_t) * 2 == sizeof(cast_t),
        "invalid template arguments for whole_number<limb_t, cast_t, size_t> :"
        " cast_t should be two times of the size of limb_t"
      );
    }

    /// initializer list constructor.
    constexpr whole_number(std::initializer_list<limb_t> num) : whole_number() {
      if (num.size() > limb_n) {
        throw std::invalid_argument("initializer list elements should be less than or equal the limb_n");
      }

      size_t i = limb_n - 1 - (limb_n - num.size());
      for (auto e: num) {
        limbs[i--] = e;
      }
    }

    /// integral constructor.
    template <typename T>
    constexpr whole_number(T num) : whole_number() {
      static_assert(
        std::is_integral_v<T>,
        "literal should be of integral type"
      );

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
      constexpr whole_number CONSTEXPR_ONE = {0x01};
      return *this += CONSTEXPR_ONE;
    }

    constexpr whole_number &operator--() {
      constexpr whole_number CONSTEXPR_ONE = {0x01};
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

    constexpr whole_number operator/(whole_number const &div) const {
      if (!div) {
        throw std::domain_error("detected whole_number - division by zero");
      }

      constexpr whole_number CONSTEXPR_ONE = {1};
      constexpr whole_number CONSTEXPR_ZERO = {0};

      int div_case = div.is_one_limb();
      int cmp_case = compare(*this, div);

      switch (cmp_case) {
        case EQUAL:
          return CONSTEXPR_ONE;
        case LESS:
          return CONSTEXPR_ZERO;
      }

      if (div_case == LIMB_OCCUPATION_ONE && div.limbs[0] == 1) {
        return *this;
      } else if (div_case == LIMB_OCCUPATION_ONE) {
        return div_by_1limb(div.limbs[0]);
      }

      return bit_long_div(div);
    }

    constexpr whole_number &operator/=(whole_number const &div) {
      if (!div) {
        throw std::domain_error("detected whole_number - division by zero");
      }

      int div_case = div.is_one_limb();
      int cmp_case = compare(*this, div);

      switch (cmp_case) {
        case EQUAL: {
          limbs[0] = 1;
          for (size_t i = 1; i < limb_n; ++i) {
            limbs[i] = 0;
          }
        }
          return *this;
        case LESS: {
          for (size_t i = 0; i < limb_n; ++i) {
            limbs[i] = 0;
          }
        }
          return *this;
      }

      if (div_case == LIMB_OCCUPATION_ONE && div.limbs[0] == 1) {
        return *this;
      } else if (div_case == LIMB_OCCUPATION_ONE) {
        self_div_by_1limb(div.limbs[0]);
        return *this;
      }

      self_bit_long_div(div);
      return *this;
    }

    constexpr whole_number operator%(whole_number const &mod) const {
      if (!mod) {
        throw std::domain_error("detected whole_number - mod by zero");
      }

      constexpr whole_number CONSTEXPR_ZERO = {0};

      int mod_case = mod.is_one_limb();
      int cmp_case = compare(*this, mod);

      switch (cmp_case) {
        case EQUAL:
          return CONSTEXPR_ZERO;
        case LESS:
          return *this;
      }

      if (mod_case == LIMB_OCCUPATION_ONE && mod.limbs[0] == 1) {
        return CONSTEXPR_ZERO;
      } else if (mod_case == LIMB_OCCUPATION_ONE) {
        return mod_by_1limb(mod.limbs[0]);
      }

      return bit_long_mod(mod);
    }

    constexpr whole_number &operator%=(whole_number const &mod) {
      if (!mod) {
        throw std::domain_error("detected whole_number - mod by zero");
      }

      int mod_case = mod.is_one_limb();
      int cmp_case = compare(*this, mod);

      switch (cmp_case) {
        case EQUAL: {
          for (size_t i = 0; i < limb_n; ++i) {
            limbs[i] = 0;
          }
        }
          return *this;
        case LESS:
          return *this;
      }

      if (mod_case == LIMB_OCCUPATION_ONE && mod.limbs[0] == 1) {
        for (size_t i = 0; i < limb_n; ++i) {
          limbs[i] = 0;
        }
        return *this;
      } else if (mod_case == LIMB_OCCUPATION_ONE) {
        limbs[0] = mod_by_1limb(mod.limbs[0]);
        for (size_t i = 1; i < limb_n; ++i) {
          limbs[i] = 0;
        }
        return *this;
      }

      *this = bit_long_mod(mod);
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

    /// @brief automatically resolve the logical &&, ||, and ! operators.
    constexpr explicit operator bool() const noexcept {
      limb_t result = 0;
      for (size_t i = 0; i < limb_n; ++i) {
        result |= limbs[i];
      }

      return result;
    }

    // bitwise logical operators : start

    constexpr whole_number &operator&=(whole_number const &op) {
      for (size_t i = 0; i < limb_n; ++i) {
        limbs[i] &= op.limbs[i];
      }
      return *this;
    }

    constexpr whole_number &operator|=(whole_number const &op) {
      for (size_t i = 0; i < limb_n; ++i) {
        limbs[i] |= op.limbs[i];
      }
      return *this;
    }

    constexpr whole_number &operator^=(whole_number const &op) {
      for (size_t i = 0; i < limb_n; ++i) {
        limbs[i] ^= op.limbs[i];
      }
      return *this;
    }

    constexpr whole_number operator&(whole_number const &op) const {
      whole_number bwl_and;
      for (size_t i = 0; i < limb_n; ++i) {
        bwl_and.limbs[i] = limbs[i] & op.limbs[i];
      }
      return bwl_and;
    }

    constexpr whole_number operator|(whole_number const &op) const {
      whole_number bwl_or;
      for (size_t i = 0; i < limb_n; ++i) {
        bwl_or.limbs[i] = limbs[i] | op.limbs[i];
      }
      return bwl_or;
    }

    constexpr whole_number operator^(whole_number const &op) const {
      whole_number bwl_xor;
      for (size_t i = 0; i < limb_n; ++i) {
        bwl_xor.limbs[i] = limbs[i] ^ op.limbs[i];
      }
      return bwl_xor;
    }

    constexpr whole_number operator~() const {
      whole_number bwln = *this;
      for (size_t i = 0; i < limb_n; ++i) {
        bwln.limbs[i] = ~bwln.limbs[i];
      }

      return bwln;
    }

    // bitwise logical operators : end

    // bitwise logical operators for integral operands : start

    constexpr whole_number &operator&=(limb_t op) {
      limbs[0] &= op;
      return *this;
    }

    constexpr whole_number &operator|=(limb_t op) {
      limbs[0] |= op;
      return *this;
    }

    constexpr whole_number &operator^=(limb_t op) {
      limbs[0] ^= op;
      return *this;
    }

    constexpr whole_number operator&(limb_t op) const {
      whole_number bwl_and;
      bwl_and.limbs[0] = limbs[0] & op;
      return bwl_and;
    }

    constexpr whole_number operator|(limb_t op) const {
      whole_number bwl_or;
      bwl_or.limbs[0] = limbs[0] | op;
      return bwl_or;
    }

    constexpr whole_number operator^(limb_t op) const {
      whole_number bwl_xor;
      bwl_xor.limbs[0] = limbs[0] ^ op;
      return bwl_xor;
    }

    // bitwise logical operators for integral operands : end

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

namespace std {
  template <typename limb_t, typename cast_t, size_t limb_n>
  struct numeric_limits<epi::whole_number<limb_t, cast_t, limb_n>> {
    // static constexpr bool is_specialized = true;

    constexpr static epi::whole_number<limb_t, cast_t, limb_n> max() {
      constexpr size_t                          limb_bits = sizeof(limb_t) * 8;
      constexpr limb_t                          max_limb = std::numeric_limits<limb_t>::max();
      epi::whole_number<limb_t, cast_t, limb_n> max_value = max_limb;
      for (size_t i = 0; i < limb_n - 1; ++i) {
        max_value <<= limb_bits;
        max_value |= max_limb;
      }
      return max_value;
    }

    constexpr static epi::whole_number<limb_t, cast_t, limb_n> min() {
      constexpr size_t                          limb_bits = sizeof(limb_t) * 8;
      constexpr limb_t                          min_limb = std::numeric_limits<limb_t>::min();
      epi::whole_number<limb_t, cast_t, limb_n> min_value = min_limb;
      for (size_t i = 0; i < limb_n - 1; ++i) {
        min_value <<= limb_bits;
        min_value |= min_limb;
      }
      return min_value;
    }
  };
} // namespace std

#endif