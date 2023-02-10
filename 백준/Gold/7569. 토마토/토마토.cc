#include <bits/stdc++.h>
using namespace std;
using ppp = pair<int, pair<int, int>>;

// 앞, 오, 뒤, 왼, 위, 아래
int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int arr[102][102][102];
int dist[102][102][102];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, h;
    int num = 0;
    queue<ppp> q;

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> arr[i][j][k];
                // 익은 토마토는 bfs를 위해 미리 큐에
                if (arr[i][j][k] == 1)
                    q.push({i, {j, k}});
                else if (arr[i][j][k] == -1)
                    dist[i][j][k] = -1;
                // 안 익은 토마토 개수 미리 체크
                else if (arr[i][j][k] == 0)
                    num++;
            }
        }
    }

    if (num == 0)
    {
        cout << 0;
        return 0;
    }

    int max_dist = 0;

    while (!q.empty())
    {
        ppp cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nz = cur.first + dz[i];
            int ny = cur.second.first + dy[i];
            int nx = cur.second.second + dx[i];

            if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue; // out of boundary
            if (arr[nz][ny][nx] == 0 && dist[nz][ny][nx] == 0)
            {
                dist[nz][ny][nx] = dist[cur.first][cur.second.first][cur.second.second] + 1; // 익게 만들기
                if (max_dist < dist[nz][ny][nx])
                    max_dist = dist[nz][ny][nx];
                num--; // 안 익은 거 개수 업데이트
                q.push({nz, {ny, nx}});
            }
        }
    }

    if (num == 0)
        cout << max_dist;
    else
        cout << -1;
}