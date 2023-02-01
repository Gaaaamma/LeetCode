.PHONY: all clean

CPPFILES=pb0001.cpp pb0704.cpp pb0027.cpp pb0977.cpp pb0203.cpp pb0206.cpp pb0160.cpp pb0242.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-Wall

all: $(EXEFILES)

%: %.cpp
	g++ $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	