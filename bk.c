#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "bk.h"


void initBachground(BACKGROUND *b){
    b->bk1.img=IMG_Load("backjdid.jpg");
    b->bk1.pos1.x=0;
    b->bk1.pos1.y=0;

    b->bk1.pos2.x=0;
    b->bk1.pos2.y=0;
    b->bk1.pos2.w=b->w;
    b->bk1.pos2.h=b->h;

    b->btn.img=IMG_Load("best_score.png");
    b->btn.pos1.x=1200-290;
    b->btn.pos1.y=0;

    
    b->anim.img=IMG_Load("birds.png");

    b->anim.pos1.x=100;
    b->anim.pos1.y=50;


    b->anim.pos2.x=0;
    b->anim.pos2.y=0;
    b->anim.pos2.w=b->anim.img->w/9;
    b->anim.pos2.h=b->anim.img->h;
    b->count=0;

    
    b->anim2.img=IMG_Load("etoiles.png");

    b->anim2.pos1.x=0;
    b->anim2.pos1.y=0;


    b->anim2.pos2.x=0;
    b->anim2.pos2.y=0;
    b->anim2.pos2.w=b->anim2.img->w/5;
    b->anim2.pos2.h=b->anim2.img->h;



    b->count=0;
    b->count2=0;

    b->score.font=TTF_OpenFont("28 Days Later.ttf",60);
    b->score.postxt.x=0;
    b->score.postxt.y=0;
    b->score.col.r=255;
    b->score.col.g=255;
    b->score.col.b=255;

    b->textBestScore[0].font=TTF_OpenFont("28 Days Later.ttf",60);
    b->textBestScore[0].postxt.x=500;
    b->textBestScore[0].postxt.y=100;
    b->textBestScore[0].col.r=255;
    b->textBestScore[0].col.g=255;
    b->textBestScore[0].col.b=255;

    b->textBestScore[1].font=TTF_OpenFont("28 Days Later.ttf",60);
    b->textBestScore[1].postxt.x=b->textBestScore[0].postxt.x;
    b->textBestScore[1].postxt.y=b->textBestScore[0].postxt.y+100;
    b->textBestScore[1].col.r=255;
    b->textBestScore[1].col.g=255;
    b->textBestScore[1].col.b=255;

    b->textBestScore[2].font=TTF_OpenFont("28 Days Later.ttf",60);
    b->textBestScore[2].postxt.x=b->textBestScore[0].postxt.x;
    b->textBestScore[2].postxt.y=b->textBestScore[1].postxt.y+100;
    b->textBestScore[2].col.r=255;
    b->textBestScore[2].col.g=255;
    b->textBestScore[2].col.b=255;

    b->bestScoreRect.x=b->textBestScore[0].postxt.x-20;
    b->bestScoreRect.y=b->textBestScore[0].postxt.y-20;
    b->bestScoreRect.w=500;
    b->bestScoreRect.h=400;
}


void initBachground2(BACKGROUND *b){
    b->bk1.img=IMG_Load("backjdid.jpg");
    b->bk1.pos1.x=0;
    b->bk1.pos1.y=b->h;

    b->bk1.pos2.x=0;
    b->bk1.pos2.y=0;
    b->bk1.pos2.w=b->w;
    b->bk1.pos2.h=b->h;

    b->btn.img=IMG_Load("best_score.png");
    b->btn.pos1.x=1200-290;
    b->btn.pos1.y=b->h;


    b->anim.img=IMG_Load("birds.png");

    b->anim.pos1.x=100;
    b->anim.pos1.y=50+b->h;


    b->anim.pos2.x=0;
    b->anim.pos2.y=0;
    b->anim.pos2.w=b->anim.img->w/9;
    b->anim.pos2.h=b->anim.img->h;
    b->count=0;

    b->anim2.img=IMG_Load("etoiles.png");

    b->anim2.pos1.x=100;
    b->anim2.pos1.y=b->h;


    b->anim2.pos2.x=0;
    b->anim2.pos2.y=0;
    b->anim2.pos2.w=b->anim2.img->w/5;
    b->anim2.pos2.h=b->anim2.img->h;

    b->count=0;
    b->count2=0;

    b->score.font=TTF_OpenFont("28 Days Later.ttf",60);
    b->score.postxt.x=0;
    b->score.postxt.y=b->h;
    b->score.col.r=255;
    b->score.col.g=255;
    b->score.col.b=255;
}

