#include <iostream>
using namespace std;
struct node
{
    int element;
    struct node * suivant;
};
typedef struct node node;
using pile = node* ; 



void push(int x,pile * P)
{
    pile C=(pile)malloc(sizeof(node));
    C->element=x;
    C->suivant=*P;
    *P=C;
    return;
}
int pop(pile * P)
{
    if(*P!=NULL)
    {
        int res=(*P)->element;       
        pile temp=*P;
        *P=(*P)->suivant;
        free(temp);
        return res;
    }
    else
        exit(EXIT_FAILURE);
}
void affichepile(pile P) {
    pile temp = P ; 
    if(P == nullptr){ 
        cout<<"[ ]"<<endl;
        return;
    }
    cout<<'[';
    while(temp->suivant!=nullptr)
    {
        cout << temp->element <<" ; "  ;
        temp = temp->suivant;
    }
    if(temp!=NULL)
        cout << temp->element <<"]"<<endl ; 
    return;
}
void reverseutils(pile X,pile* Y )
{
    pile temp = X; 
    while (temp !=NULL)
    {
        int res = temp->element;
        push(res,Y);
        temp = temp->suivant ; 
    } 
}
bool check(pile P,int k)
{
    pile temp = P ; 
    while(temp!=NULL)
    {
        if (temp->element == k)
            return true ;
        temp = temp->suivant  ;

    }
    return false ; 

}
void viderpile(pile*P)
{
    while ((*P)!= NULL)
    {
        pile temp = *P ;
        (*P) = (*P)->suivant ; 
        free(temp) ;
        

    }



}
void removedup(pile* P )
{   pile temp = *P ; 
    pile temp2{nullptr} ; 
    while (temp!= NULL)
    {
        if (check(temp2,temp->element)==false)
        {
            int res = temp->element ; 
            push(res,&temp2) ; 
        }
        temp = temp->suivant ; 
    }
    viderpile(P) ; 
    reverseutils(temp2,P) ; 
}

int main()
{
    pile P {nullptr} ; 
   
    push(5,&P) ; 
    push(5,&P) ; 
    push(6,&P) ;
    push(6,&P) ; 
    push(2,&P) ; 
    push(6,&P) ; 
    push(5,&P) ; 
    push(2,&P) ; 
    push(2,&P) ;  
    affichepile(P);
    removedup(&P) ;
    affichepile(P) ; 
    
    return 0;
}
