#ifndef EXTENDED_PRECISION_INTEGERS_CONFIG_HPP
#define EXTENDED_PRECISION_INTEGERS_CONFIG_HPP

#if (defined(__SIZEOF_INT128__) || defined(UINT128MAX))
  #warning default template argument types used <uint64_t, __uint128_t>
  #define ENV_64BIT_EXTENDED
#elif (defined(__amd__64__) || defined(__amd_64) || defined(__x86_64__) || defined(__x86_64))
  #warning default template argument types used <uint32_t, uint64_t>
  #define ENV_64_BIT
#elif (defined(__INTEL__) || defined(__i386__) || defined(_M_IX86) || defined(__arm__))
  #warning default template argument types used <uint16_t, uint32_t>
  #define ENV_32_BIT
#endif

#endif