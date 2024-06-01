#ifndef MRDCVLSC_EXTENDED_PRECISION_INTEGERS_HPP
#define MRDCVLSC_EXTENDED_PRECISION_INTEGERS_HPP

#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string_view>
#include <type_traits>

#include <cstddef>
#include <cstdint>
#include <cstring>

// =================================================================================================
// DETECT THE MAXIMUM WIDTH OF THE LARGEST POD/PRIMITIVE TYPE IN THE SYSTEM
// =================================================================================================

#if (defined(__SIZEOF_INT128__) || defined(UINT128MAX)) && !defined(_MSVC_LANG)
    // TODO: find way to check if the following instructions are available
    // `__umodti3` & `__udivti3` #define ENV_64BIT_EXTENDED // temporarily disabled
    // since some environment does not support `__umodti3` & `__udivti3`
    #define ENV_64_BIT
#elif (defined(__amd__64__) || defined(__amd_64) || defined(__amd64__) || defined(__aarch64__) || defined(__x86_64__) || defined(__x86_64) || defined(_WIN64))
    #define ENV_64_BIT
#elif (defined(__INTEL__) || defined(__i386__) || defined(_M_IX86) || defined(__arm__) || defined(_WIN32))
    #define ENV_32_BIT
#else
    #define ENV_16_BIT
#endif

#if defined(ENV_64BIT_EXTENDED)
    #warning COMPILING_UINT128_T_LARGEST_VALUE
using LARGEST_AVAILABLE_T = __uint128_t;
#elif defined(ENV_64_BIT)
using LARGEST_AVAILABLE_T = std::uint64_t;
#elif defined(ENV_32_BIT)
using LARGEST_AVAILABLE_T = std::uint32_t;
#elif defined(ENV_16_BIT)
using LARGEST_AVAILABLE_T = std::uint16_t;
#else
    #error largest value detection failed
#endif

// dev
// #define _LITTLE_ENDIAN

namespace epi {

    // =================================================================================================
    // CHECK IF THE COMPILER IS COMPILING FOR C++20
    // =================================================================================================

#ifdef _MSVC_LANG
    #define DETECTED_CXX_STANDARD_VERSION _MSVC_LANG
#else
    #define DETECTED_CXX_STANDARD_VERSION __cplusplus
#endif

#if (DETECTED_CXX_STANDARD_VERSION <= 201703L)
    #error EPI.HPP REQUIREMENT : C++20 is needed
#else

    // =================================================================================================
    // CONSTANTS
    // =================================================================================================

    static constexpr std::array<unsigned char, 16> HEX_TO_CHAR = {
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f',
    };

    static constexpr std::array<unsigned char, 127> CHAR_TO_HEX = {
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
      0x09, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xff, 0xff,
      0xff, 0xff, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    };

    enum class base_t
    {
        bin,
        oct,
        dec,
        hex,
        invalid
    };

    // =================================================================================================
    // COMPILE-TIME META-FUNCTIONS
    // =================================================================================================

    /// @brief get the maximum base 10 digits a number with a
    /// certain bit width/size can hold.
    template <size_t bits_n>
    struct base10_digit_capacity {
        private:

        /// @brief get the maximum number of digits for the whole_number<> if it
        /// were to be represented in base10 for any arbitrary uint(2^n)
        /// whole_number<> type.
        ///
        /// A replacement for the formula : $\lfloor log_{10}(2^n - 1) \rfloor + 1$,
        /// since it can't calculate past 2^64 - 1, or the max value of a
        /// `uint64_t`.
        static constexpr size_t get_base10_max_digit() {
            // when we get the maximum digits for each of the number bases
            // in the series of powers of 2 raised to increasing multiples of 8, we
            // can get the repeating series below by repeatedly subtracting a
            // previous maximum digit to its next corresponding maximum digit. we
            // repeat the same thing for the next maximum then to the next one, if
            // we do this repeatedly we will see a repeating sequence of ... 2, 3,
            // 2, 3, 2, ... will emerge.
            constexpr size_t base10_diff_series[5] = {2, 3, 2, 3, 2};

            /// initial base 2^8 starting max number of digit when represented in
            /// base 10.
            size_t base10_max_digits = 3;

            // we then use the repeating sequence to get the maximum possible
            // numbers of digit that the current whole_number<> class can hold in a
            // base10 representation.
            for (size_t i = 0; ((i + 2) * 8) <= bits_n; ++i) {
                base10_max_digits += base10_diff_series[i % 5];
            }

            return base10_max_digits;
        }

