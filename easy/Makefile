.PHONY: all clean

CPPFILES=pb0001.cpp pb0704.cpp pb0027.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-Wall

all: $(EXEFILES)

%: %.cpp
	g++ $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	