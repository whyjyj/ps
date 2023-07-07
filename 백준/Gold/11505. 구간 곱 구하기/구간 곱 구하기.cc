#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007

vector<ll> num;
vector<ll> tree;
void init(vector<ll> &num, vector<ll> &tree, int nodeNum, int nodeL, int nodeR)
{
    // Leaf
    if (nodeL == nodeR)
    {
        tree[nodeNum] = num[nodeL];
    }
    // Internal Node
    else
    {
        int mid = (nodeL + nodeR) / 2;
        init(num, tree, nodeNum * 2, nodeL, mid);
        init(num, tree, nodeNum * 2 + 1, mid + 1, nodeR);
        tree[nodeNum] = ((tree[nodeNum * 2] % MOD) * (tree[nodeNum * 2 + 1] % MOD)) % MOD;
    }
}

int query(vector<ll> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
{
    if (R < nodeL || nodeR < L)
    {
        return -1;
    }
    if (L <= nodeL && nodeR <= R)
    {
        return tree[nodeNum];
    }
    int mid = (nodeL + nodeR) / 2;
    ll lmul = query(tree, nodeNum * 2, nodeL, mid, L, R);
    ll rmul = query(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    if (lmul == -1)
        return rmul % MOD;
    else if (rmul == -1)
        return lmul % MOD;
    else
        return ((lmul % MOD) * (rmul % MOD)) % MOD;
}

void update(vector<ll> &num, vector<ll> &tree, int node, int start, int end, int index, int val)
{
    if (index < start || index > end)
    {
        return;
    }
    if (start == end)
    {
        num[index] = val;
        tree[node] = val;
        return;
    }
    update(num, tree, node * 2, start, (start + end) / 2, index, val);
    update(num, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = (tree[node * 2] % MOD) * (tree[node * 2 + 1] % MOD) % MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    num.resize(n);

    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);
    tree.resize(tree_size);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    init(num, tree, 1, 0, n - 1);

    int cnt = m + k;
    for (int i = 0; i < cnt; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(num, tree, 1, 0, n - 1, b - 1, c);
        }
        else if (a == 2)
        {
            cout << query(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
}