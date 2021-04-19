travail:background.o main.o fonction.o hero.o enigmealeatoire.o enigmestat.o
	gcc background.o main.o fonction.o hero.o  enigmealeatoire.o enigmestat.o -o travail -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
main.o:main.c	
	gcc -c main.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
background.o:background.c
	gcc -c background.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
fonction.o:fonction.c
	gcc -c fonction.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
hero.o:hero.c
	gcc -c hero.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
		
enigmealeatoire.o:enigmealeatoire.c
	gcc -c enigmealeatoire.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
			
enigmestat.o:enigmestat.c
	gcc -c enigmestat.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
			
