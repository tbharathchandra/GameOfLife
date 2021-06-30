#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 25

void printUniverse(int universe[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << universe[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void initializeGliderUniverse(int universe[SIZE][SIZE])
{
    int x = (SIZE - 1) / 2;
    universe[x + 1][x - 1] = 1;
    universe[x + 1][x] = 1;
    universe[x + 1][x + 1] = 1;
    universe[x][x + 1] = 1;
    universe[x - 1][x] = 1;
}

int calcState(int universe[SIZE][SIZE], int i, int j, int alive)
{
    if ((alive < 2 || alive > 3) && universe[i][j] == 1)
        return 0;
    else if (alive == 3 && universe[i][j] == 0)
        return 1;
    else
        return universe[i][j];
}

int aliveAround(int universe[SIZE][SIZE], int i, int j)
{
    int alive = 0;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (i + x >= 0 && i + x < SIZE && j + y >= 0 && j + y < SIZE)
            {
                if (x == 0 && y == 0)
                    continue;
                alive += universe[i + x][j + y];
            }
        }
    }
    return alive;
}

void startGame(int universe[SIZE][SIZE], int max_iterations)
{
    int tmp[SIZE][SIZE];
    memset(tmp, 0, sizeof(tmp));
    for (int iteration = 0; iteration < max_iterations; iteration++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                int alive = 0;
                alive = aliveAround(universe, i, j);
                tmp[i][j] = calcState(universe, i, j, alive);
            }
        }
        memcpy(universe, tmp, (SIZE) * (SIZE) * sizeof(int));
        printUniverse(universe);
    }
}

int main()
{
    int max_i;
    cin >> max_i;
    int universe[SIZE][SIZE];
    memset(universe, 0, sizeof(universe));
    initializeGliderUniverse(universe);
    printUniverse(universe);
    startGame(universe, max_i);
}