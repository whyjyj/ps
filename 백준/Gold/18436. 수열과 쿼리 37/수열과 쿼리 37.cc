#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void initTree(vector<int> &num, vector<int> &oddTree, vector<int> &evenTree, int nodeNum, int nodeL, int nodeR)
{
    // Leaf
    if (nodeL == nodeR)
    {
        if (num[nodeL] % 2 == 0)
        {
            evenTree[nodeNum] = 1;
            oddTree[nodeNum] = 0;
        }
        else
        {
            evenTree[nodeNum] = 0;
            oddTree[nodeNum] = 1;
        }
    }
    // Internal Node
    else
    {
        int mid = (nodeL + nodeR) / 2;
        initTree(num, oddTree, evenTree, nodeNum * 2, nodeL, mid);
        initTree(num, oddTree, evenTree, nodeNum * 2 + 1, mid + 1, nodeR);
        evenTree[nodeNum] = evenTree[nodeNum * 2] + evenTree[nodeNum * 2 + 1];
        oddTree[nodeNum] = oddTree[nodeNum * 2] + oddTree[nodeNum * 2 + 1];
    }
}

void update(vector<int> &num, vector<int> &oddTree, vector<int> &evenTree, int node, int start, int end, int index, int val)
{
    if (index < start || index > end)
    {
        return;
    }
    if (start == end)
    {
        num[index] = val;

        if (num[index] % 2 == 0)
        {
            evenTree[node] = 1;
            oddTree[node] = 0;
        }
        else
        {
            evenTree[node] = 0;
            oddTree[node] = 1;
        }
        return;
    }
    update(num, oddTree, evenTree, node * 2, start, (start + end) / 2, index, val);
    update(num, oddTree, evenTree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    evenTree[node] = evenTree[node * 2] + evenTree[node * 2 + 1];
    oddTree[node] = oddTree[node * 2] + oddTree[node * 2 + 1];
}

int oddQuery(vector<int> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
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
    int lCount = oddQuery(tree, nodeNum * 2, nodeL, mid, L, R);
    int rCount = oddQuery(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    if (lCount == -1)
        return rCount;
    else if (rCount == -1)
        return lCount;
    else
        return lCount + rCount;
}

int evenQuery(vector<int> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
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
    int lCount = evenQuery(tree, nodeNum * 2, nodeL, mid, L, R);
    int rCount = evenQuery(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    if (lCount == 0)
        return rCount;
    else if (rCount == 0)
        return lCount;
    else
        return lCount + rCount;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> num;
    vector<int> evenTree;
    vector<int> oddTree;

    int n;
    cin >> n;
    num.resize(n);

    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);
    oddTree.resize(tree_size);
    evenTree.resize(tree_size);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    initTree(num, oddTree, evenTree, 1, 0, n - 1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(num, oddTree, evenTree, 1, 0, n - 1, b - 1, c);
        }
        else if (a == 2)
        {
            cout << evenQuery(evenTree, 1, 0, n - 1, b - 1, c - 1) << '\n';
        }
        else if (a == 3)
        {
            cout << oddQuery(oddTree, 1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
}