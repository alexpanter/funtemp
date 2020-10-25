.PHONY: clean

GCC=g++
STD=-std=c++17
FLAGS=-Werror
HEADERS=pair.hpp

test: test.cpp $(HEADERS)
	$(GCC) $(STD) $< -o $@
	@./$@

clean:
	@rm -f test
