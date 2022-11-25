//
// Created by theom on 03/11/2022.
//

///////////////
/// HEADER ///
/////////////


#ifndef V1_HEADER_H
#define V1_HEADER_H

#include <stdio.h>
#include <allegro.h>
#include <time.h>

/**------------------------------------------------------------------------------------------------------------------**/
/**------------------------------------------------------------------------------------------------------------------**/


/////////////
///DEFINE///
///////////

#define NB_COLONNES 40
#define NB_LIGNES 40
#define SAISIE_MAX 20


/**------------------------------------------------------------------------------------------------------------------**/
/**------------------------------------------------------------------------------------------------------------------**/


///////////////////
/// STRUCTURES ///
/////////////////

///Informations du jeu///
typedef struct informations_habitations
{
    int cout;
    int nb_case_x;
    int nb_case_y;
    int nb_hab_terrainVague;
    int nb_hab_cabane;
    int nb_hab_maison;
    int nb_hab_immeuble;
    int nb_hab_gratteCiel;
}t_infoHab;

typedef struct informations_industries
{
    int cout;
    int nb_case_x;
    int nb_case_y;
    int capa_totale_eau;
    int capa_totale_elec;
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


/**------------------------------------------------------------------------------------------------------------------**/

///Structures du joueur///
typedef struct habitation
{
    char nom_bat[20];
    int num_bat;        //Numéro de batiment pour pouvoir comparer aux autres cases et savoir sur quelles cases est un batiment, commence à 1 (defaut:0)
    int type;           // 0:vide   1:terrain vague(0 hab), 2:cabane(10 hab), 3:maison(50 hab), 4:immeuble(100 hab), 5:Gratte-ciel(1000 hab)
    int conso_eau;      //=Nb habitants de ce type d'habitation
    int conso_elec;     //=Nb habitants de ce type d'habitation
    int nbr_hab;
}t_habitation;

typedef struct industrie
{
    int num_bat;
    int type;           // 0:vide   6:chateau eau    7:Centrale electrique
    char nom_bat[20];
}t_industrie;

typedef struct jeu_cases
{
    int num_case;       //Numéro de case en faisant par lignes [0;1599]
    int type_case;      //0:vide    1:route(canalisation ou ligne tension)     3:industrie     4:habitation
    int num_color;      //numero de coloration si on a besoin, a 0 par defaut (par ex pour les differentes cases d'un meme batiment)
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
    long int argent;
    int nbr_habitants;
    int capa_eau;
    int capa_elec;
    int impots;
    int nbr_mois_jeu;
    int mode_jeu;           // 0 communiste, 1 capitaliste
    t_possessions possesions;
    t_case** map;     //Matrice de structures cases pout toutes les cases de la map (map[i][j], i=lignes, j=colonnes)
}t_ville;


/**------------------------------------------------------------------------------------------------------------------**/
/**------------------------------------------------------------------------------------------------------------------**/


/////////////////
///PROTOTYPES///
///////////////

///INITIALISATIONS///
void sp_init_struct(t_ville* maVille, t_infos* infos);
void init_struct_ville (t_ville* maVille);
void init_struct_infos (t_infos* mesInfos);
t_case** creation_matrice();
void remplissage_matrice(t_case** maMatrice);



///ALLEGRO///
void AllegroInit();
BITMAP* recup_sprites( BITMAP*scr,int w,int h,int startx,int starty,int col,int element);


///MENU///
void menu(BITMAP* doublebuffer,int* startgame,t_ville* ville);

///JEU///
//Boucle de jeu
void bouclejeu(BITMAP* doublebuffer, t_ville* ville, t_infos* infos);
int detectionClick(int click_x, int click_y);
t_case* recherche_case_selec(t_ville* ville, int click_x, int click_y);

//Construction batiment
int poserbat(int batselected,BITMAP* doublebuffer, t_ville* maVille,BITMAP* maison,BITMAP* cabane,BITMAP* immeuble,BITMAP* gratteciel,BITMAP* usine,BITMAP* chateaudeau,BITMAP* route);

//Calcul data joueur
int calcul_data_J(t_ville* ville, t_infos* infos);


#endif //V1_HEADER_H