.PHONY: all clean

CPPFILES=pb0209.cpp pb0059.cpp pb0707.cpp pb0024.cpp pb0019.cpp pb0142.cpp pb0454.cpp pb0015.cpp pb0018.cpp pb0151.cpp \
pb0028.cpp pb0007.cpp pb0150.cpp pb0347.cpp pb0102.cpp pb0107.cpp pb0199.cpp pb0429.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-std=c++11 -Wall

all: $(EXEFILES)

%: %.cpp
	g++ $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	