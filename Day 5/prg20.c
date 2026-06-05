
#include <stdio.h>
#include<math.h>
long long m(long long n)
{
    long long max=-1;
    while(n%2==0)
    {
        max=2;
        n/=2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
        while(n%i==0)
        {
            max=i;
            n/=i;
        }
    if(n>2)
        max=n;
    return max;
}
int main()
{
    long long n;
    printf("Enter a number:\n");
    scanf("%lld",&n);
  // n=600851475143; 
    printf("%lld\n",m(n));

    return 0;
}