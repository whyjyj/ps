#include <bits/stdc++.h>
using namespace std;

int BottomUpLCS(const string &X, const string &Y, int m, int n)
{

    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1]) // 주의: i - 1, j - 1
            {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else if (table[i - 1][j] >= table[i][j - 1])
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {
                table[i][j] = table[i][j - 1];
            }
        }
    }

    return table[m][n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input1, input2;
    cin >> input1 >> input2;

    cout << BottomUpLCS(input1, input2, input1.length(), input2.length());
}