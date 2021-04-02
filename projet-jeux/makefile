prog:jeux.o main.o
	gcc jeux.o main.o -o prog -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
main.o:main.c	
	gcc -c main.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
fichier.o:jeux.c
	gcc -c jeux.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
