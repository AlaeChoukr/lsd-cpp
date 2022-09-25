#include<stdio.h>
#include<stdlib.h>


void check_msb(int num)
{
if (num==0)
{ printf("msb is not set") ; }
else
{
int res = num & (1<<sizeof(int)*8-1) ;
if (res==0)
printf("0\n") ;
else
printf("1\n") ;
}
}






int main()
{
 check_msb(123) ;
 check_msb(-5) ;

return 0 ; }
