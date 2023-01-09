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

int main()
{
    pile P {nullptr} ; 
    pile C (nullptr) ; 
    pile V{nullptr} ; 
    push(4,&C) ; 
    push(3,&C) ;
    push(2,&C); 
    push(5,&P) ; 
    push(6,&P) ; 
    affichepile(P);
    return 0;
}
