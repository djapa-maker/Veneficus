#include "entete.h"
int main()
{
test ();
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO)!=0)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }

    SDL_Event event;

   SDL_Surface *screen;

SDL_Surface *image;
SDL_Surface *imageM;
SDL_Rect posimage;
posimage.x=0;
posimage.y=0;
image=IMG_Load("lbo3.jpg");   
imageM=IMG_Load("masque.jpg"); 
Personne p;
p.posperso.x=0;
p.posperso.y=600;
p.posperso.h=267;
p.posperso.w=200;
p.perso=IMG_Load("8.png");
    screen=SDL_SetVideoMode(1920,1360,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(screen==NULL)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }
    
    int gamerunning=1;
    int frame=0;

   
   
    const int FPS=20;

int temps;
temps=0;

    Uint32 start;
    
   minimap m;
initmap(&m);
SDL_EnableKeyRepeat(1,1);
    while(gamerunning)
    {
        SDL_BlitSurface(imageM,NULL,screen,&posimage);
        SDL_BlitSurface(image,NULL,screen,&posimage);
        SDL_BlitSurface(p.perso,NULL,screen,&p.posperso);
	afficherminimap (m,  screen);
        start=SDL_GetTicks();
	affichertemps ( temps,screen);
        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {

            case SDL_QUIT:
                gamerunning=0;
                break;
case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    gamerunning=0;
                    break;
                case SDLK_RIGHT:
                    p.direction=1;
                    if(collisionPP(p,imageM)==0)
		    {
                    p.posperso.x+=11;
                    if(m.pospoint.x<=m.posminimap.x+1240)
                    m.pospoint.x++;
                    }
                    break;
                case SDLK_LEFT:
		p.direction=2;
		if(collisionPP(p,imageM)==0)
		{
                     p.posperso.x-=11;
		if(m.pospoint.x>=m.posminimap.x)
		m.pospoint.x--;
                }
                    break;

                }
                break;
           
            }
        }
       


        SDL_Flip(screen);
       
        
        frame++;
if(frame==20)
{
temps++;
frame=0;
}
        if(1000/FPS>SDL_GetTicks()-start)
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
    }
}


