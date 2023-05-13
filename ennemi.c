#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 717
#define SCREEN_W 1276
#include "ennemi.h"
SDL_Surface *screen;
Ennemi e;
/*if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO| SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n",SDL_GetError());
return -1;
}*/

//screen=SDL_SetVideoMode(SCREEN_W , SCREEN_H ,32 , SDL_SWSURFACE |SDL_DOUBLEBUF);

void Init_imageBACK(image * IMAGE)
{
IMAGE->url="im.png";
IMAGE->img=IMG_Load(IMAGE->url);
if (IMAGE->img==NULL)
{printf("unable to load background image %s \n",SDL_GetError());
}
IMAGE->pos_img_ecran.x=0;
IMAGE->pos_img_ecran.y=0;
IMAGE->pos_img_affiche.x=0;
IMAGE->pos_img_affiche.y=0;
IMAGE->pos_img_affiche.h=1200;
IMAGE->pos_img_affiche.w=1600;

}


void affiche_image(SDL_Surface *screen,image IMAGE)
{

SDL_BlitSurface(IMAGE.img , &IMAGE.pos_img_affiche ,screen , &IMAGE.pos_img_ecran);
}
void InitEnnemi(Ennemi *e){
e->image[0][0]=IMG_Load("en444.png");
e->image[0][1]=IMG_Load("en555.png");
e->image[0][2]=IMG_Load("en666.png");


e->image[1][0]=IMG_Load("en222.png");
e->image[1][1]=IMG_Load("en333.png");
e->image[1][2]=IMG_Load("en111.png");
e->image_act=e->image[0][0];
e->pos.x=50;
e->pos.y=300;
e->frame=0;
e->dir=0;

}
void afficherEnnemi(Ennemi e, SDL_Surface *screen){
	SDL_BlitSurface(e.image_act,NULL,screen,&e.pos); 
}


void animerennemi(Ennemi *e){
if (e->frame==3)
e->frame=0;
else
(e->frame)++;

switch (e->dir)
{
case 0:
e->image_act=e->image[0][e->frame];
break;
case 1:
e->image_act=e->image[1][e->frame];
break;

}
}

void move (Ennemi *e){

int posMAX=900;
int posMIN=100;
int speed=1;
if(e->dir==0){
    if(e->pos.x>posMIN){ 
      e->pos.x-=speed;}
 else{
     e->dir=1;
}
}else{
   if(e->pos.x<posMAX){
     e->pos.x+=speed;
}else{
    e->dir=0;
}}}




/*int collision(personne*p, ennemi*e)
{
   
    if (((p->posScreen.x + p->posScreen.w) < e->pos.x) || (p->posScreen.x > (e->pos.x + e->pos.w)) || ((p->posScreen.y + p->posScreen.h) < e->pos.y) || (p->posScreen.y > (e->pos.y + e->pos.h)))
    {
        return 0;
    }
    else
    {
        return 1;
    }}*/
/*void deplacerIA(Ennemi *E, SDL_Rect posperso)
{
    if (((E->pos.x - posperso.x) < 200) && ((E->pos.x - posperso.x) > 80))
    {
        E->direction = 1;
        E->pos.x -= 20;
    }
    else if (((E->pos.x - posperso.x) < -80) && ((E->pos.x - posperso.x) > -200))
    {
        E->direction = 0;
        E->pos.x += 20;
    }
    else if (((E->pos.x - posperso.x) <= 80) && ((E->pos.x - posperso.x) >= 0))
    {
        E->direction = 3;
    }
    else if (((E->pos.x - posperso.x) <= 0) && ((E->pos.x - posperso.x) >= -80))
    {
        E->direction = 2;
    }
}*/

















































