#include "../include/read_lines.h"



/************************ Implementation des fonctions ***********************/

int fonction1(listeDouble queue)
{
    int i = 0 ;
    int res = -1 ;
    listeDouble temp = queue ; 
    while (temp.debut !=NULL) 
{       if (temp.debut->element == '\n')   
        {
            res = i;
            break;
        }
    i++ ;
    temp.debut = temp.debut->suivant ;
        


} 
    return res ; }





int extractionDebut(listeDouble * P)
{
    if(listeDoubleVide(*P))
    {
        exit(EXIT_FAILURE);
    }
    int res=P->debut->element;
    suppressionDebut(P);
    return res;
}
int extractionFin(listeDouble * P)
{
    if(listeDoubleVide(*P))
    {
        exit(EXIT_FAILURE);
    }
    char res=P->fin->element;
    suppressionFin(P);
    return res;
}
// La fonction test_vide_listeDouble
int listeDoubleVide(listeDouble L)
{
    if(L.debut==NULL)
        return 1;
    return 0;
}
// La fonction affichage
void affichageListeDouble(listeDouble L)
{
    /* Si la liste est vide */
    if(listeDoubleVide(L)==1)
    {
        printf("[]\n");
        // On sort de la fonction
        return;
    }
    /* On continue si la liste st non vide */
    celluleDouble *temp=L.debut;
    printf("[");
    while(temp->suivant!=NULL)
    {
        printf("%d, ",temp->element);
        temp=temp->suivant;
    }
    if(temp!=NULL)
        printf("%d",temp->element);
    printf("]\n");
}
// La fonction ajourDebut()
void ajoutDebut(char x,listeDouble * L)
{
    /* Declaration et initialisation de la cellue a ajouter */
    celluleDouble * C=(celluleDouble *)malloc(sizeof(celluleDouble));
    C->element=x;
    C->suivant=L->debut;
    C->precedent=NULL;
    /* Fin initialisation de la cellule double */
    
    /* Cas ou la liste L est vide */
    if(listeDoubleVide(*L)==1)
    {
        L->debut=C;
        L->fin=C;
        L->longueur=1;
        return;
    }
    /* Si la liste L n'est pas vide */
    L->debut->precedent=C;
    L->debut=C;
    L->longueur+=1;
    return;
}
// La fonction ajourFin()
void ajoutFin(char x,listeDouble *L)
{
    /** Declaration et initialisation de la cellue a ajouter **/
    celluleDouble * C=(celluleDouble *)malloc(sizeof(celluleDouble));
    C->element=x;
    C->precedent=L->fin;
    C->suivant=NULL;
    /** Fin initialisation de la cellule double **/
    
    /* Si la liste L est vide on ajoute au debut */
    if(listeDoubleVide(*L)==1)
    {
        ajoutDebut(x,L);
        return;
    }
    /* Si la liste n'est pas vide */
    L->fin->suivant=C;
    L->fin=C;
    L->longueur+=1;
    return;
}
// La fonction suppressionDebut()
void suppressionDebut(listeDouble * L)
{
    /* Cas d'une liste vide */
    if(listeDoubleVide(*L)==1)
        return;
    /* Cas d'une liste a un seul element */
    if(L->longueur==1)
    {
        L->longueur=0;
        if(L->debut!=NULL)
            free(L->debut);
        L->debut=NULL;
        return;
    }
    /* declaration d'un pointeur temporaire vers la premiere celluleDouble */
    celluleDouble * temp=L->debut;
    /* Deplacement du debut de la liste vers la celluleDouble suivante */
    L->debut=L->debut->suivant;
    L->longueur-=1;
    /* Liberation de la premiere celluleDouble*/
    free(temp);
    return;
}
// La fonction suppressionFin()
void suppressionFin(listeDouble * L)
{
    if(listeDoubleVide(*L)==1)
        return;
    /* Cas d'une liste a un seul element */
    if(L->longueur==1)
    {
        suppressionDebut(L);
        return;
    }
    /* declaration d'un pointeur temporaire vers la derniere celluleDouble */
    celluleDouble * temp=L->fin;
    /* Deplacement de la fin de la liste vers la celluleDouble precedente */
    L->fin=L->fin->precedent;
    L->fin->suivant=NULL;
    L->longueur-=1;
    free(temp);
    return;
}
// La fonction librer
void libererListeDouble(listeDouble L)
{
    while(L.debut!=NULL)
    {
        celluleDouble * temp=L.debut;
        L.debut=L.debut->suivant;
        free(temp);
    }
}
