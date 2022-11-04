//
// Created by theom on 03/11/2022.
//

#ifndef V1_HEADER_H
#define V1_HEADER_H

#include <stdio.h>
#include <allegro.h>
#include <stdbool.h>


//////////////////////structures///////////////////::::


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
    int capa;
    int nbr_utilisation;
}t_eau;

typedef struct centrale
{
    int electricite;
    int nbr_utilisation;
}t_electricite;

typedef struct condition_amelioration_terrain_vague /// terrain vague
{
    int eau;
    int electricite;
}t_amelioration_TV; /// TV -> Terrain Vague

typedef struct condition_amelioration_cabane /// cabane
{
    int eau;
    int electricite;
}t_amelioration_C; /// C -> Cabane

typedef struct condition_amelioration_maison /// maison
{
    int eau;
    int electricite;
}t_amelioration_M; /// M -> Maison

typedef struct condition_amelioration_immeuble /// immeuble
{
    int eau;
    int electricite;
}t_amelioration_I; /// I -> Immeuble

typedef struct condition_amelioration_Gratte_ciel /// Gratte-ciel
{
    int eau;
    int electricite;
}t_amelioration_GC; /// GC -> Gratte-ciel

typedef struct batiment_habitation
{
    int type; /// 0->terrain vague(0 hab), 1->cabane(10 hab), 2->maison(50 hab), 3->immeuble(100 hab), 4->Gratte-ciel(1000 hab)
    char nom_bat[20];
    int taille;
    int conso_eau;
    int conso_elec;
    int nbr_hab;
    int nbr_cases_x;
    int nbr_cases_y;
    int cout;
}t_batiment_hab;

typedef struct batiment_production
{
    int type; /// 0->centrale, 1->chateau eau
    int nbr_cases_x;
    int nbr_cases_y;
    int cout;
}t_batiment_prod;

typedef struct route
{
    int nbr_cases_x ;
    int nbr_cases_y ;
    int cout ;
}t_route;



//////////////////////////PROTO//////////////////////////////////

BITMAP* recup_sprites( BITMAP*scr,int w,int h,int startx,int starty,int col,int element);

void AllegroInit();

void menu(BITMAP* doublebuffer);

t_eau* initchateaueau();

t_electricite * initelec();

t_amelioration_TV * initamelTV();

t_amelioration_C * initamelcab();

t_amelioration_M * initamelmaison();

t_amelioration_I * initamelimmeuble();

t_amelioration_GC * initamelGC();

t_batiment_hab * initbathab();

t_batiment_prod * initbatprod();

t_route * initroute();

#endif //V1_HEADER_H
