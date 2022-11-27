//
// Created by theom on 17/11/2022.
//

#include "Header.h"

////////////////////////////
/// BOUCLE DE JEU ET SP ///
//////////////////////////


void bouclejeu(BITMAP* doublebuffer, t_ville* maVille, t_infos* infos, int* startgame)
{

    ///DECLARATIONS///

    ///Variables///
    //Temps
    int ingame=1;
    float clk1=0,clk2=0,clktot=0;
    int cmptpause=0;

    int batselected=0;// 1 pour une habitation, 2 pour une route, 3 pour une usine, 4 pour un chateau d'eau, 5 pour sup
    int niveauselec=0;// 0 pour normal, 1 pour l'eau, -1 pour elec
    int destructselec=0;// choisir de detruire ou pas
    ///Variables a base de structure///
    t_case* case_temp=NULL;

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
    BITMAP* route_elec;
    BITMAP* route_eau;

    ///Police///
    FONT* police;

    police=load_font("police.pcx", NULL, NULL);

    //Joueur
    int click_x=-1, click_y=-1, selection=-1;

    platjeu = load_bitmap("images/jeu/plateau/platjeu2.bmp",NULL);
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

    chateaudeau = load_bitmap("images/jeu/plateau/chateaudeau.bmp",NULL);
    if (!chateaudeau)
    {
        allegro_message("pas pu trouver chateau d'eau de jeu");
        exit(EXIT_FAILURE);
    }

    route = load_bitmap("images/jeu/plateau/route.bmp",NULL);
    if (!route)
    {
        allegro_message("pas pu trouver route de jeu");
        exit(EXIT_FAILURE);
    }

    route_eau = load_bitmap("images/jeu/plateau/route_eau.bmp",NULL);
    if (!route_eau)
    {
        allegro_message("pas pu trouver route de jeu");
        exit(EXIT_FAILURE);
    }

    route_elec = load_bitmap("images/jeu/plateau/route_elec.bmp",NULL);
    if (!route_elec)
    {
        allegro_message("pas pu trouver route de jeu");
        exit(EXIT_FAILURE);
    }




    ///BOUCLE DE JEU///
    while(!key[KEY_ESC] && ingame==1 && *startgame==1)
    {
        ///PRISE DU TEMPS 1///
        clk1=clock()/CLOCKS_PER_SEC;
        if(clktot>=15)//compteur de temps en mois toute les 15 sec
        {
            maVille->nbr_mois_jeu++;
            maVille->argent += (maVille->nbr_habitants * maVille->impots);
            devolve(maVille,infos);
            canevolve(maVille,infos);

            //printf("%d\n",cmptmois);
            clktot=0;
        }
        blit(fondjeu,doublebuffer,0,0,0,0,1920,1080);
        masked_blit(platjeu,doublebuffer,0,0,0,0,1920,1080);
        afficherdonnees(doublebuffer,maVille);


        /// Affichage coordonnées souris ///
        //textprintf_ex(doublebuffer,font,3,0,makecol(255,255,255),makecol(0,0,0),"%d %d",mouse_x, mouse_y);

        ///boutons de selection///

        //bouton menu

        if((mouse_y>6 && mouse_y<73)&&(mouse_x>48 && mouse_x<330))
        {
            if((mouse_b&1)==1)
            {
                rest(5);
                ingame=0;
                break;
                //retour au menu
            }
        }

        //bouton save

        if((mouse_y>6 && mouse_y<79)&&(mouse_x>495 && mouse_x<952))
        {
            rest(5);
            if((mouse_b&1)==1)
            {
                //save partie on appelle un sous prog qui enregistre tout
                sauvegardeJoueur(maVille);
            }
        }
        //bouton quitter
        if((mouse_y>5 && mouse_y<75)&&(mouse_x>1256 && mouse_x<1712))
        {
            rest(5);
            if((mouse_b&1)==1)
            {
                *startgame=0;
                ingame=0;
                //*startgame=0;
            }
        }

        //bouton placer bat
        if((mouse_y>222 && mouse_y<286)&&(mouse_x>27 && mouse_x<346))
        {
            if((mouse_b&1)==1)
            {

                if(batselected==1)
                {
                    batselected=0;
                }
                else
                {
                    destructselec=0;
                    batselected=1;
                }
                rest(50);
            }
        }

        //bouton placer route
        if((mouse_y>319 && mouse_y<383)&&(mouse_x>27 && mouse_x<346)&&cmptpause==0)
        {
            if(mouse_b & 1)
            {

                if(batselected==2)
                {
                    batselected=0;
                }
                else
                {
                    destructselec=0;
                    batselected=2;
                }
                rest(50);
            }
        }
        //bouton placer chateau d'eau
        if((mouse_y>417 && mouse_y<481)&&(mouse_x>27 && mouse_x<346)&&cmptpause==0)
        {
            if((mouse_b&1)==1)
            {

                if(batselected==3)
                {
                    batselected=0;
                }
                else
                {
                    destructselec=0;
                    batselected=3;
                }
                rest(50);
            }
        }
        //bouton placer usine
        if((mouse_y>511 && mouse_y<576)&&(mouse_x>27 && mouse_x<346)&&cmptpause==0)
        {
            if((mouse_b&1)==1)
            {

                if(batselected==4)
                {
                    batselected=0;
                }
                else
                {
                    destructselec=0;
                    batselected=4;
                }
                rest(50);
            }
        }

        //bouton 0
        if((mouse_y>606 && mouse_y<671)&&(mouse_x>27 && mouse_x<346))
        {
            if((mouse_b&1)==1)
            {
                rest(50);
                niveauselec=0;
            }
        }
        //bouton -1
        if((mouse_y>707 && mouse_y<773)&&(mouse_x>27 && mouse_x<346))
        {
            if((mouse_b&1)==1)
            {
                rest(50);
                niveauselec=1;
            }
        }
        //bouton -2
        if((mouse_y>816 && mouse_y<880)&&(mouse_x>27 && mouse_x<346))
        {
            if((mouse_b&1)==1)
            {
                rest(50);
                niveauselec=2;
            }
        }

        //bouton pause
        if((mouse_y>906 && mouse_y<970)&&(mouse_x>27 && mouse_x<346))
        {
            if((mouse_b&1)==1)
            {
                if(cmptpause==0)
                {
                    cmptpause=1;
                }
                else
                {
                    cmptpause=0;
                }
                rest(50);
            }
        }

        if(cmptpause == 1)
        {
            textout_ex(doublebuffer,police,"PAUSE",960,540, makecol(0,0,0),-1);
        }


        //bouton suppr batiment
        if((mouse_y>976 && mouse_y<1074)&&(mouse_x>284 && mouse_x<346))
        {
            if((mouse_b&1)==1)
            {
                if(destructselec==0)
                {
                    destructselec=1;
                    batselected=0;
                }
                else
                {
                    destructselec=0;
                }
                rest(50);
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

        batselected=poserbat(batselected,doublebuffer,maVille,maison,cabane,immeuble, gratteciel,usine,chateaudeau,route,infos);



        detruirebat(maVille,destructselec);

        if(niveauselec==0)
        {
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
                        draw_sprite(doublebuffer,maison,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y-20);
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
                    if(maVille->map[i][j].habitation->type==6)
                    {
                        draw_sprite(doublebuffer,chateaudeau,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    }
                }
            }
        }

        if(niveauselec==1)
        {
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
                        draw_sprite(doublebuffer,route_eau,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    }
                    if(maVille->map[i][j].habitation->type==2)
                    {
                        draw_sprite(doublebuffer,maison,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y-20);
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
                    if(maVille->map[i][j].habitation->type==6)
                    {
                        draw_sprite(doublebuffer,chateaudeau,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    }
                }
            }
        }

        if(niveauselec==2)
        {
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
                        draw_sprite(doublebuffer,route_elec,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    }
                    if(maVille->map[i][j].habitation->type==2)
                    {
                        draw_sprite(doublebuffer,maison,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y-20);
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
                    if(maVille->map[i][j].habitation->type==6)
                    {
                        draw_sprite(doublebuffer,chateaudeau,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    }
                }
            }
        }

        ///CALCUL DONNEES JOUEUR///
        ingame = calcul_data_J(maVille, infos);
        //tothab(maVille);


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
            if((click_x > ville->map[i][j].num_case_x) && (click_x < ville->map[i+1][j+1].num_case_x)  &&  (click_y > ville->map[i][j].num_case_y) && (click_y < ville->map[i+1][j+1].num_case_y))
            {
                case_recherchee = &ville->map[i][j];
                return case_recherchee;
            }
        }
    }
    return NULL;
}

