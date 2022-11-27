//
// Created by Clement on 17/11/2022.
//


#include "Header.h"

///CALCUL DES DONNEES DU JOUEUR///

int calcul_data_J(t_ville* ville, t_infos* infos)      //Le programme va prendre ce qu'on connait déjà (possessions
{
    int hab_terrainVague=0;
    int hab_cabane=0;
    int hab_maison=0;
    int hab_immeuble=0;
    int hab_gratteCiel=0;

    ///Calcul nombre habitants///
    hab_terrainVague = ville->possesions.nb_terrainVague * infos->I_habitations.nb_hab_terrainVague;
    hab_cabane = ville->possesions.nb_cabane * infos->I_habitations.nb_hab_cabane;
    hab_maison = ville->possesions.nb_maison * infos->I_habitations.nb_hab_maison;
    hab_immeuble = ville->possesions.nb_immeuble * infos->I_habitations.nb_hab_immeuble;
    hab_gratteCiel = ville->possesions.nb_gratteCiel * infos->I_habitations.nb_hab_gratteCiel;

    ville->nbr_habitants = hab_terrainVague + hab_cabane + hab_maison + hab_immeuble + hab_gratteCiel;

    ///Calcul capacité eau totale de la ville///
    ville->capa_eau = ville->possesions.nb_chateauEau * infos->I_industries.capa_totale_eau;

    ///Calcul capacité électrique totale de la ville///
    ville->capa_elec = ville->possesions.nb_centraleElec * infos->I_industries.capa_totale_elec;

    ///Calcul Victoire ou Défaite///
    //Victoire : 50M ECEflouz ou 50 000 hab
    //Défaite : 0 ECEflouz

    //Victoire
    if(ville->argent >= 50000000  ||  ville->nbr_habitants >= 50000)
    {
        //Allegro : affichage victoire                                             NEED ALLEGRO
        return 0;   ////Mettre la variable ingame à 0 pour quitter la boucle de jeu
    }

    //Défaite
    if(ville->argent <= 0)
    {
        //Allegro : affichage défaite                                               NEED ALLEGRO
        return 0;   //Mettre la variable ingame à 0 pour quitter la boucle de jeu
    }

    return 1;   //On renvoie 1 pour que la variable ingame soit à 1 et que la boucle de jeu continue

}
