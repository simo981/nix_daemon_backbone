CFLAGS = -O3
CC = gcc
TARGET = DAEMON
LINK = 
OBJ = main.o
.PHONY = clean

$(TARGET): $(OBJ)
	$(CC) $^ $(LINK) -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(TARGET)
