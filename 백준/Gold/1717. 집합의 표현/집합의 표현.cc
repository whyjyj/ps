#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int p[1000002];

int find(int n)
{
    if (p[n] < 0)
        return n;
    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    p[a] += p[b];
    p[b] = a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    memset(p, -1, sizeof(int) * 1000002);

    for (size_t i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // union
        if (a == 0)
        {
            merge(b, c);
        }
        // find
        else if (a == 1)
        {
            b = find(b);
            c = find(c);
            if (b == c)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
}