#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"
#include "ennemi.h"
#include "header.h"
#include "bk.h"
int main(int argc, char *argv[])
{
int n;
do
    {
	printf("1 joueur | 2 joueurs\n");
	scanf("%d",&n);
    }
    while((n<1)||(n>2));

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    SDL_Surface *screen;
    screen = SDL_SetVideoMode(1200, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    int done = 1;
    SDL_Event event;
     int x,y;

    BACKGROUND b,b2;
    b.w=1200;
    b.h=720;
    initBachground(&b);
    b.bestScoreColor = SDL_MapRGB(screen->format, 0, 0, 0);

    SDL_Rect rect1,rect2;
    /*rect1.x = 100;
    rect1.w = 50;
    rect1.h = 50;
   rect1.y = (b.h/2-rect1.h/2);*/
  

    
    

    Uint32 color = SDL_MapRGB(screen->format, 255, 255, 255);

    Mix_Music *mus;
    mus = Mix_LoadMUS("backgroundmusic.mp3");
    Mix_PlayMusic(mus, -1);

    scoreInfo s[3], l;
   
    int sc = 1;
    char scc[100];
    int show = 0;
    char score[100];
    int turnOnsplitScreen=0;
    
   Uint32 dt,t_prev;
personne p,p2;

    image IMAGE;
    int posdebut=p.pos.y;
   // int posdebut=p2.pos2.y;
    

    initperso(&p);
Ennemi e;
InitEnnemi(&e);
minimap m;
initmap(&m);
 while (done)
    {
        SDL_PollEvent(&event);
        sc = rect1.x;
        sprintf(scc, "%d", sc);
        b.score.windtxt = TTF_RenderText_Blended(b.score.font, scc, b.score.col);
        afficherBachground(b, screen);
        afficher_perso(&p,screen);
        afficherminimap (m,screen);
        afficherEnnemi(e,screen);
        SDL_FillRect(screen, &rect1, color);
        SDL_BlitSurface(b.btn.img, NULL, screen, &b.btn.pos1);
        animerbackground(&b);
        animerbackground2(&b);
	/*if(n==2)
	  initperso(&p2);*/
	animerennemi(&e);
        move(&e);
        SDL_Delay(40);
        switch (event.type)
        {
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                rect1.x += 4;
                // 625=1200/2-50/2
               if (p.x >= (b.w/2-p.w/2))
                {
                    p.x = (b.w/2-p.w/2);
                    scrolling(&b, 4, 4);
                }
             p.direc=1;
	     moveperso(&p, dt);
	     animerpersonne(&p);

            }
            else if (event.key.keysym.sym == SDLK_LEFT)
            {
                rect1.x -= 4;
                if (p.x <= (b.w/2-p.w/2))
                {
                    p.x = (b.w/2-p.w/2);
                    scrolling(&b, 2, 4);
                }
	     p.direc=0;
	     moveperso(&p, dt);
             animerpersonne(&p);
	    
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                rect1.y -= 4;
                if (rect1.y <= (b.h/2-rect1.h/2))
                {
                    rect1.y = (b.h/2-rect1.h/2);
                    scrolling(&b, 1, 4);
                }
            /* p.etat=1;
             saut(&p, dt,posdebut);*/
            }
            else if (event.key.keysym.sym == SDLK_DOWN)
            {
                rect1.y += 4;
                if (p.y >= (b.h/2-p.h/2))
                {
                    p.y = (b.h/2-p.h/2);
                    scrolling(&b, 3, 4);
                }

            }
            if(event.key.keysym.sym == SDLK_p){
                b.w=1200;
                b.h=720/2;
                turnOnsplitScreen=1;
                b2.w=1200;
                b2.h=720/2;
                initBachground2(&b2);
		/*initperso(&p2);
		afficher_perso(&p2,screen);*/
                // b2.bestScoreColor = SDL_MapRGB(screen->format, 0, 0, 0);
              rect2.x = 100;
                rect2.w = 50;

                rect2.h = 50;
                rect2.y = b2.h+(b2.h/2-rect2.h/2);
            }
            if(event.key.keysym.sym == SDLK_n){
                b.h=720;
                turnOnsplitScreen=0;
            }
            if (event.key.keysym.sym == SDLK_d)
            {
                rect2.x += 4;
                // 625=1200/2-50/2
               if (rect2.x >= (b2.w/2-rect2.w/2))
                {
                    rect2.x = (b2.w/2-rect2.w/2);
                    scrolling(&b2, 4, 4);
                }
             /* p2.direc=1;
              moveperso(&p2,dt);
              animerpersonne(&p2);*/
            }
            else if (event.key.keysym.sym == SDLK_q)
            {
                rect2.x -= 4;
                if (rect2.x <= (b2.w/2-rect2.w/2))
                {
                    rect2.x = (b2.w/2-rect2.w/2);
                    scrolling(&b2, 2, 4);
                }
		/*p2.direc=0;
	     moveperso(&p2, dt);
              animerpersonne(&p2);*/

            }
            else if (event.key.keysym.sym == SDLK_z)
            {
                rect2.y -= 4;
                if (rect2.y <= (b2.h+b.h/2-rect2.h/2))
                {
                    rect2.y = b2.h+(b.h/2-rect2.h/2);
                    scrolling(&b2, 1, 4);
                }
            }
            else if (event.key.keysym.sym == SDLK_s)
            {
                rect2.y += 4;
                if (rect2.y >= (b2.h+b.h/2-rect2.h/2))
                {
                    rect2.y = b2.h+(b.h/2-rect2.h/2);
                    scrolling(&b2, 3, 4);
                }
            }
	 else if (event.key.keysym.sym == SDLK_SPACE)
            {
               p.etat=1;
	       saut(&p,dt,posdebut);
            }
	else if( event.key.keysym.sym ==SDLK_ESCAPE)
	  {
		done=0;
		
	  }

            break;
        case SDL_MOUSEBUTTONDOWN:
             x = event.motion.x;
             y = event.motion.y;
            if (x > b.btn.pos1.x && x < b.btn.pos1.x + b.btn.img->w && y > b.btn.pos1.y && y < b.btn.pos1.y + b.btn.img->h)
            {
                show = 1;
            }
            break;
        }
 if (show == 1)
        {
            bestScore("test.txt", s);
            SDL_FillRect(screen, &b.bestScoreRect, b.bestScoreColor);
            for (int i = 0; i < 3; i++)
            {
                sprintf(score, "%s %d %d", s[i].playerName, s[i].temps, s[i].score);
                b.textBestScore[i].windtxt = TTF_RenderText_Blended(b.textBestScore[i].font, score, b.textBestScore[i].col);
                SDL_BlitSurface(b.textBestScore[i].windtxt, NULL, screen, &b.textBestScore[i].postxt);
            }
        }

        if(turnOnsplitScreen==1){
            sc = rect2.x;
            sprintf(scc, "%d", sc);
            b2.score.windtxt = TTF_RenderText_Blended(b2.score.font, scc, b2.score.col);
            afficherBachground(b2, screen);
            SDL_FillRect(screen, &rect2, color);
            animerbackground(&b2);
            animerbackground2(&b2);
        }
        
        if (event.type == SDL_QUIT)
            done = 0;
        SDL_Flip(screen);
    }
    animerpersonne(&p);
   
    liberer_perso(p);
    
   
    SDL_Quit();
    return 0;
}

