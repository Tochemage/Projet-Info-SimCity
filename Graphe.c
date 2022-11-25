//
// Created by Clement on 17/11/2022.
//


#include "Header.h"

////////////////////////////
///PROGRAMME DES GRAPHES///
//////////////////////////

/*
///BFS///
void graphe_BFS(t_ville* ville, t_infos* infos)
{

}

 */






/*****************************************************************************************/
/*****************************************************************************************/

/**  PROGRAMMES DE GRAPHE DU TP2 DE CLEMENT ET THEO  **/
//En plus au cas où on ait besoin mais il faudra adapter


/** GESTION DE GRAPHE **/
/*
 //affichage des successeurs du sommet num
void afficher_successeurs(pSommet * sommet, int num)
{

    printf(" sommet %d :\n",num);

    pArc arc=sommet[num]->arc;

    while(arc!=NULL)
    {
        printf("%d ",arc->sommet);
        arc=arc->arc_suivant;
    }

}

// Ajouter l'ar�te entre les sommets s1 et s2 du graphe
pSommet* CreerArete(pSommet* sommet,int s1,int s2)
{
    if(sommet[s1]->arc==NULL)
    {
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        return sommet;
    }

    else
    {
        pArc temp=sommet[s1]->arc;
        while( !(temp->arc_suivant==NULL))
        {
            temp=temp->arc_suivant;
        }
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;

        if(temp->sommet>s2)
        {
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->sommet=temp->sommet;
            temp->sommet=s2;
            temp->arc_suivant=Newarc;
            return sommet;
        }

        temp->arc_suivant=Newarc;
        return sommet;
    }
}

///Pgrm Cl�ment pour retirer une arete pour le pgrm de chaine/cycle eulerien
pSommet* RetirerArete(pSommet* sommet,int s1,int s2)
{
    //int dejafait=0; //Variable qui sert � indiquer aux conditions "if" si l'arc a d�j� �t� retir� ou non
    if((sommet[s1]->arc->arc_suivant)==NULL)    //Si le sommet 1 n'a pas d'autres aretes
    {
        sommet[s1]->arc=NULL;
        return sommet;
        //dejafait=1;
    }
    else if((sommet[s1]->arc->sommet)==s2)   //Si l'arc � retirer est celui sur lequel l'arc du sommet 1 pointe
    {
        sommet[s1]->arc=sommet[s1]->arc->arc_suivant;
        return sommet;
        //dejafait=1;
    }
    else    //Si l'arc � retirer est dans les arcs suivants de l'arc sur lequel le sommet 1 pointe
    {
        pArc temp=sommet[s1]->arc;
        while((temp->arc_suivant->sommet)!=s2) //On cherche l'arc juste avant celui qu'il faut retirer
        {
            temp=temp->arc_suivant;
        }
        temp->arc_suivant=temp->arc_suivant->arc_suivant;
    }
    return sommet;
}



// cr�er le graphe
Graphe* CreerGraphe(int ordre)
{
    Graphe * Newgraphe=(Graphe*)malloc(sizeof(Graphe));
    Newgraphe->pSommet = (pSommet*)malloc(ordre*sizeof(pSommet));

    for(int i=0; i<ordre; i++)
    {
        Newgraphe->pSommet[i]=(pSommet)malloc(sizeof(struct Sommet));
        Newgraphe->pSommet[i]->numNoeud=i;
        Newgraphe->pSommet[i]->arc=NULL;
    }
    return Newgraphe;
}


// La construction du r�seau peut se faire � partir d'un fichier dont le nom est pass� en param�tre
//Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs
Graphe * lire_graphe(char * nomFichier)
{
    Graphe* graphe;
    FILE * ifs = fopen(nomFichier,"r");
    int taille, orientation, ordre, s1, s2;

    if (!ifs)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre);

    graphe=CreerGraphe(ordre); // cr�er le graphe d'ordre sommets

    fscanf(ifs,"%d",&taille);
    fscanf(ifs,"%d",&orientation);

    graphe->orientation=orientation;
    graphe->ordre=ordre;

    // cr�er les ar�tes du graphe
    for (int i=0; i<taille; ++i)
    {
        fscanf(ifs,"%d%d",&s1,&s2);
        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2);

        if(!orientation)
            graphe->pSommet=CreerArete(graphe->pSommet, s2, s1);
    }

    return graphe;
}

//affichage du graphe avec les successeurs de chaque sommet
void graphe_afficher(Graphe* graphe)
{
    printf("graphe\n");

    if(graphe->orientation)
        printf("oriente\n");
    else
        printf("non oriente\n");

    printf("ordre = %d\n",graphe->ordre);

    printf("listes d'adjacence :\n");

    for (int i=0; i<graphe->ordre; i++)
    {
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }

}
 */


