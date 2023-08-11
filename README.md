# extended-precision-integers

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
![tests](https://github.com/mrdcvlsc/extended-precision-integers/actions/workflows/tests.yml/badge.svg)

A C++ header file that provides extended precision data types, Types that have **Fixed sizes** and can hold larger numbers than **Plain Old Data** types (POD eg. `int`, `uint8_t` `unsigned long`, & etc.).

**Notes:**
- using the result of shifting bits greater than a `whole_number<>`'s width is strongly discouraged.
- When computing very large value of numbers with `constexpr` you might need to set the
`-fconstexpr-steps=` to a larger value.

## **Example Usage**

This library already provides default synthesized integer types like; `epi::uint128_t`, `epi::uint256_t`, `epi::uint320_t`, etc. To use them just include the `epi.hpp` header file in your project, then you can treat them like a normal integral type e.g. `unsigned int`, `unsigned short`, etc.

```c++
#include <iostream>
#include "path/to/epi/epi.hpp"

int main() {
  epi::uint1024_t bigint = 2;

  for (size_t i = 0; i < 1000; ++i) {
    bigint *= bigint;
  }

  std::cout << std::hex << bigint << '\n';

  return 0;
}
```

## **TO-DO**

- [ ] - [Extended Unsigned Integers [WIP]](TODO/extended-unsigned-integers.md)
- [ ] - [Extended Signed Integers [N/A]](TODO/extended-signed-integers.md)
- [ ] - [Extended Floating Point [N/A]](TODO/extended-floating-point.md)

## **Requirements**
- Little Endian System
- C++20 or Above


$\lfloor log_{10}(2^n - 1) \rfloor + 1$