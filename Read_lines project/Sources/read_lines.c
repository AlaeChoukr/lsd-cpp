#include "../include/read_lines.h"

char* read_lines(int fd){
    char* res = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, res, 0) < 0) //si fd ou BUFFERSIZE négatif ou le fichier est illisible ou vide retourne NULL
		return NULL;
    static listeDouble queue = {NULL,NULL,0} ; // une liste doublement chainée statique qui va contenir tout les caractères (elle est statique car on aura besoin de stocker l'excédent pour le prochain appel de la fonction)

while (fonction1(queue) == -1 ) 
{   
    char* buffer = malloc(sizeof(char)*BUFFER_SIZE); 
    int number =read(fd,buffer,BUFFER_SIZE) ; // on stocke le nombre de caractères ajoutés dans la variable number tout en ajoutant ces caractères dans buffer
    if(number<=0) // si le fichier txt est vide break 
        break;
    for (int i = 0; i<number;i++)
    {   
        ajoutFin (buffer[i],&queue) ; //tant que notre liste ne contient pas \n on ajoute les caractères à queue un par un jusqu'à la taille du bufersize
    }
}
if (queue.debut == NULL)
    return NULL ; 
int number2 = fonction1(queue) ; // ici l'indice du \n dans notre liste 
if (number2 == -1) // ici le cas où on se trouve dans la dernière ligne car pas de \n
    number2 = queue.longueur-1 ; 
res = malloc(sizeof(char)*(number2+2)) ;
for(int i=0;i<number2+1;i++){
    res[i] = extractionDebut(&queue) ; // on ajoute nos caractères dans res tout en les supprimant dans queue

} 
res[number2+1]= '\0' ;
return res ; // retourne les lignes une par une si on appelle la fonction plusieurs fois 
}








