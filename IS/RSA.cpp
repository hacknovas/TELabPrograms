#include <bits/stdc++.h>
using namespace std;

double modPower(double a, double key, double n)
{
    double i = 0, x = 0;
    double c = 1;

    while (i < key)
    {
        if (i + 1 == key)
        {
            x = pow(a, 1);
            i++;
        }
        else
        {
            x = pow(a, 2);
            i += 2;
        }
        c = fmod((fmod(x, n) * c), n);
    }
    x = fmod(c, n);

    return x;
}

bool isPrime(double n)
{
    if (n <= 1)
    {
        return false;
    }

    for (double i = 2; i < n; i++)
    {
        if (fmod(n, i) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    double p, q, n, N, e, d, msg, cipher;
x:
    cout << "\nEnter Prime Number:" << endl;
    cout << "P -> ";
    cin >> p;
    if (!isPrime(p))
    {
        goto x;
    }
y:
    cout << "Q -> ";
    cin >> q;

    if (!isPrime(q))
    {
        goto y;
    }

    n = p * q;
    N = (p - 1) * (q - 1); // Phi of n
z:
    cout << "\nEnter e ->" << endl;
    cin >> e;

    int a, b, r;
    a = N;
    b = e;
    while (1)
    {
        if (b == 0)
        {
            if (a == 1)
            {
                printf("\n*e is valid!");
                break;
            }
            else
            {
                printf("\n*e is invalid!");
                goto z;
            }
        }
        else
        {
            r = fmod(a, b);
            a = b;
            b = r;
        }
    }

    // to finnd "d"
    double temp;
    double k = 0, f_check;
    while (1)
    {
        temp = (1 + k * N) / e;
        f_check = floor(temp);
        if (temp == f_check)
        {
            cout << "\nDecrypt Key :" << temp << endl;
            d = temp;
            break;
        }

        k++;
    }

    cout << "\nEnter Message:" << endl;
    cin >> msg;

    cipher = modPower(msg, e, n);
    cout << "\nCipher Text: " << cipher;

    cout << "\nDecrypted Message: " << modPower(cipher, d, n);

    return 0;
}
