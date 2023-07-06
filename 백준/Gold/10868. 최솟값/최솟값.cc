#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<int> tree;

void init(vector<int> &num, vector<int> &tree, int nodeNum, int nodeL, int nodeR)
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
        tree[nodeNum] = min(tree[nodeNum * 2], tree[nodeNum * 2 + 1]);
    }
}

int query(vector<int> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
{
    if (R < nodeL || nodeR < L)
    {
        return 1000000001;
    }
    if (L <= nodeL && nodeR <= R)
    {
        return tree[nodeNum];
    }
    int mid = (nodeL + nodeR) / 2;
    int lmin = query(tree, nodeNum * 2, nodeL, mid, L, R);
    int rmin = query(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    if (lmin == 1000000001)
        return rmin;
    else if (rmin == 1000000001)
        return lmin;
    else
        return min(lmin, rmin);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    num.resize(n);
    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);
    tree.resize(tree_size);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    init(num, tree, 1, 0, n - 1);

    for (int j = 0; j < m; j++)
    {
        int a, b;
        cin >> a >> b;
        cout << query(tree, 1, 0, n - 1, a - 1, b - 1) << '\n';
    }
}