#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

#define SIZE 25

int generateKey(int i, int j)
{
    return (i * 100) + j;
}

void printUniverse(unordered_set<int> &set)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (set.find(generateKey(i, j)) == set.end())
                cout << "0 ";
            else
                cout << "1 ";
        }
        cout << endl;
    }
    cout << endl;
}

void initializeGliderUniverse(unordered_set<int> &set)
{
    int x = (SIZE - 1) / 2;
    set.insert(generateKey(x + 1, x - 1));
    set.insert(generateKey(x + 1, x));
    set.insert(generateKey(x + 1, x + 1));
    set.insert(generateKey(x, x + 1));
    set.insert(generateKey(x - 1, x));
}

int entry(unordered_set<int> &set, int i, int j)
{
    return (set.find(generateKey(i, j)) == set.end()) ? 0 : 1;
}

int calcState(unordered_set<int> &set, int i, int j, int alive)
{
    if ((alive < 2 || alive > 3) && entry(set, i, j) == 1)
        return 0;
    else if (alive == 3 && entry(set, i, j) == 0)
        return 1;
    else
        return entry(set, i, j);
}

int aliveAround(unordered_set<int> &set, int i, int j)
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
                alive += entry(set, x + i, y + j);
            }
        }
    }
    return alive;
}

void startGame(unordered_set<int> &set, int max_iterations)
{
    unordered_set<int> set2;
    for (int it = 0; it < max_iterations; it++)
    {
        set2.clear();
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                int alive = aliveAround(set, i, j);
                if (calcState(set, i, j, alive) == 1)
                    set2.insert(generateKey(i, j));
            }
        }
        set = set2;
        printUniverse(set);
    }
}

int main()
{
    int max_i;
    cin >> max_i;
    unordered_set<int> set1;

    initializeGliderUniverse(set1);
    printUniverse(set1);
    startGame(set1, max_i);
}