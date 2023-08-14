CC:=gcc
CXX:=g++
OS:=$(shell uname)

HEADERS:=$(wildcard ../include/epi/*.hpp)
TEST_EXECUTABLES:=$(subst .cpp,.out,$(wildcard *.cpp))
LINKING:=

CXX_STANDARD:=-std=c++20
CXX_LIB:=
CXXFLAGS:=-Wall -Wextra -g3
LIBFLAGS:=

# disable asan if compiler is an arm compiler
IS_ARM_COMPILER:=$(findstring arch,$(CC))$(findstring arm,$(CC))

# disable asan if on a windows operating system
IS_ON_WINDOWS:=$(findstring MSYS_NT,$(OS))$(findstring win,$(OS))$(findstring Win,$(OS))$(findstring WIN,$(OS))

ENABLE_SANITIZER:=$(if $(strip $(IS_ARM_COMPILER)$(IS_ON_WINDOWS)),noasan)

ifneq ($(ENABLE_SANITIZER),noasan)
LIBFLAGS+=-fsanitize=address
endif

.PHONY: test clean

test: $(TEST_EXECUTABLES)
	$(foreach TEST_PROGRAM, $^,\
		./$(TEST_PROGRAM) ;\
	)

$(TEST_EXECUTABLES): %.out: %.cpp $(HEADERS) small_test.hpp
	$(strip $(CXX) $(LINKING) $(CXX_STANDARD) $(CXXFLAGS) $< -o $@ $(LIBFLAGS))

clean:
	@echo "main makefile - clean"
	@rm *.out