void afficherdonnees(BITMAP* doublebuffer,t_ville *maVille)
{
    FONT *police = load_font("images/font/police.pcx",NULL,NULL);
    if(!police)
        allegro_message("Erreur chargement police");

    textprintf_ex(doublebuffer,police,330,120,makecol(0,0,0),-1,"%ld",maVille->argent);
    textprintf_ex(doublebuffer,police,700,120,makecol(0,0,0),-1,"%d",maVille->nbr_mois_jeu);
    textprintf_ex(doublebuffer,police,1042,120,makecol(0,0,0),-1,"%d",maVille->nbr_habitants);
    textprintf_ex(doublebuffer,police,1315,129,makecol(0,0,0),-1,"%d",maVille->capa_elec);
    textprintf_ex(doublebuffer,police,1650,120,makecol(0,0,0),-1,"%d",maVille->capa_eau);

}

void tothab(t_ville* maVille)
{
    int habtot=0;
    for(int i=0; i<NB_LIGNES; i++)
    {
        for (int j = 0; j < NB_COLONNES; j++)
        {
            if(maVille->map[i][j].habitation->type==4 || maVille->map[i][j].habitation->type==2 || maVille->map[i][j].habitation->type==3 || maVille->map[i][j].habitation->type==1)
            {
                habtot+=maVille->map[i][j].habitation->nbr_hab;
            }
        }
    }
    maVille->nbr_habitants=habtot;
}




