#ifndef PERSO_H_INCLUDED 
#define PERSO_H_INCLUDED 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 717
#define SCREEN_W 1276
#define sommet 50
#define gravity 2
#define maxvitesse 30
#define direction_droite 1
#define direction_gauche 2
#include "ennemi.h"
/*typedef struct {
char *url;
SDL_Rect pos_img_ecran;
SDL_Rect pos_img_affiche;
SDL_Surface *img;
}image;*/

typedef struct {
SDL_Surface *sheet;
int x,y,w,h;
char *url;
SDL_Surface *perso;
SDL_Rect pos;
double acceleration;
double vitesse;
int direc;
int etat;
int frame;
int speedsaut; 
int vitesse_y;
int vitesse_x;
int score;
int vie;
}personne;
void animerpersonne(personne *p);
//void initialiser_background(image *imge);
void initialiseraudio(Mix_Music *music);
void initperso(personne *p);
//void afficher_background(SDL_Surface *screen, image imge);
void afficher_perso(personne *p,SDL_Surface *screen);
void moveperso(personne *p,Uint32 dt);
void animerpersonne(personne *p);
void saut(personne *p,int dt ,int posdebut);
void liberer_image(image imge);
void liberer_perso(personne p);
void liberer_music(Mix_Music *music);
#endif
