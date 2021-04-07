travail:background.o main.o fonction.o
	gcc background.o main.o fonction.o -o travail -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
main.o:main.c	
	gcc -c main.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
background.o:background.c
	gcc -c background.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
fonction.o:fonction.c
	gcc -c fonction.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
