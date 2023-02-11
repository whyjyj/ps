#include <bits/stdc++.h>
using namespace std;

int arr[1002][1002];
int dist[1002][1002];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    int cnt = 0;
    queue<pair<int, int>> q; // {y, x}
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                q.push({i, j});
            }
            else if (arr[i][j] == 0)
                cnt++;
        }
    }
    int max_dist = 0;

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
            if (dist[ny][nx] == 0 && arr[ny][nx] == 0)
            {
                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                q.push({ny, nx});
                cnt--;
                if (dist[ny][nx] > max_dist)
                    max_dist = dist[ny][nx];
            }
        }
    }

    if (cnt == 0)
        cout << max_dist;
    else
        cout << -1;
}