/** BFS(parcours largeur) et DFS(parcours longueur) + COMPOSANTES CONNEXES **/

/*
void InitialParcourLongueur(Graphe* graphee, int taille)
{
    //Initialisation de la couleur des sommets
    //N=Noir, deja vu.  B=Blanc a voir
    printf("\n***DFS***\n");
    int start;
    printf("saisir le premier sommet:\n");
    scanf("%d",&start);
    printf("\n");
    int i;
    pSommet* graphe=graphee->pSommet;
    for(i=0;i<taille;i++){
        graphe[i]->couleur='B';
    }

    i=start;
    if(graphe[i]->couleur=='B'){
        printf("%d,",graphe[i]->valeur);
        graphe[i]->couleur='N';
        pArc Temparc=graphe[i]->arc;
        while(!(Temparc==NULL)){
            ParcourLongueur(graphe,Temparc->sommet,taille);
            Temparc=Temparc->arc_suivant;
        }
    }
    printf("\n");

    //}
    return;
}


void ParcourLongueur(pSommet* graphe,int s, int taille)
{
    if(graphe[s]->couleur=='B'){
        printf("%d,",graphe[s]->valeur);
        graphe[s]->couleur='N';
        pArc Temparc=graphe[s]->arc;
        while(!(Temparc==NULL)){
            ParcourLongueur(graphe,Temparc->sommet,taille);
            Temparc=Temparc->arc_suivant;
        }
    }
    return;
}




void InitialParcourLargeur_(Graphe* graphee, int taille)
{
    //Initialisation de la couleur des sommets
    //N=Noir, deja vu.  B=Blanc a voir
    printf("\n***BFS***\n");
    int i=0;
    File file=fileVide();
    pSommet* graphe=graphee->pSommet;

    int start;
    printf("saisir le premier sommet:\n");
    scanf("%d",&start);
    printf("\n");

    for(i=0;i<taille;i++)
    {
        graphe[i]->couleur='B';
    }
    enfiler(file,start);

    while(longueur(file))
    {
        i=defilement(file);
        if(graphe[i]->couleur=='B')
        {
            pArc Temparc=graphe[i]->arc;
            if(Temparc!=NULL)
            {
                enfiler(file,Temparc->sommet);
                while(Temparc->arc_suivant!=NULL)
                {
                    Temparc=Temparc->arc_suivant;
                    enfiler(file,Temparc->sommet);
                }
            }
            printf("%d,",graphe[i]->valeur);
            graphe[i]->couleur='N';
        }
    }
    printf("\n");
}




void composantes_connexes(Graphe* g)
{
    printf("\n***composantes connexes***\n");
    int taille=g->ordre,j=0;
    pSommet* graphe=g->pSommet;
    for(int i=0;i<taille;i++)
    {
        graphe[i]->couleur='B';
    }
    for(int i=0;i<taille;i++)
    {
        if(graphe[i]->couleur=='B')
        {

            graphe[i]->couleur='N';
            pArc Temparc=graphe[i]->arc;
            if(Temparc!=NULL)
            {
                printf("\n\ncomposante connexes %d:\n\n",j+1);
                printf("%d,",graphe[i]->valeur);
                j++;
                while(!(Temparc==NULL))
                {
                    ParcourLongueur(graphe,Temparc->sommet,taille);
                    Temparc=Temparc->arc_suivant;
                }
            }
            else
            {
                printf("\n\ncomposante connexes %d:\n\n",j+1);
                printf("%d,",graphe[i]->valeur);
                j++;
            }
        }
    }
    printf("\n\n");
}




void ParcourLongueurDeux(pSommet* graphe,int s, int taille)
{
    if(graphe[s]->couleur=='B'){
        graphe[s]->couleur='N';
        pArc Temparc=graphe[s]->arc;
        RetirerArete(graphe, s, graphe[s]->arc->sommet);
        while(!(Temparc==NULL)){
            ParcourLongueurDeux(graphe,Temparc->sommet,taille);
            Temparc=Temparc->arc_suivant;
        }
    }
    return;
}

*/







 /** SOUS PROGRAMMES DE FILE + HEADER DE FILE ET DE CELLULE (pour faire marcher les files et les sp de graphe) **/

 /*
 #include "Graphe.h"
#include "cellule.h"
#include "fifo.h"

File fileVide() {
   File F;
   F = (File)malloc(sizeof(struct _file));
   if (F == NULL) printf("erreur allocation fileVide");
   F->longueur = 0;
   F->tete = F->queue = NULL;
   return(F);
}

int longueur(File F) {
   if (F == NULL)printf("file existe pas - longueur");
   return(F->longueur);
}

void enfiler(File F, typage element) {
   Cellule cellule;
   if (F == NULL) printf ("file existe pas - enfiler");

   cellule = (Cellule)malloc(sizeof(struct _cellule));
   if (cellule == NULL) printf("erreur allocation memoire - enfiler");
   cellule->element = element;
   cellule->suivant = NULL;
   if (longueur(F) == 0){
      F->tete = F->queue = cellule;
   }
   else {
     F->queue->suivant = cellule;
     F->queue = cellule;
   }
   ++(F->longueur);
}

typage tete(File F) {
   if (F == NULL || longueur(F) == 0) printf(" File existe pas - tete");
   return(F->tete->element);
}

void defiler(File F) {
   Cellule cellule;

   if (F == NULL || longueur(F) == 0)printf("File existe pas - defiler");
      cellule = F->tete;
   if (longueur(F) == 1)
      F->tete = F->queue = NULL;
   else
      F->tete = F->tete->suivant;
   --(F->longueur);
   free(cellule);
}

typage defilement(File F) {
   Cellule cellule;
   typage element;
   if (F == NULL || longueur(F) == 0) printf("File existe pas - defilement");
   cellule = F->tete;
   element = cellule->element;
   if (longueur(F) == 1){
      F->tete = F->queue = NULL;
   }
   else{
      F->tete = F->tete->suivant;
   }
   free(cellule);
   --(F->longueur);
   return(element);
}


void ecrireFile(File F) {
   Cellule cellule;

   if (F == NULL) printf("erreur ecrireFile");
   cellule = F->tete;
   while (cellule != NULL) {
      printf("%d ", cellule->element->numNoeud);
      cellule = cellule->suivant;
   }
   printf("\n");
}
  */




 /* HEADER fifo.h */

 /*
 #ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED



struct _file {
   int longueur;
   Cellule tete;
   Cellule queue;
};

typedef struct _file* File;

#define fileEstVide(F) ((F)->longueur == 0)

File fileVide();
int longueur(File F);
void enfiler(File F, typage element);
typage tete(File F);
void defiler(File F);
typage defilement(File F);
void ecrireFile(File F);




#endif // FIFO_H_INCLUDED

  */



/* HEADER cellule.h */

/*
 #ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED


typedef pSommet typage;

struct _cellule {
   typage element;
   struct _cellule *suivant;
};

typedef struct _cellule* Cellule;

#endif // CELLULE_H_INCLUDED

 */