#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

 
void initmap (minimap *m)
{
m->ur1m="minimapjdida.jpg";
m->img_miniature=IMG_Load(m->ur1m);
if (m->img_miniature==NULL)
{printf("unable to load background image %s \n",SDL_GetError());
}
m->pos_map_ecran.x=1000;
m->pos_map_ecran.y=600;

m->ur1p="mp.png";
m->joueur_miniature=IMG_Load(m->ur1p);
if (m->joueur_miniature==NULL)
{printf("unable to load background image %s \n",SDL_GetError());
}
m->pos_joueur_miniature_map.x=1050;
m->pos_joueur_miniature_map.y=650;
}
/*void initialiser_imageBACK(image *IMAGE)
{
IMAGE->ur1="background + obst.png";
IMAGE->img=IMG_Load(IMAGE->ur1);
if (IMAGE->img==NULL)
{printf("unable to load background image %s \n",SDL_GetError());
}
IMAGE->pos_img_ecran.x=0;
IMAGE->pos_img_ecran.y=0;
IMAGE->pos_img_affiche.x=0;
IMAGE->pos_img_affiche.y=0;
IMAGE->pos_img_affiche.h=563;
IMAGE->pos_img_affiche.w=1000;

}*/
void afficherminimap (minimap m , SDL_Surface *screen )
{
SDL_BlitSurface(m.img_miniature ,NULL ,screen , &m.pos_map_ecran);
SDL_BlitSurface(m.joueur_miniature,NULL,screen,&m.pos_joueur_miniature_map);
}
void liberer (minimap m)
{
SDL_FreeSurface(m.img_miniature);
}

/*void affiche_image(SDL_Surface *screen,image IMAGE)
{
SDL_BlitSurface(IMAGE.img , &IMAGE.pos_img_affiche ,screen , &IMAGE.pos_img_ecran);
}
void liberer_image(image IMAGE)
{
SDL_FreeSurface(IMAGE.img);
}

void iniPerso(personne *p)
{
p->frame=0;

p->mat[0][0]=IMG_Load("perso.png");
p->mat[0][1]=IMG_Load("perso.png");
p->mat[0][2]=IMG_Load("perso.png");
p->mat[0][3]=IMG_Load("perso.png");

/*p->mat[1][0]=IMG_Load("left1.png");
p->mat[1][1]=IMG_Load("left2.png");
p->mat[1][2]=IMG_Load("left3.png");
p->mat[1][3]=IMG_Load("left4.png");
p->image_actuelle=p->mat[0][0];

p->image_actuelle=p->mat[0][0];

p->posScreen.x=6;
p->posScreen.y=230;

p->vitesse=5;
p->acceleration=0;
p->up=0;
p->direction=0;
p->score=0;
p->nbvie=3;
}
void afficherPerso(perso p, SDL_Surface * screen)
{
SDL_BlitSurface(p.image_actuelle,NULL,screen,&p.posScreen);
}
void liberer_personne(perso p)
{
SDL_FreeSurface(p.image_actuelle);

}
void animerPerso(perso *p)
{

if (p->frame==3)
p->frame=0;
else
(p->frame)++;

switch (p->direction)
{
case 1:
p->image_actuelle=p->mat[1][p->frame];
break;
case 0:
p->image_actuelle=p->mat[0][p->frame];
break;
}
/*if (p->direction=0)
{printf("11");
 p->image_actuelle=p->mat[0][p->frame];}
else if (p->direction=1)
{printf("77777");
p->image_actuelle=p->mat[1][p->frame];}*/

//p->image_actuelle=p->mat[p->direction][p->frame];

//}
/*void movePerso(personne *pers)
{
	if(pers->direction==0)
	{
		pers->posScreen.x+=20*pers->acceleration;
	}
	else if(pers->direction==1)
	{
		pers->posScreen.x-=20*pers->acceleration;
	}
	if(pers->acceleration<1)
	{
		pers->acceleration+=0.1;
	}
}
/*
}*/


/*void MAJMinimap(personne p, minimap *m, SDL_Rect camera, int redimensionnement) {
    SDL_Rect posJoueurABS;
 
    posJoueurABS.x = p.posScreen.x;
    posJoueurABS.y = p.posScreen.y; //+ camera.y;

    if (m->pos_joueur_miniature_map.x > 0) {
        m->pos_joueur_miniature_map.x = (posJoueurABS.x * 20 / 100) + 825;
        m->pos_joueur_miniature_map.y = (posJoueurABS.y * 20 / 100) + 28 ;
    } 
}

	



SDL_Color GetPixel(SDL_Surface *pSurface,int x, int y)
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char*)pSurface->pixels;
pPosition+=(pSurface->pitch*y);
pPosition+=(pSurface->format->BytesPerPixel *x);
memcpy(&col,pPosition,pSurface->format->BytesPerPixel);
SDL_GetRGB(col,pSurface->format,&color.r,&color.g,&color.b);
return (color);
}*/



