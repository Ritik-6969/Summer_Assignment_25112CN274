#include <stdio.h>

int main() {

    int a = 0, b = 1;
    int nextTerm;
    
    int n ;
    printf("enter the term of fibnonacci : \n");
    scanf("%d", &n);
    if (n == 0 || n == 1){
        printf("fib(%d) : %d",n, n);
        return 0;
    }

    for (int i = 2; i <= n; ++i) {
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    printf("fib(%d) : %d",n, nextTerm);
    
    return 0;
}