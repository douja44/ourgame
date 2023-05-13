#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 717
#define SCREEN_W 1276
/*typedef struct
{
char *ur1;
SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
}image;*/
typedef struct
{
char *ur1m;
SDL_Surface *img_miniature;
SDL_Rect pos_map_ecran;
char *ur1p;
SDL_Surface *joueur_miniature;
SDL_Rect pos_joueur_miniature_map;
}minimap;


typedef struct {
    int start_ticks; // Le temps de départ en ms
    int paused_ticks; // Le temps écoulé en ms pendant la pause
    int paused; // Indique si le temps est en pause
    int started; // Indique si le temps a été démarré
} Timer;
typedef struct {
    Uint32 seconds ;
    Uint32 minutes;
} Times;
/*typedef struct
{
SDL_Rect posScreen;
int frame;
SDL_Surface * mat[20][20];
SDL_Surface * image_actuelle;

int direction;
double vitesse,acceleration;
int up;
int nbvie;
int score;
int etat;
}personne;*/

/*typedef struct {
    SDL_Rect rect; 
    SDL_Surface* surface; 
} Personnage;*/

/*typedef struct {
    SDL_Rect rect; 
    SDL_Surface* surface; 
} Obstacle;*/

typedef struct
{
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
}texte;

/*typedef struct {
    int x;
    int y;
    int solved;
} Enigma;*/

/*typedef struct {
    Enigma* enigmas;
    int nb_enigmas;
} MiniMap;*/


//void initialiser_imageBACK(image *IMAGE);
//void affiche_image(SDL_Surface *screen,image IMAGE);
//void liberer_image(image IMAGE);
void initmap (minimap *m);
//void iniPerso(personne *p);
//void afficherPerso(personne p, SDL_Surface * screen);
//void liberer_personne(personne p);
//void movePerso(personne *pers );
//void animerPerso(personne *p);
//void sautPerso(personne *p);
//void MAJMinimap (personne p, minimap *m,SDL_Rect camera, int redimensionnement );
void afficherminimap (minimap m , SDL_Surface *screen );
void liberer (minimap m);
void affichertemps (int * temps ,SDL_Surface *screen , char * buffer[32]);
void initialiser_textetemps(texte *txte);
void affiche_texte_temps(SDL_Surface *screen,texte txte , int temps ,char buffer[32]);
void liberer_texte_temps( texte txte);
//int collisionPP (personne p, SDL_Surface * surface );
int animerminimap (minimap * m);

//int IA (Grille g ,int joueur_Programme);




#endif

