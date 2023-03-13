.PHONY: all clean

CPPFILES= backpack01.cpp bubbleSort.cpp selectSort.cpp insertSort.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-std=c++11 -Wall

all: $(EXEFILES)

%: %.cpp
	g++  $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	