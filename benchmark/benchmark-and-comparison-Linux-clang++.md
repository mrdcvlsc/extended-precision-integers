# **Benchmark and Comparison**

Date: Thu Jul 20 17:36:11 UTC 2023

Compiler : clang++

OS : Linux


## **uint128_t**

## add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+** | 10 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+** | 10 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+** | 80 nanoseconds |

## sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-** | 50 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-** | 20 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-** | 40 nanoseconds |

## mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***** | 33 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***** | 33 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***** | 33 nanoseconds |

## div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/** | 266 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/** | 233 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/** | 66 nanoseconds |

## mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%** | 166 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%** | 366 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%** | 100 nanoseconds |


## assign add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+=** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+=** | 10 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+=** | 0 nanoseconds |

## assign sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-=** | 20 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-=** | 50 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-=** | 10 nanoseconds |

## assign mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***=** | 33 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***=** | 33 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***=** | 33 nanoseconds |

## assign div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/=** | 300 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/=** | 500 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/=** | 100 nanoseconds |

## assign mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%=** | 100 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%=** | 200 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%=** | 66 nanoseconds |


## left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<** | 100 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<** | 0 nanoseconds |

## right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>** | 30 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>** | 10 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>** | 0 nanoseconds |

## assign left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<=** | 30 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<=** | 30 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<=** | 40 nanoseconds |

## assign right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>=** | 10 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>=** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>=** | 80 nanoseconds |


## **uint192_t**

## add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+** | 40 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+** | 30 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+** | 50 nanoseconds |

## sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-** | 30 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-** | 40 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-** | 20 nanoseconds |

## mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***** | 33 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***** | 66 nanoseconds |

## div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/** | 133 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/** | 633 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/** | 66 nanoseconds |

## mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%** | 133 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%** | 333 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%** | 33 nanoseconds |


## assign add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+=** | 40 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+=** | 30 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+=** | 40 nanoseconds |

## assign sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-=** | 40 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-=** | 30 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-=** | 30 nanoseconds |

## assign mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***=** | 66 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***=** | 33 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***=** | 0 nanoseconds |

## assign div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/=** | 133 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/=** | 900 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/=** | 66 nanoseconds |

## assign mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%=** | 200 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%=** | 933 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%=** | 33 nanoseconds |


## left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<** | 40 nanoseconds |

## right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>** | 10 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>** | 0 nanoseconds |

## assign left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<=** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<=** | 10 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<=** | 0 nanoseconds |

## assign right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>=** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>=** | 90 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>=** | 0 nanoseconds |


## **uint256_t**

## add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+** | 30 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+** | 40 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+** | 20 nanoseconds |

## sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-** | 40 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-** | 40 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-** | 40 nanoseconds |

## mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***** | 100 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***** | 66 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***** | 0 nanoseconds |

## div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/** | 100 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/** | 533 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/** | 33 nanoseconds |

## mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%** | 233 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%** | 1766 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%** | 33 nanoseconds |


## assign add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+=** | 40 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+=** | 40 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+=** | 50 nanoseconds |

## assign sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-=** | 20 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-=** | 50 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-=** | 30 nanoseconds |

## assign mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***=** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***=** | 66 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***=** | 66 nanoseconds |

## assign div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/=** | 333 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/=** | 1500 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/=** | 66 nanoseconds |

## assign mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%=** | 200 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%=** | 1166 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%=** | 66 nanoseconds |


## left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<** | 80 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<** | 0 nanoseconds |

## right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>** | 60 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>** | 0 nanoseconds |

## assign left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<=** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<=** | 90 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<=** | 0 nanoseconds |

## assign right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>=** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>=** | 10 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>=** | 0 nanoseconds |


## **uint320_t**

## add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+** | 40 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+** | 30 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+** | 30 nanoseconds |

## sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-** | 20 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-** | 50 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-** | 30 nanoseconds |

## mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***** | 100 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***** | 66 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***** | 0 nanoseconds |

## div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/** | 166 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/** | 1566 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/** | 66 nanoseconds |

## mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%** | 266 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%** | 2100 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%** | 66 nanoseconds |


## assign add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+=** | 40 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+=** | 20 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+=** | 50 nanoseconds |

## assign sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-=** | 30 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-=** | 30 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-=** | 30 nanoseconds |

## assign mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***=** | 100 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***=** | 100 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***=** | 66 nanoseconds |

## assign div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/=** | 333 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/=** | 1233 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/=** | 100 nanoseconds |

