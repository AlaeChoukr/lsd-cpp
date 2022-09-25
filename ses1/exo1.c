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







int main()
{
 check_msb(-718) ;
 check_msb(78) ;

return 0 ; }
