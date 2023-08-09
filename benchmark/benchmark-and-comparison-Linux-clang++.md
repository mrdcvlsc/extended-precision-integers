# **Benchmark and Comparison**

Date: Wed Aug  9 14:21:27 UTC 2023

Compiler : clang++

OS : Linux


# Benchmark for **uint128_t**

### uint128_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 40 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 14 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 25 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 156 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 56 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 225 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 25 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 19 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 25 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 325 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 6 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 93 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 268 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 18 ns |

### uint128_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 27 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 26 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 25 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 23 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 26 ns |

# Benchmark for **uint192_t**

### uint192_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 43 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 18 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 68 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 575 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 81 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 431 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 34 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 62 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 506 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 131 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 650 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 31 ns |

### uint192_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 27 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 40 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 33 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 29 ns |

# Benchmark for **uint256_t**

### uint256_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 33 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 56 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 56 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 868 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 75 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 125 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 875 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 34 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 62 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 675 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 100 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 962 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 18 ns |

### uint256_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 40 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 26 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 34 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 25 ns |

# Benchmark for **uint320_t**

### uint320_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 38 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 41 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 62 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 56 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 75 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 1500 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 62 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 87 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 1168 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 50 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 35 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 36 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 62 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 68 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 68 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 1712 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 106 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 981 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 31 ns |

### uint320_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 34 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 38 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 39 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 35 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 26 ns |

# Benchmark for **uint512_t**

### uint512_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 41 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 27 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 51 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 42 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 40 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 212 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 112 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 18 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 87 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 3825 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 62 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 156 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 3381 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 25 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 44 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 38 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 23 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 47 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 44 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 175 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 125 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 106 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 4618 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 143 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 3362 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 37 ns |

### uint512_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 40 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 41 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 30 ns |

# Benchmark for **uint1024_t**

### uint1024_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 61 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 53 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 73 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 64 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 41 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 518 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 468 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 168 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 21256 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 6 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 350 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 22575 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 56 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 53 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 66 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 66 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 43 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 687 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 487 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 18 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 112 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 14300 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 56 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 337 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 18062 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 6 ns |

### uint1024_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 33 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 53 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 42 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 33 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 83 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 40 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 75 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 39 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 40 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 101 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 28 ns |

# Benchmark for **uint524288_t**

### uint524288_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 20153 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 18214 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 2260 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 31126 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 23096 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 2534 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 25593856 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 147902294 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 9100 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 68875 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 6379758673 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 9737 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 223396 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 5882415374 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 6668 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 18326 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 18379 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 2991 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 29320 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 23838 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 3220 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 25580843 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 147864909 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 9587 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 68019 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 6950032676 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 12656 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 109869 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 4739940873 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 7550 ns |

### uint524288_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 10765 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 20322 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 2935 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 9929 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 31546 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 2941 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 7934 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 19598 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 2880 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 8039 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 34272 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 2900 ns |


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
