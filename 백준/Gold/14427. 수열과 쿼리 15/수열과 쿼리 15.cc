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

int queryMinValue(vector<int> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
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
    int lmin = queryMinValue(tree, nodeNum * 2, nodeL, mid, L, R);
    int rmin = queryMinValue(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    if (lmin == -1)
        return rmin;
    else if (rmin == -1)
        return lmin;
    else
        return min(lmin, rmin);
}

int queryMinIdx(vector<int> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
{
    // if (R < nodeL || nodeR < L)
    // {
    //     return -1;
    // }
    // if (L <= nodeL && nodeR <= R)
    // {
    //     return tree[nodeNum];
    // }
    // Leaf Node
    if (nodeL == nodeR)
        return nodeL;
    // Internal Node
    int mid = (nodeL + nodeR) / 2;
    int lmin = queryMinValue(tree, nodeNum * 2, nodeL, mid, L, R);
    int rmin = queryMinValue(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    int minIdx = -1;
    if (lmin == -1)
        minIdx = queryMinIdx(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    else if (rmin == -1)
        minIdx = queryMinIdx(tree, nodeNum * 2, nodeL, mid, L, R);
    else if (lmin <= rmin)
        minIdx = queryMinIdx(tree, nodeNum * 2, nodeL, mid, L, R);
    else if (lmin > rmin)
        minIdx = queryMinIdx(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    return minIdx;
}

void update(vector<int> &num, vector<int> &tree, int node, int start, int end, int index, int val)
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
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    num.resize(n);

    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);
    tree.resize(tree_size);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    init(num, tree, 1, 0, n - 1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b, c;
            cin >> b >> c;
            update(num, tree, 1, 0, n - 1, b - 1, c);
        }
        else if (a == 2)
        {
            cout << queryMinIdx(tree, 1, 0, n - 1, 0, n - 1) + 1 << '\n';
        }
    }
}