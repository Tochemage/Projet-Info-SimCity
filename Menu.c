//
// Created by theom on 03/11/2022.
//

#include "Header.h"

void menu(BITMAP* doublebuffer)
{
    BITMAP* fondmenu[120];
    char nomfichier[100];
    int menutmpimg=0, menuimg=119;
    int undermenu=0;

    for (int i=0; i<120; i++)
    {
        sprintf(nomfichier,"images/menu/backmenu/back%d.bmp",i+1);

        fondmenu[i] = load_bitmap(nomfichier,NULL);
        if (!fondmenu[i])
        {
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }
    while(!key[KEY_ESC])
    {
        menutmpimg++;
        if (menutmpimg>=5)
        {
            menutmpimg=0;
            menuimg-=1;

            if (menuimg<=0)
            {
                menuimg=119;
            }
        }
        blit(fondmenu[menuimg],doublebuffer,0,0,0,0,1280,960);

        switch(undermenu)
        {
            case 0:
            {
                //menu principal
                break;
            }
            case 1:
            {
                //lancer une game
                break;
            }
            case 2:
            {
                //charger une sauvegarde
                break;
            }
            case 3:
            {
                //regles
                break;
            }
            case 4:
            {
                //credits
                break;
            }
            case 5:
            {
                //quitter
                allegro_exit();
                exit(0);
            }
        }


        rest(5);
        show_mouse(doublebuffer);
        blit(doublebuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }


    for(int i=0; i<48; i++)
    {
        destroy_bitmap(fondmenu[i]);
    }
}