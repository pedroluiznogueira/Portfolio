#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // asks the user to enter their name in the terminal
    string name = get_string("What's your name?\n");
    
    // Says Hello and the name wich the user typed
    printf("Hello, %s\n", name);
}