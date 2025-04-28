CXX = g++
CXXFLAGS = -std=c++11 -Wall
INCLUDES = -Iinclude
SRC = src/main.cpp src/Trie.cpp
TARGET = SmartMakeupSearch

all:
	$(CXX) $(CXXFLAGS) $(SRC) $(INCLUDES) -o $(TARGET)
