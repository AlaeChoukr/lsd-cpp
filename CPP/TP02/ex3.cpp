#include <iostream>
#include <vector>

using namespace std ;
template <typename T>
using matrix =  vector <vector<T>> ; 
template <typename T>
matrix<T> matpownaive(matrix<T> a , int k  )
{
    matrix<T> temp = a ; 
    int n = a.size() ; 
    matrix<T> res (n,vector<T>(n,0)) ; 
    for (int p = 0 ; p< k-1 ; p++)
    {
        for (int i = 0;i<n;i++)
        {
            for (int j = 0 ; j<n;j++)
            {
                for (int m=0;m<n;m++)
                { 
                    res[i][j] +=temp[i][m]*a[m][j];
                }
            }
        }
        temp = res ;
        res = matrix<int>(n,vector<int>(n,0)) ;

    }   
    return temp ; 
}
template<typename T >
void matprint(matrix<T> a )
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
template < typename T>
matrix<T> multiply (matrix<T> a, matrix<T> b)
{
    int n= a.size();
	matrix<T> c(n,vector<T>(n,0)) ;
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<n;j++)
		{
			for(int m=0; m<n ; m++)
			    c[i][j]+= a[i][m] * b[m][j];
		}
	}
	return c;
}
template<typename T >
matrix<T> matpow(matrix<T> a , int k )
{
    if (k==1)
        return a ; 
    if (k%2 == 1)
        return multiply(matpownaive(matpow(a,(k-1)/2),2),a) ;
    else
        return matpownaive(matpow(a,k/2),2) ;
}

int main()
{
    matrix<int> v(3, vector<int>(3,7)) ; 
    matprint(v) ; 

    matrix<int> d = matpownaive(v,6) ;
    matprint(d) ;

    matrix<int> c = matpow(v,6) ; 
    matprint(c) ;
   
    
    } 

