#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pill = pair<ll, int>;
int v, e;
// {cost, index}
vector<pill> adj[1005];
vector<int> previous;
vector<int> path;
ll dist[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    fill(dist, dist + v + 1, LLONG_MAX);
    previous.resize(v + 1, -1);
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    int st, en;
    cin >> st >> en;
    priority_queue<pill, vector<pill>, greater<pill>> pq;
    dist[st] = 0;
    pq.push({0, st}); // Corrected order to {distance, index}
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        ll curDist = cur.first; // Distance should be the first element
        int idx = cur.second;   // Index should be the second element
        if (dist[idx] != curDist)
            continue;
        for (auto nxt : adj[idx])
        {
            int nidx = nxt.second; // Corrected access to index
            ll cost = nxt.first;   // Corrected access to cost
            if (dist[nidx] > curDist + cost)
            {
                dist[nidx] = curDist + cost;
                previous[nidx] = idx;
                pq.push({dist[nidx], nidx}); // Corrected order to {distance, index}
            }
        }
    }

    // Path reconstruction (example: from starting node to each node)

    for (int cur = en; cur != -1; cur = previous[cur])
        path.push_back(cur);

    reverse(path.begin(), path.end());

    // Print the shortest distances
    cout << dist[en] << '\n';
    cout << path.size() << '\n';
    for (auto v : path)
        cout << v << ' ';
    cout << '\n';

    return 0;
}