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
