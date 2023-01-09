#include <iostream>
using namespace std ;
template <typename T > 

T multiply (T x , int y )
{
    T res = x*y ;
    return res ;
}
int main()
{
    cout << multiply<double>(5.2,4) << endl ; 
    cout << multiply<int>(10,4) << endl ;

}
