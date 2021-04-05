#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n,m,y,b,d;
    
    do
    {
        n = get_int("Start Size: ");
    }
    while(n < 9);
    
    do
    {
        m = get_int("End Size: ");
    }
    while(m < n);
    
    for(y = 0; n < m; y++)
    {
        b = n/3;
        d = n/4;
        n = n + b - d;
    }
    
    {
        printf("Years: %i\n", y);
    }
}