/*
int detectionClick(int click_x, int click_y)    //Renvoie un entier permettant de savoir sur quoi le joueur a clique -> (-1:Rien    0:Construire un batiment   1:VisionEtage  2:Menu   3:Sauvegarde    4:quitter)

int detectionClick(int click_x, int click_y)    //Renvoie un entier permettant de savoir sur quoi le joueur a clique -> (-1:Rien    0:Construire un batiment   1:Données bat  2:VisionEtage   3:Sauvegarde    4:quitter)
{
    //A FAIRE                                                       NEED ALLEGRO

    if(mouse sur construire un batiment) //quel que soit le batiment
    {
        return 0;
    }
    if(mouse sur icone vision etage)
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


/* BONUS
case_temp = recherche_case_selec(maVille, click_x, click_y);
//BONUS Allegro : afficher les données de case_temp
*/

///INTERACTIONS JOUEUR///
/*
if((mouse_b&1)==1)    //Permet de savoir sur quelle icone le joueur a cliqué
{
    ///Detection et analyse
    click_x = mouse_x;
    click_y = mouse_y;
    //selection = detectionClick(click_x, click_y);
    //(-1:Rien    0:Construire un batiment   1:Données bat  2:VisionEtage   3:Sauvegarde    4:quitter)

    ///Appel des sous-programmes
    if(selection==0)    //Construction batiment
    {
        //appel fonction constru bat en envoyant click_x et click_y pour detecter ensuite quel bat il veut construire
    }
    if(selection==1)    //Voir données batiment sur cette case
    {

    }
    if(selection==2)    //Voir autres étages (eau, elec)
    {
        //appeler vision autres étages                                              NEED ALLEGRO
    }
    if(selection==3)
    {
        //Appeler programme de sauvegarde
    }
    if(selection==4)
    {

    }
}*/
