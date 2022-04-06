CC=cc
ELF=longpal

clean:
	rm ./$(ELF)

build:
	$(CC) -g -o $(ELF) $(ELF).c

debug: build
	gdb $(ELF)

test: build
	./$(ELF) < tests
