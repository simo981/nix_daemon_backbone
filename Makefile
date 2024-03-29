CFLAGS = -Ofast
CC = clang
TARGET = DAEMON
LINK = 
OBJ = main.o
.PHONY = clean

$(TARGET): $(OBJ)
	$(CC) $^ $(LINK) -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(TARGET) 2>/dev/null
