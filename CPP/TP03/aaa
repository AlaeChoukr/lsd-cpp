#include <iostream>
#include <string>

using namespace std ; 
const int MAX_CONTACTS = 8;
class Contact 
{
    private : 
    string nom ; 
    string prénom ; 
    string surnom ; 
    string numtel  ; 
    public : 
    Contact() : nom(""), prénom(""), surnom(""), numtel("") {}
    Contact(string n,string p ,string s,string num) 
        : nom{n},prénom{p},surnom{s},numtel{num} {}
    string get_nom(){return nom ; } 
    string get_prénom(){return prénom ;} 
    string get_surnom(){return surnom ; }
    string get_num(){return numtel ;}

    
} ;

class PhoneBook {
private:
  Contact contacts[MAX_CONTACTS];  
  int taille;

public:
  PhoneBook() : taille{0} {}  

  
  void add(Contact newcontact) {
    if (taille == MAX_CONTACTS) 
    {
      
      contacts[0] = newcontact;
    } 
    else {
      contacts[taille] = newcontact;
      taille+= 1;
    }
  }


  
  void displayContacts() {
    cout.width(10) ; cout<< left << "   Index" << "|"   ;
    cout.width(10 ); cout << left << "    Nom" << "|"   ; 
    cout.width(10 ); cout << left << "  Prenom" << "|"   ; 
    cout.width(10 ); cout << left << "  Surnom" << "|"  << endl ; 
    cout << "------------------------------------------------" << endl;
    for (int i = 0; i < taille; i++) {
      Contact contact = contacts[i];
      cout.width(10) ; cout <<left << i << "|";
      string FirstName = contact.get_nom();
      string LastName = contact.get_prénom();
      string NickName = contact.get_surnom();
      
      if (FirstName.size() > 9){
          FirstName.replace(9, FirstName.size(), ".");
      }
      if (LastName.size() > 9){
          LastName.replace(9, LastName.size(), ".");
      }
      if (NickName.size() > 9){
          NickName.replace(9, NickName.size(), ".");
      }
      
      cout.width(10); cout << left << FirstName << "|";
      cout.width(10); cout << left << LastName << "|";
      cout.width(10); cout << left << NickName << endl;
    }
  }

  void displayContact(int index) {
    if (index < 0 || index >= taille) {
      cout << "Index invalide" << endl;
      return;
    }

    Contact contact = contacts[index];
    cout << "Nom: " << contact.get_nom() << endl;
    cout << "Prenom: " << contact.get_prénom() << endl;
    cout << "Surnom: " << contact.get_surnom() << endl;
    cout << "Numero: " << contact.get_num() << endl;
  }
} ; 




int main() {
  PhoneBook phoneBook;  

  while (true) {
    cout << "Entrez une des commandes  (ADD, SEARCH, EXIT): ";
    string command;
    cin >> command;

    if (command == "ADD") {
      
      cout << "Entrez le nom: ";
      string nom;
      cin >> nom;

      cout << "Entrez le prenom: ";
      string prénom;
      cin >> prénom;

      cout << "Entrez surnom : ";
      string surnom;
      cin >> surnom;

      cout << "Entrez numero de telephone: ";
      string num;
      cin >> num;

     
      Contact contact{nom, prénom, surnom,num};
      phoneBook.add(contact);
    } 
    else if (command == "SEARCH") {
      
      phoneBook.displayContacts();

      
      cout << "Entrez l'index du contact : ";
      int index;
      cin >> index;
     
      phoneBook.displayContact(index);

    } 
    else if (command == "EXIT") {
      // Quit the program
      break;
    } 
    else {
      
      cout << "Commande invalide" << endl;
      break ; 
    }
  }

  return 0;
}

