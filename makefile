CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces -Wno-unused-parameter
INCLUDES = -I/home/art/projektit/libraries/raylib/src
LDFLAGS = -L/home/art/projektit/libraries/raylib/src
LDLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

WCC = emcc
WCFLAGS = -s USE_GLFW=3 -s WASM=1 -s ASYNCIFY -Os -Wall -Wno-unused-parameter
WINCLUDES = -I/home/art/projektit/libraries/raylib/src
WLDFLAGS = -s USE_GLFW=3 -s WASM=1 -s ASYNCIFY -s ALLOW_MEMORY_GROWTH=1 -s TOTAL_MEMORY=67108864
WLDLIBS = /home/art/projektit/libraries/raylib/src/libraylib.a
WSHELL = --shell-file shell.html

SRC = main.c
OBJ = $(SRC:.c=.o)
EXEC = mygame
WEXEC = index.html

all: $(EXEC)

web: $(SRC)
	$(WCC) $(WCFLAGS) $(WINCLUDES) $(SRC) -o $(WEXEC) $(WLDFLAGS) $(WLDLIBS) $(WSHELL)
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC) $(WEXEC)

