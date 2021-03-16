prog:fichier.o main.o
	gcc fichier.o main.o -o prog -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
main.o:main.c	
	gcc -c main.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
fichier.o:fichier.c
	gcc -c fichier.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
