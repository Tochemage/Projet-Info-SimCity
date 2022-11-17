//
// Created by theom on 17/11/2022.
//

#include "Header.h"

void bouclejeu(BITMAP* doublebuffer)
{
    ///Variables///
    //Temps
    int ingame=1;
    float clk1=0,clk2=0,clktot=0;
    int cmptmois=0;

    //Joueur
    int click_x=-1, click_y=-1, selection=-1;

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


        ///INTERACTIONS JOUEUR///
        if(mouse_b&1==1)    //Permet de savoir sur quelle icone le joueur a cliqué
        {
            click_x = mouse_x;
            click_y = mouse_y;
            selection = detectionClick(click_x, click_y);
            //(-1:Rien    0:Construire un batiment   1:Données bat  2:VisionEtage   3:Sauvegarde    4:quitter)
        }





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
        clktot+=clk2-clk1;
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