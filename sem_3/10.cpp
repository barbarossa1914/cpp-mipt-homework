#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%i", &n);
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        char dir[10];
        int coord;
        scanf("%s %i", dir, &coord);
        if (strcmp(dir, "North") == 0)
            y += coord;
        else if (strcmp(dir, "South") == 0)
            y -= coord;
        else if (strcmp(dir, "West") == 0)
            x -= coord;
        else if (strcmp(dir, "East") == 0)
            x += coord;
    }
    printf("%i %i", x, y);
}