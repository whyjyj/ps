#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int NUM = 500005;

int p[NUM];

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

    int n, m, ans = 0;
    cin >> n >> m;

    memset(p, -1, sizeof(int) * NUM);

    /**
     * 사이클이 완성되었는지를 어떻게 판단할 것인가
     * set 1개면 사이클?
     * 만약 새로 입력한 애들이 merge 하기 전에 이미 같은 set이면 사이클인가?
     * 입력 받을 때 마다 merge하기 전에 루트값 비교하고 이미 같은데 다시 입력 들어왔다면 사이클 완성?
     * 즉, 사이클은 이미 같은 set에 속해 있는 애 2개가 다시 입력으로 들어왔을 때 생긴다.
     * 단, -1 제외
     */

    for (size_t i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        int ra = find(a);
        int rb = find(b);

        if (ra == rb && ra != -1 && rb != -1 && ans == 0)
        {
            // cycle 완성
            ans = i + 1;
        }

        merge(a, b);
    }

    cout << ans;
}