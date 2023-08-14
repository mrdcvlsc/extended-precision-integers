# **Benchmark and Comparison**

Date: Mon Aug 14 09:43:02 UTC 2023

Compiler : clang++

OS : Linux


# Benchmark for **uint128_t**

### uint128_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 26 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 106 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 750 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 131 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 650 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 75 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 26 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 131 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 850 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 68 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 118 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 731 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 68 ns |
| ................................. | ........ | ............ |

### uint128_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 27 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 27 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 24 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 24 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 25 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 26 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 25 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint192_t**

### uint192_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 150 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 1250 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 162 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 1162 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 62 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 6 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 50 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 131 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 1437 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 193 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 1175 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 31 ns |
| ................................. | ........ | ............ |

### uint192_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 41 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 36 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 29 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint256_t**

### uint256_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 35 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 50 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 175 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 1831 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 218 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 2156 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 6 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 68 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 43 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 12 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 143 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 2406 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 206 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 2125 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 31 ns |
| ................................. | ........ | ............ |

### uint256_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 42 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 34 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 30 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint320_t**

### uint320_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 39 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 68 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 62 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 143 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 2718 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 231 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 3418 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 39 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 24 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 47 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 56 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 68 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 175 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 3700 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 243 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 3462 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 37 ns |
| ................................. | ........ | ............ |

### uint320_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 42 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 34 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 34 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 29 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint512_t**

### uint512_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 36 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 46 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 150 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 112 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 231 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 8512 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 350 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 8400 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 34 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 42 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 41 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 41 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 162 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 131 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 187 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 8712 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 312 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 8312 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 43 ns |
| ................................. | ........ | ............ |

### uint512_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 41 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 40 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 38 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 39 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 30 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint1024_t**

### uint1024_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 62 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 53 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 73 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 67 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 38 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 518 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 550 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 275 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 39144 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 537 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 37763 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 58 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 57 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 69 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 65 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 42 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 556 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 493 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 293 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 39519 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 68 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 468 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 37750 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 56 ns |
| ................................. | ........ | ............ |

### uint1024_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 59 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 47 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 81 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 46 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 82 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 41 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 47 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 114 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 27 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint524288_t**

### uint524288_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 20158 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 18047 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 2284 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 31269 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 23133 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 2788 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 25573752 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 147831806 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 9068 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 130152 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 11434622644 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 11643 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 333161 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 11442595918 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 9412 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 18327 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 18370 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 3086 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 29278 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 23861 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 3267 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 25598901 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 147917493 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 10125 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 126407 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 12622751757 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 14669 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 312536 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 9270564566 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 13125 ns |
| ................................. | ........ | ............ |

### uint524288_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 7092 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 20756 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 3218 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 9932 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 30899 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 3194 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 5928 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 19608 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 3153 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 8051 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 34891 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 3100 ns |
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
