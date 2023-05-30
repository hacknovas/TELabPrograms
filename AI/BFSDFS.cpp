// @Doni_Prathamesh ...RBFS & ...RDFS
#include <bits/stdc++.h>
using namespace std;

void recursive_bfs(vector<vector<int>> &Edges, queue<int> &q, vector<bool> &discoverd)
{
    if (q.empty())
    {
        return;
    }

    int u = q.front();
    q.pop();

    cout << u << " ";

    for (auto v : Edges[u])
    {
        if (!discoverd[v])
        {
            discoverd[v] = true;
            q.push(v);
        }
    }

    recursive_bfs(Edges, q, discoverd);
}

void recursive_dfs(vector<vector<int>> &Edges, vector<bool> &discoverd, int str_nd)
{
    discoverd[str_nd] = true;
    cout << str_nd << " ";

    for (auto i : Edges[str_nd])
    {
        if (!discoverd[i])
        {
            recursive_dfs(Edges, discoverd, i);
        }
    }
}

int main()
{
    int n, ne;

    cout << "\nEnter No of Vertices: " << endl;
    cin >> n;
    cout << "Enter No of Edges: " << endl;
    cin >> ne;
    vector<vector<int>> Edges(ne);

    int src, dest;

    cout << "\nEnter Source and Destination:" << endl;
    for (int i = 0; i < ne; i++)
    {
        cin >> src;
        cin >> dest;
        Edges[src].push_back(dest);
        Edges[dest].push_back(src);
    }

    vector<bool> discoverd(n, false);

    queue<int> q;

    int str_nd;

    cout << "\nEnter Start Node: " << endl;
    cin >> str_nd;
    q.push(str_nd);

    cout << "\nBFS:" << endl;
    discoverd[str_nd] = true;
    recursive_bfs(Edges, q, discoverd);

    discoverd.assign(n, false);

    cout << "\nDFS:" << endl;
    recursive_dfs(Edges, discoverd, str_nd);

    return 0;
}
