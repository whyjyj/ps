#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dist[100001];
int cost[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> dist[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    int min_cost = cost[0];

    for (int i = 0; i < n - 1; i++)
    {
        min_cost = min(min_cost, cost[i]);
        ans += min_cost * dist[i];
    }

    cout << ans;
}