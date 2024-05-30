# **Benchmark and Comparison**

Date: Thu May 30 14:12:22 UTC 2024

Compiler : clang++

OS : Linux


# Benchmark for **uint128_t**

### uint128_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 41 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 76 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 489 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 94 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 468 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 40 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 70 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 534 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 36 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 86 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 447 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 32 ns |
| ................................. | ........ | ............ |

### uint128_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 28 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 28 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint192_t**

### uint192_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 40 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 83 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 916 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 108 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 861 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 74 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 1008 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 106 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 868 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 29 ns |
| ................................. | ........ | ............ |

### uint192_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 34 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 29 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint256_t**

### uint256_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 48 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 40 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 92 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 1423 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 34 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 120 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 1413 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 45 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 90 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 1670 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 121 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 1417 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 30 ns |
| ................................. | ........ | ............ |

### uint256_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 37 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 29 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint320_t**

### uint320_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 38 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 54 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 50 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 102 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 2043 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 34 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 128 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 2544 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 49 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 54 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 99 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 2484 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 42 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 135 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 2579 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 29 ns |
| ................................. | ........ | ............ |

### uint320_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 36 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 38 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 29 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint512_t**

### uint512_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 41 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 47 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 36 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 34 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 148 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 85 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 132 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 6144 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 39 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 180 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 6038 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 29 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 40 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 41 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 135 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 96 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 119 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 6557 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 42 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 212 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 6222 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 30 ns |
| ................................. | ........ | ............ |

### uint512_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 34 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 35 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 38 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 34 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 38 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 39 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 29 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint1024_t**

### uint1024_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 58 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 47 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 65 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 55 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 36 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 442 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 395 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 217 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 30529 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 44 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 320 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 28768 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 53 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 51 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 30 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 60 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 61 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 36 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 464 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 403 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 32 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 207 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 30327 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 48 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 313 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 28055 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 31 ns |
| ................................. | ........ | ............ |

### uint1024_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 42 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 38 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 41 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 80 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 31 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 41 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 52 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 33 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 88 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 120 ns |
| ................................. | ........ | ............ |

# Benchmark for **uint65536_t**

### uint65536_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 2227 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 2014 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 123 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 3521 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 2647 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 248 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 790015 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 1950881 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 145 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 14060 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 117973633 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 551 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 19115 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 109872795 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 297 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 2110 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 2097 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 242 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 3368 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 2763 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 359 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 784095 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 1946709 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 211 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 11093 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 107714011 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 603 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 20020 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 107559772 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 569 ns |
| ................................. | ........ | ............ |

### uint65536_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 676 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 1732 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 230 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 1629 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 3803 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 218 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 500 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 4408 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 232 ns |
| ................................. | ........ | ............ |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 1432 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 6646 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 222 ns |
| ................................. | ........ | ............ |


## System 
```js
Architecture:                       x86_64
CPU op-mode(s):                     32-bit, 64-bit
Address sizes:                      48 bits physical, 48 bits virtual
Byte Order:                         Little Endian
CPU(s):                             4
On-line CPU(s) list:                0-3
Vendor ID:                          AuthenticAMD
Model name:                         AMD EPYC 7763 64-Core Processor
CPU family:                         25
Model:                              1
Thread(s) per core:                 2
Core(s) per socket:                 2
Socket(s):                          1
Stepping:                           1
BogoMIPS:                           4890.85
Flags:                              fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx mmxext fxsr_opt pdpe1gb rdtscp lm constant_tsc rep_good nopl tsc_reliable nonstop_tsc cpuid extd_apicid aperfmperf pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 movbe popcnt aes xsave avx f16c rdrand hypervisor lahf_lm cmp_legacy svm cr8_legacy abm sse4a misalignsse 3dnowprefetch osvw topoext invpcid_single vmmcall fsgsbase bmi1 avx2 smep bmi2 erms invpcid rdseed adx smap clflushopt clwb sha_ni xsaveopt xsavec xgetbv1 xsaves clzero xsaveerptr rdpru arat npt nrip_save tsc_scale vmcb_clean flushbyasid decodeassists pausefilter pfthreshold v_vmsave_vmload umip vaes vpclmulqdq rdpid fsrm
Virtualization:                     AMD-V
Hypervisor vendor:                  Microsoft
Virtualization type:                full
L1d cache:                          64 KiB (2 instances)
L1i cache:                          64 KiB (2 instances)
L2 cache:                           1 MiB (2 instances)
L3 cache:                           32 MiB (1 instance)
NUMA node(s):                       1
NUMA node0 CPU(s):                  0-3
Vulnerability Gather data sampling: Not affected
Vulnerability Itlb multihit:        Not affected
Vulnerability L1tf:                 Not affected
Vulnerability Mds:                  Not affected
Vulnerability Meltdown:             Not affected
Vulnerability Mmio stale data:      Not affected
Vulnerability Retbleed:             Not affected
Vulnerability Spec rstack overflow: Vulnerable: Safe RET, no microcode
Vulnerability Spec store bypass:    Vulnerable
Vulnerability Spectre v1:           Mitigation; usercopy/swapgs barriers and __user pointer sanitization
Vulnerability Spectre v2:           Mitigation; Retpolines; STIBP disabled; RSB filling; PBRSB-eIBRS Not affected; BHI Not affected
Vulnerability Srbds:                Not affected
Vulnerability Tsx async abort:      Not affected
```
