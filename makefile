CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TARGET = $(BUILD_DIR)/robby

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)  # Create build directory if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all run clean
