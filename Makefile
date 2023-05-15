#-------------------------------------------------------------------------------
# options for code generation
#-------------------------------------------------------------------------------

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TARGET = wordsearch

.PHONY: all clean

#-------------------------------------------------------------------------------
# make commands
#-------------------------------------------------------------------------------

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#-------------------------------------------------------------------------------
# clean commands
#-------------------------------------------------------------------------------

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
