CXX=clang++
CXX_STANDARD=-std=c++17
FLAGS=-Wall -Wextra
OS := $(shell uname)

ifeq ($(OS), Linux)
FLAGS+=-fsanitize=address
EXTENSION=out
OUTPUT_NAME=epi_test
else
EXTENSION=exe
OUTPUT_NAME=epi_test
endif


default:
	@echo OS : $(OS)
	@echo Compiler : $(CXX)
	@echo extended-precision-integers : written by @mrdcvlsc
	@echo makefile commands:
	@echo make test - compile test program
	@echo make run_test - run test program
	@echo make style - apply clang format

test:
	@echo compiling test program...
	@echo OS : $(OS)
	@echo Compiler : $(CXX)
	@$(CXX) $(CXX_STANDARD) test.cpp -o $(OUTPUT_NAME).$(EXTENSION) $(FLAGS)
	@echo done compiling test program.

run_test:
	@echo running test program...
ifeq ($(OS), Linux)
	./$(OUTPUT_NAME).$(EXTENSION)
else
	./$(OUTPUT_NAME).$(EXTENSION)
endif
	@echo done running test program.

style:
	@echo fixing code format and code style...
	@clang-format -i -style=file *.cpp *.hpp
	@echo done fixing style format.

.PHONY: test run_test style