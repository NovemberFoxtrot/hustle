SRC = $(wildcard src/*.c)
SRC += $(wildcard imports/*.c)
OBJ = $(SRC:.c=.o)
PREFIX=/usr/local
BIN=hustle

hustler: $(SRC)
	$(CC) $^ -g -std=c99 -lm -I imports -o $@

install: $(BIN)
	install $(BIN) $(PREFIX)/bin

uninstall:
	rm $(PREFIX)/bin/$(BIN)

clean:
	rm -f $(BIN) $(OBJ)

.PHONY: clean install uninstall
