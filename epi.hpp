#ifndef EXTENDED_PRECISION_INTEGERS_HPP
#define EXTENDED_PRECISION_INTEGERS_HPP

#include <iostream>
#include <iomanip>
#include <type_traits>
#include <cstring>
#include <memory>
#include <utility>
#include <sstream>
#include "config.hpp"

namespace epi {

    // Forward declare both templates:
    template<typename limb_t, typename cast_t, size_t limb_n> class number;

    template<typename limb_t, typename cast_t, size_t limb_n>
    std::ostream& operator<<(
        std::ostream&,
        const number<limb_t, cast_t, limb_n>&
    );

    template<typename limb_t, typename cast_t, size_t limb_n>
    class number {
        private:
            limb_t limbs[limb_n];
        public:

            /// @brief Number base use to represent the integer.
            constexpr static size_t limb_number_base = (sizeof(limb_t) * 8);

            constexpr number() {
                if constexpr (sizeof(limb_t) * 2 != sizeof(cast_t)) {
                    throw std::invalid_argument(
                        "In 'number<limb_t, cast_t, ...>' : the sizeof(cast_t) should be 2 times the sizeof(limb_t)."
                    );
                }
            }

            constexpr number(std::initializer_list<limb_t> num) : number() {
                if (sizeof(limb_t) * limb_n < sizeof(limb_t) * num.size()) {
                    throw std::invalid_argument("initializer list has a bigger size than the defined number<> type");
                }

                for (size_t i = 0; i < limb_n; i++) {
                    limbs[i] = 0;
                }

                size_t i = limb_n - num.size();
                for (auto num_limb: num) {
                    limbs[limb_n - 1 - i++] = num_limb;
                }
            }

            template<typename T>
            constexpr number(const T& num) {
                if constexpr (sizeof(T) <= sizeof(limb_t) * limb_n) {
                    std::memcpy(limbs, &num, sizeof(T));
                } else {
                    throw std::invalid_argument("Argument has bigger size than the defined number<> type");
                }
            }

            constexpr number(number const& src) {
                std::memcpy(limbs, src.limbs, limb_n * sizeof(limb_t));
            }

            constexpr number &operator=(number const& src) {
                if (this != &src) {
                    std::memcpy(limbs, src.limbs, limb_n * sizeof(limb_t));
                }
                return *this;
            }

            friend std::ostream &operator<< <limb_t, cast_t, limb_n>( std::ostream&, const number<limb_t, cast_t, limb_n>& );
    
            constexpr number operator+(number const& add) const {
                number sum;
                limb_t carry = 0;

                for (size_t i = 0; i < limb_n; ++i) {
                    cast_t index_sum = (cast_t) limbs[i] + add.limbs[i] + carry;
                    sum.limbs[i] = index_sum;
                    carry = index_sum >> limb_number_base;
                }

                return sum;
            }

            constexpr number &operator+=(number const& add) {
                limb_t carry = 0;

                for (size_t i = 0; i < limb_n; ++i) {
                    cast_t index_sum = (cast_t) limbs[i] + add.limbs[i] + carry;
                    limbs[i] = index_sum;
                    carry = index_sum >> limb_number_base;
                }

                return *this;
            }

            constexpr number operator-(number const& sub) const {
                number diff;
                limb_t carry = 0;

                for (size_t i =0; i < limb_n; ++i) {
                    cast_t index_diff = (cast_t) limbs[i] - sub.limbs[i] - carry;
                    diff.limbs[i] = index_diff;
                    carry = (index_diff >> limb_number_base) & 0x1;
                }

                return diff;
            }

            constexpr number &operator-=(number const& sub) {
                limb_t carry = 0;

                for (size_t i =0; i < limb_n; ++i) {
                    cast_t index_diff = (cast_t) limbs[i] - sub.limbs[i] - carry;
                    limbs[i] = index_diff;
                    carry = (index_diff >> limb_number_base) & 0x1;
                }

                return *this;
            }

