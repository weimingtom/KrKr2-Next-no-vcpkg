CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lEGL -lGLESv2

TARGET = gles2_fbo_example
SRC = gles2_fbo_example.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: clean
