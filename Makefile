CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic
VALGRIND = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all

SRC = main.cpp
TEST = test.cpp
HEADERS = MyContainer.hpp

TARGET_MAIN = main
TARGET_TEST = test

all: Main test

Main: $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_MAIN) $(SRC)

test: $(TEST) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TEST) $(TEST)

valgrind: Main test
	$(VALGRIND) ./$(TARGET_MAIN)
	$(VALGRIND) ./$(TARGET_TEST)

clean:
	rm -f $(TARGET_MAIN) $(TARGET_TEST)
