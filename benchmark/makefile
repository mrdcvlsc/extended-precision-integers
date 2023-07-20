CXX:=clang++
CXX_FLAGS:=-std=c++17
OFLAG:=-O3
OS:=$(shell uname)

.PHONY: default download compile run

BLOCKS:=1 2 3
WIDENESS:=1 2 3 4 5 6 7
LIMBSIZE:=-D_LIMBSIZE_U16 -D_LIMBSIZE_U32 -D_LIMBSIZE_U64

EXECUTABLES:=\
$(foreach wide, $(WIDENESS), \
	$(foreach block, $(BLOCKS), \
		benchmark$(wide)_$(block).out\
	) \
)

default:
	@echo Benchmark and Comparison

run: $(EXECUTABLES)
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
	@echo "Compiling Benchmark Program"
	$(foreach executable, $(EXECUTABLES), \
		./$(executable) >> benchmark-and-comparison-$(OS)-$(CXX).md; \
	)

	@echo "" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "## System " >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "\`\`\`js" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "$$(lscpu)" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "\`\`\`" >> benchmark-and-comparison-$(OS)-$(CXX).md
	@echo "benchmark done"

#########################################################
#            COMPILE EXECUTABLES
#########################################################

# // _ARITHMETIC, _ASSIGNED_BLOCK1, _SHIFTS

%.out: benchmark.cpp ../epi.hpp wide-integer.dlrc boost-mp.dlrc
	@echo "Compiling Benchmark Program"
	$(foreach wide, $(WIDENESS), \
		$(foreach block, $(BLOCKS), \
			$(CXX) $(CXX_FLAGS) benchmark.cpp -o benchmark$(wide)_$(block).out $(OFLAG) -D_WIDENESS_BIT_NUM$(wide) -D_BLOCK_$(block) -I ./boost/include/; \
		) \
	)

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
	@rm -rf *.out *.md
