# extended-precision-integers

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
![tests](https://github.com/mrdcvlsc/extended-precision-integers/actions/workflows/tests.yml/badge.svg)

A C++ header only library that provides extended precision data types, number types that have **Fixed sizes** and can hold larger values than **Plain Old Data** types (POD eg. `int`, `uint8_t` `unsigned long`, & etc.).

**Notes:**
- using the result of shifting bits greater than a `whole_number<>`'s width is strongly discouraged.
- When computing very large value of numbers with `constexpr` you might need to set the
`-fconstexpr-steps=` to a larger value.

## **Example Usage**

This library already provides default synthesized integer types like; `epi::uint128_t`, `epi::uint256_t`, `epi::uint320_t`, etc. To use them just include the `epi.hpp` header file in your project, then you can treat them like a normal integral type e.g. `unsigned int`, `unsigned short`, etc.

```c++
// example.cpp - get 3^600
#include <iostream>
#include "path/to/epi/include/epi/epi.hpp"

int main() {
  epi::uint1024_t a = 3;
  epi::uint1024_t b = a;

  for (size_t i = 1; i < 600; ++i) {
    a *= b;
  }

  std::cout << "0x" << std::hex << a << '\n';

  return 0;
}
```

## **TO-DO**

- [X] - [Extended Unsigned Integers](TODO/extended-unsigned-integers.md)
- [ ] - [Extended Signed Integers [N/A]](TODO/extended-signed-integers.md)
- [ ] - [Extended Floating Point [N/A]](TODO/extended-floating-point.md)

## **Requirements**
- Little Endian System
- C++20 or Above
