#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 25

void printUniverse(int universe[SIZE + 2][SIZE + 2])
{
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            cout << universe[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void initializeGliderUniverse(int universe[SIZE + 2][SIZE + 2])
{
    int x = (SIZE - 1) / 2;
    x++;
    universe[x + 1][x - 1] = 1;
    universe[x + 1][x] = 1;
    universe[x + 1][x + 1] = 1;
    universe[x][x + 1] = 1;
    universe[x - 1][x] = 1;
}

int calcState(int universe[SIZE + 2][SIZE + 2], int i, int j, int alive)
{
    if ((alive < 2 || alive > 3) && universe[i][j] == 1)
        return 0;
    else if (alive == 3 && universe[i][j] == 0)
        return 1;
    else
        return universe[i][j];
}

void startGame(int universe[SIZE + 2][SIZE + 2], int max_iterations)
{
    int tmp[SIZE + 2][SIZE + 2];
    memset(tmp, 0, sizeof(tmp));
    for (int iteration = 0; iteration < max_iterations; iteration++)
    {
        for (int i = 1; i <= SIZE; i++)
        {
            for (int j = 1; j <= SIZE; j++)
            {
                int alive = 0;
                alive = universe[i - 1][j - 1] + universe[i - 1][j] + universe[i - 1][j + 1] + universe[i][j - 1] + universe[i][j + 1] + universe[i + 1][j - 1] + universe[i + 1][j] + universe[i + 1][j + 1];
                tmp[i][j] = calcState(universe, i, j, alive);
            }
        }
        memcpy(universe, tmp, (SIZE + 2) * (SIZE + 2) * sizeof(int));
        printUniverse(universe);
    }
}

int main()
{
    int max_i;
    cin >> max_i;
    int universe[SIZE + 2][SIZE + 2];
    memset(universe, 0, sizeof(universe));
    initializeGliderUniverse(universe);
    printUniverse(universe);
    startGame(universe, max_i);
}