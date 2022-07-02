#include <iostream>
using namespace std;
int table[9][9];
bool isSafe(int num, int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (table[i][col] == num)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (table[row][i] == num)
        {
            return false;
        }
    }
    int rowstart = row - (row % 3);
    int colstart = col - (col % 3);
    for (int i = rowstart; i < rowstart + 3; i++)
    {
        for (int j = colstart; j < colstart + 3; j++)
        {
            if (table[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool sodukosolver()
{
    int row = -1, col = -1, i, j;
    bool isEmpty = false;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (table[i][j] == 0)
            {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
        {
            break;
        }
    }
    if (!isEmpty) // completely filled
    {
        return true;
    }
    for (int k = 1; k <= 9; k++)
    {
        if (isSafe(k, row, col))
        {
            table[row][col] = k;
            if (sodukosolver())
            {
                return true;
            }
            table[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int a;
            cin >> a;
            table[i][j] = a;
        }
    }
    bool ans = sodukosolver();
    cout << ans << endl;
    cout << "_______________________" << endl;
    if (ans)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << table[i][j] << " ";
                if ((j + 1) % 3 == 0 && j != 0)
                {
                    cout << "|"
                         << " ";
                }
            }
            cout << endl;
            if ((i + 1) % 3 == 0)
            {
                cout << "_______________________" << endl;
            }
        }
    }
    else
    {
        cout << "Solution is not possible";
    }
}