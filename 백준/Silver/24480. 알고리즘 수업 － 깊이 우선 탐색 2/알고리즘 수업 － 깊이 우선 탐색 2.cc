#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vec;
int vis[100002];
int order[100002];
int order_cnt;

void dfs(int n)
{
    vis[n] = 1;
    order[n] = ++order_cnt;
    for (int nxt : vec[n])
    {
        if (vis[nxt] == 0)
        {
            dfs(nxt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    vec.resize(n + 1); // 1-idx

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(vec[i].begin(), vec[i].end(), greater<int>());
    }

    dfs(r);

    for (int i = 1; i <= n; i++)
    {
        cout << order[i] << '\n';
    }
}