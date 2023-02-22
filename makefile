CXX=clang++
CXX_STANDARD=-std=c++17
FLAGS=-Wall -Wextra

ifeq ($(OS), Linux)
FLAGS+=-fsanitize=address
endif

default:
	@echo extended-precision-integers : written by @mrdcvlsc
	@echo makefile commands:
	@echo make test - compile test program
	@echo make run_test - run test program
	@echo make style - apply clang format

test:
	@echo compiling test program
	@$(CXX) $(CXX_STANDARD) test.cpp -o test.out $(FLAGS)

run_test:
	@echo running test program
	@./test.out

style:
	@echo fixing code format and code style
	@clang-format -i -style=file *.cpp *.hpp