        public:

        static constexpr size_t value = get_base10_max_digit();
    };

    /// @brief get the maximum base 8 digits a number with a certain bit width/size
    /// can hold.
    template <size_t bits_n>
    struct base8_digit_capacity {
        private:

        /// @brief get the maximum number of digits for the whole_number<> if it
        /// were to be represented in base8 for any arbitrary uint(2^n)
        /// whole_number<> type.
        ///
        /// A replacement for the formula : $\lfloor log_{8}(2^n - 1) \rfloor + 1$,
        /// since it can't calculate past 2^64 - 1, or the max value of a
        /// `uint64_t`.
        static constexpr size_t get_base8_max_digit() {
            // uses the same technique in `get_base10_max_digit`.
            constexpr size_t base8_diff_series[3] = {3, 2, 3};
            size_t           base8_max_digits = 3;

            for (size_t i = 0; ((i + 2) * 8) <= bits_n; ++i) {
                base8_max_digits += base8_diff_series[i % 3];
            }

            return base8_max_digits;
        }

        public:

        static constexpr size_t value = get_base8_max_digit();
    };

    // =================================================================================================
    // BIG UNSIGNED INTEGER IMPLEMENTATION
    // =================================================================================================

    /// @brief Template Class for creating any fixed arbitrary sized whole numbers.
    ///
    /// @note Example: an unsigned 128 bit integer is equal to
    /// whole_number<uint32_t, uint64_t, 4>, this is because 32 * 4 = 128 so
    /// basically we just used four uint32_t to represent a uint128_t.
    ///
    /// @tparam limb_t any unsigned integral types.
    /// @tparam cast_t unsigned integral types that is exactly two times bigger than
    /// limb_t.
    /// @tparam bits_n number of bits of the whole number.
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

        /// @brief The maximum base 2 (binary) digit count.
        static constexpr size_t BASE2_DIGIT_CAP = LIMB_BITS * limb_n;

        /// @brief The maximum base 8 (octadecimal) digit count.
        static constexpr size_t BASE8_DIGIT_CAP = base8_digit_capacity<bits_n>::value;

        /// @brief The maximum base 10 (decimal) digit count.
        static constexpr size_t BASE10_DIGIT_CAP = base10_digit_capacity<bits_n>::value;

        /// @brief The maximum base 16 (hexadecimal) digit count.
        static constexpr size_t BASE16_DIGIT_CAP = sizeof(limb_t) * 2 * limb_n;

        std::array<limb_t, limb_n> limbs;

        public:

        /// default constuctor.
        constexpr whole_number() noexcept : limbs{} {
            constexpr bool invalid_limb_t = std::is_unsigned_v<limb_t>;
            constexpr bool invalid_cast_t = std::is_unsigned_v<cast_t> || std::is_same_v<LARGEST_AVAILABLE_T, cast_t>;
            constexpr bool wrong_cast_t_size = (sizeof(limb_t) * 2) == sizeof(cast_t);

            if constexpr (!invalid_limb_t) {
                static_assert(invalid_limb_t, "limb_t should be an unsigned integral type");
            } else if constexpr (!invalid_cast_t) {
                static_assert(invalid_cast_t, "cast_t should be an unsigned integral type");
            } else if constexpr (!wrong_cast_t_size) {
                static_assert(wrong_cast_t_size, "sizeof(cast_t) should be exactly two times (2x) the sizeof(limb_t)");
            }
        }

        /// initializer list constructor.
        constexpr whole_number(std::initializer_list<limb_t> num_limbs) : whole_number() {
            if (num_limbs.size() > limb_n) {
                throw std::invalid_argument(
                  "initializer list elements should be "
                  "less than or equal the limb_n"
                );
            }

            size_t index = limb_n - 1 - (limb_n - num_limbs.size());
            for (auto limb: num_limbs) {
                limbs[index--] = limb;
            }
        }

