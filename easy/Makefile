.PHONY: all clean

CPPFILES=pb001.cpp pb704.cpp
EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-Wall

all: $(EXEFILES)

%: %.cpp
	g++ $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	