void afficherBachground(BACKGROUND b,SDL_Surface* screen){
    SDL_BlitSurface(b.bk1.img,&b.bk1.pos2,screen,&b.bk1.pos1);
    SDL_BlitSurface(b.anim.img,&b.anim.pos2,screen,&b.anim.pos1);
    SDL_BlitSurface(b.anim2.img,&b.anim2.pos2,screen,&b.anim2.pos1);
    SDL_BlitSurface(b.score.windtxt,NULL,screen,&b.score.postxt);
}


void scrolling(BACKGROUND* b,int derection,int acc){
    switch (derection)
    {
    case 1:
        b->bk1.pos2.y-=acc;
        break;
    case 2:
        b->bk1.pos2.x-=acc;
        break;
    case 3:
        b->bk1.pos2.y+=acc;
        break;
    case 4:
        b->bk1.pos2.x+=acc;
        break;
    }
    if(b->bk1.pos2.y>=b->bk1.img->h-b->bk1.pos2.h)
        b->bk1.pos2.y=b->bk1.img->h-b->bk1.pos2.h;
    if(b->bk1.pos2.y<=0)
        b->bk1.pos2.y=0;
    if(b->bk1.pos2.x>=b->bk1.img->w-b->bk1.pos2.w)
        b->bk1.pos2.x=b->bk1.img->w-b->bk1.pos2.w;
    if(b->bk1.pos2.x<=0)
        b->bk1.pos2.x=0;
    //1-->> top
    //2-->>rigth
    //3-->>bottom
    //4-->>left
}

void saveScore(scoreInfo s, char *fileName){
    FILE* myFile=NULL;
    myFile=fopen(fileName,"a+");
    if(myFile!=NULL){
        fprintf(myFile,"%d %d %s\n",s.score,s.temps,s.playerName);
    }
    fclose(myFile);
}


void bestScore(char * fileName, scoreInfo best_Score[]){
    FILE* myFile=NULL;
    myFile=fopen(fileName,"a+");
    scoreInfo *tab;
    tab=(scoreInfo*)malloc(1*sizeof(scoreInfo));
    int tabLenght=0;
    if(myFile!=NULL){
        while(!feof(myFile)){
            fscanf(myFile,"%d %d %s\n",&tab[tabLenght].score,&tab[tabLenght].temps,tab[tabLenght].playerName);
            tabLenght++;
            tab=realloc(tab,(tabLenght+1)*sizeof(scoreInfo));
        }
    }

    int skip;
    for(int i=0;i<3;i++){
        best_Score[i]=tab[0];
        skip=0;
        for(int j=0;j<tabLenght;j++){
            if(tab[j].score>best_Score[i].score){
                best_Score[i]=tab[j];
                skip=j;
            }
            else if(tab[j].score==best_Score[i].score&&tab[j].temps<best_Score[i].temps){
                best_Score[i]=tab[j];
                skip=j;
            }
        }
        for(int k=skip;k<tabLenght;k++)
                tab[k]=tab[k+1];
        tabLenght--;
    }
    free(tab);
    fclose(myFile);
}



void animerbackground(BACKGROUND* b){
    b->count++;
    if(b->count>=10){
        b->anim.pos1.x+=10;
        b->anim.pos2.x+=b->anim.pos2.w;
        if(b->anim.pos2.x>=b->anim.img->w-b->anim.pos2.x)
            b->anim.pos2.x=0;
        if(b->anim.pos1.x>=1000)
            b->anim.pos1.x=0;
        b->count=0;
    }
}


void animerbackground2(BACKGROUND* b){
    b->count2++;
    if(b->count2>=10){
        b->anim2.pos2.x+=b->anim2.pos2.w;
        if(b->anim.pos2.x>=b->anim2.img->w-b->anim2.pos2.x)
            b->anim2.pos2.x=0;
        b->count2=0;
    }
}




