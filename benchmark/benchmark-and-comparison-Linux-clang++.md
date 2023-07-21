# **Benchmark and Comparison**

Date: Fri Jul 21 17:42:47 UTC 2023

Compiler : clang++

OS : Linux


# Benchmark for **uint128_t**

### uint128_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 25 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 26 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 18 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 18 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 68 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 306 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 18 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 62 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 168 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 37 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 21 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 26 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 22 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 27 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 31 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 62 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 337 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 50 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 87 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 250 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 37 ns |

### uint128_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 35 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 20 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 33 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 0 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 74 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 0 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 24 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 19 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 41 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 21 ns |

# Benchmark for **uint192_t**

### uint192_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 28 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 30 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 35 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 37 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 300 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 56 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 118 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 568 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 31 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 30 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 33 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 18 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 50 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 50 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 893 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 56 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 87 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 512 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 37 ns |

### uint192_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 42 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 28 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 32 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 36 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 35 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 26 ns |

# Benchmark for **uint256_t**

### uint256_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 36 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 28 ns |
memcmp = 71
Failed sub operation

| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 31 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 29 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 29 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 34 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 56 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 43 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 18 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 81 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 1081 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 31 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 125 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 1168 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 18 ns |

### uint256_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 44 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 555 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 32 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 35 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 32 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 39 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 28 ns |

# Benchmark for **uint320_t**

### uint320_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 38 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 31 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 30 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 39 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 31 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 75 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 68 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 25 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 93 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 1325 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 56 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 81 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 987 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 43 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 32 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 30 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 28 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 33 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 34 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 34 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 68 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 25 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 62 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 1668 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 43 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 125 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 1368 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 43 ns |

### uint320_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 26 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 34 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 42 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 29 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 34 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 33 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 35 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 35 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 32 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 28 ns |

# Benchmark for **uint512_t**

### uint512_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 43 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 27 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 50 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 45 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 39 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 162 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 112 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 43 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 75 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 2893 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 31 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 143 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 3837 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 37 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 41 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 36 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 30 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 44 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 45 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 39 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 156 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 118 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 31 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 112 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 4043 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 68 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 193 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 3818 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 62 ns |

### uint512_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 27 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 35 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 43 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 34 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 32 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 38 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 39 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 35 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 37 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 37 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 27 ns |

# Benchmark for **uint1024_t**

### uint1024_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 60 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 52 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 29 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 74 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 64 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 41 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 687 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 568 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 31 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 125 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 11831 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 37 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 243 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 11306 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 37 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 55 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 56 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 33 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 68 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 63 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 44 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 568 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 475 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 12 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 106 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 16694 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 62 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 368 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 23706 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 50 ns |

### uint1024_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 30 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 63 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 42 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 33 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 87 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 32 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 42 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 71 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 36 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 40 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 102 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 41 ns |

# Benchmark for **uint524288_t**

### uint524288_t Arithmetic Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+`** | 20133 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+`** | 18062 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+`** | 2147 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-`** | 31150 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-`** | 23036 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-`** | 2827 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*`** | 25410000 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*`** | 147848024 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*`** | 8687 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/`** | 48594 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/`** | 4366800192 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/`** | 7443 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%`** | 157057 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%`** | 6291866899 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%`** | 5243 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`+=`** | 18332 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`+=`** | 18314 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`+=`** | 2821 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`-=`** | 29289 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`-=`** | 23842 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`-=`** | 3279 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`*=`** | 25576978 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`*=`** | 147874618 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`*=`** | 9743 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`/=`** | 45481 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`/=`** | 4632821296 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`/=`** | 9393 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`%=`** | 94751 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`%=`** | 5496050504 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`%=`** | 8418 ns |

### uint524288_t Shift Operations : 

| Library | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<`** | 10670 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<`** | 20392 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<`** | 2936 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>`** | 10070 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>`** | 31634 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>`** | 2860 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`<<=`** | 8812 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`<<=`** | 23649 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`<<=`** | 2837 ns |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **`>>=`** | 8059 ns |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **`>>=`** | 34226 ns |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **`>>=`** | 2857 ns |


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
