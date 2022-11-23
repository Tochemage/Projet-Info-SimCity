//
// Created by theom on 17/11/2022.
//

#include "Header.h"


void bouclejeu(BITMAP* doublebuffer, t_ville* maVille, t_infos* infos)
{
    ///Variables///
    //Temps
    int ingame=1;
    float clk1=0,clk2=0,clktot=0;
    int cmptmois=0;
    int cmptpause=0;

    //Joueur
    int click_x=-1, click_y=-1, selection=-1;

    ///BITMAP///
    BITMAP* platjeu;



    platjeu = load_bitmap("images/jeu/plateau/platjeu.bmp",NULL);
    if (!platjeu)
    {
        allegro_message("pas pu trouver plateau de jeu");
        exit(EXIT_FAILURE);
    }

    while(!key[KEY_ESC] && ingame==1)
    {
        ///PRISE DU TEMPS 1///
        clk1=clock()/CLOCKS_PER_SEC;
        if(clktot>=15)//compteur de temps en mois toute les 15 sec
        {
            cmptmois++;

            printf("%d\n",cmptmois);
            clktot=0;
        }

        blit(platjeu,doublebuffer,0,0,0,0,1920,1080);

        ///INTERACTIONS JOUEUR///
        if(mouse_b&1==1)    //Permet de savoir sur quelle icone le joueur a cliqué
        {
            ///Detection et analyse
            click_x = mouse_x;
            click_y = mouse_y;
            selection = detectionClick(click_x, click_y);
            //(-1:Rien    0:Construire un batiment   1:Données bat  2:VisionEtage   3:Sauvegarde    4:quitter)

            ///Appel des sous-programmes
            if(selection==0)    //Construction batiment
            {
                //appel fonction constru bat en envoyant click_x et click_y pour detecter ensuite quel bat il veut construire
            }
            if(selection==1)    //Voir données batiment sur cette case
            {
                recherche_case_selec(maVille, click_x, click_y);
                //Afficher données batiment case
            }
        }


        /*
        //detection pour placer un bat
        if((mouse_y>234 && mouse_y<234+799)&&(mouse_x>740 && mouse_x<740+799))
        {
            for(int i=0;i<40;i++)
            {
                for(int j=0;j<40;j++)
                {
                    if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+i*20 && mouse_x<740+20+i*20) && mouse_b&1==1)
                    {
                        maVille->map[i][j].habitation->type=batselected;
                    }
                }
            }
        }
         */

        //mettre en play pause avec un bouton

        /*
         if()//condition bouton
         {
            if(ingame==0)
            {
            ingame=1
            }
            else
            {
            ingame=0
            }
         }
        */

        ///QUITTER LE JEU///
        if(key[KEY_RCONTROL])//quitter le jeu (fin du prog)
        {
            ingame=0;
        }
        show_mouse(doublebuffer);
        blit(doublebuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(10);


        ///PRISE DU TEMPS 2///
        clk2=clock()/CLOCKS_PER_SEC;
        if(cmptpause==0)
        {
            clktot+=clk2-clk1;
        }

    }
}


/**------------------------------------------------------------------------------------------------------------------**/
/**------------------------------------------------------------------------------------------------------------------**/

/// SOUS-PROGRAMMES SERVANT A BOUCLE DE JEU ///

int detectionClick(int click_x, int click_y)    //Renvoie un entier permettant de savoir sur quoi le joueur a clique -> (-1:Rien    0:Construire un batiment   1:Données bat  2:VisionEtage   3:Sauvegarde    4:quitter)
{
    //A FAIRE                                                       NEED ALLEGRO
    /*
    if(mouse sur construire un batiment) //quel que soit le batiment
    {
        return 0;
    }
    if(mouse sur un batiment)
    {
        return 1;
    }
    if(mouse sur icone vision etages)
    {
        return 2;
    }
    if(mouse sur icone sauvegarde)
    {
        return 3;
    }
    if(mouse sur icone quitter)
    {
        return 4;
    }
    else
    {
        return -1;
    }
    */
}



t_case* recherche_case_selec(t_ville* ville, int click_x, int click_y)
{
    int i=0, j=0;
    int indice_ligne=0, indice_colonne=0;
    int lignes = NB_LIGNES;
    int colonnes = NB_COLONNES;
    t_case* case_recherchee;

    for(i=0; i<lignes; i++)
    {
        for (j = 0; j < colonnes; j++)
        {
            if((ville->map[i][j].num_case_x > click_x) && (ville->map[i][j].num_case_y > click_y))
            {
                case_recherchee = &ville->map[i-1][j-1];
            }
        }
    }

    return case_recherchee;
}


