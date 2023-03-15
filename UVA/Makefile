.PHONY: all clean

CPPFILES= SuperLongSum.cpp ILoveBigNums.cpp MinimalCoverage.cpp Parity.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-std=c++11 -Wall

all: $(EXEFILES)

%: %.cpp
	g++  $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	