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

test: test_vector test_matrix

test_vector: $(OBJ_FILES) test/test_vector.o
	$(CXX) $(CXXFLAGS) -o test_vector $(OBJ_FILES) test/test_vector.o
	./test_vector

test/test_vector.o: test/test_vector.cpp
	$(CXX) $(CXXFLAGS) -c test/test_vector.cpp -o test/test_vector.o

test_matrix: $(OBJ_FILES) test/test_matrix.o
	$(CXX) $(CXXFLAGS) -o test_matrix $(OBJ_FILES) test/test_matrix.o
	./test_matrix

test/test_matrix.o: test/test_matrix.cpp
	$(CXX) $(CXXFLAGS) -c test/test_matrix.cpp -o test/test_matrix.o

clean:
	rm -f $(SRC_DIR)/*.o main test_vector main.o $(TEST_DIR)/*.o