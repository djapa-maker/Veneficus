prog:fonction.o main.o
	gcc fonction.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image
fonction.o:fonction.c
	gcc -c fonction.c -g
