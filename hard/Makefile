.PHONY: all clean

CPPFILES= pb0239.cpp pb0332.cpp pb0051.cpp pb0037.cpp pb0135.cpp pb0968.cpp pb0123.cpp pb0188.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-std=c++11 -Wall

all: $(EXEFILES)

%: %.cpp
	g++  $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	