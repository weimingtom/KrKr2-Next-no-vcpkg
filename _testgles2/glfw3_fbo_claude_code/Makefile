# sudo apt update
# sudo apt install make gcc libgl-dev libglfw3-dev

CC = gcc
CFLAGS = -std=gnu99
LDFLAGS = -lglfw /usr/lib/x86_64-linux-gnu/libGL.so -lm

TARGET = fbo_example
SRC = src/main.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)

test:
	./$(TARGET)

.PHONY: clean
