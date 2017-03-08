CXX=g++
CXXFLAGS=-Wall -g -std=c++11
OBJS=main.o manager.o player.o team.o trainer.o
OUT=projekt1.13.out

all: $(OUT)

$(OUT): $(OBJS)
	$(CXX) $^ -o $@

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o

.PHONY: all clean
