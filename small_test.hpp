#ifndef SMALL_TEST_HPP
#define SMALL_TEST_HPP

#ifdef _DISABLE_PRINT_RESULTS
  #define _DISABLE_PRINT_SUBJECTS
#endif

#include <iostream>
#include <vector>

namespace smlts {

  // class definition

  /** @brief To make the output cleaner you can use these -D compilation flags :
   * `_DISABLE_PRINT_RESULTS`, `_DISABLE_PRINT_TEST_NAMES` and/or `_DISABLE_PRINT_SUBJECTS`.
   */
  class test {

    private:

    std::vector<size_t> test_results;
    std::vector<size_t> failed_cases;
    size_t              test_number;
    int                 final_verdict;

    void print_passed_failed(int result, std::string const &test_name = "");

    public:

    test() : test_number(0), final_verdict(0) {
    }

    template <typename T1, typename T2>
    void cmp_eq(T1 a, T2 b, size_t numBytes, std::string const &test_name = "");

    /// @brief  compare type sizes.
    template <typename T1, typename T2>
    void cmp_ts(std::string const &test_name = "");

    void cmp_exp(bool A, bool B, std::string const &test_name = "");

    void pass(std::string const& test_name);
    void fail(std::string const& test_name);

    /** @brief To make the output cleaner you can use these -D compilation flags :
     * `_DISABLE_PRINT_RESULTS`, `_DISABLE_PRINT_TEST_NAMES` and/or `_DISABLE_PRINT_SUBJECTS`.
     */
    int get_final_verdict();
  };

  // method declarations

  void test::print_passed_failed(int result, std::string const &test_name) {
#ifndef _DISABLE_PRINT_TEST_NAMES
    std::string internal_test_name = test_name;
#else
    std::string internal_test_name = "";
#endif

    if (!result) {
#ifndef _DISABLE_PRINT_RESULTS
      std::cout << "PASSED : "
                << "test " << std::dec << test_number << " (" << internal_test_name << ")";
#endif
    } else {
#ifndef _DISABLE_PRINT_RESULTS
      std::cout << "!!! FAILED : "
                << "test " << std::dec << test_number << " (" << internal_test_name << ")";
#endif
      failed_cases.push_back(test_number);
    }

#ifdef _DISABLE_PRINT_SUBJECTS
    std::cout << "\n";
#endif
  }

  template <typename T1, typename T2>
  void test::cmp_eq(T1 a, T2 b, size_t numBytes, std::string const &test_name) {
    test_number++;
    int result = memcmp(&a, &b, numBytes);
    test_results.push_back(result);
    final_verdict |= result;

    print_passed_failed(result, test_name);

#ifndef _DISABLE_PRINT_SUBJECTS
    std::cout << std::hex << "  ->  " << a << " == " << std::hex << b << "\n";
#endif
  }

  /// @brief  compare type sizes.
  template <typename T1, typename T2>
  void test::cmp_ts(std::string const &test_name) {
    test_number++;
    bool result = sizeof(T1) != sizeof(T2);
    test_results.push_back(result);
    final_verdict |= result;

    print_passed_failed(result, test_name);

#ifndef _DISABLE_PRINT_SUBJECTS
    std::cout << std::hex << "  ->  " << sizeof(T1) << " ::type_equality:: " << sizeof(T2) << "\n";
#endif
  }

  void test::cmp_exp(bool A, bool B, std::string const &test_name) {
    test_number++;
    bool result = A != B;
    test_results.push_back(result);
    final_verdict |= result;

    print_passed_failed(result, test_name);

#ifndef _DISABLE_PRINT_SUBJECTS
    std::cout << std::hex << "  ->  " << A << " :::: " << B << "\n";
#endif
  }

  void test::pass(std::string const& test_name) {
    test_number++;
    print_passed_failed(0, test_name);
    test_results.push_back(0);
    std::cout << "\n";
  }

  void test::fail(std::string const& test_name) {
    test_number++;
    print_passed_failed(1, test_name);
    test_results.push_back(1);
    failed_cases.push_back(test_number);
    std::cout << "\n";
  }

  int test::get_final_verdict() {
    if (!final_verdict) {
      std::cout << "\nFINAL VERDICT : PASSED\n";
      return 0;
    }

    std::cout << "\nFINAL VERDICT : FAILED\n\n";
    std::cout << "Failed on test cases :\n";

    for (auto e: failed_cases) {
      std::cout << std::dec << e << " ";
    }

    std::cout << "\nNumber of failed test cases : " << failed_cases.size() << "\n";
    std::cout << "\n";

    return 1;
  }

} // namespace smlts
#endif