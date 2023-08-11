# **Benchmark and Comparison**

Date: Fri Aug 11 06:59:12 UTC 2023

Compiler : clang++

OS : Linux


# Benchmark for **uint128_t**

### uint128_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 27 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 112 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 662 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 81 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 131 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 718 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 62 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 27 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 26 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 25 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 112 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 700 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 68 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 156 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 637 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 43 ns |
| ................................. | ........ | ............ |

### uint128_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 26 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 25 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 25 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint192_t**

### uint192_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 43 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 150 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 1193 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 162 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 1181 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 6 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 118 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 1393 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 193 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 1175 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 25 ns |
| ................................. | ........ | ............ |

### uint192_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 41 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 38 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 29 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint256_t**

### uint256_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 100 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 0 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 0 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 143 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 1812 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 81 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 200 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 2125 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 85 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 12 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 150 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 2350 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 212 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 2100 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 50 ns |
| ................................. | ........ | ............ |

### uint256_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 42 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 25 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 34 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 27 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint320_t**

### uint320_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 40 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 40 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 34 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 36 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 62 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 68 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 156 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 2706 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 250 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 3456 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 35 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 41 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 50 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 175 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 3712 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 268 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 3518 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 68 ns |
| ................................. | ........ | ............ |

### uint320_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 44 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 35 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 27 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint512_t**

### uint512_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 46 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 47 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 42 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 40 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 143 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 118 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 225 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 8306 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 281 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 8362 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 41 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 39 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 41 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 45 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 181 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 125 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 187 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 8712 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 306 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 9093 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 37 ns |
| ................................. | ........ | ............ |

### uint512_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 38 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 41 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 38 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 35 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 38 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 39 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 29 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint1024_t**

### uint1024_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 64 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 56 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 71 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 61 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 44 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 518 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 543 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 293 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 42763 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 487 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 37725 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 56 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 55 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 66 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 66 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 42 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 543 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 481 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 300 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 39594 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 431 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 40294 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 56 ns |
| ................................. | ........ | ............ |

### uint1024_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 57 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 33 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 81 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 36 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 39 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 76 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 48 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 105 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 33 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint524288_t**

### uint524288_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 20428 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 21269 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 2497 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 31103 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 23060 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 2698 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 25429754 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 147878761 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 9012 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 136414 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 11437694473 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 11618 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 315124 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 11433030225 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 9331 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 18304 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 18372 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 3067 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 29289 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 23948 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 3363 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 25591198 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 147882303 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 10356 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 117476 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 12688767277 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 14643 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 278186 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 9265674894 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 12881 ns |
| ................................. | ........ | ............ |

### uint524288_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 7118 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 20967 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 3206 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 9910 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 30943 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 3146 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 5933 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 19644 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 3119 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 8054 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 34827 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 3061 ns |
| ................................. | ........ | ............ |


## System 
```js
Architecture:                    x86_64
CPU op-mode(s):                  32-bit, 64-bit
Address sizes:                   46 bits physical, 48 bits virtual
Byte Order:                      Little Endian
CPU(s):                          2
On-line CPU(s) list:             0,1
Vendor ID:                       GenuineIntel
Model name:                      Intel(R) Xeon(R) Platinum 8272CL CPU @ 2.60GHz
CPU family:                      6
Model:                           85
Thread(s) per core:              1
Core(s) per socket:              2
Socket(s):                       1
Stepping:                        7
BogoMIPS:                        5187.81
Flags:                           fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ss ht syscall nx pdpe1gb rdtscp lm constant_tsc rep_good nopl xtopology cpuid pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 movbe popcnt aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase bmi1 hle avx2 smep bmi2 erms invpcid rtm avx512f avx512dq rdseed adx smap clflushopt avx512cd avx512bw avx512vl xsaveopt xsavec xsaves md_clear
Hypervisor vendor:               Microsoft
Virtualization type:             full
L1d cache:                       64 KiB (2 instances)
L1i cache:                       64 KiB (2 instances)
L2 cache:                        2 MiB (2 instances)
L3 cache:                        35.8 MiB (1 instance)
NUMA node(s):                    1
NUMA node0 CPU(s):               0,1
Vulnerability Itlb multihit:     KVM: Mitigation: VMX unsupported
Vulnerability L1tf:              Mitigation; PTE Inversion
Vulnerability Mds:               Mitigation; Clear CPU buffers; SMT Host state unknown
Vulnerability Meltdown:          Mitigation; PTI
Vulnerability Mmio stale data:   Vulnerable: Clear CPU buffers attempted, no microcode; SMT Host state unknown
Vulnerability Retbleed:          Vulnerable
Vulnerability Spec store bypass: Vulnerable
Vulnerability Spectre v1:        Mitigation; usercopy/swapgs barriers and __user pointer sanitization
Vulnerability Spectre v2:        Mitigation; Retpolines, STIBP disabled, RSB filling, PBRSB-eIBRS Not affected
Vulnerability Srbds:             Not affected
Vulnerability Tsx async abort:   Mitigation; Clear CPU buffers; SMT Host state unknown
```
