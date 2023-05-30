#include <bits/stdc++.h>
using namespace std;

int modPower(int prime_root, int key, int prime)
{
    double i = 0, x = 0;
    double c = 1;

    while (i < key)
    {
        if (i + 1 == key)
        {
            x = pow(prime_root, 1);
            i++;
        }
        else
        {
            x = pow(prime_root, 2);
            i += 2;
        }
        c = fmod((fmod(x, prime) * c), prime);
    }
    x = fmod(c, prime);

    return x;
}

bool isPrimitive(double p_root, double prime)
{
    set<double> s;
    for (int i = 1; i < prime; i++)
    {
        int k = modPower(p_root, i, prime);
        cout << k << " ";

        auto pos = s.find(k);
        if (pos == s.end())
        {
            s.insert(k);
        }
        else if (pos != s.end())
        {
            return false;
        }
    }

    return true;
}

bool isPrime(double n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
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
    double prime, p_root, A, B, YA, YB, KA, KB;
x:
    cout << "\nEnter Prime:" << endl;
    cin >> prime;
    if (!isPrime(prime))
    {
        cout << "Not Prime...Enter another one" << endl;
        goto x;
    }
y:
    cout << "\nEnter Primitive Root:" << endl;
    cin >> p_root;

    if (!isPrimitive(p_root, prime))
    {
        cout << "*Not Primitive root...Enter Again" << endl;
        goto y;
    }

    cout << "\nEnter first Key(A):" << endl;
    cin >> A;
    YA = modPower(p_root, A, prime);

    cout << "\nEnter second key(B):" << endl;
    cin >> B;
    YB = modPower(p_root, B, prime);

    KA = modPower(YB, A, prime);
    KB = modPower(YA, B, prime);

    cout << "\nComputed Key by both end:" << endl;
    cout << "A ->" << KA << " "
         << "B ->" << KB << endl;

    return 0;
}
