CC = gcc
CFLAGS = -Wall -Wextra
CFLAGSAFTER = -lpcre2-8 
TARGET = fs
SRC_DIR = src

all: $(TARGET)

$(TARGET): $(SRC_DIR)/main.c 
	$(CC) $(CFLAGS) -o $(TARGET)  $< $(CFLAGSAFTER)
