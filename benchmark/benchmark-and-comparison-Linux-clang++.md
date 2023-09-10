# **Benchmark and Comparison**

Date: Sun Sep 10 03:11:22 UTC 2023

Compiler : clang++

OS : Linux


# Benchmark for **uint128_t**

### uint128_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 27 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 27 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 56 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 112 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 693 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 106 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 668 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 26 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 87 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 725 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 118 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 687 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 62 ns |
| ................................. | ........ | ............ |

### uint128_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 44 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 26 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 25 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 21 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 20 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 23 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 25 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 28 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint192_t**

### uint192_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 62 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 50 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 112 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 1293 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 168 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 1212 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 27 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 143 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 1375 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 162 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 1256 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 37 ns |
| ................................. | ........ | ............ |

### uint192_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 44 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 27 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 27 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 28 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint256_t**

### uint256_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 41 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 93 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 81 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 6 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 143 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 1925 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 175 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 1881 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 33 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 38 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 56 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 12 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 118 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 2418 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 62 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 181 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 1875 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 37 ns |
| ................................. | ........ | ............ |

### uint256_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 44 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 27 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 27 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 39 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 27 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint320_t**

### uint320_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 48 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 39 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 36 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 81 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 68 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 131 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 2731 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 225 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 3481 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 40 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 38 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 81 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 81 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 150 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 3450 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 62 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 175 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 3493 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 37 ns |
| ................................. | ........ | ............ |

### uint320_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 42 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 27 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 27 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 39 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 38 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 29 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint512_t**

### uint512_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 51 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 40 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 58 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 48 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 42 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 187 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 143 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 168 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 8000 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 300 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 7831 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 44 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 44 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 47 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 52 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 44 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 212 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 143 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 18 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 187 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 8387 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 62 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 225 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 7800 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 12 ns |
| ................................. | ........ | ............ |

### uint512_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 49 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 39 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 39 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 41 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 131 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 28 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint1024_t**

### uint1024_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 72 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 58 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 36 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 86 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 75 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 46 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 662 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 518 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 18 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 268 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 40462 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 62 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 537 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 39069 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 64 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 74 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 76 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 76 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 94 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 668 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 556 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 281 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 39181 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 393 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 35506 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 50 ns |
| ................................. | ........ | ............ |

### uint1024_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 54 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 46 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 45 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 101 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 41 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 46 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 78 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 44 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 44 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 106 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 30 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint65536_t**

### uint65536_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 3083 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 2632 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 152 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 4551 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 3395 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 306 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 1025575 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 2892406 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 156 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 15606 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 127645737 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 475 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 33993 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 127486833 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 193 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 2750 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 2777 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 307 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 4439 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 3585 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 400 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 1025886 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 2894302 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 300 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 15181 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 127676061 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 787 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 29968 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 127543689 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 650 ns |
| ................................. | ........ | ............ |

### uint65536_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 867 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 1951 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 214 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 1132 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 4999 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 216 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 610 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 2209 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 217 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 909 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 5300 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 214 ns |
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
Model name:                      Intel(R) Xeon(R) Platinum 8370C CPU @ 2.80GHz
CPU family:                      6
Model:                           106
Thread(s) per core:              1
Core(s) per socket:              2
Socket(s):                       1
Stepping:                        6
BogoMIPS:                        5586.87
Flags:                           fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ss ht syscall nx pdpe1gb rdtscp lm constant_tsc rep_good nopl xtopology cpuid pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 movbe popcnt aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single pti fsgsbase bmi1 hle avx2 smep bmi2 erms invpcid rtm avx512f avx512dq rdseed adx smap clflushopt avx512cd avx512bw avx512vl xsaveopt xsavec xsaves md_clear
Hypervisor vendor:               Microsoft
Virtualization type:             full
L1d cache:                       96 KiB (2 instances)
L1i cache:                       64 KiB (2 instances)
L2 cache:                        2.5 MiB (2 instances)
L3 cache:                        48 MiB (1 instance)
NUMA node(s):                    1
NUMA node0 CPU(s):               0,1
Vulnerability Itlb multihit:     KVM: Mitigation: VMX unsupported
Vulnerability L1tf:              Mitigation; PTE Inversion
Vulnerability Mds:               Mitigation; Clear CPU buffers; SMT Host state unknown
Vulnerability Meltdown:          Mitigation; PTI
Vulnerability Mmio stale data:   Vulnerable: Clear CPU buffers attempted, no microcode; SMT Host state unknown
Vulnerability Retbleed:          Not affected
Vulnerability Spec store bypass: Vulnerable
Vulnerability Spectre v1:        Mitigation; usercopy/swapgs barriers and __user pointer sanitization
Vulnerability Spectre v2:        Mitigation; Retpolines, STIBP disabled, RSB filling, PBRSB-eIBRS Not affected
Vulnerability Srbds:             Not affected
Vulnerability Tsx async abort:   Mitigation; Clear CPU buffers; SMT Host state unknown
```
