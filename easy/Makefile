.PHONY: all clean

CPPFILES=pb0001.cpp pb0704.cpp pb0027.cpp pb0977.cpp pb0203.cpp pb0206.cpp pb0160.cpp pb0242.cpp pb1002.cpp pb0349.cpp pb0202.cpp \
pb0383.cpp pb0344.cpp pb0541.cpp ex0005.cpp ex0058.cpp pb0459.cpp pb0232.cpp pb0225.cpp pb0020.cpp pb1047.cpp traverseTree.cpp \
pb0144.cpp pb0145.cpp pb0094.cpp pb0104.cpp pb0637.cpp pb0111.cpp pb0226.cpp pb0101.cpp pb0110.cpp pb0257.cpp pb0100.cpp pb0404.cpp \
pb0112.cpp pb0014.cpp pb0617.cpp pb0700.cpp pb0530.cpp pb0501.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-std=c++11 -Wall

all: $(EXEFILES)

%: %.cpp
	g++ $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	