## assign mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%=** | 100 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%=** | 1033 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%=** | 0 nanoseconds |


## left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<** | 50 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<** | 10 nanoseconds |

## right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>** | 10 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>** | 60 nanoseconds |

## assign left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<=** | 80 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<=** | 10 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<=** | 30 nanoseconds |

## assign right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>=** | 70 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>=** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>=** | 30 nanoseconds |


## **uint512_t**

## add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+** | 60 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+** | 40 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+** | 20 nanoseconds |

## sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-** | 60 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-** | 40 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-** | 20 nanoseconds |

## mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***** | 200 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***** | 100 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***** | 0 nanoseconds |

## div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/** | 366 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/** | 7733 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/** | 100 nanoseconds |

## mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%** | 166 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%** | 2766 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%** | 66 nanoseconds |


## assign add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+=** | 60 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+=** | 10 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+=** | 50 nanoseconds |

## assign sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-=** | 40 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-=** | 60 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-=** | 30 nanoseconds |

## assign mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***=** | 166 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***=** | 133 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***=** | 33 nanoseconds |

## assign div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/=** | 333 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/=** | 8467 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/=** | 66 nanoseconds |

## assign mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%=** | 233 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%=** | 5233 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%=** | 100 nanoseconds |


## left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<** | 20 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<** | 60 nanoseconds |

## right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>** | 60 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>** | 80 nanoseconds |

## assign left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<=** | 70 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<=** | 10 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<=** | 60 nanoseconds |

## assign right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>=** | 10 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>=** | 20 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>=** | 20 nanoseconds |


## **uint1024_t**

## add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+** | 50 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+** | 60 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+** | 40 nanoseconds |

## sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-** | 90 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-** | 80 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-** | 60 nanoseconds |

## mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***** | 633 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***** | 600 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***** | 66 nanoseconds |

## div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/** | 266 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/** | 37934 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/** | 33 nanoseconds |

## mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%** | 500 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%** | 24333 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%** | 100 nanoseconds |


## assign add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+=** | 50 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+=** | 50 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+=** | 50 nanoseconds |

## assign sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-=** | 70 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-=** | 80 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-=** | 50 nanoseconds |

## assign mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***=** | 833 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***=** | 666 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***=** | 0 nanoseconds |

## assign div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/=** | 400 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/=** | 38200 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/=** | 100 nanoseconds |

## assign mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%=** | 433 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%=** | 36334 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%=** | 0 nanoseconds |


## left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<** | 80 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<** | 80 nanoseconds |

## right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>** | 10 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>** | 80 nanoseconds |

## assign left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<=** | 90 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<=** | 0 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<=** | 90 nanoseconds |

## assign right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>=** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>=** | 100 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>=** | 0 nanoseconds |


## **uint524288_t**

## add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+** | 20240 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+** | 18120 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+** | 2180 nanoseconds |

## sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-** | 31330 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-** | 30380 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-** | 3120 nanoseconds |

## mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***** | 25604241 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***** | 147928592 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***** | 10000 nanoseconds |

## div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/** | 87334 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/** | 7977154724 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/** | 3233 nanoseconds |

## mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%** | 141835 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%** | 3854515983 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%** | 2400 nanoseconds |


## assign add operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **+=** | 18470 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **+=** | 18500 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **+=** | 3150 nanoseconds |

## assign sub operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **-=** | 152582 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **-=** | 121891 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **-=** | 3510 nanoseconds |

## assign mul operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | ***=** | 25614174 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | ***=** | 148535065 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | ***=** | 10066 nanoseconds |

## assign div operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **/=** | 51300 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **/=** | 3329066646 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **/=** | 6300 nanoseconds |

## assign mod operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **%=** | 118601 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **%=** | 3090555168 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **%=** | 7133 nanoseconds |


## left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<** | 80 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<** | 0 nanoseconds |

## right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>** | 90 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>** | 10 nanoseconds |

## assign left shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **<<=** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **<<=** | 10 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **<<=** | 0 nanoseconds |

## assign right shift operation : 

| Lib | Operator | Average |
| --- | --- | --- |
| [`wide-integer`](https://github.com/ckormanyos/wide-integer) | **>>=** | 0 nanoseconds |
| [`extended-precision-integers`](https://github.com/mrdcvlsc/extended-precision-integers) | **>>=** | 50 nanoseconds |
| [`boost::multiprecision`](https://github.com/boostorg/multiprecision) | **>>=** | 20 nanoseconds |


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
