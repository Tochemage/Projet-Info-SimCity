//
// Created by theom on 03/11/2022.
//

#ifndef V1_HEADER_H
#define V1_HEADER_H

#include <stdio.h>
#include <allegro.h>



///////////////////
/// STRUCTURES ///
/////////////////

///Informations du jeu///
typedef struct informations_habitations
{
    int cout;
    int nb_case_x;
    int nb_case_y;
}t_infoHab;

typedef struct informations_industries
{
    int cout;
    int nb_case_x;
    int nb_case_y;
}t_infoIndus;

typedef struct informations_routes      //Pareil pour canalisations et lignes électriques
{
    int cout;
    int nb_case_x;
    int nb_case_y;
}t_infoRoute;

typedef struct evolution_terrain_vague
{
    int eau;
    int electricite;
}t_info_terrainV_Evol;

typedef struct evolution_cabane
{
    int eau;
    int electricite;
}t_info_cabane_Evol;

typedef struct evolution_maison
{
    int eau;
    int electricite;
}t_info_maison_Evol;

typedef struct evolution_immeuble
{
    int eau;
    int electricite;
}t_info_immeuble_Evol;

typedef struct evolution_gratte_ciel
{
    int eau;
    int electricite;
}t_info_gratteC_Evol;

typedef struct informations_evolution
{
    t_info_terrainV_Evol Evol_terrain_vague;
    t_info_cabane_Evol Evol_cabane;
    t_info_maison_Evol Evol_maison;
    t_info_immeuble_Evol Evol_immeuble;
    t_info_gratteC_Evol Evol_gratte_ciel;
}t_infoEvol;

typedef struct informations_jeu
{
    t_infoHab I_habitations;
    t_infoIndus I_industries;
    t_infoRoute I_routes;       //Pareil pour canalisations et lignes électriques
    t_infoEvol I_evolution;
}t_infos;


///Structures du joueur///
typedef struct habitation
{
    int type;           // 0->terrain vague(0 hab), 1->cabane(10 hab), 2->maison(50 hab), 3->immeuble(100 hab), 4->Gratte-ciel(1000 hab)
    char nom_bat[20];
    int conso_eau;      //=Nb habitants de ce type d'habitation
    int conso_elec;     //=Nb habitants de ce type d'habitation
    int nbr_hab;
}t_habitation;

typedef struct industrie
{
    int type;           // 5:chateau eau    6:Centrale electrique
    char nom_bat[20];
}t_industrie;

typedef struct jeu_cases
{
    int type_case;      //0:vide    1:route(canalisation ou ligne tension)     3:industrie     4:habitation
    int num_color;      //numero de coloration si on a besoin (par ex pour les differentes cases d'un meme batiment)
    int num_case_x;     //numero de case en x et en y pour retrouver la case si besoin
    int num_case_y;
    t_habitation* habitation;    //Structure habitation s'il y en a une, sinon pointe sur NULL
    t_industrie* industrie;      //Structure industrie s'il y en a une, sinon pointe sur NULL
}t_case;

typedef struct possesions_joueur
{
    int nb_chateauEau;
    int nb_centraleElec;
    int nb_terrainVague;
    int nb_cabane;
    int nb_maison;
    int nb_immeuble;
    int nb_gratteCiel;
}t_possessions;

typedef struct ville
{
    char nom[30];
    int argent;
    int nbr_habitants;
    int capa_eau;
    int capa_elec;
    int impots;
    int nbr_mois_jeu;
    int mode_jeu;           // 0 communiste, 1 capitaliste
    t_possessions possesions;
    t_case map[35][45];     //A FAIRE : matrice de structures cases pout toutes les cases de la map
}t_ville;


/////////////////
///PROTOTYPES///
///////////////

void AllegroInit();
void menu(BITMAP* doublebuffer);

BITMAP* recup_sprites( BITMAP*scr,int w,int h,int startx,int starty,int col,int element);


#endif //V1_HEADER_H
