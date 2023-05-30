#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **board, int x, int y, int n)
{
    for (int row = 0; row < x; row++)
    {
        if (board[row][y] == 1)
        {
            return false;
        }
    }

    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;

    while (row >= 0 && col < n)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **board, int x, int n)
{
    if (x >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, x, col, n))
        {
            board[x][col] = 1;

            if (nQueen(board, x + 1, n))
            {
                return true;
            }

            board[x][col] = 0;
        }
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter N value:" << endl;
    cin >> n;

    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    cout << endl;
    if (nQueen(board, 0, n))

    {
        for (int i = 0; i < n; i++)
        {
            
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\n*Solution Not Available.";
    }

    return 0;
}