        constexpr whole_number(std::string_view const &num) : whole_number() {
            if (num.empty()) {
                throw std::length_error("empty char*/string constructor are not allowed");
            }

            base_t base = base_t::invalid;

            bool is_all_digit = true;

            for (auto c: num) {
                if (!(c >= '0' && c <= '9')) {
                    is_all_digit = false;
                    break;
                }
            }

            // determine what number base representation does the input number
            // string is in and check its validity after.

            if (is_all_digit) {
                constexpr size_t base10_max_digits = BASE10_DIGIT_CAP;
                if (num.size() > base10_max_digits) {
                    throw std::length_error("base 10 number string exceed the max number of digits");
                } else if (!valid_base10(num)) {
                    throw std::length_error("invalid digit character detected");
                }
                base = base_t::dec;
            } else {
                if (num.size() >= 3 && num.front() == '0') {
                    if (num[1] == 'b') {
                        constexpr size_t base2_max_digits = bits_n;
                        if ((num.size() - 2) > base2_max_digits) {
                            throw std::length_error("binary string exceed the max number of digits");
                        } else if (!valid_base2(num)) {
                            throw std::length_error("invalid binary character detected");
                        }
                        base = base_t::bin;
                    } else if (num[1] == 'o') {
                        constexpr size_t base8_max_digits = BASE8_DIGIT_CAP;
                        if ((num.size() - 2) > base8_max_digits) {
                            throw std::length_error("octal string exceed the max number of digits");
                        } else if (!valid_base8(num)) {
                            throw std::length_error("invalid octal character detected");
                        }
                        base = base_t::oct;
                    } else if (num[1] == 'x') {
                        constexpr size_t base16_max_digits = limb_n * sizeof(limb_t) * 2;
                        if ((num.size() - 2) > base16_max_digits) {
                            throw std::length_error("hex string exceed the max number of digits");
                        } else if (!valid_base16(num)) {
                            throw std::length_error("invalid hex character detected");
                        }
                        base = base_t::hex;
                    }
                }
            }

            // convert the current number base string representation into it's
            // actual in memory value.

            constexpr size_t HEX_BASE = 16;

            if (base == base_t::dec) {
                constexpr size_t output_len = BASE10_DIGIT_CAP;
                size_t           offset = output_len - num.size();

                std::array<std::uint8_t, output_len> output{};

                constexpr size_t base = 10;

                for (size_t i = 0; i < num.size(); ++i) {
                    uint8_t carry = num[i] - '0';
                    size_t  j = num.size();
                    while (j--) {
                        uint8_t tmp = output[j + offset] * base + carry;
                        output[j + offset] = tmp % HEX_BASE;
                        carry = tmp / HEX_BASE;
                    }
                }

                /// In one byte we have a max of 2 hex character, where each char is 4 bit.
                constexpr size_t HEX_CHAR_BITS = 4;
                constexpr size_t HEX_CHAR_PER_LIMB = sizeof(limb_t) * 2;

                for (size_t i = 0; i < limb_n * HEX_CHAR_PER_LIMB; ++i) {
                    limbs[i / HEX_CHAR_PER_LIMB] |= ((limb_t) output[output_len - 1 - i])
                                                    << (HEX_CHAR_BITS * (i % HEX_CHAR_PER_LIMB));
                }
            } else if (base == base_t::bin) {
                for (size_t i = 0; i < num.size() - 2; ++i) {
                    limb_t           hex_char = num[num.size() - 1 - i] - '0';
                    constexpr size_t BIN_CHAR_BITS = 1;
                    limbs[i / (LIMB_BITS)] |= (hex_char << (BIN_CHAR_BITS * (i % (LIMB_BITS))));
                }
            } else if (base == base_t::oct) {
                constexpr size_t output_len = BASE8_DIGIT_CAP;
                size_t           offset = output_len - (num.size() - 2);

                std::array<std::uint8_t, output_len> output{};

                constexpr size_t base = 8;

                for (size_t i = 0; i < (num.size() - 2); ++i) {
                    uint8_t carry = num[i + 2] - '0';
                    size_t  backward_iterator = (num.size() - 2);
                    while (backward_iterator--) {
                        uint8_t tmp = output[backward_iterator + offset] * base + carry;
                        output[backward_iterator + offset] = tmp % HEX_BASE;
                        carry = tmp / HEX_BASE;
                    }
                }

                /// In one byte we have a max of 2 hex character, where each char is 4 bit.
                constexpr size_t HEX_CHAR_BITS = 4;
                constexpr size_t HEX_CHAR_PER_LIMB = sizeof(limb_t) * 2;

                for (size_t i = 0; i < limb_n * HEX_CHAR_PER_LIMB; ++i) {
                    limbs[i / HEX_CHAR_PER_LIMB] |= ((limb_t) output[output_len - 1 - i])
                                                    << (HEX_CHAR_BITS * (i % HEX_CHAR_PER_LIMB));
                }
            } else if (base == base_t::hex) {
                for (size_t i = 0; i < num.size() - 2; ++i) {
                    limb_t           hex_char = CHAR_TO_HEX[static_cast<unsigned char>(num[num.size() - 1 - i])];
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

            if constexpr (static_cast<bool>(partition)) {
                for (size_t i = 0; i < partition; ++i) {
                    limbs[i] = static_cast<limb_t>(num >> (i * LIMB_BITS));
                }
            } else if constexpr (!static_cast<bool>(partition)) {
                limbs[0] = num;
            }
        }

        friend std::ostream &operator<<(std::ostream &out, const whole_number &num) {
            if (out.flags() & std::ios_base::hex) {
                auto             prev_ios_width = static_cast<int>(out.width());
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
                        out << std::setfill('0') << std::setw(padding) << std::right
                            << (unsigned int) num.limbs[limb_n - 1 - i];
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
                out << std::move(num.to_string_base8());
            } else {
                out << std::move(num.to_string_base10());
            }

            return out;
        }

        // arithmetic operators : start
        constexpr whole_number operator+(whole_number const &add) const noexcept {
            whole_number sum;
            limb_t       carry = 0;

            for (size_t i = 0; i < limb_n; ++i) {
                cast_t index_sum =
                  static_cast<cast_t>(limbs[i]) + static_cast<cast_t>(add.limbs[i]) + static_cast<cast_t>(carry);
                sum.limbs[i] = static_cast<int>(index_sum);
                carry = index_sum >> LIMB_BITS;
            }

            return sum;
        }

        constexpr whole_number &operator+=(whole_number const &add) noexcept {
            limb_t carry = 0;

            for (size_t i = 0; i < limb_n; ++i) {
                cast_t index_sum =
                  static_cast<cast_t>(limbs[i]) + static_cast<cast_t>(add.limbs[i]) + static_cast<cast_t>(carry);
                limbs[i] = static_cast<int>(index_sum);
                carry = index_sum >> LIMB_BITS;
            }

            return *this;
        }

        constexpr whole_number operator-(whole_number const &sub) const noexcept {
            whole_number diff;
            limb_t       carry = 0;

            for (size_t i = 0; i < limb_n; ++i) {
                cast_t index_diff = (cast_t) limbs[i] - sub.limbs[i] - carry;
                diff.limbs[i] = static_cast<limb_t>(index_diff);
                carry = (index_diff >> LIMB_BITS) & 0x1;
            }

            return diff;
        }

        constexpr whole_number &operator-=(whole_number const &sub) noexcept {
            limb_t carry = 0;

            for (size_t i = 0; i < limb_n; ++i) {
                cast_t index_diff = (cast_t) limbs[i] - sub.limbs[i] - carry;
                limbs[i] = static_cast<limb_t>(index_diff);
                carry = (index_diff >> LIMB_BITS) & 0x1;
            }

            return *this;
        }

        // pre-fix increment/decrement
        constexpr whole_number &operator++() noexcept {
            constexpr whole_number CONSTEXPR_ONE = static_cast<size_t>(1);
            return *this += CONSTEXPR_ONE;
        }

        constexpr whole_number &operator--() noexcept {
            constexpr whole_number CONSTEXPR_ONE = static_cast<size_t>(1);
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
                prod.limbs[i] = static_cast<limb_t>(index_prod);
                carry = index_prod >> LIMB_BITS;
            }

            for (size_t i = 1; i < limb_n; ++i) {
                carry = 0;
                for (size_t j = 0; j < limb_n - i; ++j) {
                    cast_t index_prod = (cast_t) limbs[j] * mul.limbs[i] + prod.limbs[i + j] + carry;
                    prod.limbs[i + j] = static_cast<limb_t>(index_prod);
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

            constexpr whole_number CONSTEXPR_ONE = static_cast<size_t>(1UL);
            constexpr whole_number CONSTEXPR_ZERO;

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

            constexpr whole_number CONSTEXPR_ZERO;

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
        constexpr bool operator==(whole_number const &num) const noexcept {
            return !compare(*this, num);
        }

        constexpr bool operator!=(whole_number const &num) const noexcept {
            return compare(*this, num);
        }

        constexpr bool operator<(whole_number const &num) const noexcept {
            return compare(*this, num) == LESS;
        }

        constexpr bool operator>(whole_number const &num) const noexcept {
            return compare(*this, num) == GREAT;
        }

        constexpr bool operator<=(whole_number const &num) const noexcept {
            return compare(*this, num) <= EQUAL;
        }

        constexpr bool operator>=(whole_number const &num) const noexcept {
            return compare(*this, num) >= EQUAL;
        }

        // relational operators : end

        /// @brief automatically resolve the logical &&, ||, and ! operators.
        constexpr explicit operator bool() const noexcept {
            // TODO: optimize this by detecting constexpr keyword then
            // return true if value is not constexpr zero and vice-versa.

            // constant cryptographic time comparison
            limb_t result = 0;
            for (size_t i = 0; i < limb_n; ++i) {
                result |= limbs[i];
            }
            return result;

            // not-constant cryptographic time comparison
            // constexpr whole_number ZERO = 0;
            // for (size_t i = 0; i < limb_n; ++i) {
            //   if (limbs[i] != ZERO.limbs[i]) {
            //     return true;
            //   }
            // }
            // return false;
        }

        // bitwise logical operators : start

        constexpr whole_number &operator&=(whole_number const &num) noexcept {
            for (size_t i = 0; i < limb_n; ++i) {
                limbs[i] &= num.limbs[i];
            }
            return *this;
        }

        constexpr whole_number &operator|=(whole_number const &num) noexcept {
            for (size_t i = 0; i < limb_n; ++i) {
                limbs[i] |= num.limbs[i];
            }
            return *this;
        }

        constexpr whole_number &operator^=(whole_number const &num) noexcept {
            for (size_t i = 0; i < limb_n; ++i) {
                limbs[i] ^= num.limbs[i];
            }
            return *this;
        }

        constexpr whole_number operator&(whole_number const &num) const noexcept {
            whole_number bwl_and;
            for (size_t i = 0; i < limb_n; ++i) {
                bwl_and.limbs[i] = limbs[i] & num.limbs[i];
            }
            return bwl_and;
        }

        constexpr whole_number operator|(whole_number const &num) const noexcept {
            whole_number bwl_or;
            for (size_t i = 0; i < limb_n; ++i) {
                bwl_or.limbs[i] = limbs[i] | num.limbs[i];
            }
            return bwl_or;
        }

        constexpr whole_number operator^(whole_number const &num) const noexcept {
            whole_number bwl_xor;
            for (size_t i = 0; i < limb_n; ++i) {
                bwl_xor.limbs[i] = limbs[i] ^ num.limbs[i];
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

        constexpr whole_number &operator&=(limb_t single_limb) noexcept {
            limbs[0] &= single_limb;
            return *this;
        }

        constexpr whole_number &operator|=(limb_t single_limb) noexcept {
            limbs[0] |= single_limb;
            return *this;
        }

        constexpr whole_number &operator^=(limb_t single_limb) noexcept {
            limbs[0] ^= single_limb;
            return *this;
        }

        constexpr whole_number operator&(limb_t single_limb) const noexcept {
            whole_number bwl_and;
            bwl_and.limbs[0] = limbs[0] & single_limb;
            return bwl_and;
        }

        constexpr whole_number operator|(limb_t single_limb) const noexcept {
            whole_number bwl_or;
            bwl_or.limbs[0] = limbs[0] | single_limb;
            return bwl_or;
        }

        constexpr whole_number operator^(limb_t single_limb) const noexcept {
            whole_number bwl_xor;
            bwl_xor.limbs[0] = limbs[0] ^ single_limb;
            return bwl_xor;
        }

        // bitwise logical operators for integral operands : end

        // shift operators : start

        /// code improved/refactored times: 1x
        constexpr whole_number &operator<<=(size_t lshift) noexcept {
            size_t lshift_internal = lshift % bits_n;
            size_t limb_shifts = lshift_internal / LIMB_BITS;
            size_t bit_shifts = lshift_internal % LIMB_BITS;

            cast_t shifted_bits = 0;

            limbs[limb_n - 1] = limbs[limb_n - 1 - limb_shifts] << bit_shifts;

            for (size_t i = limb_n - 2; i >= limb_shifts && i < limb_n; i--) {
                shifted_bits = static_cast<cast_t>(limbs[i - limb_shifts]) << bit_shifts;
                limbs[i] = static_cast<limb_t>(shifted_bits);
                limbs[i + 1] |= static_cast<limb_t>(shifted_bits >> LIMB_BITS);
            }

            for (size_t i = 0; i < limb_shifts; i++) {
                limbs[i] = 0;
            }
            
            return *this;
        }

        /// code improved/refactored times: 1x
        constexpr whole_number operator<<(size_t lshift) const noexcept {
            whole_number result;

            size_t lshift_internal = lshift % bits_n;
            size_t limb_shifts = lshift_internal / LIMB_BITS;
            size_t bit_shifts = lshift_internal % LIMB_BITS;

            cast_t shifted_bits = 0;

            result.limbs[limb_n - 1] = limbs[limb_n - 1 - limb_shifts] << bit_shifts;

            for (size_t i = limb_n - 2; i >= limb_shifts && i < limb_n; i--) {
                shifted_bits = static_cast<cast_t>(limbs[i - limb_shifts]) << bit_shifts;
                result.limbs[i] = static_cast<limb_t>(shifted_bits);
                result.limbs[i + 1] |= static_cast<limb_t>(shifted_bits >> LIMB_BITS);
            }

            for (size_t i = 0; i < limb_shifts; i++) {
                result.limbs[i] = 0;
            }
            
            return result;
        }

        /// code improved/refactored times: 1x
        constexpr whole_number &operator>>=(size_t rshift) noexcept {
            size_t rshift_internal = rshift % bits_n;
            size_t limb_shifts = rshift_internal / LIMB_BITS;
            size_t bit_shifts = rshift_internal % LIMB_BITS;
            
            cast_t shifted_bits = 0;

            limbs[0] = limbs[limb_shifts] >> bit_shifts;

            for (size_t i = 1; i < limb_n - limb_shifts; i++) {
                shifted_bits = static_cast<cast_t>(limbs[limb_shifts + i]) << (LIMB_BITS - bit_shifts);
                limbs[i] = static_cast<limb_t>(shifted_bits >> LIMB_BITS);
                limbs[i - 1] |= static_cast<limb_t>(shifted_bits);
            }

            for (size_t i = limb_n - limb_shifts; i < limb_n; i++) {
                limbs[i] = 0;
            }

            return *this;
        }

        /// code improved/refactored times: 1x
        constexpr whole_number operator>>(size_t rshift) const noexcept {
            whole_number result;

            size_t rshift_internal = rshift % bits_n;
            size_t limb_shifts = rshift_internal / LIMB_BITS;
            size_t bit_shifts = rshift_internal % LIMB_BITS;

            cast_t shifted_bits = 0;

            result.limbs[0] = limbs[limb_shifts] >> bit_shifts;

            for (size_t i = 1; i < limb_n - limb_shifts; i++) {
                shifted_bits = static_cast<cast_t>(limbs[limb_shifts + i]) << (LIMB_BITS - bit_shifts);
                result.limbs[i] = static_cast<limb_t>(shifted_bits >> LIMB_BITS);
                result.limbs[i - 1] |= static_cast<limb_t>(shifted_bits);
            }

            return result;
        }

        // shift operators : end

        [[nodiscard]] std::string to_string_base2(bool no_leading_zero = true) const noexcept {
            std::string num_str;
            num_str.reserve(BASE2_DIGIT_CAP);

            for (size_t i = 0; i < limb_n; ++i) {
                num_str.append(std::bitset<LIMB_BITS>(limbs[limb_n - 1 - i]).to_string());
            }

            if (no_leading_zero) {
                size_t leading_zeros = 0;
                size_t index = 0;
                for (; index < num_str.size() - 1; ++index) {
                    if (num_str[index] != '0') {
                        leading_zeros = index;
                        break;
                    }
                }

                if (index == num_str.size() - 1 && !static_cast<bool>(leading_zeros)) {
                    num_str = num_str.back();
                } else {
                    num_str = num_str.substr(leading_zeros, num_str.size() - leading_zeros);
                }
            }

            return num_str;
        }

        [[nodiscard]] std::string to_string_base8() const noexcept {
            std::string num_str;
            num_str.reserve(BASE10_DIGIT_CAP);

            whole_number           quotient = *this;
            whole_number           remainder = 0;
            constexpr whole_number BASE8 = 8;

            if (!quotient) {
                return "0";
            }

            while (quotient) {
                self_div_and_mod_by_1limb(quotient, BASE8.limbs[0], remainder);
                num_str.push_back('0' + remainder.limbs[0]);
            }

            std::reverse(num_str.begin(), num_str.end());

            return num_str;
        }

        [[nodiscard]] std::string to_string_base10() const noexcept {
            std::string num_str;
            num_str.reserve(BASE10_DIGIT_CAP);

            whole_number           quotient = *this;
            whole_number           remainder = 0;
            constexpr whole_number BASE10 = 10;

            if (!quotient) {
                return "0";
            }

            while (quotient) {
                self_div_and_mod_by_1limb(quotient, BASE10.limbs[0], remainder);
                num_str.push_back('0' + remainder.limbs[0]);
            }

            std::reverse(num_str.begin(), num_str.end());

            return num_str;
        }

        [[nodiscard]] std::string to_string_base16() const noexcept {
            std::stringstream out;
            out << std::hex << *this;
            return out.str();
        }

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
            for (auto digit: num) {
                if (!(digit >= '0' && digit <= '9')) {
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

        static constexpr int compare(whole_number const &lhs, whole_number const &rhs) noexcept {
            int comparison_result = EQUAL;

            for (size_t i = 0; i < limb_n; ++i) {
                if (lhs.limbs[limb_n - 1 - i] < rhs.limbs[limb_n - 1 - i]) {
                    comparison_result = LESS;
                    break;
                } else if (lhs.limbs[limb_n - 1 - i] > rhs.limbs[limb_n - 1 - i]) {
                    comparison_result = GREAT;
                    break;
                }
            }

            return comparison_result;
        }

        /// @return 0 - if a zero integer, return 1 - if has one limb, return 2 - if
        /// has higher limb value occupations.
        [[nodiscard]] constexpr int is_one_limb() const noexcept {
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
            constexpr size_t MS_LIMB = limb_n - 1UL;
            whole_number     quotient;
            whole_number     remainder;
            limb_t           remainder_bit = 0;
            limb_t           one_bit = 1;
            size_t           index = 0;
            size_t           shift_value = 0;

            for (size_t i = 0; i < bits_n; ++i) {
                index = MS_LIMB - i / LIMB_BITS;
                shift_value = i % LIMB_BITS;

                remainder = remainder << 1UL;
                remainder_bit = limbs[index] << shift_value;
                remainder_bit >>= (LIMB_BITS - 1UL);

                remainder.limbs[0] |= remainder_bit;

                if (remainder >= divisor) {
                    remainder -= divisor;
                    quotient.limbs[index] |= (one_bit << ((LIMB_BITS - 1UL) - shift_value));
                }
            }

            return quotient;
        }

        constexpr whole_number &self_bit_long_div(whole_number const &divisor) noexcept {
            constexpr size_t MS_LIMB = limb_n - 1UL;
            whole_number     remainder;
            limb_t           remainder_bit = 0;
            limb_t           one_bit = 1;
            size_t           index = 0;
            size_t           shift_value = 0;

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
                remainder |= static_cast<cast_t>(limbs[limb_n - 1 - i]);
                quotient.limbs[limb_n - 1 - i] = static_cast<limb_t>(remainder / static_cast<cast_t>(divisor));
                remainder = (remainder % static_cast<cast_t>(divisor)) << LIMB_BITS;
            }

            return quotient;
        }

        constexpr whole_number &self_div_by_1limb(limb_t divisor) noexcept {
            cast_t remainder = 0;

            remainder = limbs[limb_n - 1] % divisor;
            remainder <<= LIMB_BITS;
            limbs[limb_n - 1] = limbs[limb_n - 1] / divisor;

            for (size_t i = 1; i < limb_n; ++i) {
                remainder |= static_cast<cast_t>(limbs[limb_n - 1 - i]);
                limbs[limb_n - 1 - i] = static_cast<limb_t>(remainder / static_cast<cast_t>(divisor));
                remainder = (remainder % static_cast<cast_t>(divisor)) << LIMB_BITS;
            }

            return *this;
        }

        static constexpr void self_div_and_mod_by_1limb(
          whole_number &quotient, limb_t divisor, whole_number &remainder
        ) noexcept {
            cast_t remainder_limb = 0;

            remainder_limb = quotient.limbs[limb_n - 1] % divisor;
            remainder_limb <<= LIMB_BITS;
            quotient.limbs[limb_n - 1] = quotient.limbs[limb_n - 1] / divisor;

            for (size_t i = 1; i < limb_n; ++i) {
                remainder_limb |= static_cast<cast_t>(quotient.limbs[limb_n - 1 - i]);
                quotient.limbs[limb_n - 1 - i] = static_cast<limb_t>(remainder_limb / static_cast<cast_t>(divisor));
                remainder_limb = (remainder_limb % static_cast<cast_t>(divisor)) << LIMB_BITS;
            }

            remainder = remainder_limb >> LIMB_BITS;
        }

        // mods

        constexpr whole_number bit_long_mod(whole_number const &divisor) const noexcept {
            constexpr size_t MS_LIMB = limb_n - 1;
            whole_number     remainder;
            limb_t           remainder_bit = 0;

            for (size_t i = 0; i < bits_n; ++i) {
                remainder = remainder << 1UL;
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
                remainder |= static_cast<cast_t>(limbs[limb_n - 1 - i]);
                remainder = (remainder % static_cast<cast_t>(divisor)) << LIMB_BITS;
            }

            return remainder >> LIMB_BITS;
        }
    }; // whole_number class : end

    // =================================================================================================
    // CREATE PRE-DEFINED TYPES FOR USERS
    // =================================================================================================
    #if defined(ENV_64BIT_EXTENDED)

    using uint128_t = whole_number<uint64_t, LARGEST_AVAILABLE_T, 128>;
    using uint192_t = whole_number<uint64_t, LARGEST_AVAILABLE_T, 192>;
    using uint256_t = whole_number<uint64_t, LARGEST_AVAILABLE_T, 256>;
    using uint320_t = whole_number<uint64_t, LARGEST_AVAILABLE_T, 320>;
    using uint512_t = whole_number<uint64_t, LARGEST_AVAILABLE_T, 512>;
    using uint1024_t = whole_number<uint64_t, LARGEST_AVAILABLE_T, 1024>;

    #elif defined(ENV_64_BIT)

    using uint128_t = whole_number<uint32_t, uint64_t, 128>;
    using uint192_t = whole_number<uint32_t, uint64_t, 192>;
    using uint256_t = whole_number<uint32_t, uint64_t, 256>;
    using uint320_t = whole_number<uint32_t, uint64_t, 320>;
    using uint512_t = whole_number<uint32_t, uint64_t, 512>;
    using uint1024_t = whole_number<uint32_t, uint64_t, 1024>;

    #elif defined(ENV_32_BIT)

    using uint128_t = whole_number<uint16_t, uint32_t, 128>;
    using uint192_t = whole_number<uint16_t, uint32_t, 192>;
    using uint256_t = whole_number<uint16_t, uint32_t, 256>;
    using uint320_t = whole_number<uint16_t, uint32_t, 320>;
    using uint512_t = whole_number<uint16_t, uint32_t, 512>;
    using uint1024_t = whole_number<uint16_t, uint32_t, 1024>;

    #endif
#endif

} // namespace epi

// =================================================================================================
// STD MIN AND MAX SUPPORT
// =================================================================================================

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
