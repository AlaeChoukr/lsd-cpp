#include<stdio.h>
#include<stdlib.h>


void print_bits(unsigned char byte)
{
 
for ( int i = sizeof(char)*8-1 ; i >= 0; i--)
{
  int res = byte >> i ;

if (res & 1)
      printf("1");
    else
      printf("0");
}
printf("\n") ;
return  ;
}

int main()
{
 print_bits(128) ;
return 0 ; }
