//
// Created by theom on 03/11/2022.
//

#include "Header.h"

void menu(BITMAP* doublebuffer, int *startgame,t_ville* ville)
{
    BITMAP* fondmenu[120];
    BITMAP* logo;
    BITMAP* buttonstart[3];
    BITMAP* buttonload[3];
    BITMAP* buttonrules[3];
    BITMAP* buttoncredits[3];
    BITMAP* buttonexit[3];
    BITMAP* buttonmodedejeu[3];
    BITMAP* regles[4];
    BITMAP* credits;
    char nomfichier[100];
    int menutmpimg=0, menuimg=119;
    int undermenu=0;
    int cmpt=0,incmpt=0;
    int nameset=0;
    int gamemode=0;
    int numregle=0;
    int songplaying=0;

    SAMPLE *menusong = load_wav("sons/menusong.wav");
    if (!menusong)
    {
        allegro_message("error loading");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<120; i++)
    {
        sprintf(nomfichier,"images/menu/backmenu/back (%d).bmp",i+1);

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

    credits = load_bitmap("images/menu/regle/credits.bmp",NULL);
    if (!credits)
    {
        allegro_message("pas pu trouver credits");
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

    for (int i=0; i<3; i++)
    {
        sprintf(nomfichier,"images/menu/mode de jeu/choixmodedejeu%d.bmp",i+1);

        buttonmodedejeu[i] = load_bitmap(nomfichier,NULL);
        if (!buttonexit[i])
        {
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }
    for (int i=0; i<4; i++)
    {
        sprintf(nomfichier,"images/menu/regle/regles%d.bmp",i+1);

        regles[i] = load_bitmap(nomfichier,NULL);
        if (!regles[i])
        {
            allegro_message("pas pu trouver %s",nomfichier);
            exit(EXIT_FAILURE);
        }
    }


    while(!key[KEY_ESC] && undermenu!=6)
    {

        if(songplaying==0)
        {
            //play_sample(menusong,150,123,1000,1);
            songplaying=1;
        }

        menutmpimg++;
        if (menutmpimg>=5)
        {
            menutmpimg=0;
            menuimg++;

            if (menuimg>=120)
            {
                menuimg=0;
            }
        }
        blit(fondmenu[menuimg],doublebuffer,0,0,0,0,1920,1080);

        switch(undermenu)
        {
            case 0:
            {
                //menu principal
                draw_sprite(doublebuffer,logo,778,80);//logo

                if(incmpt==1)
                {
                    cmpt++;
                }


                if((mouse_y>460 && mouse_y<581)&&(mouse_x>637 && mouse_x<920))//bouton lancer partie
                {
                    draw_sprite(doublebuffer,buttonstart[1],630,460);
                    if((mouse_b&1)==1)
                    {
                        draw_sprite(doublebuffer,buttonstart[2],630,460);
                        incmpt=1;

                    }
                    if(cmpt>=30)
                    {
                        incmpt=0;
                        cmpt=0;
                        undermenu=1;

                    }
                }
                else
                {
                    draw_sprite(doublebuffer,buttonstart[0],630,460);
                }

                if((mouse_y>460 && mouse_y<581)&&(mouse_x>987 && mouse_x<1270))//bouton charger une partie
                {
                    draw_sprite(doublebuffer,buttonload[1],980,460);
                    if((mouse_b&1)==1)
                    {
                        draw_sprite(doublebuffer,buttonload[2],980,460);
                        incmpt=1;
                    }
                    if(cmpt>=30)
                    {
                        incmpt=0;
                        cmpt=0;
                        undermenu=2;
                    }
                }
                else
                {
                    draw_sprite(doublebuffer,buttonload[0],980,460);
                }

                if((mouse_y>630 && mouse_y<758)&&(mouse_x>637 && mouse_x<920))//bouton regles
                {
                    draw_sprite(doublebuffer,buttonrules[1],630,630);
                    if((mouse_b&1)==1)
                    {
                        draw_sprite(doublebuffer,buttonrules[2],630,630);
                        incmpt=1;
                    }
                    if(cmpt>=30)
                    {
                        incmpt=0;
                        cmpt=0;
                        undermenu=3;
                    }
                }
                else
                {
                    draw_sprite(doublebuffer,buttonrules[0],630,630);
                }

                if((mouse_y>637 && mouse_y<758)&&(mouse_x>987 && mouse_x<1270))//bouton credits
                {
                    draw_sprite(doublebuffer,buttoncredits[1],980,630);
                    if((mouse_b&1)==1)
                    {
                        draw_sprite(doublebuffer,buttoncredits[2],980,630);
                        incmpt=1;
                    }
                    if(cmpt>=30)
                    {
                        incmpt=0;
                        cmpt=0;
                        undermenu=4;
                    }
                }
                else
                {
                    draw_sprite(doublebuffer,buttoncredits[0],980,630);
                }

                if((mouse_y>797 && mouse_y<918)&&(mouse_x>817 && mouse_x<1100))//bouton exit
                {
                    draw_sprite(doublebuffer,buttonexit[1],810,790);
                    if((mouse_b & 1)==1)
                    {
                        draw_sprite(doublebuffer,buttonexit[2],810,790);
                        incmpt=1;
                    }
                    if(cmpt>=30)
                    {
                        incmpt=0;
                        cmpt=0;
                        undermenu=5;
                    }
                }
                else
                {
                    draw_sprite(doublebuffer,buttonexit[0],810,790);
                }



                break;
            }
            case 1:
            {
                //lancer une game
                if(key[KEY_E])
                {
                    undermenu=0;
                }

                if (gamemode==0)//choix du mod de jeu
                {
                    draw_sprite(doublebuffer,buttonmodedejeu[0],0,0);
                    if((mouse_y>334 && mouse_y<685)&&(mouse_x>85 && mouse_x<930))//bouton exit
                    {
                        draw_sprite(doublebuffer,buttonmodedejeu[1],0,0);
                        if((mouse_b&1)==1)
                        {
                            ville->mode_jeu=0;
                            gamemode=1;
                        }
                    }
                    if((mouse_y>334 && mouse_y<685)&&(mouse_x>1000 && mouse_x<1800))//bouton exit
                    {
                        draw_sprite(doublebuffer,buttonmodedejeu[2],0,0);
                        if((mouse_b&1)==1)
                        {
                            ville->mode_jeu=1;
                            gamemode=1;
                        }
                    }

                    if(key[KEY_RCONTROL])//skip le mode de jeu
                    {
                        ville->mode_jeu=0;//communiste par default
                        gamemode=1;
                    }
                }

                //saisir nom de ville

                //permettre de skip le nom de ville
                if(key[KEY_LCONTROL])
                {
                    strcpy(ville->nom,"Paris");
                    *startgame=1;
                    undermenu=6;
                }

                break;
            }
            case 2:
            {
                //charger une sauvegarde
                chargementJoueur(ville);
                *startgame=1;
                undermenu=6;
                break;
            }
            case 3:
            {
                //regles
                if(key[KEY_E])
                {
                    undermenu=0;
                }

                if(incmpt==1)
                {
                    cmpt++;
                }

                draw_sprite(doublebuffer,regles[numregle],400,300);
                if((mouse_y>690 && mouse_y<730)&&(mouse_x>1370 && mouse_x<1420))
                {
                    if((mouse_b&1)==1 && incmpt==0)
                    {
                        numregle++;
                        incmpt=1;
                    }
                    if(cmpt>=30)
                    {
                        incmpt=0;
                        cmpt=0;
                    }

                }
                if(numregle>3)
                {
                    numregle=0;
                    undermenu=0;
                }
                break;

            }
            case 4:
            {
                //credits
                if(key[KEY_E])
                {
                    undermenu=0;
                }

                draw_sprite(doublebuffer,credits,0,0);
                if((mouse_y>782 && mouse_y<910)&&(mouse_x>1449 && mouse_x<1559))
                {
                    if((mouse_b&1)==1)
                    {
                        undermenu=0;
                    }
                }
                break;
            }
            case 5:
            {
                //quitter
                undermenu=6;
                *startgame=0;
                break;
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

