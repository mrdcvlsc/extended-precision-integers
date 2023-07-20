CXX:=clang++
CXX_FLAGS:=-std=c++17
OFLAG:=-O3
OS:=$(shell uname)

.PHONY: default download compile run

default:
	@echo Benchmark and Comparison

run: \
benchmark1-128.out benchmark2-128.out benchmark3-128.out \
benchmark1-192.out benchmark2-192.out benchmark3-192.out \
benchmark1-256.out benchmark2-256.out benchmark3-256.out \
benchmark1-320.out benchmark2-320.out benchmark3-320.out \
benchmark1-512.out benchmark2-512.out benchmark3-512.out \
benchmark1-1024.out benchmark2-1024.out benchmark3-1024.out \
benchmark1-524288.out benchmark2-524288.out benchmark3-524288.out
	@echo "Running Benchmark Program"
	@echo "# **Benchmark and Comparison**" > benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "Date: $$(date)" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "Compiler : $(CXX)" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "OS : $(OS)" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "running benchmark"
	
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark1-128.out >> benchmark-and-comparison-$(OS)-$(CXX).md	
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark2-128.out >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark3-128.out >> benchmark-and-comparison-$(OS)-$(CXX).md

	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark1-192.out >> benchmark-and-comparison-$(OS)-$(CXX).md	
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark2-192.out >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark3-192.out >> benchmark-and-comparison-$(OS)-$(CXX).md

	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark1-256.out >> benchmark-and-comparison-$(OS)-$(CXX).md	
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark2-256.out >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark3-256.out >> benchmark-and-comparison-$(OS)-$(CXX).md

	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark1-320.out >> benchmark-and-comparison-$(OS)-$(CXX).md	
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark2-320.out >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark3-320.out >> benchmark-and-comparison-$(OS)-$(CXX).md

	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark1-512.out >> benchmark-and-comparison-$(OS)-$(CXX).md	
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark2-512.out >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark3-512.out >> benchmark-and-comparison-$(OS)-$(CXX).md

	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark1-1024.out >> benchmark-and-comparison-$(OS)-$(CXX).md	
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark2-1024.out >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark3-1024.out >> benchmark-and-comparison-$(OS)-$(CXX).md

	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark1-524288.out >> benchmark-and-comparison-$(OS)-$(CXX).md	
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark2-524288.out >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	./benchmark3-524288.out >> benchmark-and-comparison-$(OS)-$(CXX).md

	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "## System " >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "\`\`\`js" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "$$(lscpu)" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "\`\`\`" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "benchmark done"

#########################################################
#            COMPILE EXECUTABLES
#########################################################

# // _ARITHMETIC, _ASSIGNED_ARITHMETIC, _SHIFTS

benchmark1-128.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark1-128.out -O3 $(OFLAG) -D_ARITHMETIC -D_WIDENESS_128BIT -I ./boost/include/

benchmark2-128.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark2-128.out -O3 $(OFLAG) -D_ASSIGNED_ARITHMETIC -D_WIDENESS_128BIT -I ./boost/include/

benchmark3-128.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark3-128.out -O3 $(OFLAG) -D_SHIFTS -I ./boost/include/

benchmark1-192.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark1-192.out -O3 $(OFLAG) -D_ARITHMETIC -D_WIDENESS_192BIT -I ./boost/include/

benchmark2-192.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark2-192.out -O3 $(OFLAG) -D_ASSIGNED_ARITHMETIC -D_WIDENESS_192BIT -I ./boost/include/

benchmark3-192.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark3-192.out -O3 $(OFLAG) -D_SHIFTS -I ./boost/include/

benchmark1-256.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark1-256.out -O3 $(OFLAG) -D_ARITHMETIC -D_WIDENESS_256BIT -I ./boost/include/

benchmark2-256.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark2-256.out -O3 $(OFLAG) -D_ASSIGNED_ARITHMETIC -D_WIDENESS_256BIT -I ./boost/include/

benchmark3-256.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark3-256.out -O3 $(OFLAG) -D_SHIFTS -I ./boost/include/

benchmark1-320.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark1-320.out -O3 $(OFLAG) -D_ARITHMETIC -D_WIDENESS_320BIT -I ./boost/include/

benchmark2-320.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark2-320.out -O3 $(OFLAG) -D_ASSIGNED_ARITHMETIC -D_WIDENESS_320BIT -I ./boost/include/

benchmark3-320.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark3-320.out -O3 $(OFLAG) -D_SHIFTS -I ./boost/include/

benchmark1-512.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark1-512.out -O3 $(OFLAG) -D_ARITHMETIC -D_WIDENESS_512BIT -I ./boost/include/

benchmark2-512.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark2-512.out -O3 $(OFLAG) -D_ASSIGNED_ARITHMETIC -D_WIDENESS_512BIT -I ./boost/include/

benchmark3-512.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark3-512.out -O3 $(OFLAG) -D_SHIFTS -I ./boost/include/

benchmark1-1024.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark1-1024.out -O3 $(OFLAG) -D_ARITHMETIC -D_WIDENESS_1024BIT -I ./boost/include/

benchmark2-1024.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark2-1024.out -O3 $(OFLAG) -D_ASSIGNED_ARITHMETIC -D_WIDENESS_1024BIT -I ./boost/include/

benchmark3-1024.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark3-1024.out -O3 $(OFLAG) -D_SHIFTS -I ./boost/include/

benchmark1-524288.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark1-524288.out -O3 $(OFLAG) -D_ARITHMETIC -D_WIDENESS_524288BIT -I ./boost/include/

benchmark2-524288.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark2-524288.out -O3 $(OFLAG) -D_ASSIGNED_ARITHMETIC -D_WIDENESS_524288BIT -I ./boost/include/

benchmark3-524288.out: wide-integer.dlrc boost-mp.dlrc benchmark.cpp ../epi.hpp
	@echo "Compiling Benchmark Program"
	@$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark3-524288.out -O3 $(OFLAG) -D_SHIFTS -I ./boost/include/

#########################################################
#            DOWNLOAD AND EXTRACT LIBRARIES
#########################################################

boost-mp.dlrc:
	@echo "Downloading : boost.org : boost::multiprecision"
	@wget https://github.com/boostorg/multiprecision/archive/refs/tags/Boost_1_82_0.tar.gz
	@echo "Extracting  : boost.org : boost::multiprecision"
	@tar -xvzf Boost_1_82_0.tar.gz
	@mv ./multiprecision-Boost_1_82_0 ./boost
	@rm Boost_1_82_0.tar.gz
	@echo "downloaded: $$(date)" > boost-mp.dlrc

wide-integer.dlrc:
	@echo "Downloading : ckormanyos - wide-integer"
	@wget https://github.com/ckormanyos/wide-integer/archive/refs/heads/master.zip
	@echo "Extracting  : ckormanyos - wide-integer"
	@unzip master.zip -d ./
	@mv ./wide-integer-master ./wide-integer
	@rm master.zip
	@echo "downloaded: $$(date)" > wide-integer.dlrc

#########################################################

clean:
	@rm -rf wide-integer boost benchmark.out *.dlrc *.zip *.tar *.gz *.o *.out *.md