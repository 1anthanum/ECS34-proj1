CC = gcc
CXX = g++

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TEST_SRC_DIR = ./testsrc

CXXFLAGS = -std=c++17 -I$(INC_DIR)
LDFLAGS = -lgtest -lgtest_main -lpthread


all: directories runtests

runtests: $(BIN_DIR)/teststrutils
	$(BIN_DIR)/teststrutils

$(BIN_DIR)/teststrutils: $(OBJ_DIR)/StringUtils.o $(OBJ_DIR)/StringUtilsTests.o
	$(CXX) -o $(BIN_DIR)/teststrutils $(CXXFLAGS) $(OBJ_DIR)/StringUtils.o $(OBJ_DIR)/StringUtilsTests.o -L/opt/homebrew/Cellar/googletest/1.14.0/lib $(LDFLAGS)

$(OBJ_DIR)/StringUtils.o: $(SRC_DIR)/StringUtils.cpp $(INC_DIR)/StringUtils.h
	$(CXX) -o $(OBJ_DIR)/StringUtils.o -c $(CXXFLAGS) $(SRC_DIR)/StringUtils.cpp

$(OBJ_DIR)/StringUtilsTests.o: $(TEST_SRC_DIR)/StringUtilsTests.cpp $(INC_DIR)/StringUtils.h
	$(CXX) -o $(OBJ_DIR)/StringUtilsTests.o -c -std=c++17 -I$(INC_DIR) -I/opt/homebrew/Cellar/googletest/1.14.0/include $(TEST_SRC_DIR)/StringUtilsTests.cpp

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)

directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)