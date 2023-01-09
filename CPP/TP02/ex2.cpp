#include <iostream>
using namespace std ;

template<typename T>

T powiter(T a , int n)
{
    T res = 1 ; 
    while(n>0)
    {
	    if(n%2==1){
	       
	        res = res*a;
	        a = a*a;
	    }
	    
	    else{
	       
	        a = a*a;
	    }
	    n= n/2 ;
	    
    }
    return res ;

}
template <typename T> 
T powrec (T a , int n)
{
    if (n==1)
    {
        return 1 ; 
    }
    if (n%2 ==1)
    {
        return powrec(a,(n-1)/2)*powrec(a,(n-1)/2)*a ; }
    else 
    {
        return  powrec(a,n/2)*powrec(a,n/2) ; 
    }
    
}
int main()
{
    cout << powiter(2,5) << endl ; 
    cout << powiter(2.2,4) << endl ; 
    cout << powrec(2,5) << endl ; 
    cout << powrec(2.2,4) << endl ; 
    return 0 ; 
}
