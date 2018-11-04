CC = gcc

CFLAGS = -Wall
 
OUTPUT = wbmp

IMGHANDLER = imghandler/imgFileHandler.c imghandler/dencode.c 

all:
	$(CC) $(CFLAGS) $(IMGHANDLER) main.c -o $(OUTPUT)