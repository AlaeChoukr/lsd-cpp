#include <iostream>
#include <vector>

using namespace std;
using matrix = vector<vector<int>> ; 


const int MAX_N = 100;
int n;
bool vis[MAX_N];

void ajoutLiaison(matrix *a ,int x,int y)
{
    (*a)[x][y] = 1;
    (*a)[y][x] = 1;
}
 


void dfs(matrix a , int u) {
  // Mark the current node as visited
  vis[u] = true;

 
  for (int v =1 ; v<a.size();v++) {
    
    if ( !vis[v]) {
      dfs(a,v);
    }
  }
}
void matprint(matrix a )
{
    int n = a.size() ; 
    for (int i = 0 ; i<n;i++) 
    {
        for (int j=0;j<n;j++)
            cout << a[i][j] << " " ; 
        cout << endl ; 
    }
    cout << endl ;
}
  

int main() {
  int v {} ; 
    cout << "Bonjour Combien de noeuds souhaitez-vous ?" << endl ; 
    cin >> v ; 
   

    
    matrix adj= matrix(v,vector<int>(v,0));
    int liaisons ; 
    cout << " Combien  de liaisons souhaitez-vous ?" << endl ; 
    cin >> liaisons ; 
    for (int i = 0 ;i<liaisons;i++)
    {
        int a = 0 ; 
        int b = 0 ;
        cout <<"Entrez le numero du premier noeud "<<endl ; 
        cin >>   a ;
        cout <<"Entrez le numero du deuxième noeud "<<endl ; 
        cin >> b ; 
        ajoutLiaison(&adj,a,b) ; 

    }




    
   /* ajoutLiaison(0,3);
    ajoutLiaison(1,2);
    ajoutLiaison(1,3);
    ajoutLiaison(3,4);
    ajoutLiaison(1,4);
    ajoutLiaison(2,4);*/
    matprint(adj) ; 
  int ans = 0;

  
  for (int i = 1; i <= v; i++) {
    if (!vis[i]) {
      ans++;
      dfs(adj,i);

      
    }
  }

  cout << ans << endl;
  return 0;
}
