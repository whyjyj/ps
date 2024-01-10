#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int NUM = 10001;

int p[NUM];
int cost[NUM];

int find(int n)
{
    if (p[n] < 0)
        return n;
    p[n] = find(p[n]);
    return p[n];
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (p[a] > p[b])
    {
        p[b] = a;
    }
    else
    {
        p[a] = b;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, ans = 0;
    cin >> n >> m >> k;

    memset(p, -1, sizeof(int) * NUM);

    /**
     * p[root]에 음수 형태로 그 집합의 친구비 최솟값 저장 -> 음수니까 union 할 때 max값으로 업데이트하면 된다.
     */

    for (size_t i = 0; i < n; i++)
    {
        cin >> cost[i];
        p[i] = -cost[i];
    }

    for (size_t i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a - 1, b - 1);
    }

    for (size_t i = 0; i < n; i++)
    {
        if (p[i] < 0)
            ans += p[i];
    }
    ans *= -1;
    if (ans > k)
        cout << "Oh no";
    else
        cout << ans;
}