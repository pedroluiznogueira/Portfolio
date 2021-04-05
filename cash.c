#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float n, a, b, c, d, y, w, v;
    int x, z, u, t; 
    do
    {
        n = get_float("Change owed: ");
    }
    while(n < 0);
    
    a = 25;
    b = 10;
    c = 5;
    d = 1;
    
    x = (int) n / a;
    y = n - (x * a);
    z = (int) y / b;
    w = y - (z * b);
    u = (int) w / c;
    v = w - (u * c);
    t = (int) v / d;
    
    float m = x + z + u + t;
    
    printf("%.0f\n", m);
}