#ifndef MRDCVLSC_EXTENDED_PRECISION_INTEGERS_HPP
#define MRDCVLSC_EXTENDED_PRECISION_INTEGERS_HPP

#include <cmath>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <ostream>
#include <random>
#include <stdexcept>
#include <string_view>
#include <type_traits>

#include "config.hpp"
#include "constants.hpp"
#include "meta-functions.hpp"

namespace epi {

#if (__cplusplus < 201703L)
  #error C++17 is needed
#else

  /// @brief Template Class for creating any fixed arbitrary sized whole numbers.
  ///
  /// @note Example: an unsigned 128 bit integer is equal to whole_number<uint32_t, uint64_t, 4>,
  /// this is because 32 * 4 = 128 so basically we just used four uint32_t to represent a uint128_t.
  ///
  /// @tparam limb_t any unsigned integral types.
  /// @tparam cast_t unsigned integral types that is exactly two times bigger than limb_t.
  /// @tparam limb_n number of limbs a whole number representation will have.
  template <typename limb_t, typename cast_t, size_t bits_n>
  class whole_number {

    /// @brief number of bits in a limb, or the number base of a limb.
    static constexpr size_t LIMB_BITS = sizeof(limb_t) * 8;

    static constexpr bool incompatible_limb_t_for_bits_n = bits_n % (LIMB_BITS) == 0;
    static_assert(incompatible_limb_t_for_bits_n, "`bits_n` should be divisible by the `sizeof(limb_t)`");
    static constexpr size_t limb_n = bits_n / (LIMB_BITS);

    static constexpr int LESS = -1;
    static constexpr int GREAT = 1;
    static constexpr int EQUAL = 0;

    /// @brief The maximum base 10 digit count.
    static constexpr size_t BASE10_DIGIT_CAP = compile_time::base10_digit_capacity<bits_n>::value;

    /// @brief The maximum base 8 digit count.
    static constexpr size_t BASE8_DIGIT_CAP = compile_time::base8_digit_capacity<bits_n>::value;

    limb_t limbs[limb_n];

    public:

