#include<stdio.h>
#include<stdlib.h>


void print_nth_byte (int n, int m )
{

int s = m*8-1 ;

for ( int i = s ; i >= s-7; i--)
{
  int res = n >> i ;

if (res & 1)
      printf("1");
    else
      printf("0");
}
printf("\n") ;

return  ; }
int main()
{
print_nth_byte (2500, 2 ) ;
return 0 ; }
