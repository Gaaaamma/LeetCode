.PHONY: all clean

CPPFILES=pb0209.cpp pb0059.cpp pb0707.cpp pb0024.cpp pb0019.cpp pb0142.cpp pb0454.cpp pb0015.cpp pb0018.cpp pb0151.cpp \
pb0028.cpp pb0007.cpp pb0150.cpp pb0347.cpp pb0102.cpp pb0107.cpp pb0199.cpp pb0429.cpp pb0515.cpp pb0116.cpp pb0117.cpp \
pb0222.cpp pb0513.cpp pb0113.cpp pb0106.cpp pb0105.cpp pb0654.cpp pb0098.cpp pb0236.cpp pb0235.cpp pb0701.cpp pb0450.cpp \
pb0669.cpp pb0538.cpp pb0077.cpp pb0216.cpp pb0017.cpp pb0039.cpp pb0040.cpp pb0131.cpp pb0093.cpp pb0078.cpp pb0090.cpp \
pb0491.cpp pb0046.cpp pb0047.cpp pb0376.cpp pb0053.cpp pb0122.cpp pb0055.cpp pb0045.cpp pb0134.cpp pb0406.cpp pb0452.cpp \
pb0435.cpp pb0763.cpp pb0056.cpp pb0738.cpp pb0714.cpp pb0062.cpp pb0063.cpp pb0343.cpp pb0096.cpp pb0416.cpp pb1049.cpp \
pb0494.cpp pb0474.cpp pb0518.cpp pb0377.cpp pb0322.cpp pb0279.cpp pb0139.cpp pb0198.cpp pb0213.cpp pb0337.cpp pb0309.cpp \
pb0300.cpp pb0718.cpp pb1143.cpp pb1035.cpp pb0739.cpp pb0002.cpp pb0011.cpp pb0022.cpp pb0967.cpp pb0003.cpp pb0005.cpp \
pb0031.cpp pb0054.cpp pb0064.cpp pb0073.cpp pb0074.cpp pb0033.cpp pb0200.cpp pb0207.cpp pb0994.cpp pb0230.cpp pb0438.cpp \
pb0394.cpp pb0155.cpp pb0215.cpp pb0567.cpp pb0684.cpp pb0148.cpp pb0238.cpp pb0048.cpp pb0287.cpp pb0743.cpp pb0043.cpp \
pb0189.cpp pb0034.cpp pb0560.cpp pb1254.cpp pb0304.cpp pb1020.cpp pb0133.cpp pb0079.cpp pb0114.cpp pb2390.cpp pb0071.cpp \
pb0946.cpp pb0516.cpp pb0128.cpp pb1372.cpp pb0662.cpp pb2336.cpp

EXEFILES=$(CPPFILES:.cpp=)
FLAGS=-std=c++11 -Wall

all: $(EXEFILES)

%: %.cpp
	g++ $< $(FLAGS) -o $@

clean:
	rm -f $(EXEFILES)
	