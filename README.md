# extended-precision-integers

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
![tests](https://github.com/mrdcvlsc/extended-precision-integers/actions/workflows/tests.yml/badge.svg)

A C++ header file that provides extended precision data types, Types that have **Fixed sizes** and can hold larger numbers than **Plain Old Data** types (POD eg. `int`, `uint8_t` `unsigned long`, & etc.).

To use just include the header file `#include "epi.hpp"`.

**Notes:**
- using the result of shifting bits greater than a `number<>`'s width is strongly discouraged.
- When computing very large value of numbers with `constexpr` you might need to set the
`-fconstexpr-steps=` to a large value.

## **TO-DO**

- [ ] - [Extended Unsigned Integers [WIP]](TODO/extended-unsigned-integers.md)
- [ ] - [Extended Signed Integers [N/A]](TODO/extended-signed-integers.md)
- [ ] - [Extended Floating Point [N/A]](TODO/extended-floating-point.md)

## **Requirements**
- Little Endian System
- C++17 or Above