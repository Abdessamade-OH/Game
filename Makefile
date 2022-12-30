OBJS = bin/main.o bin/game.o bin/TextureManager.o bin/GameObject.o bin/Scene.o bin/menuScene.o bin/LevelScene.o bin/MenuItem.o

CC = g++

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

OBJS_NAME = bin/game

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS_NAME)
	
bin/main.o:	src/main.cpp
	$(CC) -c src/main.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/main.o
	
bin/game.o:	src/game.cpp
	$(CC) -c src/game.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/game.o
	
bin/TextureManager.o:	src/TextureManager.cpp
	$(CC) -c src/TextureManager.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/TextureManager.o
	
bin/GameObject.o:	src/GameObject.cpp
	$(CC) -c src/GameObject.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/GameObject.o
	
bin/Scene.o:	src/Scene.cpp
	$(CC) -c src/Scene.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/Scene.o
	
bin/menuScene.o:	src/menuScene.cpp
	$(CC) -c src/menuScene.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/menuScene.o
	
bin/LevelScene.o:		src/LevelScene.cpp
	$(CC) -c src/LevelScene.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/LevelScene.o
	
bin/MenuItem.o:		src/MenuItem.cpp
	$(CC) -c src/MenuItem.cpp $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/MenuItem.o
	
	

	
debug:
	$(CC) -g $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS_NAME)	
start:
	./$(OBJS_NAME)
clean:
	rm bin/*.o
