#include <stdio.h>
#include <stdlib.h>
#include "ballsortpuzzle.h"

int main()
{
    int rows = 4;
    int columns = 6;
    char field[rows][columns];
    generator(rows, columns, field);

    while (check(rows, columns, field) != true)
    {
        game_field(rows, columns, field);
        int x = 0, y = 0;
        printf("Enter what: %ls", &x);
        scanf("%d", &x);
        printf("Enter where: %ls", &y);
        scanf("%d", &y);
        down_possible(rows, columns, field, x, y);
    }
    printf("YOU WON\n");
}