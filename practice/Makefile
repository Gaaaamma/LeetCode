.PHONY: all clean

CPPFILES= backpack01.cpp bubbleSort.cpp selectSort.cpp insertSort.cpp quickSort.cpp transform.cpp disjointSet.cpp mergeSort.cpp \
constructors.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-std=c++11 -Wall

all: $(EXEFILES)

%: %.cpp
	g++  $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	