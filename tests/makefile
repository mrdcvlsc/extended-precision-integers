OS:=$(shell uname)
HEADERS:=$(wildcard ../include/epi/*.hpp)
TEST_EXECUTABLES:=$(subst .cpp,.out,$(wildcard *.cpp))
LINKING:=

CXX_STANDARD:=-std=c++20
CXX_LIB:=
CXXFLAGS:=-Wall -Wextra -g3
LIBFLAGS:=

OS_COMPILER:=$(OS)-$(CXX)

# ifeq ($(OS_COMPILER), Linux-clang++)
ifeq ($(CXX), clang++)
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