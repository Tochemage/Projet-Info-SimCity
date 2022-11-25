//
// Created by Clement on 17/11/2022.
//


#include "Header.h"

////////////////////////////////////////////////
/// CONSTRUCTION / DECONSTRUCTION BATIMENTS ///
//////////////////////////////////////////////


int poserbat(int batselected,BITMAP* doublebuffer, t_ville* maVille,BITMAP* maison,BITMAP* cabane,BITMAP* immeuble,BITMAP* gratteciel,BITMAP* usine,BITMAP* chateaudeau,BITMAP* route)
{

    if(batselected==1)
    {
        for(int i=0;i<40;i++)
        {
            for(int j=0;j<40;j++)
            {
                if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+j*20 && mouse_x<740+20+j*20) && i!=39 && j!=39 && i!=38 && j!=38 && maVille->map[i][j].habitation->type==0 && maVille->map[i+2][j].habitation->type==0 && maVille->map[i+1][j].habitation->type==0 && maVille->map[i+2][j+2].habitation->type==0 && maVille->map[i+1][j+1].habitation->type==0 && maVille->map[i][j+2].habitation->type==0 && maVille->map[i][j+1].habitation->type==0 && maVille->map[i+2][j+1].habitation->type==0 && maVille->map[i+1][j+2].habitation->type==0)
                {
                    draw_sprite(doublebuffer,cabane,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    //draw_sprite(doublebuffer,cabane,mouse_x,mouse_y);
                    if((mouse_b&1)==1 && maVille->map[i][j].habitation->type==0 && maVille->map[i+2][j].habitation->type==0 && maVille->map[i+1][j].habitation->type==0 && maVille->map[i+2][j+2].habitation->type==0 && maVille->map[i+1][j+1].habitation->type==0 && maVille->map[i][j+2].habitation->type==0 && maVille->map[i][j+1].habitation->type==0 && maVille->map[i+2][j+1].habitation->type==0 && maVille->map[i+1][j+2].habitation->type==0)
                    {
                        for(int k=0;i<3;i++)
                        {
                            for (int l = 0; j < 3; j++)
                            {
                                maVille->map[i+k][j+l].habitation->type = -1;
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
                if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+j*20 && mouse_x<740+20+j*20) && maVille->map[i][j].habitation->type==0)
                {
                    draw_sprite(doublebuffer,route,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    if((mouse_b&1)==1 && maVille->map[i][j].habitation->type==0)
                    {
                        maVille->map[i][j].habitation->type=7;
                        batselected=0;
                    }
                }
            }
        }
    }

    if(batselected==3)
    {
        for(int i=0;i<40;i++)
        {
            for(int j=0;j<40;j++)
            {
                if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+j*20 && mouse_x<740+20+j*20) && i!=39 && j!=39 && i!=38 && i!=37 &&j!=38 && j!=37 && j!=36 && j!=35  && maVille->map[i][j].habitation->type==0 && maVille->map[i+2][j].habitation->type==0 && maVille->map[i+1][j].habitation->type==0 && maVille->map[i+2][j+2].habitation->type==0 && maVille->map[i+1][j+1].habitation->type==0 && maVille->map[i][j+2].habitation->type==0 && maVille->map[i][j+1].habitation->type==0 && maVille->map[i+2][j+1].habitation->type==0 && maVille->map[i+1][j+2].habitation->type==0)
                {
                    draw_sprite(doublebuffer,usine,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    if((mouse_b&1)==1 && maVille->map[i][j].habitation->type==0 && maVille->map[i+2][j].habitation->type==0 && maVille->map[i+1][j].habitation->type==0 && maVille->map[i+2][j+2].habitation->type==0 && maVille->map[i+1][j+1].habitation->type==0 && maVille->map[i][j+2].habitation->type==0 && maVille->map[i][j+1].habitation->type==0 && maVille->map[i+2][j+1].habitation->type==0 && maVille->map[i+1][j+2].habitation->type==0)
                    {
                        for(int k=0;i<4;i++)
                        {
                            for (int l = 0; j < 6; j++)
                            {
                                maVille->map[i+k][j+l].habitation->type = -1;
                            }

                        }
                        maVille->map[i][j].habitation->type=5;
                        batselected=0;
                    }
                }
            }
        }
    }
    return batselected;
}