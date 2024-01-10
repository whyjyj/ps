#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int p[201];

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
    cin >> n;
    cin >> m;

    memset(p, -1, sizeof(int) * 201);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
                merge(i, j);
        }
    }

    vector<int> vec;
    vec.resize(m + 1);
    for (size_t i = 0; i < m; i++)
    {

        cin >> vec[i];
        vec[i]--; // input: 1-indexed
    }

    int before = -300;
    for (int i = 0; i < m; i++)
    {

        if (before != -300)
        {
            if (before != find(vec[i]))
            {
                cout << "NO";
                // cout << '\n'
                //      << before << ' ' << find(vec[i]) << vec[i];
                return 0;
            }
        }
        before = find(vec[i]);
    }

    cout << "YES";
}