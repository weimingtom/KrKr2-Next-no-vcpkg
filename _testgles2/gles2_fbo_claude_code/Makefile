# sudo apt update
# sudo apt install make gcc libgles2-mesa-dev

CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lEGL -lGLESv2

TARGET = gles2_fbo_example
SRC = gles2_fbo_example.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)

test:
	./$(TARGET)

.PHONY: clean
