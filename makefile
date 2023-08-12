CC=clang
CXX=clang++
CXX_STANDARD=-std=c++20
WARNING_FLAGS=-Wall -Wextra -Wno-shift-count-negative -Wno-shift-count-overflow
DFLAGS=
SANITIZER_FLAG=
OS := $(shell uname)

ifeq ($(OS), Linux)
EXTENSION=out
OUTPUT_NAME=epi_test
else
EXTENSION=exe
OUTPUT_NAME=epi_test
endif

OS_COMPILER=$(OS)$(CXX)

ifeq ($(OS_COMPILER), Linuxclang++)
SANITIZER_FLAG+=-g3 -fsanitize=address
endif

default:
	@echo extended-precision-integers : written by @mrdcvlsc
	@echo OS : $(OS)
	@echo Compiler :
	@$(CC) --version

test:
	@echo compiling test program...
	@echo OS : $(OS)
	@echo Compiler : $(CXX)
	$(CXX) $(CXX_STANDARD) tests/test.cpp -o tests/$(OUTPUT_NAME).$(EXTENSION) $(WARNING_FLAGS) $(SANITIZER_FLAG) $(DFLAGS)
	@echo done compiling test program.

run_test:
	@echo running test program...
	./tests/$(OUTPUT_NAME).$(EXTENSION)
	@echo done running test program.

style:
	@echo fixing code format and code style...
	@clang-format -i -style=file *.cpp *.hpp tests/*.cpp tests/*.hpp benchmark/*.cpp benchmark/*.hpp
	@echo done fixing style format.

perf_build:
	@echo compiling test program without sanitizers...
	@echo OS : $(OS)
	@echo Compiler : $(CXX)
	@$(CXX) $(CXX_STANDARD) tests/test_perf.cpp -o tests/$(OUTPUT_NAME)_perf.$(EXTENSION) $(WARNING_FLAGS) -D_NO_PRINT_PASS -D_DISABLE_PRINT_SUBJECTS -D_DISABLE_PRINT_RESULTS -D_DISABLE_PRINT_TEST_NAMES -O3
	@echo done compiling test program.

perf_run:
	@echo "-----------------------------------------------------"
	@echo "perf stat -d"
	perf stat -d ./tests/$(OUTPUT_NAME)_perf.$(EXTENSION)
	@echo "-----------------------------------------------------"
	@echo "perf record"
	perf record ./tests/$(OUTPUT_NAME)_perf.$(EXTENSION)

perf_report:
	perf report

.PHONY: test run_test style