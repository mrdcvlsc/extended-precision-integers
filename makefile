CXX=clang++
CXX_STANDARD=-std=c++17

test:
	$(CXX) $(CXX_STANDARD) main.cpp -o main.out -Wall -Wextra -fsanitize=address

run:
	./main.out