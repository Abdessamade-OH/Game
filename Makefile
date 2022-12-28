OBJS = src/main.cpp src/game.cpp src/TextureManager.cpp src/GameObject.cpp src/menuScene.cpp

CC = g++

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

OBJS_NAME = bin/game

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS_NAME)
debug:
	$(CC) -g $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS_NAME)	
start:
	./$(OBJS_NAME)
