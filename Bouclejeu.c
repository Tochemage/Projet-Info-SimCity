//
// Created by theom on 17/11/2022.
//

#include "Header.h"

void bouclejeu(BITMAP* doublebuffer)
{
    int ingame=1;
    float clk1=0,clk2=0,clktot=0;
    int cmptmois=0;

    while(!key[KEY_ESC] && ingame==1)
    {
        clk1=clock()/CLOCKS_PER_SEC;
        if(clktot>=15)//compteur de temps en mois toute les 15 sec
        {
            cmptmois++;

            printf("%d\n",cmptmois);
            clktot=0;
        }

        if(key[KEY_RCONTROL])//quitter le jeu (fin du prog)
        {
            ingame=0;
        }
        show_mouse(doublebuffer);
        blit(doublebuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(10);

        clk2=clock()/CLOCKS_PER_SEC;
        clktot+=clk2-clk1;
    }
}
