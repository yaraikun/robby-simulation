CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TARGET = $(BUILD_DIR)/robby

all: $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(BUILD_DIR): 
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET)

clean:
	find $(BUILD_DIR) -type f ! -name '.gitkeep' -exec rm -f {} +

.PHONY: all run clean
