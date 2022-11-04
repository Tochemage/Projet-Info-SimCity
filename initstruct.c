//
// Created by theom on 04/11/2022.
//
#include "Header.h"

t_eau* initchateaueau()
{
    t_eau* chateaueau=(t_eau*)malloc(sizeof(t_eau));
    chateaueau->capa=5000;
    chateaueau->nbr_utilisation=0;
    return chateaueau;
}

t_electricite * initelec()
{
    t_electricite * centrale=(t_electricite*)malloc(sizeof(t_electricite));
    centrale->nbr_utilisation=0;
    centrale->electricite=5000;
    return centrale;
}

t_amelioration_TV * initamelTV()
{
    t_amelioration_TV * conditionamelterrain=(t_amelioration_TV*)malloc(sizeof(t_amelioration_TV));
    conditionamelterrain->electricite=0;
    conditionamelterrain->eau=0;
    return conditionamelterrain;
}

t_amelioration_C * initamelcab()
{
    t_amelioration_C * conditionamelcab=(t_amelioration_C*)malloc(sizeof(t_amelioration_C));
    conditionamelcab->electricite=10;
    conditionamelcab->eau=10;
    return conditionamelcab;;
}

t_amelioration_M * initamelmaison()
{
    t_amelioration_M * conditionamelmaison=(t_amelioration_M*)malloc(sizeof(t_amelioration_M));
    conditionamelmaison->eau=40;
    conditionamelmaison->electricite=40;
    return conditionamelmaison;
}

t_amelioration_I * initamelimmeuble()
{
    t_amelioration_I *conditionamelimmeuble=(t_amelioration_I*)malloc(sizeof(t_amelioration_I));
    conditionamelimmeuble->electricite=50;
    conditionamelimmeuble->eau=50;
    return conditionamelimmeuble;
}

t_amelioration_GC * initamelGC()
{
    t_amelioration_GC * conditionamelGC=(t_amelioration_GC*)malloc(sizeof(t_amelioration_GC));
    conditionamelGC->electricite=900;
    conditionamelGC->eau=900;
    return conditionamelGC;
}

t_batiment_hab * initbathab()
{
    t_batiment_hab * bathab=(t_batiment_hab*)malloc(sizeof(t_batiment_hab));
    bathab->taille=0;
    bathab->type=0;
    bathab->cout=1000;
    bathab->conso_eau=0;
    bathab->conso_elec=0;
    bathab->nbr_hab=0;
    bathab->nom_bat[0]='\0';
    bathab->nbr_cases_x=3;
    bathab->nbr_cases_y=4;
    return bathab;
}

t_batiment_prod * initbatprod()
{
    t_batiment_prod * batprod=(t_batiment_prod*)malloc(sizeof(t_batiment_prod));
    batprod->cout=100000;
    batprod->type=-1;
    batprod->nbr_cases_y=6;
    batprod->nbr_cases_x=4;
    return batprod;
}

t_route * initroute()
{
    t_route *route=(t_route*)malloc(sizeof(t_route));
    route->cout=10;
    route->nbr_cases_x=1;
    route->nbr_cases_y=1;
    return route;
}
