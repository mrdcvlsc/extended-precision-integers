#ifndef EXTENDED_PRECISION_INTEGERS_CONFIG_HPP
#define EXTENDED_PRECISION_INTEGERS_CONFIG_HPP

#if (defined(__SIZEOF_INT128__) || defined(UINT128MAX))
  #define ENV_64BIT_EXTENDED
#elif (defined(__amd__64__) || defined(__amd_64) || defined(__x86_64__) || defined(__x86_64))
  #define ENV_64_BIT
#elif (defined(__INTEL__) || defined(__i386__) || defined(_M_IX86) || defined(__arm__))
  #define ENV_32_BIT
#endif

// dev
#define _LITTLE_ENDIAN

#endif