    /// default constuctor.
    constexpr whole_number() noexcept : limbs() {
      constexpr bool invalid_limb_t = std::is_unsigned_v<limb_t>;
      constexpr bool invalid_cast_t = std::is_unsigned_v<cast_t> || std::is_same_v<__uint128_t, cast_t>;
      constexpr bool wrong_cast_t_size = sizeof(limb_t) * 2 == sizeof(cast_t);

      if constexpr (!invalid_limb_t) {
        static_assert(invalid_limb_t, "limb_t should be an unsigned integral type");
      } else if constexpr (!invalid_cast_t) {
        static_assert(invalid_cast_t, "cast_t should be an unsigned integral type");
      } else if constexpr (!wrong_cast_t_size) {
        static_assert(wrong_cast_t_size, "sizeof(cast_t) should be exactly 2x the sizeof(limb_t)");
      }
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

    constexpr whole_number(std::string_view const &num) : whole_number() {
      if (num.empty()) {
        throw std::length_error("empty char*/string constructor are not allowed");
      }

      constants::base_t base = constants::base_t::invalid;

      bool is_all_digit = true;

      for (auto c: num) {
        if (!(c >= '0' && c <= '9')) {
          is_all_digit = false;
          break;
        }
      }

      // determine what number base representation does the input number string is in
      // and check its validity after.

      if (is_all_digit) {
        constexpr size_t base10_max_digits = BASE10_DIGIT_CAP;
        if (num.size() > base10_max_digits) {
          throw std::length_error("base 10 number string exceed the max number of digits");
        } else if (!valid_base10(num)) {
          throw std::length_error("invalid digit character detected");
        }
        base = constants::base_t::dec;
      } else {
        if (num.size() >= 3 && num.front() == '0') {
          if (num[1] == 'b') {
            constexpr size_t base2_max_digits = bits_n;
            if ((num.size() - 2) > base2_max_digits) {
              throw std::length_error("binary string exceed the max number of digits");
            } else if (!valid_base2(num)) {
              throw std::length_error("invalid binary character detected");
            }
            base = constants::base_t::bin;
          } else if (num[1] == 'o') {
            constexpr size_t base8_max_digits = BASE8_DIGIT_CAP;
            if ((num.size() - 2) > base8_max_digits) {
              throw std::length_error("octal string exceed the max number of digits");
            } else if (!valid_base8(num)) {
              throw std::length_error("invalid octal character detected");
            }
            base = constants::base_t::oct;
          } else if (num[1] == 'x') {
            constexpr size_t base16_max_digits = limb_n * sizeof(limb_t) * 2;
            if ((num.size() - 2) > base16_max_digits) {
              throw std::length_error("hex string exceed the max number of digits");
            } else if (!valid_base16(num)) {
              throw std::length_error("invalid hex character detected");
            }
            base = constants::base_t::hex;
          }
        }
      }

      // convert the current number base string representation into it's actual in memory value.

      if (base == constants::base_t::dec) {
        constexpr size_t output_len = BASE10_DIGIT_CAP;
        size_t           offset = output_len - num.size();

        std::uint8_t output[output_len] = {};

        constexpr size_t base = 10;

        for (size_t i = 0; i < num.size(); ++i) {
          uint8_t carry = num[i] - '0';
          size_t  j = num.size();
          while (j--) {
            uint8_t tmp = output[j + offset] * base + carry;
            output[j + offset] = tmp % 16;
            carry = tmp / 16;
          }
        }

        /// In one byte we have a max of 2 hex character, where each char is 4 bit.
        constexpr size_t HEX_CHAR_BITS = 4;
        constexpr size_t HEX_CHAR_PER_LIMB = sizeof(limb_t) * 2;

        for (size_t i = 0; i < limb_n * HEX_CHAR_PER_LIMB; ++i) {
          limbs[i / HEX_CHAR_PER_LIMB] |= ((limb_t) output[output_len - 1 - i])
                                          << (HEX_CHAR_BITS * (i % HEX_CHAR_PER_LIMB));
        }
      } else if (base == constants::base_t::bin) {
        for (size_t i = 0; i < num.size() - 2; ++i) {
          limb_t           hex_char = num[num.size() - 1 - i] - '0';
          constexpr size_t BIN_CHAR_BITS = 1;
          limbs[i / (LIMB_BITS)] |= (hex_char << (BIN_CHAR_BITS * (i % (LIMB_BITS))));
        }
      } else if (base == constants::base_t::oct) {
        constexpr size_t output_len = BASE8_DIGIT_CAP;
        size_t           offset = output_len - (num.size() - 2);

        std::uint8_t output[output_len] = {};

        constexpr size_t base = 8;

        for (size_t i = 0; i < (num.size() - 2); ++i) {
          uint8_t carry = num[i + 2] - '0';
          size_t  j = (num.size() - 2);
          while (j--) {
            uint8_t tmp = output[j + offset] * base + carry;
            output[j + offset] = tmp % 16;
            carry = tmp / 16;
          }
        }

        /// In one byte we have a max of 2 hex character, where each char is 4 bit.
        constexpr size_t HEX_CHAR_BITS = 4;
        constexpr size_t HEX_CHAR_PER_LIMB = sizeof(limb_t) * 2;

        for (size_t i = 0; i < limb_n * HEX_CHAR_PER_LIMB; ++i) {
          limbs[i / HEX_CHAR_PER_LIMB] |= ((limb_t) output[output_len - 1 - i])
                                          << (HEX_CHAR_BITS * (i % HEX_CHAR_PER_LIMB));
        }
      } else if (base == constants::base_t::hex) {
        for (size_t i = 0; i < num.size() - 2; ++i) {
          limb_t           hex_char = constants::CHAR_TO_HEX[(unsigned char) num[num.size() - 1 - i]];
          constexpr size_t HEX_CHAR_BITS = 4;
          limbs[i / (sizeof(limb_t) * 2)] |= (hex_char << (HEX_CHAR_BITS * (i % (sizeof(limb_t) * 2))));
        }
      } else {
        throw std::invalid_argument("char*/string should be in a proper number base format");
      }
    }

    /// integral constructor.
    constexpr whole_number(size_t num) noexcept : whole_number() {
      constexpr size_t partition = sizeof(size_t) / sizeof(limb_t);

      if constexpr (partition) {
        for (size_t i = 0; i < partition; ++i) {
          limbs[i] = num >> (i * LIMB_BITS);
        }
      } else if constexpr (!partition) {
        limbs[0] = num;
      }
    }

    /// copy constructor.
    constexpr whole_number(whole_number const &src) noexcept : whole_number() {
      for (size_t i = 0; i < limb_n; ++i) {
        limbs[i] = src.limbs[i];
      }
    }

    /// copy assignment.
    constexpr whole_number &operator=(whole_number const &src) noexcept {
      if (this != &src) {
        for (size_t i = 0; i < limb_n; ++i) {
          limbs[i] = src.limbs[i];
        }
      }

      return *this;
    }

    // friend std::ostream &operator<< <limb_t, cast_t, limb_n>(std::ostream &);
    friend std::ostream &operator<<(std::ostream &out, const whole_number &num) {
      if (out.flags() & std::ios_base::hex) {
        auto             prev_ios_width = out.width();
        auto             prev_ios_fill = out.fill();
        constexpr size_t padding = sizeof(limb_t) * 2;

        if constexpr (std::is_same<limb_t, char>::value || std::is_same<limb_t, unsigned char>::value) {
          size_t i = 0;
          for (; i < limb_n; ++i) {
            if (num.limbs[limb_n - 1 - i]) {
              out << (unsigned int) num.limbs[limb_n - 1 - i];
              i++;
              break;
            } else if (i == limb_n - 1 && !num.limbs[limb_n - 1 - i]) {
              out << 0x0;
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
              out << num.limbs[limb_n - 1 - i];
              i++;
              break;
            } else if (i == limb_n - 1 && !num.limbs[limb_n - 1 - i]) {
              out << 0x0;
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

    // arithmetic operators : start
    constexpr whole_number operator+(whole_number const &add) const noexcept {
      whole_number sum;
      limb_t       carry = 0;

      for (size_t i = 0; i < limb_n; ++i) {
        cast_t index_sum = (cast_t) limbs[i] + add.limbs[i] + carry;
        sum.limbs[i] = index_sum;
        carry = index_sum >> LIMB_BITS;
      }

      return sum;
    }

    constexpr whole_number &operator+=(whole_number const &add) noexcept {
      limb_t carry = 0;

      for (size_t i = 0; i < limb_n; ++i) {
        cast_t index_sum = (cast_t) limbs[i] + add.limbs[i] + carry;
        limbs[i] = index_sum;
        carry = index_sum >> LIMB_BITS;
      }

      return *this;
    }

    constexpr whole_number operator-(whole_number const &sub) const noexcept {
      whole_number diff;
      limb_t       carry = 0;

      for (size_t i = 0; i < limb_n; ++i) {
        cast_t index_diff = (cast_t) limbs[i] - sub.limbs[i] - carry;
        diff.limbs[i] = index_diff;
        carry = (index_diff >> LIMB_BITS) & 0x1;
      }

      return diff;
    }

    constexpr whole_number &operator-=(whole_number const &sub) noexcept {
      limb_t carry = 0;

      for (size_t i = 0; i < limb_n; ++i) {
        cast_t index_diff = (cast_t) limbs[i] - sub.limbs[i] - carry;
        limbs[i] = index_diff;
        carry = (index_diff >> LIMB_BITS) & 0x1;
      }

      return *this;
    }

    // pre-fix increment/decrement
    constexpr whole_number &operator++() noexcept {
      constexpr whole_number CONSTEXPR_ONE = {0x01};
      return *this += CONSTEXPR_ONE;
    }

    constexpr whole_number &operator--() noexcept {
      constexpr whole_number CONSTEXPR_ONE = {0x01};
      return *this -= CONSTEXPR_ONE;
    }

    // post-fix increment/decrement
    constexpr whole_number operator++(int) noexcept {
      whole_number prev = *this;
      ++*this;
      return prev;
    }

    constexpr whole_number operator--(int) noexcept {
      whole_number prev = *this;
      --*this;
      return prev;
    }

    constexpr whole_number operator*(whole_number const &mul) const noexcept {
      whole_number prod;
      limb_t       carry = 0;

      for (size_t i = 0; i < limb_n; ++i) {
        cast_t index_prod = (cast_t) limbs[i] * mul.limbs[0] + carry;
        prod.limbs[i] = index_prod;
        carry = index_prod >> LIMB_BITS;
      }

      for (size_t i = 1; i < limb_n; ++i) {
        carry = 0;
        for (size_t j = 0; j < limb_n - i; ++j) {
          cast_t index_prod = (cast_t) limbs[j] * mul.limbs[i] + prod.limbs[i + j] + carry;
          prod.limbs[i + j] = index_prod;
          carry = (index_prod >> LIMB_BITS);
        }
      }

      return prod;
    }

    constexpr whole_number &operator*=(whole_number const &mul) noexcept {
      *this = *this * mul;
      return *this;
    }

    constexpr whole_number operator/(whole_number const &div) const {
      if (!div) {
        throw std::domain_error("detected whole_number - division by zero");
      }

      constexpr whole_number CONSTEXPR_ONE = {1};
      constexpr whole_number CONSTEXPR_ZERO = {0};

      int limb_used = div.is_one_limb();
      int cmp_case = compare(*this, div);

      switch (cmp_case) {
        case EQUAL:
          return CONSTEXPR_ONE;
        case LESS:
          return CONSTEXPR_ZERO;
      }

      constexpr int ONE_LIMB_ONLY = 1;

      if (limb_used == ONE_LIMB_ONLY && div.limbs[0] == 1) {
        return *this;
      } else if (limb_used == ONE_LIMB_ONLY) {
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

      constexpr int ONE_LIMB_ONLY = 1;

      if (div_case == ONE_LIMB_ONLY && div.limbs[0] == 1) {
        return *this;
      } else if (div_case == ONE_LIMB_ONLY) {
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

      constexpr int ONE_LIMB_ONLY = 1;

      if (mod_case == ONE_LIMB_ONLY && mod.limbs[0] == 1) {
        return CONSTEXPR_ZERO;
      } else if (mod_case == ONE_LIMB_ONLY) {
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

      constexpr int ONE_LIMB_ONLY = 1;

      if (mod_case == ONE_LIMB_ONLY && mod.limbs[0] == 1) {
        for (size_t i = 0; i < limb_n; ++i) {
          limbs[i] = 0;
        }
        return *this;
      } else if (mod_case == ONE_LIMB_ONLY) {
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
    constexpr bool operator==(whole_number const &op) const noexcept {
      return !compare(*this, op);
    }

    constexpr bool operator!=(whole_number const &op) const noexcept {
      return compare(*this, op);
    }

    constexpr bool operator<(whole_number const &op) const noexcept {
      return compare(*this, op) == LESS;
    }

    constexpr bool operator>(whole_number const &op) const noexcept {
      return compare(*this, op) == GREAT;
    }

    constexpr bool operator<=(whole_number const &op) const noexcept {
      return compare(*this, op) <= EQUAL;
    }

    constexpr bool operator>=(whole_number const &op) const noexcept {
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

    constexpr whole_number &operator&=(whole_number const &op) noexcept {
      for (size_t i = 0; i < limb_n; ++i) {
        limbs[i] &= op.limbs[i];
      }
      return *this;
    }

    constexpr whole_number &operator|=(whole_number const &op) noexcept {
      for (size_t i = 0; i < limb_n; ++i) {
        limbs[i] |= op.limbs[i];
      }
      return *this;
    }

    constexpr whole_number &operator^=(whole_number const &op) noexcept {
      for (size_t i = 0; i < limb_n; ++i) {
        limbs[i] ^= op.limbs[i];
      }
      return *this;
    }

    constexpr whole_number operator&(whole_number const &op) const noexcept {
      whole_number bwl_and;
      for (size_t i = 0; i < limb_n; ++i) {
        bwl_and.limbs[i] = limbs[i] & op.limbs[i];
      }
      return bwl_and;
    }

    constexpr whole_number operator|(whole_number const &op) const noexcept {
      whole_number bwl_or;
      for (size_t i = 0; i < limb_n; ++i) {
        bwl_or.limbs[i] = limbs[i] | op.limbs[i];
      }
      return bwl_or;
    }

    constexpr whole_number operator^(whole_number const &op) const noexcept {
      whole_number bwl_xor;
      for (size_t i = 0; i < limb_n; ++i) {
        bwl_xor.limbs[i] = limbs[i] ^ op.limbs[i];
      }
      return bwl_xor;
    }

    constexpr whole_number operator~() const noexcept {
      whole_number bwln = *this;
      for (size_t i = 0; i < limb_n; ++i) {
        bwln.limbs[i] = ~bwln.limbs[i];
      }

      return bwln;
    }

    // bitwise logical operators : end

    // bitwise logical operators for integral operands : start

    constexpr whole_number &operator&=(limb_t op) noexcept {
      limbs[0] &= op;
      return *this;
    }

    constexpr whole_number &operator|=(limb_t op) noexcept {
      limbs[0] |= op;
      return *this;
    }

    constexpr whole_number &operator^=(limb_t op) noexcept {
      limbs[0] ^= op;
      return *this;
    }

    constexpr whole_number operator&(limb_t op) const noexcept {
      whole_number bwl_and;
      bwl_and.limbs[0] = limbs[0] & op;
      return bwl_and;
    }

    constexpr whole_number operator|(limb_t op) const noexcept {
      whole_number bwl_or;
      bwl_or.limbs[0] = limbs[0] | op;
      return bwl_or;
    }

    constexpr whole_number operator^(limb_t op) const noexcept {
      whole_number bwl_xor;
      bwl_xor.limbs[0] = limbs[0] ^ op;
      return bwl_xor;
    }

    // bitwise logical operators for integral operands : end

    // shift operators : start

    constexpr whole_number &operator<<=(size_t lshift) noexcept {
      return (*this = *this << lshift);
    }

    constexpr whole_number operator<<(size_t lshift) const noexcept {
      whole_number result;

      size_t lshift_internal = lshift % bits_n;
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

    constexpr whole_number &operator>>=(size_t rshift) noexcept {
      return (*this = *this >> rshift);
    }

    constexpr whole_number operator>>(size_t rshift) const noexcept {
      whole_number result;

      size_t rshift_internal = rshift % bits_n;
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

    private:

    static constexpr bool valid_base16(std::string_view const &num) {
      for (size_t i = 2; i < num.size(); ++i) {
        if (!((num[i] >= '0' && num[i] <= '9') || (num[i] >= 'a' && num[i] <= 'f'))) {
          return false;
        }
      }
      return true;
    }

    static constexpr bool valid_base10(std::string_view const &num) {
      for (size_t i = 0; i < num.size(); ++i) {
        if (!(num[i] >= '0' && num[i] <= '9')) {
          return false;
        }
      }
      return true;
    }

    static constexpr bool valid_base8(std::string_view const &num) {
      for (size_t i = 2; i < num.size(); ++i) {
        if (!(num[i] >= '0' && num[i] <= '7')) {
          return false;
        }
      }
      return true;
    }

    static constexpr bool valid_base2(std::string_view const &num) {
      for (size_t i = 2; i < num.size(); ++i) {
        if (!(num[i] == '0' || num[i] == '1')) {
          return false;
        }
      }
      return true;
    }

    static constexpr int compare(whole_number const &l, whole_number const &r) noexcept {
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
    constexpr int is_one_limb() const noexcept {
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

    constexpr whole_number bit_long_div(whole_number const &divisor) const noexcept {
      constexpr size_t MS_LIMB = limb_n - 1;
      whole_number     quotient = {0}, remainder = {0};
      limb_t           remainder_bit = 0, one_bit = 1;
      size_t           index = 0, shift_value = 0;

      for (size_t i = 0; i < bits_n; ++i) {
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

    constexpr whole_number &self_bit_long_div(whole_number const &divisor) noexcept {
      constexpr size_t MS_LIMB = limb_n - 1;
      whole_number     remainder = {0};
      limb_t           remainder_bit = 0, one_bit = 1;
      size_t           index = 0, shift_value = 0;

      limb_t partial_quotient = 0;
      size_t prev_index = MS_LIMB - 0 / LIMB_BITS;

      for (size_t i = 0; i < bits_n; ++i) {
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

    constexpr whole_number div_by_1limb(limb_t divisor) const noexcept {
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

    constexpr whole_number &self_div_by_1limb(limb_t divisor) noexcept {
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

    constexpr whole_number bit_long_mod(whole_number const &divisor) const noexcept {
      constexpr size_t MS_LIMB = limb_n - 1;
      whole_number     remainder = {0};
      limb_t           remainder_bit = 0;

      for (size_t i = 0; i < bits_n; ++i) {
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

    constexpr limb_t mod_by_1limb(limb_t divisor) const noexcept {
      cast_t remainder = 0;

      remainder = limbs[limb_n - 1] % divisor;
      remainder <<= LIMB_BITS;

      for (size_t i = 1; i < limb_n; ++i) {
        remainder |= limbs[limb_n - 1 - i];
        remainder = (remainder % divisor) << LIMB_BITS;
      }

      return remainder >> LIMB_BITS;
    }
  }; // whole_number class : end

  // predefined types
  #if defined(ENV_64BIT_EXTENDED)

  typedef whole_number<uint64_t, __uint128_t, 128>  uint128_t;
  typedef whole_number<uint64_t, __uint128_t, 192>  uint192_t;
  typedef whole_number<uint64_t, __uint128_t, 256>  uint256_t;
  typedef whole_number<uint64_t, __uint128_t, 320>  uint320_t;
  typedef whole_number<uint64_t, __uint128_t, 512>  uint512_t;
  typedef whole_number<uint64_t, __uint128_t, 1024> uint1024_t;
  typedef whole_number<uint64_t, __uint128_t, 2048> uint2048_t;
  typedef whole_number<uint64_t, __uint128_t, 4096> uint4096_t;

  #elif defined(ENV_64BIT)

  typedef whole_number<uint32_t, uint64_t, 128>  uint128_t;
  typedef whole_number<uint32_t, uint64_t, 192>  uint192_t;
  typedef whole_number<uint32_t, uint64_t, 256>  uint256_t;
  typedef whole_number<uint32_t, uint64_t, 320>  uint320_t;
  typedef whole_number<uint32_t, uint64_t, 512>  uint512_t;
  typedef whole_number<uint32_t, uint64_t, 1024> uint1024_t;
  typedef whole_number<uint32_t, uint64_t, 2048> uint2048_t;
  typedef whole_number<uint32_t, uint64_t, 4096> uint4096_t;

  #elif defined(ENV_32BIT)

  typedef whole_number<uint16_t, uint32_t, 64>   uint64_t;
  typedef whole_number<uint16_t, uint32_t, 128>  uint128_t;
  typedef whole_number<uint16_t, uint32_t, 192>  uint192_t;
  typedef whole_number<uint16_t, uint32_t, 256>  uint256_t;
  typedef whole_number<uint16_t, uint32_t, 320>  uint320_t;
  typedef whole_number<uint16_t, uint32_t, 512>  uint512_t;
  typedef whole_number<uint16_t, uint32_t, 1024> uint1024_t;
  typedef whole_number<uint16_t, uint32_t, 2048> uint2048_t;
  typedef whole_number<uint16_t, uint32_t, 4096> uint4096_t;

  #endif

#endif

} // namespace epi

#if (__cplusplus >= 201703L)
namespace std {
  template <typename limb_t, typename cast_t, size_t bits_n>
  struct numeric_limits<epi::whole_number<limb_t, cast_t, bits_n>> {
    // static constexpr bool is_specialized = true;

    constexpr static epi::whole_number<limb_t, cast_t, bits_n> max() {
      constexpr size_t limb_bits = sizeof(limb_t) * 8;
      constexpr limb_t max_limb = std::numeric_limits<limb_t>::max();
      constexpr size_t limb_n = epi::whole_number<limb_t, cast_t, bits_n>::limb_n;

      epi::whole_number<limb_t, cast_t, limb_n> max_value = max_limb;
      for (size_t i = 0; i < limb_n - 1; ++i) {
        max_value <<= limb_bits;
        max_value |= max_limb;
      }
      return max_value;
    }

    constexpr static epi::whole_number<limb_t, cast_t, bits_n> min() {
      constexpr limb_t min_limb = std::numeric_limits<limb_t>::min();
      constexpr size_t limb_bits = sizeof(limb_t) * 8;
      constexpr size_t limb_n = epi::whole_number<limb_t, cast_t, bits_n>::limb_n;

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

#endif