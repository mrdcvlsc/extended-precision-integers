# extended-precision-integers

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
![tests](https://github.com/mrdcvlsc/extended-precision-integers/actions/workflows/tests.yml/badge.svg)

A C++ header file that provides extended precision data types, Types that have **Fixed sizes** and can hold larger numbers than **Plain Old Data** types (POD eg. `int`, `uint8_t` `unsigned long`, & etc.).

To use just include the header file `#include "epi.hpp"`.

**Notes:**
- using the result of shifting bits greater than a `number<>`'s width is strongly discouraged.


## **TO-DO**

- [ ] - Extended Unsigned Integers [WIP].
- [ ] - Extended Signed Integers [N/A].
- [ ] - Extended Floating Point [N/A].

## **Environment Requirements**
- little Endian