#include "exo3.h"

int main(){
    int x;
    scanf("%d",&x);
    check_msb(x);
    unsigned char ch;
    scanf("%hhu",&ch);
    print_bits(ch);
    return 0;
}
