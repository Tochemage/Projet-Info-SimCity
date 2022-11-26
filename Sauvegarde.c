//
// Created by Clement on 17/11/2022.
//


#include "Header.h"

//////////////////////////////////////////////////////
/// SAUVEGARDE ET CHARGEMENT DE PARTIE + SCENARIO ///
////////////////////////////////////////////////////

/// SAUVEGARDE ///


///Sous-programme de sauvegarde
void sauvegardeJoueur(t_ville* ville)  //Mettre structure joueur en paramètre
{
    ///Déclarations
    FILE* fichierVille=NULL;
    FILE* fichierMap=NULL;

    ///Instructions

    ///Fichier 1 (structure ville)
    fichierVille=fopen("sauvegardestructjoueur.txt", "w+"); //Ouverture du fichierVille
    if(fichierVille==NULL) //Si le programme n'arrive pas à ouvrir le fichierVille
    {
        printf("Erreur lors de l'ouverture du fichierVille de sauvegarde ville\n"); //Message d'erreur d'ouverture
    }
    else //Si l'ouverture du fichierVille a réussi
    {
        fprintf(fichierVille, "%s\n", ville->nom);
        //fprintf(fichierVille, "\n"); //Mise à la ligne dans le fichierVille pour pouvoir lire ensuite ligne par ligne
        fprintf(fichierVille, "%ld\n", ville->argent);
        fprintf(fichierVille, "%d\n", ville->nbr_habitants);
        fprintf(fichierVille, "%d\n", ville->capa_eau);
        fprintf(fichierVille, "%d\n", ville->capa_elec);
        fprintf(fichierVille, "%d\n", ville->impots);
        fprintf(fichierVille, "%d\n", ville->nbr_mois_jeu);
        fprintf(fichierVille, "%d\n", ville->mode_jeu);
        fprintf(fichierVille, "%d\n", ville->possesions.nb_chateauEau);
        fprintf(fichierVille, "%d\n", ville->possesions.nb_centraleElec);
        fprintf(fichierVille, "%d\n", ville->possesions.nb_terrainVague);
        fprintf(fichierVille, "%d\n", ville->possesions.nb_cabane);
        fprintf(fichierVille, "%d\n", ville->possesions.nb_maison);
        fprintf(fichierVille, "%d\n", ville->possesions.nb_immeuble);
        fprintf(fichierVille, "%d\n", ville->possesions.nb_gratteCiel);

        fclose(fichierVille); //Fermeture du fichierVille
    }

    ///Fichier 2 (matrice map)
    fichierMap=fopen("sauvegardeMap.txt", "w+"); //Ouverture du fichierMap
    if(fichierMap==NULL) //Si le programme n'arrive pas à ouvrir le fichierMap
    {
        printf("Erreur lors de l'ouverture du fichierMap de sauvegarde map\n"); //Message d'erreur d'ouverture
    }
    else //Si l'ouverture du fichierMap a réussi
    {
        for(int i=0; i<NB_LIGNES; i++)      //On va parcourir toutes les cases en commencant par les lignes pour les sauvegarder
        {
            for(int j=0; j<NB_COLONNES; j++)
            {
                fprintf(fichierMap, "%d\n", ville->map[i][j].num_case);
                fprintf(fichierMap, "%d\n", ville->map[i][j].type_case);
                fprintf(fichierMap, "%d\n", ville->map[i][j].num_color);
                fprintf(fichierMap, "%d\n", ville->map[i][j].num_case_x);
                fprintf(fichierMap, "%d\n", ville->map[i][j].num_case_y);
                fprintf(fichierMap, "%s\n", ville->map[i][j].habitation->nom_bat);
                fprintf(fichierMap, "%d\n", ville->map[i][j].habitation->num_bat);
                fprintf(fichierMap, "%d\n", ville->map[i][j].habitation->type);
                fprintf(fichierMap, "%d\n", ville->map[i][j].habitation->apport_eau);
                fprintf(fichierMap, "%d\n", ville->map[i][j].habitation->apport_elec);
                fprintf(fichierMap, "%d\n", ville->map[i][j].habitation->nbr_hab);
                fprintf(fichierMap, "%d\n", ville->map[i][j].industrie->num_bat);
                fprintf(fichierMap, "%d\n", ville->map[i][j].industrie->type);
                fprintf(fichierMap, "%s\n", ville->map[i][j].industrie->nom_bat);

            }
        }
        fclose(fichierMap); //Fermeture du fichier
    }
}

///Sous-programme de chargement des données du joueur
void chargementJoueur(t_ville* ville)      //Mettre structure joueur en paramètre
{
    ///Déclarations
    FILE* fichier=NULL;

    ///Instructions

    //Fichier 1 (structure ville)
    fichier=fopen("sauvegardestructjoueur.txt", "r"); //Ouverture du fichier
    if(fichier==NULL) //Si le programme n'arrive pas à ouvrir le fichier
    {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde ville\n"); //Message d'erreur d'ouverture
    }
    else //Si l'ouverture du fichier a réussi
    {
        fscanf(fichier, "%s\n", ville->nom); //chargement du nom
        fscanf(fichier, "%ld\n", &ville->argent);
        fscanf(fichier, "%d\n", &ville->nbr_habitants);
        fscanf(fichier, "%d\n", &ville->capa_eau);
        fscanf(fichier, "%d\n", &ville->capa_elec);
        fscanf(fichier, "%d\n", &ville->impots);
        fscanf(fichier, "%d\n", &ville->nbr_mois_jeu);
        fscanf(fichier, "%d\n", &ville->mode_jeu);
        fscanf(fichier, "%d\n", &ville->possesions.nb_chateauEau);
        fscanf(fichier, "%d\n", &ville->possesions.nb_centraleElec);
        fscanf(fichier, "%d\n", &ville->possesions.nb_terrainVague);
        fscanf(fichier, "%d\n", &ville->possesions.nb_cabane);
        fscanf(fichier, "%d\n", &ville->possesions.nb_maison);
        fscanf(fichier, "%d\n", &ville->possesions.nb_immeuble);
        fscanf(fichier, "%d\n", &ville->possesions.nb_gratteCiel);

        fclose(fichier); //Fermeture du fichier
    }


    //Fichier 2 (matrice map)
}
