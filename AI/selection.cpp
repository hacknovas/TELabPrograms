#include <bits/stdc++.h>
using namespace std;

vector<int> selection_sort(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int index = i;
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
        }
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
    return arr;
}

int main()
{
    int n;
    cout << "\nEnter Total Numbers:" << endl;
    cin >> n;
    int temp;
    vector<int> arr;
    cout << "Enter Numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    arr = selection_sort(arr);
    cout << "\nSorted Array:" << endl;
    for (auto i : arr)
    {

        cout << i << " ";
    }
    return 0;
}