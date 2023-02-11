#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int dist[101][101];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = input[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0}); // {y,x}
    dist[0][0] = 1;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (dist[ny][nx] != 0 || arr[ny][nx] != 1)
                continue;

            dist[ny][nx] = dist[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }

    cout << dist[n - 1][m - 1];
}