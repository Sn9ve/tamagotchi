DEBUG=yes
CXX=g++
LDFLAGS=-lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR=src/
INCLUDE_DIR=include/
LIB_DIR=lib/
BIN_DIR=bin/

ifeq ($(DEBUG),yes)
	CXXFLAGS=-std=c++11 -Wall -Wextra -pedantic -g
	OBJ_DIR=obj/debug/
	EXE=$(BIN_DIR)tamagotchi-debug
else
	CXXFLAGS=-std=c++11 -march=native -O2
	OBJ_DIR=obj/release/
	EXE=$(BIN_DIR)tamagotchi-release
endif

SRC=$(wildcard $(SRC_DIR)*.cpp)
TMP_OBJ=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC))
OBJ=$(TMP_OBJ:.cpp=.o)

all: $(EXE)

$(EXE): main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -L $(LIB_DIR) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDE_DIR)%.hpp
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

.PHONY: clean mrproper

clean:
	rm -f $(OBJ_DIR)*.o

mrproper: clean
	rm -f $(EXE)
