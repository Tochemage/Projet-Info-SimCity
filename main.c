#include "Header.h"

int main() {


    AllegroInit();

    BITMAP *doublebuffer;

    doublebuffer=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(doublebuffer);



    ///Declarations de variables///
    t_ville* ville = (t_ville*)malloc(sizeof(t_ville));
    t_infos* infoVille = (t_infos*)malloc(sizeof(t_infos));
    int ingame=0;
    int *startgame=NULL;
    startgame=&ingame;


    ///Initialisations///
    sp_init_struct(ville, infoVille);   //Sp d'initialisation des structures


    /// A RETIRER !!! ///
    sauvegardeJoueur(ville);


    do{
    menu(doublebuffer,startgame,ville);
    printf("out menu");

    if(ingame==1)
    {
        bouclejeu(doublebuffer, ville, infoVille,startgame);
    }
    printf("out jeu");
    }while(ingame==1);

    destroy_bitmap(doublebuffer);
    allegro_exit();
    //getchar();


    return 0;
}END_OF_MAIN()
