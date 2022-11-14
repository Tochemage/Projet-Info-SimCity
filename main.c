#include "Header.h"

int main() {


    AllegroInit();

    BITMAP *doublebuffer;

    doublebuffer=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(doublebuffer);



    ///Declarations de variables///
    t_ville* ville = (t_ville*)malloc(sizeof(t_ville));
    t_infos* infoVille = (t_infos*)malloc(sizeof(t_infos));

    ///Initialisations///
    sp_init_struct(ville, infoVille);   //Sp d'initialisation des structures


    while(!key[KEY_ESC])
    {
        menu(doublebuffer);



        show_mouse(doublebuffer);
        blit(doublebuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(10);
    }

    destroy_bitmap(doublebuffer);
    allegro_exit();



    return 0;
}END_OF_MAIN()
