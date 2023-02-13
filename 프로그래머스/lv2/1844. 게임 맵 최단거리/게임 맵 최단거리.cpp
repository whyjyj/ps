#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int dist[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int m = maps[0].size(); // 가로
    int n = maps.size(); // 세로
    queue<pair<int,int>> q;
    
    for(int i=0;i<n;i++) {
        memset(dist[i], -1, sizeof(int) * m);
    }
    
    
    q.push({0,0});
    dist[0][0] = 1;
    
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny<0|| ny>=n || nx<0 || nx>=m) continue;
            if(maps[ny][nx] != 1 || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[cur.first][cur.second] + 1;
            q.push({ny,nx});
        }
    }
    
    answer = dist[n-1][m-1];
    
    return answer;
}