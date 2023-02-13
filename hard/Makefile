.PHONY: all clean

CPPFILES= pb0239.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-std=c++11 -Wall

all: $(EXEFILES)

%: %.cpp
	g++  $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	