#ifndef UNTITLED_BK_H
#define UNTITLED_BK_H
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
typedef struct{
SDL_Rect pos1,pos2;
SDL_Surface *img;
}IMAGE;

typedef struct{
SDL_Rect postxt;
TTF_Font *font;
SDL_Surface *windtxt;
SDL_Color col;
}TEXT;

typedef struct 
{
  int score;
  int temps;
  char playerName[20];
}scoreInfo;

typedef struct{
  IMAGE bk1;
  IMAGE btn;
  IMAGE anim,anim2;
  int count,count2;
  TEXT score;
  TEXT textBestScore[3];
  SDL_Rect bestScoreRect;
  Uint32 bestScoreColor;
  int w,h;
}BACKGROUND;

void initBachground(BACKGROUND *b);
void initBachground2(BACKGROUND *b);
void afficherBachground(BACKGROUND b,SDL_Surface* screen);
void scrolling(BACKGROUND* b,int derection,int acc);
void animerbackground(BACKGROUND* b);
void animerbackground2(BACKGROUND* b);


void saveScore(scoreInfo s, char *fileName);
void bestScore(char * fileName, scoreInfo best_Score[]);

#endif
