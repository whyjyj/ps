#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void init(vector<ll> &num, vector<ll> &tree, int nodeNum, int start, int end)
{
    // Leaf
    if (start == end)
    {
        tree[nodeNum] = num[start];
    }
    // Internal Node
    else
    {
        int mid = (start + end) / 2;
        init(num, tree, nodeNum * 2, start, mid);
        init(num, tree, nodeNum * 2 + 1, mid + 1, end);
        tree[nodeNum] = tree[nodeNum * 2] + tree[nodeNum * 2 + 1];
    }
}

void update_lazy(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end)
{
    if (lazy[node] != 0)
    {
        tree[node] += lazy[node] * (end - start + 1);
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll query(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end, int L, int R)
{
    update_lazy(tree, lazy, node, start, end);
    if (R < start || end < L)
    {
        return 0;
    }
    if (L <= start && end <= R)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    ll lsum = query(tree, lazy, node * 2, start, mid, L, R);
    ll rsum = query(tree, lazy, node * 2 + 1, mid + 1, end, L, R);
    return lsum + rsum;
}

void update_range(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end, int left, int right, ll val)
{
    update_lazy(tree, lazy, node, start, end);
    if (right < start || left > end)
    {
        return;
    }
    if (left <= start && end <= right)
    {
        tree[node] += val * (end - start + 1);
        if (start != end)
        {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    update_range(tree, lazy, node * 2, start, (start + end) / 2, left, right, val);
    update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> num;
    vector<ll> tree;
    vector<ll> lazy;

    int n;
    cin >> n;
    num.resize(n);
    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);
    tree.resize(tree_size);
    lazy.resize(tree_size);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    init(num, tree, 1, 0, n - 1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int i, j, k;
            cin >> i >> j >> k;
            update_range(tree, lazy, 1, 0, n - 1, i - 1, j - 1, k);
        }
        else if (q == 2)
        {
            int x;
            cin >> x;
            cout << query(tree, lazy, 1, 0, n - 1, x - 1, x - 1) << '\n';
        }
    }
}