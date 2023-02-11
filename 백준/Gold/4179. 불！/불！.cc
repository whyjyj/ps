#include <bits/stdc++.h>
using namespace std;

char arr[1002][1002];
int jihun_map[1002][1002];
int fire_map[1002][1002];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    pair<int, int> jihun;
    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++)
    {
        memset(jihun_map[i], -1, sizeof(int) * c);
        memset(fire_map[i], -1, sizeof(int) * c);
    }

    for (int i = 0; i < r; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 'F')
            {
                q.push({i, j}); // 불난 곳 푸쉬
                fire_map[i][j] = 0;
            }

            else if (arr[i][j] == 'J')
            {
                jihun = {i, j};
                jihun_map[i][j] = 0;
            }
        }
    }

    // bfs for fire_map

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                continue;
            if (arr[ny][nx] != '.' || fire_map[ny][nx] != -1)
                continue;
            fire_map[ny][nx] = fire_map[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }

    // bfs for jihun_map
    q.push(jihun);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            {
                cout << jihun_map[cur.first][cur.second] + 1;
                return 0;
            }
            if (arr[ny][nx] != '.' || jihun_map[ny][nx] != -1)
                continue;
            // 불 먼저 도달해서 못 가는 경우
            if (fire_map[ny][nx] != -1 && fire_map[ny][nx] <= jihun_map[cur.first][cur.second] + 1)
                continue;
            jihun_map[ny][nx] = jihun_map[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }
    cout << "IMPOSSIBLE";
}
