OS:=$(shell uname)
HEADERS:=$(wildcard ../*.hpp)
TEST_EXECUTABLES:=$(subst .cpp,.out,$(wildcard *.cpp))
LINKING:=

CXXFLAGS:=-Wall -Wextra -g3 -std=c++20

ifeq ($(CXX), Linux)
CXXFLAGS+=-fsanitize=address
endif

.PHONY: test clean

test: $(TEST_EXECUTABLES)
	$(foreach TEST_PROGRAM, $^,\
		./$(TEST_PROGRAM) ;\
	)

$(TEST_EXECUTABLES): %.out: %.cpp $(HEADERS) small_test.hpp
	$(strip $(CXX) $(LINKING) $< -o $@ $(CXXFLAGS))

clean:
	@echo "main makefile - clean"
	@rm *.out