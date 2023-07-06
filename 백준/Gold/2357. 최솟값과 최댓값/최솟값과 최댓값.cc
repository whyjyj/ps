#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> num;
vector<int> maxTree;
vector<int> minTree;

void initMin(vector<int> &num, vector<int> &tree, int nodeNum, int nodeL, int nodeR)
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
        initMin(num, tree, nodeNum * 2, nodeL, mid);
        initMin(num, tree, nodeNum * 2 + 1, mid + 1, nodeR);
        tree[nodeNum] = min(tree[nodeNum * 2], tree[nodeNum * 2 + 1]);
    }
}
void initMax(vector<int> &num, vector<int> &tree, int nodeNum, int nodeL, int nodeR)
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
        initMax(num, tree, nodeNum * 2, nodeL, mid);
        initMax(num, tree, nodeNum * 2 + 1, mid + 1, nodeR);
        tree[nodeNum] = max(tree[nodeNum * 2], tree[nodeNum * 2 + 1]);
    }
}

int minQuery(vector<int> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
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
    int lmin = minQuery(tree, nodeNum * 2, nodeL, mid, L, R);
    int rmin = minQuery(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    if (lmin == -1)
        return rmin;
    else if (rmin == -1)
        return lmin;
    else
        return min(lmin, rmin);
}

int maxQuery(vector<int> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
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
    int lmax = maxQuery(tree, nodeNum * 2, nodeL, mid, L, R);
    int rmax = maxQuery(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    if (lmax == 0)
        return rmax;
    else if (rmax == 0)
        return lmax;
    else
        return max(lmax, rmax);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    num.resize(n);
    int h = (int)ceil(log2(n));
    int treeSize = 1 << (h + 1);
    maxTree.resize(treeSize);
    minTree.resize(treeSize);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    initMin(num, minTree, 1, 0, n - 1);
    initMax(num, maxTree, 1, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << minQuery(minTree, 1, 0, n - 1, a - 1, b - 1) << ' ' << maxQuery(maxTree, 1, 0, n - 1, a - 1, b - 1) << '\n';
    }
}