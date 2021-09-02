#include "cs1010.h"
#include <stdlib.h>

long square(long a){
	return a * a;
}


int main(){
    long x = cs1010_read_long();
    //long ans = x + (square(x%2)==0) + 2*(square(x%2)==1);
    long ans = (x + 1) | 1;
    //long ans = 1 << (x & 1); 
	cs1010_println_long(ans);
    return 0;
}
