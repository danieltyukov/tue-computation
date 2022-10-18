#include <stdio.h>
#include <stdlib.h>

#define START 'S'
#define DESTINATION 'D'
#define PATH '+'
#define WALL '#'
#define UNSEEN '.'
#define SEEN '~'

typedef struct
{
    char *grid;
    int maxX;
    int maxY;
} navigation_t;

typedef struct
{
    int x;
    int y;
} position_t;

void newGrid(navigation_t *nav)
{
    if (nav->grid != NULL)
    {
        free(nav->grid);
        nav->grid = NULL;
        nav->maxX = 0;
        nav->maxY = 0;
    }
    printf("Number of rows? ");
    scanf(" %d", &nav->maxY);
    printf("Number of columns? ");
    scanf(" %d", &nav->maxX);
    if (nav->maxY < 2 || nav->maxX < 2)
    {
        printf("The number of rows and columns must be at least two\n");
        return;
    }
    nav->grid = (char *)malloc(nav->maxX * nav->maxY * sizeof(char *));
}

void inputGrid(navigation_t nav)
{
    int sCount = 0;
    for (int y = 0; y < nav.maxY; y++)
    {
        printf("Input row %d: ", y);
        for (int x = 0; x < nav.maxX; x++)
        {
            scanf(" %c", &nav.grid[y * nav.maxX + x]);
            if (nav.grid[y * nav.maxX + x] == 'S')
            {
                sCount++;
                if (sCount > 1)
                {
                    printf("Extra starting point\n");
                    nav.grid[y * nav.maxX + x] = '#';
                }
            }
        }
    }
}

void printGrid(navigation_t nav)
{
    for (int y = 0; y < nav.maxY; y++)
    {
        for (int x = 0; x < nav.maxX; x++)
        {
            printf("%c", nav.grid[y * nav.maxX + x]);
        }
        printf("\n");
    }
}

position_t findStart(navigation_t nav)
{
    position_t start;
    int startPoint = 0;
    int destinationPath = 0;
    for (int y = 0; y < nav.maxY; y++)
    {
        for (int x = 0; x < nav.maxX; x++)
        {
            if (nav.grid[y * nav.maxX + x] == 'S')
            {
                startPoint = 1;
                start.x = x;
                start.y = y;
            }
            if (nav.grid[y * nav.maxX + x] == 'D')
            {
                destinationPath = 1;
            }
        }
    }
    if (startPoint == 0)
    {
        printf("Grid contains no starting point\n");
        start.x = -1;
    }
    if (destinationPath == 0)
    {
        printf("Grid contains no destination\n");
    }
    return start;
}

int findPath(navigation_t nav, int x, int y, int length)
{
    int nlength, elength, slength, wlength;
    if (x >= nav.maxX || x < 0 || y >= nav.maxY || y < 0)
        return 0;
    else if (nav.grid[y * nav.maxX + x] == WALL || nav.grid[y * nav.maxX + x] == SEEN || nav.grid[y * nav.maxX + x] == PATH || (nav.grid[y * nav.maxX + x] == START && length > 0))
        return 0;
    else if (nav.grid[y * nav.maxX + x] == DESTINATION)
        return length;
    else if (nav.grid[y * nav.maxX + x] != START)
        nav.grid[y * nav.maxX + x] = PATH;
    if ((nlength = findPath(nav, x, y - 1, length + 1)))
        return nlength;
    if ((elength = findPath(nav, x + 1, y, length + 1)))
        return elength;
    if ((slength = findPath(nav, x, y + 1, length + 1)))
        return slength;
    if ((wlength = findPath(nav, x - 1, y, length + 1)))
        return wlength;
    if (nav.grid[y * nav.maxX + x] == UNSEEN || nav.grid[y * nav.maxX + x] == PATH)
    {
        nav.grid[y * nav.maxX + x] = SEEN;
    }
    return 0;
}

void resetPath(navigation_t nav)
{
    // Reset all SEEN and PATH characters in the grid to UNSEEN, allowing findPath to be run again.
    for (int y = 0; y < nav.maxY; y++)
    {
        for (int x = 0; x < nav.maxX; x++)
        {
            if (nav.grid[y * nav.maxX + x] == SEEN || nav.grid[y * nav.maxX + x] == PATH)
            {
                nav.grid[y * nav.maxX + x] = UNSEEN;
            }
        }
    }
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int longestPath(navigation_t nav, int x, int y, int length)
{

    // Small change from findPath, which stops as soon as it finds a path, to not stop at the first match but keep going.
    int nlength, elength, slength, wlength;
    if (x >= nav.maxX || x < 0 || y >= nav.maxY || y < 0)
        return 0;
    else if (nav.grid[y * nav.maxX + x] == WALL || nav.grid[y * nav.maxX + x] == PATH || (nav.grid[y * nav.maxX + x] == START && length > 0))
        return 0;
    else if (nav.grid[y * nav.maxX + x] == DESTINATION)
    {
        printf("Found a path of length %d\n", length);
        return length;
    }
    else if (nav.grid[y * nav.maxX + x] != START)
        nav.grid[y * nav.maxX + x] = PATH;
    nlength = longestPath(nav, x, y - 1, length + 1);
    elength = longestPath(nav, x + 1, y, length + 1);
    slength = longestPath(nav, x, y + 1, length + 1);
    wlength = longestPath(nav, x - 1, y, length + 1);
    if (nav.grid[y * nav.maxX + x] == UNSEEN || nav.grid[y * nav.maxX + x] == PATH)
    {
        nav.grid[y * nav.maxX + x] = SEEN;
    }
    return max(max(nlength, elength), max(slength, wlength));
}

int main()
{
    char cmd;
    navigation_t nav = {NULL};
    position_t start;
    int pathLength = 0;
    do
    {
        printf("Command? ");
        scanf(" %c", &cmd);
        switch (cmd)
        {
        default:
            printf("Unknown command '%c'\n", cmd);
            break;
        case 'q':
            printf("Bye!\n");
            break;
        case 'i':
            pathLength = 0;
            newGrid(&nav);
            if (nav.maxX >= 2 && nav.maxY >= 2)
            {
                inputGrid(nav);
            }
            break;
        case 'p':
            printGrid(nav);
            break;
        case 's':
            start = findStart(nav);
            if (start.x != -1)
            {
                printf("The start is at x=%d and y=%d\n", start.x, start.y);
            }
            break;
        case 'f':
            start = findStart(nav);
            pathLength = findPath(nav, start.x, start.y, pathLength);
            if (pathLength == 0)
                printf("No path found\n");
            if (pathLength != 0)
                printf("Found a path of length %d\n", pathLength);
            printGrid(nav);
            break;
        case 'r':
            resetPath(nav);
            pathLength = 0;
            break;
        case 'l':
            start = findStart(nav);
            pathLength = longestPath(nav, start.x, start.y, pathLength);
            if (pathLength == 0)
                printf("No path found\n");
            if (pathLength != 0)
                printf("The length of the longest path is %d\n", pathLength);
            break;
        }
    } while (cmd != 'q');
    free(nav.grid);
}