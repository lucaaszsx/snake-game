# Project name
PROJ_NAME=snake

# Project folders
SRC=./src
BUILD=./build

# .c files
C_SRC=$(wildcard $(SRC)/*.c)

# .h files
H_SRC=$(wildcard $(SRC)/*.h)

# Object files
OBJ=$(subst .c,.o,$(subst $(SRC),$(BUILD),$(C_SRC)))

# Compiler
CC=gcc

# Compiler flags
CC_FLAGS=-c      \
		-W       \
		-Wall    \
		-ansi    \
		-pedantic \
		-std=c99

# SDL Flags
SDL_CFLAGS=$(shell pkg-config --cflags sdl3)
SDL_LIBS=$(shell pkg-config --libs sdl3)

#
# Compilation and linking
#
all: buildFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC Linker: $^'
	$(CC) $^ $(SDL_LIBS) -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

$(BUILD)/%.o: $(SRC)/%.c $(SRC)/%.h
	@ echo 'Building target using GCC Compiler: $<' 
	$(CC) $< $(CC_FLAGS) $(SDL_CFLAGS) -o $@
	@ echo ' '

$(BUILD)/main.o: $(SRC)/main.c $(H_SRC)
	@ echo 'Building main target using GCC Compiler: $<' 
	$(CC) $< $(CC_FLAGS) $(SDL_CFLAGS) -o $@
	@ echo ' '

buildFolder:
	@ mkdir $(BUILD) -p

clean:
	@ rm -rf $(BUILD)/*.o $(PROJ_NAME) ~*
	@ rmdir $(BUILD)

run: all
	./$(PROJ_NAME)

.PHONY: all buildFolder clean run