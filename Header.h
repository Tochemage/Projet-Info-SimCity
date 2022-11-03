//
// Created by theom on 03/11/2022.
//

#ifndef V1_HEADER_H
#define V1_HEADER_H

#include <stdio.h>
#include <allegro.h>

BITMAP* recup_sprites( BITMAP*scr,int w,int h,int startx,int starty,int col,int element);

void AllegroInit();

typedef struct ville
{
    char nom[20];
    int argent;
    int nbr_habitants;
    int impots;
    int mode_jeu; /// 0 communiste, 1 capitaliste
}t_ville;



#endif //V1_HEADER_H
