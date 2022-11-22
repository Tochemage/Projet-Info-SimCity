//
// Created by theom on 17/11/2022.
//

#include "Header.h"

void bouclejeu(BITMAP* doublebuffer,t_ville* ville)
{
    ///Variables///
    //Temps
    int ingame=1;
    float clk1=0,clk2=0,clktot=0;
    int cmptmois=0;
    int cmptpause=0;

    int batselected;// 0 pour une habitation

    ///BITMAP///
    BITMAP* platjeu;

    //Joueur
    int click_x=-1, click_y=-1, selection=-1;

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



        //detection pour placer un bat
        if((mouse_y>234 && mouse_y<234+799)&&(mouse_x>740 && mouse_x<740+799))
        {
            for(int i=0;i<40;i++)
            {
                for(int j=0;j<40;j++)
                {
                    if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+i*20 && mouse_x<740+20+i*20) && mouse_b&1==1)
                    {
                        ville->map[i][j].habitation->type=batselected;
                    }
                }
            }
        }

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