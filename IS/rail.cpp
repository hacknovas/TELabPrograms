// @Doni_Prathamesh
#include <bits/stdc++.h>
using namespace std;

class RailFenceCipher
{

public:
    RailFenceCipher(string str, int key)
    {
        string encrypted_text = encryption(str, key);
        cout << "\nEncrypted Text:\t" << encrypted_text << endl;
        string decrypted_text = decryption(encrypted_text, key);
        cout << "Decrypted Text:\t" << decrypted_text << endl;
    }
    string encryption(string, int);
    string decryption(string, int);
};

string RailFenceCipher::encryption(string str, int key)
{
    char matrix[key][str.length()];
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            matrix[i][j] = '_';
        }
    }

    int cnt = false;
    int row = 0, col = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (row == 0 || row == key - 1)
        {
            cnt = !cnt;
        }

        matrix[row][col++] = str[i];

        cnt ? row++ : row--;
    }

    string res;

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            if (matrix[i][j] != '_')
            {
                res.push_back(matrix[i][j]);
            }
        }
    }

    return res;
}

string RailFenceCipher::decryption(string str, int key)
{
    char matrix[key][str.length()];

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            matrix[i][j] = '_';
        }
    }

    int cnt = false;
    int row = 0, col = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (row == 0 || row == key - 1)
        {
            cnt = !cnt;
        }

        matrix[row][col++] = '*';

        cnt ? row++ : row--;
    }

    int index = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            if (index < str.length() && matrix[i][j] == '*')
            {
                matrix[i][j] = str[index++];
            }
        }
        cout << endl;
    }

    string res;
    cnt = false;
    row = 0, col = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (row == 0 | row == key - 1)
        {
            cnt = !cnt;
        }

        if (matrix[row][col] != '_')
        {
            res.push_back(matrix[row][col++]);
        }

        cnt ? row++ : row--;
    }

    return res;
}

int main()
{
    string str;
    int key;

    cout << "\nEnter String:" << endl;
    getline(cin, str);
    cout << "Enter Key:" << endl;
    cin >> key;

    RailFenceCipher ob(str, key);

    return 0;
}
