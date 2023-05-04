
src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

CXXFLAGS = -std=c++11 -I include/ -O3

zero_approx: $(obj)
	$(CXX) -g -o $@ $^ $(CXXFLAGS)
clean:
	rm -rf *o zero_approx