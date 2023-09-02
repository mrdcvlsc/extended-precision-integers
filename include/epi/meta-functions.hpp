#ifndef MRDCVLSC_EXTENDED_PRECISION_INTEGERS_META_FUNCTION_HPP
#define MRDCVLSC_EXTENDED_PRECISION_INTEGERS_META_FUNCTION_HPP

#include <stddef.h>

namespace epi::compile_time {
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
            // when we get the series of maximum digits for each of the number base
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
} // namespace epi::compile_time

#endif