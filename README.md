# extended-precision-integers

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
![tests](https://github.com/mrdcvlsc/extended-precision-integers/actions/workflows/tests.yml/badge.svg)

This is a C++ header-only library that offers extended precision data types, which are number types with **fixed sizes** capable of holding larger values than traditional **Plain Old Data** types (PODs) like `int`, `uint8_t`, `unsigned long`, etc.

## **Example Usage**

This library provides default synthesized integer types such as `epi::uint128_t`, `epi::uint256_t`, `epi::uint320_t`, and so on. To utilize them, include the `epi.hpp` header file in your project. These types can be treated just like regular integral types, for instance, `unsigned int` or `unsigned short`.

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

## **Assigning a Large Value**

While assigning to the types provided by the library using literal integer types is generally acceptable, there are cases where the compiler might generate an error due to exceeding the maximum width of built-in POD/primitive types. For example:

```c++
// error: integer literal is too large to be
// represented in any integer type
epi::uint256_t AES256KEY = 123456789101112131415ULL;
```

In such situations, the library offers an alternative way of initialization using the `std::string_view` constructor, allowing support for very long integer values.

```c++
// this will compile successfully
epi::uint256_t AES256KEY("123456789101112131415");
```

> Note  
> However, keep in mind that extended-precision types will throw an error during initialization if the input `string_view` value exceeds the type's bit width.

## **Assigning With Different Base Representation**

It's possible to assign values with different base representations using the appropriate post-fix format indicators: `0b` for binary, `0o` for octal, and `0x` for hexadecimal.

**Hexadecimal:**
```c++
epi::uint256_t AES256KEY("0x6b14e9f95da1aff57");
```

**Octadecimal:**
```c++
epi::uint256_t AES256KEY("0o15305164771273206577527");
```

**Binary:**
```c++
epi::uint256_t AES256KEY("0b1101011000101001110100111111001010111011010000110101111111101010111");
```

All of these initializations are equivalent to `epi::uint256_t AES256KEY("123456789101112131415");` mentioned earlier.

## **Default Library Types**

The library provides default types as shown below:

| type | min | max |
| --- | :---: | --- |
| `epi::uint128_t` | 0 | 340282366920938463463374607431768211455 |
| `epi::uint192_t` | 0 | 6277101735386680763835789423207666416102355444464034512895 |
| `epi::uint256_t` | 0 | 115792089237316195423570985008687907853269984665640564039457584007913129639935 |
| `epi::uint320_t` | 0 | 2135987035920910082395021706169552114602704522356652769947041607822219725780640550022962086936575 |
| `epi::uint512_t` | 0 | 13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084095 |
| `epi::uint1024_t` | 0 | 179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137215 |

The maximum values are calculated using the formula $2^{\text{bit-width}} - 1$.

For instance, the `unsigned int` type is 32 bits wide, so its maximum value is $2^{32}-1$, and the `unsigned short int` type is 16 bits wide, so its maximum value is $2^{16}-1$.

## **Creating A New Extended Precision Type**

To create a custom extended precision integer type, let's say a **2048**-bit wide integer, you need to specify the desired type by providing an appropriate **unsigned integer** type to the template arguments of the `epi::whole_number<limb_t, cast_t, bit_width>` class. Here's an example:

```c++
typedef epi::whole_number<std::uint32_t, std::uint64_t, 2048> uint2048_t;

int main() {
  uint2048_t large_number = 0;
}
```

In the example above:
- `std::uint32_t` as `limb_t` is an alias for `unsigned int`, a 32-bit wide integer.
- `std::uint64_t` as `cast_t` is an alias for `unsigned long int`, a 64-bit wide integer in most systems.
- `2048` as `bit_width` represents the desired width of the type (`uint2048_t`).

The requirement is that the `cast_t` parameter should have a bit width exactly 2 times the bit width of `limb_t`. In the example, 32 x 2 = 64.

## **Compile Time Support (`constexpr`)**

This library also supports compile-time calculations using the `constexpr` keyword.

```c++
constexpr epi::uint512_t factorial(size_t N) {
  epi::uint512_t factorial = 1;

  for(epi::uint512_t i = 1; i <= N; ++i) {
    factorial *= i;
  }

  return factorial;
}

int main() {
  constexpr auto fac98 = factorial(98);
  std::cout << std::hex << fac98 << "\n";
}

// OUTPUT:
// b3fdae4141a01eb87d7eef7be85b2081adb3d8455d37d503f972677dba3450455447b6f366c6e85568b196e3bb65397be2e31f13800000000000000000000000
```

> Warning  
> However, be aware that large calculations at compile time could significantly increase compilation duration and resource usage, possibly leading to errors. For extremely large calculations, it's recommended not to use `constexpr`.

> Important  
>
> Avoid using shifted bits beyond the width of a `whole_number<>`.
>
> For very large value computations with `constexpr`, consider adjusting the `-fconstexpr-steps` to a higher value.

## **TO-DO**

- [X] - [Extended Unsigned Integers](TODO/extended-unsigned-integers.md)
- [ ] - [Extended Signed Integers [N/A]](TODO/extended-signed-integers.md)
- [ ] - [Extended Floating Point [N/A]](TODO/extended-floating-point.md)

## **Requirements**
- Little Endian System
- C++20 or Above
