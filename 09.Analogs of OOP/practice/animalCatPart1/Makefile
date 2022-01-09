CFLAGS = -Wall -g `pkg-config --cflags glib-2.0 gobject-2.0`

LDFLAGS = `pkg-config --libs glib-2.0 gobject-2.0`

EXEC =  kitty

SRC =  main.c animalcat.c animalcat.c

OBJ =  main.o animalcat.o animalcat.o

$(EXEC): $(OBJ)
	 @$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	 @$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	 @rm -f $(OBJ) $(EXEC)
