#ifndef SMALL_TEST_HPP
#define SMALL_TEST_HPP

#include <iostream>
#include <ostream>
#include <vector>

#define ASSERT_EQ_SMLTS(TEST, A, B, BYTES) (TEST).cmp_eq((A), (B), (BYTES), __FILE__, __LINE__);

namespace smlts {

    // class definition

    /** @brief To make the output cleaner you can use these -D compilation flags :
     * `_DISABLE_PRINT_RESULTS`, `_DISABLE_PRINT_TEST_NAMES` and/or
     * `_DISABLE_PRINT_SUBJECTS`.
     */
    class test {

        private:

        std::vector<std::string> file;
        std::vector<size_t>      line;
        std::vector<size_t>      test_results;
        int                      final_verdict;

        public:

        test() : file{}, line{}, test_results{}, final_verdict(0) {
        }

        template <typename T1, typename T2>
        void cmp_eq(T1 a, T2 b, size_t numBytes, std::string const &file_name, size_t file_line);

        /// @brief  compare type sizes.
        template <typename T1, typename T2>
        void cmp_ts(std::string const &file_name, size_t file_line);

        void cmp_exp(bool A, bool B, std::string const &file_name, size_t file_line);

        void assertion(bool expression, std::string const &file_name, size_t file_line);

        void pass(std::string const &, size_t);
        void fail(std::string const &file_name, size_t file_line);

        /** @brief To make the output cleaner you can use these -D compilation flags
         * :
         * `_DISABLE_PRINT_RESULTS`, `_DISABLE_PRINT_TEST_NAMES` and/or
         * `_DISABLE_PRINT_SUBJECTS`.
         */
        int get_final_verdict(std::string const &);
        int get_final_verdict_silent();
    };

    void test::pass(std::string const &, size_t) {
        test_results.push_back(0);
        final_verdict |= 0;
    }

    void test::fail(std::string const &file_name, size_t file_line) {
        test_results.push_back(1);
        file.push_back(file_name);
        line.push_back(file_line);
        final_verdict |= 1;
    }

    template <typename T1, typename T2>
    void test::cmp_eq(T1 a, T2 b, size_t numBytes, std::string const &file_name, size_t file_line) {
        int result = memcmp(&a, &b, numBytes);
        test_results.push_back(result);
        if (result) {
            file.push_back(file_name);
            line.push_back(file_line);
        }
        final_verdict |= result;
    }

    /// @brief  compare type sizes.
    template <typename T1, typename T2>
    void test::cmp_ts(std::string const &file_name, size_t file_line) {
        bool result = sizeof(T1) != sizeof(T2);
        test_results.push_back(result);
        if (result) {
            file.push_back(file_name);
            line.push_back(file_line);
        }
        final_verdict |= static_cast<int>(result);
    }

    void test::cmp_exp(bool A, bool B, std::string const &file_name, size_t file_line) {
        bool result = A != B;
        test_results.push_back(result);
        if (result) {
            file.push_back(file_name);
            line.push_back(file_line);
        }
        final_verdict |= static_cast<int>(result);
    }

    void test::assertion(bool expression, std::string const &file_name, size_t file_line) {
        bool result = !expression;
        test_results.push_back(result);
        if (result) {
            file.push_back(file_name);
            line.push_back(file_line);
        }
        final_verdict |= static_cast<int>(result);
    }

    int test::get_final_verdict(std::string const &test_name = "") {
        if (!final_verdict) {
            // std::cout << "\nFINAL VERDICT [" << test_name << "] TEST : PASSED\n";
            return 0;
        }

        // std::cout << "\nFINAL VERDICT [" << test_name << "] TEST : FAILED\n\n";
        // std::cout << "Failed on test cases :\n";

        for (size_t i = 0; i < file.size(); ++i) {
            // std::cout << "\tfile : " << file[i] << " | line : " << line[i] << "\n";
        }

        return 1;
    }

    int test::get_final_verdict_silent() {
        if (!final_verdict) {
            return 0;
        }

        return 1;
    }

} // namespace smlts
#endif