//
// Created by Clement on 17/11/2022.
//


#include "Header.h"

void canevolve(t_ville* maVille, t_infos* infos)
{
    for(int i=0;i<40;i++)
    {
        for(int j=0;j<40;j++)
        {
            if(maVille->map[i][j].habitation->type==1 || maVille->map[i][j].habitation->type==2 || maVille->map[i][j].habitation->type==3)
            {
                if(maVille->map[i][j].habitation->type==1)
                {
                    if(maVille->map[i][j].habitation->apport_eau >= infos->I_evolution.Evol_maison.eau && maVille->map[i][j].habitation->apport_elec>infos->I_evolution.Evol_maison.electricite)
                    {
                        maVille->map[i][j].habitation->type=2;
                        maVille->map[i][j].habitation->nbr_hab=infos->I_habitations.nb_hab_maison;
                    }
                }
                if(maVille->map[i][j].habitation->type==2)
                {
                    if(maVille->map[i][j].habitation->apport_eau >= infos->I_evolution.Evol_immeuble.eau && maVille->map[i][j].habitation->apport_elec>infos->I_evolution.Evol_immeuble.electricite)
                    {
                        maVille->map[i][j].habitation->type=3;
                        maVille->map[i][j].habitation->nbr_hab=infos->I_habitations.nb_hab_immeuble;
                    }
                }
                if(maVille->map[i][j].habitation->type==3)
                {
                    if(maVille->map[i][j].habitation->apport_eau >= infos->I_evolution.Evol_gratte_ciel.eau && maVille->map[i][j].habitation->apport_elec>infos->I_evolution.Evol_gratte_ciel.electricite)
                    {
                        maVille->map[i][j].habitation->type=4;
                        maVille->map[i][j].habitation->nbr_hab=infos->I_habitations.nb_hab_gratteCiel;
                    }
                }
            }
        }
    }
}

void devolve(t_ville* maVille, t_infos* infos)
{
    for(int i=0;i<40;i++)
    {
        for(int j=0;j<40;j++)
        {
            if(maVille->map[i][j].habitation->type==4 || maVille->map[i][j].habitation->type==2 || maVille->map[i][j].habitation->type==3)
            {
                if(maVille->map[i][j].habitation->type==4)
                {
                    if(maVille->map[i][j].habitation->apport_eau < infos->I_evolution.Evol_gratte_ciel.eau && maVille->map[i][j].habitation->apport_elec < infos->I_evolution.Evol_gratte_ciel.electricite)
                    {
                        maVille->map[i][j].habitation->type=3;
                    }
                }
                if(maVille->map[i][j].habitation->type==3)
                {
                    if(maVille->map[i][j].habitation->apport_eau < infos->I_evolution.Evol_immeuble.eau && maVille->map[i][j].habitation->apport_elec < infos->I_evolution.Evol_immeuble.electricite)
                    {
                        maVille->map[i][j].habitation->type=2;
                    }
                }
                if(maVille->map[i][j].habitation->type==2)
                {
                    if(maVille->map[i][j].habitation->apport_eau < infos->I_evolution.Evol_maison.eau && maVille->map[i][j].habitation->apport_elec < infos->I_evolution.Evol_maison.electricite)
                    {
                        maVille->map[i][j].habitation->type=1;
                    }
                }
            }
        }
    }
}