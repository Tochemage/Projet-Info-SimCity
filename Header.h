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

typedef struct condition_amelioration_terrain_vague /// terrain vague
{
    int eau;
    int electricite;
    int route;
}t_amelioration_TV; /// TV -> Terrain Vague

typedef struct condition_amelioration_cabane /// cabane
{
    int eau;
    int electricite;
    int route;
}t_amelioration_C; /// C -> Cabane

typedef struct condition_amelioration_maison /// maison
{
    int eau;
    int electricite;
    int route;
}t_amelioration_M; /// M -> Maison

typedef struct condition_amelioration_immeuble /// immeuble
{
    int eau;
    int electricite;
    int route;
}t_amelioration_I; /// I -> Immeuble

typedef struct condition_amelioration_Gratte_ciel /// Gratte-ciel
{
    int eau;
    int electricite;
    int route;
}t_amelioration_GC; /// GC -> Gratte-ciel

typedef struct batiment
{
    int type; /// 0->terrain vague(0 hab), 1->cabane(10 hab), 2->maison(50 hab), 3->immeuble(100 hab), 4->Gratte-ciel(1000 hab)
    char nom_bat[20];
    int taille;
    int conso_eau;
    int conso_elec;
    int nbr_hab;
}t_batiment;


#endif //V1_HEADER_H