/*int collisionPP(perso p, SDL_Surface* Masque) {
    int collision = 0;  // initialisation de la collision à 0
    // pour chaque position du perso
    for(int i = 1; i <= 8; i++) {
        int x = p.posScreen.x, y = p.posScreen.y, w = p.posScreen.w, h = p.posScreen.h;
        // on calcule les coordonnées x et y selon la position i du personnage
        switch(i) {
            case 1: 
		x = p.posScreen.x; y = p.posScreen.y;
		break;
            case 2:
		x = p.posScreen.x + w/2; y = p.posScreen.y;
		break;
            case 3:
		x = p.posScreen.x + w; y = p.posScreen.y; 
		break;
            case 4: 
		x = p.posScreen.x; y = p.posScreen.y + h/2;
		break;
            case 5:
		x = p.posScreen.x; y = p.posScreen.y + h;
		break;
            case 6: 
		x = p.posScreen.x + w/2; y = p.posScreen.y + h;
		break;
            case 7:
		x = p.posScreen.x + w; y = p.posScreen.y + h;
		break;
            case 8:
		x = p.posScreen.x + w; y = p.posScreen.y + h/2;
		break;
        }
        // on récupère la couleur du pixel à la position (x,y) de la surface Masque
        SDL_Color pixelColor = GetPixel(Masque, x, y);
        // si la couleur n'est pas noir (ici on considère une couleur totalement transparente comme une couleur de collision)
        if (pixelColor.r == 0 && pixelColor.g == 0 && pixelColor.b == 0) {
            collision = 1;  // on a détecté une collision
            break;  // on sort de la boucle for car une seule collision suffit
        }
    }
    return collision;  
}*/

/*

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, NULL, destination, &offset);
}

 void TimerInit(Timer *timer) {
    timer->start_ticks = 0;
    timer->paused_ticks = 0;
    timer->paused = 0;
    timer->started = 0;
}

// Démarrage du timer
void TimerStart(Timer *timer) {
    timer->started = 1;
    timer->paused = 0;
    timer->start_ticks = SDL_GetTicks();
    timer->paused_ticks = 0;
}
void TimerStop(Timer *timer) {
    timer->started = 0;
    timer->paused = 0;
    timer->start_ticks = 0;
    timer->paused_ticks = 0;
}

// Pause du timer
void TimerPause(Timer *timer) {
    if (timer->started && !timer->paused) {
        timer->paused = 1;
        timer->paused_ticks = SDL_GetTicks() - timer->start_ticks;
        timer->start_ticks = 0;
    }
}
void TimerUnpause(Timer *timer) {
    if (timer->started && timer->paused) {
        timer->paused = 0;
        timer->start_ticks = SDL_GetTicks() - timer->paused_ticks;
        timer->paused_ticks = 0;
    }
}

// Temps écoulé depuis le début du jeu
int TimerGetTicks(Timer *timer) {
    int time = 0;
    if (timer->started) {
        if (timer->paused) {
            time = timer->paused_ticks;
        } else {
            time = SDL_GetTicks() - timer->start_ticks;
        }
    }
    return time;
} 


void render_time(SDL_Surface* screen, TTF_Font* font, Uint32 start_time) {
    Uint32 current_time = SDL_GetTicks();
    Uint32 elapsed_time = current_time - start_time;
    Uint32 seconds = elapsed_time / 1000;
    Uint32 minutes = seconds / 60;
    seconds -= minutes * 60;

    char time_str[10];
    sprintf(time_str, "%02u:%02u", minutes, seconds);

    SDL_Color color = { 255, 255, 255 };
    SDL_Surface* time_surface = TTF_RenderText_Solid(font, time_str, color);
    SDL_Rect time_rect = { 10, 10, 0, 0 };
    SDL_BlitSurface(time_surface, NULL, screen, &time_rect);
    SDL_FreeSurface(time_surface);
}	

void animerMinimap(MiniMap* m, SDL_Surface* screen) {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
   
    // Boucle pour animer chaque énigme
    for (int i = 0; i < m->nb_enigmas; i++) {
        // Choix aléatoire de la nouvelle couleur
        Uint8 r = rand() % 256;
        Uint8 g = rand() % 256;
        Uint8 b = rand() % 256;
       
        // Dessin du point représentant l'énigme
        SDL_Rect point = {m->enigmas[i].x, m->enigmas[i].y, 2, 2};
        SDL_FillRect(screen, &point, SDL_MapRGB(screen->format, r, g, b));
       
        
        SDL_Flip(screen);
    }
}	
*/
