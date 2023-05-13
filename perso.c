#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"
#include "ennemi.h"
/*void initialiser_background(image *imge){
   imge->url="im.png";
   imge->img=IMG_Load(imge->url);
   if (imge->img==NULL)
	{printf("unable to load playback2 image %s \n",SDL_GetError());
	return ;
	}
	imge->pos_img_ecran.x=0;
	imge->pos_img_ecran.y=0;
	imge->pos_img_affiche.x=0;
	imge->pos_img_affiche.y=0;
	imge->pos_img_affiche.h=SCREEN_H;
	imge->pos_img_affiche.w=SCREEN_W;

}
void initialiseraudio(Mix_Music *music){
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
printf("%s",SDL_GetError());}
music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
}*/

void initperso(personne *p){
p->url="yejridroite.png";
p->perso=IMG_Load(p->url);
if (p->perso==NULL)
	{printf("unable to load yejridroite image %s \n",SDL_GetError());
	return ;
	}

p->pos.x=50;
p->pos.y=370;
p->vitesse=5;
p->acceleration=0;
p->etat=0 ;
p->vitesse_x=1;
p->speedsaut=2;
p->vitesse_y=p->speedsaut;
p->frame=0;
}
void afficher_background(SDL_Surface *screen, image imge){
SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_perso(personne *p,SDL_Surface *screen){
SDL_Rect precedent,suivant;
precedent.x=p->pos.x;
precedent.y=p->pos.y;
precedent.w=p->pos.w;
precedent.h=p->pos.h;

suivant.x=p->frame*200;
suivant.y=0;
suivant.w=200;
suivant.h=200;
SDL_BlitSurface(p->sheet,&suivant,screen,&precedent);
}
void moveperso(personne *p,Uint32 dt) 
{
double dx =0.5* p->acceleration * dt * dt + p->vitesse * dt;
    if(p->direc==1)
    {
    {
    p->pos.x+=dx;
    }
    if (p->etat!=direction_droite)
     {

	p->etat=direction_droite;
	p->sheet=IMG_Load("yejridroite.png");
      }
      }
      else if (p->direc==0)
      {
      { 
      p->pos.x -=dx;
      }
      if (p->etat!=direction_gauche)
      {
      p->etat=direction_gauche;
      p->sheet=IMG_Load("yejrigauche.png");
      }
      }
      if (p->etat==0)
      {
      if ((p->etat=0)&&(p->direc==1))
	{
	  p->etat=direction_droite;
	  p->sheet=IMG_Load("yemchidroite.png");
	}
	else {
		p->etat=direction_gauche;
	  p->sheet=IMG_Load("yemchigauche.png");
		}
	}
 	/*p->pos.x+=gravity;*/
	/*if(p->pos.y=maxvitesse)
	{ 
	   p->pos.y=maxvitesse;
	}
 	/*if (p->pos.x>=SCREEN_W-200){
	   p->pos.x=SCREEN_W-200;
	
	}
	if (p->pos.y>=SCREEN_H-200){
	   p->pos.y=SCREEN_H-200;
	
	}*/
	
}

void animerpersonne(personne *p)
{
p->frame++;
if (p->frame>=9)
{
p->frame++;   
p->frame=0;
}
//p->frame=0;
}

void saut(personne *p,int dt ,int posdebut)
{
double dx =0.5 * p->acceleration * dt * dt + p->vitesse *dt;
int seuil=(0,0);
if (p->pos.y!=seuil && p->etat==1)
{
p->pos.y-=dx;
}
if(p->pos.y==seuil)
{
p->etat=2;
}
if (p->pos.y!=posdebut && p->etat==2)
{
p->pos.y+=dx;
}
if (p->pos.y==posdebut)
{
p->etat=0;
}
p->vitesse +=p->acceleration * dt;

}
void liberer_image(image imge){
SDL_FreeSurface(imge.img);
}
void liberer_perso(personne p){
SDL_FreeSurface(p.perso);
 }
void liberer_music(Mix_Music *music){
Mix_FreeMusic(music);
}


