CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g  -pthread
SRCS = circ_list.h test.cpp
OBJS = test.o
TARGET = test

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lgtest -lgtest_main
test.o: test.cpp circ_list.h
	$(CXX) $(CXXFLAGS) -c test.cpp
clean:
	rm -f $(OBJS) $(TARGET)
