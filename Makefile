CXX = g++
CXXFLAGS = -I./include -Wall -Wextra -Werror -fsanitize=address
SRC_DIR = src
TEST_DIR = test
INCLUDE_DIR = include
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)

all: main test

main: $(OBJ_FILES) main.o
	$(CXX) $(CXXFLAGS) -o main $(OBJ_FILES) main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test: all_tests

all_tests: $(OBJ_FILES) $(TEST_OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o all_tests $(OBJ_FILES) $(TEST_OBJ_FILES)
	./all_tests

$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o main all_tests main.o $(TEST_DIR)/*.o