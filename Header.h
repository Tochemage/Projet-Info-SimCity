//
// Created by theom on 03/11/2022.
//

#ifndef V1_HEADER_H
#define V1_HEADER_H

#include <stdio.h>
#include <allegro.h>
#include <stdbool.h>

BITMAP* recup_sprites( BITMAP*scr,int w,int h,int startx,int starty,int col,int element);

void AllegroInit();

void menu(BITMAP* doublebuffer);

typedef struct ville
{
    char nom[30];
    int argent;
    int nbr_habitants;
    int impots;
    int mode_jeu; /// 0 communiste, 1 capitaliste
}t_ville;

typedef struct chateau_eau
{
    int capa = 5000;
    int nbr_utilisation;
}t_eau;

typedef struct centrale
{
    int electricite = 5000;
    int nbr_utilisation;
}t_electricite;

typedef struct condition_amelioration_terrain_vague /// terrain vague
{
    int eau = 0;
    int electricite = 0;
}t_amelioration_TV; /// TV -> Terrain Vague

typedef struct condition_amelioration_cabane /// cabane
{
    int eau = 10;
    int electricite = 10;
}t_amelioration_C; /// C -> Cabane

typedef struct condition_amelioration_maison /// maison
{
    int eau = 40;
    int electricite = 40;
}t_amelioration_M; /// M -> Maison

typedef struct condition_amelioration_immeuble /// immeuble
{
    int eau = 50;
    int electricite = 50;
}t_amelioration_I; /// I -> Immeuble

typedef struct condition_amelioration_Gratte_ciel /// Gratte-ciel
{
    int eau = 900;
    int electricite = 900;
}t_amelioration_GC; /// GC -> Gratte-ciel

typedef struct batiment_habitation
{
    int type; /// 0->terrain vague(0 hab), 1->cabane(10 hab), 2->maison(50 hab), 3->immeuble(100 hab), 4->Gratte-ciel(1000 hab)
    char nom_bat[20];
    int taille;
    int conso_eau;
    int conso_elec;
    int nbr_hab;
    int nbr_cases_x = 3;
    int nbr_cases_y = 3;
    int cout = 1000;
}t_batiment_hab;

typedef struct batiment_production
{
    int type; /// 0->centrale, 1->chateau eau
    int nbr_cases_x = 4;
    int nbr_cases_y = 6;
    int cout = 100000;
}t_batiment_prod;

typedef struct route
{
    int nbr_cases_x = 1;
    int nbr_cases_y = 1;
    int cout = 10;
}t_route;


#endif //V1_HEADER_H
