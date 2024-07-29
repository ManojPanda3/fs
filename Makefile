CC = gcc
CFLAGS = -Wall -Wextra -pthread
TARGET = fs
SRC_DIR = src

all: $(TARGET)

$(TARGET): $(SRC_DIR)/main.c 
	$(CC) $(CFLAGS) -o $(TARGET) $<
