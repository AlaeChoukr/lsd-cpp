#include <iostream>
#include <string>

using namespace std ; 
const int MAX_BOOKS = 8 ; 


class Book
{
    private : 
        string name ; 
        int ISBN ; 
        string author ; 
        string link ; 
    public : 
        Book() : name{""} , author{""} , link{""} {}
        Book(string n , int i,string a , string l) : name{n} , ISBN{i}, author{a},link{l} {} 
        string getname() {return name ; } 
        int getisbn() {return ISBN ; }
        string getauthor() {return author  ; }
        string getlink() {return link ; }
        
} ;
class Library
{
    private : 
        Book books[MAX_BOOKS] ; 
        int taille ; 
    public : 
        Library() : taille{0} {}
        void add(Book newbook)
        {
            if (taille == 8)
                books[0] = newbook ; 
            else 
                books[taille] = newbook ; 
                taille++ ; 
            
        }
        void displaybooks() 
        {
            cout.width(10) ; cout << right << "    Index" << "|" ; 
            cout.width(10) ; cout << right << "Book name " << "|" ; 
            cout.width(10) ; cout << right << "   Author " << "|" << endl ; 
            cout << "---------------------------------" << endl ; 
            for (int i =0 ;i<taille;i++ )
            {
                Book  c  = books[i] ;
                string nom = c.getname() ; 
                string auteur = c.getauthor() ; 
                cout.width(10) ; cout<< right << i << "|" ; 
                if ( nom.size() >9)
                    nom.replace(9,nom.size(),".") ;
                if ( auteur.size() >9)
                    auteur.replace(9,auteur.size(),".") ;
                cout.width(10) ; cout<< right << nom << "|" ; 
                cout.width(10) ; cout<< right << auteur  << "|" << endl; 

            }
        }
        void displaybook(int index) {
            if (index < 0 || index >= taille) {
                cout << "Index invalide" << endl;
                return;}
            
            Book book = books[index];
            cout << "Nom: " << book.getname() << endl;
            cout << "Auteur: " << book.getauthor() << endl;
        }
    
}  ;

int main()
{ 
    Library my_library ; 
    while(true)
    {
        cout << "Entrez une des commandes suivantes (ADD,SEARCH,EXIT)" << endl ; 
        string commande ; 
        cin >> commande ;
        if (commande=="ADD")
        {
            cout << "Entrez le nom du livre " << endl ; 
            string nom ;
            cin >> nom ; 
            cout << "Entrez le nom de l'auteur "<< endl ; 
            string auteur ; 
            cin >> auteur ; 
            cout << "Entrez le num ISBN "<< endl ; 
            int num ; 
            cin >> num; 
            cout << "Entrez le lien"<< endl ; 
            string link ;
            cin >> link ; 
            Book b{nom,num,auteur,link} ; 
            my_library.add(b) ;
        } 


        else if (commande == "SEARCH") {
            my_library.displaybooks();
            cout << "Entrez l'index du livre : ";
            int index;
            cin >> index;
            my_library.displaybook(index);

         }
        else if (commande == "EXIT") 
        {
            break;
        } 
        else 
        {
            cout << "Commande invalide" << endl;
            break ; 
        }
    }
}


     
         





























            
            




            

         

    
   


























