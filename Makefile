# MAKEFILE

CC=g++
CPPFLAGS=-std=c++11 -Wall
CFLAGS=

HEADERS=$(INCLUDE_DIR)block.h $(INCLUDE_DIR)wall.h $(INCLUDE_DIR)databank.h
OBJECTS=$(OBJ_DIR)block.o $(OBJ_DIR)wall.o $(OBJ_DIR)databank.o

#$(INCLUDE_DIR)animBlock.h
#$(OBJ_DIR)animBlock.o

INCLUDE_DIR=include/
LINK=-LF:\Projects\C++\C++_LIBS\SDL2-2.0.5\x86_64-w64-mingw32\lib -LF:\Projects\C++\C++_LIBS\ncursesw-64\lib
BIN_DIR=bin/$(BUILD_TARGET)/
OBJ_DIR=obj/$(BUILD_TARGET)/

LINK_OPTIONS=-lmingw32 -lncursesw -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -lopengl32

INCLUDE=-I$(INCLUDE_DIR) -IF:\Projects\C++\C++_LIBS\SDL2-2.0.5\x86_64-w64-mingw32\include -IF:\Projects\C++\C++_LIBS\ncursesw-64\include
BUILD_TARGET=Debug

BIN_DIR=bin/$(BUILD_TARGET)/
OBJ_DIR=obj/$(BUILD_TARGET)/

TARGET=main
EXE=GAME

EXECUTABLE_SUFFIX=.exe

all: $(BIN_DIR)$(EXE)$(EXECUTABLE_SUFFIX)

$(OBJ_DIR)%.o: src/%.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $(INCLUDE) $< -o $@

$(OBJ_DIR)main.o: main.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $(INCLUDE) main.cpp -o $(OBJ_DIR)main.o

$(BIN_DIR)$(EXE)$(EXECUTABLE_SUFFIX): $(OBJ_DIR)main.o $(OBJECTS) $(HEADERS)
	$(CC) $(LINK) -o $(BIN_DIR)$(EXE)$(EXECUTABLE_SUFFIX) $(OBJ_DIR)*.o $(LINK_OPTIONS)

clean:
	rm -f $(OBJ_DIR)*.o $(OBJ_DIR)main.o $(BIN_DIR)$(EXE)$(EXECUTABLE_SUFFIX)

rebuild: clean all


