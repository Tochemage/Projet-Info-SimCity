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

    //Exemples sauvegarde et chargement
    //sauvegardeJoueur(ville);
    //chargementJoueur(ville);
    /*printf("%d\n", ville->map[0][0].num_case);
    printf("%d\n", ville->map[0][0].type_case);
    printf("%d\n", ville->map[0][0].num_color);
    printf("%d\n", ville->map[0][0].num_case_x);
    printf("%d\n", ville->map[0][0].num_case_y);
    printf("%s\n", ville->map[0][0].habitation->nom_bat);
    printf("%d\n", ville->map[0][0].habitation->num_bat);
    printf("%d\n", ville->map[0][0].habitation->type);
    printf("%d\n", ville->map[0][0].habitation->apport_eau);
    printf("%d\n", ville->map[0][0].habitation->apport_elec);
    printf("%d\n", ville->map[0][0].habitation->nbr_hab);
    printf("%d\n", ville->map[0][0].industrie->num_bat);
    printf("%d\n", ville->map[0][0].industrie->type);
    printf("%s\n", ville->map[0][0].industrie->nom_bat);*/


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
