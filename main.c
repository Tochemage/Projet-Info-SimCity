#include "Header.h"

int main() {

    AllegroInit();

    BITMAP *doublebuffer;

    doublebuffer=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(doublebuffer);

    while(!key[KEY_ESC])
    {

        show_mouse(doublebuffer);
        blit(doublebuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(10);
    }

    destroy_bitmap(doublebuffer);
    allegro_exit();
    return 0;
}END_OF_MAIN()