            constexpr number operator*(number const& mul) const {
                number prod;
                limb_t carry = 0;

                for (size_t i = 0; i < limb_n; ++i) {
                    cast_t index_prod = (cast_t) limbs[i] * mul.limbs[0] + carry;
                    prod.limbs[i] = index_prod;
                    carry = index_prod >> limb_number_base;
                }

                for (size_t i = 1; i < limb_n; ++i) {
                    carry = 0;
                    for (size_t j = 0; j < limb_n - i; ++j) {
                        cast_t index_prod = (cast_t) limbs[j] * mul.limbs[i] + prod.limbs[i + j] + carry;
                        prod.limbs[i + j] = index_prod;
                        carry = (index_prod >> limb_number_base);
                    }
                }

                return prod;
            }

            constexpr number &operator*=(number const& mul) {
                *this = *this * mul;
                return *this;
            }
    };

    template <typename limb_t, typename cast_t, size_t limb_n>
    std::ostream& operator<<( std::ostream& out, const number<limb_t, cast_t, limb_n>& num ) {
        
        if (out.flags() & std::ios_base::hex) {
            auto prev_ios_width = out.width();
            auto prev_ios_fill  = out.fill();
            constexpr size_t padding = sizeof(limb_t) * 2;
            
            if constexpr (std::is_same<limb_t, char>::value || std::is_same<limb_t, unsigned char>::value) {
                size_t i = 0;
                for (; i < limb_n; ++i) {
                    if(num.limbs[limb_n - 1 - i]) {
                        std::cout << (unsigned int) num.limbs[limb_n - 1 - i];
                        i++;
                        break;
                    } else if (i == limb_n - 1 && !num.limbs[limb_n - 1 - i]) {
                        std::cout << 0x0;
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
                    if(num.limbs[limb_n - 1 - i]) {
                        std::cout << num.limbs[limb_n - 1 - i];
                        i++;
                        break;
                    } else if (i == limb_n - 1 && !num.limbs[limb_n - 1 - i]) {
                        std::cout << 0x0;
                    }
                }

                for (; i < limb_n; ++i) {
                    out << std::setfill('0') << std::setw(padding) << std::right
                        << num.limbs[limb_n - 1 - i];
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
    typedef number<uint64_t, __uint128_t,  2>  uint128_t;
    typedef number<uint64_t, __uint128_t,  3>  uint192_t;
    typedef number<uint64_t, __uint128_t,  4>  uint256_t;
    typedef number<uint64_t, __uint128_t,  5>  uint320_t;
    typedef number<uint64_t, __uint128_t,  8>  uint512_t;
    typedef number<uint64_t, __uint128_t, 16> uint1024_t;
    typedef number<uint64_t, __uint128_t, 32> uint2048_t;
    #elif defined(ENV_64BIT)
    typedef number<uint32_t, uint64_t,  4>  uint128_t;
    typedef number<uint32_t, uint64_t,  6>  uint192_t;
    typedef number<uint32_t, uint64_t,  8>  uint256_t;
    typedef number<uint32_t, uint64_t, 10>  uint320_t;
    typedef number<uint32_t, uint64_t, 16>  uint512_t;
    typedef number<uint32_t, uint64_t, 32> uint1024_t;
    typedef number<uint32_t, uint64_t, 64> uint2048_t;
    #elif defined(ENV_32BIT)
    typedef number<uint16_t, uint32_t,   4>   uint64_t;
    typedef number<uint16_t, uint32_t,   8>  uint128_t;
    typedef number<uint16_t, uint32_t,  12>  uint192_t;
    typedef number<uint16_t, uint32_t,  16>  uint256_t;
    typedef number<uint16_t, uint32_t,  20>  uint320_t;
    typedef number<uint16_t, uint32_t,  32>  uint512_t;
    typedef number<uint16_t, uint32_t,  64> uint1024_t;
    typedef number<uint16_t, uint32_t, 128> uint2048_t;
    #endif

} // namespace epi

#endif