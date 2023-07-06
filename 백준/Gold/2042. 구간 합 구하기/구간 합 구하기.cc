#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_NUM = 1000000;

int n, m, k;
vector<ll> num;
vector<ll> tree;

// num: num array
// tree: segment tree
// nodeNum: 노드 번호
// node에 저장되어 있는 합의 범위가 nodeL - nodeR
void init(vector<long long> &num, vector<long long> &tree, int nodeNum, int nodeL, int nodeR)
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

ll sum(vector<ll> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
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
    ll lsum = sum(tree, nodeNum * 2, nodeL, mid, L, R);
    ll rsum = sum(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    return lsum + rsum;
}

void update(vector<long long> &num, vector<long long> &tree, int node, int start, int end, int index, long long val)
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

    cin >> n >> m >> k;

    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);

    num.resize(n);
    tree.resize(tree_size);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    init(num, tree, 1, 0, n - 1);

    for (int i = 0; i < m + k; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            // change b'th number to c
            update(num, tree, 1, 0, n - 1, b - 1, c);
        }
        else if (a == 2)
        {
            // sum from b'th to c'th number
            cout << sum(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
}