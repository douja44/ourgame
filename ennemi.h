#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#define SCREEN_H 717
#define SCREEN_W 1276
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct {
char *url;
SDL_Rect pos_img_ecran;
SDL_Rect pos_img_affiche;
SDL_Surface *img;
}image;


typedef struct Ennemi{
SDL_Rect pos;
SDL_Surface *image[3][2];
SDL_Surface *image_act;

int frame;
int dir;
}Ennemi;

/*typedef struct {
SDL_Surface *sheet;
char *url;
int x,y,w,h;
SDL_Surface *perso;
SDL_Rect pos;
double vitesse;
double acceleraction;
int etat;
int timing;
int direction;
int frame;
int vitesse_verticale;
int vitesse_horizontale;
int speedsaut;
}personne;*/

void Init_imageBACK(image * IMAGE);
//void affiche_image(SDL_Surface *screen,image IMAGE);
void InitEnnemi(Ennemi * e);
void afficherEnnemi(Ennemi e, SDL_Surface *screen);
void animerennemi(Ennemi * e);
void move(Ennemi * e);
//int collisionBB(personne p, Ennemi e);

#endif

