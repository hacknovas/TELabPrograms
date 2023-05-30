#include <bits/stdc++.h>
using namespace std;

class DES
{
    vector<int> key;
    vector<int> plain_text;
    vector<int> cipher_text;
    vector<int> key1;
    vector<int> key2;

protected:
    vector<int> P10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    vector<int> P8 = {6, 3, 7, 4, 8, 5, 10, 9};
    vector<int> P4 = {2, 4, 3, 1};
    vector<int> IP = {2, 6, 3, 1, 4, 8, 5, 7};
    vector<int> EP = {4, 1, 2, 3, 2, 3, 4, 1};
    vector<int> IP_inv = {4, 1, 3, 5, 7, 2, 8, 6};
    vector<vector<int>> S0 = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
    vector<vector<int>> S1 = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};

public:
    DES(vector<int> pt, vector<int> K)
    {
        plain_text = pt;
        key = K;
        key_generation();
        encryption();
        decryption();
    }
    vector<int> shift(vector<int>, int);
    void key_generation();
    void encryption();
    vector<int> algorithm(vector<int>, vector<int>);
    string _binary(int);
    vector<int> swap_LR(vector<int>);
    void decryption();
};

void DES::decryption()
{
    vector<int> arr;
    for (int i = 0; i < 8; i++)
    {
        arr.push_back(cipher_text[IP[i] - 1]);
    }

    vector<int> arr1 = algorithm(arr, key2);

    vector<int> swapped = swap_LR(arr1);

    vector<int> arr2 = algorithm(swapped, key1);

    vector<int> decrypted;

    for (int i = 0; i < 8; i++)
    {
        decrypted.push_back(arr2[IP_inv[i] - 1]);
    }

    cout << "\nDecrypted:" << endl;
    for (auto i : decrypted)
    {
        cout << i << " ";
    }
}

vector<int> DES::swap_LR(vector<int> arr)
{
    vector<int> LHS(arr.begin(), arr.begin() + arr.size() / 2);
    vector<int> RHS(arr.begin() + arr.size() / 2, arr.end());

    vector<int> res;

    for (auto i : RHS)
    {
        res.push_back(i);
    }

    for (auto i : LHS)
    {
        res.push_back(i);
    }

    return res;
}

string DES::_binary(int val)
{
    if (val == 0)
    {
        return "00";
    }
    else if (val == 1)
    {
        return "01";
    }
    else if (val == 2)
    {
        return "10";
    }
    else
    {
        return "11";
    }
}

vector<int> DES::algorithm(vector<int> arr, vector<int> key_)
{
    vector<int> LHS(arr.begin(), arr.begin() + arr.size() / 2);
    vector<int> RHS(arr.begin() + arr.size() / 2, arr.end());

    vector<int> expanded;

    for (int i = 0; i < 8; i++)
    {
        expanded.push_back(RHS[EP[i] - 1]);
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        arr[i] = key_[i] ^ expanded[i];
    }

    vector<int> L_1(arr.begin(), arr.begin() + arr.size() / 2);
    vector<int> R_1(arr.begin() + arr.size() / 2, arr.end());

    int row, col, val;

    row = L_1[0] + L_1[3];
    col = L_1[1] + L_1[2];
    val = S0[row][col];
    string str_l = _binary(val);

    row = R_1[0] + R_1[3];
    col = R_1[1] + R_1[2];
    val = S1[row][col];
    string str_r = _binary(val);

    vector<int> r_;

    for (int i = 0; i < 2; i++)
    {
        char c1 = str_l[i];
        r_.push_back(c1 - '0');
    }
    for (int i = 0; i < 2; i++)
    {
        char c2 = str_r[i];
        r_.push_back(c2 - '0');
    }

    vector<int> r_p4;
    for (int i = 0; i < 4; i++)
    {
        r_p4.push_back(r_[P4[i] - 1]);
    }

    for (int i = 0; i < 4; i++)
    {
        LHS[i] = LHS[i] ^ r_p4[i];
    }

    vector<int> res;

    for (int i = 0; i < 4; i++)
    {
        res.push_back(LHS[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        res.push_back(RHS[i]);
    }

    return res;
}

void DES::encryption()
{
    vector<int> arr;

    for (int i = 0; i < 8; i++)
    {
        arr.push_back(plain_text[IP[i] - 1]);
    }

    vector<int> arr1 = algorithm(arr, key1);

    vector<int> swapped = swap_LR(arr1);

    vector<int> arr2 = algorithm(swapped, key2);

    for (int i = 0; i < 8; i++)
    {
        cipher_text.push_back(arr2[IP_inv[i] - 1]);
    }

    cout << "\nCipher text:" << endl;

    for (auto i : cipher_text)
    {
        cout << i << " ";
    }
}

vector<int> DES::shift(vector<int> arr, int n)
{
    while (n > 0)
    {
        int temp = arr[0];
        for (int i = 0; i < arr.size() - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[arr.size() - 1] = temp;
        n--;
    }

    return arr;
}

void DES::key_generation()
{
    vector<int> _key;

    for (int i = 0; i < 10; i++)
    {
        _key.push_back(key[P10[i] - 1]);
    }

    vector<int> LHS(_key.begin(), _key.begin() + _key.size() / 2);
    vector<int> RHS(_key.begin() + _key.size() / 2, _key.end());

    vector<int> LS_1 = shift(LHS, 1);
    vector<int> RS_1 = shift(RHS, 1);

    for (int i = 0; i < 5; i++)
    {
        _key[i] = LS_1[i];
        _key[i + 5] = RS_1[i];
    }

    for (int i = 0; i < 8; i++)
    {
        key1.push_back(_key[P8[i] - 1]);
    }

    vector<int> LS_2 = shift(LHS, 2);
    vector<int> RS_2 = shift(RHS, 2);

    for (int i = 0; i < 5; i++)
    {
        _key[i] = LS_2[i];
        _key[i + 5] = RS_2[i];
    }

    for (int i = 0; i < 8; i++)
    {
        key2.push_back(_key[P8[i] - 1]);
    }

    cout << "\nkey 1:\n";
    for (auto i : key1)
    {
        cout << i << " ";
    }
    cout << "\nkey 2:\n";
    for (auto i : key2)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> Plain_text;
    vector<int> K;

    int temp;
    cout << "\nEnter Your Text:" << endl;
    for (int i = 0; i < 8; i++)
    {
        cin >> temp;
        Plain_text.push_back(temp);
    }
    cout << "\n";

    cout << "\nEnter Your Key:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> temp;
        K.push_back(temp);
    }
    cout << "\n";
    DES ob(Plain_text, K);

    return 0;
}



// 1 0 0 1 0 1 1 1
// 1 0 1 0 0 0 0 0 1 0

// 1 0 1 0 0 1 0 0
// 1 0 0 1 0 0 1 0