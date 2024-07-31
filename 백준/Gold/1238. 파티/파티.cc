#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
int n, m, st;
// {cost, index}
vector<pii> adj[1005];
const int INF = 1e9 + 10;
int backDist[1005];
int goDist[1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> st;
    fill(backDist, backDist + n + 1, INF);
    fill(goDist, goDist + n + 1, INF);
    while (m--)
    {
        int u, n, w;
        cin >> u >> n >> w;
        adj[u].push_back({w, n});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    backDist[st] = 0;
    pq.push({backDist[st], st});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int curDist = cur.first, idx = cur.second;
        if (backDist[idx] != curDist)
            continue;
        for (auto nxt : adj[idx])
        {
            int cost = nxt.first, nidx = nxt.second;
            if (backDist[nidx] > curDist + cost)
            {
                backDist[nidx] = curDist + cost;
                pq.push({backDist[nidx], nidx});
            }
        }
    }

    // go dist - from everywhere(i) to st(x)
    int max_dist = -1;
    for (size_t i = 1; i <= n; i++)
    {
        // priority_queue<pii, vector<pii>, greater<pii>> pq;
        fill(goDist, goDist + n + 1, INF);
        goDist[i] = 0;
        pq.push({goDist[i], i});
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int curDist = cur.first, idx = cur.second;
            if (goDist[idx] != curDist)
                continue;
            for (auto nxt : adj[idx])
            {
                int cost = nxt.first, nidx = nxt.second;
                if (goDist[nidx] > curDist + cost)
                {
                    goDist[nidx] = curDist + cost;
                    pq.push({goDist[nidx], nidx});
                }
            }
        }
        if (goDist[st] != INF)
            max_dist = max(backDist[i] + goDist[st], max_dist);
    }

    cout << max_dist << '\n';
}