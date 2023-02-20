CXX=clang++
CXX_STANDARD=-std=c++17

default:
	@echo extended-precision-integers : written by @mrdcvlsc

test:
	$(CXX) $(CXX_STANDARD) test.cpp -o test.out -Wall -Wextra -fsanitize=address

run_test:
	./test.out

style:
	@clang-format -i -style=file *.cpp *.hpp