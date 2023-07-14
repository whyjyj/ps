#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void init(vector<int> &num, vector<int> &tree, int nodeNum, int start, int end)
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
        tree[nodeNum] = tree[nodeNum * 2] ^ tree[nodeNum * 2 + 1];
    }
}

void update_lazy(vector<int> &tree, vector<int> &lazy, int node, int start, int end)
{
    if (lazy[node] != 0)
    {
        if ((end - start + 1) % 2 == 1)
        {
            tree[node] ^= lazy[node];
        }
        if (start != end)
        {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

int query(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int L, int R)
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
    int lxor = query(tree, lazy, node * 2, start, mid, L, R);
    int rxor = query(tree, lazy, node * 2 + 1, mid + 1, end, L, R);
    return lxor ^ rxor;
}

/**
 * 구간에 딱 들어가는 노드 찾았을 때는 바로 xor 연산하고 자식들은 lazy propagate
 * lazy propagate을 어떻게 기록하고 있지?
 *
 */
void update_range(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right, int val)
{
    update_lazy(tree, lazy, node, start, end);
    if (right < start || left > end)
    {
        return;
    }
    if (left <= start && end <= right)
    {
        lazy[node] = val;
        update_lazy(tree, lazy, node, start, end);
        return;
    }
    update_range(tree, lazy, node * 2, start, (start + end) / 2, left, right, val);
    update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> num;
    vector<int> tree;
    vector<int> lazy;

    int n, m;
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

    cin >> m;

    for (int p = 0; p < m; p++)
    {
        int q, i, j, k;
        cin >> q;
        if (q == 1)
        {
            cin >> i >> j >> k;
            update_range(tree, lazy, 1, 0, n - 1, i, j, k);
        }
        else if (q == 2)
        {
            cin >> i >> j;
            cout << query(tree, lazy, 1, 0, n - 1, i, j) << '\n';
        }
    }
}