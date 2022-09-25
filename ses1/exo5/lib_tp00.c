#include<stdio.h>
#include<stdlib.h>


void check_msb(int num)
{

int res = num & (1<<sizeof(int)*8-1) ;
if (res==0)
printf("msb is not set\n") ;
else
printf("msb is set\n") ;
}



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

