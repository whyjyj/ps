#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, m, needTime;

    cin >> h >> m >> needTime;

    m += needTime;
    h += (m / 60);
    m %= 60;

    h %= 24;

    cout << h << ' ' << m;
}