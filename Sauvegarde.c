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
    FILE* fichier=NULL;

    ///Instructions

    //Fichier 1 (structure ville)
    fichier=fopen("sauvegardestructjoueur.txt", "w+"); //Ouverture du fichier
    if(fichier==NULL) //Si le programme n'arrive pas à ouvrir le fichier
    {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde\n"); //Message d'erreur d'ouverture
    }
    else //Si l'ouverture du fichier a réussi
    {
        fprintf(fichier, "%s\n", ville->nom);
        //fprintf(fichier, "\n"); //Mise à la ligne dans le fichier pour pouvoir lire ensuite ligne par ligne
        fprintf(fichier, "%ld\n", ville->argent);
        fprintf(fichier, "%d\n", ville->nbr_habitants);
        fprintf(fichier, "%d\n", ville->capa_eau);
        fprintf(fichier, "%d\n", ville->capa_elec);
        fprintf(fichier, "%d\n", ville->impots);
        fprintf(fichier, "%d\n", ville->nbr_mois_jeu);
        fprintf(fichier, "%d\n", ville->mode_jeu);
        fprintf(fichier, "%d\n", ville->possesions.nb_chateauEau);
        fprintf(fichier, "%d\n", ville->possesions.nb_centraleElec);
        fprintf(fichier, "%d\n", ville->possesions.nb_terrainVague);
        fprintf(fichier, "%d\n", ville->possesions.nb_cabane);
        fprintf(fichier, "%d\n", ville->possesions.nb_maison);
        fprintf(fichier, "%d\n", ville->possesions.nb_immeuble);
        fprintf(fichier, "%d\n", ville->possesions.nb_gratteCiel);


        fclose(fichier); //Fermeture du fichier
    }

    //Fichier 2 (matrice map)
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
        printf("Erreur lors de l'ouverture du fichier de sauvegardevouvou"); //Message d'erreur d'ouverture
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
