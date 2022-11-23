//
// Created by Clement on 08/11/2022.
//

#include "Header.h"

/////////////////////////////////////////////////
///SOUS-PROGRAMME GENERAL DES INITIALISATIONS///
///////////////////////////////////////////////

void sp_init_struct(t_ville* maVille, t_infos* infos)           //Appels de tous les sp d'initialisation
{
    init_struct_ville(maVille);
    init_struct_infos(infos);
}


/**------------------------------------------------------------------------------------------------------------------**/

///INITIALISATION STRUCT VILLE///
void init_struct_ville (t_ville* maVille)
{
    ///General///
    maVille->argent = 500000;
    maVille->nbr_habitants = 0;
    maVille->capa_eau = 0;
    maVille->capa_elec = 0;
    maVille->impots = 10;
    maVille->nbr_mois_jeu = 0;
    maVille->mode_jeu = -1;

    ///Possessions///
    maVille->possesions.nb_chateauEau = 0;
    maVille->possesions.nb_centraleElec = 0;
    maVille->possesions.nb_terrainVague = 0;
    maVille->possesions.nb_cabane = 0;
    maVille->possesions.nb_maison = 0;
    maVille->possesions.nb_immeuble = 0;
    maVille->possesions.nb_gratteCiel = 0;

    ///Matrice map///
    maVille->map = creation_matrice();
    remplissage_matrice(maVille->map);
}


/**------------------------------------------------------------------------------------------------------------------**/

///CREATION MATRICE///
t_case** creation_matrice()
{
    int i=0;

    int lignes=NB_LIGNES;
    int colonnes=NB_COLONNES;

    t_case** maMatrice = (t_case**)malloc(lignes * sizeof(t_case*));
    if(maMatrice==NULL)
    {
        allegro_message("\nPb alloc lignes matrice\n");
    }

    for(i=0; i<lignes; i++)
    {
        maMatrice[i]=(t_case*)malloc(colonnes * sizeof(t_case));
        if(maMatrice[i]==NULL)
        {
            allegro_message("\nPb alloc colonnes matrice\n");
        }
    }

    //printf("\n\nMatrice creee avec %d lignes et %d colonnes", lignes, colonnes);

    return maMatrice;
}

/**------------------------------------------------------------------------------------------------------------------**/

///REMPLISSAGE MATRICE///
void remplissage_matrice(t_case** maMatrice)
{
    int i=0, j=0;
    int lignes=NB_LIGNES;
    int colonnes=NB_COLONNES;
    int indice_ligne=0;
    int indice_colonne=0;
    int numero_case=0;

    for(i=0; i<lignes; i++)
    {
        for(j=0; j<colonnes; j++)
        {
            ///Num case///
            maMatrice[i][j].num_case=numero_case;
            numero_case++;

            ///Type case et coloration///
            maMatrice[i][j].type_case = 0;
            maMatrice[i][j].num_color = 0;

            ///Coordonnees cases///
            maMatrice[i][j].num_case_x = 740+indice_colonne;
            maMatrice[i][j].num_case_y = 234+indice_ligne;
            indice_colonne+=20;
            //printf("%d:%d-%d ", maMatrice[i][j].num_case, maMatrice[i][j].num_case_x, maMatrice[i][j].num_case_y);

            ///Structure habitation///
            maMatrice[i][j].habitation = (t_habitation*) malloc(sizeof (t_habitation));
            maMatrice[i][j].habitation->num_bat = 0;
            maMatrice[i][j].habitation->type = 0;
            maMatrice[i][j].habitation->conso_eau = 0;
            maMatrice[i][j].habitation->conso_elec = 0;
            maMatrice[i][j].habitation->nbr_hab = 0;

            ///Structure industrie///
            maMatrice[i][j].industrie = (t_industrie*) malloc(sizeof (t_industrie));
            maMatrice[i][j].industrie->num_bat = 0;
            maMatrice[i][j].industrie->type = 0;
        }
        indice_ligne+=20;
        indice_colonne=0;
        //printf("\n");
    }
}

/**------------------------------------------------------------------------------------------------------------------**/

///INITIALISATION STRUCT INFOS VILLE///
void init_struct_infos (t_infos* mesInfos)
{
    ///Habitations///
    mesInfos->I_habitations.cout = 1000;
    mesInfos->I_habitations.nb_case_x = 3;
    mesInfos->I_habitations.nb_case_y = 3;

    ///Industries///
    mesInfos->I_industries.cout = 100000;
    mesInfos->I_industries.nb_case_x = 4;
    mesInfos->I_industries.nb_case_y = 6;

    ///Routes, canalisations, lignes électriques///
    mesInfos->I_routes.cout = 10;
    mesInfos->I_routes.nb_case_x = 1;
    mesInfos->I_routes.nb_case_y = 1;

    ///Evolution des habitations///
    mesInfos->I_evolution.Evol_terrain_vague.eau = 0;
    mesInfos->I_evolution.Evol_terrain_vague.electricite = 0;

    mesInfos->I_evolution.Evol_cabane.eau = 10;
    mesInfos->I_evolution.Evol_cabane.electricite = 10;

    mesInfos->I_evolution.Evol_maison.eau = 50;
    mesInfos->I_evolution.Evol_maison.electricite = 50;

    mesInfos->I_evolution.Evol_immeuble.eau = 100;
    mesInfos->I_evolution.Evol_immeuble.electricite = 100;

    mesInfos->I_evolution.Evol_gratte_ciel.eau = 1000;
    mesInfos->I_evolution.Evol_gratte_ciel.electricite = 1000;
}





/**------------------------------------------------------------------------------------------------------------------**/
/**------------------------------------------------------------------------------------------------------------------**/
