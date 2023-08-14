#ifndef MRDCVLSC_EXTENDED_PRECISION_INTEGERS_CONFIG_HPP
#define MRDCVLSC_EXTENDED_PRECISION_INTEGERS_CONFIG_HPP

#if (defined(__SIZEOF_INT128__) || defined(UINT128MAX))
  // TODO: find way to check if the following instructions are available `__umodti3` & `__udivti3`
  // #define ENV_64BIT_EXTENDED // temporarily disabled since some environment does not support `__umodti3` & `__udivti3`
  
  #define ENV_64_BIT
#elif (defined(__amd__64__) || defined(__amd_64) || defined(__x86_64__) || defined(__x86_64))
  #define ENV_64_BIT
#elif (defined(__INTEL__) || defined(__i386__) || defined(_M_IX86) || defined(__arm__))
  #define ENV_32_BIT
#endif

// dev
#define _LITTLE_ENDIAN

#endif