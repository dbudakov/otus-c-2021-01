LDFLAGS = `pkg-config --cflags --libs glib-2.0`

all: GSList GArray GQueue GHashTable GTree

GSList:
	@gcc $(LDFLAGS) $@.c -o $@

GArray:
	@gcc $(LDFLAGS) $@.c -o $@

GQueue:
	@gcc $(LDFLAGS) $@.c -o $@

GHashTable:
	@gcc $(LDFLAGS) $@.c -o $@

GTree:
	@gcc $(LDFLAGS) $@.c -o $@

clean:
	@rm -f GSList GArray GQueue GHashTable GTree
