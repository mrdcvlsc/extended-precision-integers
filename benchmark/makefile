CXX=clang++
CXX_FLAGS=-std=c++17
OFLAG=-O3

.PHONY: default download compile run

default:
	@echo Benchmark and Comparison

run: benchmark.out
	./benchmark.out

benchmark.out: wide-integer.dlrc benchmark.cpp
	$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark.out $(OFLAG)

#########################################################
#            DOWNLOAD AND EXTRACT LIBRARIES
#########################################################

wide-integer.dlrc:
	wget https://github.com/ckormanyos/wide-integer/archive/refs/heads/master.zip
	unzip master.zip -d ./
	mv ./wide-integer-master ./wide-integer
	rm master.zip
	echo "downloaded: $$(date)" > wide-integer.dlrc

#########################################################

clean:
	rm -rf wide-integer benchmark.out *.dlrc *.zip *.tar *.tgz *.o