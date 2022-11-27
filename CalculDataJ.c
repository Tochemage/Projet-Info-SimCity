//
// Created by Clement on 17/11/2022.
//


#include "Header.h"

///////////////////////////////////
///CALCUL DES DONNEES DU JOUEUR///
/////////////////////////////////


int calcul_data_J(t_ville* ville, t_infos* infos)      //Le programme va prendre ce qu'on connait déjà (possessions
{
    int hab_terrainVague=0;
    int hab_cabane=0;
    int hab_maison=0;
    int hab_immeuble=0;
    int hab_gratteCiel=0;

    ///Remise à 0 des possessions///
    ville->possesions.nb_chateauEau = 0;
    ville->possesions.nb_centraleElec = 0;
    ville->possesions.nb_terrainVague = 0;
    ville->possesions.nb_cabane = 0;
    ville->possesions.nb_maison = 0;
    ville->possesions.nb_immeuble = 0;
    ville->possesions.nb_gratteCiel = 0;

    ///Calcul possessions///
    for(int i=0; i<NB_LIGNES; i++)
    {
        for(int j=0; j<NB_COLONNES; j++)
        {
            if(ville->map[i][j].habitation->type == 1)
            {
                ville->possesions.nb_cabane++;
            }
            if(ville->map[i][j].habitation->type == 2)
            {
                ville->possesions.nb_maison++;
            }
            if(ville->map[i][j].habitation->type == 3)
            {
                ville->possesions.nb_immeuble++;
            }
            if(ville->map[i][j].habitation->type == 4)
            {
                ville->possesions.nb_gratteCiel++;
            }
            if(ville->map[i][j].habitation->type == 6)
            {
                ville->possesions.nb_chateauEau++;
            }
            if(ville->map[i][j].habitation->type == 5)
            {
                ville->possesions.nb_centraleElec++;
            }

        }
    }

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
        allegro_message("Bravo !!! Vous avez gagné, vous avez 50 000 000 ECEflouz ou 50 000 habitants");
        return 0;   //Mettre la variable ingame à 0 pour quitter la boucle de jeu
    }

    //Défaite
    if(ville->argent <= 0)
    {
        allegro_message("Dommage... Vous avez perdu, vous n'avez plus d'argent");
        return 0;   //Mettre la variable ingame à 0 pour quitter la boucle de jeu
    }

    return 1;   //On renvoie 1 pour que la variable ingame soit à 1 et que la boucle de jeu continue

}
