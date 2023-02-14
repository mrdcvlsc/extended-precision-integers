#ifndef EXTENDED_PRECISION_INTEGERS_HPP
#define EXTENDED_PRECISION_INTEGERS_HPP

#include <iostream>
#include <iomanip>
#include <type_traits>
#include <cstring>
#include <memory>
#include <utility>
#include <sstream>

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
            number() {}

            constexpr number(std::initializer_list<limb_t> num) {
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
                constexpr size_t number_size = sizeof(limb_t) * limb_n;

                if constexpr (sizeof(T) <= sizeof(limb_t) * limb_n) {
                    std::memcpy(limbs, &num, sizeof(T));
                } else {
                    throw std::invalid_argument("Argument has bigger size than the defined number<> type");
                }
            }

            friend std::ostream &operator<< <limb_t, cast_t, limb_n>( std::ostream&, const number<limb_t, cast_t, limb_n>& );
    };

    template <typename limb_t, typename cast_t, size_t limb_n>
    std::ostream& operator<<( std::ostream& out, const number<limb_t, cast_t, limb_n>& num ) {

        if (out.flags() & std::ios_base::hex) {
            constexpr size_t padding = sizeof(limb_t) * 2;
            
            if constexpr (std::is_same<limb_t, char>::value || std::is_same<limb_t, unsigned char>::value) {
                for (size_t i = 0; i < limb_n; ++i) {
                    out << std::setfill('0') << std::setw(padding) << std::right
                        << (unsigned int) num.limbs[limb_n - 1 - i];
                }
                out << std::setfill(' ') << std::setw(0) << std::dec;
            } else {
                for (size_t i = 0; i < limb_n; ++i) {
                    out << std::setfill('0') << std::setw(padding) << std::right
                        << num.limbs[limb_n - 1 - i];
                }
                out << std::setfill(' ') << std::setw(0) << std::dec;
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
} // namespace epi

#endif