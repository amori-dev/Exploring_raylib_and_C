# Compiler
CC = gcc

# Raylib paths
RAYLIB_DIR = C:\raylib-5.0\raylib-5.0_win64_mingw-w64
RAYLIB_INC = $(RAYLIB_DIR)\include
RAYLIB_LIB = $(RAYLIB_DIR)\lib

# Compiler flags
CFLAGS = -Wall -I$(RAYLIB_INC)
LDFLAGS = -L$(RAYLIB_LIB) -lraylib -lopengl32 -lgdi32 -lwinmm

# Source files
SRCS = $(wildcard *.c)
# Object files
OBJS = $(SRCS:.c=.o)
# Executable name
TARGET = game.exe 

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	del $(OBJS) $(TARGET).exe

.PHONY: all clean

