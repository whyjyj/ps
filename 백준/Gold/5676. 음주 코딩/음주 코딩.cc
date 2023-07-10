#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
        tree[nodeNum] = (tree[nodeNum * 2] * tree[nodeNum * 2 + 1]);
    }
}

int query(vector<int> &tree, int nodeNum, int nodeL, int nodeR, int L, int R)
{
    if (R < nodeL || nodeR < L)
    {
        return 100;
    }
    if (L <= nodeL && nodeR <= R)
    {
        return tree[nodeNum];
    }
    int mid = (nodeL + nodeR) / 2;
    ll lmul = query(tree, nodeNum * 2, nodeL, mid, L, R);
    ll rmul = query(tree, nodeNum * 2 + 1, mid + 1, nodeR, L, R);
    if (lmul == 100)
        return rmul;
    else if (rmul == 100)
        return lmul;
    else
        return lmul * rmul;
}

void update(vector<int> &num, vector<int> &tree, int node, int start, int end, int index, int val)
{
    if (index < start || index > end)
    {
        return;
    }
    if (start == end)
    {
        if (val > 0)
            val = 1;
        else if (val < 0)
            val = -1;
        else
            val = 0;
        num[index] = val;
        tree[node] = val;
        return;
    }
    update(num, tree, node * 2, start, (start + end) / 2, index, val);
    update(num, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    while (cin >> n >> k)
    {
        num.resize(n);

        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            if (input > 0)
                input = 1;
            else if (input < 0)
                input = -1;
            else
                input = 0;
            num[i] = input;
        }

        int h = (int)ceil(log2(n));
        int tree_size = 1 << (h + 1);
        tree.resize(tree_size);
        init(num, tree, 1, 0, n - 1);

        for (int i = 0; i < k; i++)
        {
            char a;
            int b, c;
            cin >> a >> b >> c;
            if (a == 'C')
            {
                update(num, tree, 1, 0, n - 1, b - 1, c);
            }
            else if (a == 'P')
            {
                if (query(tree, 1, 0, n - 1, b - 1, c - 1) == 1)
                    cout << '+';
                else if (query(tree, 1, 0, n - 1, b - 1, c - 1) == -1)
                    cout << '-';
                else
                    cout << "0";
            }
        }
        cout << '\n';
    }
}