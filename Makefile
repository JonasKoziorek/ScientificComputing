CXX = g++
CXXFLAGS = -I./include -Wall -Wextra -Werror -fsanitize=address

SRC_DIR = src
TEST_DIR = test
INCLUDE_DIR = include

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: main test

main: $(OBJ_FILES) main.o
	$(CXX) $(CXXFLAGS) -o main $(OBJ_FILES) main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test: $(OBJ_FILES) $(TEST_FILES:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o test_vector $(OBJ_FILES) $(TEST_FILES:.cpp=.o)
	./test_vector

clean:
	rm -f $(SRC_DIR)/*.o main test_vector main.o $(TEST_DIR)/*.o