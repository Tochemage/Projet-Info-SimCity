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

    int batselected=0;// 1 pour une habitation, 2 pour une route, 3 pour une usine, 4 pour un chateau d'eau, 5 pour sup

    ///BITMAP///
    BITMAP* platjeu;
    BITMAP* fondjeu;

    ///batiments///
    BITMAP* maison;
    BITMAP* cabane;
    BITMAP* immeuble;
    BITMAP* gratteciel;
    BITMAP* usine;
    BITMAP* chateaudeau;

    BITMAP* route;

    //Joueur
    int click_x=-1, click_y=-1, selection=-1;

    platjeu = load_bitmap("images/jeu/plateau/platjeu.bmp",NULL);
    if (!platjeu)
    {
        allegro_message("pas pu trouver plateau de jeu");
        exit(EXIT_FAILURE);
    }

    fondjeu = load_bitmap("images/jeu/plateau/fondjeu.bmp",NULL);
    if (!fondjeu)
    {
        allegro_message("pas pu trouver fond du jeu");
        exit(EXIT_FAILURE);
    }

    maison = load_bitmap("images/jeu/plateau/sprite_maison.bmp",NULL);
    if (!maison)
    {
        allegro_message("pas pu trouver maison de jeu");
        exit(EXIT_FAILURE);
    }

    cabane = load_bitmap("images/jeu/plateau/sprite_cabane.bmp",NULL);
    if (!cabane)
    {
        allegro_message("pas pu trouver cabane de jeu");
        exit(EXIT_FAILURE);
    }

    immeuble = load_bitmap("images/jeu/plateau/sprite_immeuble.bmp",NULL);
    if (!immeuble)
    {
        allegro_message("pas pu trouver immeuble de jeu");
        exit(EXIT_FAILURE);
    }

    gratteciel = load_bitmap("images/jeu/plateau/gratte_ciel.bmp",NULL);
    if (!gratteciel)
    {
        allegro_message("pas pu trouver gratte ciel de jeu");
        exit(EXIT_FAILURE);
    }

    usine = load_bitmap("images/jeu/plateau/sprite_usine.bmp",NULL);
    if (!usine)
    {
        allegro_message("pas pu trouver usine de jeu");
        exit(EXIT_FAILURE);
    }

    route = load_bitmap("images/jeu/plateau/route.bmp",NULL);
    if (!route)
    {
        allegro_message("pas pu trouver route de jeu");
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
        blit(fondjeu,doublebuffer,0,0,0,0,1920,1080);
        masked_blit(platjeu,doublebuffer,0,0,0,0,1920,1080);

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

        if(key[KEY_P])
        {
            batselected++;
        }
        if(batselected==6)
        {
            batselected=0;
        }


        if(batselected==1)
        {
            for(int i=0;i<40;i++)
            {
                for(int j=0;j<40;j++)
                {
                    if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+j*20 && mouse_x<740+20+j*20) && i!=0 && i!=39 && j!=0 && j!=39)
                    {
                        draw_sprite(doublebuffer,cabane,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                        if(mouse_b&1==1 && maVille->map[i][j].habitation->type==0 && maVille->map[i-1][j].habitation->type==0 && maVille->map[i+1][j].habitation->type==0 && maVille->map[i-1][j-1].habitation->type==0 && maVille->map[i+1][j+1].habitation->type==0 && maVille->map[i][j-1].habitation->type==0 && maVille->map[i][j+1].habitation->type==0 && maVille->map[i-1][j+1].habitation->type==0 && maVille->map[i+1][j-1].habitation->type==0)
                        {
                            for(int k=0;i<3;i++)
                            {
                                for (int l = 0; j < 3; j++) {
                                    maVille->map[i-1+k][j-1+l].habitation->type = -1;
                                }

                            }
                            maVille->map[i][j].habitation->type=1;
                            batselected=0;
                        }
                    }
                }
            }
        }

        if(batselected==2)
        {
            for(int i=0;i<40;i++)
            {
                for(int j=0;j<40;j++)
                {
                    if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+j*20 && mouse_x<740+20+j*20))
                    {
                        draw_sprite(doublebuffer,route,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                        if(mouse_b&1==1 && maVille->map[i][j].habitation->type==0)
                        {
                            maVille->map[i][j].habitation->type=7;
                            batselected=0;
                        }
                    }
                }
            }
        }



        for(int i=0;i<40;i++)
        {
            for(int j=0;j<40;j++)
            {
                if(maVille->map[i][j].habitation->type==1)
                {
                    draw_sprite(doublebuffer,cabane,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                }
                if(maVille->map[i][j].habitation->type==7)
                {
                    draw_sprite(doublebuffer,route,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                }
                if(maVille->map[i][j].habitation->type==2)
                {
                    draw_sprite(doublebuffer,maison,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                }
                if(maVille->map[i][j].habitation->type==3)
                {
                    draw_sprite(doublebuffer,immeuble,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                }
                if(maVille->map[i][j].habitation->type==4)
                {
                    draw_sprite(doublebuffer,gratteciel,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                }
                if(maVille->map[i][j].habitation->type==5)
                {
                    draw_sprite(doublebuffer,usine,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
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


