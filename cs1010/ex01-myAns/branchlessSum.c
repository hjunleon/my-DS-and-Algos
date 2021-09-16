#include "cs1010.h"

int main(){
    long x = cs1010_read_long();
    long y = cs1010_read_long();
    long ans = 0;
    ans += x * (x>0) + y * (y>0);
    cs1010_println_long(ans);
    return 0;
}
