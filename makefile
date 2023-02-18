CXX=clang++
CXX_STANDARD=-std=c++17

test:
	$(CXX) $(CXX_STANDARD) test.cpp -o test.out -Wall -Wextra -fsanitize=address

run_test:
	./test.out