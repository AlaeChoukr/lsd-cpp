#include<stdio.h>

void check_msb(int);
void print_bits(unsigned char);
void print_nth_byte (int, int);


int main(){
    int x;
    scanf("%d",&x);
    check_msb(x);
    unsigned char ch;
    scanf("%hhu",&ch);
    print_bits(ch);
    int n, m;
    scanf("%d",&m);
    scanf("%d",&n);
    print_nth_byte (n, m);
    return 0;
}
