#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> num;
vector<ll> sum;
vector<ll> mod;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll ans = 0;
    cin >> n >> m;
    num.resize(n + 1);
    sum.resize(n + 1);
    mod.resize(m); // 0 ~ m-1
    num[0] = 0;
    sum[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        sum[i] = sum[i - 1] + num[i];
        mod[sum[i] % m]++;
    }

    for (int i = 0; i < m; i++)
    {
        ans += (mod[i] * (mod[i] - 1) / 2);
    }
    ans += mod[0];
    cout << ans;
}