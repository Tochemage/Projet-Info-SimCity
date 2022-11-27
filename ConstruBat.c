//
// Created by Clement on 17/11/2022.
//


#include "Header.h"

////////////////////////////////////////////////
/// CONSTRUCTION / DECONSTRUCTION BATIMENTS ///
//////////////////////////////////////////////


int poserbat(int batselected,BITMAP* doublebuffer, t_ville* maVille,BITMAP* maison,BITMAP* cabane,BITMAP* immeuble,BITMAP* gratteciel,BITMAP* usine,BITMAP* chateaudeau,BITMAP* route, t_infos* mesInfos)
{
    int yaroute=0;
    if(batselected==1)//bat
    {
        for(int i=0;i<40;i++)
        {
            for(int j=0;j<40;j++)
            {
                if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+j*20 && mouse_x<740+20+j*20) && i!=39 && j!=39 && i!=38 && j!=38 && j!=37 && i!=37 && j!=0 && i!=0 && maVille->map[i][j].habitation->type==0 && maVille->map[i+2][j].habitation->type==0 && maVille->map[i+1][j].habitation->type==0 && maVille->map[i+2][j+2].habitation->type==0 && maVille->map[i+1][j+1].habitation->type==0 && maVille->map[i][j+2].habitation->type==0 && maVille->map[i][j+1].habitation->type==0 && maVille->map[i+2][j+1].habitation->type==0 && maVille->map[i+1][j+2].habitation->type==0)
                {
                    draw_sprite(doublebuffer,cabane,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    if((mouse_b&1)==1)
                    {
                        yaroute=isroute(batselected,maVille,i,j);
                        if(yaroute==1 && mesInfos->I_habitations.cout<maVille->argent)
                        {
                            for(int k=0;k<3;k++)
                            {
                                yaroute=0;
                                for (int l = 0; l < 3; l++)
                                {
                                    maVille->map[i+k][j+l].habitation->type = -1;
                                }
                            }
                            maVille->map[i][j].habitation->type=1;
                            maVille->map[i][j].habitation->nbr_hab=mesInfos->I_habitations.nb_hab_cabane;
                            //maVille->map[i][j].habitation->num_bat=;
                            maVille->argent-= mesInfos->I_habitations.cout;
                            batselected=0;
                        }
                    }
                }
            }
        }
    }

    if(batselected==2)  //Route
    {
        for(int i=0;i<40;i++)
        {
            for(int j=0;j<40;j++)
            {
                if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+j*20 && mouse_x<740+20+j*20) && maVille->map[i][j].habitation->type==0)
                {
                    draw_sprite(doublebuffer,route,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    if((mouse_b&1)==1 && maVille->map[i][j].habitation->type==0 && mesInfos->I_routes.cout<maVille->argent)
                    {
                        maVille->map[i][j].habitation->type = 7;
                        maVille->argent-=mesInfos->I_routes.cout;
                        //batselected = 0;
                    }
                }
            }
        }
    }

    if(batselected==4)//usine
    {
        for(int i=0;i<NB_LIGNES;i++)
        {
            for(int j=0;j<NB_COLONNES;j++)
            {
                if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+j*20 && mouse_x<740+20+j*20) && i!=39  && i!=38 && i!=37 && i!=36 && i!=0 && j!=0 && j!=39 && j!=38 && j!=37 && j!=36 && j!=35 && j!=34 && maVille->map[i][j].habitation->type==0 && maVille->map[i+2][j].habitation->type==0 && maVille->map[i+1][j].habitation->type==0 && maVille->map[i+2][j+2].habitation->type==0 && maVille->map[i+1][j+1].habitation->type==0 && maVille->map[i][j+2].habitation->type==0 && maVille->map[i][j+1].habitation->type==0 && maVille->map[i+2][j+1].habitation->type==0 && maVille->map[i+1][j+2].habitation->type==0 && maVille->map[i+3][j].habitation->type==0 && maVille->map[i][j+4].habitation->type==0 && maVille->map[i][j+5].habitation->type==0 && maVille->map[i][j+3].habitation->type==0 && maVille->map[i+3][j+1].habitation->type==0 && maVille->map[i+3][j+2].habitation->type==0 && maVille->map[i+3][j+3].habitation->type==0 && maVille->map[i+3][j+4].habitation->type==0 && maVille->map[i+3][j+5].habitation->type==0 && maVille->map[i+2][j+4].habitation->type==0)
                {
                    draw_sprite(doublebuffer,usine,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    if((mouse_b&1)==1 && maVille->map[i][j].habitation->type==0 && maVille->map[i+2][j].habitation->type==0 && maVille->map[i+1][j].habitation->type==0 && maVille->map[i+2][j+2].habitation->type==0 && maVille->map[i+1][j+1].habitation->type==0 && maVille->map[i][j+2].habitation->type==0 && maVille->map[i][j+1].habitation->type==0 && maVille->map[i+2][j+1].habitation->type==0 && maVille->map[i+1][j+2].habitation->type==0)
                    {
                        yaroute=isroute(batselected,maVille,i,j);
                        if(yaroute==1 && mesInfos->I_industries.cout<maVille->argent)
                        {
                            yaroute = 0;
                            for (int k = 0; k < 4; k++)
                            {
                                for (int l = 0; l < 6; l++)
                                {
                                    maVille->map[i + k][j + l].habitation->type = -1;
                                }

                            }
                            maVille->map[i][j].habitation->type = 5;
                            maVille->argent-=mesInfos->I_industries.cout;
                            batselected=0;
                        }

                    }
                }
            }
        }
    }

    if(batselected==3)//chateau d'eau
    {
        for(int i=0;i<NB_LIGNES;i++)
        {
            for(int j=0;j<NB_COLONNES;j++)
            {
                if((mouse_y>234+i*20 && mouse_y<234+20+i*20)&&(mouse_x>740+j*20 && mouse_x<740+20+j*20) && i!=39 && j!=39 && i!=38 && i!=37 &&j!=38 && j!=37 && j!=36 && j!=35 && i!=0 && j!=0 && maVille->map[i][j].habitation->type==0 && maVille->map[i+2][j].habitation->type==0 && maVille->map[i+1][j].habitation->type==0 && maVille->map[i+2][j+2].habitation->type==0 && maVille->map[i+1][j+1].habitation->type==0 && maVille->map[i][j+2].habitation->type==0 && maVille->map[i][j+1].habitation->type==0 && maVille->map[i+2][j+1].habitation->type==0 && maVille->map[i+1][j+2].habitation->type==0 && maVille->map[i+3][j].habitation->type==0 && maVille->map[i+4][j].habitation->type==0 && maVille->map[i+5][j].habitation->type==0 && maVille->map[i][j+3].habitation->type==0 && maVille->map[i+1][j+3].habitation->type==0 && maVille->map[i+2][j+3].habitation->type==0 && maVille->map[i+3][j+3].habitation->type==0 && maVille->map[i+4][j+3].habitation->type==0 && maVille->map[i+5][j+3].habitation->type==0 && maVille->map[i+4][j+2].habitation->type==0)
                {
                    draw_sprite(doublebuffer,chateaudeau,maVille->map[i][j].num_case_x,maVille->map[i][j].num_case_y);
                    if((mouse_b&1)==1 && maVille->map[i][j].habitation->type==0 && maVille->map[i+2][j].habitation->type==0 && maVille->map[i+1][j].habitation->type==0 && maVille->map[i+2][j+2].habitation->type==0 && maVille->map[i+1][j+1].habitation->type==0 && maVille->map[i][j+2].habitation->type==0 && maVille->map[i][j+1].habitation->type==0 && maVille->map[i+2][j+1].habitation->type==0 && maVille->map[i+1][j+2].habitation->type==0)
                    {
                        yaroute=isroute(batselected,maVille,i,j);
                        if(yaroute==1 && mesInfos->I_industries.cout<maVille->argent)
                        {
                            yaroute = 0;
                            for (int k = 0; k < 4; k++)
                            {
                                for (int l = 0; l < 6; l++)
                                {
                                    maVille->map[i + l][j + k].habitation->type = -1;
                                }

                            }
                            maVille->map[i][j].habitation->type = 6;
                            maVille->argent-=mesInfos->I_industries.cout;
                            batselected=0;
                        }

                    }
                }
            }
        }
    }
    return batselected;
}


