EXENAME = run.sh
OBJS = gen code brute
TEMP = in out1 out2
GEN = gen

CXX = g++

all: $(EXENAME) $(OBJS)
	bash $(EXENAME)

gen: $(GEN).cpp
	$(CXX) gen.cpp -o $(GEN)

brute: brute.cpp
	$(CXX) brute.cpp -o brute

code: code.cpp
	$(CXX) code.cpp -o code

clean:
	-rm -f $(OBJS) $(TEMP)