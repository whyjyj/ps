#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
        tree[nodeNum] = tree[nodeNum * 2] + tree[nodeNum * 2 + 1];
    }
}

ll query(vector<ll> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
{
    if (R < nodeL || nodeR < L)
    {
        return 0;
    }
    if (L <= nodeL && nodeR <= R)
    {
        return tree[nodeNum];
    }
    int mid = (nodeL + nodeR) / 2;
    ll lsum = query(tree, nodeNum * 2, nodeL, mid, L, R);
    ll rsum = query(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    return lsum + rsum;
}

void update(vector<ll> &num, vector<ll> &tree, int node, int start, int end, int index, ll val)
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
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    num.resize(n);
    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);
    tree.resize(tree_size);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    init(num, tree, 1, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        if (x > y)
            cout << query(tree, 1, 0, n - 1, y - 1, x - 1) << '\n';
        else
            cout << query(tree, 1, 0, n - 1, x - 1, y - 1) << '\n';
        update(num, tree, 1, 0, n - 1, a - 1, b);
    }
}