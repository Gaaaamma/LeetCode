.PHONY: all clean

CPPFILES=pb0209.cpp pb0059.cpp pb0707.cpp pb0024.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-Wall

all: $(EXEFILES)

%: %.cpp
	g++ $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	