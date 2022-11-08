//
// Created by theom on 03/11/2022.
//

#include "Header.h"

void menu(BITMAP* doublebuffer)
{
    BITMAP* fondmenu[120];
    BITMAP* logo;
    BITMAP* buttonstart[3];
    BITMAP* buttonload[3];
    BITMAP* buttonrules[3];
    BITMAP* buttoncredits[3];
    BITMAP* buttonexit[3];
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

    logo = load_bitmap("images/menu/logo/Simcity.bmp",NULL);
    if (!logo)
    {
        allegro_message("pas pu trouver logo");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<3; i++)
    {
        sprintf(nomfichier,"images/menu/logo/buttonstart%d.bmp",i+1);

        buttonstart[i] = load_bitmap(nomfichier,NULL);
        if (!buttonstart[i])
        {
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }
    for (int i=0; i<3; i++)
    {
        sprintf(nomfichier,"images/menu/logo/buttonload%d.bmp",i+1);

        buttonload[i] = load_bitmap(nomfichier,NULL);
        if (!buttonload[i])
        {
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }
    for (int i=0; i<3; i++)
    {
        sprintf(nomfichier,"images/menu/logo/buttonrules%d.bmp",i+1);

        buttonrules[i] = load_bitmap(nomfichier,NULL);
        if (!buttonrules[i])
        {
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }
    for (int i=0; i<3; i++)
    {
        sprintf(nomfichier,"images/menu/logo/buttoncredits%d.bmp",i+1);

        buttoncredits[i] = load_bitmap(nomfichier,NULL);
        if (!buttoncredits[i])
        {
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }
    for (int i=0; i<3; i++)
    {
        sprintf(nomfichier,"images/menu/logo/buttonexit%d.bmp",i+1);

        buttonexit[i] = load_bitmap(nomfichier,NULL);
        if (!buttonexit[i])
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
            menuimg--;

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
                draw_sprite(doublebuffer,logo,470,50);//logo
                if((mouse_y>430 && mouse_y<565)&&(mouse_x>330 && mouse_x<630))//bouton lancer partie
                {
                    draw_sprite(doublebuffer,buttonstart[1],330,430);
                    if(mouse_b&1==1)
                    {
                        draw_sprite(doublebuffer,buttonstart[2],330,430);
                    }
                }
                else
                {
                    draw_sprite(doublebuffer,buttonstart[0],330,430);
                }

                if((mouse_y>430 && mouse_y<535)&&(mouse_x>680 && mouse_x<980))//bouton charger une partie
                {
                    draw_sprite(doublebuffer,buttonload[1],680,430);
                    if(mouse_b&1==1)
                    {
                        draw_sprite(doublebuffer,buttonload[2],680,430);
                    }
                }
                else
                {
                    draw_sprite(doublebuffer,buttonload[0],680,430);
                }

                if((mouse_y>600 && mouse_y<735)&&(mouse_x>330 && mouse_x<630))//bouton regles
                {
                    draw_sprite(doublebuffer,buttonrules[1],330,600);
                    if(mouse_b&1==1)
                    {
                        draw_sprite(doublebuffer,buttonrules[2],330,600);
                    }
                }
                else
                {
                    draw_sprite(doublebuffer,buttonrules[0],330,600);
                }

                if((mouse_y>600 && mouse_y<735)&&(mouse_x>680 && mouse_x<980))//bouton credits
                {
                    draw_sprite(doublebuffer,buttoncredits[1],680,600);
                    if(mouse_b&1==1)
                    {
                        draw_sprite(doublebuffer,buttoncredits[2],680,600);
                    }
                }
                else
                {
                    draw_sprite(doublebuffer,buttoncredits[0],680,600);
                }

                if((mouse_y>760 && mouse_y<895)&&(mouse_x>520 && mouse_x<820))//bouton exit
                {
                    draw_sprite(doublebuffer,buttonexit[1],520,760);
                    if(mouse_b&1==1)
                    {
                        draw_sprite(doublebuffer,buttonexit[2],520,760);
                    }
                }
                else
                {
                    draw_sprite(doublebuffer,buttonexit[0],520,760);
                }



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