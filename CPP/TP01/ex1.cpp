// C++ implementation of the approach
#include<iostream>
#include <vector>
using namespace std;
const int MAXN = 100;
using matrix = vector<vector<int>> ; 

vector<int> shortest[MAXN];
 
 
// function to add edge to the graph
void ajoutLiaison(matrix *a ,int x,int y)
{
    (*a)[x][y] = 1;
    (*a)[y][x] = 1;
}
 
// Function to perform BFS on the graph
void bfs(matrix a ,int start)
{
    
    vector<bool> visited(a.size(), false);
    vector<int> q;
    q.push_back(start);
  
    // Set source as visited
    visited[start] = true;
    shortest[start].push_back(start);
  
    int vis;
    while (!q.empty()) {
        vis = q[0];
  
        // Print the current node
        q.erase(q.begin());
  
        // For every adjacent vertex to the current vertex
        for (int i = 0; i < a[vis].size(); i++) {
            if (a[vis][i] == 1 && (!visited[i])) {
  
                // Push the adjacent node to the queue
                shortest[i] = shortest[vis];
                shortest[i].push_back(i);
                q.push_back(i);
  
                // Set
                visited[i] = true;
            }
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
  

int main()
{
    
    int v {} ; 
    cout << "Bonjour Combien de noeuds souhaitez-vous ?" << endl ; 
    cin >> v ; 
    int k {} ; 
    cout << "Entrez le num du noeud de destination ?" << endl ; 
    cin >> k ; 

   
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
    
    bfs(adj,0);
    cout<< "The shortest path is :" << endl; 
    for (int i : shortest[k])
        {
            cout << i  << " ";
        }
}
