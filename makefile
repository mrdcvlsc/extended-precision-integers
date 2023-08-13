CC:=clang
CXX:=clang++
OS:=$(shell uname)

.PHONY: default test clean style

default:
	@echo extended-precision-integers : written by @mrdcvlsc
	@echo OS : $(OS)
	@echo Compiler :
	@$(CC) --version

test:
	@echo compiling test program...
	@echo OS : $(OS)
	@echo Compiler : $(CXX)
	$(MAKE) -C tests test

clean:
	@echo removing compiled test programs
	rm benchmark/*.out tests/*.out benchmark/*.exe tests/*.exe

style:
	@echo fixing code format and code style...
	@clang-format -i -style=file include/epi/*.hpp tests/*.cpp tests/*.hpp benchmark/*.cpp
	@echo done fixing style format.