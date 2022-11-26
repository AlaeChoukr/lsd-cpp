#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

// Defintion d'une cellule double
struct celluleDouble
{
    char element;
    struct celluleDouble * suivant;
    struct celluleDouble * precedent;
};
typedef struct celluleDouble celluleDouble;
// Fin de la definition d'une cellule double
// Defintion d'une liste doublement chainee
struct listeDouble
{
    celluleDouble * debut;
    celluleDouble * fin;
    unsigned longueur;
};
typedef struct listeDouble listeDouble;
// Fin de la definition d'une liste double
// Prototypes
char	*read_lines(int fd);
int fonction1(listeDouble) ;
void affichageListeDouble(listeDouble) ; 
int listeDoubleVide(listeDouble ) ; 
void ajoutDebut(char, listeDouble *);
void ajoutFin(char,listeDouble *);
void suppressionDebut(listeDouble *);
void suppressionFin(listeDouble *);
void libererListeDouble(listeDouble);
int extractionDebut(listeDouble *);
int extractionFin(listeDouble *);
