#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

struct node
{
    node(int a, int b)
    {
        dest = a;
        weights = b;
    }
    int dest;
    int weights;
};

void astar(int s, int d, vector<node> v[], int discovered[], int parent[], int dist[], int heu[], int n)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push(make_pair(heu[s], s));
    dist[s] = 0;

    while (!pq.empty())
    {
        int p_s = pq.top().second;
        if (p_s == d)
        {
            return;
        }
        pq.pop();

        if (!discovered[p_s])
        {

            for (int i = 0; i < v[p_s].size(); i++)
            {
                if (!discovered[v[p_s][i].dest] )
                {
                    int f = dist[p_s] + v[p_s][i].weights + heu[v[p_s][i].dest];
                    pq.push(make_pair(f, v[p_s][i].dest));

                    dist[v[p_s][i].dest] = dist[p_s] + v[p_s][i].weights;
                    parent[v[p_s][i].dest] = p_s;
                }
            }

            discovered[p_s] = 1;
        }
    }
}

int main()
{
    int n, ne;
    cin >> n;
    cin >> ne;

    vector<node> v[n];

    for (int i = 0; i < ne; i++)
    {
        int src;
        cin >> src;
        int dest;
        cin >> dest;
        int weigh;
        cin >> weigh;
        v[src].push_back(node(dest, weigh));
        // v[dest].push_back(node(src, weigh));
    }

    int discovered[n];
    int parent[n];
    int dist[n];
    int heu[n];

    cout << "heu";
    for (int i = 0; i < n; i++)
    {
        cin >> heu[i];

        discovered[i] = 0;
        parent[i] = i;
        dist[i] = INT_MAX;
    }
    int s, d;
    cout << "src";
    cin >> s;
    cout << "dest";
    cin >> d;

    astar(s, d, v, discovered, parent, dist, heu, n);

    stack<int> path;
    int curr = d;

    do
    {
        path.push(curr);
        curr = parent[curr];
    } while (curr != 0);

    path.push(s);

    while (!path.empty())
    {
        cout << path.top() << "\t";
        path.pop();
    }

    return 0;
}