int isroute(int batselected, t_ville* maVille,int coord_x,int coord_y)
{

    switch(batselected)
    {
        case 1:
        {
            for(int i=0;i<3;i++)
            {
                if(maVille->map[coord_x-1][coord_y+i].habitation->type==7 || maVille->map[coord_x+i][coord_y-1].habitation->type==7 || maVille->map[coord_x+3][coord_y+i].habitation->type==7 || maVille->map[coord_x+i][coord_y+3].habitation->type==7)
                {
                    return 1;
                }
            }
            break;
        }
        case 3:
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<6;j++)
                {
                    if(maVille->map[coord_x-1][coord_y+j].habitation->type==7 || maVille->map[coord_x+i][coord_y-1].habitation->type==7 || maVille->map[coord_x+4][coord_y+j].habitation->type==7 || maVille->map[coord_x+i][coord_y+6].habitation->type==7)
                    {
                        return 1;
                    }
                }
            }
            break;
        }
        case 4:
        {
            for(int i=0;i<6;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(maVille->map[coord_x-1][coord_y+j].habitation->type==7 || maVille->map[coord_x+i][coord_y-1].habitation->type==7 || maVille->map[coord_x+4][coord_y+j].habitation->type==7 || maVille->map[coord_x+i][coord_y+6].habitation->type==7)
                    {
                        return 1;
                    }
                }
            }
            break;
        }
    }
    return 0;
}