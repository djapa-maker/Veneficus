test1:*.c *.h
	gcc *.h *.c -lm -lSDL -lSDL_image  -lSDL_ttf -lSDL_mixer -o test1 -g
